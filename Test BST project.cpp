#include<iostream>
#include<cstdlib>
using namespace std;
template <class dataType>
class BinarySearchTree
{
private:
    struct bstNode
    {
        dataType info;
        bstNode *leftChild = NULL;
        bstNode *rightChild = NULL;
    };
    bstNode* root;
    int nodes;
    class alreadyExist{};
public:
    BinarySearchTree():root(NULL),nodes(0){}
    bstNode* createNode()
    {
        ++nodes;
        return (new bstNode);
    }

    ///find existing data if it is present in the tree and return its rootAddress else return null
    bstNode* find(bstNode *rootAddress, dataType data)
    {
        if(rootAddress)
        {
            if(data<rootAddress->info)
                return(find(rootAddress->leftChild, data));
            else if(data>rootAddress->info)
                return(find(rootAddress->rightChild, data));

            return rootAddress;
        }
        else
            return NULL;
    }

    ///find maximum valued element in the tree
    dataType findmax()
    {
        return ((findmax(root))->info);
    }

    bstNode* findmax(bstNode* rootAddress)
    {
        bstNode* maxVal;
        if(rootAddress->rightChild==NULL)
            maxVal = root;
        else
        {
            findmax(rootAddress->rightChild);
        }
         return maxVal;
    }


    ///finding minimum value in the BST
    dataType findmin()
    {
        return findmin(root)->info;
    }
    bstNode* findmin(bstNode* rootAddress)
    {
        if(rootAddress == NULL)
            return NULL;
        else
        {
            if(rootAddress->leftChild == NULL)
                return NULL;
            else
                return findmin(rootAddress->leftChild);
        }
    }
    ///height or depth of the tree
    int heightOfBst()
    {
        return heightOfBst(root);
    }

    int heightOfBst(bstNode* rootAddress)
    {
        int leftHeight, rightHeight;
        if(rootAddress == NULL)
            return 0;
        else
        {
            leftHeight = heightOfBst(rootAddress->leftChild);
            rightHeight = heightOfBst(rootAddress->rightChild);
            if(leftHeight > rightHeight)
                return leftHeight+1;
            else
                return rightHeight+1;
        }
    }
    ///insertion of new data into the tree
    void insert(dataType data)
    {
        bstNode *temp=root, *newNode;

        if(root==NULL)
        {
            newNode = createNode();
            newNode->info = data;
            root=newNode;
        }
        else
        {
            try
            {
                newNode = this->find(root,data);
                if(newNode)
                    throw(alreadyExist());
                else
                {
                    newNode = createNode();
                    newNode->info = data;

                    while(temp != NULL)
                    {
                        if(newNode -> info<temp->info)
                        {
                            if(temp->leftChild == NULL)
                            {
                                temp->leftChild = newNode;
                                return;
                            }
                            temp = temp->leftChild;
                        }
                        else if(newNode->info > temp->info)
                        {
                            if(temp->rightChild == NULL)
                            {
                                temp->rightChild = newNode;
                                return;
                            }
                            temp = temp->rightChild;
                        }
                    }
                }
            }
            catch(alreadyExist)
            {
                cout<<"The data you tried to store in the tree already exist."<<endl;
                cout<<"Insertion failed."<<endl<<endl;
            }
        }
    }


    ///deletion of element from tree
    dataType Delete(dataType data)
    {
        nodes--;
        return ((Delete(data, root))->info);
    }
    bstNode* Delete(dataType data, bstNode* rootAddress)
    {
        bstNode *temp;
        if(rootAddress == NULL)
            cout<<"No such element found in the tree."<<endl;
        else if(data<rootAddress->info)
            rootAddress->leftChild = Delete(data,rootAddress->leftChild);
        else if(data>rootAddress->info)
            rootAddress->rightChild = Delete(data,rootAddress->rightChild);
        else    ///the element to be deleted is found in the tree
        {
            if(rootAddress->leftChild && rootAddress->rightChild)   ///incase the node has both child
            {
                temp = findmax(rootAddress->leftChild);
                rootAddress->info = temp->info;
                rootAddress->leftChild = Delete(rootAddress->info,rootAddress->leftChild);
            }
            else    ///incase rootAddress has one or none child
            {
                temp = rootAddress;
                if(rootAddress->leftChild == NULL && rootAddress->rightChild == NULL)
                    rootAddress = NULL;
                else if(rootAddress->leftChild == NULL)
                    rootAddress = rootAddress->rightChild;
                else if(rootAddress->rightChild == NULL)
                    rootAddress = rootAddress->leftChild;
                delete(temp);
                return rootAddress;
            }
        }

        return rootAddress;
    }

    ///Traversal of tree
    void Traverse()
    {
        cout<<"Nodes = "<<nodes<<endl;
        cout<<"Preorder Traversal : ";
        preorder(root);
        cout<<endl;

        cout<<"Inorder Traversal : ";
        inorder(root);
        cout<<endl;

        cout<<"Postorder Traversal : ";
        postorder(root);
        cout<<endl;
    }

private:
    void inorder(bstNode* root)
    {
         if(root)
         {
             inorder(root->leftChild);
             cout<<root->info<<" ";
             inorder(root->rightChild);
         }
    }

    void preorder(bstNode* root)
    {
         if(root)
         {
             cout<<root->info<<" ";
             preorder(root->leftChild);
             preorder(root->rightChild);
         }
    }

    void postorder(bstNode* root)
    {
         if(root)
         {
             postorder(root->leftChild);
             postorder(root->rightChild);
             cout<<root->info<<" ";
         }
    }

};

int main()
{
    BinarySearchTree<int> numbers;
    numbers.insert(9);
    numbers.insert(7);
    numbers.insert(8);
    numbers.insert(12);
    numbers.insert(3);
    numbers.insert(2);
    numbers.insert(15);

    numbers.Delete(15);
    numbers.Delete(2);

    numbers.Traverse();
    cout<<endl<<endl<<"Height of Binary Search Tree = "<<numbers.heightOfBst()<<endl;
    system("pause");
    return 0;
}
