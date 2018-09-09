#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node *next, *arb;
};

// using map 4 traversals. Array can also be used as we are storing and reading in a sequence
Node* cloneLinkedListWithRandomPointer_1(Node *mainList) {
    unordered_map<Node*, Node*> randomPointerMap;

    Node *headMain = mainList, *permHeadClone = NULL, **ppHeadClone = &permHeadClone, *tempHeadClone;

    while(headMain) {
        (*ppHeadClone) = new Node;
        (*ppHeadClone)->data = headMain->data;
        (*ppHeadClone)->next = NULL;
        (*ppHeadClone)->arb = headMain->arb;
        ppHeadClone = &((*ppHeadClone)->next);
        headMain = headMain->next;
    }

    //make mainList arb point to equivalent down cloneList pointer
    headMain = mainList;
    tempHeadClone = permHeadClone;
    while(headMain) {
        randomPointerMap.insert(make_pair(headMain, headMain->arb));
        headMain->arb = tempHeadClone;
        headMain = headMain->next;
        tempHeadClone = tempHeadClone->next;
    }

    //fix arb pointer of cloneList
    tempHeadClone = permHeadClone;
    while(tempHeadClone) {
        if(tempHeadClone->arb)
            tempHeadClone->arb = tempHeadClone->arb->arb;
        tempHeadClone = tempHeadClone->next;
    }

    //fix arb pointer of mainList
    headMain = mainList;
    while(headMain) {
        headMain->arb = randomPointerMap[headMain->arb];
        headMain = headMain->next;
    }

    return permHeadClone;
}

// Constant extra space. Insert clone node in middle of original linked list nodes
Node* cloneLinkedListWithRandomPointer_2(Node *mainList) {
    Node *tempNode = NULL, *headMainList = mainList, *headCloneList, *tempHeadCloneList;

    while(headMainList) {
        tempNode = headMainList->next;
        headMainList->next = new Node;
        headMainList->next->data = headMainList->data;
        headMainList->next->arb = NULL;
        headMainList->next->next = tempNode;
        headMainList = tempNode;
    }

    headMainList = mainList;
    while(headMainList) {
        headMainList->next->arb = (headMainList->arb)?headMainList->arb->next:NULL;
        headMainList =  headMainList->next->next;
    }

    headMainList = mainList;
    headCloneList = headMainList->next;
    tempHeadCloneList = headCloneList;
    while(headMainList) {
        headMainList->next = tempHeadCloneList->next;
        headMainList = headMainList->next;
        if(headMainList) {
            tempHeadCloneList->next = headMainList->next;
            tempHeadCloneList = headMainList->next;
        }
        else {
            tempHeadCloneList->next = NULL;
        }
    }

    return headCloneList;
}

//using map
Node* cloneLinkedListWithRandomPointer_3(Node *mainList) {
    unordered_map<Node*, Node*> mainToCloneNodeMap;
    Node *mainHead = mainList, *tempNode = NULL;
    
    while(mainHead) {
        tempNode = new Node;
        tempNode->data = mainHead->data;
        tempNode->next = NULL;
        tempNode->arb = NULL;
        
        mainToCloneNodeMap.insert(make_pair(mainHead, tempNode));
        mainHead = mainHead->next;
    }

    mainHead = mainList;
    while(mainHead) {
        mainToCloneNodeMap[mainHead]->next = mainToCloneNodeMap[mainHead->next];
        mainToCloneNodeMap[mainHead]->arb = mainToCloneNodeMap[mainHead->arb];
        mainHead = mainHead->next;
    }

    mainHead = mainList;
    return mainToCloneNodeMap[mainHead];
}

void printLinkedList(Node *root) {
    while(root) {
        cout<<"("<<root->arb<<",";
        if(root->arb)
            cout<<root->arb->data;
        else
            cout<<"---";
        cout<<")"<<" -> ";
        root = root->next;
    }
    cout<<"NULL"<<endl;
}

main(int argc, char const *argv[])
{
    Node a, b, c, d;
    a.data = 10;
    b.data = 20;
    c.data = 30;
    d.data = 40;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;

    a.arb = &c;
    b.arb = &b;
    c.arb = NULL;
    d.arb = &a;

    printLinkedList(&a);
    printLinkedList(cloneLinkedListWithRandomPointer_3(&a));
    return 0;
}
