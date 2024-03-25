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
// Bubble sort will lead to TLE hence applying Merge Sort
class Solution {
public:
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* list1 , ListNode* list2){
        ListNode* tail = new ListNode(); // Initialize tail properly
        ListNode* dummy = tail;
        while(list1 and list2){
            if(list1->val < list2->val){
                tail->next = list1;
                list1=list1->next;
            }
            else{
                tail->next = list2;
                list2=list2->next;
            }
            tail = tail->next;
        }
        
        if(list1) tail->next =list1;
        if(list2) tail->next = list2;
        return dummy->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        // e.g. 1->2->3->4
        ListNode* left = head;
        ListNode* right = getMid(head); // 1->2->3->N
        ListNode* temp = right->next;
        right->next = NULL;
        right = temp; // 4
        
        left = sortList(left);
        right = sortList(right);
        return mergeList(left, right);
    }
};