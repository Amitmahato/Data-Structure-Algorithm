#include<iostream>
#include<cstdlib>
using namespace std;
class Empty{};
template <class T>
class node
{
private:
    T data;
    node* next;
    node* Front = NULL;
    node* Rear = NULL;

public:
    void enQueue(T val)
    {
        node* newNode;
        newNode = new node;
        newNode->data = val;
        newNode->next = NULL;
        if(Front == NULL)
        {
            Front = newNode;
            Rear = newNode;
        }
        else
        {
            Rear->next = newNode;
            Rear = newNode;
        }
    }
    T deQueue()
    {
        T val;
        if(Front == NULL)
        {
            cout<<"The queue is empty."<<endl;
            exit(1);
        }
        node *temp;
        temp = Front;
        val = temp->data;
        Front = Front->next;
        delete temp;
        return val;
    }
    T peek()
    {
        try
        {
            if(Front==NULL)
            {
                throw Empty();
            }
            return Front->data;
        }
        catch(Empty)
        {
            throw Empty();
        }
    }
};

int main()
{
    node<float> Queue;
    int choice;
    float val;
    char ans;
    do
    {
        cout<<"####\tMenu\t####"<<endl;
        cout<<"\t\t1. Enqueue"<<endl;
        cout<<"\t\t2. Dequeue"<<endl;
        cout<<"\t\t3. Peek"<<endl<<endl;
        cout<<"\t\tYour Choice : ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
        case 1:
            {
                cout<<"Enter value to enqueue : ";
                cin>>val;
                Queue.enQueue(val);
                break;
            }

        case 2:
            {
                cout<<"The dequeued element : "<<Queue.deQueue()<<endl;
                break;
            }

        case 3:
            {
                try
                {
                    cout<<"The rearmost element : "<<Queue.peek()<<endl;
                }
                catch(Empty)
                {
                    cout<<"The queue is empty."<<endl;
                }
                break;
            }
        }

        cout<<"Enter any character to operate again or 'n' to cancel : ";
        cin>>ans;
        system("cls");
    }while(ans!='n');


    system("pause");
    return 0;
}
