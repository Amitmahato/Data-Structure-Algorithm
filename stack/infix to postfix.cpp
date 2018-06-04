#include <iostream>
#include<cstdlib>
#include <string>
using namespace std;

const int SIZE = 100;
class FULL{};
class EMPTY{};
template <class T>
class Stack
{
    private:
        T data[SIZE];
        int top;
    public:
        Stack():top(-1){}
        bool isEmpty() {return (top==-1);}
        bool isFull() {return (top==SIZE-1);}
        void push(T n)
        {
            if(top >= SIZE -1 )
            {
                cout << "Stack Overflow!!!!" << endl;
                throw FULL();
            }
            else
                data[++top] = n;
        }

        T pop()
        {
            if(top <= -1)
            {
                cout << "Stack Underflow!!!!" << endl;
                throw EMPTY();
            }
            else
                return data[top--];
        }

        T peek()
        {
            if(top <= -1)
            {
                cout << "Stack Underflow!!!!" << endl;
                throw EMPTY();
            }
            else
                return data[top];
        }
};

//char of operator to order int:
//3 for $
//2 * /
//1 + -
int weight(char c)
{
    switch(c)
    {
        case '$':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
    }
}


int main()
{
    string infix, postfix = "";
    cout << "Infix Expression : ";
    cin >> infix;
    Stack<char> s;
    try
    {
        for(int i = 0; i < infix.length(); i++)
        {
            if(infix[i]==' ')
                continue;
            else if(infix[i]!='+' && infix[i]!='-' && infix[i]!='*' && infix[i]!='/' && infix[i]!='$'&& infix[i]!='(' && infix[i]!=')' )
            {
                postfix.push_back(infix[i]);
            }
            else if(infix[i]=='(') s.push(infix[i]);
            else if(infix[i]==')')
            {
                while(s.peek()!='(')
                    postfix.push_back(s.pop());
                s.pop();
            }
            //if scanned char is operator
            else
            {
                if(s.isEmpty())
                    s.push(infix[i]);
                else
                {
                    char c_peek=s.peek();
                    char c_scan = infix[i];
                    int i_peek = weight(c_peek), i_scan = weight(c_scan);
                    if(c_peek!='+' && c_peek!='-'&& c_peek!='*'&& c_peek!='/'&& c_peek!='$')
                        s.push(infix[i]);
                    else
                    {
                        if(i_scan > i_peek)
                        {
                            s.push(c_scan);
                        }
                        else
                        {
                            while(!s.isEmpty() && s.peek()!='(' && weight(s.peek())>=i_scan)
                            {
                                postfix.push_back(s.pop());
                            }
                            s.push(c_scan);
                        }
                    }
                }
            }

        }
        while(!s.isEmpty())
            postfix.push_back(s.pop());
        cout << postfix << endl;
    }
    catch(FULL)
    {
        cout << "Try a shorter expression. Terminating the program" << endl;
    }
    catch(EMPTY)
    {
        cout << "Stack empty. Is the expression correct? Terminating the program" << endl;
        cout << postfix << endl;
    }

    system("pause");
    return 0;
}
