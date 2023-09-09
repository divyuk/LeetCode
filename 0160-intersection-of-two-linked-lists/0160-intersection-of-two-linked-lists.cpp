/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    int calculateDifference(ListNode *headA, ListNode *headB)
    {
        int lenA = 0, lenB = 0;
        while (headA)
        {
            lenA++;
            headA = headA->next;
        }
        while (headB)
        {
            lenB++;
            headB = headB->next;
        }

        return lenA - lenB;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        //! Calculating the difference between length
        int difference = calculateDifference(headA, headB);

        if (difference < 0)
            while (difference++ != 0)
                headB = headB->next;
        else
            while (difference-- != 0)
                headA = headA->next;

//         while (abs(difference) == 0)
//             headA = headA->next;

        //! Running them together
        while (headA)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};