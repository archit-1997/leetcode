class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        vector<int> v1(26, 0), v2(26, 0);
        int n1 = word1.size(), n2 = word2.size();
        if (n1 != n2)
            return false;
        for (int i = 0; i < n1; i++)
        {
            int c1 = word1[i] - 'a';
            int c2 = word2[i] - 'a';
            v1[c1]++, v2[c2]++;
        }

        for (int i = 0; i < 26; i++)
        {
            if ((v1[i] == 0 && v2[i] != 0) || v1[i] != 0 && v2[i] == 0)
                return false;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (int i = 0; i < 26; i++)
        {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }
};