#!/usr/bin/env racket
#lang racket

(define (pow-mod a b mod)
  (cond
    [(= b 0) 1]
    [(even? b) (modulo (sqr (pow-mod a (quotient b 2) mod)) mod)]
    [else (modulo (* a (pow-mod a (sub1 b) mod)) mod)]))

(define/contract (ideal-arrays n maxValue)
  (-> exact-integer? exact-integer? exact-integer?)
  (let* ([MOD 1000000007]
         [max_val maxValue]
         [spf (make-vector (+ max_val 1) 0)])
    (vector-set! spf 1 1)
    (for ([i (in-range 2 (+ max_val 1))])
      (when (zero? (vector-ref spf i))
        (vector-set! spf i i)
        (for ([j (in-range (* i 2) (+ max_val 1) i)])
          (when (zero? (vector-ref spf j))
            (vector-set! spf j i)))))
    (let* ([a_max (+ n max_val)]
           [fact (make-vector (+ a_max 1) 1)]
           [inv_fact (make-vector (+ a_max 1) 1)])
      (for ([i (in-range 1 (+ a_max 1))])
        (vector-set! fact i (modulo (* (vector-ref fact (- i 1)) i) MOD)))
      (vector-set! inv_fact a_max (pow-mod (vector-ref fact a_max) (- MOD 2) MOD))
      (for ([i (in-range (- a_max 1) 0 -1)])
        (vector-set! inv_fact i (modulo (* (vector-ref inv_fact (+ i 1)) (+ i 1)) MOD)))
      (let loop-d ([d 1]
                   [total 0])
        (if (> d max_val)
            (modulo total MOD)
            (let* ([res (if (= d 1)
                            1
                            (let factorize ([x d]
                                            [prod 1])
                              (if (= x 1)
                                  prod
                                  (let* ([p (vector-ref spf x)]
                                         [cnt (let count ([x x]
                                                          [c 0])
                                                (if (zero? (remainder x p))
                                                    (count (quotient x p) (+ c 1))
                                                    c))]
                                         [x_new (quotient x (expt p cnt))])
                                    (factorize x_new
                                               (modulo (* prod
                                                          (modulo (* (vector-ref fact (+ cnt (- n 1)))
                                                                     (vector-ref inv_fact cnt)
                                                                     (vector-ref inv_fact (- n 1)))
                                                                  MOD))
                                                       MOD))))))]
                   [new_total (modulo (+ total res) MOD)])
              (loop-d (add1 d) new_total)))))))

(module+ test
  (require rackunit)
  (check-equal? (ideal-arrays 2 5) 10)
  (check-equal? (ideal-arrays 5 3) 11))
