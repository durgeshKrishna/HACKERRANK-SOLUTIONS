#include<stdio.h>
#include<malloc.h>
#define null 0
struct node
{
    int data,post,r;
    struct node *next,*rad;
};
typedef struct node *list;
void display(list );                    //Function declaration
list head();
void create(list );
void insert(list ,int );
int findmax(list );
void sort(list ,int );
void innode(list ,list ,int );
void delenode(list );
void display(list );

int main();

list head()                              //Creating a head node
{
    list temp;
    temp=malloc(sizeof(struct node));
    temp->data=-1;
    temp->post=-1;
    temp->r=0;
    temp->next=null;
    temp->rad=null;
    return temp;
}
void create(list l)                        //construct a list with 10 nodes
{
    int i;
    list p=l;
    for(i=0;i<10;i++)
    {
        list temp;
        temp=malloc(sizeof(struct node));
        temp->next=null;
        temp->rad=null;
        temp->data=0;
        temp->r=0;
        temp->post=i;
        p->next=temp;
        p=temp;
    }
}
void insert(list p,int x)                   //Insert the elements in the list (pass 1)
{
    int y;
    y=x%10;
    for(p=p->next;p->post!=y;p=p->next);
        while(p->rad!=null)
            p=p->rad;
        list temp;
        temp=malloc(sizeof(struct node));
        temp->data=x;
        temp->r=0;
        temp->post=p->post;
        temp->rad=null;
        temp->next=null;
        p->rad=temp;
}
int findmax(list p)                       //Find the  no of digits in the max value
{
    int i=0,j;
    list a=p,b;
    for(a=a->next;a!=null;a=a->next)
    {
        for(b=a;b!=null;b=b->rad)
        {
           if(i<b->data)
                i=b->data;
        }
    }
    j=0;
    while(i>0)
    {
        j++;
        i/=10;
    }
    return j;
}
void sort(list p,int m)                //Radix sort function
{
    list temp,t1,t2;
    int y=10,x,i,z;
    for(i=0;i<m-1;i++,y=y*10)
    {
        t1=p;
        for(t1=t1->next;t1!=null;t1=t1->next)
        {
            t2=t1;
            temp=t1;
            for(t2=t2->rad;t2!=null;t2=t2->rad)
            {
                x=t2->data;
                z=x/y;
                z=z%10;
                if(t2->r==0)
                {
                    delenode(temp);
                    innode(p,t2,z);
                    t2=temp;
                }
                else
                temp=temp->rad;
            }
        }
        printf("\n\nPass %d\n\n",i+2);
        display(p);
        reset(p);
    }
}
void reset(list x)
{
    list temp;
    for(x=x->next;x!=null;x=x->next)
        for(temp=x->rad;temp!=null;temp=temp->rad)
           temp->r=0;
}
void innode(list p,list t2,int y)            //Move the node belong to its position
{
    list a=p,temp=t2;
    for(a=a->next;a->post!=y;a=a->next);
        while(a->rad!=null)
            a=a->rad;
        temp->post=y;
        temp->r=1;
        temp->rad=null;
        temp->next=null;
        a->rad=temp;
}
void delenode(list temp)                     //Delete the node before we moving to its position
{
    list p=temp;
    p->rad=p->rad->rad;
}
void display(list p)                         //Display the list elements
{
    list temp,t1=p;
    for(t1=t1->next;t1!=null;t1=t1->next)
    {
        for(temp=t1->rad;temp!=null;temp=temp->rad)
            printf("\t%d",temp->data);
    }
}
int main()                                    //Actual main function
{
    int x,n,i,m;
    list l;
    l=head();
    create(l);
    printf("Enter the number  of element:");
    scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        insert(l,x);
    }
    printf("\nPass 1:\n");
    display(l);
    m=findmax(l);
    sort(l,m);
    printf("\n\nAfter radix sort\n\n");
    display(l);
    return 0;
}
