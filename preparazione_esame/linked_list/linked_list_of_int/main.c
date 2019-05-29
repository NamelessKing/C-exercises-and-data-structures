#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int print(char *s){
    printf("%s",s);
    return 1;
}


int main(){
    int x;
    list l1 = NULL,l2 = NULL,merged = NULL;

    append_itr(&l2,12);
    append_itr(&l2,12);
    append_itr(&l2,12);append_itr(&l2,12);




    printf("%d",remove_elem(&l2,12,4));

    print_list(l2);





    x = l1?(destroy(&l1)):(print("l1 vuota\n"));
    x = l2?(destroy(&l2)):(print("l2 vuota\n"));
    x = merged?(destroy(&merged)):(print("merged vuota\n"));

    return x;
}
