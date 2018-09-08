// https://practice.geeksforgeeks.org/problems/check-for-bst/1

#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

//Top Down Approach
bool isBSTUtilTopDown(Node *root, int min, int max) {
    if(!root)
        return true;
    
    if(root->data <= min || root->data >= max)
        return false;

    int leftRet = true, rightRet = true;
    if(root->left) {
        leftRet = isBSTUtilTopDown(root->left, min, root->data);
    }

    if(root->right && leftRet) {
        rightRet = isBSTUtilTopDown(root->right, root->data, max);
    }
    
    return (leftRet && rightRet);
}


struct RetData {
    int min, max;
    bool isBST;
};

int getMax(int a, int b) {
    return (a>b)?a:b;
}

int getMin(int a, int b) {
    return (a<b)?a:b;
}

RetData nullRet = {INT32_MAX, INT32_MIN, true};

RetData isBSTUtilBottomUp(Node *root) {
    if(!root)
        return nullRet;
    
    RetData leftRet = nullRet, rightRet = nullRet;

    if(root->left) {
        leftRet = isBSTUtilBottomUp(root->left);
    }
    if(root->right) {
        rightRet = isBSTUtilBottomUp(root->right);
    }

    RetData retData = nullRet;
    if(leftRet.isBST && rightRet.isBST && (root->data > leftRet.max && root->data < rightRet.min)) {
        retData.min = getMin(leftRet.min, root->data);
        retData.max = getMax(rightRet.max, root->data);
        return retData;
    }
    else {
        retData.isBST = false;
        return retData;
    }
}

bool isBST(Node *root) {
    //return isBSTUtilTopDown(root, INT32_MIN, INT32_MAX);
    return isBSTUtilBottomUp(root).isBST; 
}

int main(int argc, char const *argv[])
{
    
    return 0;
}