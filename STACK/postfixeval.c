#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int top=-1,size,len;
char postfix_exp[50];
int stack[50];
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
int push(int data)
{
    stack[++top]=data;
}
int pop()
{
    if(is_empty())
    {
        printf("stack is empty");
        exit(0);
    }
    else
        return stack[top--];    
}
int peek()
{
        return stack[top];    
}
void postfix_eval()
{
    int num1,num2;
    for (int i=0;i<len;i++)
    {
        if(isdigit(postfix_exp[i]))
        {
            push(postfix_exp[i]-'0');
        }
        else if (postfix_exp[i]=='+'||postfix_exp[i]=='-'||postfix_exp[i]=='*'||postfix_exp[i]=='/'||postfix_exp[i]=='^')
        {
            num2=pop();
            num1=pop();
            switch (postfix_exp[i])
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
            case '^':
            push(num1^num2);
            break;
            }
        }

    }
}
void main()
{
    //int *stack=(int*)malloc(sizeof(int));
    printf("Enter the postfix expression: ");
    scanf("%s",postfix_exp);
    len=strlen(postfix_exp);
    size=len;
    postfix_eval();
    printf("%d",peek());
}
