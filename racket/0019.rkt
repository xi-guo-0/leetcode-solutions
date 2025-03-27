#!/usr/bin/env racket
#lang racket

; val : integer?
; next : (or/c list-node? #f)
(struct list-node (val next) #:mutable #:transparent)

; constructor
(define (make-list-node [val 0])
  (list-node val #f))

(define/contract (remove-nth-from-end head n)
  (-> (or/c list-node? #f) exact-integer? (or/c list-node? #f))
  (let ([len (let loop ([count 0]
                        [cur head])
               (cond
                 [(list-node? (list-node-next cur)) (loop (add1 count) (list-node-next cur))]
                 [else count]))])

    (let loop ([cur head]
               [count 0]
               [to-remove (add1 (- len n))])
      (cond
        [(eq? cur #f) #f]
        [(eq? count to-remove) (loop (list-node-next cur) (add1 count) to-remove)]
        [else (list-node (list-node-val cur) (loop (list-node-next cur) (add1 count) to-remove))]))))

(module+ test
  (require rackunit)
  (define (list->linked-list lst)
    (foldr (lambda (x acc) (list-node x acc)) #f lst))
  (check-equal? (remove-nth-from-end (list->linked-list '[1 2 3 4 5]) 2)
                (list->linked-list '[1 2 3 5]))
  (check-equal? (remove-nth-from-end (list->linked-list '[1]) 1) (list->linked-list '[]))
  (check-equal? (remove-nth-from-end (list->linked-list '[1 2]) 1) (list->linked-list '[1])))
