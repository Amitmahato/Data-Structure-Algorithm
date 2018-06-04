#include<iostream>
using namespace std;
void insert(int *arr,int val, int position)
{
    for(int i=arr[19];i>=position;i--)
    {
        if(i==position)
            arr[position]=val;
        else
            arr[i]=arr[i-1];

    }
    arr[19]++;
}

void del(int *arr,int position)
{
    for(int i=position;i<arr[19];i++)
        arr[i]=arr[i+1];
    arr[19]--;
}

int search(int *arr,int val)
{
    for(int i=0;i<arr[19];i++)
    {
        if(arr[i]==val)
            return i;
    }
    return -1;
}
int main()
{
    /** Initial Array **/
    int arr[20]={2,4,0,7,9,7,4};
    arr[19]=7; //length of occupied values in the array
    cout<<"/** Initial Array **/"<<endl;
    for (int i=0;i<arr[19];i++)
        cout<<"arr["<<i<<"] = "<<arr[i]<<endl;

    cout<<"Size of array : "<<arr[19]<<endl;

    /** Insertion Operation **/
    cout<<endl<<"/** Insertion Operation  **/"<<endl;
    insert(arr,129,3);
    insert(arr,126,5);
    insert(arr,123,7);
    for (int i=0;i<arr[19];i++)
        cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
    cout<<"Size of array = "<<arr[19]<<endl;


    /** Deletion Operation  **/
    cout<<endl<<"/** Deletion Operation  **/"<<endl;
    del(arr,3);  //1st call deletes the element at index 3 and shifts all after it to 1 left & hence element at 4 index is now at index 3 and so on
    del(arr,3);  //thus again deleting with same index deletes the next element at index 3
    for(int i=0;i<arr[19];i++)
        cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
    cout<<"Size of array = "<<arr[19]<<endl;

    /** Searching Operation **/
    cout<<endl<<"/** Search Operation  **/"<<endl;
    cout<<"Note : Negative index denotes the element isn't present in the array"<<endl;
    cout<<"2 is at index : "<<search(arr,2)<<endl;
    cout<<"1245 is at index : "<<search(arr,1245)<<endl;
    cout<<"Size of array = "<<arr[19]<<endl;


    return 0;
}
