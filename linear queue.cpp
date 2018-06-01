#include<iostream>
#include<cstdlib>
using namespace std;
const int len=5;

template <class T>
class Queue
{
private:
    T q[len];
    int Front, Rear;
public:
    Queue():Front(-1),Rear(-1) {}
    void enq(T data)
    {
        if(Front ==-1)
            Front += 1;
        if(Rear == len-1)
        {
            cout<<"Queue Overflow"<<endl;
            exit(1);
        }
        else
            q[++Rear] = data;
    }

    T deq()
    {
        if (Front == -1 || Front>Rear)
            {
                cout<<"Queue Underflow"<<endl;
                exit(1);
            }
        else
        {
            T temp = q[Front];
            Front += 1;
            return temp;
        }
    }

    T peek()
    {
        return q[Front];
    }
    isEmpty()
    {
        return (Front == -1);
    }
};

main()
{
    Queue<int> q;
    char ans;
    while(1)
    {
        int choice;
        cout<<"Work with Queue : "<<endl;
        cout<<"\t1.\tEnqueqe"<<endl;
        cout<<"\t2.\tDequeue"<<endl;
        cout<<"\t3.\tEmpty?"<<endl;
        cout<<"\t4.\tPeek?"<<endl<<endl<<"\t";
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                    int val;
                    cout<<"Enter the value to enqueue to Queue : ";
                    cin>>val;
                    q.enq(val);
                    break;
                }
            case 2:
                {
                    int k = q.deq();
                    cout<<"The dequeue operation successfull. The dequed value is "<<k<<endl;
                    break;
                }
            case 3:
                {
                    if(q.isEmpty())
                        cout<<"The stack is empty."<<endl;
                    else
                        cout<<"No, The stack isn't empty."<<endl;

                    break;
                }
            case 4:
                {
                    cout<<"Frontmost element is "<<q.peek()<<endl;
                    break;
                }
        }
        cout<<"\n Operate on the queue again? Supply any value for yes and 'n'/'N' for no : ";
        cin>>ans;
        if((ans='n') || (ans = 'N'))
            break;
        system("cls");
    }

    return 0;
}
