/********************12/03/2019*************************************/
#include <stdio.h>
#include <string.h>
#define DIM 100
#define MATRIX_DIM 9
#define GENERAL_DIM 5


void stampa_array(int a[],int dim){
    int i;
    for(i = 0; i < dim;i++){
        printf("%d ",a[i]);
    }
}


void read_string(){
    char mystring[100]={9};
    int i;
    scanf("%s",mystring);
    /*printf("La string letta e \n%s\n",mystring);*/

    i = 0;
    while(mystring[i]){
        printf("%c\n",mystring[i]);
        i++;
    }

}


void stringhe_uguali(){
    char str1[DIM], str2[DIM];
    int i,flag = 1;

    printf("inserire prima parola\n");
    scanf("%[^\n]%*c",str1);
    printf("inserire seconda parola\n");
    scanf("%[^\n]%*c",str2);


    i = 0;
    while(flag && (str1[i]!='\0' ||  str2[i]!='\0')){
        printf("%c <==> %c\n",str1[i],str2[i]);
        if(str1[i] != str2[i]){
            flag = 0;
        }
        i++;
    }

    if(flag){
        printf("Stringhe uguali");
    }else{
        printf("Stringhe diverse");
    }

}



void print_char_and_value(){

    char alfa_min[DIM]="abcdefghijklmnopqrstuvwxyz";
    char alfa_max[DIM]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;

    printf("CARATTERI IN MINUSCOLO\n");
    for ( i = 0; alfa_min[i]; i++) {
        printf("%c <==> %d\n",alfa_min[i],alfa_min[i]);
    }


    printf("\n\nCARATTERI IN MINUSCOLO\n");
    for ( i = 0; alfa_max[i]; i++) {
        printf("%c <==> %d\n",alfa_max[i],alfa_max[i]);
    }


}



void my_strcmp(){
    char str1[DIM], str2[DIM];
    int i,flag=1;

    printf("inserire prima parola\n");
    scanf("%[^\n]%*c",str1);
    printf("inserire seconda parola\n");
    scanf("%[^\n]%*c",str2);

    printf("\nORIGINAL =>%d",strcmp(str1,str2));

    printf("\n\n");

    i = 0;
    while(flag && (str1[i]!='\0' ||  str2[i]!='\0')){
       /* printf("%c <==> %c\n",str1[i],str2[i]);*/

        if(str1[i] != str2[i]){
            flag = 0;
        }else{
            i++;
        }
    }


    printf("*****************************\n");
    /*printf("%c <==> %c\n",str1[i],str2[i]);*/

    if((str1[i]<str2[i])){
        printf("-1 =====> %d",str1[i]-str2[i]);
    }else if((str1[i]>str2[i])){
        printf("1 =====> %d",str1[i]-str2[i]);
    }else{
        printf("0 =====> %d",str1[i]-str2[i]);
    }

}





int my_strcmp2(){
    char str1[DIM], str2[DIM];
    int i,flag=1,risp=0;

    printf("inserire prima parola\n");
    scanf("%[^\n]%*c",str1);
    printf("inserire seconda parola\n");
    scanf("%[^\n]%*c",str2);

    printf("\nORIGINAL =>%d",strcmp(str1,str2));

    printf("\n\n");

    i = 0;
    while(flag && (str1[i]!='\0' ||  str2[i]!='\0')){
       /* printf("%c <==> %c\n",str1[i],str2[i]);*/

        if(str1[i] < str2[i]){
            flag = 0;
            risp = -1;
        }else if(str1[i] >str2[i]){
            flag = 0;
            risp = 1;
        }else{
            i++;
        }
    }

    return risp;

}


/********************15/03/2019*************************************/

char* my_strcat(char dest[DIM],char src[DIM]){
    int i,dest_i;

    for(dest_i = 0; dest[dest_i];dest_i++ );

    for(i = 0;src[i];i++,dest_i++){
        /*printf("dest_i=%d  i=%d \n",dest_i,i);*/
        dest[dest_i] = src[i];
        /*printf("%c\n",dest[dest_i]);*/
    }

    /*printf("dest_i=%d  i=%d \n",dest_i,i);*/
    dest[dest_i] = '\0';

    return dest;
}

void printarray(int dest[DIM],int size){
    int i;

    for (i = 0; i < size; i++) {
        printf("%d\n",dest[i]);
    }
}

/***************(ESERCIZI MARIN 13/03/2019) 17/03/2019**********************/

/*
ritorna 1(true) se tosearch[] è il prefisso di content[]
altrimenti ritorna 0(false).
esempi:
is_prefix("ciao","ciao")    => 1
is_prefix("cia","ciao")     => 1
is_prefix("ciaoaa","ciao")  => 0
is_prefix("ciao","addio")   => 0
is_prefix("","ciao")        => 1 (se tosearch[0] ha elemento nullo (cioè stringa vuota) ritorna sempre 1)
*/
int is_prefix(char tosearch[],char content[]){
    int i,risp = tosearch[0]!='\0';

    i = 0;
    while(risp && tosearch[i]){
        if(tosearch[i]==content[i]){
            i++;
        }else{
            risp = !risp;
        }
    }

    return tosearch[0] ? risp : !risp;
}

