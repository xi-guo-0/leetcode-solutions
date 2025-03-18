#!/usr/bin/env racket
#lang racket

(define/contract (int-to-roman num)
  (-> exact-integer? string?)
  (define radix '(1000 900 500 400 100 90 50 40 10 9 5 4 1))
  (define symbol '("M" "CM" "D" "CD" "C" "XC" "L" "XL" "X" "IX" "V" "IV" "I"))

  (define (convert num radix symbol)
    (cond
      [(or (null? radix) (null? symbol)) ""]
      [else
       (let* ([value (car radix)]
              [sym (car symbol)]
              [count (quotient num value)]
              [new-num (remainder num value)])
         (string-append (apply string-append (make-list count sym))
                        (convert new-num (cdr radix) (cdr symbol))))]))
  (convert num radix symbol))

(module+ test
  (require rackunit)
  (check-equal? (int-to-roman 3749) "MMMDCCXLIX")
  (check-equal? (int-to-roman 58) "LVIII")
  (check-equal? (int-to-roman 1994) "MCMXCIV"))
