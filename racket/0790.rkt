#!/usr/bin/env racket
#lang racket

(define/contract (num-tilings n)
  (-> exact-integer? exact-integer?)
  (cond
    [(= n 1) 1]
    [(= n 2) 2]
    [else
     (let loop ([i 3]
                [p3 1]
                [p2 1]
                [p1 2])
       (define current (modulo (+ (* 2 p1) p3) 1000000007))
       (if (= i n)
           current
           (loop (add1 i) p2 p1 current)))]))

(module+ test
  (require rackunit)
  (check-eq? (num-tilings 3) 5)
  (check-eq? (num-tilings 1) 1)
  (check-eq? (num-tilings 4) 11)
  (check-eq? (num-tilings 5) 24))
