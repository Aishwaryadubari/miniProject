Int#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct node
{
   char item[50];
   int price;
   struct node*link;
};
struct node*first=NULL;

struct list
{

    char ele[50];
    int cost;
    int quantity;
    struct list*link;
};
struct list*last=NULL;

FILE *f1,*f2,*f3;
char item[50];char buff1[1024];int buff2;
int price;



int mainmenu()
{char item[50];
int price;
    f1=fopen("items.c","r");
    f2=fopen("price.c","r");
    f3=fopen("mini.c","w");
    if(f1==NULL||f2==NULL||f3==NULL)
    {
        printf("\n error:cannot open file");exit(1);
    }
    while(!feof(f1)&&!feof(f2))
{
    fscanf(f1,"\n%s\n",item);
    fscanf(f2,"\n%d\n",&price);
    fprintf(f3,"\n%s\n",item);
    fprintf(f3,"\n%d\n",price);
}fclose(f1);fclose(f2);fclose(f3);
f3=fopen("mini.c","r");
while(!feof(f3))
{
   fscanf(f3,"\n%s\n",item);
    fscanf(f3,"\n%d\n",&price);
    printf("\n%s\t\t%d\n",item,price);
}fclose(f3);

return 0;
}

void create()
{ struct node*p,*t=NULL;
f1=fopen("items.c","r");
    f2=fopen("price.c","r");
    while((fscanf(f1,"%s",buff1)==1)&&(fscanf(f2,"%d",&buff2)==1))
    {
    p=(struct node*)malloc(sizeof(struct node));
    p->link=NULL;
    strcpy(p->item,buff1);
    p->price=buff2;
    p->link=first;
    first=p;}

fclose(f1);fclose(f2);
}


void display()
{struct node*t;

    if(first==NULL)
    printf("\nno node exist");
else
 {
    t=first;
    while(t!=NULL)
{
    printf("\n%s\t%d",t->item,t->price);
    t=t->link;
}
}}


void insert()
{
    struct node*p,*t=first;char s1[50];int s2;
    f1=fopen("items.c","a");
    f2=fopen("price.c","a");

p=(struct node*)malloc(sizeof(struct node));
printf("\nenter item ");
fflush(f1);
scanf("%s",p->item);
strcpy(s1,p->item);
printf("enter price ");
fflush(f2);
scanf("%d",&p->price);
s2=p->price;
fprintf(f1,"%s\n",s1);
fprintf(f2,"%d\n",s2);;
p->link=NULL;
while(t->link!=NULL)
{
    t=t->link;
}t->link=p;
fclose(f1);fclose(f2);
mainmenu();
printf("\nitem inserted");
}


void purchase()
{ struct node*t;
     int i,flag=0,n,q=0;int price;int yes;
     char item[50],name[50];int c;
    do
    {
    printf("\nwhat you want to buy  ");
    scanf("%s",item);

     flag=0;
    t=first;
    while(t!=NULL)
    {
        if(strcmp(item,t->item)==0)
        {flag=1;
            printf("\n%s\t%d",t->item,t->price);
            printf("\nhow many plates of %s you want to buy ",t->item);
            scanf("%d",&n);
            price=t->price;
            add(item,price,n);
            q=q+n*t->price;
            }

            t=t->link;
    }
    if(flag==0)

{  printf("\nnot available");
}

printf("\n press 1  want to buy any more \t 0 for exit");
    scanf("%d",&i);


}while(i);
     printf("\nenter your name ");
scanf("%s",name);



    printf("\ndo u want to buy press 1 or to cancel order press 0");
    scanf("%d",&yes);
    if(yes==1)
      {printf("\npay the total bill ");
      if(q>500)
{
c=q-((20/100)*q);
showlist();
printf("\n\tTOTAL BILL= %d",c);
}
else
   {

    printf("\n");
    showlist();
    printf("\n%s your TOTAL BILL= %d",name,q);}

      printf("\nbill paid suceesfully ");}
    else
        {last=NULL;}

}


