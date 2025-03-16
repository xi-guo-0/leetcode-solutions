#!/usr/bin/env racket
#lang racket

; val : integer?
; next : (or/c list-node? #f)
(struct list-node (val next) #:mutable #:transparent)

(define (make-list-node [val 0])
  (list-node val #f))

(define/contract (add-two-numbers l1 l2)
  (-> (or/c list-node? #f) (or/c list-node? #f) (or/c list-node? #f))
  (define (add l1 l2 carry)
    (cond
      [(and (not l1) (not l2) (zero? carry)) #f]
      [else
       (let* ([val1 (if l1
                        (list-node-val l1)
                        0)]
              [val2 (if l2
                        (list-node-val l2)
                        0)]
              [sum (+ val1 val2 carry)]
              [new-val (modulo sum 10)]
              [new-carry (quotient sum 10)]
              [next1 (if l1
                         (list-node-next l1)
                         #f)]
              [next2 (if l2
                         (list-node-next l2)
                         #f)])
         (list-node new-val (add next1 next2 new-carry)))]))
  (add l1 l2 0))

(module+ test
  (require rackunit)
  (define (list->linked-list lst)
    (if (null? lst)
        #f
        (list-node (car lst) (list->linked-list (cdr lst)))))
  (check-equal? (add-two-numbers (list->linked-list '(2 4 3)) (list->linked-list '(5 6 4)))
                (list->linked-list '(7 0 8)))

  (check-equal? (add-two-numbers (list->linked-list '(0)) (list->linked-list '(0)))
                (list->linked-list '(0)))
  (check-equal? (add-two-numbers (list->linked-list '(9 9 9 9 9 9 9)) (list->linked-list '(9 9 9 9)))
                (list->linked-list '(8 9 9 9 0 0 0 1))))
