#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) 
{
  //Write your code here.
  int i,j,m1=0,m2=0,m3=0;
  for(i=1;i<=n;i++)
  {
      for(j=i+1;j<=n;j++)
      {
          int AND=i&j;
          int OR=i|j;
          int XOR=i^j;
          
          if ( m1<AND&& AND<k)
          {m1=AND;}
          if ( m2<OR && OR<k)
          {m2=OR;}
          if ( m3<XOR && XOR<k)
          {m3=XOR;}
          
          
      }
      
  }
  printf("%d\n",m1);
  printf("%d\n",m2);
  printf("%d\n",m3);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}

