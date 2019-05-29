#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


/*
5.5.2
Marbles - 1
We have an infinite number of blue and red marbles.
Write a function that computes the number
of sequences of n marbles such that it never
happens that three marbles with the same colours are
consecutive.
Examples:
• If n = 0 the function computes 1
• If n = 3 the function computes 6 since the possible sequences are (R, B, B), (R, B, R),
(R, R, B), (B, R, R), (B, R, B), (B, B, R)
• If n = 4 the function computes 10
*/
int marbles1(int n,char last,char prev){
    if(n == 0){
        return 1;
    }else{

        if(last == 'R' && prev == 'R' ){
            return marbles1(n-1,'B',last);
        }else
        if(last == 'B' && prev == 'B'){
            return marbles1(n-1,'R',last);
        }else{
            return marbles1(n-1,'B',last) + marbles1(n-1,'R',last);
        }
    }
}


/*
5.5.3 Marbles - 2
We are in the same setting of Exercise 5.5.2,
but we want to count all the sequences in which the
blue marbles apper only in sub-sequences with
length exactly 2 with the exception of the last marble
which can be a single blue.
Examples:
• If n = 0 the function computes 1
• If n = 1 the possible sequences are (R) and (B), i.e., the function computes 2
• If n = 2 the valid sequences are (R, R), (R, B), (B, B), i.e., the function computes 3
• If n = 3 the valid sequences are (R, B, B), (R, R, B), (B, B, R), (R, R, R), i.e., the algorithm
computes 4
• If n = 4 the valid sequences are (R, R, R, R), (B, B, R, R), (R, B, B, R), (R, R, B, B), (R, R, R, B),
(B, B, R, B), i.e., the algorithm computes 6
Solution The reasoning follows that of the previous excercise, i.e., we keep track of the last two
marbles. The code is shown in Table 5.2
*/
int marbles2(int n,char last,char prev){
    if(n == 0){
        return 1;
    }else{
        if(last == 'B' && prev == 'B'){
            return marbles2(n-1,'R',last);
        }else{

            if(last == 'B' && prev != 'B'){
                return marbles2(n-1,'B',last);
            }else{
                return marbles2(n-1,'B',last) + marbles2(n-1,'R',last);
            }

        }

    }
}


/*
5.5.4 Marbles - 3
We are in the same setting of Exercise 5.5.2, but we want to count all the sequences in which it
never happens that neither two blue marbles nor three red marbles appear consectuvie.
Examples:
• If n = 0 the function computes 1
• If n = 3 the valid sequences are (R, B, R), (R, R, B), (B, R, R), (B, R, B), i.e., the function
computes 4
• If n = 4 then the function computes 5
*/
int marbles3(int n,char now,char prev){
    if(n == 0){
        return 1;
    }else{

        if(now == 'R' && prev == 'R'){
            return marbles3(n-1,'B',now);
        }else{

            if(now == 'B'){
                return marbles3(n-1,'R',now);
            }else{
                return marbles3(n-1,'R',now) + marbles3(n-1,'B',now);;
            }

        }
    }
}


/*5.5.5 Coloured bricks*/
int coloured_bricks(int n , int r , int b , char last ){
    if(n == 0){
        return 1;
    }else{

        if(b>0 && r>0){

            if(last == 'R'){
               return coloured_bricks(n-1,r,b-1,'B');
            }else{
               return coloured_bricks(n-1,r,b-1,'B') + coloured_bricks(n-1,r-1,b,'R');
            }
        }else{

           if(b>0){
                return coloured_bricks(n-1,r,b-1,'B');
           }

           if(r>0 && last != 'R' ){
               return coloured_bricks(n-1,r-1,b,'R');
           }


        }

    }
}
