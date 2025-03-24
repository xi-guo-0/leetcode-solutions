#!/usr/bin/env racket
#lang racket

(define/contract (letter-combinations digits)
  (-> string? (listof string?))
  (define keyboard
    '((#\space) ()
                (#\a #\b #\c)
                (#\d #\e #\f)
                (#\g #\h #\i)
                (#\j #\k #\l)
                (#\m #\n #\o)
                (#\p #\q #\r #\s)
                (#\t #\u #\v)
                (#\w #\x #\y #\z)))
  (if (= (string-length digits) 0)
      '()
      (map list->string
           (foldl (lambda (a result)
                    (for*/list ([x (list-ref keyboard a)]
                                [r result])
                      (cons x r)))
                  '(())
                  (reverse (map (lambda (c) (- (char->integer c) (char->integer #\0)))
                                (string->list digits)))))))
(module+ test
  (require rackunit)
  (check-equal? (letter-combinations "23") '("ad" "ae" "af" "bd" "be" "bf" "cd" "ce" "cf"))
  (check-equal? (letter-combinations "") '())
  (check-equal? (letter-combinations "2") '("a" "b" "c")))
