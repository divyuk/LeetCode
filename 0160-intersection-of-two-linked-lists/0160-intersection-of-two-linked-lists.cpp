class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>s1;

        while(headA){
            s1.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(s1.find(headB)!=s1.end())
                return headB;
            headB=headB->next;
        }
        return NULL;
    }
};