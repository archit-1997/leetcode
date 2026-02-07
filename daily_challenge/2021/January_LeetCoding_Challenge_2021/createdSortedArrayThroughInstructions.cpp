#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;
class Solution {
public:
  int createSortedArray(vector<int> &instructions) {
    int mod = 1e9 + 7;
    new_data_set p;
    int n = instructions.size();
    int ans = 0;
    unordered_map<int, int> count;
    if (n <= 2)
      return 0;
    p.insert(instructions[0]);
    p.insert(instructions[1]);

    count[instructions[0]]++;
    count[instructions[1]]++;

    for (int i = 2; i < n; i++) {
      int num = instructions[i];
      p.insert(num);
      count[instructions[i]]++;
      int small = p.order_of_key(num);
      int big = (i + 1) - (small + count[instructions[i]]);
      ans = (ans + min(big, small)) % mod;
    }
    return ans;
  }
};