/*ritorna 1(true) se una tosearch[] è contenuta in content[] */
int is_inside(char tosearch[],char content[]){
    int i,j,risp = tosearch[0]!='\0',triggered = 0;

    i=0;
    j=0;
    while(risp && tosearch[j]){
        if(content[i] == tosearch[j] && !triggered){
            triggered = !triggered;
        }

        if(!content[i]){
            risp = !risp;
        }

        if(triggered){
            if(content[i] == tosearch[j]){
                i++;
                j++;
            }else{
                j=0;
                triggered = !triggered;
            }
        }else{
            i++;
        }
    }

    return tosearch[0] ? risp : !risp;
}

/****************************** 19/03/2019**********************/


/*
MATRICE DA USARE COME PRPVA

    int campo1[MATRIX_DIM][MATRIX_DIM] = {
        { 8, 2, 1, 5, 4, 6, 3, 7, 9 },
        { 9, 6, 4, 8, 3, 7, 5, 2, 1 },
        { 5, 3, 7, 2, 1, 9, 6, 8, 4 },
        { 7, 1, 6, 4, 8, 2, 9, 5, 3 },
        { 3, 4, 9, 7, 5, 1, 8, 6, 2 },
        { 2, 8, 5, 6, 9, 3, 4, 1, 7 },
        { 1, 5, 8, 9, 7, 4, 2, 3, 6 },
        { 4, 7, 2, 3, 6, 5, 1, 9, 8 },
        { 6, 9, 3, 1, 2, 8, 7, 4, 5 }
    };

*/




/*Ritorna la somma degli elementi di una riga di una matrice*/
int sum_row(int matrix[][MATRIX_DIM],int row){
    int i,sum = 0;

    for (i = 0; i < MATRIX_DIM; i++) {
        sum += matrix[row][i];
    }

    return sum;
}

/*Ritorna la somma degli elementi di una colonna di una matrice*/
int sum_col(int matrix[][MATRIX_DIM],int col){
    int i,sum = 0;

    for (i = 0; i < MATRIX_DIM; i++) {
        sum += matrix[i][col];
    }

    return sum;
}


/*
Ritorna 1 se la somma degli elementi di ciascuna riga della
matrice danno lo stesso risultato
*/
int is_sum_rows_is_equal(int matrix[][MATRIX_DIM]){

    int i,sum = 0,risp = 0;

    sum = sum_row(matrix,0);

    for(i = 1; i < MATRIX_DIM && !risp; i++){
        if(sum != sum_row(matrix,i)){
            risp = !risp;
        }
    }

    return !risp;
}


/*
Ritorna 1 se la somma degli elementi di ciascuna colonna della
matrice danno lo stesso risultato
*/
int is_sum_cols_is_equal(int matrix[][MATRIX_DIM]){

    int i,sum = 0,risp = 0;

    sum = sum_col(matrix,0);

    for(i = 1; i < MATRIX_DIM && !risp; i++){
        if(sum != sum_col(matrix,i)){
            risp = !risp;
        }
    }

    return !risp;
}


/*
Ritorna la somma degli elementi della diagonale di una matrice
*/
int sum_diagonal(int matrix[][MATRIX_DIM],int row,int col){
    int i,iterate,sum = 0;

    if(row>col){
        iterate = col;
    }else{
        iterate = row;
    }

    for(i=0; i<iterate;i++ ){
        sum +=  matrix[i][i];
    }

    return sum;
}


/****************************** 17/03/2019**********************/
/*
insert_elem_to_array(int v1[DIM],int elem,int pos,int length)
funzione che inserisce un elemento(intero) in un array di interi
tenendo nell'array i numeri successi alla posizione da inserire
*/
void insert_elem_to_array(int v1[DIM],int elem,int pos,int length){
    int i;

    for(i = length; i>=pos; i--){
        v1[i] = v1[i - 1];
    }
    v1[pos] = elem;

    /*
    TEST WITH THESE LINES IN main()
    int i;
    int len = 10;
    int v1[DIM] = {1,2,3,4,5,6,7,8,9,10};

    insert_elem_to_array(v1,99,4,len);

    for ( i = 0; i <= len; i++) {
        printf("%d, ",v1[i]);
    }
    */
}

/*----------------------------------------------------------------*/

