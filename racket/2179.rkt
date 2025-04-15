#!/usr/bin/env racket
#lang racket

(define/contract (good-triplets nums1 nums2)
  (-> (listof exact-integer?) (listof exact-integer?) exact-integer?)

  (let* ([n (length nums1)]
         [pos1 (make-vector n 0)]
         [pos2 (make-vector n 0)])
    (for ([(v i) (in-indexed nums1)])
      (vector-set! pos1 v i))
    (for ([(v i) (in-indexed nums2)])
      (vector-set! pos2 v i))
    (let ([combined-pos (for/list ([v (in-list nums1)])
                          (vector-ref pos2 v))])
      (let ([ft (make-vector (add1 n) 0)])
        (let loop ([i 0]
                   [res 0])
          (if (= i n)
              res
              (let* ([pos (list-ref combined-pos i)]
                     [left (let loop-query ([idx (add1 pos)]
                                            [sum 0])
                             (if (<= idx 0)
                                 sum
                                 (let ([lsb (bitwise-and idx (- idx))])
                                   (loop-query (- idx lsb) (+ sum (vector-ref ft idx))))))]
                     [_ (let loop-update ([idx (add1 pos)])
                          (when (< idx (vector-length ft))
                            (vector-set! ft idx (add1 (vector-ref ft idx)))
                            (loop-update (+ idx (bitwise-and idx (- idx))))))]
                     [right (- (- (sub1 n) pos) (- i left))])
                (loop (add1 i) (+ res (* left right))))))))))

(module+ test
  (require rackunit)
  (check-equal? (good-triplets '(2 0 1 3) '(0 1 2 3)) 1)
  (check-equal? (good-triplets '(4 0 1 3 2) '(4 1 0 2 3)) 4))
