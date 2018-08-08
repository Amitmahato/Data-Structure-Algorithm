#include<iostream>
using namespace std;
template <class T>
int minValIndex(T Ar[],int index,int size)
{
    int minLoc = index;
    for(int i=index+1;i<size;i++)
    {
        minLoc = (Ar[minLoc]>Ar[i])? i : minLoc;
    }
    return minLoc;
}

template <class T>
void selectionSort(T Ar[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int loc = minValIndex(Ar,i,size);
        T temp = Ar[loc];
        Ar[loc] = Ar[i];
        Ar[i] = temp;
    }
}


int main()
{
    int size = 5;
    int numbers[size] = {9,8,5,6,7};
    selectionSort(numbers,size);
    cout<<"Sorted Array Content : ";
    for(int i=0;i<size;i++)
        cout<<numbers[i]<<"  ";
    cout<<endl;
    return 0;
}
