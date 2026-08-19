# 📝 897. Increasing Order Search Tree (LeetCode)

🔗 [Problem Link](https://leetcode.com/problems/increasing-order-search-tree)

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
Stack, Tree, Depth-First Search, Binary Search Tree, Binary Tree

### 🚀 Performance
- **Runtime:** N/A
- **Memory:** N/A

---

### 📜 Problem Description

Given the  `root`  of a binary search tree, rearrange the tree in  **in-order**  so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

**Example 1:**

 ![image](https://assets.leetcode.com/uploads/2020/11/17/ex1.jpg) 

```
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

```

**Example 2:**

 ![image](https://assets.leetcode.com/uploads/2020/11/17/ex2.jpg) 

```
Input: root = [5,1,7]
Output: [1,null,5,null,7]

```

**Constraints:**

	
- The number of nodes in the given tree will be in the range  `[1, 100]` .
	
- `0 <= Node.val <= 1000`