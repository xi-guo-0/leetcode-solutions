#!/usr/bin/env racket
#lang racket

; val : integer?
; left : (or/c tree-node? #f)
; right : (or/c tree-node? #f)
(struct tree-node (val left right) #:mutable #:transparent)

; constructor
(define (make-tree-node [val 0])
  (tree-node val #f #f))

(define find-elements%
  (class object%
    (super-new)

    ; root : (or/c tree-node? #f)
    (init-field root)

    (define tree root)

    (define (find-in bs node)
      (cond
        [(empty? (cdr bs)) (not (eq? #f node))]
        [(eq? #f node) #f]
        [else
         (find-in (cdr bs)
                  (if (even? (cadr bs))
                      (tree-node-left node)
                      (tree-node-right node)))]))

    (define (target->binary target)
      (map (lambda (c) (- (char->integer c) (char->integer #\0)))
           (string->list (number->string target 2))))

    ; find : exact-integer? -> boolean?
    (define/public (find target) (find-in (target->binary (+ 1 target)) tree))))

;; Your find-elements% object will be instantiated and called as such:
;; (define obj (new find-elements% [root root]))
;; (define param_1 (send obj find target))

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

  (test-case "Example 1"
    (let ([obj (new find-elements% [root (list->tree '(-1 #f -1))])])
      (check-false (send obj find 1))
      (check-true (send obj find 2))))
  (test-case "Example 2"
    (let ([obj (new find-elements% [root (list->tree '(-1 -1 -1 -1 -1))])])
      (check-true (send obj find 1))
      (check-true (send obj find 3))
      (check-false (send obj find 5))))
  (test-case "Example 3"
    (let ([obj (new find-elements% [root (list->tree '(-1 #f -1 -1 #f -1))])])
      (check-true (send obj find 2))
      (check-false (send obj find 3))
      (check-false (send obj find 4))
      (check-true (send obj find 5)))))
