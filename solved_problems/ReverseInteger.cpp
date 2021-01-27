/*Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

*/

class Solution {
public:
	int reverse(int x) {
		long long num = 0;
		int a = 0;
		while (x)
		{
			a = x % 10;
			num = a + num * 10;
			x = x / 10;
		}
		return (num>INT_MAX||num<INT_MIN)?0:num;	
	}
};
