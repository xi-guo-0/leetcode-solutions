#!/usr/bin/env racket
#lang racket

(define/contract (three-consecutive-odds arr)
  (-> (listof exact-integer?) boolean?)
  (match arr
    [(cons a (cons b (cons c d)))
     (or (and (odd? a) (odd? b) (odd? c)) (three-consecutive-odds (cons b (cons c d))))]
    [else #f]))

(module+ test
  (require rackunit)
  (check-false (three-consecutive-odds '(2 6 4 1)))
  (check-true (three-consecutive-odds '(1 2 34 3 4 5 7 23 12))))
