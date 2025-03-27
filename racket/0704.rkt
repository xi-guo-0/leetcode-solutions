#!/usr/bin/env racket
#lang racket

(define/contract (search nums target)
  (-> (listof exact-integer?) exact-integer? exact-integer?)
  (define (helper left right)
    (if (= left right)
        -1
        (let* ([mid (quotient (+ left right) 2)]
               [val (list-ref nums mid)])
          (cond
            [(= val target) mid]
            [(< val target) (helper (add1 mid) right)]
            [else (helper left mid)]))))
  (helper 0 (length nums)))

(module+ test
  (require rackunit)
  (check-equal? (search '[-1 0 3 5 9 12] 9) 4)
  (check-equal? (search '[-1 0 3 5 9 12] 2) -1))
