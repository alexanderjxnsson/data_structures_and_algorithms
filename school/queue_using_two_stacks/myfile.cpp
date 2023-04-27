#include <iostream>
#include <stack>

class Queue{
    private:
        std::stack<int> stack1;
        std::stack<int> stack2;
    public:
        Queue(){};
        ~Queue(){};
        void enqueue(int x);
        int dequeue();
};
int arrSize = 0, arrValue = 0;
int main() {
    std::cout<<"Enter size: ";
    std::cin>>arrSize;
    int A[arrSize];
    std::cout<<"Enter values\n";
    for (int i = 0; i < arrSize; i++)
    {
        std::cin>>arrValue;
        A[i] = arrValue;
    }
 
    Queue queue;
 
    std::cout << "Enqueue: " << std::flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        queue.enqueue(A[i]);
        std::cout << A[i] << std::flush;
        if (i < sizeof(A)/sizeof(A[0])-1){
            std::cout << " <- " << std::flush;
        }
    }
    std::cout << std::endl;
 
    std::cout << "Dequeue: " << std::flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        std::cout << queue.dequeue() << std::flush;
        if (i < sizeof(A)/sizeof(A[0])-1){
            std::cout << " <- " << std::flush;
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}

void Queue::enqueue(int x) {
    stack1.push(x);
}
 
int Queue::dequeue() {
    int x = -1;
    if (stack2.empty()){
        if (stack1.empty()){
            std::cout << "Queue Underflow" << std::endl;
            return x;
        } else {
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }
    x = stack2.top();
    stack2.pop();
    return x;
}