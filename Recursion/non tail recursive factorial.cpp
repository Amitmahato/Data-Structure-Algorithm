#include<iostream>
#include<cstdlib>
using namespace std;
class FloatVal{};
class NegativeVal{};
double fact(double n)
{
    if(n==1 || n==0)
        return 1;
    else
        return n*fact(n-1); //non tail since fact(n-1) is the recursive part but the last statement isn't just the recursive call but also the n as n*fact(n-1)
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
        else if(num<0)
            throw NegativeVal();

        cout<<"The factorial of "<<num<<" = "<<fact(num)<<endl;
    }
    catch(FloatVal)
    {
        cout<<"The factorial of float value isn't possible."<<endl;
        exit(1);
    }
    catch(NegativeVal)
    {
        cout<<"The factorial of negative value isn't possible."<<endl;
        exit(1);
    }

    system("pause");
    return 0;
}
