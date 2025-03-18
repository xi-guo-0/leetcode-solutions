#!/usr/bin/env racket
#lang racket

(define/contract (longest-common-prefix strs)
  (-> (listof string?) string?)
  (define (common-prefix str1 str2)
    (define (loop i)
      (cond
        [(or (= i (string-length str1)) (= i (string-length str2))) (substring str1 0 i)]
        [(char=? (string-ref str1 i) (string-ref str2 i)) (loop (+ i 1))]
        [else (substring str1 0 i)]))
    (loop 0))
  (define (reduce-prefix strs)
    (foldl common-prefix (first strs) (rest strs)))
  (if (null? strs)
      ""
      (reduce-prefix strs)))

(module+ test
  (require rackunit)
  (check-equal? (longest-common-prefix '("flower" "flow" "flight")) "fl")
  (check-equal? (longest-common-prefix '("dog" "racecar" "car")) ""))
