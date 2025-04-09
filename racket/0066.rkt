#!/usr/bin/env racket
#lang racket

(define/contract (plus-one digits)
  (-> (listof exact-integer?) (listof exact-integer?))
  (let loop ([digits (reverse digits)]
             [carry 1]
             [result '()])
    (if (null? digits)
        (if (zero? carry)
            result
            (cons carry result))
        (let* ([sum (+ (car digits) carry)]
               [new-digit (remainder sum 10)]
               [new-carry (quotient sum 10)])
          (loop (cdr digits) new-carry (cons new-digit result))))))

(module+ test
  (require rackunit)
  (check-equal? (plus-one '(1 2 3)) '(1 2 4))
  (check-equal? (plus-one '(4 3 2 1)) '(4 3 2 2))
  (check-equal? (plus-one '(9)) '(1 0)))
