#!/usr/bin/env racket
#lang racket

(define/contract (good-triplets nums1 nums2)
  (-> (listof exact-integer?) (listof exact-integer?) exact-integer?)
  (let* ([n (length nums1)]
         [pos1 (make-vector n 0)])
    (for ([(v i) (in-indexed nums1)])
      (vector-set! pos1 v i))
    (let* ([combined-pos (for/vector ([v (in-list nums2)])
                           (vector-ref pos1 v))]
           [ft (make-vector (add1 n) 0)])
      (let loop ([i 0]
                 [res 0])
        (if (= i n)
            res
            (let* ([pos (vector-ref combined-pos i)]
                   [left (let q-loop ([idx (add1 pos)]
                                      [sum 0])
                           (if (<= idx 0)
                               sum
                               (let ([lsb (bitwise-and idx (- idx))])
                                 (q-loop (- idx lsb) (+ sum (vector-ref ft idx))))))]
                   [_ (let u-loop ([idx (add1 pos)])
                        (when (< idx (vector-length ft))
                          (vector-set! ft idx (add1 (vector-ref ft idx)))
                          (u-loop (+ idx (bitwise-and idx (- idx))))))]
                   [right (- (- (sub1 n) pos) (- i left))])
              (loop (add1 i) (+ res (* left right)))))))))

(module+ test
  (require rackunit)
  (check-equal? (good-triplets '(2 0 1 3) '(0 1 2 3)) 1)
  (check-equal? (good-triplets '(4 0 1 3 2) '(4 1 0 2 3)) 4))
