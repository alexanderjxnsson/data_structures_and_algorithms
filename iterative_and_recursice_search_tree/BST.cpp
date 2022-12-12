//Binary tree
#include <iostream>

class Node{
    public:
    Node *lChild;
    int value;
    Node *rChild;
    Node(){};
    Node(int data);
};

class Tree{
    private:
    Node *root;
    public:
    Tree(){root = nullptr;};
    Node *getRoot(){return root;};
    void itInsert(int key);
    void inOrder(Node *p);
    Node *itSearch(int key);
    Node *rInsert(Node *p, int key);
    Node *rSearch(Node *p, int key);
    Node *Delete(Node *p, int key);
    Node *inPre(Node *p);
    Node *inSucc(Node *p);
    int height(Node *p);
    
};
int main() {
    Tree tree1;
    tree1.itInsert(10);
    tree1.itInsert(5);
    tree1.itInsert(25);
    tree1.itInsert(14);
    tree1.itInsert(7);
    tree1.itInsert(45);
    tree1.itInsert(65);
    std::cout<<"First tree: ";
    tree1.inOrder(tree1.getRoot());
    std::cout<<std::endl;
    //iterative search
    std::cout<<"Iterative search for 1\n";
    Node *temp = tree1.itSearch(1);
    if (temp != nullptr)
    {
        std::cout<<"Element: "<<temp->value<<" found!\n";
    }
    else{
        std::cout<<"Element not found!\n";
    }
    //recursive search
    std::cout<<"Recursive search for 5\n";
    temp = tree1.rSearch(tree1.getRoot(), 5);
    if (temp != nullptr)
    {
        std::cout<<"Element: "<<temp->value<<" found!\n";
    }
    else{
        std::cout<<"Element not found\n";
    }
    std::cout<<"Recursive insert of three new values!\n";
    tree1.rInsert(tree1.getRoot(), 1337);
    tree1.rInsert(tree1.getRoot(), 55);
    tree1.rInsert(tree1.getRoot(), 666);
    std::cout<<"First tree afterwards: ";
    tree1.inOrder(tree1.getRoot());
    std::cout<<std::endl;

    //NEW TREE
    Tree tree2;
    tree2.itInsert(8);
    tree2.itInsert(2);
    tree2.itInsert(67);
    tree2.itInsert(12);
    tree2.itInsert(13);
    tree2.itInsert(1);
    tree2.itInsert(21);
    tree2.itInsert(31);
    std::cout<<std::endl;
    std::cout<<"Second tree: ";
    tree2.inOrder(tree2.getRoot());
    std::cout<<std::endl;
    temp = tree2.inPre(tree2.getRoot());
    std::cout<<"InPre: "<<temp->value<<std::endl;
    temp = tree2.inSucc(tree2.getRoot());
    std::cout<<"InSucc: "<<temp->value<<std::endl;
    tree2.Delete(tree2.getRoot(), 13);
    std::cout<<"Second tree after delete of 13: ";
    tree2.inOrder(tree2.getRoot());
    //iterative search
    std::cout<<"\nIterative search for 1\n";
    temp = tree2.itSearch(1);
    if (temp != nullptr)
    {
        std::cout<<"Element: "<<temp->value<<" found!\n";
    }
    else{
        std::cout<<"Element not found!\n";
    }
    //recursive search
    std::cout<<"Recursive search for 13\n";
    temp = tree1.rSearch(tree2.getRoot(), 13);
    if (temp != nullptr)
    {
        std::cout<<"Element: "<<temp->value<<" found!\n";
    }
    else{
        std::cout<<"Element not found\n";
    }
    std::cout<<std::endl;
    
    return 0;
}

Node *Tree::itSearch(int key){
    Node *t = root;
    while (t != nullptr)
    {
        if(key == t->value){
            return t;
        }
        else if (key < t->value)
        {
            t = t->lChild;
        }
        else{
            t = t->rChild;
        }
    }
    return nullptr;
}

void Tree::itInsert(int key){
    Node *t = root;
    Node *p;
    Node *r;
    if (root == nullptr)
    {
        p = new Node;
        p->value = key;
        p->lChild = nullptr;
        p->rChild = nullptr;
        root = p;
        return;
    }
    
    while (t != nullptr)
    {
        r = t;
        if (key<t->value)
        {
            t = t->lChild;
        }
        else if (key>t->value)
        {
            t = t->rChild;
        }
        else{
            return;
        }
    }
    p = new Node;
    p->value = key;
    p->lChild = nullptr;
    p->rChild = nullptr;
    if (key<r->value)
    {
        r->lChild = p;
    }
    else{
        r->rChild = p;
    }
}

void Tree::inOrder(Node *p){
    if (p)
    {
        inOrder(p->lChild);
        std::cout<<p->value<<", "<<std::flush;
        inOrder(p->rChild);
    }
}

Node *Tree::rInsert(Node *p, int key){
    Node *temp;
    if (p == nullptr)
    {
        temp = new Node;
        temp->value = key;
        temp->lChild = nullptr;
        temp->rChild = nullptr;
        return temp;
    }
    if (key<p->value)
    {
        p->lChild = rInsert(p->lChild, key);
    }
    else if (key>p->value)
    {
        p->rChild = rInsert(p->rChild, key);
    }
    return p;
}

Node *Tree::rSearch(Node *p, int key){
    if (p == nullptr)
    {
        return nullptr;
    }
    if (key == p->value)
    {
        return p;
    }
    else if (key < p->value)
    {
        return rSearch(p->lChild, key);
    }
    else
    {
        return rSearch(p->rChild, key);
    }
}

Node *Tree::inPre(Node* p){
    while (p && p->rChild != nullptr)
    {
        p = p->rChild;
    }
    return p;
}

Node *Tree::inSucc(Node* p){
    while (p && p->lChild != nullptr)
    {
        p = p->lChild;
    }
    return p;
}

Node *Tree::Delete(Node *p, int key){
    Node *q;
    if (p == nullptr)
    {
        return nullptr;
    }
    if (p->lChild == nullptr && p->rChild == nullptr)
    {
        if (p == root)
        {
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
    if (key < p->value)
    {
        p->lChild = Delete(p->lChild, key);
    }
    else if (key > p->value)
    {
        p->rChild = Delete(p->rChild, key);
    }
    else{
        if (height(p->lChild) > height(p->rChild))
        {
            q = inPre(p->lChild);
            p->value = q->value;
            p->lChild = Delete(p->lChild, q->value);
        }
        else{
            q = inSucc(p->rChild);
            p->value = q->value;
            p->rChild = Delete(p->rChild, q->value);
        }
    }
    return p;
}

int Tree::height(Node *p){
    int x;
    int y;
    if (p == nullptr)
    {
        return 0;
    }
    x = height(p->lChild);
    y = height(p->rChild);
    return x>y?x+1:y+1;
}