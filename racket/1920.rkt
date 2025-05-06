#!/usr/bin/env racket
#lang racket

(define/contract (build-array nums)
  (-> (listof exact-integer?) (listof exact-integer?))
  (let ([v (list->vector nums)])
    (for/list ([i nums])
      (vector-ref v i))))

(module+ test
  (require rackunit)
  (check-equal? (build-array '(0 2 1 5 3 4)) '(0 1 2 4 5 3))
  (check-equal? (build-array '(5 0 1 2 3 4)) '(4 5 0 1 2 3)))
