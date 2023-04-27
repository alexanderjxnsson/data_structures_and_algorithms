#include <iostream>
class Node{
    public:
    int data;
    class Node *next;
}*first=NULL;
enum CHOICES{DISPLAY = 1, LENGTH, INSERT, DELETE, EXIT};
bool bMenu = true;
int size = 0, choice = 0, newValue = 0, index = 0, i = 0;

//display, length, insert, delete
void create(int A[],int n);
void Display(class Node *p);
void RDisplay(class Node *p);
void insert(class Node *p,int index,int x);
int count(class Node *p);
int rCount(class Node *p);
int Delete(class Node *p,int index);

int main() {
    std::cout<<"Welcome to Linked lists!\n";
    std::cout<<"Enter the size of the list: ";
    std::cin>>size;
    int A[size];
    std::cout<<"Enter your elements: \n";
    for (int i = 0; i < size; i++)
    {
        std::cin>>A[i];
    }
    create(A, size);
    system("pause");
    system("cls");
    while (bMenu == true)
    {
        std::cout<<"What do you want to do?\n1. Display\n2. Print length of linked list\n3. Insert new value\n4. Delete node\n5. Exit\n";
        std::cin>>choice;
        switch (choice)
        {
        case DISPLAY:
            Display(first);
            system("pause");
            system("cls");
            break;
        case LENGTH:
            std::cout<<"The length of the list is: "<<count(first)<<std::endl;
            system("pause");
            system("cls");
            break;
        case INSERT:
            std::cout<<"Enter what element you want to insert: ";
            std::cin>>newValue;
            Display(first);
            std::cout<<"At what index?\n";
            std::cin>>index;
            insert(first, index, newValue);
            std::cout<<"The new list after new element:\n";
            Display(first);
            system("pause");
            system("cls");
            break;
        case DELETE:
            std::cout<<"Enter what index you want to delete: \n";
            Display(first);
            std::cin>>index;
            Delete(first, index);
            std::cout<<"The new list after new element:\n";
            Display(first);
            system("pause");
            system("cls");
            system("pause");
            system("cls");
            break;
        case EXIT:
            std::cout<<"Exiting the program\n";
            bMenu = false;
            break;
        default:
            std::cout<<"Enter a valid number, please!\n";
            break;
        }
    }
    




}

void create(int A[],int n)
{
    int i;
    class Node *t,*last;
    first=(class Node *)malloc(sizeof(class Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(class Node*)malloc(sizeof(class Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(class Node *p)
{
    i = 0;
    while(p!=NULL)
    {
        std::cout<<"Index "<<i<<": "<<p->data<<std::endl;
        i++;
        p=p->next;
    }
    std::cout<<std::endl;
}

void RDisplay(class Node *p)
{
    if(p!=NULL)
    {
        RDisplay(p->next);
        std::cout<<p->data<<std::endl;
    }
}

void insert(class Node *p,int index,int x)
{
    class Node *temp;
    int i;
    if(index < 0 || index > count(p))
        return;
    temp=(class Node *)malloc(sizeof(class Node));
    temp->data=x;
    if(index == 0)
    {
        temp->next=first;
        first=temp;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        temp->next=p->next;
        p->next=temp;
    }
}

int count(class Node *p){
    int counter = 0;
    while (p)
    {
        counter++;
        p=p->next;
    }
    return counter;
}

int rCount(class Node *p){
    if (p!=NULL)
    {
        return rCount(p->next)+1;
    }
    else{
        return 0;
    }
}

int Delete(class Node *p,int index)
{
    class Node *q=NULL;
    int x=-1,i;
    if(index < 1 || index > count(p))
        return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}