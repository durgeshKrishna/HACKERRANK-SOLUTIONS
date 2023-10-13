#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;
int stack[100];
char Exp[100];
int size;
int a;
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
int pop()
{
	if (is_empty())
	{
		printf("Pop() cannot be perfomed.\nStack is empty");
		exit(0);
	}
	else
	{
		a=stack[top];
		top--;
		return a;
	}
}
void push(int data)
{
	if (is_full())
	{
		printf("Stack is full\n");
		printf("%c cannot be inserted",data);
		exit(0);
	}
	else
	{
		top++;
		stack[top]=data;
	}
}
void rpn()
{
    char op;
    int num1,i,num2,n;
    for ( i=0;i<size;i++)
    {
        if (('0'<=Exp[i]) && (Exp[i]<='9')&&('0'<=Exp[i-1]) && (Exp[i-1]<='9') )
        {
            n=pop();
            push((n*10)+(Exp[i]-48));
        }
        else if (('0'<=Exp[i]) && (Exp[i]<='9'))
        {
            push(Exp[i]-48);
        }
        else if (Exp[i] == '+' || Exp[i] == '-' || Exp[i] == '*' || Exp[i] == '/')
        {
            op=Exp[i];
            num2=pop();
            num1=pop();
            switch(op)
            {
                case '+':
                push(num1+num2);
                break;
                case '-':
                push(num1-num2);
                break;
                case '*':
                push(num1*num2);
                break;
                case '/':
                push(num1/num2);
                break;
                default:
                printf("invalid operator");
            }
            
        }
        else if ((int)Exp[i]==32)
        {
            continue;
        }
        
    }
}
void main()
{   
    printf("Input: ");
    scanf("%[^\n]s",Exp);
    size=strlen(Exp);
    rpn();
    printf("Output: %d\n",stack[0]); 
}
