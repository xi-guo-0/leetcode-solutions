#!/usr/bin/env racket
#lang racket

(define/contract (check-valid-cuts n rectangles)
  (-> exact-integer? (listof (listof exact-integer?)) boolean?)

  (define (has-valid-cut rectangles dimension)
    (define sorted-rectangles
      (sort rectangles (lambda (a b) (< (list-ref a dimension) (list-ref b dimension)))))
    (define (fold-rec rectangles prev-cut)
      (cond
        [(empty? rectangles) (first prev-cut)]
        [else
         (let* ([item (first rectangles)]
                [prev-start (second prev-cut)]
                [prev-end (third prev-cut)]
                [item-start (list-ref item dimension)]
                [item-end (list-ref item (+ dimension 2))])
           (if (and (>= item-start prev-start) (< item-start prev-end))
               (fold-rec (rest rectangles) (list (first prev-cut) prev-start (max prev-end item-end)))
               (fold-rec (rest rectangles) (list (+ 1 (first prev-cut)) item-start item-end))))]))
    (fold-rec (rest sorted-rectangles)
              (list 1
                    (list-ref (first sorted-rectangles) dimension)
                    (list-ref (first sorted-rectangles) (+ dimension 2)))))

  (or (>= (has-valid-cut rectangles 0) 3) (>= (has-valid-cut rectangles 1) 3)))

(module+ test
  (require rackunit)
  (check-true (check-valid-cuts 5 '((1 0 5 2) (0 2 2 4) (3 2 5 3) (0 4 4 5))))
  (check-true (check-valid-cuts 4 '((0 0 1 1) (2 0 3 4) (0 2 2 3) (3 0 4 3))))
  (check-false (check-valid-cuts 4 '((0 2 2 4) (1 0 3 2) (2 2 3 4) (3 0 4 2) (3 2 4 4)))))
