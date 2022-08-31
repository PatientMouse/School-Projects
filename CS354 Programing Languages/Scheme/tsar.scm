;@Author: Andrew Gerber
;Check function that takes in the subject the element to search for the the replace value, this is only triggetred on atom cases
(define (check subj srch repl)
    ;declare a new random value
    (define new (random 100));
  ;Check: is the sub equal to 'RANDOM
  (if (eq? subj 'RANDOM)
             ;if they are the same return the new random
             new
             ;if not the same check if the subj is the serch element
             (if (eq? subj srch)
                ;reuturn the repl
                repl
                ;return the old
                subj)))

;Function: Tree search and replace
(define (tsar subj srch repl)
    ;checkl of the subj is not a pair
    (if (not (pair? subj))
            ;if its single(ATOM CASE):
            ;replace the value
            (check subj srch repl)
            
         ;if it is a pair
         (if (null? (cdr subj))
             ;if cdr is null serch through car to find if eq?)
         (if (and (and (pair? subj) (pair? srch)) (eq? (car subj) (car srch)))
                
                ;check if the subj that is a pair and the cars match has a random
                (tsar repl 'RANDOM (random 1000))
                ;if not then coninute down the rabbit hole
                (cons (tsar (car subj) srch repl) (tsar (cdr subj) srch repl))
                )
            ;if not then coninute down the rabbit hole
            (cons (tsar (car subj) srch repl) (tsar (cdr subj) srch repl))
        )
    ))

;TESTS:

(define (test subj srch repl result)
  (display "Test:")(newline)
  (display "The subj is:")(display subj)(newline)
  (display "The srch is:")(display srch)(newline)
  (display "The repl is:")(display repl)(newline)
  (display "the tsar results are:")(display (tsar subj srch repl))(newline)
  (display "It should be:")(display result)(newline)(newline)
  )

(test 'z 'x 'y 'z)
(test 'x 'x 'y 'y)
(test 'x 'x 'x 'x)
(test '() 'x 'y '())
(test '(x x) 'x 'y '(y y))
(test 'z 'x 'y '(y (y) z))
(test '(x (x) z) 'x 'y '(x (y y) z))
(test '(x (x) z) '(x) '(y y) '(x (y y) z))
(test '(x (x) ((x)) z) '(x) '(y y) '(x (y y) ((y y)) z))
(test '(x (x) ((x)) z) '(x) '() '(x () (()) z))
(test '(x (x) ((x)) z) '() '(y y) '(x (x y y) ((x y y) y y) z y y))
(test '(x (x) ((x)) z) '(x) '(RANDOM y) '(x (ran y) ((ran y)) z))
(test '(x (x) ((x)) z) '(x) '(RANDOM RANDOM) '(x (rando rando) ((rando rando)) z))
