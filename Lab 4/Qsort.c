#include <stdio.h>
#include <stdlib.h>



int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main () {
   int n;
   scanf("%d",&n);
    int values[n];
   printf("Before sorting the list is: \n");

   for( int i = 0 ; i < n; i++ ) {
      scanf("%d", &values[i]);
   }
   for( int i = 0 ; i < n; i++ ) {
      printf("%d ", values[i]);
   }

   qsort(values, 5, sizeof(int), cmpfunc);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {   
      printf("%d ", values[n]);
   }
  
   return(0);
}