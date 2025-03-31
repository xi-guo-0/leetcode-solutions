#!/usr/bin/env racket
#lang racket

(define/contract (str-str haystack needle)
  (-> string? string? exact-integer?)
  (let loop ([start 0]
             [end (string-length needle)])
    (if (> end (string-length haystack))
        -1
        (if (equal? (substring haystack start end) needle)
            start
            (loop (add1 start) (add1 end))))))

(module+ test
  (require rackunit)
  (check-equal? (str-str "sadbutsad" "sad") 0)
  (check-equal? (str-str "leetcode" "leeto") -1))
