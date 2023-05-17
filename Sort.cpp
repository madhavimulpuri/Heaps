#include <iostream>
using namespace std;

int hs; // heap size

void swap(int *x, int *y)
{
   
    int temp = *x;
    *x = *y;
    *y = temp;
}

void max_heapify(int arr[], int i)
{
    int lc = 2*i+1, rc = 2*(i+1), largest;
    if(lc<hs && arr[lc]>arr[i]) largest = lc; 
    else largest = i;
    if(rc<hs && arr[rc]>arr[largest]) largest = rc; 
    if(largest!=i)
    {
   
        swap(&arr[largest],&arr[i]);
        max_heapify(arr,largest);
    }
}

void build_maxheap(int arr[], int n)
{
    for(int i=(n/2)-1;i>=0;i--)
        max_heapify(arr,i);
}
void heapSort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        swap(&arr[0], &arr[hs-1]);
        hs=hs-1;
        max_heapify(arr, 0);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of heap: ";
    cin>>n;
    hs=n;
    int arr[50];
    cout<<"Enter "<<n<<" elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    printf("Before sorting, the elements are : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    build_maxheap(arr,n);
    heapSort(arr,n);
    printf("\nAfter sorting, the elements are : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
