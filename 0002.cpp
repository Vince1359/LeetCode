/*
 * 2. Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

struct ListNode {
	int val;
	ListNode *next;
	explicit ListNode(const int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
	static ListNode* add_two_numbers(ListNode* l1, ListNode* l2) {
		const auto len1 = get_len(l1), len2 = get_len(l2);
		auto p1 = len1 > len2 ? l1 : l2;
		auto p2 = len1 > len2 ? l2 : l1;

		ListNode* pre = nullptr;
		auto carried = 0;
		while (p1) {
			const auto a = p1->val;
			const auto b = p2 ? p2->val : 0;
			p1->val = (a + b + carried) % 10;
			carried = (a + b + carried) / 10;

			pre = p1;
			p1 = p1->next;
			p2 = p2 ? p2->next : nullptr;
		}
		pre->next = carried ? new ListNode(1) : nullptr;

		return len1 > len2 ? l1 : l2;
	}
private:
	static int get_len(ListNode * l) {
		auto res = 0;
		while (l)
			res++, l = l->next;
		return res;
	}
};