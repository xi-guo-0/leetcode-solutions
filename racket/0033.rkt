#!/usr/bin/env racket
#lang racket

(define/contract (search nums target)
  (-> (listof exact-integer?) exact-integer? exact-integer?)
  (define (search-helper nums first last)
    (if (= first last)
        -1
        (let* ([mid (+ first (quotient (- last first) 2))]
               [mid-value (list-ref nums mid)])
          (cond
            [(= mid-value target) mid]
            [(<= (list-ref nums first) mid-value)
             (if (and (<= (list-ref nums first) target) (< target mid-value))
                 (search-helper nums first mid)
                 (search-helper nums (+ mid 1) last))]
            [else
             (if (and (> (list-ref nums mid) target) (<= target (list-ref nums (- last 1))))
                 (search-helper nums first mid)
                 (search-helper nums (+ mid 1) last))]))))
  (search-helper nums 0 (length nums)))

(module+ test
  (require rackunit)
  (check-equal? (search '(4 5 6 7 0 1 2) 0) 4)
  (check-equal? (search '(4 5 6 7 0 1 2) 3) -1)
  (check-equal? (search '(1) 0) -1))
