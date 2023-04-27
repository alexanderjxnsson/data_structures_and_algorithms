/*
https://www.youtube.com/watch?v=UHxtjVsOTHc&ab_channel=CodeBeauty
https://www.youtube.com/watch?v=_IhTp8q0Mm0&ab_channel=CodeBeauty
depth first search:
    preorder(data, left, right)
    inorder(left, data, right)
    postorder(left, right, data)
breadth first search
*/

#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void printTree_preorder(Node* root);
void printTree_inorder(Node* root);
void printTree_postorder(Node* root);

int main(){
    // Level 1
    Node* root = createNode(1);

    // Level 2
    root->left = createNode(2);
    root->right = createNode(3);

    // Level 3
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Level 4
    root->left->right->left = createNode(9);
    root->right->right->left = createNode(15);

    std::cout << "Preorder print: \n";
    printTree_preorder(root);

    std::cout << "\nInorder print: \n";
    printTree_inorder(root);

    std::cout << "\nPostorder print: \n";
    printTree_postorder(root);

    return 0;
}

void printTree_preorder(Node* root){
    if(root == nullptr)
        return;

    std::cout<< root->data << std::endl;
    printTree_preorder(root->left);
    printTree_preorder(root->right);
}

void printTree_inorder(Node* root){
    if(root == nullptr)
        return;

    printTree_inorder(root->left);
    std::cout<< root->data << std::endl;
    printTree_inorder(root->right);
}

void printTree_postorder(Node* root){
    if(root == nullptr)
        return;

    printTree_postorder(root->left);
    printTree_postorder(root->right);
    std::cout<< root->data << std::endl;
}