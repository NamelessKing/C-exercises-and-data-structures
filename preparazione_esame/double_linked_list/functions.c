#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

/*FUNZIONI FATTI DA ME*/
/*int prepend(list *l,int info){

    list node = (list)malloc(sizeof(struct node));

    if(!node)return 0;

    node->info = info;
    node->next = NULL;
    node->prev = NULL;

    if(!(*l)){
        *l = node;
    }else{
        node->next = *l;
        *l->prev = node;
        *l = node;
    }
}*/

void print_Dlist(Dlist l){
    Node temp = l->head;
    while(temp){
        printf("[ %d ]-> ",temp->info);
        temp = temp->next;
    }
    printf("\n");
}


Dlist getempty_Dlist(){
    Dlist l = (Dlist)malloc(sizeof(struct dlist));
    if(!l){
        return NULL;
    }
    return l;
}

int destroy_list(Node *l){
    if(*l){
        destroy_list(&(*l)->next);
    }else
    if(*l == NULL){
        return 0;
    }
    free(*l);
    return 1;
}

int destroy_Dlist(Dlist *l){
    if(!*l){
        return destroy_list(&(*l)->head);
        free(*l);
        return 1;
    }else{
        return 0;
    }
}

int prepend_Dlist(Dlist *l,int info){
    Node node = (Node)malloc(sizeof(struct node));
    if(!node){
        return 0;
    }

    node->info = info;
    node->prev = NULL;
    node->next = NULL;

    if(!(*l)){
        (*l) = getempty_Dlist();
        if(!(*l)){
            return 0;
        }
        (*l)->head = node;
        (*l)->tail = node;
        return 1;
    }else{
        node->next = (*l)->head;
        (*l)->head->prev = node;
        (*l)->head = node;
        return 1;
    }
}







/*ESERCIZI LIBRO MARIN*/
/*
8.2 Exercises
8.2.1 Append an element to a list
Write a function that, given a doubly
linked list and an integer, appends
to the tail of the list a new
node containing the provided number.
The function returns 1 if the
allocation in the heap of the
new node succeeds, 0 otherwise.
*/
int append(Dlist *l,int info){
    return 0;
}


/*int remove_elem(list *l,int e){
    inf f = 0;
    list t = *l;
    while(t && !f){
        if(t->info == e){
            if(t->next != NULL)
                t->next->prev = t->prev;
            if(t->prev != NULL)
                t->prev->next = t->next;
            free(t);
            f = 1;
        }
    }
    return f;
}*/
