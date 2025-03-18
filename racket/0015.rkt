#!/usr/bin/env racket
#lang racket

(define/contract (three-sum nums)
  (-> (listof exact-integer?) (listof (listof exact-integer?)))
  (define (indices nums)
    (foldl (lambda (x i acc) (hash-set acc x i)) #hash() nums (range (length nums))))
  (define rights (indices nums))
  (define (two-sum-acc nums target j acc)
    (match nums
      ['() acc]
      [(cons x xs)
       (let* ([k-found (hash-ref rights (- target x) #f)])
         (if (and k-found (> k-found j))
             (two-sum-acc xs target (add1 j) (cons (sort (list (- target) x (- target x)) <) acc))
             (two-sum-acc xs target (add1 j) acc)))]))
  (define (three-sum-acc nums i acc)
    (match nums
      ['() acc]
      [(cons y ys) (three-sum-acc ys (add1 i) (two-sum-acc ys (- y) (add1 i) acc))]))
  (remove-duplicates (three-sum-acc nums 0 '())))

(module+ test
  (require rackunit)
  (check-equal? (three-sum '(-1 0 1 2 -1 -4)) '((-1 0 1) (-1 -1 2)))
  (check-equal? (three-sum '(0 1 1)) '())
  (check-equal? (three-sum '(0 0 0)) '((0 0 0))))
