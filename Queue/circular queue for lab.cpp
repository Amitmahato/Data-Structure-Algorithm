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
    void enQ(T data)
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

    T deQ()
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
    bool isEmpty()
    {
        return (Front == -1);
    }
};
int main()
{
    Queue<float> circularQ;
    for(float i=0;i<9;i++)
    {
        if(int(i)%4==0 || int(i)%4 == 1)
        {
            circularQ.enQ(5*i-5.0/2);
            cout<<"Enqueued element : "<<5*i-5.0/2<<endl;
        }
        else
            cout<<"Dequeued element : "<<circularQ.deQ()<<endl;
    }

    system("pause");
    return 0;
}
