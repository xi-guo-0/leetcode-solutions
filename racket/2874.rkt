#!/usr/bin/env racket
#lang racket

(define/contract (maximum-triplet-value nums)
  (-> (listof exact-integer?) exact-integer?)
  (let loop ([remaining-nums nums]
             [max-i 0]
             [max-diff 0]
             [max-result 0])
    (if (null? remaining-nums)
        max-result
        (let* ([current-num (car remaining-nums)]
               [new-result (max max-result (* max-diff current-num))]
               [new-max-diff (max max-diff (- max-i current-num))]
               [new-max-i (max max-i current-num)])
          (loop (cdr remaining-nums) new-max-i new-max-diff new-result)))))

(module+ test
  (require rackunit)
  (check-equal? (maximum-triplet-value '(12 6 1 2 7)) 77)
  (check-equal? (maximum-triplet-value '(1 10 3 4 19)) 133)
  (check-equal? (maximum-triplet-value '(1 2 3)) 0))
