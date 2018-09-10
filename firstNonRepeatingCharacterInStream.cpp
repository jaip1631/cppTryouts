// https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
struct Node
{
    char ch;
    Node *prev, *next;
};
Node *firstNonRepQueue, *rear, **head_ref = &firstNonRepQueue;

void deleteDLL(Node *head)
{
    Node *temp;
    while (head)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
    firstNonRepQueue = NULL;
    rear = NULL;
}

void insertToDLL(char ch)
{
    Node *temp = new Node;
    temp->ch = ch;
    temp->next = NULL;
    temp->prev = NULL;

    if((*head_ref) == NULL)
    {
        firstNonRepQueue = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear->next->prev = rear;
        rear->next->next = NULL;
        rear = rear->next;
    }
}

void deleteFromDLL(Node *ptr)
{
    if(ptr->prev == NULL && ptr->next == NULL)
    {
        firstNonRepQueue = NULL;
        rear = NULL;
    }
    else if(ptr->prev == NULL)
    {
        firstNonRepQueue = ptr->next;
        firstNonRepQueue->prev = NULL;
    }
    else if(ptr->next == NULL)
    {
        rear = ptr->prev;
        ptr->prev->next = NULL;
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }

    delete ptr;
}

int main(int argc, char const *argv[])
{
    int testCase = 1, arrSize;
    char ch;
    unordered_map<char, Node *> mapToItr;
    unordered_set<char> removedChar;
    Node *itr;

    vector<char> arr;
    arrSize = arr.size();
    cin >> testCase;
    while (testCase--)
    {
        mapToItr.clear();
        deleteDLL(firstNonRepQueue);
        removedChar.clear();
        cin >> arrSize;
        for (int i = 0; i < arrSize; i++)
        {
            cin >> ch;
            if (removedChar.find(ch) == removedChar.end() && mapToItr.find(ch) == mapToItr.end())
            {
                insertToDLL(ch);
                itr = rear;
                mapToItr.insert(make_pair(ch, itr));
            }
            else if (removedChar.find(ch) == removedChar.end())
            {
                itr = mapToItr[ch];
                mapToItr.erase(ch);
                deleteFromDLL(itr);
                removedChar.insert(ch);
            }
            if (rear == NULL)
                cout << "-1 ";
            else
                cout << firstNonRepQueue->ch << " ";
        }
        cout << endl;
    }
    return 0;
}
