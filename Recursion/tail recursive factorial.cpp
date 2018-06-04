#include<iostream>
#include<cstdlib>
using namespace std;
class FloatVal{};
double tail(double n,double i)
{
    if(n<0)
    {
        cout<<"The factorial of negative number isn't possible."<<endl;
        exit(1);
    }
    else if(n==0)
        return i;
    else
        return tail(n-1, i*n);
}
double fact(double n)
{
    if(n==0 || n==1)
        return 1;
    else
        return tail(n,1);
}
int main()
{
    double num;
    cout<<"Enter a number : ";
    cin>>num;
    try
    {
        if(int(num) != num)
        {
            throw FloatVal();
        }
        cout<<"The factorial of "<<num<<" = "<<fact(num)<<endl;
    }
    catch(FloatVal)
    {
        cout<<"The factorial of float value isn't possible."<<endl;
        exit(1);
    }

    system("pause");
    return 0;
}

