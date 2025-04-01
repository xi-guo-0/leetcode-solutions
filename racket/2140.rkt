#!/usr/bin/env racket
#lang racket

(define/contract (most-points questions)
  (-> (listof (listof exact-integer?)) exact-integer?)
  (let recur ([i 0]
              [memo (hash)])
    (cond
      [(>= i (length questions)) 0]
      [(hash-ref memo i #f)
       =>
       values]
      [else
       (let* ([q (list-ref questions i)]
              [points (first q)]
              [brainpower (second q)]
              [take-points (+ points (recur (+ i brainpower 1) memo))]
              [skip-points (recur (+ i 1) memo)]
              [max-points (max take-points skip-points)]
              [new-memo (hash-set memo i max-points)])
         (recur i new-memo))])))

(module+ test
  (require rackunit)
  (check-equal? (most-points '((3 2) (4 3) (4 4) (2 5))) 5)
  (check-equal? (most-points '((1 1) (2 2) (3 3) (4 4) (5 5))) 7))
