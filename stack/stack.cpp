#include<iostream>
#include<cstdlib>
#define maxsize 20
using namespace std;
int top=-1;
void push(float *s,float val)
{
    if(top==maxsize-1)
    {
        cout<<"The Stack Is Full."<<endl;
        exit(1);
    }
    else
        s[++top]=val;
}
float pop(float *s)
{
    if(top==-1)
    {
        cout<<"The stack is empty"<<endl;
        exit(1);
    }
    else
        return s[top--];
}
bool empty(float *s)
{
    return (top==-1)?1:0;
}
int main()
{
    float S[maxsize];
    char ans;
    do
    {
        int choice;
        cout<<"Work with stack : "<<endl;
        cout<<"\t1.\tPush"<<endl;
        cout<<"\t2.\tPop"<<endl;
        cout<<"\t3.\tCheck for empty stack?"<<endl;
        cout<<"\t4.\tCheck the top value in the stack?"<<endl<<"\t";
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                    float val;
                    cout<<"Enter the value to push to stack : ";
                    cin>>val;
                    push(S,val);
                    break;
                }
            case 2:
                {
                    cout<<"The stack pop successfull. The popped value is "<<pop(S)<<endl;
                    break;
                }
            case 3:
                {
                    if(empty(S))
                        cout<<"The stack is empty."<<endl;
                    else
                        cout<<"No, The stack isn't empty."<<endl;

                    break;
                }
            case 4:
                {
                    cout<<"Stack["<<top<<"] = "<<S[top]<<endl;
                    break;
                }
        }
        cout<<"\n\t Operate on the stack again,y/n? ";
        cin>>ans;
        system("cls");
    }while(ans=='y' || ans =='Y');
    return 0;
}
