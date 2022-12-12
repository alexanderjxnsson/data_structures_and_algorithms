#include <iostream>

void heapifyMin(int array[], int x, int i);
void heapifyMax(int array[], int sz, int root);
void heapSort(int array[], int n, int minOrMax);
void print(int array[], int sz);


int main() {
    //Min
    int A[] = {4, 8, 1, 13, 15, 30};
    int sz = sizeof(A) / sizeof(A[0]);
    heapSort(A, sz, 0);
    std::cout<<"After min sort: ";
    print(A, sz);
    //Max
    heapSort(A, sz, 1);
    std::cout<<"After  max sort: ";
    print(A, sz);
}

void heapifyMin(int array[], int sz, int root){
    int largest = root;
    int lChild = 2 * root + 1;
    int rChild = 2 * root + 2;
    if (lChild < sz && array[lChild] > array[largest])
    {
        largest = lChild;
    }
    if (rChild < sz && array[rChild] > array[largest])
    {
        largest = rChild;
    }
    if (largest != root)
    {
        std::swap(array[root], array[largest]);
        heapifyMin(array, sz, largest);
    }
}

void heapifyMax(int array[], int sz, int root){
    int largest = root;
    int lChild = 2 * root + 1;
    int rChild = 2 * root + 2;
    if (lChild < sz && array[lChild] < array[largest])
    {
        largest = lChild;
    }
    if (rChild < sz && array[rChild] < array[largest])
    {
        largest = rChild;
    }
    if (largest != root)
    {
        std::swap(array[root], array[largest]);
        heapifyMax(array, sz, largest);
    }
}

void heapSort(int array[], int sz, int minOrMax){
    int min = 0, max = 1;
    if (minOrMax == min)
    {
        for (int i = sz / 2 - 1; i >= 0; i--)
        {
            heapifyMin(array, sz, i);
        }
        for (int j = sz - 1; j >= 0; j--)
        {
            std::swap(array[0], array[j]);
            heapifyMin(array, j, 0);
        }
    }
    else if (minOrMax == max)
    {
        for (int i = sz / 2 - 1; i >= 0; i--)
        {
            heapifyMax(array, sz, i);
        }
        for (int j = sz - 1; j >= 0; j--)
        {
            std::swap(array[0], array[j]);
            heapifyMax(array, j, 0);
        }
    }
    
    
}

void print(int array[], int sz){
    for (int i = 0; i < sz; ++i)
    {
        std::cout<<array[i]<<", ";
    }
    std::cout<<std::endl;
}