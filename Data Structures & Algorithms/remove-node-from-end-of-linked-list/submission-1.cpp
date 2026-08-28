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

   int findSz(ListNode* head){
    if(!head->next) return 1;
    return 1+findSz(head->next);
   }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
        int sz = findSz(head);
        cout<<sz<<endl;
        ListNode* curr = head;
        ListNode* toDel = head->next;
 
        int fromFront = sz-n;
        if(fromFront == 0 &&  sz >1){
            head = head -> next;
            return head;
        }
        while(fromFront>1 && toDel){
            fromFront--;
            curr = curr->next;
            toDel = toDel->next;
            cout<<head->val<<","<<toDel->val<<","<<n<<endl;

        }
        if(toDel){
             curr->next = toDel->next;
        }
        else{
            return nullptr;
        }
        
    
        return head;
        
    }
};