/*
Ritorna la somma degli elementi della diagonale secondaria di una matrice
*/
int sum_secondary_diagonal(int matrix[DIM][DIM],int row,int col){
    int i,j,k,sum = 0,iterate;

    if(row>col){
        iterate = col;
    }else{
        iterate = row;
    }

    for(i = 0,j = col - 1,k = 0;k<iterate; i++,j--,k++ ){
        sum += matrix[i][j];
    }

    return sum;

    /*
    TEST WITH THESE LINES IN main()
    int mat[DIM][DIM] ={
        {8, 2, 1, 5,1},
        {9, 6, 4, 8,1},
        {5, 3, 7, 2,1},
        {7, 1, 6, 4,1}
    };

    int sum = sum_secondary_diagonal(mat,4,5);
    printf("\n%d\n",sum);
    */
}

/*----------------------------------------------------------------*/
/*
Ritorna la somma degli elementi di una diagonale secondaria di una matrice
in base all'alle coordinate date
*/
/*
DA FINIREEEE
int sum_secondary_diagonal_by_xy(int matrix[DIM][DIM],int x,int y,int row,int col){

}*/


/*
********************************************************************
********************************************************************
***************************** 17/03/2019****************************
********************************************************************
********************************************************************
*/

/*
Data una matrice di float DIM1xDIM2 e un array di float di
dimensione DIM1, sommarare gli elementi delle righe della
matrice e salvare il valore nel vettore. La posizione i del
vettore deve contenere la somma degli elementi della riga i
della matrice
*/
void sum_row_in_array(int mat[][DIM],int array[],int dim){
    int i,j,sum = 0;

    for(i = 0;i<dim;i++){
        sum = 0;
        for(j = 0;j<dim;j++){
            sum += mat[i][j];
        }
        array[i] = sum;
    }

    /*
    TEST WITH THESE LINES IN main()
    int dim = 5;
    int m[DIM][DIM]={
        {1,0,0,1,1},
        {0,1,0,1,1},
        {0,0,1,1,1},
        {0,0,1,1,1},
        {0,0,1,1,1}
    };

    int a[DIM];

    sum_row_in_array(m,a,dim);

    stampa_array(a,dim);
    */
}

/*
Data una stringa, contare di quante parole `e formata. Le parole sono
separate da uno o pi`u spazi consecutivi.
*/
int count_words(char str[]){
    int i = 0,count = 0,trigger = 0;
    while(str[i]){

        if(str[i] == ' '){
            trigger = 0;
        }else{
            if(!trigger){
                trigger = 1;
            }else{
                count--;
            }
        }

        if(trigger){
            count++;
        }
        i++;
    }
    return count;

    /*
    TEST WITH THESE LINES IN main()
    char str[] = "cc   a aa";
    printf("%d",count_words(str));
    */
}

/*
4.4 Eliminazione duplicati
Dato un array di interi di lunghezza nota,
eliminare gli elementi duplicati tenendo
solo la prima occorrenza di ciascuno di essi.
Non alterare l’ordine degli altri elementi.
Non utilizzare array ausiliari.
*/
void shift_left_by_one(int arr[],int pos,int dim){
    int i;
    for(i = pos; i < dim; i++){
        arr[i] = arr[i + 1];
    }
}

void elimina_duplicati(int arr[],int *dim_ind){
    int i,j;
    for(i = 0; i < *dim_ind; i++){
        for(j = i + 1; j < *dim_ind; j++){
            if(arr[i] == arr[j]){
                /*printf("%d ",*dim_ind);*/
                shift_left_by_one(arr,j,*dim_ind);
                *dim_ind = *dim_ind - 1;
                j--;
            }
        }
    }
    /*
    TEST WITH THESE LINES IN main()
    int dim = 14;
    int arr[] = {4,1,2,1,1,2,1,1,1,1,3,3,3,4};

    elimina_duplicati(arr,&dim);
    stampa_array(arr,dim);
    */
}




int main(){



   /* int campo1[MATRIX_DIM][MATRIX_DIM] = {
        { 8, 2, 1, 5, 4, 6, 3, 7, 9 },
        { 9, 6, 4, 8, 3, 7, 5, 2, 1 },
        { 5, 3, 7, 2, 1, 9, 6, 8, 4 },
        { 7, 1, 6, 4, 8, 2, 9, 5, 3 },
        { 3, 4, 9, 7, 5, 1, 8, 6, 2 },
        { 2, 8, 5, 6, 9, 3, 4, 1, 7 },
        { 1, 5, 8, 9, 7, 4, 2, 3, 6 },
        { 4, 7, 2, 3, 6, 5, 1, 9, 8 },
        { 6, 9, 3, 1, 2, 8, 7, 4, 5 }
    };

    int campo2[MATRIX_DIM][MATRIX_DIM]={
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };

    int campo3[MATRIX_DIM][MATRIX_DIM]={
        {1,0},
        {0,1},
        {0,0}
    };

    int campo4[MATRIX_DIM][MATRIX_DIM]={
        {1,0,0},
        {0,1,0}
    };


    printf("%d",sum_diagonal(campo1,9,9));*/



    return 0;

}
