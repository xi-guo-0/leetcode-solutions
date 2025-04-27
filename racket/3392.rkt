#!/usr/bin/env racket
#lang racket

(define/contract (count-subarrays nums)
  (-> (listof exact-integer?) exact-integer?)
  (for/sum ([a nums] [b (cdr nums)] [c (cddr nums)]) (if (= (* (+ a c) 2) b) 1 0)))

(module+ test
  (require rackunit)
  (check-equal? (count-subarrays '(1 2 1 4 1)) 1)
  (check-equal? (count-subarrays '(1 1 1)) 0))
