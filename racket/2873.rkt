#!/usr/bin/env racket
#lang racket

(define/contract (maximum-triplet-value nums)
  (-> (listof exact-integer?) exact-integer?)
  (let ([nums (list->vector nums)])
    (apply max
           (cons 0
                 (for*/list ([i (range (vector-length nums))]
                             [j (range (add1 i) (vector-length nums))]
                             [k (range (add1 j) (vector-length nums))])
                   (* (- (vector-ref nums i) (vector-ref nums j)) (vector-ref nums k)))))))

(module+ test
  (require rackunit)
  (check-equal? (maximum-triplet-value '(12 6 1 2 7)) 77)
  (check-equal? (maximum-triplet-value '(1 10 3 4 19)) 133)
  (check-equal? (maximum-triplet-value '(1 2 3)) 0))
