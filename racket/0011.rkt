#!/usr/bin/env racket
#lang racket

(define/contract (max-area height)
  (-> (listof exact-integer?) exact-integer?)
  (let ([height (list->vector height)])
    (define (compute-max-area l r)
      (if (< l r)
          (let ([hl (vector-ref height l)]
                [hr (vector-ref height r)])
            (max (* (- r l) (min hl hr))
                 (if (< hl hr)
                     (compute-max-area (add1 l) r)
                     (compute-max-area l (sub1 r)))))
          0))
    (compute-max-area 0 (sub1 (vector-length height)))))

(module+ test
  (require rackunit)
  (check-equal? (max-area '(1 8 6 2 5 4 8 3 7)) 49)
  (check-equal? (max-area '(1 1)) 1))
