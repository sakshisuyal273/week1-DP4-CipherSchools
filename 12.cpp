#include<iostream>
using namespacestd;

class ListNode {
    public :
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
    if(a == NULL) {
        return b;
    }
    else if(b==NULL) {
        return a;
    }
    else {
        ListNode* result = NULL;
        if(a->val <= b->val) {
           result = a;
           result->next = mergeTwoLists(a->next, b);
        }else {
            result=  b;
            result->next = mergeTwoLists(a, b->next);
        }
        return result;
    }
}

ListNode* mergeKSortedLL( vector<ListNode*> lists) {
    if(lists..size()==0) {
        return NULL;
    }
    else if(lists.size()==1) {
        return lists[0];
    }
    else {
        int last = lists.size()-1;
        while(last>0) {
            int i=0, j=last;
            while(i < j) {
                lists[i] = mergeTwoLists(lists[i], lists[j]);
                i++; j--;
                if(i>=j) {
                    last = j;
                }
            }
        }
        return lists[0];
    }
}

int main() {

}




//reverse linked list

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() { head = NULL; }

	void reverse()
	{
		Node* current = head;
		Node *prev = NULL, *next = NULL;

		while (current != NULL) {
			
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

int main()
{
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.reverse();

	cout << "\nReversed linked list \n";
	ll.print();
	return 0;
}



//cycle is there or not in linked list
#include<iostream>
using namespace std;

 bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow= slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }

        }
        return false;
    }



//Intersection of linked list

#include<iostream>
using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2  = headB;
        while(p1 != p2) {
            if(p1==NULL) {
                p1 = headB;
            }
            else {
                p1=p1->next;
            }
            if(p2==NULL){
                p2=headA;
            }
            else{
                p2=p2->next;
            }
        }
        return p1;
    }
