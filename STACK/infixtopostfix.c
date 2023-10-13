#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int top = -1, size, len;
char Exp[50];
char stack[50];
char post_exp[50];
int is_full()
{
    if (top == size - 1)
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
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char push(char data)
{
    stack[++top] = data;
}
char pop()
{
    return stack[top--];
}
char peek()
{
    return stack[top];
}
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return -1;
}
void infixtopostfix()
{
    int i,j = 0;
    for ( i = 0; i < len; i++)
    {
        if (isalpha(Exp[i]) || isdigit(Exp[i]))
        {
            post_exp[j]=Exp[i];
            j++;
        }
        else if (Exp[i] == '(' || Exp[i] == '^')
        {
            push(Exp[i]);
        }
        else if (Exp[i] == '+' || Exp[i] == '-' || Exp[i] == '*' || Exp[i] == '/')
        {
            if (!is_empty())
            {
                if (precedence(Exp[i]) > precedence(peek()))
                {
                    push(Exp[i]);
                }
                else if (precedence(Exp[i]) <= precedence(peek()))
                {
                    while (!is_empty() && precedence(Exp[i]) <= precedence(peek()))
                    {
                        post_exp[j] = pop();
                        j++;
                    }
                    if (is_empty()||precedence(Exp[i]) > precedence(peek()) )
                    {
                        push(Exp[i]);
                    }
                }
            }
            else
                push(Exp[i]);
        }
        else if (Exp[i] == ')')
        {
            while (peek() != '(')
            {
                post_exp[j] = pop();
                j++;
            }
            pop();
        }
    }
    while (!is_empty())
    {
        post_exp[j] = pop();
        j++;
    }
}
void main()
{
    printf("Enter the Expression: ");
    scanf("%s", Exp);
    len = strlen(Exp);
    size = len;
    infixtopostfix();
    printf("%s",post_exp);
}
