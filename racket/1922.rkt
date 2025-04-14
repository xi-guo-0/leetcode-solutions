#!/usr/bin/env racket
#lang racket

(define (pow-mod a b mod)
  (cond
    [(= b 0) 1]
    [(even? b) (modulo (sqr (pow-mod a (quotient b 2) mod)) mod)]
    [else (modulo (* a (pow-mod a (sub1 b) mod)) mod)]))

(define/contract (count-good-numbers n)
  (-> exact-integer? exact-integer?)
  (let ([MOD 1000000007])
    (let* ([even-count (quotient (+ n 1) 2)]
           [odd-count (quotient n 2)]
           [pow5 (pow-mod 5 even-count MOD)]
           [pow4 (pow-mod 4 odd-count MOD)])
      (modulo (* pow5 pow4) MOD))))

(module+ test
  (require rackunit)
  (check-equal? (count-good-numbers 1) 5)
  (check-equal? (count-good-numbers 4) 400)
  (check-equal? (count-good-numbers 50) 564908303))
