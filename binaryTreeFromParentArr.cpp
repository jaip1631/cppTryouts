// https://www.geeksforgeeks.org/construct-a-binary-tree-from-parent-array-representation/

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *createTree(const vector<int> &parentVec)
{
    vector<Node *> refNodeVec(parentVec.size(), NULL);
    Node *root = NULL;
    for (int i = 0; i < parentVec.size(); i++)
    {
        if(refNodeVec[i] == NULL)
            refNodeVec[i] = newNode(i);

        if(parentVec[i] == -1)
        {
            root = refNodeVec[i];
            continue;
        }

        if(refNodeVec[parentVec[i]] == NULL)
            refNodeVec[parentVec[i]] = newNode(parentVec[i]);

        if(refNodeVec[parentVec[i]]->left == NULL)
            refNodeVec[parentVec[i]]->left = refNodeVec[i];
        else
            refNodeVec[parentVec[i]]->right = refNodeVec[i];
    }

    return root;
}

int main(int argc, char const *argv[])
{

    return 0;
}
