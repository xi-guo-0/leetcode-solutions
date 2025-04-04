#!/usr/bin/env racket
#lang racket

; val : integer?
; left : (or/c tree-node? #f)
; right : (or/c tree-node? #f)
(struct tree-node (val left right) #:mutable #:transparent)

; constructor
(define (make-tree-node [val 0])
  (tree-node val #f #f))

(define/contract (lca-deepest-leaves root)
  (-> (or/c tree-node? #f) (or/c tree-node? #f))
  (define (deepest-leaves-lca-helper node)
    (if (not node)
        (cons 0 #f)
        (let ([left (deepest-leaves-lca-helper (tree-node-left node))]
              [right (deepest-leaves-lca-helper (tree-node-right node))])
          (cond
            [(> (car left) (car right)) (cons (add1 (car left)) (cdr left))]
            [(< (car left) (car right)) (cons (add1 (car right)) (cdr right))]
            [else (cons (add1 (car left)) node)]))))
  (cdr (deepest-leaves-lca-helper root)))

(module+ test
  (require rackunit)
  (define (list->tree lst)
    (if (null? lst)
        #f
        (let build ([index 0])
          (if (>= index (length lst))
              #f
              (let ([val (list-ref lst index)])
                (if (eq? val #f)
                    #f
                    (tree-node val (build (+ (* index 2) 1)) (build (+ (* index 2) 2)))))))))
  (check-equal? (lca-deepest-leaves (list->tree '(3 5 1 6 2 0 8 #f #f 7 4))) (list->tree '(2 7 4)))
  (check-equal? (lca-deepest-leaves (list->tree '(1))) (list->tree '(1)))
  (check-equal? (lca-deepest-leaves (list->tree '(0 1 3 #f 2))) (list->tree '(2))))
