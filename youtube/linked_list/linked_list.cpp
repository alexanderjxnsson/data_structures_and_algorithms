// https://www.youtube.com/watch?v=HKfj0l7ndbc&t=27s&ab_channel=CodeBeauty
// First element = head, stores second elements adress via pointer, and so on.
// Last stores NULL
// No random access, because random adresses. Only know where your first element are. Need to traverse from one to desired value
// User defined data types for linked list
#include <iostream>

class Node{
    public:
    int value;
    Node* next; // ptr to next value
};

void printList(Node* n);

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;
    
    printList(head);

    return 0;
}

void printList(Node* n){
    while(n != NULL){
        std::cout << n->value << " ";
        n = n->next;
    }
    std::cout<<std::endl;
}