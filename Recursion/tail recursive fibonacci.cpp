#include<iostream>
#include<cstdlib>
using namespace std;
class ZeroTerm{};
int tail(int n, int a=1, int b=1)
{
    if(n>2)
    {
        int c = a;
        a = b;
        b = c+a;
        return tail(n-1,a,b);
    }
    return b;
}
int fibo(int n)
{
    if(n==1 || n==2)
        return 1;

    return tail(n);
}

int main()
{
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    try
    {
        if(num<1)
            throw ZeroTerm();

        for(int i=1;i<=num;i++)
            cout<<fibo(i)<<"\t";
    }
    catch(ZeroTerm)
    {
        cout<<"The fibonacci series for number of terms < 1, doesn't exist."<<endl;
        exit(1);
    }
}
