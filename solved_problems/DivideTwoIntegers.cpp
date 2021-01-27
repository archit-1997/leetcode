/*Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3

Example 2:

Input: dividend = 7, divisor = -3
Output: -2

Note:

    Both dividend and divisor will be 32-bit signed integers.
    The divisor will never be 0.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.

*/

class Solution {
public:
    int divide(long int dividend, long int divisor) {
        long int div_closest = 0;
        long long int quotient = 0;
        int sign = -1;
        if((dividend<=0 && divisor<=0) || (dividend>=0 && divisor>=0))sign=1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        for(int i=31;i>=0;i--)
        {
            if(div_closest + (divisor<<i) <= dividend)
            {
                div_closest+=divisor<<i;
                quotient |= 1<<i;
            }
        }
        if(sign>0 && quotient<0)quotient=INT_MAX;
        return (int)(sign*quotient);
    }
};
