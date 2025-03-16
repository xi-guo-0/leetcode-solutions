#!/usr/bin/env racket
#lang racket

(define/contract (find-median-sorted-arrays nums1 nums2)
  (-> (listof exact-integer?) (listof exact-integer?) flonum?)

  (define (find-kth smallest-array largest-array k)
    (let* ([len-smallest (length smallest-array)]
           [len-largest (length largest-array)])
      (cond
        [(> len-smallest len-largest) (find-kth largest-array smallest-array k)]
        [(= len-smallest 0) (list-ref largest-array k)]
        [(= k 0) (min (car smallest-array) (car largest-array))]
        [else
         (let* ([i (min (quotient k 2) (sub1 len-smallest))]
                [j (- k i 1)]
                [x (list-ref smallest-array i)]
                [y (list-ref largest-array j)])
           (cond
             [(< x y) (find-kth (drop smallest-array (+ i 1)) largest-array j)]
             [else (find-kth smallest-array (drop largest-array (+ j 1)) i)]))])))

  (let* ([sorted-array1 nums1]
         [sorted-array2 nums2]
         [len-smallest (length sorted-array1)]
         [len-largest (length sorted-array2)]
         [total-length (+ len-smallest len-largest)]
         [half-length (quotient total-length 2)])
    (exact->inexact (if (odd? total-length)
                        (find-kth sorted-array1 sorted-array2 half-length)
                        (/ (+ (find-kth sorted-array1 sorted-array2 (sub1 half-length))
                              (find-kth sorted-array1 sorted-array2 half-length))
                           2.0)))))

(module+ test
  (require rackunit)
  (check-= (find-median-sorted-arrays '(1 3) '(2)) 2.0 0.01)
  (check-= (find-median-sorted-arrays '(1 2) '(3 4)) 2.5 0.01)
  (check-= (find-median-sorted-arrays '(0 0) '(0 0)) 0.0 0.01)
  (check-= (find-median-sorted-arrays '(1) '(2 3 4)) 2.5 0.01))
