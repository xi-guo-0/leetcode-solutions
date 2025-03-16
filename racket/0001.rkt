#!/usr/bin/env racket
#lang racket

(define/contract (two-sum nums target)
  (-> (listof exact-integer?) exact-integer? (listof exact-integer?))
  (define (helper s i)
    (let* ([v (list-ref nums i)]
           [diff (- target v)])
      (if (hash-has-key? s diff)
          (list (hash-ref s diff) i)
          (helper (hash-set s v i) (add1 i)))))
  (helper (hash) 0))

(module+ test
  (require rackunit)
  (check-equal? (two-sum '(2 7 11 15) 9) '(0 1))
  (check-equal? (two-sum '(3 2 4) 6) '(1 2))
  (check-equal? (two-sum '(3 3) 6) '(0 1)))
