#include<iostream>
#include<cstdlib>
using namespace std;
int count = 0;
class NoDisk{};
void Toh(int n,char a, char b, char c)
{
    if(n==1)
    {
        cout<<n<<" : "<<a<<" -> "<<c<<endl;
        count++;
    }
    else
    {
        count++;
        Toh(n-1,a,c,b);
        cout<<n<<" : "<<a<<" -> "<<c<<endl;
        Toh(n-1,b,a,c);
    }
}
int main()
{
    int nDisk;
    cout<<"How many disks ? : ";
    cin>>nDisk;
    cout<<"\nMovement of Nth disks is represented as"<<endl<<"N : source -> destination\n"<<endl;
    try
    {
        if(nDisk<=0)
            throw NoDisk();

        Toh(nDisk,'A','B','C');
    }
    catch(NoDisk)
    {
        cout<<"No any disk available to move."<<endl<<"Terminating Program."<<endl;
        exit(1);
    }
    cout<<endl<<"Required steps = "<<count<<endl<<endl;

    system("pause");
    return 0;
}
