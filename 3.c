/*
* 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
* 提示：
*	0 <= s.length <= 5 * 104
*	s 由英文字母、数字、符号和空格组成
* 
* 解题思路：滑动窗口
*	用两个索引l, r分别代表一个 无重复子串 的起始位置, s[l]...s[r]为无重复子串，此子串长度为r-l+1
*	移动r至r+1，如s[r+1]与子串有重复，则l向前移动，计算一个新的子串
* 可利用哈希数组unsigned char c_hash_table[s[r]]，来快速确定s[r]是否与子串重复
*/


#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
	int i, len, l, r, tmp, max = 0;
	unsigned char c_hash_table[128]; // 一个ASCII字符最大值127

	for (i = 0; i < 128; i++)
		c_hash_table[i] = 0;

	len = strlen(s);
	if (len == 0)
		return 0;

	l = r = 0;
	while (l < len - max) {
		while (r < len && c_hash_table[s[r]] == 0) {
			c_hash_table[s[r]] = 1;
			r++;
		}
		tmp = r - l;
		if (tmp > max)
			max = tmp;
		c_hash_table[s[l]] = 0;
		l++;
	}

	return max;
}

int main(void)
{
	printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
	printf("%d\n", lengthOfLongestSubstring("bbbbb"));
	printf("%d\n", lengthOfLongestSubstring("pwwkew"));

	return 0;
}