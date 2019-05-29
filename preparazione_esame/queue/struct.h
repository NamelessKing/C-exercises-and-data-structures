struct node {
   int info;
   struct node *next;
};
typedef struct queue {
    struct node *head;
    struct node *tail;
};

typedef struct queue *tqueue;

queue getemppty();
int enqueue(tqueue q,int info);
