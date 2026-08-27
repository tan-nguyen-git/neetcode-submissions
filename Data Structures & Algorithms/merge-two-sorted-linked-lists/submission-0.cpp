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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newhd = nullptr;
        ListNode* curr = nullptr;
        ListNode* curr1 = list1 , *curr2 = list2;
        if(curr1 == nullptr) return curr2;
        if(curr2 == nullptr) return curr1;
        while(curr1 != nullptr || curr2 != nullptr ){
            if(newhd == nullptr){
                if(curr1->val >= curr2->val){
                    newhd = curr2;
                    curr=curr2;
                    curr2 = curr2->next;
                }
                else{
                    newhd = curr1;
                    curr=curr1;
                    curr1 = curr1->next;
                }
            }
            if(curr1 == nullptr){
                curr->next = curr2;
                break;
            }
            if(curr2 == nullptr){
                curr->next = curr1;
                break;
            }
            if(curr1->val >= curr2->val){
                curr->next = curr2;
                curr = curr2;
                curr2 = curr2->next;
                
            }
            else{
                curr->next = curr1;
                curr= curr1;
                curr1 = curr1->next;
            }

        }
        return newhd;
    }
};
