#!/usr/bin/env racket
#lang racket

; val : integer?
; next : (or/c list-node? #f)
(struct list-node (val next) #:mutable #:transparent)

; constructor
(define (make-list-node [val 0])
  (list-node val #f))

(define/contract (reverse-k-group head k)
  (-> (or/c list-node? #f) exact-integer? (or/c list-node? #f))
  (define (reverse-list lst n)
    (define (helper lst acc n)
      (if (zero? n)
          (values acc lst)
          (helper (list-node-next lst) (list-node (list-node-val lst) acc) (sub1 n))))
    (helper lst #f n))
  (define (has-k-nodes? lst k)
    (if (zero? k)
        #true
        (and lst (has-k-nodes? (list-node-next lst) (sub1 k)))))
  (define (reverse-in-k-groups lst)
    (if (has-k-nodes? lst k)
        (let-values ([(reversed-head remaining) (reverse-list lst k)])
          (set-list-node-next! (get-last-node reversed-head) (reverse-in-k-groups remaining))
          reversed-head)
        lst))
  (define (get-last-node node)
    (if (or (not node) (not (list-node-next node)))
        node
        (get-last-node (list-node-next node))))
  (reverse-in-k-groups head))

(module+ test
  (require rackunit)
  (define (list->linked-list lst)
    (foldr (lambda (x acc) (list-node x acc)) #f lst))
  (check-equal? (reverse-k-group (list->linked-list '(1 2 3 4 5)) 2) (list->linked-list '(2 1 4 3 5)))
  (check-equal? (reverse-k-group (list->linked-list '(1 2 3 4 5)) 3)
                (list->linked-list '(3 2 1 4 5))))
