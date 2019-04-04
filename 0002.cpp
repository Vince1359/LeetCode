struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int len1 = getLen(l1), len2 = getLen(l2);
		ListNode* p1 = len1 > len2 ? l1 : l2;
		ListNode* p2 = len1 > len2 ? l2 : l1;

		ListNode* pre = nullptr;
		int carried = 0;
		while (p1) {
			int a = p1->val;
			int b = p2 ? p2->val : 0;
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
	int getLen(ListNode * l) {
		int res = 0;
		while (l)
			res++, l = l->next;
		return res;
	}
};