#include <iostream>

class CircularArray{
    public:
        int size;
        int front;
        int rear;
        int *Q;
};

void create(class CircularArray *q, int size);
void enQueue(class CircularArray *q, int x);
int deQueue(class CircularArray *q);
void display(class CircularArray q);

int main(){
    CircularArray cArr;
    create(&cArr, 5);
    enQueue(&cArr, 1);
    enQueue(&cArr, 2);
    enQueue(&cArr, 3);
    enQueue(&cArr, 4);
    enQueue(&cArr, 5);
    display(cArr);
    std::cout<<"Erasing: "<<deQueue(&cArr)<<std::endl;
    display(cArr);
    return 0;
}

void create(class CircularArray *q, int sz){
    q->size = sz;
    q->front = q->rear = -1;
}
void enQueue(class CircularArray *q, int x){
    if((q->rear+1)%q->size == q->front)
        std::cout<<"Queue is full!\n";
    else{
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}
int deQueue(class CircularArray *q){
    int x = -1;
    if(q->front == q->rear)
        std::cout<<"Queue is empty!\n";
    else{
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}
void display(class CircularArray q){
    int i = q.front+1;
    do
    {
        std::cout<<q.Q[i]<<" ";
        i = (i+1)%q.size;
    } while (i != (q.rear+1)%q.size);
    std::cout<<std::endl;
}