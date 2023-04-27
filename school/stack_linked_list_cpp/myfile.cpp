#include <iostream>
class LinkedList{
    public:
        int value;
        class LinkedList *next;
        void display();
        void push(int value);
        int pop();
}*top = NULL;
int sizeOfArray = 0, arrValue = 0;

int main() {
    class LinkedList list;
    std::cout<<"Enter size: ";
    std::cin>>sizeOfArray;
    int Arr[sizeOfArray];
    std::cout<<"Enter values: \n";
    for (int i = 0; i < sizeOfArray; i++)
    {
        std::cin>>arrValue;
        Arr[i] = arrValue;
        list.push(Arr[i]);
    }
    list.display();
    std::cout<<std::endl;
    std::cout<<"Value "<<list.pop()<<" has been popped!\n";
    list.display();
    std::cout<<std::endl;
}

void LinkedList::display(){
    class LinkedList *temp;
    temp = top;
    std::cout<<"The values of the linked list are: ";
    while (temp != NULL)
    {
        std::cout<<temp->value<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

void LinkedList::push(int newValue){
    class LinkedList *temp;
    temp = new LinkedList[5];
    if(temp == NULL)
        std::cout<<"Stack is full!\nValue :"<<newValue<<" didn't fit\n";
    else{
        temp->value = newValue;
        temp->next = top;
        top = temp;
    }
}

int LinkedList::pop(){
    class LinkedList *temp;
    int x = -1;
    if(top == NULL)
        std::cout<<"Stack is empty!\n";
    else{
        temp = top;
        top = top->next;
        x = temp->value;
        free(temp);
    }
    return x;
}
