#!/usr/bin/env racket
#lang racket

(define/contract (is-match s p)
  (-> string? string? boolean?)
  (define (match-helper s p)
    (cond
      [(and (string=? s "") (string=? p "")) #t]
      [(string=? p "") #f]
      [(and (> (string-length p) 1) (char=? (string-ref p 1) #\*))
       (or (match-helper s (substring p 2))
           (and (not (string=? s ""))
                (or (char=? (string-ref p 0) #\.) (char=? (string-ref s 0) (string-ref p 0)))
                (match-helper (substring s 1) p)))]
      [else
       (and (not (string=? s ""))
            (or (char=? (string-ref p 0) #\.) (char=? (string-ref s 0) (string-ref p 0)))
            (match-helper (substring s 1) (substring p 1)))]))
  (match-helper s p))

(module+ test
  (require rackunit)
  (check-false (is-match "aa" "a"))
  (check-true (is-match "aa" "a*"))
  (check-true (is-match "ab" ".*")))
