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
    ListNode* reverseLinkedList(ListNode* head){
        if(!head || !head->next) return head;

        ListNode * newHead = reverseLinkedList(head->next);
        //making the last element on the newly reversed linked list point to 
        //head, now head is the last node in the ll
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
   
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k ==1) return head;

        ListNode* newHead = nullptr;
        ListNode* prevGroupTail = nullptr;
        ListNode* curr = head;
        while(true){
            ListNode* kth = curr;
            for(int i = 1 ; i < k && kth; i ++){
                kth = kth->next;
            }
            if(!kth) break;
            ListNode* nextGroup = kth->next;
            //disconect the pointer to the next group
            kth->next = nullptr;
            
            ListNode* currHead = reverseLinkedList(curr);
            if(!newHead) newHead = currHead;
            if(prevGroupTail) prevGroupTail -> next = currHead;
            prevGroupTail = curr;
            curr = nextGroup;


        }
        if(prevGroupTail) prevGroupTail->next = curr;

        return newHead;

        
    }
};
