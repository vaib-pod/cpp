//138. copy list with random pointer 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertcopy(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* nextnode = temp->next;
            Node* newnode = new Node(temp->val);
            newnode->next = nextnode;
            temp->next = newnode;
            temp = nextnode;
        }
    }
    void connectrandom(Node* head){
        Node* temp = head;
        
        while(temp!=NULL){
            Node* copy = temp->next;
        if(temp->random){
            copy->random = temp->random->next;
        }
        else{
            copy->random = NULL;
        }
        temp = temp->next->next;}
    }
    Node* deepconnect(Node* head){
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while(temp!=NULL){
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp=temp->next;
        }
        return dummy->next;

    }
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        insertcopy(head);
        connectrandom(head);
        return deepconnect(head);  
    }
};
