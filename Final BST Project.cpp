#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
class notFound{};
class duplicateValue{};
struct node
{
    int data ;
    node* left;
    node* right;
} ;
node * root,* par;

node* insertion(node * root,int d)
{
    try
    {
        if(root==NULL)
        {
            root=new node;
            root->data=d;
            root->left = root->right = NULL;
        }
        else if(d < root->data)
        {
            root->left = insertion(root->left,d);
        }
        else if(d> root->data)
        {
            root->right = insertion(root->right,d);
        }
        else
            throw duplicateValue();
    }
    catch(duplicateValue)
    {
        cout<<"The value already exist."<<endl<<"Insertion Failure."<<endl;
        return root;
    }
    return root;
}

node * searching(node* root, int val)
{
    try
    {
        if (root==NULL)
        {
            throw notFound();
        }
        else if (val<root->data)
        {
           par=root;
           searching(root->left,val);}
        else if(val>root->data)
       {
           par=root;
           searching(root->right,val);
        }
        else
            return root;
    }
    catch(notFound)
    {
        cout<<"Element doesn't exist in the tree."<<endl;
        return NULL;
    }
}

node * find_grtst( node* root)
{
    if (root == NULL)
        cout << "\n the tree is empty";
    else if ( root->right==NULL)
        return root;
    else
        return find_grtst(root->right);
}
node * find_smlst( node* root)
{
    if (root==NULL)
        cout << "\n the tree is empty";
    else if ( root->left==NULL)
        return root;
    else
        return find_smlst(root->left);
}
int height(node* root)
{
    if (root==NULL)
        return 0;
    else
        return max(height(root->left),height(root->right))+1;
}
int totalnode(node* root)
{
    if (root== NULL)
        return 0;
    else
        return totalnode(root->left)+totalnode(root->right)+1;
}
int int_node(node* root)
{
    if (root==NULL||(root->left==NULL&& root->right==NULL))
        return 0;
    else
        return (int_node(root->left)+int_node(root->right)+1);
}

//deletion of node from the BST
node* del_node(node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = del_node(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = del_node(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        node* temp = find_smlst(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = del_node(root->right, temp->data);
    }
    return root;
}

///Traversal of tree
void inorder(node* root)
{
     if(root)
     {
         inorder(root->left);
         cout<<root->data<<" ";
         inorder(root->right);
     }
}

void preorder(node* root)
{
     if(root)
     {
         cout<<root->data<<" ";
         preorder(root->left);
         preorder(root->right);
     }
}

void postorder(node* root)
{
     if(root)
     {
         postorder(root->left);
         postorder(root->right);
         cout<<root->data<<" ";
     }
}

void Traverse(node* root)
{
    int choice;
    cout<<"Type Of Traversal : \n";
    cout<<"\t1. Preorder Traversal\n";
    cout<<"\t2. Inorder Traversal\n";
    cout<<"\t3. Postorder Traversal\n";
    cout<<"\t4. All\n";
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Preorder Traversal : ";
        preorder(root);
        break;
    case 2:
        cout<<"Inorder Traversal : ";
        inorder(root);
        break;
    case 3:
        cout<<"Postorder Traversal : ";
        postorder(root);
        break;
    case 4:
        cout<<"Preorder Traversal: \t";
        preorder(root);
        cout<<endl<<"Inorder Traversal: \t";
        inorder(root);
        cout<<endl<<"Postorder Traversal: \t";
        postorder(root);
        break;
    default:
        cout<<"Wrong input."<<endl;
        break;
    }
}


int main()
{
int choice;
while(1)
{
    cout<<" \n \t \t \t *** BINARY SEARCH TREE ***";
    cout<< "\nMENU: \n";
    cout<<"\t 1. Insertion \n";
    cout<<"\t 2. Search \n";
    cout<<"\t 3. Deletion\n";
    cout<<"\t 4. Traversal\n";
    cout<<"\t 5. Greatest Node\n";
    cout<<"\t 6. Smallest Node \n";
    cout<<"\t 7. Height Of Tree \n";
    cout<<"\t 8. Total Number Of Nodes\n";
    cout<<"\t 9. Count Internal And External Nodes\n";
    cout<<"\t 10. Exit\n";
    cout<<"Enter your choice : ";
    cin>> choice;
    switch(choice)
    {
        case 1:
            int datum;
            char nam[20];
            cout<< "\nEnter your data:";
            cin>> datum;
            root = insertion(root,datum);
            break;
        case 2:
            int value;
            cout<<"\n Enter the key to be searched:";
            cin>> value;
            if(searching(root,value))
            {
                cout<<"\n Element found ::"<<searching(root,value)->data;
            }
            break;
         case 3:
            int del;
            cout<< "\n Enter the data to be deleted :: ";
            cin>> del;
            try
            {
                if(searching(root,del))
                {
                    root = del_node(root,del);
                    cout<<"Tree after deletion : "<<endl;
                    cout<<"Inorder Traversal: ";
                    inorder(root);
                }
                else
                    throw notFound();
            }
            catch(notFound)
            {
                cout<<"Deletion Failure.";
            }
            break;
         case 4:
            Traverse(root);
            break;
         case 5:
            cout<< "\n Element of greatest node ::"<<find_grtst(root)->data;
            break;
         case 6:
            cout<< "\n Element of smallest node ::"<<find_smlst(root)->data;
            break;
         case 7:
            cout << "\n The height of the tree ::"<<height(root);
            break;
         case 8:
            cout<< "\n The total no. of nodes ::"<< totalnode(root);
            break;
         case 9:
            cout<< "\n The no of internal nodes::"<< int_node(root);
            cout<< "\n The no of external nodes::"<< totalnode(root)-int_node(root);
            break;
         case 10:
            exit(0);
    }
    cout<<endl<<endl;
    system("pause");
    system("cls");
}
return 0;
}
