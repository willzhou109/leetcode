#include <iostream>
using std::cout, std::endl;
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*int count = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* saved_next = nullptr; // start of the next group of k
        while (count < k) {
            count += 1;
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if (count == k - 1) {
                saved_next = nxt->next;
            }
        }
        head->next = saved_next;
        return prev;*/


        ListNode* start_of_group = head;
        ListNode* ret = nullptr;
        int group_count = 0; // counter for number of groups
        ListNode* start_of_prev_group = nullptr;
        while (start_of_group) {
            group_count += 1;
            ListNode* curr = start_of_group;
            ListNode* prev = nullptr;
            ListNode* start_of_next = nullptr;
            int count = 0;

            // count to make sure there are k nodes than can be traversed
            int test_count = 0;
            while (curr && test_count < k) {
                test_count += 1;
                curr = curr->next;
            }
            curr = start_of_group;

            // performing reversal per group
            while (count < k && curr && test_count == k) {
                count += 1;
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
                if (count == k) {
                    start_of_next = nxt;
                }
            }

            if (group_count == 1) { // if it's the first group
                ret = prev;
            } else {
                start_of_prev_group->next = prev; // 1->next = 4 in case 1
            }

            if (test_count < k) { // if the last group has insufficient nodes, we don't reverse it, just connect
                start_of_prev_group->next = start_of_group;
                start_of_group = nullptr;
            } else {
                start_of_group->next = start_of_next; // 3->next = 5
                start_of_prev_group = start_of_group; // 3
                start_of_group = start_of_next; // 3 becomes 5
            }
            cout << test_count << endl;

        }
        return ret;
    }
};
