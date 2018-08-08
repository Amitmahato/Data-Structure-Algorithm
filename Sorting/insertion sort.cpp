#include<iostream>
using namespace std;
template <class T>
void insertionSort(T Ar[],int size)
{
    for(int i=1;i<size;i++)
    {
        T temp = Ar[i];
        int j = i-1;
        while(j>-1 && temp<Ar[j])
        {
            Ar[j+1] = Ar[j];
            Ar[j] = temp;
            j--;
        }
    }
}

int main()
{
    int size = 5;
    int numbers[size] = {9,8,5,6,7};
    insertionSort(numbers,size);
    cout<<"Sorted Array Content : ";
    for(int i=0;i<size;i++)
        cout<<numbers[i]<<"  ";
    cout<<endl;
    return 0;
}
