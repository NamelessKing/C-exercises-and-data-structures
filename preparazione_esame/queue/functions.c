#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"


queue getemppty(){
    tqueue q = (tqueue)malloc(struct queue);
    q->head = NULL;
    q->tail = NULL;
    return q;
}


int enqueue(tqueue q,int info){
    if((q)->head == NULL && (*q)->tail == NULL){
        (*q)->head = (struct node*)malloc(sizeof(struct node));
        (*q)->head->info = info;
        (*q)->head->next = NULL
        (*q)->tail = head;
    }else{
        (*q)->tail->next = (struct node*)malloc(sizeof(struct node));
        (*q)->tail->next->info = info;
        (*q)->tail->next->next = NULL;
    }

}
