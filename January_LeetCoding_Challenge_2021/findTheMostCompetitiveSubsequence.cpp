class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        stack<int> st;
        int n = nums.size();
        int pop_count = 0;
        int i = 0;
        while (i < n)
        {
            if (st.empty())
                st.push(nums[i++]);
            else
            {
                if (st.top() <= nums[i])
                    st.push(nums[i++]);
                else
                {
                    if (pop_count < (n - k))
                    {
                        st.pop();
                        pop_count++;
                    }
                    else
                        st.push(nums[i++]);
                }
            }
        }
        vector<int> v;
        while (!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(v[i]);
        return ans;
    }
};