#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int size,i;
char Exp[100];
char stack[100];
int position[100];
int top = -1;
bool condition = true;
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
int pop()
{
    int n=position[top];
    stack[top];
    top--;
    return n;
}
void push(char data, int pos)
{
    top++;
    stack[top] = data;
    position[top] = pos;
}
int peek() 
    {return stack[top];}
void validbraces()
{
    for (i = 0; i < size; i++)
    {
        switch (Exp[i])
        {
        case '(':
            push(Exp[i], i);
            break;
        case '[':
            push(Exp[i], i);
            break;
        case '{':
            push(Exp[i], i);
            break;
        }
        if (!is_empty())
        {
            switch (Exp[i])
            {
            case ')':
                if (peek() == '(')
                {
                    pop();
                }
                else
                {
                    printf("%d ", pop());
                    condition = false;
                }
                break;
            case ']':
                if (peek() == '[')
                {
                    pop();
                }
                else
                {
                    printf("%d ", pop());
                    condition = false;
                }
                break;
            case '}':
                if (peek() == '{')
                {
                    pop();
                }
                else
                {
                    printf("%d ", pop());
                    condition = false;
                }
                break;
            }
        }
        else
        {
            printf("%d ", i);
            condition = false;
        }
    }
    while(!is_empty())
    {
        condition=false;
        printf("%d ",pop());
    }
    if (condition)
        printf("True");
    else
        printf("False");
}
void main()
{
    scanf("%s",Exp);
    size = strlen(Exp);
    validbraces();

}
