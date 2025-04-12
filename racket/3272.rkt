#!/usr/bin/env racket
#lang racket

(define/contract (count-good-integers n k)
  (-> exact-integer? exact-integer? exact-integer?)
  (let ([generate-palindromes
         (lambda (n)
           (let ([m (quotient (+ n 1) 2)])
             (let ([lower (expt 10 (- m 1))]
                   [upper (expt 10 m)])
               (for/list ([v (in-range lower upper)])
                 (let ([s (number->string v)])
                   (if (even? n)
                       (string-append s (list->string (reverse (string->list s))))
                       (string-append
                        s
                        (list->string
                         (reverse (string->list (substring s 0 (- (string-length s) 1))))))))))))]
        [divisible-by-k? (lambda (s) (zero? (modulo (string->number s) k)))]
        [factorial (lambda (x)
                     (if (<= x 1)
                         1
                         (foldl * 1 (range 1 (+ x 1)))))])
    (let ([count-valid (lambda (key n)
                         (let* ([counts (foldl (lambda (d h) (hash-update h d add1 0)) #hash() key)]
                                [count0 (hash-ref counts #\0 0)]
                                [product (for/product ([(_ cnt) (in-hash counts)]) (factorial cnt))]
                                [numerator (* (- n count0) (factorial (- n 1)))])
                           (quotient numerator product)))])
      (let* ([pals (generate-palindromes n)]
             [filtered (filter divisible-by-k? pals)]
             [keys (map (lambda (s) (sort (string->list s) char<?)) filtered)]
             [unique-keys (remove-duplicates keys)])
        (for/sum ([key (in-list unique-keys)]) (count-valid key n))))))

(module+ test
  (require rackunit)
  (check-equal? (count-good-integers 3 5) 27)
  (check-equal? (count-good-integers 1 4) 2)
  (check-equal? (count-good-integers 5 6) 2468))
