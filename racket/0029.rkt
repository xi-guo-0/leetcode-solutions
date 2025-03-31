#!/usr/bin/env racket
#lang racket

(define/contract (divide dividend divisor)
  (-> exact-integer? exact-integer? exact-integer?)
  (define (subtract-loop dividend divisor quotient)
    (if (< dividend divisor)
        quotient
        (let loop ([current divisor]
                   [multiple 1])
          (if (<= (+ current current) dividend)
              (loop (+ current current) (+ multiple multiple))
              (subtract-loop (- dividend current) divisor (+ quotient multiple))))))
  (if (and (= dividend -2147483648) (= divisor -1))
      2147483647
      (let* ([negative? (not (equal? (negative? dividend) (negative? divisor)))]
             [dividend (abs dividend)]
             [divisor (abs divisor)]
             [result (subtract-loop dividend divisor 0)])
        (if negative?
            (- result)
            result))))

(module+ test
  (require rackunit)
  (check-equal? (divide 10 3) 3)
  (check-equal? (divide 7 -3) -2))
