#!/usr/bin/env racket
#lang racket

; val : integer?
; next : (or/c list-node? #f)
(struct list-node (val next) #:mutable #:transparent)

; constructor
(define (make-list-node [val 0])
  (list-node val #f))

(define/contract (merge-two-lists list1 list2)
  (-> (or/c list-node? #f) (or/c list-node? #f) (or/c list-node? #f))
  (cond
    [(false? list1) list2]
    [(false? list2) list1]
    [else
     (let ([x (list-node-val list1)]
           [y (list-node-val list2)])
       (if (<= x y)
           (list-node x (merge-two-lists (list-node-next list1) list2))
           (list-node y (merge-two-lists list1 (list-node-next list2)))))]))

(module+ test
  (require rackunit)
  (define (list->linked-list lst)
    (foldr (lambda (x acc) (list-node x acc)) #f lst))
  (check-equal? (merge-two-lists (list->linked-list '(1 2 4)) (list->linked-list '(1 3 4)))
                (list->linked-list '(1 1 2 3 4 4)))
  (check-equal? (merge-two-lists (list->linked-list '()) (list->linked-list '()))
                (list->linked-list '()))
  (check-equal? (merge-two-lists (list->linked-list '()) (list->linked-list '(0)))
                (list->linked-list '(0))))
