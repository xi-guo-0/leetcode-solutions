#!/usr/bin/env racket
#lang racket

(define/contract (combination-sum2 candidates target)
  (-> (listof exact-integer?) exact-integer? (listof (listof exact-integer?)))
  (let ([sorted-candidates (sort candidates <)])
    (let loop ([start 0]
               [remaining target]
               [path '()]
               [acc '()])
      (cond
        [(= remaining 0) (cons (reverse path) acc)]
        [(or (> start (sub1 (length sorted-candidates))) (< remaining 0)) acc]
        [else
         (let* ([current (list-ref sorted-candidates start)]
                [new-remaining (- remaining current)]
                [new-path (cons current path)]
                [new-start (add1 start)]
                [result-with-current (if (>= new-remaining 0)
                                         (loop new-start new-remaining new-path acc)
                                         acc)])
           (let ([next-start (let loop ([i (add1 start)])
                               (if (and (< i (length sorted-candidates))
                                        (= (list-ref sorted-candidates i) current))
                                   (loop (add1 i))
                                   i))])
             (loop next-start remaining path result-with-current)))]))))

(module+ test
  (require rackunit)
  (check-equal? (combination-sum2 '(10 1 2 7 6 1 5) 8) '((2 6) (1 7) (1 2 5) (1 1 6)))
  (check-equal? (combination-sum2 '(2 5 2 1 2) 5) '((5) (1 2 2))))
