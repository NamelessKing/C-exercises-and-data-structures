#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
/**********IMPLEMENTAZIONE FUNZIONI***********/
void print_list(list l){
    if(l){
        printf("[ %d ]-> ",l->info);
        print_list(l->next);
    }else{
        printf("\n");
    }
}

int destroy(list *l){
    if(*l){
        destroy(&(*l)->next);
    }else
    if(*l == NULL){
        return 0;
    }
    free(*l);
    return 1;
}


int prepend(list *l,int info){
    list node = (list)malloc(sizeof(struct node));
    if(!node){
        return 0;
    }
    node->info = info;
    node->next = NULL;
    if(*l == NULL){
        *l = node;
    }else{
        node->next = *l;
        *l = node;
    }
    return 1;
}


int append_itr(list *l,int info){
    list node,temp;
    if(!(*l)){
        return prepend(l,info);
    }

    node = (list)malloc(sizeof(struct node));
    if(!node){
        return 0;
    }
    node->info = info;
    node->next = NULL;

    temp = *l;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = node;
    return 1;
}

int append_rec(list *l,int info){
    if(!*l){
        *l = (list)malloc(sizeof(struct node));
        if(!*l){
            return 0;
        }
        (*l)->info = info;
        (*l)->next = NULL;
        return 1;
    }else{
        return append_rec(&(*l)->next,info);
    }
}

int remove_head(list *l){
    list temp;
    if(!*l){
        return 0;
    }else{
        temp = *l;
        *l = (*l)->next;
        free(temp);
        return 1;
    }
}

list remove_head_to_return(list *l){
    list temp;
    if(!*l){
        return NULL;
    }

    temp = *l;
    *l = (*l)->next;
    temp->next = NULL;
    return temp;
}

int remove_tail_itr(list *l){
    list *temp/*,temp2 = NULL*/;
    if(!*l){
        return 0;
    }else{
        temp = l;

        while((*temp)->next){
            temp = &((*temp)->next);
        }
        free(*temp);
        *temp = NULL;
        return 1;
    }
}

int remove_tail_rec(list *l){
    if(!*l){
        return 0;
    }else
    if(!(*l)->next){
        free(*l);
        *l = NULL;
        return 1;
    }else{
        return remove_tail_rec(&(*l)->next);
    }
}

int remove_first_occ_of_elem(list *l,int info){
    list temp,prev;
    if(!*l){
        return 0;
    }else{
        list temp = *l;
        prev = temp;
        while(temp && temp->info != info){
            prev = temp;
            temp = temp->next;
        }
        /*prev->next = temp->next;*/
        if(temp == prev){
            if(temp->next){
                *l = temp->next;
            }else{
                *l = NULL;
            }
        }else{
            if(temp)
                prev->next = temp->next;
        }
        free(temp);
        /*printf("%p\n",temp);
        printf("%p\n",prev);*/
        return 1;
    }
}


int remove_all_occ_of_info_rec(list *l,int info){
    list temp;
    if(!*l){
        return 0;
    }else{
        if((*l)->info == info){
            temp = *l;
            *l = (*l)->next;
            free(temp);
            return remove_all_occ_of_info_rec(l,info);
        }else{
            return remove_all_occ_of_info_rec(&(*l)->next,info);
        }
    }
}


int remove_all_occ_of_info_itr(list *l,int info){
    list temp,prev;
    if(*l){
        if(!(*l)->next && (*l)->info == info ){
            free(*l);
            *l = NULL;
            return 1;
        }else{
            temp = *l;
            prev = temp;
            while(temp){
                if(temp->info == info){
                    if(*l == temp){
                        *l = temp->next;
                        free(temp);
                        temp = *l;
                        prev = temp;
                    }else{
                        prev->next = temp->next;
                        free(temp);
                        temp = prev->next;
                    }
                }else{
                    prev = temp;
                    temp = temp->next;
                }
            }
        }

        return 1;

    }else{
        return 0;
    }
}


list numbers_to_list(int num,list aux){
    if(!num){
        return aux;
    }else{
        aux = numbers_as_lists(num/10,aux);
        prepend(&aux,(num%10));
        return aux;
    }
}

void reverse_list(list *l){
    list temp;
    if(*l && (*l)->next){
        temp = (*l)->next;
        reverse_list(&temp);
        (*l)->next->next = *l;
        (*l)->next =NULL;
        (*l) = temp ;
    }
}


