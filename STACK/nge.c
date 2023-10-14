#include<stdio.h>
#include<stdbool.h>
#define MAX_1 100
int top=-1;
int MAX=MAX_1 ; 
int arr[MAX_1];
bool isempty(){
	return top==-1;
}
int peek(){
	return arr[top];
}
void push(int item)
{

	arr[++top]=item;
}
int pop(){
	if(!isempty())return arr[top--];
	else return -1;
}
void nxtgrt(int *nums,int n,int *nge)
{  
    int i;
    for(i=n-1;i>=0;i--)
	{
			while(!isempty() && peek()<=nums[i])
        		pop();
        	
			if(!isempty())
        		 nge[i]=peek();
        	 else
        	     nge[i]=-1;
        	     
        	push(nums[i]);
	}	
	
}

int main()
{   
  int j;
	int arr1[]={4,25,25,1};
	int n=3;
	int arr2[n];
	nxtgrt(arr1,n,arr2);
	printf("[");
	for(j=0;j<n;j++)
	{
	  printf("%d ",arr2[j]);	
	}
	printf("]");
    return 0;
}

