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
    void setNewNode(ListNode* curr, ListNode* newCurr, int carry){
        while(curr){
            int sum = curr->val + carry;
            if(sum > 9){
                carry = 1;
                sum = sum -10;
            }
            else{
                carry =0;
            }
            ListNode* newNode = new ListNode(sum);
            newCurr->next= newNode; 
            newCurr = newCurr->next;
            curr= curr->next;
        }
        if(carry)
            newCurr->next = new ListNode(carry);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        ListNode* newHead = nullptr;
        ListNode* newCurr = nullptr;
        int carry =0;

        while(c1 && c2){
            int sum = c1->val + c2->val + carry;
            if(sum > 9){
                carry = 1;
                sum = sum -10;
            }
            else{
                carry =0;
            }
            
            ListNode* newNode = new ListNode(sum);
            cout<<sum<<endl;
            if(!newHead ){
                newHead = newNode;
                newCurr = newNode;
                
            }
            else{
                newCurr->next= newNode; 
                newCurr = newCurr->next;
            }
            
            c1= c1->next;
            c2= c2->next;
        }
        if(!c1 && !c2){
            if(carry)
                newCurr->next = new ListNode(carry);
            
        }
        else if(!c1){
            setNewNode(c2, newCurr, carry);
        }
        else{
            setNewNode(c1, newCurr, carry);
        }
        return newHead;


        
    }
};
