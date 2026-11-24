# 📝 2546. Number of Subarrays With GCD Equal to K (LeetCode)

🔗 [Problem Link](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange) ![Language](https://img.shields.io/badge/Language-C++-blue)

### 💡 Tags
Array, Math, Number Theory

### 🚀 Performance
- **Runtime:** 14 ms
- **Memory:** 12.3 MB

---

### 📜 Problem Description

Given an integer array  `nums`  and an integer  `k` , return  *the number of  **subarrays**  of*  `nums`  *where the greatest common divisor of the subarray's elements is*  `k` .

A  **subarray**  is a contiguous non-empty sequence of elements within an array.

The  **greatest common divisor of an array**  is the largest integer that evenly divides all the array elements.

**Example 1:**

```
Input: nums = [9,3,1,2,6,3], k = 3
Output: 4
Explanation: The subarrays of nums where 3 is the greatest common divisor of all the subarray's elements are:
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]

```

**Example 2:**

```
Input: nums = [4], k = 7
Output: 0
Explanation: There are no subarrays of nums where 7 is the greatest common divisor of all the subarray's elements.

```

**Constraints:**

	
- `1 <= nums.length <= 1000`
	
- `1 <= nums[i], k <= 109`