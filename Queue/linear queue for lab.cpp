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
            return q[Front++];
        }
    }

    T peek()
    {
        return q[Front];
    }
    bool isEmpty()
    {
        return (Front == -1);
    }
};
int main()
{
    Queue<float> linearQ;
    for(float i=0;i<3;i++)
    {
        linearQ.enq(5*i-5.0/2);
        cout<<"Enqueued element : "<<5*i-5.0/2<<endl;
    }
    for(int i=0;i<4;i++)
        cout<<"Dequeued element : "<<linearQ.deq()<<endl;

    system("pause");
    return 0;
}
