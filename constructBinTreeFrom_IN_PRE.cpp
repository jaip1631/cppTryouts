#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node *CreateNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *constructTreeFrom_IN_PRE(int *IN, int *PRE, int &i_pre, int left, int right)
{
    if(left > right)
        return NULL;
    
    Node * root = CreateNode(PRE[i_pre]);
    int i_in;
    for(i_in = left; i_in <= right; i_in++)
    {
        if(IN[i_in] == PRE[i_pre])
            break;
    }

    i_pre++;
    root->left = constructTreeFrom_IN_PRE(IN, PRE, i_pre, left, i_in-1);
    root->right = constructTreeFrom_IN_PRE(IN, PRE, i_pre, i_in+1, right);
    
    return root;
}

void inOrder(Node *root)
{
    if(root != NULL)
    {
        if(root->left)
            inOrder(root->left);
        cout<<root->data<<" ";
        if(root->right)
            inOrder(root->right);
    }
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        if(root->left)
            preOrder(root->left);
        if(root->right)
            preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if(root != NULL)
    {
        if(root->left)
            postOrder(root->left);
        if(root->right)
            postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    int IN[] = {5, 7, 12, 10, 15, 20};
    int PRE[] = {10, 5, 12, 7, 20, 15};
    int i_pre = 0;
    Node *root = constructTreeFrom_IN_PRE(IN, PRE, i_pre, 0, 5);
    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    return 0;
}