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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* prev = head;
        int len =0;
        // Counting the length of the LL
        while(temp){
            ++len;
            temp=temp->next;
        }
        temp = head;
        //Before Position where the bombing has to be done
        int pos = len-n;
        // Checking if its not the first pos\U0001f47b
        if(len==n)
            return head->next;
        // Going to the position location 
        int i =0;
        while(i<pos){
            prev = temp;
            temp=temp->next;
            i++;
        }
        prev->next = temp->next;
        return head;
    }
};