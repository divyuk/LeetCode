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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*h = list1;
        ListNode* currTraveller = list1;
        ListNode* saveA = list1;
        ListNode* saveB = list1;
        for(int i = 0 ;i<a-1 ; i++){
           
            currTraveller = currTraveller->next;
             saveA= currTraveller;
        }
        currTraveller=list1;
        
        for(int i =0; i<b;i++){
            currTraveller=currTraveller->next;
             saveB= currTraveller;
        }
        ListNode *temp2 = list2;  // Initialize pointer to traverse list2
        while(temp2->next){
            temp2 = temp2->next;
        }
         saveA->next = list2;
        temp2->next = saveB->next;
        
        return list1;
    }
};