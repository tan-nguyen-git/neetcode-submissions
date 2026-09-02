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
    ListNode* mergeTwoSortedList(ListNode* first, ListNode* second){
        if(!first && !second) return nullptr;
        if(!first) return second;
        if(!second) return first;
        ListNode* res = nullptr;
        ListNode* currRes = nullptr;
        ListNode* currFirst = first;
        ListNode* currSecond = second;
        while(currFirst && currSecond){
            if(currFirst->val <= currSecond->val){
                if(!res){
                    res = currFirst;
                    currRes = res;
                }
                else{
                    currRes->next = currFirst;
                    currRes= currFirst;
                }
                currFirst= currFirst->next;
                
            
            }
            else{
                if(!res){
                    res = currSecond;
                    currRes = res;
                }
                else{
                    currRes->next = currSecond;
                    currRes = currSecond;
                }
                currSecond= currSecond->next;
               
            }
        }
        if(!currFirst && !currSecond) return res;
        else if(!currFirst){
            currRes->next = currSecond;
        }
        else if(!currSecond){
            currRes->next = currFirst;
        }
        return res;


    }
    //divided usually using left and right
    ListNode* divided(int left,int right,vector<ListNode*>& lists ){
        if(left == right){
            return lists[left];
        }
        int middle = (right-left)/2 + left;
        ListNode* leftHd = divided(left, middle, lists);
        ListNode* rightHd = divided(middle+1, right,lists);

        return mergeTwoSortedList(leftHd, rightHd);



        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //merge from the back of the array and using pop_back
        int sz = lists.size();
        //no list and only one element
        if(sz == 0) return nullptr;
        if(sz == 1) return lists.at(0);
        ListNode*res = divided(0,sz-1, lists);
        return res;
    }
};
