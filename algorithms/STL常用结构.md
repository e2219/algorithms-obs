
# 一、 顺序容器
## Vector

```
vector<int> v;  
v.push_back(10);  
v.pop_back();  
  
v.size();  
v.empty();  
  
v[0]; // 不检查越界  
v.at(0); // 检查越界（慢）  
  
sort(v.begin(), v.end());  
reverse(v.begin(), v.end());
```

常用技巧
```
vector<int> v(n, 0); // 初始化 n 个 0  
vector<int> v = {1,2,3};  
  
v.erase(v.begin()+i); // 删除第 i 个，第 i + 1 及之后向前移动一位
v.clear();
```

## String
```
vector<int> v(n, 0); // 初始化 n 个 0  
vector<int> v = {1,2,3};  
  
v.erase(v.begin()+i); // 删除第 i 个  
v.clear();
```
字符串转数字
```
int x = stoi(s);
long y = stol(s);
stoll(long long), stoul(unsigned long long),stod(double)... 
```

# 二、关联容器（自动排序）
## Set
>去除重复元素

```
set<int> s;  
s.insert(3);  
s.insert(1);  
  
s.erase(1);  
s.count(3); // 是否存在（0/1）  
  
for (auto x : s) cout << x;
```
查找元素
```
auto it = s.find(3);  
if (it != s.end()) {}
```

## Map
>键值映射

```
map<string,int> mp;  
  
mp["a"] = 1;  
mp["b"]++;  
  
mp.count("a"); //检查是否存在
mp.erase("a");
```
遍历
```
for (auto [k,v] : mp) {  
	cout << k << " " << v;  
}
```

## 三、无序容器（哈希， O(1）期望）

## unordered_set
## unordered_map

## 四、队列/栈

## Stack
```
stack<int> st;  
st.push(1);  
st.pop();  
st.top();
```
## 单调栈

>是一种特殊设计的栈结构，栈内的元素具有严格的单调性。例如，对于一个单调递减栈（栈底到栈顶元素递减），新元素入栈时，若其大于栈顶元素，则不断出栈，否则入栈，这样就在线性时间内实现了**查找下一个更大的元素**
>>**单调栈**的本质是 *弹出不用的元素，保证每个元素最多入栈出栈一次*，栈中的元素都是待计算的元素，通过控制其单调性，**及时去掉无用数据，保证栈中数据有序**

```
vector<int> dailyTemperatures(vector<int>& temperatures) {
	int n = temperatures.size();
	vector<int> ans(n);
	stack<int> stk;
	for (int i = 0; i < n; i++) {
		while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
			ans[stk.top()] = i - stk.top();
			stk.pop();
		}
		stk.push(i);
	}
	return ans;
}
```

## Queue
```
queue<int> q;  
q.push(1);  
q.pop();  
q.front();
```

## Deque
```
deque<int> dq;  
dq.push_front(1);  
dq.push_back(2);  
  
dq.pop_front();  
dq.pop_back();
```

## 单调队列(与滑动数组结合)

指定 k 个一组的滑动窗口，求这个窗口中元素的最大值。

想象一个折线图，在从左到右遍历的过程中，已经离开窗口的元素永远不可能是最大值，在一个窗口中会存在一个最大值。用双端队列来储存**索引**，**当前窗口的最大值索引放在队首**。窗口向右滑动，如果新入队的元素小于队尾元素，就入队，因为在后续遍历的过程中，它们可能是其他窗口的最大值。反之，如果进入窗口的元素大于等于队尾元素，说明之前的队尾元素无论如何也不可能成为最大值，应该离开队列(**pop_back()**)。当滑动窗口队首的元素（是一个索引）小于遍历的 i - k + 1 时，说明这个数应该离开窗口(**pop_front()**)。 这样就保证了队列的元素个数始终小于k，且队列最左侧是当前窗口最大值的索引。**队列储存滑动窗口中可能成为最大值的元素索引**

*及时去掉无用数据，保证双端队列有序*

代码模板
```
vector<int> maxSlidingWindow(vector<int>& nums, int k){
	int n = nums.size();
	vector<int> ans(n - k + 1); //答案的元素个数是 n - k + 1
	deque<int> q; //创建单调双端队列储存当前滑动窗口最大值
	for (int i = 0; i < n; i++) {
		while (!q.empty() && nums[q.back()] <= nums[i]) { //进入窗口的元素大于队尾
			q.pop_back();
		}
		q.push_back(i);
		int left = i - k + 1; //判断何时开始更新答案，以及队首元素是否该出队
		if (q.front() < left) { //元素离开窗口
			q.pop_front();
		}
		if (left >= 0) { //窗口元素个数足够时，更新答案
			ans[left] = nums[q.front()];
		}
	}
	return ans;
}
```

## 五、优先队列
## Priority_queue
```
// 大顶堆
priority_queue<int> pq;  
pq.push(3);  
pq.push(1);  
  
pq.top(); // 最大值

//小顶堆
priority_queue<int, vector<int>, greater<int>> pq;

//自定义结构
struct Node {  
int x;  
bool operator<(const Node& other) const {  
return x > other.x; // 小根堆  
}  
};  
priority_queue<Node> pq;
```

## 六、字典树

字典树：以链表模拟树的结构，实现高效查询

>走过同样的路，如果无路可走，就开辟一条新路

```
struct Node {
	Node* son[26]{}; //一个节点，对应 26 个字母(子节点)
	bool end = false; //核对是否匹配整个字符串
}
class Trie {
	Node* root = new Node();
	int find(string word) { //前缀或整个字符串
		Node* cur = root; //从根节点开始逐个查找匹配
		for (char c : word) {
			c -= 'a';
			if (cur->son[c] == nullptr) return 0; //子节点若与遍历字母不同，说明不存在
			cur = cur->son[c];
		}
		return cur->end ? 2 : 1; //遍历到树的末尾，完全匹配；否则前缀匹配
	}
	void destory(Node* node){
		if (node == nullptr) {
			return;
		}
		for (Node* son : node->son) {
			destory(son); //用递归从底至顶删除
		}
		delete node;
	}
public:
	~Trie() {
		destory(root);
	}
	void insert(string word) {
		Node* cur = root;
		for (char c : word) {
			c -= 'a';
			if (cur->son[c] == nullptr) {
				cur->son[c] = new Node(); //不存在，就创建
			}
			cur = cur->son[c];
		}
		cur->end = true; //标记 string 末尾
	}
	bool search(string word) {
		return find(word) == 2;
	}
	bool startsWith(string prefix) {
		return find(prefix) != 0;
	}
}
```

## 七、算法库
## 排序
```
sort(a.begin(), a.end());
sort(a.begin(), a.end(), greater<int>());
```
	