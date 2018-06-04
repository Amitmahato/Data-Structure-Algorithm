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
        if(((Rear + 1)%len) == Front)
        {
            cout<<"Queue Overflow"<<endl;
            exit(1);
        }
        else if(Front == -1 && Rear == -1)
            Front = 0;
        Rear = (Rear + 1)%len;
        q[Rear] = data;
    }

    T deq()
    {
        if (Front == -1)
            {
                cout<<"Queue Underflow"<<endl;
                exit(1);
            }
        else if(Front == Rear)
        {
            T temp = q[Front];
            Front = -1;
            Rear = -1;
            return temp;
        }
        T temp2 = q[Front];
        Front = (Front+1)%len;
        return temp2;
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
    Queue<float> q;
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
                    float val;
                    cout<<"\nEnter the value to enqueue to Queue : ";
                    cin>>val;
                    q.enq(val);
                    break;
                }
            case 2:
                {
                    float k = q.deq();
                    cout<<"The dequeue operation successfull. The dequed value is "<<k<<endl;
                    break;
                }

            case 3:
                {
                    if(q.isEmpty())
                        cout<<"The queue is empty."<<endl;
                    else
                        cout<<"No, The queue isn't empty."<<endl;

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
