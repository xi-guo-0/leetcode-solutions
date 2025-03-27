#!/usr/bin/env racket
#lang racket

(define/contract (search-insert nums target)
  (-> (listof exact-integer?) exact-integer? exact-integer?)
  (define (helper l r)
    (if (= l r)
        l
        (let* ([mid (quotient (+ l r) 2)]
               [val (list-ref nums mid)])
          (cond
            [(= target val) mid]
            [(< target val) (helper l mid)]
            [else (helper (add1 mid) r)]))))
  (helper 0 (length nums)))

(module+ test
  (require rackunit)
  (check-equal? (search-insert '[1 3 5 6] 5) 2)
  (check-equal? (search-insert '[1 3 5 6] 2) 1)
  (check-equal? (search-insert '[1 3 5 6] 7) 4))
