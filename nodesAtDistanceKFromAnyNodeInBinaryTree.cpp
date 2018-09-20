// https://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef Node node;

struct Node {
    int data;
    Node *left, *right;
};

void fillNodesAtDistanceNFromRoot(Node* root, int n, vector<Node *> &result) {
    if(!root || n < 0)
        return;
    
    if(n == 0) {
        result.push_back(root);
        return;
    }

    if(root->left)
        fillNodesAtDistanceNFromRoot(root->left, n-1, result);
    if(root->right)
        fillNodesAtDistanceNFromRoot(root->right, n-1, result);
}

Node * findNodeAndFillAncestorStack(Node *root, Node* target, stack<Node*> &ancestorStack) {
    if(!root)
        return NULL;

    if(root == target)
        return root;
    
    ancestorStack.push(root);
    Node *found = NULL;
    if(root->left)
        found = findNodeAndFillAncestorStack(root->left, target, ancestorStack);
    if(!found && root->right)
        found = findNodeAndFillAncestorStack(root->right, target, ancestorStack);

    if(!found)
        ancestorStack.pop();
    
    return found;
}


void printVector(const vector<Node*> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i]->data << " ";
}

int fillNodesAtDistanceNFromANode(Node *root, Node* target, int n) {
    int distanceFromRoot = -1;
    stack<Node*> ancestorStack;
    vector<Node*> result; 
    Node * topNode, *curNode;
    if(findNodeAndFillAncestorStack(root, target, ancestorStack)) {
        fillNodesAtDistanceNFromRoot(target, n, result);
        curNode = target;
        if(!ancestorStack.empty())
            distanceFromRoot = ancestorStack.size();
        //cout<<"AncestorSize: "<<ancestorStack.size()<<endl;
        n--;
        while(!ancestorStack.empty()) {
            topNode = ancestorStack.top();
            if(n == 0) {
                result.push_back(topNode);
            }
            else {
                if(n >=1 && curNode == topNode->left)
                    fillNodesAtDistanceNFromRoot(topNode->right, n-1, result);
                else if(n >=1 && curNode == topNode->right)
                    fillNodesAtDistanceNFromRoot(topNode->left, n-1, result);    
            }
            
            curNode = topNode;
            n--;
            ancestorStack.pop();
        }
    }

    printVector(result);
    return distanceFromRoot;
}
