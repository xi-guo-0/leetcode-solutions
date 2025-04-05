#!/usr/bin/env racket
#lang racket

(define/contract (minimum-index nums)
  (-> (listof exact-integer?) exact-integer?)

  (define (find-candidate lst candidate count)
    (if (null? lst)
        candidate
        (let ([num (car lst)])
          (if (= num candidate)
              (find-candidate (cdr lst) candidate (add1 count))
              (if (zero? (sub1 count))
                  (find-candidate (cdr lst) num 1)
                  (find-candidate (cdr lst) candidate (sub1 count)))))))

  (let* ([n (length nums)]
         [candidate (find-candidate (cdr nums) (car nums) 1)]
         [total-count (count (lambda (x) (= x candidate)) nums)])

    (define (scan lst i left-count)
      (if (null? lst)
          -1
          (let* ([num (car lst)]
                 [new-left-count (if (= num candidate)
                                     (add1 left-count)
                                     left-count)]
                 [right-count (- total-count new-left-count)])
            (if (and (> (* 2 new-left-count) (add1 i)) (> (* 2 right-count) (- n i 1)))
                i
                (scan (cdr lst) (add1 i) new-left-count)))))

    (scan nums 0 0)))

(module+ test
  (require rackunit)
  (check-equal? (minimum-index '(1 2 2 2)) 2)
  (check-equal? (minimum-index '(2 1 3 1 1 1 7 1 2 1)) 4)
  (check-equal? (minimum-index '(3 3 3 3 7 2 2)) -1))
