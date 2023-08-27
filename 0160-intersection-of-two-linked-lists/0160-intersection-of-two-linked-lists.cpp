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
        unordered_set<ListNode* > uset;
        
        //Filling in set
        
        while(headA){
            uset.insert(headA);
            headA=headA->next;
        }
        
        while(headB){
            if(uset.find(headB)!=uset.end()) return headB;
            headB=headB->next;
        }
        
        return NULL;
    }
};