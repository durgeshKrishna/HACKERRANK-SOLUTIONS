#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n1,n2;
    float num1,num2;
    scanf("%d %d",&n1,&n2);
    scanf("%f%f",&num1,&num2);
    printf("%d %d\n",n1+n2,n1-n2);
    printf("%.1f %.1f",num1+num2,num1-num2);
    
    return 0;
}
