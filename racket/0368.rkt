#!/usr/bin/env racket
#lang racket

(define/contract (largest-divisible-subset nums)
  (-> (listof exact-integer?) (listof exact-integer?))
  (if (empty? nums)
      '()
      (let* ([sorted-nums (list->vector (sort nums <))]
             [n (vector-length sorted-nums)]
             [dp (build-vector n (λ (_) 1))]
             [prev (build-vector n (λ (_) -1))])
        (let loop ([i 1]
                   [dp dp]
                   [prev prev]
                   [max-len 1]
                   [max-idx 0])
          (if (>= i n)
              (let build-result ([idx max-idx]
                                 [result '()])
                (if (= idx -1)
                    result
                    (build-result (vector-ref prev idx) (cons (vector-ref sorted-nums idx) result))))
              (let inner-loop ([j 0]
                               [dp dp]
                               [prev prev]
                               [max-len max-len]
                               [max-idx max-idx])
                (if (>= j i)
                    (loop (add1 i) dp prev max-len max-idx)
                    (if (zero? (remainder (vector-ref sorted-nums i) (vector-ref sorted-nums j)))
                        (let ([new-len (add1 (vector-ref dp j))])
                          (if (> new-len (vector-ref dp i))
                              (inner-loop (add1 j)
                                          (vector-set/copy dp i new-len)
                                          (vector-set/copy prev i j)
                                          (if (> new-len max-len) new-len max-len)
                                          (if (> new-len max-len) i max-idx))
                              (inner-loop (add1 j) dp prev max-len max-idx)))
                        (inner-loop (add1 j) dp prev max-len max-idx)))))))))

(module+ test
  (require rackunit)
  (check-equal? (largest-divisible-subset '(1 2 3)) '(1 2))
  (check-equal? (largest-divisible-subset '(1 2 4 8)) '(1 2 4 8)))
