struct node {
   int info;
   struct node *next;
   struct node *prev;
};
typedef struct node *Node;

struct dlist {
  Node head;
  Node tail;
};

typedef struct dlist *Dlist;

/*FUNZIONI FATTI DA ME*/
void print_Dlist(Dlist l);
Dlist getempty_Dlist();
int destroy_list(Node *l);
int destroy_Dlist(Dlist *l);
int prepend_Dlist(Dlist *l,int info);



/*ESERCIZI LIBRO MARIN*/
int remove_elem(Dlist *l,int e);
