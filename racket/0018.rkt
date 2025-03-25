#!/usr/bin/env racket
#lang racket

(define/contract (four-sum nums target)
  (-> (listof exact-integer?) exact-integer? (listof (listof exact-integer?)))
  (let* ([n (length nums)]
         [vec-nums (list->vector (sort nums <))])
    (let loop ([i 0]
               [result '()])
      (if (>= i (- n 3))
          result
          (let loop2 ([j (+ i 1)]
                      [result2 result])
            (if (>= j (- n 2))
                (loop (+ i 1) result2)
                (let loop3 ([k (+ j 1)]
                            [result3 result2])
                  (if (>= k (- n 1))
                      (loop2 (+ j 1) result3)
                      (let loop4 ([l (+ k 1)]
                                  [result4 result3])
                        (if (>= l n)
                            (loop3 (+ k 1) result4)
                            (if (= (+ (vector-ref vec-nums i)
                                      (vector-ref vec-nums j)
                                      (vector-ref vec-nums k)
                                      (vector-ref vec-nums l))
                                   target)
                                (let* ([quadruplet (list (vector-ref vec-nums i)
                                                         (vector-ref vec-nums j)
                                                         (vector-ref vec-nums k)
                                                         (vector-ref vec-nums l))]
                                       [unique-result (if (member quadruplet result4 equal?)
                                                          result4
                                                          (cons quadruplet result4))])
                                  (loop4 (+ l 1) unique-result))
                                (loop4 (+ l 1) result4))))))))))))

(module+ test
  (require rackunit)
  (check-equal? (four-sum '(1 0 -1 0 -2 2) 0) '((-2 -1 1 2) (-2 0 0 2) (-1 0 0 1)))
  (check-equal? (four-sum '(2 2 2 2 2) 8) '((2 2 2 2))))
