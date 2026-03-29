
## 语法

初始化：（大顶堆）priority_queue<typename.>, (小顶堆) priority_queue<typename, vector<typename.>, greater<typename.> >
入堆：p.push(val)
出堆：p.pop()
验空：p.empty()
大小：p.size()

---

初始化：`make_heap(vector.begin(), vector.end())` (将区间\[begin, end)的元素原地构造为堆)
**只改变元素顺序，不会改变原来的 vector 结构**
"出堆"：`pop_heap(begin, end)` 将堆顶元素与最后一个元素交换位置，保证\[begin, end - 1)是堆
入堆：`push_heap(begin, end)` 将该区间最后一个元素放入堆中，并进行上浮，保证堆顶最大
如果想使用小顶堆，必须在每个函数后加上 `greater<T>`


## 堆本质是完全二叉树

>堆是用树来实现的。在同层的子节点中，大小关系是不确定的，但都能保证他们小(大)于父节点。因此堆顶总是最大(最小)元素。
>在实际实现中，可以用 `vector`来初始化堆，再通过节点间大小关系实现`heapify_up`, `heapify_down`，从而完成 `pop`push`的操作

## 堆的代码实现

```fold
template <typename T, typename Compare = less<T>>
class PriorityQueue {
private:
	vector<T> data;
	Compare comp;
	void heapify_up(int i) {
		while (i > 0) {
			int parent = (i - 1) / 2;
			if (!comp(data[parent], data[i])) break;
			swap(data[parent], data[i]);
			i = parent;
		}
	}
	void heapify_down(int i) {
		int n = data.size(); //从 i 开始向叶节点遍历，判断子节点与父节点是否交换
		while (true) {
			int best = i;
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			if (left < n && comp(data[best], data[left])) best = left;
			if (right < n && comp(data[best], data[right])) best = right;
			if (best == i) break;
			swap(data[i], data[best]);
			i = best;
		}
	}
public:
	PriorityQueue() {}
	void push(const T& val) {
		data.push_back(val);
		heapify_up(data.size() - 1);
	}
	void pop() {
		if (empty()) throw runtime_error("PriorityQueue is empty");
		swap(data[0], data.back());
		data.pop_back();
		if (!empty()) heapify_down(0);
	}
	T top() const {
		if (empty()) throw runtime_error("PriorityQueue is empty");
		return data[0];
	}
	bool empty() const { return data.empty(); }
	int size() const { return data.size(); }
};
```

## 适用场景

1.不断对当前数组的最值进行修改
	[leetcode2558](https://leetcode.cn/problems/take-gifts-from-the-richest-pile/description/ 简单堆).
2.经典TOPK问题
	[leetcode703](https://leetcode.cn/problems/kth-largest-element-in-a-stream/description/ 创建一个k大小的堆，用于维护前k个最大元素)



