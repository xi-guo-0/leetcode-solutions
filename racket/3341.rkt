#!/usr/bin/env racket
#lang racket

(define/contract (min-time-to-reach moveTime)
  (-> (listof (listof exact-integer?)) exact-integer?)
  (let* ([move-time moveTime]
         [n (length move-time)]
         [m (length (car move-time))]
         [directions '((1 . 0) (-1 . 0) (0 . 1) (0 . -1))])

    (define (extract-min queue)
      (if (null? queue)
          (values #f '())
          (let loop ([q (cdr queue)]
                     [min-elem (car queue)]
                     [rest '()])
            (if (null? q)
                (values min-elem rest)
                (let ([current (car q)])
                  (if (< (car current) (car min-elem))
                      (loop (cdr q) current (cons min-elem rest))
                      (loop (cdr q) min-elem (cons current rest))))))))

    (define (process-neighbors x y time dist queue)
      (let loop ([dirs directions]
                 [new-queue queue]
                 [new-dist dist])
        (if (null? dirs)
            (values new-queue new-dist)
            (let* ([dir (car dirs)]
                   [dx (car dir)]
                   [dy (cdr dir)]
                   [nx (+ x dx)]
                   [ny (+ y dy)])
              (if (and (>= nx 0) (< nx n) (>= ny 0) (< ny m))
                  (let* ([move-time-val (list-ref (list-ref move-time nx) ny)]
                         [s (max time move-time-val)]
                         [new-time (+ s 1)]
                         [current-dist (hash-ref new-dist (cons nx ny) +inf.0)])
                    (if (< new-time current-dist)
                        (let ([updated-dist (hash-set new-dist (cons nx ny) new-time)])
                          (loop (cdr dirs) (cons (list new-time nx ny) new-queue) updated-dist))
                        (loop (cdr dirs) new-queue new-dist)))
                  (loop (cdr dirs) new-queue new-dist))))))

    (define (helper queue dist)
      (if (null? queue)
          -1
          (call-with-values
           (lambda () (extract-min queue))
           (lambda (current rest-queue)
             (if (not current)
                 -1
                 (let ([time (first current)]
                       [x (second current)]
                       [y (third current)])
                   (if (and (= x (sub1 n)) (= y (sub1 m)))
                       time
                       (let ([current-dist (hash-ref dist (cons x y) +inf.0)])
                         (if (> time current-dist)
                             (helper rest-queue dist)
                             (call-with-values
                              (lambda () (process-neighbors x y time dist rest-queue))
                              (lambda (new-queue new-dist) (helper new-queue new-dist))))))))))))

    (helper '((0 0 0)) (hash (cons 0 0) 0))))

(module+ test
  (require rackunit)
  (check-equal? (min-time-to-reach '((0 4) (4 4))) 6)
  (check-equal? (min-time-to-reach '((0 0 0) (0 0 0))) 3))
