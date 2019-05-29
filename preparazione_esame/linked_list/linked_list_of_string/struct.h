struct node {
   int count;
   char *str;
   struct node *next;
};
typedef struct node *list;

/*firma delle funzioni di supporto*/
void print_list(list l);
int destroy(list *l);
int prepend(list *l,char *info);
int append_itr(list *l,char *info);
int append_rec(list *l,char *info);
int get_tail_len(list l);
int remove_head(list *l);



/*******************funzioni pdf marin*****************************/
/*
7.3.5 Identify words in a paragraph
Given a string containing a paragraph,
write a function that returns a list of strings in which each
cell contains a word of the paragraph.
Assume that the every word is separated from the other by
a sequence of at least one blank ’ ’.
Do not use any function from library string.h.
*/
list word_in_list_from_string(char *str);

/*
7.3.6 Compare lists of string
Given two lists of strings, write a function
that decides if they are equals.
The comparison between the strings must be done char by char.
*/
int compare_list_of_string(list l1,list l2);

/*
7.3.7 Substring in list
Write a function that decides if,
given a list of char/string and a string,
the string is contained in the list.
*/
int search_substring(list l1,list l2);
int substring_in_list(list l,char *s);


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
*/
int count_word_in_string(char *string);
char** create_vet_of_string(char *string);
void print_vet(char **vet,int dim);
void destroy_vet(char **vet,int dim);
void print_list2(list l);
/*void test( char *string);*/

void prepend_2(list *l, char * str, int val);
void append_2(list *l, char * str, int val);
list is_present(list l, char *mystr);
void create_list(list *l, char *vetstr[], int size);


