#!/usr/bin/env racket
#lang racket

(define/contract (my-atoi s)
  (-> string? exact-integer?)
  (define INT_MIN (- #x80000000))
  (define INT_MAX #x7FFFFFFF)
  (define regex #px"^[[:space:]]*([+-]?)0*(\\d+).*")
  (define (parse-number s)
    (match (regexp-match regex s)
      [(list _ sign-str num-str)
       (define sign (if (equal? sign-str "-") -1 1))
       (define num (string->number num-str))
       (define result (* sign num))
       (cond
         [(< result INT_MIN) INT_MIN]
         [(> result INT_MAX) INT_MAX]
         [else result])]
      [_ 0]))
  (parse-number s))

(module+ test
  (require rackunit)
  (check-equal? (my-atoi "42") 42)
  (check-equal? (my-atoi "-042") -42)
  (check-equal? (my-atoi "1337c0d3") 1337)
  (check-equal? (my-atoi "0-1") 0)
  (check-equal? (my-atoi "words and 987") 0))
