#!/usr/bin/env racket
#lang racket

(define/contract (find-all-recipes recipes ingredients supplies)
  (-> (listof string?) (listof (listof string?)) (listof string?) (listof string?))

  (define (find-recipes-recursively recipes ingredients supplies found-recipes seen-recipes return-fn)
    (for ([recipe recipes]
          [ingredients-list ingredients])
      (when (and (not (set-member? seen-recipes recipe))
                 (andmap (lambda (ing) (set-member? supplies ing)) ingredients-list))
        (find-recipes-recursively recipes
                                  ingredients
                                  (set-add supplies recipe)
                                  (cons recipe found-recipes)
                                  (set-add seen-recipes recipe)
                                  return-fn)))
    (return-fn found-recipes))

  (let/cc return
    (find-recipes-recursively recipes ingredients (list->set supplies) empty (set) return)))

(module+ test
  (require rackunit)
  (check-equal?
   (list->set (find-all-recipes '("bread") '(("yeast" "flour")) '("yeast" "flour" "corn")))
   (list->set '("bread")))
  (check-equal? (list->set (find-all-recipes '("bread" "sandwich")
                                             '(("yeast" "flour") ("bread" "meat"))
                                             '("yeast" "flour" "meat")))
                (list->set '("bread" "sandwich")))
  (check-equal? (list->set (find-all-recipes '("bread" "sandwich" "burger")
                                             '(("yeast" "flour") ("bread" "meat")
                                                                 ("sandwich" "meat" "bread"))
                                             '("yeast" "flour" "meat")))
                (list->set '("bread" "sandwich" "burger"))))
