#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* swapAltNodesRec(Node *root) {
    if(root == NULL || root->next == NULL)
        return root;
    
    Node *remaning = root->next->next;
    Node *newRoot = root->next;
    newRoot->next = root;
    root->next = swapAltNodesRec(remaning);
    return newRoot;
}

void printLinkedList(Node *root) {
    while(root) {
        cout<<root->data<<"->";
        root = root->next;
    }
    cout<<"NULL"<<endl;
}

int main(int argc, char const *argv[])
{
    Node a, b, c, d, e;
    a.data = 10;
    a.next = &b;
    b.data = 20;
    b.next = &c;
    c.data = 30;
    c.next = &d;
    d.data = 40;
    d.next = &e;
    e.data = 50;
    e.next = NULL;

    printLinkedList(swapAltNodesRec(&a));
    return 0;
}