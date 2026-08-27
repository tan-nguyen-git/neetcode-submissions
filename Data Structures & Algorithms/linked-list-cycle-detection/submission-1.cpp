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
    bool hasCycle(ListNode* head) {
        
        ListNode *f =head, *sl = head;

        while(f != nullptr && f->next != nullptr){
            
            sl = sl -> next;
            f = f -> next ->next;
            if(f == sl) return true;
        }

        return false;
    }
};
