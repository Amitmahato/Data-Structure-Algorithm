#include<iostream>
using namespace std;
template <class Type>
void bubbleSort(Type Ar[],int size)
{
    for(int round=1;round<size;round++)
    {
        for(int comp=0;comp<=size-1-round;comp++)
        {
            if(Ar[comp]>Ar[comp+1])
            {
                Type temp = Ar[comp];
                Ar[comp] = Ar[comp+1];
                Ar[comp+1] = temp;
            }
        }
    }
}
int main()
{
    int size = 5;
    int numbers[size] = {9,8,7,6,5};
    bubbleSort(numbers,size);
    cout<<"Sorted Array Content : ";
    for(int i=0;i<size;i++)
        cout<<numbers[i]<<"  ";
    cout<<endl;
    return 0;
}
