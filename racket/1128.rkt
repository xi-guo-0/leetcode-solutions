#!/usr/bin/env racket
#lang racket

(define/contract (num-equiv-domino-pairs dominoes)
  (-> (listof (listof exact-integer?)) exact-integer?)
  (let ([groups (group-by identity (map (lambda (sublist) (sort sublist <)) dominoes))])
    (for/sum ([g groups]) (let ([n (length g)]) (/ (* n (sub1 n)) 2)))))

(module+ test
  (require rackunit)
  (check-equal? (num-equiv-domino-pairs '((1 2) (2 1) (3 4) (5 6))) 1)
  (check-equal? (num-equiv-domino-pairs '((1 2) (1 2) (1 1) (1 2) (2 2))) 3))
