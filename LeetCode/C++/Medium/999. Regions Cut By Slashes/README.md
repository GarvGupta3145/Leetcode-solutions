# 📝 999. Regions Cut By Slashes (LeetCode)

🔗 [Problem Link](https://leetcode.com/problems/regions-cut-by-slashes/)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
Array, Hash Table, Depth-First Search, Breadth-First Search, Union-Find, Matrix, Planar Graph

### 🚀 Performance
- **Runtime:** N/A
- **Memory:** N/A

---

### 📜 Problem Description

An  `n x n`  grid is composed of  `1 x 1`  squares where each  `1 x 1`  square consists of a  `'/'` ,  `'\'` , or blank space  `' '` . These characters divide the square into contiguous regions.

Given the grid  `grid`  represented as a string array, return  *the number of regions* .

Note that backslash characters are escaped, so a  `'\'`  is represented as  `'\\'` .

**Example 1:**

 ![image](https://assets.leetcode.com/uploads/2018/12/15/1.png) 

```
Input: grid = [" /","/ "]
Output: 2

```

**Example 2:**

 ![image](https://assets.leetcode.com/uploads/2018/12/15/2.png) 

```
Input: grid = [" /","  "]
Output: 1

```

**Example 3:**

 ![image](https://assets.leetcode.com/uploads/2018/12/15/4.png) 

```
Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.

```

**Constraints:**

	
- `n == grid.length == grid[i].length`
	
- `1 <= n <= 30`
	
- `grid[i][j]`  is either  `'/'` ,  `'\'` , or  `' '` .