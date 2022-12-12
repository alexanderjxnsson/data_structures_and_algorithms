#include <iostream>
class Node{
    public:
    Node *lChild;
    int value;
    Node *rChild;
    Node(){};
    Node(int value);
};

class Tree{
    private:
    Node *root;

    public:
    void create();
    Tree(){root = nullptr;}
    Node *getRoot(){return root;}
    void itInsert(int key);
    Node *itSearch(int key);
    int height(Node *p);
    int leafCount(){return leafCount(root);}
    int leafCount(Node *p);
    int count(Node *p);
};

class queue{
    private:
    int front, rear, size;

    Node **Q;
    public:
    queue(){front = rear = -1; size= 10; Q = new Node*[size];}
    queue(int size){front = rear = -1; this->size;Q = new Node*[size];}
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty(){return front == rear;}

};

int main() {
    Tree tree;
    tree.create();
    std::cout<<std::endl;
    std::cout<<"Leaf count: "<<tree.leafCount()<<std::endl;
    return 0;

}

void Tree::create(){
    Node *p, *temp = NULL;
    int x = 0;
    queue queue(100);
    std::cout<<"Enter root: ";
    std::cin>>x;
    root = new Node;
    root->value = x;
    root->lChild = root->rChild = NULL;
    queue.enqueue(root);

    while (!queue.isEmpty())
    {
        p = queue.dequeue();
        std::cout<<"Enter left child of "<<p->value<<" ";
        scanf("%d", &x);
        if (x != -1)
        {
            temp = new Node;
            temp->value = x;
            temp->lChild = temp->rChild = NULL;
            p->lChild = temp;
            queue.enqueue(temp);
        }
        
        std::cout<<"Enter right child of "<<p->value<<" ";
        scanf("%d", &x);
        if (x != -1)
        {
            temp = new Node;
            temp->value = x;
            temp->lChild = temp->rChild = NULL;
            p->rChild = temp;
            queue.enqueue(temp);
        }
    }
}

Node::Node(int value){
    lChild = nullptr;
    this->value = value;
    rChild = nullptr;
}

int Tree::leafCount(Node *p)  
{  
    if(p == NULL){
        return 0;  
    }
    if(p->lChild == NULL && p->rChild == NULL){
        return 1; 
    }
    else{
        return leafCount(p->lChild) + leafCount(p->rChild);
    }
}

int Tree::height(Node *root){
    int x = 0;
    int y = 0;
    if (root == 0)
    {
        return 0;
    }
    x = height(root->lChild);
    y = height(root->rChild);
    if (x > y)
        return x+1;
    else
        return y+1;
}

void queue::enqueue(Node *p){
    if (rear == size -1)
    {
        std::cout<<"Queue is full\n!";
    }
    else{
        rear++;
        Q[rear] = p;
    }
}

Node *queue::dequeue(){
    Node *p = NULL;
    if (rear == size -1)
    {
        std::cout<<"Queue is empty\n!";
    }
    else{
        p = Q[front+1];
        front++;
    }
    return p;
}