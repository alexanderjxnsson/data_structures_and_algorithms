#include <stdio.h>
#include <stdlib.h>
enum choices{DISPLAY = 1, APPEND, INSERT, ERASE, LINEAR, BINARY, rBINARY, GETMAX, GETMIN, SUM, AVG, REVERSE, GET, SET, SORT, MERGE, ARR2, SIMILAR, DIFFERENT, EXIT};
bool bMenu = true;
int menuchoice, appendValue = 0, insertValue = 0, insertIndex = 0, deleteIndex = 0, searchIndex = 0, arrayLength = 0;
struct Array{
    int *A;
    int size;
    int length;
    /* Array(int size)
    {
        this->size=size;
        A = new int[size];
    } */
}*arr, *arr2;
struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
struct Array *arr4=(struct Array *)malloc(sizeof(struct Array));
struct Array *arr5=(struct Array *)malloc(sizeof(struct Array));

void options();
void create();
void create2();
void display(struct Array *arr);
void display1(struct Array arr);
int append(struct Array *arr, int x);
int insert(struct Array *arr, int index, int x);
int Delete(struct Array *arr, int index);
int linearSearch(struct Array *arr, int key);
int binarySearch(struct Array *arr, int key);
int rBinarySearch(int a[], int l, int h, int key);
int get(struct Array *arr, int index);
void set(struct Array *arr, int index, int x);
int max(struct Array *arr);
int min(struct Array *arr);
int sum(struct Array *arr);
float avg(struct Array *arr);
void swap(int *x, int *y);
void reverse1(struct Array *arr);
void reverse2(struct Array *arr);
int isSorted(struct Array *arr);
struct Array* Merge(struct Array *arr1,struct Array *arr2);
struct Array* different(struct Array *arr1, struct Array *arr2);
struct Array* samesame(struct Array *arr1, struct Array *arr2);
int main() {
    printf("Hello and welcome!\n");
    create();
    create2();
    while (bMenu == true)
    {
        options();
        scanf("%d", &menuchoice);
        switch (menuchoice)
        {
        case DISPLAY:
            display(arr);
            break;
        case APPEND:
            printf("What value do you want to append?\n");
            scanf("%d", &appendValue);
            append(arr, appendValue);
            system("pause");
            system("cls");
            break;
        case INSERT:
            printf("What value do you want to insert?\n");
            scanf("%d", &insertValue);
            printf("What index do you want to replace the new value with?\n");
            scanf("%d", &insertIndex);
            insert(arr, insertIndex, insertValue);
            system("pause");
            system("cls");
            break;
        case ERASE:
            printf("What index do you want to delete?\n");
            scanf("%d", &deleteIndex);
            Delete(arr, deleteIndex);
            printf("Index %d has been deleted!", deleteIndex);

            break;
        case LINEAR:
            printf("What element do you want to search for?\n");
            scanf("%d", &searchIndex);
            printf("The element is in index: %d\n", linearSearch(arr, searchIndex));
            system("pause");
            system("cls");
            break;
        case BINARY:
            printf("What element do you want to search for?\n");
            scanf("%d", &searchIndex);
            printf("The element is in index: %d\n", binarySearch(arr, searchIndex));
            system("pause");
            system("cls");
            break;
        case rBINARY:
            printf("What element do you want to search for?\n"); 
            scanf("%d", &searchIndex);
            printf("The element is in index: %d\n", rBinarySearch(arr->A, 0, arr->length, searchIndex));
            system("pause");
            system("cls");
            break;
        case GETMAX:
            printf("The max value in the array is: %d\n", max(arr));
            system("pause");
            system("cls");
            break;
        case GETMIN:
            printf("The min value in the array is: %d\n", min(arr));
            system("pause");
            system("cls");
            break;
        case SUM:
            printf("The sum of the array is: %d\n", sum(arr));
            system("pause");
            system("cls");
            break;
        case AVG:
            printf("The average of the array is: %f\n", avg(arr));
            system("pause");
            system("cls");
            break;
        case REVERSE:
            reverse1(arr);
            display(arr);
            break;
        case GET:
            printf("What element do you want to search for?\n");
            scanf("%d", &searchIndex);
            printf("The element is in index: %d\n", get(arr, searchIndex));
            system("pause");
            system("cls");
            break;
        case SET:
            printf("What value do you want to insert?\n");
            scanf("%d", &insertValue);
            printf("What index do you want to replace the new value with?\n");
            scanf("%d", &insertIndex);
            set(arr, insertIndex, insertValue);
            system("pause");
            system("cls");
            break;
        case SORT:
            if (isSorted(arr) == 0)
            {
                printf("The array is not sorted!\n");
                system("pause");
                system("cls");
            }
            else{
                printf("The array is sorted!\n");
                system("pause");
                system("cls");
            }
            break;
        case MERGE:
            printf("The new array has been created!\nMerge initiated. . .\n");
            arr3=Merge(arr, arr2);
            display(arr3);
            break;
        case ARR2:
            //display1(arr2);
            system("pause");
            system("cls");
            break;
        case SIMILAR:
            printf("The similars are: \n");
            arr4 = samesame(arr, arr2);
            display(arr4);
            break;
        case DIFFERENT:
            printf("The differences are: \n");
            arr5 = different(arr, arr2);
            display(arr5);
            break;
        case EXIT:
            printf("\nYou chose to exit, bye!\n");
            bMenu = false;
            break;
        default:
            printf("Please enter a valid number!");
            break;
        }
    }
    
}
void options(){
    printf("What do you want to do?\n1. Display array\n2. Append value\n3. Insert and replace\n");
    printf("4. Delete value\n5. Linear search\n6. Binary search\n7. Recursive binary search\n");
    printf("8. Get max value\n9. Get min value\n10. Sum of array\n11. Average number\n12. Reverse the array\n13. Get specific value\n");
    printf("14. Set specific value\n15. Sorted or not?\n16. Merge\n17. Display array #2\n18. Similar\n");
    printf("19. Different\n20. Exit\n");
}

