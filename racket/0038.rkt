#!/usr/bin/env racket
#lang racket

(define (encode str)
  (regexp-replace* #px"(.)\\1*" str (λ (m c) (~a (string-length m) c))))
(define (decode str)
  (regexp-replace* #px"([0-9]+)(.)"
                   str
                   (λ (m n c) (make-string (string->number n) (string-ref c 0)))))

(define/contract (count-and-say n)
  (-> exact-integer? string?)
  (for/fold ([result "1"]) ([_ (in-range (sub1 n))])
    (encode result)))

(module+ test
  (require rackunit)
  (check-equal? (count-and-say 4) "1211")
  (check-equal? (count-and-say 1) "1"))
