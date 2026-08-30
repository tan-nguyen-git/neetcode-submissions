/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        std::map<Node*, Node*> m; 
        Node* newHead = new Node(head->val);
        m[head] = newHead;
       
        Node* newCurr = newHead;
        Node* curr = head->next;
        while(curr){
            newCurr->next = new Node(curr->val);
            newCurr = newCurr->next;
            m[curr] = newCurr;
            curr= curr->next;
        }
        newCurr->next =nullptr;
        // for(const auto& [node, random]: m){
        //     cout<<node->val<<",";
        //     if(!random){
        //         cout<<"null"<<endl;
        //     }
        //     else{
        //         cout<<random->val<<endl;
        //     }
        // }
        curr = head;
        newCurr = newHead;
        while(curr){
            newCurr->random = m[curr->random];
            curr=curr->next;
            newCurr= newCurr->next;
        }
        
        return newHead;

        
    }
};
