// https://www.youtube.com/watch?v=jaK4pn1jXTo&ab_channel=CodeBeauty
#include <iostream>
#include <queue>

void printQueue(std::queue<int> queue);

int main(){
    std::queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    std::cout << "Size is: " << myQueue.size() << std::endl;
    std::cout << "First element is: " << myQueue.front() << std::endl;
    std::cout << "Last element is: " << myQueue.back() << std::endl;

    std::cout << "My queue: ";
    printQueue(myQueue);

    return 0;
}

void printQueue(std::queue<int> queue){
    while(!queue.empty()){
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout<<std::endl;
}
