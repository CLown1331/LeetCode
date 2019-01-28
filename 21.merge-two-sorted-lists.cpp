/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (45.13%)
 * Total Accepted:    486.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        ListNode* ret = new ListNode(0);
        ListNode* cur = ret;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) {
                cur->val = l2->val;
                l2 = l2->next;
            } else {
                cur->val = l1->val;
                l1 = l1->next;
            }
            cur->next = new ListNode(0);
            cur = cur->next;
        }
        while (l1 != nullptr) {
            cur->val = l1->val;
            l1 = l1->next;
            if (l1 == nullptr) break;
            cur->next = new ListNode(0);
            cur = cur->next;
        }
        while (l2 != nullptr) {
            cur->val = l2->val;
            l2 = l2->next;
            if (l2 == nullptr) break;
            cur->next = new ListNode(0);
            cur = cur->next;
        }
        return ret;
    }
};
