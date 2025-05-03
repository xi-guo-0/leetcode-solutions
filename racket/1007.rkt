#!/usr/bin/env racket
#lang racket

(define/contract (min-domino-rotations tops bottoms)
  (-> (listof exact-integer?) (listof exact-integer?) exact-integer?)

  (let* ([rotations (lambda (a b x)
                      (let loop ([a a]
                                 [b b]
                                 [rot 0])
                        (cond
                          [(null? a) rot]
                          [(= (car a) x) (loop (cdr a) (cdr b) rot)]
                          [(= (car b) x) (loop (cdr a) (cdr b) (+ rot 1))]
                          [else #f])))]
         [candidates (if (or (null? tops) (null? bottoms))
                         '()
                         (let ([ft (car tops)]
                               [fb (car bottoms)])
                           (if (= ft fb)
                               (list ft)
                               (list ft fb))))])
    (if (null? candidates)
        -1
        (let* ([possible-rotations (append-map (lambda (x)
                                                 (let ([top-r (rotations tops bottoms x)]
                                                       [bot-r (rotations bottoms tops x)])
                                                   (filter number? (list top-r bot-r))))
                                               candidates)]
               [valid-rotations (filter number? possible-rotations)])
          (if (null? valid-rotations)
              -1
              (apply min valid-rotations))))))

(module+ test
  (require rackunit)
  (check-equal? (min-domino-rotations '(2 1 2 4 2 2) '(5 2 6 2 3 2)) 2)
  (check-equal? (min-domino-rotations '(3 5 1 2 3) '(3 6 3 3 4)) -1))
