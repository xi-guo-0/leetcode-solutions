#!/usr/bin/env racket
#lang racket

(define/contract (search-range nums target)
  (-> (listof exact-integer?) exact-integer? (listof exact-integer?))

  (define (binary-search-first nums-vec target low high)
    (if (< low high)
        (let* ([mid (quotient (+ low high) 2)]
               [mid-val (vector-ref nums-vec mid)])
          (cond
            [(= mid-val target)
             (if (or (= low mid) (< (vector-ref nums-vec (- mid 1)) target))
                 mid
                 (binary-search-first nums-vec target low mid))]
            [(< mid-val target) (binary-search-first nums-vec target (+ mid 1) high)]
            [else (binary-search-first nums-vec target low mid)]))
        -1))
  (define (binary-search-last nums-vec target low high)
    (if (< low high)
        (let* ([mid (quotient (+ low high) 2)]
               [mid-val (vector-ref nums-vec mid)])
          (cond
            [(= mid-val target)
             (if (or (= (+ mid 1) high) (> (vector-ref nums-vec (+ mid 1)) target))
                 mid
                 (binary-search-last nums-vec target (+ mid 1) high))]
            [(< mid-val target) (binary-search-last nums-vec target (+ mid 1) high)]
            [else (binary-search-last nums-vec target low mid)]))
        -1))
  (define (find-first nums-vec target)
    (binary-search-first nums-vec target 0 (vector-length nums-vec)))
  (define (find-last nums-vec target)
    (binary-search-last nums-vec target 0 (vector-length nums-vec)))

  (let* ([nums-vec (list->vector nums)]
         [first-pos (find-first nums-vec target)]
         [last-pos (find-last nums-vec target)])
    (if (and (> first-pos -1) (> last-pos -1))
        (list first-pos last-pos)
        '(-1 -1))))

(module+ test
  (require rackunit)
  (check-equal? (search-range '(5 7 7 8 8 10) 8) '(3 4))
  (check-equal? (search-range '(5 7 7 8 8 10) 6) '(-1 -1))
  (check-equal? (search-range '() 0) '(-1 -1)))
