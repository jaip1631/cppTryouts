#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node * CreateNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

int getMax(int a, int b)
{
    return a > b ? a : b;
}

int diameterTree(Node *root, int &maxDiameter)
{
    if(root == NULL)
        return 0;
    
    int leftMaxHeight = 0, rightMaxHeight = 0;
    if(root->left)
        leftMaxHeight = diameterTree(root->left, maxDiameter);
    if(root->right)
        rightMaxHeight = diameterTree(root->right, maxDiameter);

    maxDiameter = getMax(maxDiameter, 1 + leftMaxHeight + rightMaxHeight);

    return 1 + getMax(leftMaxHeight, rightMaxHeight);
}

int main()
{
    int maxDiameter = 0;
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
    f.left = NULL;
    f.right = NULL;
    z.left = NULL;
    z.right = NULL;
    x.left = NULL;
    x.right = NULL;
    c.left = NULL;
    c.right = NULL;
    v.left = NULL;
    v.right = NULL;

    diameterTree(&e, maxDiameter);
    cout<<maxDiameter;
    return 0;
}