#!/usr/bin/env racket
#lang racket

(define/contract (find-substring s words)
  (-> string? (listof string?) (listof exact-integer?))
  (define (count-words words)
    (foldl (lambda (word dict) (hash-update dict word add1 (lambda () 0))) (hash) words))
  (define (valid-substring? s words-dict word-length)
    (let loop ([i 0]
               [current-dict (hash)])
      (cond
        [(= i (string-length s)) (equal? current-dict words-dict)]
        [else
         (let* ([word (substring s i (+ i word-length))]
                [count (hash-ref words-dict word #f)])
           (if count
               (let ([new-count (add1 (hash-ref current-dict word 0))])
                 (if (> new-count count)
                     #f
                     (loop (+ i word-length) (hash-update current-dict word add1 (lambda () 0)))))
               #f))])))
  (if (or (null? words) (zero? (string-length s)))
      '()
      (let* ([word-length (string-length (first words))]
             [total-words (length words)]
             [total-length (* word-length total-words)]
             [s-length (string-length s)]
             [words-dict (count-words words)])
        (if (> total-length s-length)
            '()
            (let loop ([start 0]
                       [result '()])
              (if (> (+ start total-length) s-length)
                  (reverse result)
                  (let ([sub (substring s start (+ start total-length))])
                    (if (valid-substring? sub words-dict word-length)
                        (loop (add1 start) (cons start result))
                        (loop (add1 start) result)))))))))

(module+ test
  (require rackunit)
  (check-equal? (find-substring "barfoothefoobarman" '("foo" "bar")) '(0 9))
  (check-equal? (find-substring "wordgoodgoodgoodbestword" '("word" "good" "best" "word")) '())
  (check-equal? (find-substring "barfoofoobarthefoobarman" '("bar" "foo" "the")) '(6 9 12)))
