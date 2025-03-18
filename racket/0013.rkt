#!/usr/bin/env racket
#lang racket

(define/contract (roman-to-int s)
  (-> string? exact-integer?)
  (define rti (hash #\I 1 #\V 5 #\X 10 #\L 50 #\C 100 #\D 500 #\M 1000))
  (define (process-chars s prev-val total)
    (cond
      [(empty? s) total]
      [(> (hash-ref rti (first s) 0) prev-val)
       (process-chars (rest s)
                      (hash-ref rti (first s) 0)
                      (+ total (- (hash-ref rti (first s) 0) (* 2 prev-val))))]
      [else
       (process-chars (rest s) (hash-ref rti (first s) 0) (+ total (hash-ref rti (first s) 0)))]))
  (process-chars (string->list s) 0 0))

(module+ test
  (require rackunit)
  (check-equal? (roman-to-int "III") 3)
  (check-equal? (roman-to-int "LVIII") 58)
  (check-equal? (roman-to-int "MCMXCIV") 1994))
