#!/usr/bin/env racket
#lang racket

(define/contract (longest-nice-subarray nums)
  (-> (listof exact-integer?) exact-integer?)
  (define (slide-window left-nums right-nums current-bitset current-len max-len)
    (cond
      [(null? right-nums) max-len]
      [(zero? (bitwise-and current-bitset (car right-nums)))
       (slide-window left-nums
                     (cdr right-nums)
                     (bitwise-ior current-bitset (car right-nums))
                     (+ current-len 1)
                     (max max-len (+ current-len 1)))]
      [else
       (slide-window (cdr left-nums)
                     right-nums
                     (bitwise-xor current-bitset (car left-nums))
                     (- current-len 1)
                     max-len)]))
  (slide-window nums nums 0 0 0))

(module+ test
  (require rackunit)
  (check-equal? (longest-nice-subarray '(1 3 8 48 10)) 3)
  (check-equal? (longest-nice-subarray '(3 1 5 11 13)) 1)
  (check-equal? (longest-nice-subarray '(744437702 379056602
                                                   145555074
                                                   392756761
                                                   560864007
                                                   934981918
                                                   113312475
                                                   1090
                                                   16384
                                                   33
                                                   217313281
                                                   117883195
                                                   978927664))
                3))
