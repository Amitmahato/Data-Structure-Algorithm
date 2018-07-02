#include<iostream>
#include<cstdlib>
using namespace std;
template <class T>
class List
{
private:
    struct node
    {
        node* prev=NULL;
        T info;
        node* next=NULL;
    };
    node *head, *tail;
public:
    List():head(NULL),tail(NULL){}

    //find and return the position of the element
    int Find(T val)
    {
        int pos = 0;
        node* temp = head;
        while(temp!=NULL)
        {
            ++pos;
            if(temp->info == val)
                return pos;
            temp = temp->next;
        }
        return -1;
    }

    //return the size of the list i.e. no. of elements in list
    int size()
    {
        int len=0;
        node* temp;
        temp = head;
        while(temp!=NULL)
        {
            ++len;
            temp = temp->next;
        }
        return len;
    }

    //Insertion Operations
    void insertAt(int pos, T val)
    {
        node* cur = head;
        node* here = new node;
        here->info = val;
        if(pos == 1)
        {
            if(head == NULL)
            {
                head = here;
                tail = head;
                return;
            }
            here->next = head;
            head->prev = here;
            head = here;
            return;
        }
        else if(pos == size()+1)
        {
            tail->next = here;
            here->prev = tail;
            here->next = NULL;
            tail = here;
            return;
        }
        else
        {
            for(int i=1;i<pos;i++)
            {
                cur = cur->next;
            }
            here->prev = cur->prev;
            here->next = cur;
            (here->prev)->next = here;
            cur->prev = here;

            return;
        }
    }

    void insertAtBeginning(T newVal)
    {
        this->insertAt(1,newVal);
        return;
    }

    void insertAtEnd(T newVal)
    {
        this->insertAt(size()+1,newVal);
        return;
    }
    void insertBefore(T thisVal,T newVal)
    {
        int pos = Find(thisVal);
        if(pos>0)
            this->insertAt(pos,newVal);
        else
        {
            cout<<"Couldn't find "<<thisVal<<". Insertion of "<<newVal<<" failed."<<endl;
            return;
        }
    }

    void insertAfter(T thisVal,T newVal)
    {
        int pos = Find(thisVal);
        if(pos>0)
            this->insertAt(pos+1,newVal);
        else
        {
            cout<<"Couldn't find "<<thisVal<<". Insertion of "<<newVal<<" failed."<<endl;
            return;
        }
    }

    ///deletion operations
    T deleteAt(int pos)
    {
        T val;
        node* cur;
        cur = head;
        if(head == NULL)
        {
            cout<<"Empty list."<<endl;
            return -1;
        }
        else if(pos>size())
        {
            cout<<"Index Error. index > size of list."<<endl;
            return -1;
        }

        if(pos==1)
        {
            val = head->info;
            head = head->next;
            if(head!=NULL)
                head->prev = NULL;
            delete cur;
            return val;
        }
        if(pos==size())
        {
            val = tail->info;
            cur = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete cur;
            return val;
        }
        else
        {
            for(int i=1;i<pos;i++)
            {
                cur = cur->next;
            }
            val = cur->info;
            (cur->prev)->next = cur->next;
            (cur->next)->prev = cur->prev;
            delete cur;
            return val;
        }
    }

    T deleteBeginning()
    {
        return deleteAt(1);
    }

    T deleteEnd()
    {
        return deleteAt(size());
    }

    T deleteBefore(T thisVal)
    {
        int pos = Find(thisVal);
        if(pos>0)
            return deleteAt(pos-1);

        cout<<"There is no "<<thisVal<<". Deletion failure. ";
        return -1;
    }

    T deleteAfter(T thisVal)
    {
        int pos = Find(thisVal);
        if(pos>0)
            return deleteAt(pos+1);
        cout<<"There is no "<<thisVal<<". Deletion failure. ";
        return -1;
    }

    ///display contents
    void display()
    {
        node* temp = new node;
        temp = head;
        cout<<"Data:"<<"\t";
        while(temp!=NULL)
        {
            cout<<temp->info<<"\t";
            temp = temp->next;
        }
        cout<<endl<<endl;
    }
};
int main()
{
    List<float> l1;
    l1.insertAtBeginning(2.2);
    l1.insertAtBeginning(1.1);
    l1.insertAfter(2.2,3.3);
    l1.insertAt(4,5.5);
    l1.insertBefore(5.5,4.4);
    l1.insertAtEnd(7.7);
    l1.display();

    cout<<"Deleted data:"<<"\t";
    cout<<l1.deleteEnd()<<"\t";
    cout<<l1.deleteBefore(5.5)<<"\t";
    cout<<l1.deleteAfter(3.3)<<"\t";
    cout<<l1.deleteBeginning()<<"\t"<<endl;

    cout<<endl<<"Remaining ";
    l1.display();

    system("pause");
    return 0;
}


