#!/usr/bin/env racket
#lang racket

(define/contract (length-of-longest-substring s)
  (-> string? exact-integer?)
  (define (find-longest idx last-occurence start idx-max)
    (if (>= idx (string-length s))
        idx-max
        (let* ([char (string-ref s idx)]
               [new-start (max start (hash-ref last-occurence char -1))])
          (find-longest (add1 idx)
                        (hash-set last-occurence char idx)
                        new-start
                        (max idx-max (- idx new-start))))))
  (find-longest 0 (hash) -1 0))

(module+ test
  (require rackunit)
  (check-equal? (length-of-longest-substring "abcabcbb") 3)
  (check-equal? (length-of-longest-substring "bbbbb") 1)
  (check-equal? (length-of-longest-substring "pwwkew") 3))
