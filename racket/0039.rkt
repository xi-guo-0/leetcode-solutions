#!/usr/bin/env racket
#lang racket

(define/contract (combination-sum candidates target)
  (-> (listof exact-integer?) exact-integer? (listof (listof exact-integer?)))
  (define (loop cands cur path acc)
    (cond
      [(empty? cands) acc]
      [(= cur target) (cons (sort path <) acc)]
      [(< cur target)
       (loop (cdr cands) cur path (loop cands (+ cur (car cands)) (cons (car cands) path) acc))]
      [else acc]))
  (remove-duplicates (loop candidates 0 '() '())))

(module+ test
  (require rackunit)
  (check-equal? (combination-sum '(2 3 6 7) 7) '((7) (2 2 3)))
  (check-equal? (combination-sum '(2 3 5) 8) '((3 5) (2 3 3) (2 2 2 2)))
  (check-equal? (combination-sum '(2) 1) '()))
