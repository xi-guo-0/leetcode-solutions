#!/usr/bin/env racket
#lang racket

(define/contract (generate-parenthesis n)
  (-> exact-integer? (listof string?))
  (define (loop left right parens acc)
    (cond
      [(= right n) (cons (list->string (reverse parens)) acc)]
      [(= left n) (loop left (add1 right) (cons #\) parens) acc)]
      [(< right left)
       (append (loop (add1 left) right (cons #\( parens) acc)
               (loop left (add1 right) (cons #\) parens) acc))]
      [else (loop (add1 left) right (cons #\( parens) acc)]))

  (loop 0 0 '() '()))

(module+ test
  (require rackunit)
  (check-equal? (generate-parenthesis 3) (list "((()))" "(()())" "(())()" "()(())" "()()()"))
  (check-equal? (generate-parenthesis 1) (list "()")))
