#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

void splitList(struct node* source, struct node** frontRef, struct node** backRef)
{
    if(source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
    
    node *slow = source, *fast = source;
    while(fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// merges two sorted list into one big list
struct node* mergeList(struct node* left, struct node* right)
{
    node *result = NULL;
	node **resultHead = &result;

	while(left && right)
	{
		if(left->data < right->data)
		{
			*resultHead = left;
			left = left->next;
		}
		else
		{
			*resultHead = right;
			right = right->next;
		}
		resultHead = &((*resultHead)->next);
	}

	if(left)
		*resultHead = left;
	if(right)
		*resultHead = right;

	return result;
}

void mergeSort(struct node** headRef)
{
    struct node* head = *headRef;
    struct node* a, *b;
    if ((head == NULL) || (head->next == NULL))
       return;
    splitList(head, &a, &b); 
    mergeSort(&a);
    mergeSort(&b);
    *headRef = mergeList(a, b);
}

node *reachLastNode(node *head){
    if(head == NULL)
        return NULL;
    while(head->next != NULL){
        head = head->next;
    }
    return head;
}

node* batch(node* head, int size){
    node* temp = head;
    node* root = NULL;
    node* start, *end, *nodeNahiPata, *prev;
    start = end = NULL;
    while(temp != NULL){
        int k = size;
        start = end = temp;
        while(k > 1 && end != NULL){
            k--;
            end = end->next;
        }
        if(end == NULL)
            temp = NULL;
        else{
            temp = end->next;
            end->next = NULL;
        }
        mergeSort(&start);
		nodeNahiPata = start;
        if(root == NULL)
            root = nodeNahiPata;
		else
			prev->next = nodeNahiPata;
        nodeNahiPata = reachLastNode(nodeNahiPata);
		prev = nodeNahiPata;
        nodeNahiPata->next = temp;
    }
    return root;
}

node *batchRec(node *head, int batchSize)
{
	if(head == NULL || head->next == NULL)
		return head;
	node *temp = head;
	node *restSorted = NULL;
	int i;
	for(i = 0; i < batchSize-1 /*&& temp != NULL*/ && temp->next != NULL; i++)
	{
		temp = temp->next;
	}
	
	if(i == batchSize-1)// && temp != NULL)
	{
		restSorted = batchRec(temp->next, batchSize);
		temp->next = NULL;
		mergeSort(&head);
		node *last = reachLastNode(head);
		last->next = restSorted;
		return head;
	}

	mergeSort(&head);
	return head;
}

void printNodes(node *head)
{
	while(head)
	{
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL\n";
}

int main()
{
	node a, b, c, d, e, f, g, h;
	a.data = 20;
	b.data = 40;
	c.data = 10;
	d.data = 30;
	e.data = 60;
	f.data = 50;
	g.data = 80;
	h.data = 70;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;
	h.next = NULL;
	
	node *temp = &a;
	printNodes(&a);
	//mergeSort(&temp);
	temp = batchRec(&a, 3);
	//sorted = sortBatch(&a, 10);
	printNodes(temp);
	cin.get();
	return 0;
}
