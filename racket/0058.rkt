#!/usr/bin/env racket
#lang racket

(define/contract (length-of-last-word s)
  (-> string? exact-integer?)
  (string-length (last (string-split s))))

(module+ test
  (require rackunit)
  (check-equal? (length-of-last-word "Hello World") 5)
  (check-equal? (length-of-last-word "   fly me   to   the moon  ") 4)
  (check-equal? (length-of-last-word "luffy is still joyboy") 6))
