// https://www.geeksforgeeks.org/connect-nodes-at-same-level/

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *nextRight;
};

void connectNodesAtSameLevel(Node *root)
{
    if(!root)
        return;

    queue<Node *> sameLevelNodes;
    Node *nextRight = NULL, *curNode = NULL;
    int curQueueSize = 0;

    sameLevelNodes.push(root);

    while (!sameLevelNodes.empty())
    {
        curQueueSize = sameLevelNodes.size();
        while (curQueueSize--)
        {
            curNode = sameLevelNodes.front();
            curNode->nextRight = nextRight;
            nextRight = curNode;

            if (curNode->right)
                sameLevelNodes.push(curNode->right);
            if (curNode->left)
                sameLevelNodes.push(curNode->left);
            sameLevelNodes.pop();
        }

        nextRight = NULL;
    }
}

int main(int argc, char const *argv[])
{
    Node
        a1,
        b1,
        c1,
        d1,
        a2,
        b2,
        c2,
        d2,
        e2,
        f2,
        g2;

    a1.data = 10;
    b1.data = 4;
    c1.data = 6;
    d1.data = 30;
    a1.left = &b1;
    a1.right = &c1;
    b1.left = NULL;
    b1.right = NULL;
    c1.left = &d1;
    c1.right = NULL;
    d1.left = NULL;
    d1.right = NULL;

    connectNodesAtSameLevel(&a1);
    return 0;
}
