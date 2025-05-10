#!/usr/bin/env racket
#lang racket

(define/contract (min-sum nums1 nums2)
  (-> (listof exact-integer?) (listof exact-integer?) exact-integer?)
  (let* ([count-zero (λ (nums) (length (filter zero? nums)))]
         [sum-non-zero (λ (nums) (apply + (filter (λ (x) (> x 0)) nums)))]
         [cnt1 (count-zero nums1)]
         [cnt2 (count-zero nums2)]
         [s1 (+ (sum-non-zero nums1) cnt1)]
         [s2 (+ (sum-non-zero nums2) cnt2)])
    (cond
      [(and (= cnt1 0) (< s1 s2)) -1]
      [(and (= cnt2 0) (< s2 s1)) -1]
      [else (max s1 s2)])))

(module+ test
  (require rackunit)
  (check-equal? (min-sum '(3 2 0 1 0) '(6 5 0)) 12)
  (check-equal? (min-sum '(2 0 2 0) '(1 4)) -1))
