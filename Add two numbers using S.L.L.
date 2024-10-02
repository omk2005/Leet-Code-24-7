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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *head = nullptr;
        ListNode *temp = head;
        int sumz, carry = 0;
        while(l1!=nullptr | l2!=nullptr)
        {
            sumz = carry;
            if (l1 != nullptr)
            {
                sumz += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sumz += l2->val;
                l2 = l2->next;
            }
            carry = sumz/10;
            if (temp == nullptr)
            {
                temp = head = new ListNode(sumz%10);
                continue;
            }
            temp->next = new ListNode(sumz%10);
            temp = temp->next;
        }
        if (carry > 0)
        {
            if (temp == nullptr)
                temp = head = new ListNode(carry);
            else
                temp->next = new ListNode(carry);
        }
        return head;
    }
};
