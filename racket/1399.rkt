#!/usr/bin/env racket
#lang racket

(define (sum-digits x)
  (let loop ([x x]
             [sum 0])
    (if (zero? x)
        sum
        (loop (quotient x 10) (+ sum (remainder x 10))))))

(define/contract (count-largest-group n)
  (-> exact-integer? exact-integer?)
  (let* ([sums (map sum-digits (range 1 (add1 n)))]
         [freq (foldl (lambda (s h) (hash-update h s add1 0)) #hash() sums)]
         [counts (hash-values freq)]
         [max-count (if (null? counts)
                        0
                        (apply max counts))])
    (count (lambda (c) (= c max-count)) counts)))

(module+ test
  (require rackunit)
  (check-equal? (count-largest-group 13) 4)
  (check-equal? (count-largest-group 2) 2))