void create2(){
    printf("We'll now create our second array!\n");
    arr2=(struct Array*)malloc(sizeof(struct Array));
    arr2->length=arrayLength;
    printf("Enter all of the elements\n");
    for (int i = 0; i < arrayLength; i++)
    {
        scanf("%d", &arr2->A[i]);
    }
    printf("Array has been created!\n");
}

void create(){
    printf("We'll start by creating the array!\n");
    printf("Enter the number of elements\n");
    arr=(struct Array*)malloc(sizeof(struct Array));
    arr->A = (int *)malloc(10*sizeof(int));
    arr->length=0;
    scanf("%d", &arr->length);
    arrayLength = arr->length;
    /* scanf("%d", arr.length); */
    printf("Enter all of the elements\n");
    for (int i = 0; i < arr->length; i++)
    {
        scanf("%d", &arr->A[i]);
    }
    printf("Array has been created!\n");
}

void display(struct Array *arr){
    printf("\nElements are\n");
    for (int i = 0; i <arr->length; i++)
    {
        printf("Index %d: %d\n", i, arr->A[i]);
    }
    system("pause");
    system("cls");
}

int append(struct Array *arr, int x){
    if (arr->length<arr->size)
    {
        arr->A[arr->length++]=x;
    }
    return x;
}

int insert(struct Array *arr, int index, int x){
    int i;
    if (index>=0 && index <= arr->size)
    {
        for (i=arr->size;i>index;i--)
        {
            arr->A[index]=x;
            arr->size++;
        }
    }
    return x;
}

int Delete(struct Array *arr, int index){
    int x=0;
    int i;
    if (index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for (i = index; i < arr->length-1; i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
    return 0; 
}

int linearSearch(struct Array *arr, int key){
    int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			return i;
		}
	}
    return 0;
}

int binarySearch(struct Array *arr, int key)
{
	int l, mid, h;
	l = 0;
	h = arr->length- 1;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr->A[mid])
		{
			return mid;
		}
		else if (key < arr->A[mid])
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
    return 0;
}

int rBinarySearch(int a[], int l, int h, int key)
{
	int mid = 0;
	if (l <= h)
	{
		mid=(l + h) / 2;
		if (key == a[mid])
		{
			return mid;
		}
		else if (key < a[mid])
		{
			return rBinarySearch(a,l, mid - 1, key);
		}
		else
		{
			return rBinarySearch(a, mid + 1, h, key);
		}
	}
    return -1;
}

void display1(struct Array *arr){
    printf("Elements are: \n");
    for (int i = 0; i < arr->length; i++)
    {
        printf("%d\n", arr->A[i]);
    }
}


int get(struct Array *arr, int index){
    if (index>=0 && index <arr->length)
    {
        return arr->A[index];
    }
    return 0;
}
void set(struct Array *arr, int index, int x){
    if (index>=0 && index <arr->length)
    {
        arr->A[index] = x;
    }
}
int max(struct Array *arr){
    int max = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i]>max)
        {
            max=arr->A[i];
        }
    }
    return max;
}
int min(struct Array *arr){
    int min = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i]<min)
        {
            min=arr->A[i];
        }
    }
    return min;
}
int sum(struct Array *arr){
    int sum = 0;
    for (int i = 0; i < arr->length; i++)
    {
        sum+=arr->A[i];
    }
    return sum;
}
float avg(struct Array *arr){
    return (float)sum(arr)/arr->length;
}
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void reverse1(struct Array *arr){
    int i, j;
    for (i = 0, j=arr->length-1;i<j;i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}
void reverse2(struct Array *arr){
    int *B;
    int i, j;
    B=(int *)malloc(arr->length*sizeof(int));
    for (i=arr->length-1,j=0;i>=0; i--,j++)
    {
        B[j]=arr->A[i];
    }
    for (i=0;i<arr->length;i++)
    {
        arr->A[i]=B[i];
    }
}

int isSorted(struct Array *arr){
    int i;
    for (i = 0; i < arr->length-1; i++)
    {
        if (arr->A[i]>arr->A[i+1])
        {
            return 0;
        }
    }
    return 1;
}


struct Array* Merge(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    arr3->length=arr1->length+arr2->length;
    arr3->size=arr1->size+arr2->size;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    
    return arr3;
}

struct Array* samesame(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    while(i<arr1->length && j<arr2->length)
    { 
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    return arr3;
}

struct Array* different(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    } for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    arr3->length=k;
    return arr3;
}