// https://www.geeksforgeeks.org/length-longest-palindrome-list-linked-list-using-o1-extra-space/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int getCommonPrefixLen(Node *a, Node *b)
{
    int count = 0;
    while (a && b && a->data == b->data)
    {
        count++;
        a = a->next;
        b = b->next;
    }

    return count;
}

int getMax(int a, int b)
{
    return a > b ? a : b;
}

int getLongestPalindromeInLinkedList(Node *head)
{
    int maxPalindromeLen = 0;

    if (!head)
        return maxPalindromeLen;

    maxPalindromeLen = 1;
    Node *reversed = NULL, *cur = head, *next = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = reversed;
        maxPalindromeLen = getMax(getMax(2 * getCommonPrefixLen(cur, next),
                                         1 + 2 * getCommonPrefixLen(cur->next, next)),
                                  maxPalindromeLen);

        reversed = cur;
        cur = next;
    }

    return maxPalindromeLen;
}

void printLinkedList(Node *root)
{
    while (root)
    {
        cout << root->data << "->";
        root = root->next;
    }
    cout << "NULL" << endl;
}

int main(int argc, char const *argv[])
{
    return 0;
}
