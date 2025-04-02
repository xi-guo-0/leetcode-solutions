#!/usr/bin/env racket
#lang racket

(define/contract (longest-valid-parentheses s)
  (-> string? exact-integer?)
  (let loop ([i 0]
             [stack '(-1)]
             [max-len 0])
    (cond
      [(= i (string-length s)) max-len]
      [(char=? (string-ref s i) #\() (loop (add1 i) (cons i stack) max-len)]
      [else
       (let* ([stack (cdr stack)])
         (if (null? stack)
             (loop (add1 i) (list i) max-len)
             (loop (add1 i) stack (max max-len (- i (car stack))))))])))

(module+ test
  (require rackunit)
  (check-equal? (longest-valid-parentheses "(()") 2)
  (check-equal? (longest-valid-parentheses ")()())") 4)
  (check-equal? (longest-valid-parentheses "") 0)
  (check-equal? (longest-valid-parentheses ")()())()()(") 4))
