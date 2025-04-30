#!/usr/bin/env racket
#lang racket

(define/contract (find-numbers nums)
  (-> (listof exact-integer?) exact-integer?)
  (count (lambda (n) (even? (string-length (number->string n)))) nums))

(module+ test
  (require rackunit)
  (check-equal? (find-numbers '(12 345 2 6 7896)) 2)
  (check-equal? (find-numbers '(555 901 482 1771)) 1))