list array_to_list(int *a,int dim){
    list l;
    if(dim <= 0){
        return NULL;
    }else{
        l = (list)malloc(sizeof(struct node));
        l->info = *a;
        l->next = array_to_list(a+1,dim - 1);
        return l;

    }
}


/***********17/05/2019**********/
void print_reverse_rec(list l){
    list temp,sentinel = NULL;
    if(!l){
        printf("LISTA VUOTA");
    }else{
        temp = l;
        while(sentinel != l){
            if(temp->next == sentinel){
                printf("%d ",temp->info);
                sentinel = temp;
                temp = l;
            }else{
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

int ordered_list(list l){
    if(l && l->next){
        return (l->info <= l->next->info) && ordered_list(l->next);
    }
    return 1;
}


/*
TEST:

int print(char *s){
    printf("%s",s);
    return 1;
}


int main(){
    int x;
    list l = NULL,temp = NULL;
    append_itr(&l,8);
    append_itr(&l,2);
    append_itr(&l,30);
    append_itr(&l,4);
    append_itr(&l,7);
    append_itr(&l,1);

    print_list(l);
    order_a_list(&l);
    print_list(l);
    printf("%d\n",ordered_list(l));

    x = l?(destroy(&l)):(print("l vuota\n"));

    return x;
}

*/
void order_a_list(list *l){
    list temp,sup,prev;

    /*controllo se ci sono almeno 2 elementi*/
    if((*l) && (*l)->next){
        /*continuo a ciclare finche non ottengo la lista ordinata*/
        while(!ordered_list(*l)){
            prev = *l;
            sup = *l;
            temp = sup->next;

            while(temp){

                if(sup->info > temp->info){
                    sup->next = temp->next;
                    temp->next = sup;

                    if(sup == *l){
                        *l = temp;
                        prev = *l;
                        temp = sup->next;
                    }else{
                        prev->next = temp;
                        prev = temp;
                        temp = sup ->next;
                    }
                }else{
                    if(prev != *l){
                        prev = sup;
                    }
                    sup = temp;
                    temp = temp->next;
                    if(prev->next->next == sup){
                        prev = prev->next;
                    }

                }
            }
        }
    }
}

/*ULTIMA LEZIONE MARIN*/
/***********16/05/2019**********/
/*void elimina(list *l){
    if((*l) =! NULL){
        elimina(&(*l)->next);
        free(*l);
        *l = NULL;
    }
}

void inverti(list *l){
    if(*l != NULL && (*l)->next != NULL){
        list c = (*l)->next;
        inverti(&c);
        (*l)->next->next = *l;
        (*l)->next->NULL;
    }
}


list* last_node_info_adress( list l,int info){
    if(!l){
        return NULL;
    }else{
        tist t = last_node_info_adress(l->next,info);
        if(t == NULL){
            return (l->info == info)?l:NULL;
        }else{
            return t;
        }
    }
}*/










void from_tail_to_head(list *l){
    list temp = *l;
    while(temp->next){
        temp = temp->next;
    }

    temp->next = *l;
}




/*********ESERCIZIARIO MARIN LISTE*************/
/*
7.3.1
Numbers as lists
Write a subroutine that transforms a positive integer
number given as parameter into a list of integers.
Each node of the list contains a decimal digit of the number,
the empty list represents the number 0.
The order of the digit must be defined such
that the original number (if different from 0)
can be read by printing the list elements from the last to the first.
*/
list numbers_as_lists(int num,list aux){
    if(!num){
        return aux;
    }else{
        aux = numbers_as_lists(num/10,aux);
        prepend(&aux,(num%10));
        return aux;
    }
}


/*
7.3.2
Sum the lists
Given the number encoding defined by Exercise 7.3.1,
define a subroutine that sums two numbers
represented as lists.
Do not convert the lists into the standard int type.

TEST WITH THIS IN MAIN:
    int x;
    list l = NULL,test = NULL;

    l = numbers_as_lists(3,NULL);
    test = numbers_as_lists(14,NULL);

    print_list(l);
    print_list(test);
    print_reverse_rec(l);
    print_reverse_rec(test);
    printf("%d+%d = %d",aux_sum_the_lists(l),aux_sum_the_lists(test),sum_the_lists(l,test));
    x = l?(destroy(&l)):(print("l EMPTY\n"));
    x = test?(destroy(&test)):(print("test EMPTY\n"));
*/
int aux_sum_the_lists(list l){
    int num;
    if(!l){
        return 0;
    }
    if(!l->next){
        return l->info;
    }else{
        num = aux_sum_the_lists(l->next);
        num = ((num*10)+(l->info));
        return num;
    }
}

int sum_the_lists(list a,list b){
    return aux_sum_the_lists(a) + aux_sum_the_lists(b);
}

/*
7.3.4
Difference between list and vector
Given a list of integers `, a vector of integers
v and its dimension, write a function that returns the
elements which are contained by ` but not by v.
*/

void remove_cell_if_info_in_array(list *l,int vet[],int dim){
    int i,flag = 0;
    list temp;
    if(!*l){
        return;
    }else{
        for(i = 0;i<dim && !flag;i++){
            flag = (*l)->info == vet[i];
        }
        if(flag){
            temp = *l;
            *l = (*l)->next;
            free(temp);
            remove_cell_if_info_in_array(l,vet,dim);
        }else{
            remove_cell_if_info_in_array(&(*l)->next,vet,dim);
        }
    }
}


/*
7.3.8
Cumulative sums
Write a function that takes a list of integers
and modifies it in such a way that each element is
replaced with the sum of all the elements in the list from it up to the end.

TEST:
int print(char *s){
    printf("%s",s);
    return 1;
}


int main(){
    int x;
    list l = NULL,l2 = NULL;

    l = numbers_to_list(360542,NULL);
    reverse_list(&l);

    print_list(l);
    cumulative_sums_rec(l);
    print_list(l);
    x = l?(destroy(&l)):(print("l vuota\n"));
    x = l2?(destroy(&l2)):(print("l2 vuota\n"));

    return 0;
}
*/
int cumulative_sums_rec(list l){
    int val;
    if(l && l->next){
        val = cumulative_sums_rec(l->next);
        l->info = l->info + val;
        return l->info;
    }
    return l->info;
}

/*
7.3.10
Last occurrence of an element
Write a recursive function that receives as input
a list of integers and a number and returns the
pointer to the last cell of the list containing that number.
If it is not in the list, return NULL.

TEST:
int print(char *s){
    printf("%s",s);
    return 1;
}


int main(){
    int x;
    list l = NULL,l2 = NULL;

    l = numbers_to_list(3605542,NULL);
    reverse_list(&l);

    print_list(l);
    l2 = last_occurrence_of_info(l,5);
    print_list(l2);
    x = l?(destroy(&l)):(print("l vuota\n"));

    return 0;
}
*/
list last_occurrence_of_info(list l,int info){
    list risp;
    if(!l){
        return NULL;
    }else{
        risp = last_occurrence_of_info(l->next, info);
        if(l->info == info && !risp){
            risp = l;
        }
        return risp;
    }
}

/*
7.3.11
Write zeros at the end of a list
Given a list of int that, by hypothesis,
does not contain any zero value implement the function:
void setzerotail ( tlist l );
that sets to zero all the elements from the
last positive number to the end of the list. Examples:
• 1-(−4)-6-(−2)-(−5) returns 1-(−4)-6-0-0
• empty list returns empty list
• 6 returns 6
• (−5) − (−3) returns 0-0

Do not use any other auxiliary function or
call to the malloc function to duplicate the nodes.

TEST:
int print(char *s){
    printf("%s",s);
    return 1;
}


int main(){
    int x;
    list l = NULL;
    append_itr(&l,-1);
    append_itr(&l,-4);

    print_list(l);
    setzerotail(l);
    print_list(l);


    x = l?(destroy(&l)):(print("l vuota\n"));

    return 0;
}
*/
void setzerotail ( list l ){
    if(l){
        setzerotail (l->next);
        if(l->info < 0 && (!l->next || l->next->info == 0 )){
            l->info = 0;
        }
    }
}

/*
7.3.12 Reverse a list
Write a function that reverses a
list of integers and satisfies the following constraints:
• the elements are never read or copied;
• the list must be traversed only once;
• the use of functions for dynamic memory management
   (malloc, free, ...) is not allowed.
*/
void reverse(list *l){
    if(*l && (*l)->next){
        list pc = (* l) -> next ;
        reverse (& pc );
        (* l)-> next -> next = *l ;
        (* l)-> next = NULL ;
        (* l) = pc ;
    }
}

/*
7.3.14
Delete a list from the last repetition
Given a list of integers, write the following function:
void remove_elements ( tlist *l );
that deletes from the dynamic memory all the list cell
from the last two consecutive numbers (not
included) to the end of the list. Examples:
• 4 − 4 ⇒ empty list
• 5 − 7 − 9 − 9 − 9 − 3 − 4 − 4 − 4 − 4 − 5 − 6 − 3 ⇒ 5 − 7 − 9 − 9 − 9 − 3 − 4 − 4 − 4 − 4
• 6 ⇒ empty list
*/

/*void delete_list_from_last_rep(list *l){
    if(*l){

    }
}*/




/*int delete_list_from_last_rep(list *l){
    int info;
    if(*l && (*l)->next){
        info = delete_list_from_last_rep(&(*l)->next);
        if(info != (*l)->info){
            info = (*l)->info;
            free(*l);
            return info;
        }
    }else{
        info = (*l)->info;
        free(*l);
        return info;
    }
}*/
/*void delete_list_from_last_rep(list *l){
    if(*l && (*l)->next){
        delete_list_from_last_rep(&(*l)->next);
        if((*l)->info != (*l)->next->info ){
            free((*l)->next);
            (*l)->next = NULL;
            free((*l));
            (*l) = NULL;
        }
    }
}*/




/*
7.3.15
Alternating merge of two lists
Given two lists l1 and l2, write the following function:
tlist merge ( tlist l1 , tlist l2 );
that returns a list with the elements of l1 and l2 alternating.
If one of the two lists is longer than
the other, then all its exceeding elements will be added consecutively.

Solution.
If we accept to destroy the input list
l1 and l2, then the solution becomes trivial as
shown in Table 7.20. A little bit longer is
the solution that duplicates the lists but it is conceptually
identical.

TEST:
int print(char *s){
    printf("%s",s);
    return 1;
}


int main(){
    int x;
    list l1 = NULL,l2 = NULL,merged = NULL;

    append_itr(&l1,3);
    append_itr(&l1,88);

    append_itr(&l2,3);
    append_itr(&l2,1);
    append_itr(&l2,6);
    append_itr(&l2,9);
    append_itr(&l2,7);
    append_itr(&l2,8);

    print_list(l1);

    print_list(l2);

    merged = merge2(l1,l2);

    print_list(l1);
    print_list(l2);
    print_list(merged);





    x = l1?(destroy(&l1)):(print("l1 vuota\n"));
    x = l2?(destroy(&l2)):(print("l2 vuota\n"));
    x = merged?(destroy(&merged)):(print("merged vuota\n"));

    return x;
}
*/

list merge(list l1,list l2){
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }
    l1->next = merge(l2,l1->next);
    return l1;
}

list copy_list(list l){
    list temp=NULL;
    if(!l){
        return NULL;
    }
    prepend(&temp,l->info);
    temp->next = copy_list(l->next);
    return temp;
}

list merge2(list l1,list l2){
    list temp = NULL;
    if(!l1){
        return copy_list(l2);
    }
    if(!l2){
        return copy_list(l1);
    }
    temp = (list)malloc(sizeof(struct node));
    temp->info = l1->info;
    temp->next = merge2(l2,l1->next);
    return temp;


}

/*
7.3.17 Erase contiguous identical cells in a list
Write the recursive function:
void erase ( tlist *l );
that, given a list of integers pointed by l,
modifies the list according to the following rules:

• If the list contains a sequence of identical
cells with even length then the sequence is completely
erased

• If the list contains a sequence of identical
cells with odd length then the sequence is replaced
by a single element whose value is the value
of the elements of the eliminated sequence.

For instance, the following list:
10, 10, 10, 10, 16, 14, 12, 12, 12, 12, 12, 10
becomes:
16, 14, 12, 10
*/


void erase( list *l ){
    list temp;
    if(*l && (*l)->next){

        if((*l)->info == (*l)->next->info){
            temp = (*l)->next->next;
            free((*l)->next);
            free(*l);
            *l = temp;
            erase(l);
        }else{
            erase(&(*l)->next);
        }
    }
}

/*
7.3.20 Remove the last occ occurrences
of an item n in a list
Given a list of integers, write a
function that deletes the last occ
occurrences of an item n if they
exist. The function returns the
number of deletions that have been actually done.
The signature of the function is:;
*/

int delete_last ( list *l , int n , int occ ){
    list temp;
    int count;

    if(!(*l)  || !occ){
        return 0;
    }else{
        count = delete_last(&(*l)->next,n,occ);
        if((*l)->info == n && count < occ){
            temp = (*l);
            (*l)=(*l)->next;
            free(temp);
            temp = NULL;
            count++;
            return count;
        }else{
            return count;
        }
    }
}


/*
7.3.22 Double the pairs
Given a list of integers, we desire to write function:
void double_pairs ( tlist *l );
that duplicates the pairs of elements.
Each number in the list can be used to form only one pair.
Examples:
• List [2,7,7,7,2] becomes [2,7,7,7,7,2]
• List [2,3,3,4,6,6,6,0] becomes [2,3,3,3,3,4,6,6,6,6,6,0]
*/
void double_pairs ( list *l){
    if(!*l || !(*l)->next) return;
    if((*l)->info == (*l)->next->info){
        list temp = (list)malloc(sizeof(struct node));
        temp->info = (*l)->info;
        temp->next = (list)malloc(sizeof(struct node));
        temp->next->info = (*l)->info;
        temp->next->next = (*l)->next->next;
        (*l)->next->next = temp;
        double_pairs(&temp->next->next);
    }else double_pairs(&(*l)->next);
}

/*
7.3.23 Delete the last elements on the list whose sum is limited
Given a list of integers, we desire to write the recursive function:
void remove_sum ( tlist *l , int sum );
that deletes from the input list the maximum
number of elements from the tail such that their sum
is lower or equal to sum. T
he function returns the sum of the elements that have been deleted.
For example, given list [3,5,12,7,4,2] and sum=20,
we obtain list [3,5,12] and the function returns 13.
*/

/*void remove_sum ( list *l , int sum ){
    list temp;
    if((*l) && (*l)->next){
        temp = (*l)->next;
        remove_sum ( &(*l)->next ,sum );

        if(((*l)->info + temp->info) <= sum){
            (*l)->info = ((*l)->info + temp->info);
            (*l)->next = NULL;
            free(temp);
        }
    }
}*/

int remove_sum ( list *l , int sum ){
    int rank;
    list temp;
    if(!(*l)){
        return 0;
    }else{
        rank = remove_sum ( &(*l)->next ,sum );
        rank += (*l)->info;
        if(rank<=sum){
            temp = (*l);
            (*l) = (*l)->next;
            free(temp);
            return rank;
        }else{
            return (rank + (*l)->info);
        }
    }
}

/*
7.3.24 Remove the first occurrences of an element
Write function:
int remove_elem ( tlist *l , int elem , int occ );
that removes occ occurrences of elem from the list.
In the case of a list which contains not less
occurrences than occ, then we remove the first
items with elem and the function returns then value
of occ. If the list contains less occurrences than occ,
then we remove them all and return the number
of cells that we have effectively deleted.
*/
int remove_elem ( list *l , int elem , int occ ){
    if(!(*l) || !occ){
        return 0;
    }else{
        if((*l)->info == elem){
            list temp = (*l);
            (*l) = (*l)->next;
            free(temp);
            return  1 + remove_elem(l,elem,occ - 1);
        }else{
            return 0 + remove_elem(&(*l)->next,elem,occ);
        }
    }
}




























/*8.2.4 Find pairs in a circular list
Write a function that decides if a circular list
contains at least two distinct consecutive cells with
the same element.
*/
int find_pairs(list l){
    int res = 0;
    list p = l;

    if(p != NULL && p->next != p ){
        do{
            res = res || (p->info == p->next->info);
            p = p->next;
        }while(!res && p != l);
    }

    return res;
}

/*
8.2.5 Print a circular list recursively and in reversed order
Given a circular list of integers, write the recursive function:
void print_ac ( tlist l1 , tlist l2 );
that prints a list in the anti-clockwise order.
We consider clockwise to be the order given by the
pointers, i.e., if cell A has a pointer to cell B,
then the sequence A, B is clockwise. The function will
be called to print list l as:
print_ac (l ,l );
*/
void pr(list l ,list h){
    if(l->next == h){
        printf("%d ",l->info);
    }else{
        pr(l->next , h);
        printf("%d ",l->info);
    }
}
/**********************/
