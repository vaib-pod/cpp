//25. reverse nodes in k grp

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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* grpprev = dummy;
        while(true){
            ListNode* kth = kth_node(grpprev,k);
            if(!kth) break;

            ListNode* grpnext = kth->next;
            ListNode* prev = grpnext;
            ListNode* curr = grpprev->next;
            for(int i = 0  ; i < k ;i ++){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = grpprev->next;
            grpprev->next = kth;
            grpprev = temp;


        }
        return dummy->next;
    }
    ListNode* kth_node(ListNode* curr, int k){
        while(curr!= NULL && k>0){
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
