#include <iostream>

class ArrayQueue{
    public:
        int size = 0;
        int front = 0;
        int rear = 0;
        int *Q;
    void create(int x);
    void enQueue(int x);
    int deQueue();
    void display();
};



int main() {
    ArrayQueue arrQ;
    arrQ.create(5);

    arrQ.enQueue(1);
    arrQ.enQueue(2);
    arrQ.enQueue(3);
    arrQ.enQueue(4);
    arrQ.enQueue(5);

    arrQ.display();
    std::cout<<"Trying to add 6 to the array!\n";
    arrQ.enQueue(6);
    std::cout<<"After deleting "<<arrQ.deQueue()<<std::endl;
    arrQ.display();
}

void ArrayQueue::create(int sz){
    size = sz;
    front = rear = -1;
}

void ArrayQueue::enQueue(int x){
    if(rear == size - 1){
        std::cout<<"Queue is full!\n";
    }
    else{
        rear++;
        Q[rear] = x;
    }
}

int ArrayQueue::deQueue(){
    int x = -1;
    if(front == rear)
        std::cout<<"Queue is empty!\n";
    else{
        front++;
        x = Q[front];
    }
    return x;
}

void ArrayQueue::display(){
    int i;
    for (i = front + 1; i <= rear; i++)
    {
        std::cout<<Q[i]<<" ";
    }
    std::cout<<std::endl;
}