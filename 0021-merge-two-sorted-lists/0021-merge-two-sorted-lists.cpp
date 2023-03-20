class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val > list2->val) swap(list1,list2);
        ListNode* res = list1;
        while(list1 and list2){
            ListNode* temp =  NULL;
            while(list1 and list1->val <= list2->val){
                temp = list1;
                list1=list1->next;
            }
            temp->next = list2;
            swap(list1,list2);
        }
        return res;
    }
};