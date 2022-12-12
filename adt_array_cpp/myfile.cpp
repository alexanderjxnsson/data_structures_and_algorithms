#include <iostream>
enum CHOICES {DISPLAY = 1, APPEND, INSERT, ERASE, LINEARSEARCH,
BINARYSEARCH, GET, SET, MAX, MIN, SUM, AVERAGE, REVERSE,
REVERSE1, INSERTSORT, ISSORTED, REARRANGE, MERGE, DIFF, SAME, EXIT};

class Array{
    private:
    int *A;
    int size;
    int length;
    public:
    Array(){
        size=10;
        length=0;
        A=new int[size];
    }
    ~Array(){
        delete []A;
    }
    void Display();
    void Append(int x);
    void Insert(int index,int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index,int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array arr2);
    Array* Diff(Array arr2);
    Array* Inter(Array arr2);
};

void welcome();
void create();
void menu();
void pauseAndClearScreen();
void swap();
bool bMenu = true;
int menuChoice = 0, arrLength = 0, arrSize = 0, index = 0, element = 0, newValue = 0,
countLength = 0, arrSize1 = 0;
Array *arrNum1;
Array *arrNum2;
Array *arrNum3;

int main(){
    arrNum1 = new Array;
    arrNum2 = new Array;
    arrNum3 = new Array;
    welcome();
    std::cout<<"Let's create our first array!\nEnter number of elements: ";
    std::cin>>arrSize;
    arrNum1 = new Array;
    std::cout<<"Enter elements: \n";
    for (int i = 0; i < arrSize; i++){
        std::cin>>element;
        arrNum1->Insert(i, element);
    }
    std::cout<<"Array has been created, thank you!\n";
    pauseAndClearScreen();
    while (bMenu == true){
        menu();
        std::cin>>menuChoice;
        switch (menuChoice){
        case DISPLAY://1
            arrNum1->Display();
            break;
        case APPEND://2
            std::cout<<"What value do you want to append: ";
            std::cin>>newValue;
            arrNum1->Append(newValue);
            std::cout<<"Adding number!\n";
            pauseAndClearScreen();
            break;
        case INSERT://3
            std::cout<<"What value do you want to insert: ";
            std::cin>>newValue;
            std::cout<<"In what index: ";
            std::cin>>index;
            arrNum1->Insert(index, newValue);
            pauseAndClearScreen();
            break;
        case ERASE://4
            std::cout<<"What index do you want to delete: ";
            std::cin>>index;
            arrNum1->Delete(index);
            arrNum1->Display();
            break;
        case LINEARSEARCH://5
            std::cout<<"What value do you want to search for?\n";
            std::cin>>newValue;
            std::cout<<"Found value at index: "<<arrNum1->LinearSearch(newValue)<<std::endl;
            pauseAndClearScreen();
        break;
        case BINARYSEARCH://6
            std::cout<<"What value do you want to search for?\n";
            std::cin>>newValue;
            std::cout<<"Found value at index: "<<arrNum1->BinarySearch(newValue)<<std::endl;
            pauseAndClearScreen();
            break;
        case GET://7
            std::cout<<"What index do you want to get?\n";
            std::cin>>index;
            std::cout<<"At index: "<<arrNum1->Get(index)<<std::endl;
            pauseAndClearScreen();
            break;
        case SET://8
            std::cout<<"What value do you want to set: ";
            std::cin>>newValue;
            std::cout<<"In what index: ";
            std::cin>>index;
            arrNum1->Set(index, newValue);
            pauseAndClearScreen();
            break;
        case MAX://9
            std::cout<<"Max value is: "<<arrNum1->Max()<<std::endl;
            pauseAndClearScreen();
            break;
        case MIN://10
            std::cout<<"Min value is: "<<arrNum1->Min()<<std::endl;
            pauseAndClearScreen();
        break;
        case SUM://11
            std::cout<<"The sum is: "<<arrNum1->Sum()<<std::endl;
            pauseAndClearScreen();
        break;
        case AVERAGE://12
            std::cout<<"The average is: "<<arrNum1->Avg()<<std::endl;
            pauseAndClearScreen();
            break;
        case REVERSE://13
            arrNum1->Reverse();
            std::cout<<"The new order of array\n";
            arrNum1->Display();
            break;
        case REVERSE1://14
            arrNum1->Reverse2();
            std::cout<<"The new order of array\n";
            arrNum1->Display();
            break;
        case INSERTSORT://15
            std::cout<<"What value do you want to insert: ";
            std::cin>>newValue;
            arrNum1->InsertSort(newValue);
            std::cout<<"The new array: \n";
            arrNum1->Display();
            break;
        case ISSORTED://16
            if (arrNum1->isSorted() == 0){
                std::cout<<"The array is not sorted\n";
                pauseAndClearScreen();
            }
            else{
                std::cout<<"The array is sorted\n";
                pauseAndClearScreen();
            }
            break;
        case REARRANGE://17
            arrNum1->Rearrange();
            std::cout<<"Array after sort: ";
            arrNum1->Display();
            break;
        case MERGE://18
            std::cout<<"Let's create a new array, enter number of elements: ";
            std::cin>>arrSize1;
            std::cout<<"Enter elements: \n";
            for (int i = 0; i < arrSize1; i++){
                std::cin>>element;
                arrNum2->Insert(i, element);
            }
            std::cout<<"After merge we got: \n";
            arrNum1->Merge(*arrNum2);
            arrNum3->Display();
            break;
        case DIFF://19
            std::cout<<"Look for differences!\n";
            std::cout<<"Let's create a new array, enter number of elements: ";
            std::cin>>arrSize1;
            std::cout<<"Enter elements: \n";
            for (int i = 0; i < arrSize1; i++){
                std::cin>>element;
                arrNum2->Insert(i, element);
            }
            arrNum1->Diff(*arrNum2);
            arrNum3->Display();
            break;
        case SAME://20
            std::cout<<"Look for similairs!\n";
            std::cout<<"Let's create a new array, enter number of elements: ";
            std::cin>>arrSize1;
            std::cout<<"Enter elements: \n";
            for (int i = 0; i < arrSize1; i++){
                std::cin>>element;
                arrNum2->Insert(i, element);
            }
            arrNum1->Inter(*arrNum2);
            arrNum3->Display();
            break;
        case EXIT://21
            std::cout<<"You chose to exit, bye!\n";
            bMenu = false;
            break;
        default:
            std::cout<<"\nPlease enter e a valid number\n";
            pauseAndClearScreen();
            break;
        }
    }
}
void welcome(){
    std::cout<<"Hello and welcome to the C++-version!\n";
}
void pauseAndClearScreen(){
    system("pause");
    system("cls");
}
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void menu(){
    std::cout<<"1. Display array\n2. Append value\n3. Insert value\n4. Delete index\n"<<
                "5. Linear search\n6. Binary search\n7. Get value\n8. Set value\n9. Max value\n"<<
                "10. Min value\n11. Sum of array\n12. Average value\n13. Reverse\n14. Reverse\n15. Insert& sort\n"<<
                "16. Is it sorted?\n17. ReArrange\n18. Merge\n19. Different\n20. Similar\n21. Exit\n";
}
void Array::Display(){
    int i;
    std::cout<<"\nElements are\n";
    for(i=0;i<length;i++)
    std::cout<<A[i]<<" ";
    std::cout<<std::endl;
    system("pause");
    system("cls");
}
void Array::Insert(int index,int x){
    int i;
    if(index>=0 && index <=length){
        for(i=length;i>index;i--)
            A[i]=A[i-1];
            A[index]=x;
            length++;
    }
}

