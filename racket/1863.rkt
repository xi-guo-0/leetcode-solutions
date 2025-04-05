#!/usr/bin/env racket
#lang racket

(define/contract (subset-xor-sum nums)
  (-> (listof exact-integer?) exact-integer?)
  (* (apply bitwise-ior nums) (expt 2 (sub1 (length nums)))))

(module+ test
  (require rackunit)
  (check-equal? (subset-xor-sum '(1 3)) 6)
  (check-equal? (subset-xor-sum '(5 1 6)) 28)
  (check-equal? (subset-xor-sum '(3 4 5 6 7 8)) 480))
