#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"


void print_list(list l){
    if(!l){
        printf("NULL\n");
    }else{
        printf("[ %s ]->",l->str);
        print_list(l->next);
    }
}

int destroy(list *l){
    if(*l){
        destroy(&(*l)->next);
        free((*l)->str);
        free(*l);
        *l = NULL;
        return 1;
    }else{
        return 0;
    }
}

int prepend(list *l,char *info){
    list node = (list)malloc(sizeof(struct node));
    if(!node){
        return 0;
    }
    node->str = (char *)malloc((strlen(info)+1)*sizeof(char));
    if(!(node->str)){
        return 0;
    }
    strcpy(node->str,info);

    node->next = *l;
    *l = node;
    return 1;
}


int append_rec(list *l,char *info){
    if(!(*l)){
        return prepend(l,info);
    }else{
        return append_rec(&(*l)->next,info);
    }
}

int get_tail_len(list l){
    if(!l){
        return 0;
    }else
    if(!l->next){
        return strlen(l->str);
    }else{
        return get_tail_len(l->next);
    }
}







/*******************funzioni pdf marin*****************************/
/*
7.3.5 Identify words in a paragraph
Given a string containing a paragraph,
write a function that returns a list of strings in which each
cell contains a word of the paragraph.
Assume that the every word is separated from the other by
a sequence of at least one blank ’ ’.
Do not use any function from library string.h.

TEST:
int print(char *s){
    printf("%s",s);
    return 1;
}
int main(){
    int x;
    list l = NULL,l2 = NULL;

    l = word_in_list_from_string("ciao a tutti");

    print_list(l);

    x = l?(destroy(&l)):(print("l vuota\n"));
    x = l2?(destroy(&l2)):(print("l2 vuota\n"));

    return 0;
}

*/

list word_in_list_from_string(char *str){
    list l = NULL;
    int len;
    int i;
    char *temp = (char *)malloc(strlen(str)*sizeof(char) + 1);

    strcpy(temp,str);
    len = strlen(temp);

    for(i = 0;temp[i];i++){
        temp[i] = (temp[i] == ' ') ? '\0' : temp[i];
    }

    i = 0;
    for(i = 0;i<len;i++){
        if(temp[i] != '\0'){
           append_rec(&l,&temp[i]);
           i += (get_tail_len(l) - 1);
        }
    }

    free(temp);

    return l;
}

/*
7.3.6 Compare lists of string
Given two lists of strings, write a function
that decides if they are equals.
The comparison between the strings must be done char by char.

TEST:

int print(char *s){
    printf("%s",s);
    return 1;
}


int main(){
    int x;
    list l = NULL,l2 = NULL;

    l = word_in_list_from_string("c");
    l2 = word_in_list_from_string("  c");

    print_list(l);
    print_list(l2);

    printf("%d\n",compare_list_of_string(l,l2));

    x = l?(destroy(&l)):(print("l vuota\n"));
    x = l2?(destroy(&l2)):(print("l2 vuota\n"));

    return 0;
}

*/

int compare_list_of_string(list l1,list l2){
    if(!l1 && !l2){
        return 1;
    }else
    if(!l1 || !l2){
        return 0;
    }else{
        return strcmp(l1->str,l2->str) == 0 &&
        compare_list_of_string(l1->next,l2->next);
    }
}


/*
7.3.7 Substring in list
Write a function that decides if,
given a list of char/scting and a string,
the string is contained in the list.

TEST:

int print(char *s){
    printf("%s",s);
    return 1;
}


int main(){
    int x;
    list l = NULL,l2 = NULL;

    l = word_in_list_from_string("ciao a tutti");

    print_list(l);

    printf("%d\n",substring_in_list(l,"    "));

    x = l?(destroy(&l)):(print("l vuota\n"));
    x = l2?(destroy(&l2)):(print("l2 vuota\n"));

    return 0;
}
*/

int search_substring(list l1,list l2){
    list temp = l2;
    int flag = 0;

    while(!flag && (l1 || !temp)){
        if(!temp){
            flag = 1;
        }else
        if(!strcmp(temp->str,l1->str)){
            temp = temp->next;
            l1 = l1->next;
        }else{
            temp = l2;
            if(!strcmp(temp->str,l1->str)){
                temp = temp->next;
                l1 = l1->next;
            }else{
                l1 = l1->next;
            }
        }
    }

    return flag;
}

