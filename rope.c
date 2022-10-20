//ropes problem

#include <stdio.h>
#define capacity 100//max capacity
int size = 0;

int heap[capacity];

//methods define
//1. swapping no.'s
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
//2. parent
int parent(int i)
{
    if(size == 0 || size == 1)
    {
        return -1;
    }
    return (i-1)/2;
}
//3. left child
int leftChild(int i)
{
    if(size <= 1)
    {
        return -1;
    }
    return 2*i + 1;
}

//4. right child
int rightChild(int i)
{
    if(size <= 1)
    {
        return -1;
    }
    return 2*i + 2;
}

//5.heapify
void heapify(int arr[], int size, int i)
{
    if(size >= 2)
    {
        int l = leftChild(i);
        int r = rightChild(i);
        int min = i;
        if(l != -1 && l < size && arr[l] < arr[i])
        {
            min = l;
        }
        if(r != -1 && r < size && arr[r] < arr[i])
        {
            min = r;
        }
        if(min != i)
        {
            swap(&arr[i], &arr[min]);
            heapify(arr,size, min);
        }
    }
}

//6. Min-Heap
void minHeap(int arr[], int size)
{
    if(size >= 2)
    {
        for(int i = (size -1)/2; i >= 0; i--)
        {
            heapify(arr,size, i);
        }
    }
}
//7. Extraction of root
int extract(int arr[])
{
    if(size >= 1){
        int temp = arr[0];
        swap(&arr[size - 1] , &arr[0]);
        size--;
        heapify(arr,size, 0);
        return temp;
    }
}

//8.Insertion
void insert(int arr[], int num)
{
    if(size == 0)
    {
        arr[0] = num;
        size++;
    }
    else
    {
        arr[size] = num;
        size++;
        for(int i = (size - 1)/2; i >= 0; i--)
        {
            heapify(arr,size, i);
        }
    }
}
// imp function( Solution )
int minCost(int arr[])
{
    int cost = 0;
    /*
    ******Implementing min-heap******
    1. Turn the given array into Min-Heap
    while(array has more than 1 element)
        1. Extract top 2 min no.
        2. Add the those two no.'s .
        3. Insert the sum.
    2. return arr[0]
    */
   minHeap(arr, size);
   while(size > 1)
   {
        int min1 = extract(arr);
        int min2 = extract(arr);
        int newNum = min1 + min2;
        cost = cost + newNum;
        insert(arr, newNum);
   }
   return cost;
}


int main(void)
{
    //driver function
    //getting the inputs
    int n;
    printf("Enter the no. of ropes: ");
    scanf("%d", &n);
    size = n;

    printf("Enter the lengths of ropes: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&heap[i]);
    }

    printf("\n\nThe minimum cost of joining the ropes is %d", minCost(heap));
    return 0;
}
