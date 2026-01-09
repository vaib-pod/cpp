//160. Intersection of two linked lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0;
        int n2 = 0;
        ListNode* temp = headA;
        ListNode* temp2 = headB;
        while(temp || temp2){
            if(temp){
            n1++;
            temp = temp->next;
            }
            else{
               n2++;
            temp2 = temp2->next; 
            }
        }
    
        temp = headA;
        temp2 = headB;

        int diff = abs(n2-n1);
        if(n2>n1){
            while(diff--){
                temp2 = temp2->next;
            }
        }
        else{
            while(diff--){
                temp = temp->next;
            }
        }

        while(temp && temp2){
            if(temp == temp2) return temp;
            temp = temp->next;
            temp2 = temp2->next;
        }

        return NULL;

        
    }
};
