#include<stdio.h>
#include<conio.h>
int top=-1,top2=-1;
void push1(int s1[],int size,int ele)
{
	if(top==size-1)
	printf("\n stack overflow");
	else
	{
		top++;
		s1[top]=ele;
		printf("\n%d",top);
	}
}
void push2(int s2[],int ele,int size)
{
	if(top2==size-1)
	printf("\n stack2 overflow");
	if(top2==-1)
	{
		top2++;
		s2[top2]=ele;
	}
	else
	{
		if(ele<s2[top])
		{
			top2++;
			printf("\n %d tope",top2);
			s2[top2]=ele;
}
	}
}
int pop2(int s2[])
{
	int a2;
	if(top2==-1)
	printf("\n stack2 underflow");
	else
	{
		a2=s2[top2];
		top2--;
	}
	return a2;
}
int pop(int s1[],int s2[])
{
	int a1;
	if(top==-1)
	printf("\n stack underflow");
	else
	{
		a1=s1[top];
		top--;
		pop2(s2);
	}
	return a1;
}
int peek2(int s2[])
{
	if(top2==-1)
	printf("\n stack2 underflow");
	return s2[top2];
}
int peek1(int s1[])
{
	if(top==-1)
	printf("\n stack underflow");
	printf("\n %d",top);
	return s1[top];
}
int main()
{
	int size,ele,c,del,see1,see2;
	printf("\n enter the size of the stack:");
	scanf("\n%d",&size);
	int s1[size],s2[size];
	printf("\n 1->push\n 2->pop\n3->peek\n4->peek2");
	while(1)
	{
		printf("\n enter the choice :");
	scanf("\n%d",&c);
		switch(c)
		{
			case 1:
				printf("\n enter the element to push in the stack:");
				scanf("\n%d",&ele);
				push1(s1,size,ele);
				push2(s2,ele,size);
				break;
			case 2:
				del=pop(s1,s2);
				printf("\n deleted element from the stack is :%d",del);
				break;
			case 3:
				see1=peek1(s1);
				printf("\n latest pushing element is :%d",see1);
				break;
			case 4:
				see2=peek2(s2);
				printf("\n the minimum element in the stack:%d",see2);
				break;
			default:
				printf("\n in");
		}
	}
}
