#!/usr/bin/env racket
#lang racket

(define (scanl f init lst)
  (reverse (foldl (λ (x acc) (cons (f x (car acc)) acc)) (list init) lst)))

(define/contract (trap height)
  (-> (listof exact-integer?) exact-integer?)
  (let* ([n (length height)]
         [max-left (scanl max 0 (take height (- n 1)))]
         [max-right (reverse (scanl max 0 (take (reverse height) (- n 1))))]
         [water-levels (map min max-left max-right)]
         [deltas (map (λ (h wl) (max 0 (- wl h))) height water-levels)])
    (foldl + 0 deltas)))

(module+ test
  (require rackunit)
  (check-equal? (trap '(0 1 0 2 1 0 1 3 2 1 2 1)) 6)
  (check-equal? (trap '(4 2 0 3 2 5)) 9))
