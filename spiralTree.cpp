#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

void printSpiralLevelOrder(Node *root)
{
    if(root == NULL)
        return;

    stack<Node *> first, second;
    first.push(root);

    while(!first.empty() || !second.empty())
    {
        while(!first.empty())
        {
            Node *temp = first.top();
            first.pop();
            cout<<temp->data<<endl;
            if(temp->right)
                second.push(temp->right);
            if(temp->left)
                second.push(temp->left);
        }
        while(!second.empty())
        {
            Node *temp = second.top();
            second.pop();
            cout<<temp->data<<endl;
            if(temp->left)
                first.push(temp->left);
            if(temp->right)
                first.push(temp->right);
        }
    }
}

int main()
{
    Node e, s, f, z, x, c, v;
    e.data = 1;
    s.data = 2;
    z.data = 4;
    x.data = 5;
    f.data = 3;
    c.data = 6;
    v.data = 7;

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

    printSpiralLevelOrder(&e);
    cout<<endl;

    return 0;
}