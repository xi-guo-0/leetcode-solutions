#!/usr/bin/env racket
#lang racket

; val : integer?
; left : (or/c tree-node? #f)
; right : (or/c tree-node? #f)
(struct tree-node (val left right) #:mutable #:transparent)

; constructor
(define (make-tree-node [val 0])
  (tree-node val #f #f))

(define/contract (deepest-leaves-sum root)
  (-> (or/c tree-node? #f) exact-integer?)
  (define (deepest root)
    (if (eq? #f root)
        0
        (+ 1 (max (deepest (tree-node-left root)) (deepest (tree-node-right root))))))
  (let ([depth (- (deepest root) 1)])
    (define (helper cur-depth root)
      (cond
        [(eq? #f root) 0]
        [(= cur-depth depth) (tree-node-val root)]
        [else
         (+ (helper (+ 1 cur-depth) (tree-node-left root))
            (helper (+ 1 cur-depth) (tree-node-right root)))]))
    (helper 0 root)))

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

  (check-equal? (deepest-leaves-sum (list->tree '(1 2 3 4 5 #f 6 7 #f #f #f #f #f #f 8))) 15)
  (check-equal? (deepest-leaves-sum (list->tree '(6 7 8 2 7 1 3 9 #f 1 4 #f #f #f 5))) 19))
