// https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printLinkedList(Node *root) {
    while(root) {
        cout<<root->data<<"->";
        root = root->next;
    }
    cout<<"NULL"<<endl;
}

Node* reverseLinkedListInGroup(Node *head, int groupSize)
{
    if(!head)
        return NULL;
    Node * reversed =  NULL, *next = NULL, *cur = head, *reversedTail = cur;
    for(int i = 0; cur != NULL && i < groupSize; i++)
    {
        next = cur->next;
        cur->next = reversed;
        reversed = cur;
        cur = next;
    }

    reversedTail->next = reverseLinkedListInGroup(cur, groupSize);
    return reversed;
}

int main(int argc, char const *argv[])
{
    Node a, b, c, d, e;
    a.data = 1;
    a.next = &b;
    b.data = 2;
    b.next = &c;
    c.data = 3;
    c.next = &d;
    d.data = 4;
    d.next = &e;
    e.data = 5;
    e.next = NULL;

    printLinkedList(reverseLinkedListInGroup(&a, 6));
    return 0;
}
