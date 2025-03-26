#!/usr/bin/env racket
#lang racket

(define/contract (min-operations grid x)
  (-> (listof (listof exact-integer?)) exact-integer? exact-integer?)
  (define r (remainder (caar grid) x))
  (call/cc (lambda (k)
             (let ([a (vector-sort (for*/vector ([l grid]
                                                 [e l])
                                     (if (not (= r (remainder e x)))
                                         (k -1)
                                         (quotient e x)))
                                   <)])
               (let ([m (vector-ref a (quotient (vector-length a) 2))])
                 (for/sum ([x a]) (abs (- x m))))))))

(module+ test
  (require rackunit)
  (check-equal? (min-operations '[[2 4] [6 8]] 2) 4)
  (check-equal? (min-operations '[[1 5] [2 3]] 1) 5)
  (check-equal? (min-operations '[[1 2] [3 4]] 2) -1))
