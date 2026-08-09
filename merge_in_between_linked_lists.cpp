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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1 ;
        for(int i = 0 ; i < a-1 ; i ++){
            temp = temp->next;
        }
        ListNode* anode = temp;
        for(int i = a-1 ; i <=b ; i ++){
            temp = temp->next;
        }
        ListNode* bnode = temp;
        anode->next = list2;
        ListNode* temp2 = list2;
        while(temp2->next){
            temp2 = temp2->next;
        }
        temp2->next = bnode;
        return list1;
    }
};