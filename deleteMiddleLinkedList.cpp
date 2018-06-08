#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printList(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL\n";
}

void deleteMiddleLinkedList(Node *head)
{
    if(head == NULL)
        return;

    if(head->next == NULL)
    {
        delete head;
        return;   
    }

    Node *slow = head, *fast = head, *prev = NULL;
    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *temp = prev->next;
    prev->next = prev->next->next;
    delete temp;
}

void push(Node **head, int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

int main()
{
    Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);

    printList(head);
    deleteMiddleLinkedList(head);
    printList(head);
    return 0;
}