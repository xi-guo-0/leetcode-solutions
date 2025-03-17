#!/usr/bin/env racket
#lang racket

(define/contract (convert s numRows)
  (-> string? exact-integer? string?)

  (define (list-update lst idx fn)
    (for/list ([i (in-range (length lst))]
               [x lst])
      (if (= i idx)
          (fn x)
          x)))

  (if (or (= numRows 1) (>= numRows (string-length s)))
      s
      (let loop ([i 0]
                 [current-row 0]
                 [direction 1]
                 [rows (make-list numRows '())])
        (if (= i (string-length s))
            (apply string-append (map (lambda (row) (list->string (reverse row))) rows))
            (let* ([current-char (string-ref s i)]
                   [new-rows (list-update rows current-row (lambda (row) (cons current-char row)))]
                   [new-row (+ current-row direction)])
              (if (or (= new-row -1) (= new-row numRows))
                  (loop (add1 i) (- current-row direction) (- direction) new-rows)
                  (loop (add1 i) new-row direction new-rows)))))))

(module+ test
  (require rackunit)
  (check-equal? (convert "PAYPALISHIRING" 3) "PAHNAPLSIIGYIR")
  (check-equal? (convert "PAYPALISHIRING" 4) "PINALSIGYAHRPI")
  (check-equal? (convert "A" 1) "A"))