void add(item,price,n)
{
    struct list*p;
    p=(struct list*)malloc(sizeof(struct list));
    strcpy(p->ele,item);
    p->cost=price;
    p->quantity=n;
    if(last==NULL)
    {
        last=p;
        last->link=last;

    }
    else
        {p->link=last->link;
    last->link=p;}
}


void showlist()
{struct list*t;
if(last==NULL)
{
    printf("no node exist");
    }
    else
    {
        t=last;
        while(t->link!=last)
        {
        printf("\n%s\t%d\t%d\t",t->ele,t->cost,t->quantity);
        t=t->link;
        }printf("\n%s\t%d\t%d\t",t->ele,t->cost,t->quantity);
        }
    }


void dlete()
{struct node *t=first;int flag=0;char s1[50];int s2;
struct node *prev=t;char ele[50];
printf("\nenter item ");
scanf("%s",ele);
    if(first==NULL)
        {printf("\nno node exist");}
    else if(strcmp(t->item,ele)==0&&t->link!=NULL)
        {free(t);
    first=t->link;
    flag=1;}
    else if(strcmp(t->item,ele)==0&&t->link==NULL)
    {
        flag=1;
        free(t);
        first=NULL;
    }
    else
        {while(t!=NULL)
    {
        if(strcmp(t->item,ele)==0)
            {flag=1;
        prev->link=t->link;
        free(t);}
        else
            {prev=t;
            t=t->link;}
        }}
    if(flag==0)
    {
        printf("\ndata not found");

    }

     f1=fopen("items.c","w+");
    f2=fopen("price.c","w+");
    t=first;
    while(t!=NULL)
{   strcpy(s1,t->item);
     s2=t->price;
    fprintf(f1,"\n%s\n",s1);
    fprintf(f2,"\n%d\n",s2);;

    t=t->link;}
    fclose(f1);
    fclose(f2);
    mainmenu();
printf("\nitem deleted");

}

void admin()
    {FILE *f4;char c[20],d[20],ch;int i,j,op;
    f4=fopen("admin.c","r");
        fscanf(f4,"%s",d);
    printf("enter password ");
    for(i=0;i<5;i++)
{
    ch=getch();
    c[i]=ch;
    ch='*';
    printf("%c",ch);
}c[i]='\0';
if(strcmp(c,d)==0)
{
    do{
printf("\n1:insert\n2:delete ");
scanf("%d",&op);
switch(op)
{
    case 1:insert();break;
    case 2:dlete();break;

}printf("\ncontinue as admin press 1\t 0 exit ");
scanf("%d",&j);}while(j);
}
else
    printf("\nwrong password");

}
void user()
{FILE *f5;char c[20],ch,d[20];int i,j,op;
f5=fopen("user.c","r");
fscanf(f5,"%s",d);

printf("enter password ");
for(i=0;i<4;i++)
{
    ch=getch();
    c[i]=ch;
    ch='*';
    printf("%c",ch);

}c[i]='\0';
if(strcmp(c,d)==0)
{do{
printf("\n1:purchase\n2:display ");
scanf("%d",&op);
switch(op)
{
    case 1:purchase();break;
    case 2:display();break;

}printf("\ncontinue as user press 1\t 0 exit ");
scanf("%d",&j);}while(j);

}
else
   {

    printf("wrong password");}
fclose(f5);
}

int main()
{ int ch,j,yes;
    printf("\n");
    printf("********************************************************************************************************");
    printf("\n\t\t\t\tWELCOME TO RESTURANT\t\t\t");
    printf("\n*******************************************************************************************************");
    mainmenu();
    create();
    do
    {

      printf("\npress \t 1:admin \t 2:user  ");
        scanf("%d",&ch);

    switch(ch)
    {case 1:admin();break;

    case 2:user();break;

    default:printf("invalid");}
    printf("\n1 to continue \t 0 to exit  ");
    scanf("%d",&j);}
    while(j);
    printf("************************************************************************************************************");
    printf("\n\t\t\t\tTHANKS FOR COMING\t\t\t");
    printf("\n**********************************************************************************************************");


return 0;

}
