#!/usr/bin/env racket
#lang racket

; val : integer?
; next : (or/c list-node? #f)
(struct list-node (val next) #:mutable #:transparent)

; constructor
(define (make-list-node [val 0])
  (list-node val #f))

(define/contract (middle-node head)
  (-> (or/c list-node? #f) (or/c list-node? #f))
  (define dummy (list-node 0 head))
  (define (helper p q)
    (if (or (eq? #f (list-node-next q)) (eq? #f (list-node-next (list-node-next q))))
        (list-node-next p)
        (helper (list-node-next p) (list-node-next (list-node-next q)))))
  (helper dummy dummy))

(module+ test
  (require rackunit)
  (define (list->linked-list lst)
    (foldr (lambda (x acc) (list-node x acc)) #f lst))
  (check-equal? (middle-node (list->linked-list '[1 2 3 4 5])) (list->linked-list '[3 4 5]))
  (check-equal? (middle-node (list->linked-list '[1 2 3 4 5 6])) (list->linked-list '[4 5 6])))
