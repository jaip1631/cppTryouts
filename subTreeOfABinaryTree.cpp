//https://www.geeksforgeeks.org/check-binary-tree-subtree-another-binary-tree-set-2/

#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

void printVector(const vector<int> &vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

void fillInorder(Node *root, vector<int> &inorder) {
    if(!root)
        return;
    
    if(root->left)
        fillInorder(root->left, inorder);

    inorder.push_back(root->key);

    if(root->right)
        fillInorder(root->right, inorder);
}

void fillPreorder(Node *root, vector<int> &preorder) {
    if(!root)
        return;

    preorder.push_back(root->key);
    
    if(root->left)
        fillPreorder(root->left, preorder);

    if(root->right)
        fillPreorder(root->right, preorder);
}

void fillPrefixSuffixArray(const vector<int> &pattern, vector<int> &prefixSuffixArray) {
    for(int i = 0, j= 1; j < pattern.size();) {
        if(pattern[i] == pattern[j]) {
            prefixSuffixArray[j] = i+1;
            i++;
            j++;
        }
        else if(i == 0) {
            prefixSuffixArray[j] = 0;
            j++;
        }
        else {
            i = prefixSuffixArray[i-1];
        }
    }
}

bool containsSubstrKMP(const vector<int> &str, const vector<int> &pattern) {
    vector<int> prefixSuffixArray(pattern.size(), 0);
    fillPrefixSuffixArray(pattern, prefixSuffixArray);
    printVector(str);
    printVector(pattern);
    printVector(prefixSuffixArray);

    int i = 0, j = 0;
    for(; j < str.size() && i < pattern.size(); ) {
        if(pattern[i] == str[j]) {
            i++;
            j++;
        }
        else if(i == 0) {
            j++;
        }
        else {
            i = pattern[i-1];
        }
    }
    cout<<i<<" "<<pattern.size()<<endl;

    return i == pattern.size();
}

bool containsSubTree(Node *mainTree, Node *candidateTree) {
    vector<int> inorderCandTree, inorderMainTree, preorderCandTree, preorderMainTree;
    
    //fill inorder traversals
    fillInorder(candidateTree, inorderCandTree);
    fillInorder(mainTree, inorderMainTree);
    
    //fill preorder traversals
    fillPreorder(candidateTree, preorderCandTree);
    fillPreorder(mainTree, preorderMainTree);

    // printVector(inorderCandTree);
    // printVector(inorderMainTree);
    // printVector(preorderCandTree);
    // printVector(preorderMainTree);

    return containsSubstrKMP(inorderMainTree, inorderCandTree) && containsSubstrKMP(preorderMainTree, preorderCandTree);
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
    
    a1.key = 10;
    b1.key = 4;
    c1.key = 6;
    d1.key = 30;
    a1.left = &b1;
    a1.right = &c1;
    b1.left = NULL;
    b1.right = NULL;
    c1.left = &d1;
    c1.right = NULL;
    d1.left = NULL;
    d1.right = NULL;



    e2.key = 26;
    f2.key = 3;
    g2.key = 3;
    a2.key = 10;
    b2.key = 4;
    c2.key = 6;
    d2.key = 30;
    e2.left = &a2;
    e2.right = &f2;
    a2.left = &b2;
    a2.right = &c2;
    b2.left = NULL;
    b2.right = NULL;
    c2.left = &d2;
    c2.right = NULL;
    d2.left = NULL;
    d2.right = NULL;
    f2.left = NULL;
    f2.right = &g2;
    g2.left = NULL;
    g2.right = NULL;

    cout<<containsSubTree(&e2, &a1);
}
