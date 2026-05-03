
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

[leetcode3597](https://leetcode.cn/problems/partition-string/description/ "分割字符串") 尽可能分成互不相同的段，用字典树检验之前是否出现过
[leetcode648](https://leetcode.cn/problems/replace-words/description/ 单词替换) 替换单词为其词根(注意以 stringstream 分割单词的方法)
[leetcode720](https://leetcode.cn/problems/longest-word-in-dictionary/description/) 按顺序查找，需要特殊判断(是否可拼接)
