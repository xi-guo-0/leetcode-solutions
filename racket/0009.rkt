#!/usr/bin/env racket
#lang racket

(define/contract (is-palindrome x)
  (-> exact-integer? boolean?)
  (define (palindrome? str)
    (equal? str (list->string (reverse (string->list str)))))
  (palindrome? (number->string x)))

(module+ test
  (require rackunit)
  (check-true (is-palindrome 121))
  (check-false (is-palindrome -121))
  (check-false (is-palindrome 10)))
