

Node* copy(Node* head) {
    if(head == NULL) {
        return NULL;
    }
    Node* ptr = head, *qtr=NULL;
    while(ptr != NULL) {
        qtr = ptr->next;
        Node* newNode = new Node(ptr->val);
        ptr->next = newNode;

        pre = ptr->next;
    }
}