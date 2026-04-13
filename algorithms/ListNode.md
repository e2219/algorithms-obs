>快速增删元素，但查询较慢的数据结构鼻祖

代码实现：
```
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```

## 遍历链表

- 在遍历的过程中，head = head->next 会改变指向，这样导致再插入链表时 不能简单地插入 head，所以应该在head前设立一个哑节点，保留原来的链表头
- 根据题目判断结束情况是 head or head->next 
- 遍历的时间复杂度相仿，想想怎么能降低空间复杂度

[leetcode725](https://leetcode.cn/problems/split-linked-list-in-parts/description/ 分隔链表)

## 删除元素

- 若可能删除链表头结点，则需要创建一个哑节点指向头结点。
- 删除链表某节点，需要获得该节点前一节点，通过 `cur->next = nxt->next` 分隔开这个节点，这也决定了遍历链表的终止条件

删除模板：
```
	ListNode dummy(0, head);
	ListNode* cur = dummy;
	while (cur->next) {
		auto& nxt = cur->next;
		if (nxt->val == val) {
			cur->next = nxt->next;
			delete nxt;
		}
		else cur = cur->next;
	}
	return dummy.next;
```

[leetcode82](https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/ 删除重复元素) 彻底删除重复元素（两个while循环，cur位置保留，比较下一个和下下一个）

## 插入元素

```//插入到 cur 和 cur->next 之间
	while (cur->next) {
		ListNode* newNode = new ListNode(val, cur->next);
		cur->next = newNode;
		cur = cur->next->next;
	}
```


[leetcodeLCR029](https://leetcode.cn/problems/4ueAj6/description/) 循环列表的插入，cur 与 nxt 之间分类讨论



## 链表反转

```
//完全翻转
	ListNode* pre = nullptr;
	ListNode* cur = head;
	while (cur) {
		ListNode* nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}
	return pre
//指定区间
	ListNode dummy(0, head);
	ListNode* p0 = &dummy;
	for (int i = 0; i < left - 1; i++) {
		p0 = p0->next;
	}
	ListNode* pre = nullptr;
	ListNode* cur = p0->next;
	for (int i = 0; i < right - left + 1; i++) {
		ListNode* nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}
	p0->next->next = cur;
	p0->next = pre;
	return dummy.next;
```
![[92d9e8e4876dd7d465928b681437e747.jpg]]


## 前后指针

想象一个长度为 n 的节点，左端点在链表头部，右端点是第 n 个节点。当右端点到链表尾部时，左端点所指向的就是倒数第 n 个节点。（可以用来删除/获得倒数第 k 个节点）
```
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode dummy(0, head);
	ListNode* left = &dummy;
	ListNode* right = &dummy;
	while (n--) {
		right = right->next; //右端点是第 n + 1 个节点
	}
	while (right->next) {
		left = left->next; //左端点是倒数 n + 1 个节点（待删除节点前一个）
		right = right->next;
	}
	ListNode* nxt = left->next;
	left->next = left->next->next;
	delete nxt;
	return dummy.next;
	}
```

## 快慢指针

慢指针走一步，快指针走两步
快指针套圈，说明有环。快指针到终点，慢指针到中间
```
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) //存在环结构
			...
	}
	return slow //慢指针到中点
```
**Floyd 判圈算法**

![[558075246d0c8d864a6900d3f8817ab6.png]]
代码实现：
[leetcode142](https://leetcode.cn/problems/linked-list-cycle-ii/description/)

## 合并链表

```
//两数相加链表合并 链表头到尾，数位小到大
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode dummy;
		ListNode* cur = &dummy;
		while (l1 || l2 || carry) {
			if (l1) {
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				carry += l2->val;
				l2 = l2->next;
			}
			cur = cur->next = new ListNode(carry % 10);
			carry /= 10;
		}
		return dummy.next;
	}
```
