#!/usr/bin/env racket
#lang racket

(define/contract (minimum-cost n edges query)
  (-> exact-integer?
      (listof (listof exact-integer?))
      (listof (listof exact-integer?))
      (listof exact-integer?))

  (define (find-root parent node)
    (if (not (= (list-ref parent node) node))
        (let ([root (find-root parent (list-ref parent node))])
          (list-set parent node root)
          root)
        node))

  (define (union parent rank min-path-cost x y weight)
    (let* ([x-root (find-root parent x)]
           [y-root (find-root parent y)]
           [new-min-path-cost
            (list-set min-path-cost y-root (bitwise-and (list-ref min-path-cost y-root) weight))])
      (cond
        [(= x-root y-root) (list parent rank new-min-path-cost)]
        [else
         (let ([x-rank (list-ref rank x-root)]
               [y-rank (list-ref rank y-root)])
           (if (< x-rank y-rank)
               (list (list-set parent x-root y-root)
                     rank
                     (list-set new-min-path-cost
                               y-root
                               (bitwise-and (list-ref new-min-path-cost y-root)
                                            (list-ref new-min-path-cost x-root))))
               (if (> x-rank y-rank)
                   (list (list-set parent y-root x-root)
                         rank
                         (list-set new-min-path-cost
                                   x-root
                                   (bitwise-and (list-ref new-min-path-cost x-root)
                                                (list-ref new-min-path-cost y-root))))
                   (list (list-set parent y-root x-root)
                         (list-set rank x-root (+ (list-ref rank x-root) 1))
                         (list-set new-min-path-cost
                                   x-root
                                   (bitwise-and (list-ref new-min-path-cost x-root)
                                                (list-ref new-min-path-cost y-root)))))))])))

  (define (initialize-parent-and-rank n)
    (values (build-list n (lambda (x) x)) (make-list n 0)))

  (define (initialize-min-path-cost n)
    (make-list n -1))

  (define (process-edges parent rank min-path-cost edges)
    (foldl (lambda (edge state)
             (let ([parent (first state)]
                   [rank (second state)]
                   [min-path-cost (third state)])
               (union parent rank min-path-cost (first edge) (second edge) (third edge))))
           (list parent rank min-path-cost)
           edges))

  (define (process-query parent min-path-cost q)
    (let ([start (first q)]
          [end (second q)])
      (cond
        [(= start end) 0]
        [(not (= (find-root parent start) (find-root parent end))) -1]
        [else (list-ref min-path-cost (find-root parent start))])))

  (let*-values ([(parent rank) (initialize-parent-and-rank n)]
                [(min-path-cost) (initialize-min-path-cost n)]
                [(processed-state) (process-edges parent rank min-path-cost edges)]
                [(final-parent) (first processed-state)]
                [(final-rank) (second processed-state)]
                [(final-min-path-cost) (third processed-state)])
    (map (lambda (q) (process-query final-parent final-min-path-cost q)) query)))

(module+ test
  (require rackunit)
  (check-equal? (minimum-cost 5 '((0 1 7) (1 3 7) (1 2 1)) '((0 3) (3 4))) '(1 -1))
  (check-equal? (minimum-cost 3 '((0 2 7) (0 1 15) (1 2 6) (1 2 1)) '((1 2))) '(0)))