int substring_in_list(list l,char *s){
    list s_list = NULL;
    int risp;
    s_list = word_in_list_from_string(s);
    risp = search_substring(l,s_list);
    destroy(&s_list);
    return risp;
}


/*
7.3.13 Count the word frequency
Given a vector of words we want to create a function
that return a list of the minimal length such
that each cell contains a copy of a different
word contained in the array and the number of its
occurrences in the array.
Each cell of the list must contain a different word.
The order of the cells in the list is arbitrary.
We want to solve the exercise following the steps:

A Define the types for the list;

B Define function void prepend(tlist *l, char * str, int val)
the prepend a cell to the list *l which
will contain a copy of the string str and
a number of occurrences val. We can assume
that all the malloc calls will allocate
the dynamic memory successfully. The space
allocated for the strings must be as small as necessary;

C Define the recursive function tlist
is_present(tlistl, char *mystr)
that returns a pointer to the cell containing
a copy of mystr if present, otherwise it returns NULL;

D Define the function void
create_list(tlist *l, char *vetstr[], int size) that given the
vector of strings vetstr return the list
according the requirements of the exercise;

E Define the function void destroy_list(tlist *l)
that frees the heap memory containing the
list and set the pointer *l to NULL;
TEST:
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


    return 0;
}
*/

void print_vet(char **vet,int dim){
    /*int i;
    for(i = 0;i < dim; i++ ){
        printf("%s\n",vet[i]);
    }*/
    while(dim){
        printf("%s\n",*vet);
        dim--;
        vet++;
    }
}

void destroy_vet(char **vet,int dim){
    /*int i;
    for(i = 0;i < dim; i++ ){
        free(vet[i]);
    }
    free(vet);*/
    while(dim){
        free(*(vet + dim -1));
        dim--;
    }
    free(vet);
}

void print_list2(list l){
    if(!l){
        printf("NULL\n");
    }else{
        printf("[ %s (%d) ]->",l->str,l->count);
        print_list2(l->next);
    }
}


int count_word_in_string(char *string){
    int count = 0;

    if(*string != ' ' && *string != '\0'){
        count++;
    }

    while(*string != '\0'){
        if(*string == ' '){
            while(*string == ' '){
                string++;
            }
            if(*string != ' ' && *string != '\0'){
                count++;
            }
        }else{
            string++;
        }
    }
    return count;
}



char** create_vet_of_string( char *string){
    int i,j=0,str_len = strlen(string);
    char **vet, *copy = (char *)malloc((sizeof(char)*str_len) + 1);

    strcpy(copy,string);

    for(i = 0;copy[i];i++){
        copy[i] = (copy[i] == ' ') ? '\0':copy[i];
    }

    vet = (char **)malloc(sizeof(char *)*count_word_in_string(string));
    for(i=0;i<str_len;i++){
        if(copy[i] != '\0'){
            vet[j] = (char*)malloc(sizeof(char)*(strlen(&copy[i])+1));
            strcpy(vet[j],&copy[i]);
            j++;
            i += (strlen(&copy[i]) - 1);
        }

    }

    free(copy);

    return vet;
}


void prepend_2(list *l, char * str, int val){
    list node = (list)malloc(sizeof(struct node));
    if(!node){
        return;
    }
    node->str = (char *)malloc(sizeof(char)*(strlen(str) + 1));
    if(!node->str){
        return;
    }
    strcpy(node->str,str);
    node->count = val;
    node->next = NULL;

    if(!*l){
        *l = node;
    }else{
        node->next = *l;
        *l = node;
    }
}

void append_2(list *l, char * str, int val){
    list temp,node = (list)malloc(sizeof(struct node));
    if(!node){
        return;
    }
    node->str = (char *)malloc(sizeof(char)*(strlen(str) + 1));
    if(!node->str){
        return;
    }
    strcpy(node->str,str);
    node->count = val;
    node->next = NULL;

    if(!*l){
        *l = node;
    }else{
        temp = *l;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = node;
    }
}


list is_present(list l, char *mystr){
    if(!l){
        return NULL;
    }else{
        if(!strcmp(l->str,mystr)){
            return l;
        }else{
            return is_present(l->next,mystr);
        }
    }
}


void create_list(list *l, char **vetstr, int size){
    int i = 0;
    list word;
    while(i<size){
        word = is_present(*l,vetstr[i]);

        if(!word){
            append_2(l,vetstr[i],1);
        }else{
            word->count += 1;
        }
        i++;
    }
}






