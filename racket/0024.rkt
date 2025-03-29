#!/usr/bin/env racket
#lang racket

; val : integer?
; next : (or/c list-node? #f)
(struct list-node (val next) #:mutable #:transparent)

; constructor
(define (make-list-node [val 0])
  (list-node val #f))

(define/contract (swap-pairs head)
  (-> (or/c list-node? #f) (or/c list-node? #f))
  (match head
    [(list-node val1 (list-node val2 next)) (list-node val2 (list-node val1 (swap-pairs next)))]
    [_ head]))

(module+ test
  (require rackunit)
  (define (list->linked-list lst)
    (foldr (lambda (x acc) (list-node x acc)) #f lst))
  (check-equal? (swap-pairs (list->linked-list '(1 2 3 4))) (list->linked-list '(2 1 4 3)))
  (check-equal? (swap-pairs (list->linked-list '())) (list->linked-list '()))
  (check-equal? (swap-pairs (list->linked-list '(1))) (list->linked-list '(1)))
  (check-equal? (swap-pairs (list->linked-list '(1 2 3))) (list->linked-list '(2 1 3))))
