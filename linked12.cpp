//148. sort lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private: 
    ListNode* middleNode(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;

    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* left = list1;
        ListNode* right = list2;
        ListNode* dummy = new ListNode(0,NULL);
        ListNode* temp = dummy;
        while(left && right){
            if(left->val <= right->val){
                temp->next = left;
                left=left->next;
            }
            else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if (left != NULL) {
            temp->next = left;
        }

        else if (right != NULL) {
            temp->next = right;
        }
        return dummy->next;

    }

public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* middle = middleNode(head);

        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoLists(left,right);
    }
};
