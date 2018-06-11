#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node* next;
}*Front=NULL,*Rear=NULL;

void enQueue(int val)
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
    cout<<"Rear->data : "<<Rear->data<<endl<<"Rear->next : "<<Rear->next<<endl<<endl;
}
int deQueue()
{
    int val;
    if(Front == NULL)
    {
        cout<<"The queue is empty."<<endl;
        exit(1);
    }
    node *temp;
    temp = Front;
    val = temp->data;
    Front = Front->next;
    cout<<"Rear->data : "<<temp->data<<endl<<"Rear->next : "<<temp->next<<endl<<endl;
    delete temp;
    return val;
}
int peek()
{
    if(Front==NULL)
    {
        cout<<"The queue is empty. Terminating Program."<<endl;
        exit(1);
    }
    return Front->data;
}
int main()
{
    int choice,val;
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
                enQueue(val);
                break;
            }

        case 2:
            {
                cout<<"The dequeued element : "<<deQueue()<<endl;
                break;
            }

        case 3:
            {
                cout<<"The rearmost element : "<<peek()<<endl;
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
