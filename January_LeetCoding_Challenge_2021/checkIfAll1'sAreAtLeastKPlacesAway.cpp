class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        vector<int> pos;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                pos.push_back(i);
        }

        for (int i = 1; i < pos.size(); i++)
        {
            int val = pos[i] - pos[i - 1];
            if (val <= k)
                return false;
        }
        return true;
    }
};