#!/usr/bin/env racket
#lang racket

(define/contract (number-of-arrays differences lower upper)
  (-> (listof exact-integer?) exact-integer? exact-integer? exact-integer?)
  (let* ([min-max (let loop ([remaining-differences differences]
                             [current-sum 0]
                             [min-sum 0]
                             [max-sum 0])
                    (if (empty? remaining-differences)
                        (cons min-sum max-sum)
                        (let* ([next-sum (+ current-sum (first remaining-differences))]
                               [new-min (min next-sum min-sum)]
                               [new-max (max next-sum max-sum)])
                          (loop (rest remaining-differences) next-sum new-min new-max))))]
         [min-sum (car min-max)]
         [max-sum (cdr min-max)]
         [required-width (- max-sum min-sum)]
         [available-width (- upper lower)]
         [possible-count (+ 1 (- available-width required-width))])
    (max 0 possible-count)))

(module+ test
  (require rackunit)
  (check-equal? (number-of-arrays '(1 -3 4) 1 6) 2)
  (check-equal? (number-of-arrays '(3 -4 5 1 -2) -4 5) 4)
  (check-equal? (number-of-arrays '(4 -7 2) 3 6) 0))
