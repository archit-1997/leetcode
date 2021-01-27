/*Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		// Example: 1, 3, 2, 6, 5, 4, 1
        if (nums.size() < 2) return;
        int i = nums.size() - 1;
		//rewind i backwards from last position unil descent reached
        while (--i >= 0 && nums[i] >= nums[i+1]){}
		// 1, 3, [i=>2], 6, 5, 4, 1
        int j = i;
		//rewind j forward starting from i+1 until  >= element found 
        while (++j < nums.size() && nums[j] > nums[i]){ }
		// 1, 3, [i=>2], 6, 5, 4, [j=>1]
		// swap previous element (first element larger then nums[i] from right to left)
        if (i >= 0) swap(nums[j-1], nums[i]);
		// 1, 3, [i=>4], 6, 5, 2, [j=>1]
		// Finally reverse the tail from i+1
        reverse(nums.begin() + i + 1, nums.end());
		//// 1, 3, [i=>4], (( 6, 5, 2, [j=>1] )) => (1,3,4, 1,2,5,6)
    }
};
