#!/usr/bin/env racket
#lang racket

(define/contract (num-rabbits answers)
  (-> (listof exact-integer?) exact-integer?)
  (let* ([group-sizes (map add1 answers)]
         [grouped (group-by identity group-sizes)])
    (for/sum ([group grouped])
             (let ([size (car group)]
                   [count (length group)])
               (* (quotient (sub1 (+ count size)) size) size)))))

(module+ test
  (require rackunit)
  (check-equal? (num-rabbits '(1 1 2)) 5)
  (check-equal? (num-rabbits '(10 10 10)) 11))
