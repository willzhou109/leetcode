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
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        ListNode dummy(0);
        ListNode * tail = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
        }
        if (l1) {
            tail->next = l1;
        } else if (l2) {
            tail->next = l2;
        }
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        } else if (lists.size() == 1) {
            return lists[0];
        }
        ListNode * p1 = lists[0];
        ListNode * p2 = lists[1];
        for (int i = 0; i < lists.size() - 1; ++i) {
            p2 = lists[i + 1];
            p1 = mergeTwoLists(p1, p2);
        }
        return p1;

    }
};