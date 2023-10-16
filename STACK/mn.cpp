//minimum
#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define size 5

int top1=-1;
int top2=-1;
int m1[size];
int m2[size];
int isempty1()
{
 if(top1==-1)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}



int isfull1()
{
 if(top1==size-1)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

int push1(int a)
{
 if(isfull1())
 {
  printf("stack is full");
 }
 else
 {
  top1++;
 m1[top1]=a;
 }
}


int pop1()
{
 if(isempty1())
 {
  printf(" \n n-stack is empty");
 }
 else
 {
  top1--;
  return m1[top1+1];
 }
}


int isempty2()
{
 if(top2==-1)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}



int isfull2()
{
 if(top2==size-1)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

int push2(int a)
{
 if(isfull2())
 {
  printf("stack is full");
 }
 else
 {
  top2++;
  m2[top2]=a;
 }
}


int pop2()
{
 if(isempty2())
 {
  printf("\n m-stack is empty");
  //return;
 }
 else
 {
  top2--;
  return m2[top2+1];
 }
}
int min()
{
 return m2[top2];
}
int peek()
{
 return m1[top1];
}

int main()
{
 int i;
 int choice,data,temp;
 do{

 printf("\n ENTER CHOICE :");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
   printf("\n ELEMENT TO BE PUSHED :");
   scanf("%d",&data);
   push1(data);
   if(isempty2()||m1[top1]<m2[top2])
   {
    push2(data);
   }
   break;
  case 2:
   if(isempty1()&&isempty2())
    printf("\n stack is empty");
   else{
   if(m1[top1]==m2[top2])
   {
          pop2();
   }  
   temp=m1[top1];
   pop1();
   printf("\n POPPED ELEMENT IS %d",temp);}
   break;
  case 3:
         printf("\nminimum value %d",min());
         break;
  default:
           printf("invalid");
    
 }
 
 }while(choice!=4);
 
 
return 0; 
}