void Array::Append(int x){
    if (length<size){
        A[length++] = x;
    }
}
int Array::Delete(int index){
    int x = 0, i;
    if (index>=0 && index<size){
        x = A[index];
        for (i = index; i < size; i++){
            A[i] = A[i+1];
        }
        size--;
    }
    return 0;
}

int Array::LinearSearch(int key){
    for (int i = 0; i < length; i++){
        if (key == A [i])
        {
            return i;
        }
    }
    return 0;
}

int Array::BinarySearch(int key){
    int l, mid, h;
    l = 0;
    h = length-1;
    while (l <= h){
        mid = (l + h) / 2;
        if (key == A[mid]){
            return mid;
        }
        else if (key < A[mid]){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return 0;
}

int Array::Get(int index){
    if (index>= 0 && index<=size){
        return A[index];
    }
    else{
        std::cout<<"Out of index!\n"<<std::endl;
    }
    return 0;
}

void Array::Set(int index,int x){
    A[index] = x;
}

int Array::Max(){
    int max = A[0];
    for (int i = 0; i < length; i++){
        if (A[i]>max){
            max=A[i];
        }
    }
    return max;
}

int Array::Min(){
    int min = A[0];
    for (int i = 0; i < length; i++){
        if (A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Array::Sum(){
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += A[i];
    }
    return sum;
}

float Array::Avg(){
    float sum = 0;
    for (int i = 0; i < length; i++){
        sum += A[i];
    }
    sum = sum/length;
    return (float)sum;
}

void Array::Reverse(){
    int i, j;
    for (i = 0, j=length-1; i<j; i++, j--){
        swap(&A[i], &A[j]);
    }
}

void Array::Reverse2(){
    int *B = new int[size];
    int i, j;
    for (i = length-1, j = 0; i>=0; i--, j++){
        B[j]=A[i];
    }
    for (i=0; i<length; i++){
        A[i]=B[i];
    }
}

void Array::InsertSort(int x){
    if (length<size){
        A[length++] = x;
    }
    int i,j;
    int temp;
    for(i=0;i<length;i++){
        for(j=i+1;j<length;j++){
            if(A[i]>A[j]){
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    }
    int Array::isSorted(){
    int i;
    for (i = 0; i < length-1; i++){
        if (A[i]>A[i+1]){
            return 0;
        }
    } return 1;

}

void Array::Rearrange(){
    int i,j;
    int temp;
    for(i=0;i<length;i++){
        for(j=i+1;j<length;j++){
        if(A[i]>A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        }
    }
}

Array* Array::Merge(Array arr2){
    int i,j,k;
    i=j=k=0;
    while (i<length && j<arr2.length){
        if (A[i]<arr2.A[j]){
            arrNum3->A[k++] = A[i++];
        }
        else{
            arrNum3->A[k++] = arr2.A[j++];
        }
        for (; i < length; i++){
            arrNum3->A[k++] = A[i];
        }
        for (; j < length; j++){
            arrNum3->A[k++] = arr2.A[j];
        }
        arrNum3->length=length+arr2.length;
    }
    return arrNum3;
}

Array* Array::Diff(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j])
        arrNum3->A[k++]=A[i++];
        else if(arr2.A[j]<A[i])
            j++;
        else{
            i++;
            j++;
        }
    } for(;i<length;i++)
        arrNum3->A[k++]=A[i];
    arrNum3->length=k;
    return arrNum3;
}

Array* Array::Inter(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    while(i<length && j<arr2.length){ 
        if(A[i]<arr2.A[j])
            i++;
        else if(arr2.A[j]<A[i])
            j++;
        else if(A[i]==arr2.A[j]){
            arrNum3->A[k++]=A[i++];
            j++;
        }
    }
    arrNum3->length=k;
    return arrNum3;
}