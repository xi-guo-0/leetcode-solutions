#!/usr/bin/env racket
#lang racket

(define/contract (partition-labels s)
  (-> string? (listof exact-integer?))
  (let* ([last-pos (last-occurrences s)]
         [len (string-length s)])
    (let loop ([i 0]
               [result '()])
      (if (>= i len)
          (reverse result)
          (let* ([c (char->integer (string-ref s i))]
                 [right (hash-ref last-pos c)]
                 [new-right (scan-range s last-pos (add1 i) right)])
            (loop (add1 new-right) (cons (add1 (- new-right i)) result)))))))

(define (scan-range s last-pos start end)
  (let inner ([j start]
              [current-end end])
    (if (>= j current-end)
        current-end
        (let* ([c (char->integer (string-ref s j))]
               [new-end (hash-ref last-pos c)])
          (inner (add1 j) (max current-end new-end))))))

(define (last-occurrences s)
  (for/fold ([h (hash)])
            ([i (in-range (string-length s))]
             [c (in-string s)])
    (hash-set h (char->integer c) i)))

(module+ test
  (require rackunit)
  (check-equal? (partition-labels "ababcbacadefegdehijhklij") '(9 7 8))
  (check-equal? (partition-labels "eccbbbbdec") '(10)))
