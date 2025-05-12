#!/usr/bin/env racket
#lang racket

(require racket/list)

(define/contract (find-even-numbers digits)
  (-> (listof exact-integer?) (listof exact-integer?))

  (define (generate-permutations dgs)
    (let loop ([n 0]
               [used '()]
               [digs dgs])
      (if (= n 3)
          (list (reverse used))
          (append-map (λ (d)
                        (if (member d digs)
                            (loop (add1 n) (cons d used) (remove-first d digs))
                            '()))
                      (remove-duplicates digs =)))))

  (define (remove-first x lst)
    (cond
      [(null? lst) '()]
      [(= x (car lst)) (cdr lst)]
      [else (cons (car lst) (remove-first x (cdr lst)))]))

  (define perms (generate-permutations digits))

  (define nums (map (λ (p) (+ (* (first p) 100) (* (second p) 10) (third p))) perms))

  (define valid-nums (filter (λ (n) (and (>= n 100) (even? n))) nums))

  (sort valid-nums <))

(module+ test
  (require rackunit)
  (check-equal? (find-even-numbers '(2 1 3 0)) '(102 120 130 132 210 230 302 310 312 320))
  (check-equal? (find-even-numbers '(2 2 8 8 2)) '(222 228 282 288 822 828 882))
  (check-equal? (find-even-numbers '(3 7 5)) '()))
