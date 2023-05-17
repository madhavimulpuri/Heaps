#include <iostream>
using namespace std;

int hs;

void swap(int *x, int *y)
{
   
    int temp = *x;
    *x = *y;
    *y = temp;
}

void increase_key(int arr[], int i, int key)
{
    if(arr[i]>key)
    {
        cout<<"Increase is not possible";
        return;
    }
    arr[i]=key;
    while(i!=0 && arr[(i-1)/2] < arr[i])
    {
        swap(&arr[(i-1)/2],&arr[i]);
        i = (i-1)/2;
    }
}

void insertKey(int arr[], int key)
{
    hs = hs+1;
    arr[hs-1] = INT_MIN;
    increase_key(arr,hs-1,key);
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

void extract_max(int arr[])
{
    int x = arr[0];
    cout<<"Deleted "<<x<<endl;
    swap(&arr[0], &arr[hs-1]);
    hs=hs-1;
    max_heapify(arr,0);
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
    int pos,key;
    build_maxheap(arr,n);
    while(true){
        int choice;
        cout<<"MENU\n1. Insert key\n2. Increase key\n3. Display heap\n4. Extract maximum\n5. Exit\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter the key : "; cin>>key; insertKey(arr,key); break;
            case 2: cout<<"Enter key and position : "; cin>>key>>pos; increase_key(arr,pos,key); break;
            case 3: cout<<"The heap is : ";
                    for(int i=0;i<hs;i++)
                        cout<<arr[i]<<" ";
                    cout<<endl; break;
            case 4: extract_max(arr); break;
            case 5: exit(0);
            default: cout<<"Enter the valid choice"<<endl;
        }
    }
    return 0;
}
