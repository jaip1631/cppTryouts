#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void printVec(const vector<Node*> vec)
{
    for(unsigned i = 0; i < vec.size(); i++)
        cout<<vec[i]->data<<"->";
    cout<<"NULL"<<endl;
}

bool findNodePath(Node *root, int a, vector<Node *> &path)
{
    if(root == NULL)
        return false;
    
    path.push_back(root);

    if(root->data == a)
        return true;
    
    if(root->left && findNodePath(root->left, a, path) ||
        root->right && findNodePath(root->right, a, path))
        return true;
    
    path.pop_back();

    return false;
}

// bad implementation
void findNodePath(Node *root, int a, vector<Node *> &path, vector<Node*> curPath)
{
    if(root == NULL)
        return;
    
    if(!path.empty())
        return;

    curPath.push_back(root);

    if(root->data == a)
        path = curPath;

    if(root->left)
        findNodePath(root->left, a, path, curPath);
    
    if(root->right)
        findNodePath(root->right, a, path, curPath);
}

int findLCA_Vec(Node *root, int a, int b)
{
    int LCA = -1;
    vector<Node *> first, curFirst, second, curSecond;
    findNodePath(root, a, first);
    findNodePath(root, b, second);

    for(unsigned i = 0; i < first.size() && i < second.size() && first[i] == second[i]; i++)
        LCA = first[i]->data;

    return LCA;
}

Node * findLCAUtil(Node *root, int a, int b, Node *&left, Node *&right)
{
    if(root == NULL)
        return NULL;
    if(root->data == a)
    {
        left = root;
        return root;
    }
    if(root->data == b)
    {
        right = root;
        return root;
    }

    Node *fromLeft = NULL;
    Node *fromRight = NULL;

    fromLeft = findLCAUtil(root->left, a, b, left, right);
    fromRight = findLCAUtil(root->right, a, b, left, right);
    
    if(fromLeft && fromRight)
        return root;
    if(fromLeft)
        return fromLeft;
    return fromRight;
}

bool findNode(Node *root, int a)
{
    if(root == NULL)
        return false;
    
    if(root->data == a)
        return true;
    
    if(root->left && findNode(root->left, a) ||
        root->right && findNode(root->right, a))
        return true;
    
    return false;
}

int findLCA(Node *root, int a, int b)
{
    Node *leftLCA = NULL, *rightLCA = NULL;
    Node *LCA = findLCAUtil(root, a, b, leftLCA, rightLCA);

    if(leftLCA && rightLCA)
        return LCA->data;
    if(leftLCA && findNode(leftLCA, b))
        return leftLCA->data;
    if(rightLCA && findNode(rightLCA, a))
        return rightLCA->data;
    return -1;
}

int main(int argc, char const *argv[])
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

    cout<<findLCA(&e, 4,3)<<endl;
    return 0;
}
