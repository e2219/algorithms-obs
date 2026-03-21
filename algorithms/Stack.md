## 语法

初始化： `std::stack<int> s`
入栈： `s.push(element)`
出栈： `s.pop()` (不返回元素)
获取栈顶元素： `s.top()`
判断空否： `s.empty()`
获取元素数量： `s.size()`
直接构造： `s.emplace()`

---
## 应用场景

[leetcode3170](https://leetcode.cn/problems/lexicographically-minimum-string-after-removing-stars/description/ "遇到特殊符号出栈") (遇到 "\*" 时，删除最小元素的栈顶元素，使得字典序最小)

[leetcode946](https://leetcode.cn/problems/validate-stack-sequences/description/ "检验栈")（按照题目要求入栈，匹配到出栈元素时出栈）

[leetcode2434](https://leetcode.cn/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/ "机器人打印字典序最小的字符串") （何时出栈使字典序最小？）

[leetcode1047](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/ "删除重复项") (用栈维护上一个遍历的字母，若下一个字母与栈顶字母匹配，则出栈，否则入栈)

[leetcode1990](https://leetcode.cn/problems/reverse-substrings-between-each-pair-of-parentheses/description/ "按顺序反转括号间的子串") (在遇到')'时反转括号间的字符串并执行出栈，遇到 '(' 时压入字符串)

## 什么时候要使用栈？

典型的后进先出问题，要求按照特定顺序导出元素，或遇到特殊符号删减元素（且只能删减特殊符号前的元素），这时候就要用栈来维护已经遍历的元素。

相邻元素问题：从前往后遍历 + 有相邻元素 + 有消除操作 = 栈

## 栈问题的关键是什么？

怎样**构建** （例如 3170 创建了 26 字母栈，用于记录遍历到的字母的索引）
**何时出栈**(例如 2434 用后缀维护最小字母， 进行比较找到合适的出栈时机)
在执行进出栈操作时还要进行什么操作

---

# Stack 表达式解析

## >逆波兰数：

>常规的运算是 “中缀运算”， 比如 3 + (4 + 2) * 6， 是按照数学运算的顺序进行，符合人的直觉，由人类自身定义的规则解释。
>但对机器来说，只会按顺序读取编码，再根据读到的顺序进行运算。从而出现了逆波兰表达式（**RPN**）
>>**RPN** 的本质是 *每个运算符仅被使用于最近的两个未操作数*，因此它**不需要括号**，**不需要优先级规则**，**顺序即语义**。

可以用栈模拟出来: 
[中缀转后缀，后缀由栈计算答案](vscode://file/home/fhy/leetcode-cpp/postfix.cpp)








