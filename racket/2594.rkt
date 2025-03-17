#!/usr/bin/env racket
#lang racket

(define/contract (repair-cars ranks cars)
  (-> (listof exact-integer?) exact-integer? exact-integer?)
  (define (can-repair-all? t)
    (define (cars-repaired-by-mechanic rank)
      (exact-floor (sqrt (/ t rank))))
    (>= (apply + (map cars-repaired-by-mechanic ranks)) cars))
  (define (binary-search left right)
    (if (>= left right)
        left
        (let* ([mid (quotient (+ left right) 2)]
               [can-repair? (can-repair-all? mid)])
          (if can-repair?
              (binary-search left mid)
              (binary-search (+ mid 1) right)))))
  (binary-search 1 (* (apply max ranks) cars cars)))

(module+ test
  (require rackunit)
  (check-equal? (repair-cars '(4 2 3 1) 10) 16)
  (check-equal? (repair-cars '(5 1 8) 6) 16))
