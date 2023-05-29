// https://www.youtube.com/watch?v=-StYr9wILqo&ab_channel=CodeBeauty
// Contains pointer to next and previous node
// Can add node in the beginning of list, end of list, before and after existing node
// Node* because we dynamically change size of list

#include <iostream>

class Node{
    public:
    int value;
    Node* next;
    Node* previous;
};

void printForward(Node* head);
void printBackwards(Node* head);

int main(){
    Node* head;
    Node* tail;
    // add first node
    Node* node = new Node();
    node->value = 4;
    node->next = nullptr;
    node->previous = nullptr;
    head = node;
    tail = node;

    // add second node
    node = new Node();
    node->value = 5;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    // add third node
    node = new Node();
    node->value = 6;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    // add fourth node
    node = new Node();
    node->value = 7;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;

    printForward(head);
    std::cout << std::endl;
    printBackwards(tail);

    return 0;
}

void printForward(Node* head){
    Node* traverser = head;
    while(traverser != nullptr){
        std::cout << traverser->value << std::endl;
        traverser = traverser->next;
    }    
}

void printBackwards(Node* tail){
    Node* traverser = tail;
    while(traverser != nullptr){
        std::cout << traverser->value << std::endl;
        traverser = traverser->previous;
    }    
}