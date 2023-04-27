#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <stdlib.h>
class Node{
    public:
        char data;
        class Node *next;
}*top = NULL;

void display(); //klar
void push(char x); //klar
char pop(); //klar
int isBalanced(char *value); //klar
int isOperand(char x);
int presidence(char x);
char * toPostfix(char *infix); //ish klar, jämför med facit
int evaluation(char *postfix); //klar

int main() {
    char *value = "((a+b) * c+d)))";
    std::cout<<isBalanced(value)<<std::endl;
    char *value1 = "((a+b) * (c+d))";
    std::cout<<isBalanced(value1)<<std::endl;
    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix = toPostfix(infix);
    std::cout<<postfix<<std::endl;
    char *postfix1 = "234*+82/-";
    std::cout<<"The result is: "<<evaluation(postfix1)<<std::endl;
    return 0;
}

int isBalanced(char *value){
    for (int i = 0; value[i] != '\0'; i++)
    {
        if(value[i] == '(')
            push(value[i]);
        else if(value[i] == ')'){
            if(top == NULL)
                return 0;
            pop();
        }
    }
    if(top == NULL)
        return 1;
    else
        return 0;
}

void push(char x){
    Node *temp = new Node;
    if(temp == NULL)
        std::cout<<"Stack is full!\n";
    else{
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

char pop(){
    Node *temp = new Node;
    char x = -1;
    if (top == NULL)
        std::cout<<"Stack is empty!\n";
    else{
        temp = top;
        top = top->next;
        x = temp->data;
        free(temp);
    }
    return x;
}

void display(){
    Node *pointer = new Node;
    pointer = top;
    while (pointer != NULL)
    {
        std::cout<<pointer->data<<" ";
        pointer = pointer->next;
    }
    std::cout<<std::endl;
}

char * toPostfix(char * infix){
    int i=0,j=0;
    char *postfix = new char;
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else
        {
            if(presidence(infix[i])>presidence(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL)
        postfix[j++]=pop();
        postfix[j]='\0';
    return postfix;
}


int evaluation(char *postfix){
    int x1 = 0, x2 = 0, r = 0;

    for (int i = 0; i < postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
            push(postfix[i] - '0');
        else{
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

int isOperand(char x){
    if (x == '+' || x == '/' || x == '-' || x == '*')
    {
        return 0;
    }
    else{
        return 1;
    }
}

int presidence(char x){
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else
        return 0;
}