#!/usr/bin/env racket
#lang racket

(define/contract (minimum-operations nums)
  (-> (listof exact-integer?) exact-integer?)
  (let loop ([current-nums nums]
             [ops 0])
    (cond
      [(null? current-nums) ops]
      [(= (length (remove-duplicates current-nums)) (length current-nums)) ops]
      [else
       (loop (if (>= (length current-nums) 3)
                 (drop current-nums 3)
                 '())
             (add1 ops))])))

(module+ test
  (require rackunit)
  (check-equal? (minimum-operations '(1 2 3 4 2 3 3 5 7)) 2)
  (check-equal? (minimum-operations '(4 5 6 4 4)) 2)
  (check-equal? (minimum-operations '(6 7 8 9)) 0))
