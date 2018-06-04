#include<iostream>
#include<cstdlib>
using namespace std;
class ERROR_ZERO{};
int fibo(int n)
{
    if(n==1 || n==2)
        return 1;
    else
        return fibo(n-2)+fibo(n-1); //non-tail since addition of two recursive fibo() function is done as the last statement while returning instead of just returning recursive statement.
}
int main()
{
    int num=0;
    cout<<"Enter the number of terms : ";
    cin>>num;
    try
    {
        if(num==0)
        {
            throw ERROR_ZERO();
        }
        else
        {
            for(int i=1;i<=num;i++)
                cout<<fibo(i)<<"\t";
        }
        cout<<endl;
    }
    catch(ERROR_ZERO)
    {
        cout<<"There exist no fibonacci series for zero terms."<<endl<<"Terminating Program."<<endl;
        exit(1);
    }

    return 0;
}
