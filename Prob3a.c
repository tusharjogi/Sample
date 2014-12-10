#include<stdio.h>
#define n 5

int main(void){

 double l[n][n],a_inv[n][n],x[n][n];
 int    i,j,k;
 double multiplier, pivot,c;
 double I[n][n]= {
                   1.0, 0.0, 0.0, 0.0, 0.0,  
                   0.0, 1.0, 0.0, 0.0, 0.0,
                   0.0, 0.0, 1.0, 0.0, 0.0,
                   0.0, 0.0, 0.0, 1.0, 0.0,
                   0.0, 0.0, 0.0, 0.0, 1.0
                 };

 double a[n][n]= {  
                   1.0, 3.0,-9.0, 6.0, 4.0,
                   2.0,-1.0, 6.0, 7.0, 1.0,
                   3.0, 2.0,-3.0, 15.0,5.0,
                   8.0,-1.0, 1.0, 4.0, 2.0,
                   11.0,1.0,-2.0, 18.0,7.0
                 };
 
 /*Guass Elimination*/
 for (k=0; k<(n-1); k++){
   pivot = a[k][k];

    for (i=k+1; i<n; i++){

        multiplier = a[i][k]/pivot;
        l[i][k]    = multiplier;

        for(j=k; j<n; j++){ 

           a[i][j] = a[i][j] - multiplier*a[k][j];
       
        }
    }
 }
 printf("The U matrix is:\n");
 for(i=0;i<n;i++){
    for(j=0;j<n;j++){
       printf("%lf\t",a[i][j]);
    }
    printf("\n");
 } 

 for (i=0;i<n;i++)
    l[i][i] = 1.0;

 for(k=0;k<n;k++){
   for (i=0;i<n;i++){
          c = I[i][k];
    for (j=0;j<i;j++)
      c = c - l[i][j]*x[j][k];
    x[i][k] = c; 

   }
 }

 for (k=0; k<n; k++){
   for (i=(n-1); i>=0; i--){
       c = x[i][k];
       for (j=(n-1); j>0; j--)
           c = c - a[i][j]*a_inv[j][k];
       a_inv[i][k] = c/a[i][i];
   } 
 }

 printf("The inverse of matrix is:\n");
 for(i=0;i<n;i++){
   for(j=0;j<n;j++){
    printf("%lf\t",a_inv[i][j]); 
   }
  printf("\n");
 }

 return 0;
}
