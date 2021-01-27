/*The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"*/

class Solution
{
    public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        else if (n == 2)
        {
            return "11";
        }
        else
        {
            string s = countAndSay(n - 1);
            string n{};
            int c = 1;
            for (int i = 0; i < s.size(); i++)
            {
                if (i + 1 < s.size() and s[i] == s[i + 1])
                {
                    c++;
                }
                else
                {
                    char num = c + '0';
                    n += string{num} + string{s[i]};
                    c = 1;
                }
            }
            return n;
        }
    }
};
