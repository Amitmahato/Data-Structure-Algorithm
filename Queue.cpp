#include<iostream>
#include<cstdlib>
using namespace std;
const int len=5;

template <class T>
class Queue
{
public:
    virtual void enQ(T data) = 0;
    virtual T deQ() = 0;
    virtual T peek() = 0;
    virtual int isEmpty() = 0;
    virtual void reset() = 0;
};

template <class T=int>
class LinearQueue : public Queue<T>
{
private:
    T q[len];
    int Front, Rear;

public:
    LinearQueue():Front(-1),Rear(-1) {}
    void enQ(T data)
    {
        if(Front == -1)
            Front += 1;
        if(Rear == len-2)
            cout<<"\tWarning! This is the last element you added. The queue is full now."<<endl<<endl;
        if(Rear == len-1)
        {
            cout<<"Queue Overflow"<<endl;
            exit(1);
        }
        else
            q[++Rear] = data;
    }

    T deQ()
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

    int isEmpty()
    {
        return (Front == -1);
    }
    void reset()
    {
        Front = -1;
        Rear = -1;
    }
};

template <class T=int>
class CircularQueue : public Queue<T>
{
private:
    T q[len];
    int Front, Rear;
public:
    CircularQueue():Front(-1),Rear(-1) {}
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
    int isEmpty()
    {
        return (Front == -1);
    }
    void reset()
    {
        Front = -1;
        Rear = -1;
    }
};
void menu()
{
        cout<<"\t1.\tEnqueqe"<<endl;
        cout<<"\t2.\tDequeue"<<endl;
        cout<<"\t3.\tEmpty?"<<endl;
        cout<<"\t4.\tPeek?"<<endl<<endl<<"\t";
}
template <class T>
void makEasy(T &q,int choice)
{
    switch(choice)
    {
    case 1:
        {
            float val;
            cout<<"\nEnter the value to enqueue to Queue : ";
            cin>>val;
            q.enQ(val);
            break;
        }
    case 2:
        {
            float k = q.deQ();
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
}

int main()
{
    LinearQueue<int> linearQ;
    CircularQueue<int> circularQ;

    while(1)
    {
        char againQ;
        int chooseQ;

        cout<<"Work with Queue : "<<endl;
        cout<<"\t1.\tLinear Queue"<<endl;
        cout<<"\t2.\tCircular Queue"<<endl<<endl<<"\t";
        cin>>chooseQ;
        cout<<endl<<endl;
        switch(chooseQ)
        {
            case 1:
                {
                    while(1)
                    {
                        int subQ;
                        char again;
                        cout<<"Working Queue : Linear Queue"<<endl;
                        menu();
                        cin>>subQ;
                        switch(subQ)
                        {
                        case 1:
                            makEasy(linearQ,1);
                            break;
                        case 2:
                            makEasy(linearQ,2);
                            break;
                        case 3:
                            makEasy(linearQ,3);
                            break;
                        case 4:
                            makEasy(linearQ,4);
                            break;
                        }
                        cout<<"Work with Linear Queue more y/n? : ";
                        cin>>again;
                        if((again == 'n') || (again == 'N'))
                            break;

                        system("cls");
                    }
                    break;
                }
            case 2:
                {
                    while(1)
                    {
                        int subQ;
                        char again;
                        cout<<"Working Queue : Circular Queue"<<endl;
                        menu();
                        cin>>subQ;
                        switch(subQ)
                        {
                        case 1:
                            makEasy(circularQ,1);
                            break;
                        case 2:
                            makEasy(circularQ,2);
                            break;
                        case 3:
                            makEasy(circularQ,3);
                            break;
                        case 4:
                            makEasy(circularQ,4);
                            break;
                        }
                        cout<<"Work with Circular Queue more y/n? : ";
                        cin>>again;
                        if((again == 'n') || (again == 'N'))
                            break;

                        system("cls");
                    }
                    break;
                }

        cout<<"Work with another queue, y/n? : ";
        cin>>againQ;
        if((againQ == 'n') || (againQ == 'N'))
            break;
        }
        system("cls");

    }
    system("cls");
    return 0;
}
