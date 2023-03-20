class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        
        ListNode* merged = nullptr;
        ListNode* tail = nullptr;
        
        while (list1 && list2) {
            ListNode* smallerNode = nullptr;
            
            if (list1->val <= list2->val) {
                smallerNode = list1;
                list1 = list1->next;
            } else {
                smallerNode = list2;
                list2 = list2->next;
            }
            
            if (!merged) {
                merged = smallerNode;
                tail = smallerNode;
            } else {
                tail->next = smallerNode;
                tail = smallerNode;
            }
        }
        
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;
        
        return merged;
    }
};
