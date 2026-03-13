//61. Rotate list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        ListNode* tail = head;
        int len =1;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }
        if(k%len == 0){
            return head;
        }
        tail->next = head;
        k = k%len;
        int templen = len-k-1;
        ListNode* temp = head;
        for(int i = 0 ; i < templen; i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};
