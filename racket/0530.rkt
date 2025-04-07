#!/usr/bin/env racket
#lang racket

; val : integer?
; left : (or/c tree-node? #f)
; right : (or/c tree-node? #f)
(struct tree-node (val left right) #:mutable #:transparent)

; constructor
(define (make-tree-node [val 0])
  (tree-node val #f #f))

(require (only-in srfi/1 map))

(define/contract (get-minimum-difference root)
  (-> (or/c tree-node? #f) exact-integer?)
  (define (inorder-traversal tree)
    (if (not tree)
        '()
        (append (inorder-traversal (tree-node-left tree))
                (list (tree-node-val tree))
                (inorder-traversal (tree-node-right tree)))))
  (let ([inorder (inorder-traversal root)])
    (apply min (map (compose abs (curry apply -) list) inorder (rest inorder)))))

(module+ test
  (require rackunit)
  (define (parse-leetcode-tree str)
    (let ([make-queue (lambda () (mcons null null))]
          [enqueue! (lambda (q x)
                      (let ([new-pair (mcons x null)])
                        (if (null? (mcar q))
                            (begin
                              (set-mcar! q new-pair)
                              (set-mcdr! q new-pair))
                            (begin
                              (set-mcdr! (mcdr q) new-pair)
                              (set-mcdr! q new-pair)))))]
          [dequeue! (lambda (q)
                      (if (null? (mcar q))
                          (error "empty queue")
                          (let ([x (mcar (mcar q))])
                            (set-mcar! q (mcdr (mcar q)))
                            (when (null? (mcar q))
                              (set-mcdr! q null))
                            x)))]
          [queue-empty? (lambda (q) (null? (mcar q)))])
      (let* ([trimmed (cond
                        [(string=? str "[]") ""]
                        [(string=? str "") ""]
                        [else (substring str 1 (- (string-length str) 1))])]
             [elements (if (string=? trimmed "")
                           '()
                           (string-split trimmed ","))]
             [lst (map (lambda (elem)
                         (cond
                           [(string=? "null" elem) 'null]
                           [(string->number elem)
                            =>
                            values]
                           [else 'null]))
                       elements)]
             [root (if (null? lst)
                       #f
                       (tree-node (car lst) #f #f))])
        (if (not root)
            #f
            (let ([queue (make-queue)])
              (enqueue! queue root)
              (let loop ([remaining (cdr lst)])
                (if (or (queue-empty? queue) (null? remaining))
                    root
                    (let* ([current-node (dequeue! queue)]
                           [left-val (and (pair? remaining) (car remaining))]
                           [new-remaining (if (pair? remaining)
                                              (cdr remaining)
                                              remaining)]
                           [right-val (and (pair? new-remaining) (car new-remaining))]
                           [next-remaining (if (pair? new-remaining)
                                               (cdr new-remaining)
                                               new-remaining)]
                           [make-child (lambda (val)
                                         (and val
                                              (not (eq? val 'null))
                                              (let ([child (tree-node val #f #f)])
                                                (enqueue! queue child)
                                                child)))])
                      (set-tree-node-left! current-node (make-child left-val))
                      (set-tree-node-right! current-node (make-child right-val))
                      (loop next-remaining)))))))))

  (check-equal? (get-minimum-difference (parse-leetcode-tree "[4,2,6,1,3]")) 1)
  (check-equal? (get-minimum-difference (parse-leetcode-tree "[1,0,48,null,null,12,49]")) 1))
