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
    Dlist l = NULL,test = NULL;

    /*append_itr(&l,3);
    append_itr(&l,6);
    prepend(&l,99);
    append_rec(&l,0);
    print_list(l);

    test = remove_head_to_return(&l);

    print_list(l);
    print_list(test);

    remove_tail_itr(&test);*/

    prepend_Dlist(&l,3);
    prepend_Dlist(&l,5);
    prepend_Dlist(&l,8);




    print_Dlist(l);

    x = l?(destroy_Dlist(&l)):(print("l vuota\n"));
    x = test?(destroy_Dlist(&test)):(print("test vuota\n"));

    return x;
}
