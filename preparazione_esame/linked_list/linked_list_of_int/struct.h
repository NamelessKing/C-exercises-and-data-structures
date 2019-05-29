
struct node {
   int info;
   struct node *next;
};
typedef struct node *list;

/*firma delle funzioni*/
void print_list(list l);
int destroy(list *l);
int prepend(list *l,int info);
int append_itr(list *l,int info);
int append_rec(list *l,int info);
int remove_head(list *l);
list remove_head_to_return(list *l);
int remove_tail_itr(list *l);
int remove_tail_rec(list *l);
int remove_first_occ_of_elem(list *l,int info);
int remove_all_occ_of_info_rec(list *l,int info);
int remove_all_occ_of_info_itr(list *l,int info);
list numbers_to_list(int num,list aux);
void reverse_list(list *l);
list array_to_list(int *a,int dim);
void print_reverse_rec(list l);
int ordered_list(list l);
void order_a_list(list *l);
void from_tail_to_head(list *l);
list numbers_as_lists(int num,list aux);
int aux_sum_the_lists(list l);
int sum_the_lists(list a,list b);
void remove_cell_if_info_in_array();



/*******************funzioni pdf marin*****************************/
/*
7.3.8 Cumulative sums
Write a function that takes a list of integers
and modifies it in such a way that each element is
replaced with the sum of all the elements in the list from it up to the end.
*/
int cumulative_sums_rec(list l);


/*
7.3.10 Last occurrence of an element
Write a recursive function that receives as input
a list of integers and a number and returns the
pointer to the last cell of the list containing that number.
If it is not in the list, return NULL.
*/
list last_occurrence_of_info(list l,int info);


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
*/
void setzerotail ( list l );

/*
7.3.12 Reverse a list
Write a function that reverses a
list of integers and satisfies the following constraints:
• the elements are never read or copied;
• the list must be traversed only once;
• the use of functions for dynamic memory management
   (malloc, free, ...) is not allowed.
*/
void reverse(list *l);

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
void delete_list_from_last_rep(list *l);

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
*/

list merge(list l1,list l2);
list merge2(list l1,list l2);

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
void erase ( list *l );



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

int delete_last ( list *l , int n , int occ );

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
void double_pairs ( list *l );


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

int remove_sum ( list *l , int sum );


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
int remove_elem ( list *l , int elem , int occ );



