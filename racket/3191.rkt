#!/usr/bin/env racket
#lang racket

(define/contract (min-operations nums)
  (-> (listof exact-integer?) exact-integer?)
  (let recur ([nums nums]
              [count 0])
    (cond
      [(empty? (cddr nums)) (if (or (zero? (first nums)) (zero? (second nums))) -1 count)]
      [(zero? (first nums))
       (recur (cons (- 1 (second nums)) (cons (- 1 (third nums)) (cdddr nums))) (add1 count))]
      [else (recur (rest nums) count)])))

(module+ test
  (require rackunit)
  (check-equal? (min-operations '(0 1 1 1 0 0)) 3)
  (check-equal? (min-operations '(0 1 1 1)) -1))
