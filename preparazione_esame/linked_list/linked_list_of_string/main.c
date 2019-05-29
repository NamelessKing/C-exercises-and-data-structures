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
    list l = NULL,l2 = NULL;

    char **vet,*string = " a s s s";
    vet = create_vet_of_string(string);
    create_list(&l,vet,count_word_in_string(string));

    print_vet(vet,count_word_in_string(string));
    print_list2(l);
    destroy_vet(vet,count_word_in_string(string));

    x = l?(destroy(&l)):(print("l vuota\n"));
    x = l2?(destroy(&l2)):(print("l2 vuota\n"));


    return x;
}
