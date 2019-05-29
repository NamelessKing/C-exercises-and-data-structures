#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 100

void stampa_array(int a[],int dim){
    int i;
    for(i = 0; i < dim;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}


int is_inside_elem_from_to(int a[],int from,int to,int x){
    int i = from,risp = 0;
    while(i<to && !risp){
        risp = a[i] == x;
        i++;
    }

    return risp;
}

int is_inside_elem(int a[],int x,int dim){
    int i = 0,risp = 0;
    while(i<dim && !risp){
        risp = a[i] == x;
        i++;
    }
    return risp;
}



/*
5.
Write a program in C to count a total
number of duplicate elements in an array
Test Data :
Input the number of elements to be stored in the array :3
Input 3 elements in the array :
element - 0 : 5
element - 1 : 1
element - 2 : 1
Expected Output :
Total number of duplicate elements found in the array is : 1
*/

int count_duplicate_elements(int a[],int dim){
    int i,j,check_arr[DIM],check_arr_dim = 0,count_dup = 0;

    for(i=0;i<dim;i++){
        for(j = i + 1; j<dim; j++){
            if(a[i]==a[j] && !is_inside_elem(check_arr,a[i],check_arr_dim)){
                check_arr[check_arr_dim]=a[i];
                check_arr_dim++;
                count_dup++;
            }
        }
    }
    return count_dup;
    /*
    TEST WITH THESE LINES IN main()
    int dim = 14;
    int arr[] = {4,1,2,1,1,2,1,1,1,1,3,8,7};

    printf("%d",count_duplicate_elements(arr,dim));
    */
}

/***********************************************************************************************/

/*
6.
Write a program in C to print all unique elements in an array.
Test Data :
Input the number of elements to be stored in the array :3
Input 3 elements in the array :
element - 0 : 1
element - 1 : 5
element - 2 : 1
Expected Output :
The unique elements found in the array are :
5
*/
void unique_elements(int a[DIM],int dim,int unic_elem_arr[DIM]){
    int i,j,flag = 0;
    unic_elem_arr[0]=0;
    for(i = 0; i<dim; i++){
        flag = 0;
        for(j = 0; j<dim && !flag; j++){
            if(a[i] == a[j] && i != j){
                flag = !flag;
            }
        }

        if(!flag ){
            unic_elem_arr[0]++;
            unic_elem_arr[unic_elem_arr[0]] = a[i];
        }
    }

    /*
    TEST WITH THESE LINES IN main()
    int unic_elem_arr[DIM];
    int a[DIM] = {1,5,1,1,3,4,5,5,5,6,30,40};
    unique_elements(a,12,unic_elem_arr);
    stampa_array(unic_elem_arr,unic_elem_arr[0] + 1);
    */
}

/***********************************************************************************************/

/*
7.
Write a program in C to merge two arrays of same size sorted in decending order.
Test Data :
Input the number of elements to be stored in the first array :3
Input 3 elements in the array :
element - 0 : 1
element - 1 : 2
element - 2 : 3
Input the number of elements to be stored in the second array :3
Input 3 elements in the array :
element - 0 : 1
element - 1 : 2
element - 2 : 3
Expected Output :
The merged array in decending order is :
3 3 2 2 1 1
*/

void merge_two_arrays_same_size_sorted(int arr1[DIM],int arr2[DIM],int merged_arr[DIM],int dim){
    int i,j,max1,max2;
    merged_arr[0]=0;

    for(i = 0;i<dim;i++){
        max1 = arr1[i];
        max2 = arr2[i];
        for(j = i + 1; j<dim;j++){
            if(arr1[j]>=arr1[i] && !is_inside_elem_from_to(merged_arr,1,merged_arr[0] + 1,arr1[j])){
                max1 = arr1[j];
            }
            if(arr2[j]>=arr2[i] && !is_inside_elem_from_to(merged_arr,1,merged_arr[0] + 1,arr2[j])){
                max2 = arr2[j];
            }
        }

        if(max1>=max2){
            merged_arr[0]++;
            merged_arr[merged_arr[0]]=max1;
            merged_arr[0]++;
            merged_arr[merged_arr[0]]=max2;
        }else{
            merged_arr[0]++;
            merged_arr[merged_arr[0]]=max2;
            merged_arr[0]++;
            merged_arr[merged_arr[0]]=max1;
        }
    }


}

int main(){

    int a[DIM]={3,7,9,1,2};
    int b[DIM]={10,4,1,2,6};
    int ris[DIM];

    merge_two_arrays_same_size_sorted(a,b,ris,5);

    stampa_array(ris,ris[0] + 1);
    return 0;
}
