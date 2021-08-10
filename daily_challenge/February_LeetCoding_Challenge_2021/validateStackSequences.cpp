class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> st;

    int i = 0, j = 0;

    while (j < popped.size()) {
      while (i < pushed.size() && pushed[i] != popped[j]) {
        st.push(pushed[i]);
        i++;
      }
      if (i < pushed.size())
        st.push(pushed[i++]);
      // pop all those elements which we can pop
      while (j < popped.size() && !st.empty() && popped[j] == st.top()) {
        st.pop();
        j++;
      }
      if (j == popped.size())
        return st.empty();

      // if we have already traversed i completely
      if (i == pushed.size())
        return false;
    }
    return st.empty();
  }
};
