#!/usr/bin/env racket
#lang racket

(define/contract (reverse x)
  (-> exact-integer? exact-integer?)

  (define INT_MIN (- #x80000000))
  (define INT_MAX #x7FFFFFFF)

  (define (digits n)
    (if (= n 0)
        '()
        (cons (modulo n 10) (digits (quotient n 10)))))

  (define (reverse-digits digits)
    (foldl (lambda (digit acc) (+ (* acc 10) digit)) 0 digits))

  (let* ([sign (if (< x 0) -1 1)]
         [abs-x (abs x)]
         [reversed (reverse-digits (digits abs-x))]
         [reversed-x (* sign reversed)])
    (if (or (< reversed-x INT_MIN) (> reversed-x INT_MAX)) 0 reversed-x)))

(module+ test
  (require rackunit)
  (check-equal? (reverse 123) 321)
  (check-equal? (reverse -123) -321)
  (check-equal? (reverse 120) 21))
