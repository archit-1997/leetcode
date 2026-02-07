class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {

    vector<int> table(amount + 1, INT_MAX);
    table[0] = 0;
    for (int j = 1; j <= amount; j++) {
      for (int i = 0; i < coins.size(); i++) {
        if (coins[i] <= j) {
          int val = table[j - coins[i]];
          if (val != INT_MAX && val + 1 < table[j])
            table[j] = val + 1;
        }
      }
    }

    if (table[amount] == INT_MAX)
      return -1;

    return table[amount];
  }
};