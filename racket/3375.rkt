#!/usr/bin/env racket
#lang racket

(define/contract (min-operations nums k)
  (-> (listof exact-integer?) exact-integer? exact-integer?)
  (let ([unique-sorted-numbers (sort (remove-duplicates nums) <)])
    (let ([smallest-number (car unique-sorted-numbers)]
          [unique-count (length unique-sorted-numbers)])
      (cond
        [(< smallest-number k) -1]
        [(= smallest-number k) (sub1 unique-count)]
        [else unique-count]))))

(module+ test
  (require rackunit)

  (check-equal? (min-operations '(5 2 5 4 5) 2) 2)
  (check-equal? (min-operations '(2 1 2) 2) -1)
  (check-equal? (min-operations '(9 7 5 3) 1) 4))
