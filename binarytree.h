#include <iostream>
//Chun Wei Wang Lai
//
//----------------------------------------------------------------

using std::cout;
using std::endl;

class BSTree;
class Node
{
    private:
        int data;
        Node *left;
        Node *right;
    public:
        Node():data(0) , left(0) , right(0){};
        Node(int a):data(a) , left(0) , right(0){};
    friend class BSTree;
};

class BSTree
{
    private:
        Node *root;
    public:
        BSTree():root(0){};
        // BSTree(int a):root(0){};

        void Insert (int data);
        void Delete(int data);
        void Search(int data);
        Node* Inserting (Node* NowNode ,int data);
        Node* Searching (Node* NowNode ,int data);
        Node* Deleting (Node* NowNode ,int data);
        Node* FindRightMinNode(Node* NowNode);
            
};

void BSTree::Insert(int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
    }
    else
    {
        Inserting(root, data);
    }
}

Node* BSTree::Inserting(Node* NowNode, int data)
{
    if (NowNode == nullptr)
    {
        NowNode = new Node(data);
        return NowNode;
    }
    if (data < NowNode->data)
    {
        NowNode->left = Inserting(NowNode->left,data);
    }
    else if (data >= NowNode->data)
    {
        NowNode->right = Inserting(NowNode->right, data);
    }
    return NowNode;
}

void BSTree::Search(int data)
{
    if (root == nullptr)
        cout<<"the tree is empty"<<endl;
    else
        root = Searching(root, data);
}

Node* BSTree::Searching(Node* NowNode, int data)
{
    if (NowNode == nullptr)
    {
        cout << data << " is not in the tree "<<endl;
        return nullptr;
    }
    else if (data == NowNode->data)
    {
        cout<< data << " is in the tree"<<endl;
        return NowNode;
    }
    else if (data < NowNode->data)
        NowNode->left = Searching(NowNode->left,data);
    else if (data => NowNode->data)
        NowNode->right = Searching(NowNode->right,data);
    
}

void BSTree::Delete(int data)
{
    if (root == nullptr)
        cout<<"the tree is empty"<<endl;
    else
    {
        root = Deleting(root,data);
    }
    cout<<data<<" was removed!"<<endl;
}

Node* BSTree::Deleting(Node* NowNode, int data) 
{
    if (data < NowNode->data)
        NowNode->left = Deleting(NowNode->left,data);
    else if (data > NowNode->data)
        NowNode->right = Deleting(NowNode->right,data);
    else if (NowNode == nullptr)
    {
        cout << data << "is not in the tree "<<endl;
        return nullptr;
    }
    else
    {   // No child
        if (NowNode->left == nullptr && NowNode->right == nullptr)
        {
            delete NowNode;
            return nullptr;
        }
        // only right child
        else if (NowNode -> left == nullptr)
        {
            NowNode = NowNode->right;
        }
        // only left child
        else if  (NowNode -> right == nullptr)
        {
            NowNode = NowNode->left;
        }
        // two children
        else
        {   
            // the minimum value at right child three is bigger than the maximum value of left child tree
            Node* temp = FindRightMinNode(NowNode -> right);
            NowNode -> data = temp -> data;
            // kill the rightmin node
            NowNode->right = Deleting(NowNode->right, NowNode->data);
        }
        return NowNode;
    }
}

Node* BSTree::FindRightMinNode(Node* MinNode)
{
    while(MinNode -> left != nullptr)
    {
        MinNode = MinNode->left;
    }
    return MinNode;
}
