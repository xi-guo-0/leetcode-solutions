#!/usr/bin/env racket
#lang racket

(define/contract (top-k-frequent words k)
  (-> (listof string?) exact-integer? (listof string?))
  (define (cmp a b)
    (let ([al (car a)]
          [ar (cdr a)]
          [bl (car b)]
          [br (cdr b)])
      (if (= ar br)
          (string<? al bl)
          (> ar br))))
  (let ([ls (map (lambda (ws) (cons (car ws) (length ws))) (group-by identity words))])
    (map car (take (sort ls cmp) k))))

(module+ test
  (require rackunit)
  (check-equal? (top-k-frequent '["i" "love" "leetcode" "i" "love" "coding"] 2) '["i" "love"])
  (check-equal? (top-k-frequent '["the" "day" "is" "sunny" "the" "the" "the" "sunny" "is" "is"] 4)
                '["the" "is" "sunny" "day"]))
