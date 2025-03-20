#!/usr/bin/env racket
#lang racket

(define/contract (three-sum-closest nums target)
  (-> (listof exact-integer?) exact-integer? exact-integer?)
  (define sorted-nums (sort nums <))
  (define len (length sorted-nums))
  (define closest-sum (+ (list-ref sorted-nums 0) (list-ref sorted-nums 1) (list-ref sorted-nums 2)))
  (define (update-closest-sum current-sum)
    (if (< (abs (- current-sum target)) (abs (- closest-sum target))) current-sum closest-sum))
  (for ([i (in-range (- len 2))])
    (let loop ([left (add1 i)]
               [right (sub1 len)])
      (when (< left right)
        (define current-sum
          (+ (list-ref sorted-nums i) (list-ref sorted-nums left) (list-ref sorted-nums right)))
        (set! closest-sum (update-closest-sum current-sum))
        (cond
          [(= current-sum target) (set! closest-sum current-sum)]
          [(> current-sum target) (loop left (sub1 right))]
          [else (loop (add1 left) right)]))))
  closest-sum)

(module+ test
  (require rackunit)

  (check-equal? (three-sum-closest '(-1 2 1 -4) 1) 2)
  (check-equal? (three-sum-closest '(0 0 0) 1) 0))
