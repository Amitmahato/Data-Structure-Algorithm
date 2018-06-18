#include<iostream>
#include<cstdlib>
using namespace std;
class Indexerr{};
template <class T>
class List
{
private:
    struct node
    {
        T info;
        node* next=NULL;
    };
    node *head,*tail;
public:
    List():head(NULL),tail(NULL){}

    ///find and return the position of the element
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

    ///return the size of the list i.e. no. of elements in list
    int size()
    {
        int len=0;
        node* temp = head;
        while(temp!=NULL)
        {
            ++len;
            temp = temp->next;
        }
        return len;
    }
    ///insertion operations
    void insertAt(int pos,T val)
    {
        node* cur = head;
        node* prev = cur;
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
            head = here;
            return;
        }
        else if(pos == size()+1)
        {
            tail->next = here;
            tail = here;
            return;
        }
        for(int i=1;i<pos;i++)
        {
            prev = cur;
            cur = cur->next;
        }
        here->next = prev->next;
        prev->next = here;
        return;
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
        node* cur = head;
        node* prev = cur;
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
            cur = head;
            head = head->next;
            delete cur;
            return val;
        }
        for(int i=1;i<pos;i++)
        {
            prev = cur;
            cur = cur->next;
        }
        if(pos==size())
        {
            val = tail->info;
            prev->next = NULL;
            tail = prev;
            delete cur;
            return val;
        }
        prev->next = cur->next;
        val = cur->info;
        delete cur;
        return val;
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
        node* cur = new node;;
        cur = head;
        cout<<"Data :"<<endl;
        while(cur!=NULL)
        {
            cout<<cur->info<<"\t";
            cur = cur->next;
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

    cout<<"Deleted data:"<<endl;
    cout<<l1.deleteEnd()<<endl;
    cout<<l1.deleteBefore(5.5)<<endl;
    cout<<l1.deleteAfter(3.3)<<endl;
    cout<<l1.deleteBeginning()<<endl;

    cout<<endl<<"Remaining ";
    l1.display();

    system("pause");
    return 0;
}
