#!/usr/bin/env racket
#lang racket

(define/contract (count-days days meetings)
  (-> exact-integer? (listof (listof exact-integer?)) exact-integer?)
  (define sorted-meetings (sort meetings (lambda (a b) (< (first a) (first b)))))

  (define (calculate-free-days meetings latest-end free-days)
    (cond
      [(empty? meetings) (+ free-days (- days latest-end))]
      [else
       (let* ([meeting (first meetings)]
              [start (first meeting)]
              [end (second meeting)]
              [new-free-days (if (> start (+ latest-end 1))
                                 (+ free-days (- start latest-end 1))
                                 free-days)])
         (calculate-free-days (rest meetings) (max latest-end end) new-free-days))]))

  (calculate-free-days sorted-meetings 0 0))

(module+ test
  (require rackunit)
  (check-equal? (count-days 10 '((5 7) (1 3) (9 10))) 2)
  (check-equal? (count-days 5 '((2 4) (1 3))) 1)
  (check-equal? (count-days 6 '((1 6))) 0))
