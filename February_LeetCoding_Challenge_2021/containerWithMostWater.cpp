class Solution {
public:
  int maxArea(vector<int> &height) {

    int n = height.size();

    int ans = INT_MIN;

    int l = 0, r = n - 1;

    while (l < r) {
      int h = min(height[l], height[r]);
      int val = h * (r - l);

      ans = max(ans, val);

      if (height[l] <= height[r])
        l++;
      else
        r--;
    }

    //         int big=*max_element(height.begin(),height.end());

    //         ans=max(ans,big);

    return ans;
  }
};
