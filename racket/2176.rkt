#!/usr/bin/env racket
#lang racket

(define (group-indices-by-value lst)
  (let loop ([remaining lst]
             [index 0]
             [groups (hash)]
             [result '()])
    (cond
      [(null? remaining) (map (compose list->vector reverse) (hash-values groups))]
      [else
       (let* ([current (car remaining)]
              [new-groups (hash-update groups current (lambda (indices) (cons index indices)) '())])
         (loop (cdr remaining) (add1 index) new-groups result))])))

(define/contract (count-pairs nums k)
  (-> (listof exact-integer?) exact-integer? exact-integer?)
  (for/sum
   ([indices (group-indices-by-value nums)])
   (let ([n (vector-length indices)])
     (for/sum
      ([i (in-range n)])
      (for/sum ([j (in-range (add1 i) n)])
               (if (zero? (remainder (* (vector-ref indices i) (vector-ref indices j)) k)) 1 0))))))

(module+ test
  (require rackunit)
  (check-equal? (count-pairs '(3 1 2 2 2 1 3) 2) 4)
  (check-equal? (count-pairs '(1 2 3 4) 1) 0))
