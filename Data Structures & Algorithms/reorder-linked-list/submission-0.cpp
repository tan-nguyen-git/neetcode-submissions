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
//the trick to this proplem is to reverse the ll then
//redo the link between them
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(!head || !head->next )return head;

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next= nullptr;
        return newHead;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        //slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow is new middle
        //reverse start from slow
        ListNode* startRev = reverse(slow->next); //rever slow next 
        slow->next = nullptr; //cut the ll into 2 half
        ListNode* curr = head;
        while(curr && startRev){
            ListNode* n = curr->next;
            ListNode* nSlow = startRev -> next;
            curr->next = startRev;
            curr=n;
            startRev->next = n;
            startRev = nSlow;

        }
        

        
        
    }
};
