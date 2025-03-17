#!/usr/bin/env racket
#lang racket

(define/contract (dist-money money children)
  (-> exact-integer? exact-integer? exact-integer?)
  (cond
    [(< money children) -1]
    [else
     (let* ([max-8 (min children (quotient (- money children) 7))]
            [remaining-money (- money (* max-8 8))]
            [remaining-children (- children max-8)])
       (cond
         [(and (= remaining-children 1) (= remaining-money 4)) (- max-8 1)]
         [(= remaining-children 0)
          (if (= remaining-money 0)
              max-8
              (- max-8 1))]
         [else max-8]))]))

(module+ test
  (require rackunit)
  (check-equal? (dist-money 20 3) 1)
  (check-equal? (dist-money 16 2) 2))
