#!/usr/bin/env racket
#lang racket

(define/contract (divide-array nums)
  (-> (listof exact-integer?) boolean?)
  (andmap (compose even? length) (group-by identity nums)))

(module+ test
  (require rackunit)
  (check-true (divide-array '(3 2 3 2 2 2)))
  (check-false (divide-array '(1 2 3 4))))
