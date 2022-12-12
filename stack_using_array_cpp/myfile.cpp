#include <iostream>
#include <string>

class Stack{
    private:
        int sz;
        int top;
        int *S;
    public:
        Stack(int size){
            sz = size;
            top = -1;
            S = new int[size];
        }
        ~Stack(){
            delete []S;
        }
        void push(int x);
        void pop();
        void display();
        int peek(int index);
        int isFull();
        int isEmpty();
        int stackTop();
};
int userInupt = 0;
int main() {
    //Anger fem för att få "felmeddelande" för push av nummer 6.
    std::cout<<"Enter size of array: ";
    std::cin>>userInupt;
    class Stack stackArray(userInupt);
    stackArray.push(1);
    stackArray.push(2);
    stackArray.push(3);
    stackArray.push(4);
    stackArray.push(5);
    stackArray.push(6);
    std::cout<<::std::endl;
    stackArray.display();
    std::cout<<::std::endl;
    stackArray.pop();
    stackArray.display();
    std::cout<<::std::endl;
    std::cout<<"Number 3 is at index :"<<stackArray.peek(3)<<std::endl;
    std::cout<<::std::endl;
    std::cout<<"Top value is: "<<stackArray.stackTop()<<std::endl;
    
    return 0;
}

void Stack::display(){
    std::cout<<"The values of array is: ";
    for (int i = top; i >= 0; i--)
    {
        std::cout<<S[i]<<" ";
    }
    std::cout<<::std::endl;
}

void Stack::push(int x){
    //kollar om det nya värdet får plats
    if (top == sz -1)
        std::cout<<"Stack overflow!\nVale: "<<x<<" didn't fit!\n";
    //Annars ökar top och sätter nya top som x
    else{
        top++;
        S[top] = x;
    }
}

void Stack::pop(){
    int x = -1;
    //kollar om det finns ett värde
    if (top == -1)
        std::cout<<"Stack underflow\n";
    //Annars tar bort senaste värdet
    else{
        x = S[top--];
    }
    std::cout<<"Value "<<x<<" has been poped!\n";
}

int Stack::peek(int index){
    int x = -1;
    //kontrollerar att index finns
    if (top - index + 1 < 0)
        std::cout<<"Index doesn't exist!\n";
    //om det finns, sparar det i x och returnerar
    else{
        x = S[top - index + 1];
    }
    return x;
}

int Stack::isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

int Stack::isFull(){
    return top == sz - 1;
}

int Stack::stackTop(){
    if(!isEmpty())
        return S[top];
    else
        return -1;
}