#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int i,j,n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
      int size=2*n-1;
      int front=0;
      int last=size-1;
      int arr[size][size];
      while(n!=0)
      {
          
          for(i=front;i<=last;i++)
          {
              
              for(j=front;j<=last;j++)
              {
                  if(i==front || i==last || j==last || j==front)
                  {
                      
                      arr[i][j]=n;
                      
                  }
                  
              }
              
              
          }
          front++;
              last--;
              n--;
          
          
          
      }
      for(i=0;i<size;i++)
          {
              for(j=0;j<size;j++)
              {
                  
                  printf("%d ",arr[i][j]);
              }
        printf("\n");      
              
          }
    return 0;
}
