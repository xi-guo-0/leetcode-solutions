#!/usr/bin/env racket
#lang racket

(define/contract (put-marbles weights k)
  (-> (listof exact-integer?) exact-integer? exact-integer?)

  (define (sliding lst size)
    (if (< (length lst) size)
        '()
        (cons (take lst size) (sliding (cdr lst) size))))

  (if (empty? weights)
      0
      (let* ([n (length weights)]
             [k (min k n)]
             [weight-pairs (for/list ([pair (sliding weights 2)])
                             (apply + pair))]
             [sorted-pairs (sort weight-pairs <)]
             [smallest-sum (apply + (take sorted-pairs (min (sub1 k) (length sorted-pairs))))]
             [largest-sum (apply +
                                 (take (reverse sorted-pairs) (min (sub1 k) (length sorted-pairs))))])
        (- largest-sum smallest-sum))))

(module+ test
  (require rackunit)
  (check-equal? (put-marbles '(1 3 5 1) 2) 4)
  (check-equal? (put-marbles '(1 3) 2) 0))
