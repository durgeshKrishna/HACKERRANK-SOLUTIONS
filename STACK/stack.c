#include <stdio.h>
#include <stdlib.h>
int top=-1,size;
int is_full()
{
    if (top==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_empty()
{
    if (top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int push(int s[],int data)
{
    if (is_full())
    {
        printf("Stack is full");
    }
    else
    {
        s[++top]=data;
    }
}
int pop(int s[])
{
    
    if (is_empty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("\n popped element is%d\n",s[top--]);    
    }
}
int peek(int s[])
{
    if (is_empty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d\n",s[top]);    
    }
}
void main()
{
    int choice,n;
    printf("Enter the size of stack: ");
    scanf("%d",&size);
    int *stack=(int*)malloc(sizeof(int));
    while(1)
    {
        printf("\nEnter you choice: \n1-push()\n2-pop()\n3-peek()\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the data: ");
            scanf("%d",&n);
            push(stack,n);
            break;
            case 2:
            pop(stack);
            break;
            case 3:
            peek(stack);
            break;
            default:
            exit(0);
        }

    }
}
//#include<stdio.h>
//#include<stdlib.h>
//#include<ctype.h>
//int top=-1,data,*s,n;
//int isfull(){
//	if(top==n-1)
//	 return 1;
//	 else
//	 return 0;
//}
//int isempty()
//{
//	if(top==-1)
//	  return 1;
//	else
//	  return 0;
//}
//void push(int data){
//	top++;
//	s[top]=data;
//}
//int pop(){
//	data=s[top];
//	top--;
//	return data;
//}
//int peek(){
//	return s[top];
//}
//int main(){
//	int ch;char confirm;
//	s=(int *)malloc(n*sizeof(int));
//	printf("\n Enter the size of the stack ");
//	scanf("%d",&n);
//	do
//	{
//			printf("\n 1.push \n 2.pop \n 3. peek \n enter your choice");
//			printf("enter the operation");
//			scanf("%d",&ch);
//			switch(ch)
//			{
//			
//			case 1:
//				if(isfull())
//				printf("stack overflow");
//				else
//				printf("Enter the data to be pushed in");
//				scanf("%d",&data);
//				push(data);
//				break;
//			case 2:
//				if(isempty())
//				{
//					printf("stack underflow");
//					
//				}
//				else
//				{
//					printf("\n the popped element is %d",pop());
//				}
//				break;
//		case 3:
//			if(isempty())
//			{
//				printf("stack underflow");
//			}
//			else
//			{
//				printf("The peeked element is %d",peek());
//				
//			}
//			break;
//		default:
//			printf("invalid option");
//	      }
//
//
//    printf("\n Do you want to continue!!");
//    scanf("%s",&confirm);
//	}while(toupper(confirm)=='Y');
//	
//	
//	
//}
