#!/usr/bin/env racket
#lang racket

(define (bisect-left vec target low high)
  (let loop ([low low]
             [high high])
    (if (< low high)
        (let* ([mid (quotient (+ low high) 2)]
               [mid-val (vector-ref vec mid)])
          (if (< mid-val target)
              (loop (+ mid 1) high)
              (loop low mid)))
        low)))

(define (bisect-right vec target low high)
  (let loop ([low low]
             [high high])
    (if (< low high)
        (let* ([mid (quotient (+ low high) 2)]
               [mid-val (vector-ref vec mid)])
          (if (<= mid-val target)
              (loop (+ mid 1) high)
              (loop low mid)))
        low)))

(define/contract (count-fair-pairs nums lower upper)
  (-> (listof exact-integer?) exact-integer? exact-integer? exact-integer?)
  (let* ([sorted (sort nums <)]
         [sorted-vec (list->vector sorted)]
         [n (length sorted)])
    (for/sum ([i (in-range n)])
             (let* ([current (vector-ref sorted-vec i)]
                    [target-lower (- lower current)]
                    [target-upper (- upper current)]
                    [left (bisect-left sorted-vec target-lower (+ i 1) n)]
                    [right (bisect-right sorted-vec target-upper (+ i 1) n)])
               (- right left)))))

(module+ test
  (require rackunit)
  (check-equal? (count-fair-pairs '(0 1 7 4 4 5) 3 6) 6)
  (check-equal? (count-fair-pairs '(1 7 9 2 5) 11 11) 1)
  (check-equal? (count-fair-pairs '(0 0 0 0 0 0) 0 0) 15))
