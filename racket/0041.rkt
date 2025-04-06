#!/usr/bin/env racket
#lang racket

(define/contract (first-missing-positive nums)
  (-> (listof exact-integer?) exact-integer?)
  (let ([nums (list->set nums)])
    (for/first ([i (in-naturals 1)]
                #:when (not (set-member? nums i)))
      i)))

(module+ test
  (require rackunit)
  (check-equal? (first-missing-positive '(1 2 0)) 3)
  (check-equal? (first-missing-positive '(3 4 -1 1)) 2)
  (check-equal? (first-missing-positive '(7 8 9 11 12)) 1))
