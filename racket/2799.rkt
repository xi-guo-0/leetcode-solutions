#!/usr/bin/env racket
#lang racket

(define/contract (count-complete-subarrays nums)
  (-> (listof exact-integer?) exact-integer?)
  (let ([at-most (lambda (k)
                   (let ([count (make-hash)]
                         [left 0]
                         [res 0]
                         [n (length nums)])
                     (for ([right (in-range n)]
                           [x (in-list nums)])
                       (hash-update! count x add1 0)
                       (let loop ()
                         (when (> (hash-count count) k)
                           (define left-x (list-ref nums left))
                           (hash-update! count left-x sub1 0)
                           (when (zero? (hash-ref count left-x))
                             (hash-remove! count left-x))
                           (set! left (add1 left))
                           (loop)))
                       (set! res (+ res (- right left -1))))
                     res))]
        [k (set-count (list->set nums))]
        [n (length nums)])
    (if (zero? k)
        0
        (- (/ (* n (add1 n)) 2) (at-most (- k 1))))))

(module+ test
  (require rackunit)
  (check-equal? (count-complete-subarrays '(1 3 1 2 2)) 4)
  (check-equal? (count-complete-subarrays '(5 5 5 5)) 10))
