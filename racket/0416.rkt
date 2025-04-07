#!/usr/bin/env racket
#lang racket

(define/contract (can-partition nums)
  (-> (listof exact-integer?) boolean?)
  (let ([sum (apply + nums)])
    (if (odd? sum)
        #f
        (let ([target (quotient sum 2)])
          (letrec ([helper (lambda (remaining-nums dp)
                             (if (null? remaining-nums)
                                 (vector-ref dp target)
                                 (let ([num (car remaining-nums)])
                                   (helper (cdr remaining-nums)
                                           (for/vector ([i (in-range (add1 target))])
                                             (or (vector-ref dp i)
                                                 (and (>= i num) (vector-ref dp (- i num)))))))))])
            (helper nums (build-vector (add1 target) (λ (i) (zero? i)))))))))

(module+ test
  (require rackunit)
  (check-true (can-partition '(1 5 11 5)))
  (check-false (can-partition '(1 2 3 5))))
