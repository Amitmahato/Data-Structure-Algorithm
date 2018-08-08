#include<iostream>
using namespace std;
template <class Type>
void bubbleSort(Type Ar[],int size)
{
    int flag;
    for(int round=1;round<size;round++)
    {
        flag = 0;
        for(int comp=0;comp<=size-1-round;comp++)
        {
            if(Ar[comp]>Ar[comp+1])
            {
                flag = 1;
                Type temp = Ar[comp];
                Ar[comp] = Ar[comp+1];
                Ar[comp+1] = temp;
            }
            if(flag == 0)
            {
                cout<<"Sorting completed in "<<round<<" rounds."<<endl;
                return;
            }
        }
    }
}
int main()
{
    int size = 5;
    int numbers[size] = {9,8,5,6,7};
    bubbleSort(numbers,size);
    cout<<"Sorted Array Content : ";
    for(int i=0;i<size;i++)
        cout<<numbers[i]<<"  ";
    cout<<endl;
    return 0;
}
