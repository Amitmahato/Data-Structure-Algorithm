#include<iostream>
#include<cstring>
#include<cstdlib>
#include<typeinfo>
#define maxsize 30
using namespace std;
int top=-1;
float s[maxsize];
void push(float *s,float val)
{
    if(top==maxsize-1)
    {
        cout<<"The Stack Is Full."<<endl;
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
int weight(char c)
{
    if(c == '+' || c == '-')
        return 0;
    else if(c == '*' || c=='/')
        return 1;
    else if (c=='$')
        return 2;
    else if (c=='(' || c==')')
        return 3;
    else if(c=='{' || c=='}')
        return 4;
    else if(c=='[' || c==']')
        return 5;
    else
        return -1;
}
int main()
{
    string infix,postfix;
    int infixlen;
    cin>>infix;
    for (string::size_type i=0; i< infix.size(); i++)
    {
        char c = infix[i];
        if(c=='+' || c=='-' || c=='*' || c=='/' || c=='$' || c=='(' || c==')')
        {
            if(empty(s))
                push(s,c);
            else
            {
                while(!empty(s))
                {
                    char stackelem;
                    stackelem = pop(s); //store the popped element of stack to push it back if below condition fails.
                    if(weight(stackelem) < weight(c))
                    {
                        push(s,stackelem);
                        push(s,c);
                        break;
                    }
                    else
                        postfix.push_back(stackelem);

                }
            }
        }
        else
            postfix.push_back(c);
    }

    cout<<postfix<<endl;
}
