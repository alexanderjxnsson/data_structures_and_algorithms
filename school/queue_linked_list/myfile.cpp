#include <iostream>

class Node{
    public:
        int value;
        class Node *next;
}*front = NULL, *rear = NULL;

void enQueue(int x);
int deQueue();
void display();

int main() {
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    display();
    std::cout<<"Removing first value!\n";
    deQueue();
    display();
    std::cout<<"Emptying!\n";
    for (int i = 0; i < 5; i++)
    {
        deQueue();
    }
    //display();    
    return 0;
}

void enQueue(int x){
    Node *temp = new Node;
    if (temp == NULL)
        std::cout<<"Queue is Full!\n";
    else{
        temp->value = x;
        temp->next = NULL;
        if(front == NULL)
            front = rear = temp;
        else{
            rear->next = temp;
            rear = temp;
        }
    }
}

int deQueue(){
    int x = -1;
    class Node *temp;
    if(front == NULL){
        std::cout<<"Queue is empty!\n";
    }
    else{
        x = front->value;
        temp = front;
        front = front->next;
        free(temp);
    }
    return x;
}

void display(){
    class Node *pointer = front;
    std::cout<<"Display: ";
    while (pointer)
    {
        std::cout<<pointer->value<<" ";
        pointer = pointer->next;
    }
    std::cout<<std::endl;
}