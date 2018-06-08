#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

int SumTree(Node *root)
{
    if(root == NULL)
        return 0;
    
    int leftSum =  SumTree(root->left);
    int rightSum = SumTree(root->right);

    int returnVal = root->data + leftSum + rightSum;
    root->data = leftSum + rightSum;

    return returnVal;
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

int main()
{
    Node e, s, f, z, x, c, v;
    e.data = 10;
    s.data = -2;
    z.data = 8;
    x.data = -4;
    f.data = 6;
    c.data = 7;
    v.data = 5;

    e.left = &s;
    e.right = &f;
    s.left = &z;
    s.right = &x;
    f.left = &c;
    f.right = &v;
    z.left = NULL;
    z.right = NULL;
    x.left = NULL;
    x.right = NULL;
    c.left = NULL;
    c.right = NULL;
    v.left = NULL;
    v.right = NULL;

    inOrder(&e);

    SumTree(&e);

    cout<<endl;
    inOrder(&e);

    return 0;
}