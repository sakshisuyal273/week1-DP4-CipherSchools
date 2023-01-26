#include<iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * removeDuplicateNodes(ListNode * head) {
    if(head==NULL || head->next == NULL) {
        return head;
    }
    ListNode * curr =head, prev=NULL;
    while(curr->next != NULL) {
        if(curr->val == curr->next->val) {
            next = curr->next;
            curr->next=curr->next->next;
            delete (next);
        }
        else {
            curr=curr->next;
        }
    }
    return head;
}



//Remove duplicates from unsorted LL

#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	struct Node* next;
};

struct Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void removeDuplicates(struct Node* start)
{
	struct Node *ptr1, *ptr2, *dup;
	ptr1 = start;

	while (ptr1 != NULL && ptr1->next != NULL) {
		ptr2 = ptr1;

		while (ptr2->next != NULL) {
			if (ptr1->data == ptr2->next->data) {
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				delete (dup);
			}
			else /
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}


int main()
{
	struct Node* start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next = newNode(11);
	start->next->next->next->next->next->next = newNode(10);

	printf("Linked list before removing duplicates ");
	printList(start);

	removeDuplicates(start);

	printf("\nLinked list after removing duplicates ");
	printList(start);
	return 0;
}


//Rotate Linked List

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* rotate(Node* head, int k)
{
	
	Node* last = head;
	Node* temp = head;

	if (head == NULL || k == 0) {
		return head;
	}


	while (last->next != NULL) {
		last = last->next;
	}

	
	while (k) {

		
		head = head->next;

		
		temp->next = NULL;

		last->next = temp;
		last = temp;

		temp = head;
		k--;
	}

	return head;
}

void printList(Node* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

int main()
{
	Node* head = NULL;

	for (int i = 60; i > 0; i -= 10)
		push(&head, i);

	cout << "Given linked list \n";
	printList(head);
	head = rotate(head, 4);

	cout << "\nRotated Linked list \n";
	printList(head);
	return 1;
}



//Add two numbers

class ListNode {
    public:
        int val:
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}

};

ListNode* addTwoNubers(ListNode* a, ListNode* b) {
    if(a == NULL){
        return b;
    }
    else if(b == NULL) {
        return a;
    }
    else{
        ListNode dummy(0);
        ListNode* p=a, *q=b, *c=dummy;
        while(p!=NULL || q != NULL) {
            sum = (p==NULL ? 0 : p->val) + (q==NULL ? 0 : q->val) + carry;
            carry = sum/10;
            sum=sum%10;
            r->next = new ListNode(sum);
            r=r->next;

            if(p != NULL) p = p->next;
            if(q != NULL) q = q->next;
        }

        if(carry > 0) {
            r->next = new ListNode(carry);
        }
        return dummy.next;
    }
}





//generate Linked List copy


#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node* arbit;

	
	Node(int x)
	{
		this->val = x;
		this->next = NULL;
		this->arbit = NULL;
	}
};

Node* cloneLinkedList(Node* head)
{
	unordered_map<Node*, Node*> mp;
	Node *temp, *nhead;

	temp = head;
	nhead = new Node(temp->val);
	mp[temp] = nhead;

	while (temp->next != NULL) {
		nhead->next= new Node(temp->next->val);
			
		temp = temp->next;
		nhead = nhead->next;
		mp[temp] = nhead;
	}
	temp = head;

	while (temp != NULL) {
		mp[temp]->arbit = mp[temp->arbit];
		temp = temp->next;
	}

	return mp[head];
}

void printList(Node* head)
{
	cout << head->val << "("<< head->arbit->val << ")";

	head = head->next;
	while (head != NULL) {
		cout << " -> " << head->val << "("
			<< head->arbit->val << ")";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next= new Node(5);
		
	head->arbit = head->next->next;
	head->next->arbit = head;
	head->next->next->arbit= head->next->next->next->next;
		
	head->next->next->next->arbit= head->next->next;
		
	head->next->next->next->next->arbit= head->next;
		

	cout << "The original linked list:\n";
	printList(head);

	Node* sol = cloneLinkedList(head);

	cout << "The cloned linked list:\n";
	printList(sol);

	return 0;
}
