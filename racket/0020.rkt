#!/usr/bin/env racket
#lang racket

(define/contract (is-valid s)
  (-> string? boolean?)
  (let ([brackets (make-hash '((#\( . #\)) (#\[ . #\]) (#\{ . #\})))])
    (let loop ([L (string->list s)]
               [stack '()])
      (cond
        [(empty? L) (empty? stack)]
        [(member (car L) (hash-keys brackets)) (loop (cdr L) (cons (car L) stack))]
        [else
         (if (or (empty? stack) (not (char=? (car L) (hash-ref brackets (car stack) #f))))
             #f
             (loop (cdr L) (cdr stack)))]))))

(module+ test
  (require rackunit)
  (check-true (is-valid "()"))
  (check-true (is-valid "()[]{}"))
  (check-false (is-valid "(]"))
  (check-true (is-valid "([])")))
