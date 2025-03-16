#!/usr/bin/env racket
#lang racket

(define/contract (longest-palindrome s)
  (-> string? string?)
  (define (expand-around-center s left right)
    (let loop ([l left]
               [r right])
      (if (and (>= l 0) (< r (string-length s)) (char=? (string-ref s l) (string-ref s r)))
          (loop (sub1 l) (add1 r))
          (substring s (add1 l) r))))
  (define (find-longest-palindrome s i longest)
    (if (>= i (string-length s))
        longest
        (let* ([odd-palindrome (expand-around-center s i i)]
               [new-longest (if (> (string-length odd-palindrome) (string-length longest))
                                odd-palindrome
                                longest)]
               [even-palindrome (expand-around-center s i (add1 i))]
               [new-longest (if (> (string-length even-palindrome) (string-length new-longest))
                                even-palindrome
                                new-longest)])
          (find-longest-palindrome s (add1 i) new-longest))))
  (if (zero? (string-length s))
      ""
      (find-longest-palindrome s 0 "")))

#;(define/contract (longest-palindrome s)
    (-> string? string?)
    (define (palindrome? str)
      (equal? str (list->string (reverse (string->list str)))))
    (define (all-substrings s)
      (define len (string-length s))
      (for*/list ([i (in-range len)]
                  [j (in-range (add1 i) (add1 len))])
        (substring s i j)))
    (define palindromes (filter palindrome? (all-substrings s)))
    (if (null? palindromes)
        ""
        (argmax string-length palindromes)))

(module+ test
  (require rackunit)
  (check-equal? (longest-palindrome "babad") "bab")
  (check-equal? (longest-palindrome "cbbd") "bb"))
