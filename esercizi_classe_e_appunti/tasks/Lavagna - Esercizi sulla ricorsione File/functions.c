#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ricerca_binaria_iterativo(int a[],int dim,int elem){
    int first = 0,last = dim - 1 ,risp = 0,middle,index = -1;

    while (first <= last && !risp){

        middle = (first+last)/2;

        if(a[middle] == elem){
            risp = 1;
            index = middle;
        }

        if(a[middle]< elem ){
            printf("FIRST = %d   MIDDLE = %d   LAST = %d\n",a[first],a[middle],a[last]);
            first = (middle + 1) ;
        }else{
            printf("FIRST = %d   MIDDLE = %d   LAST = %d\n",a[first],a[middle],a[last]);
            last = (middle - 1);
        }
    }

    return index;
}
