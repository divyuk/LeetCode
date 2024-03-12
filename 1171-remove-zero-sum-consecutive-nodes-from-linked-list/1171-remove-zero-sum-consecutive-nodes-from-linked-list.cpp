
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> sums;
        int sum = 0;
        for (ListNode* current = dummy; current != nullptr; current = current->next) {
            sum += current->val;
            sums[sum] = current;
        }

        sum = 0;
        for (ListNode* current = dummy; current != nullptr; current = current->next) {
            sum += current->val;
            current->next = sums[sum]->next;
        }

        return dummy->next;
    }
};
