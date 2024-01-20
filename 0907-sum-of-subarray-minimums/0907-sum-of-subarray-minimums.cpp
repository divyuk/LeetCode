class Solution {
public:
   int sumSubarrayMins(vector<int>& A) {
      int len = A.size();
      const int MOD = 1000000007;
      vector<int> leftBounds(len, -1);
      stack<int> st;
      //leftBound
      for (int i = 0; i < len; ++i)
      {
         int num = A[i];
         while (st.size() && A[st.top()] > num)
            st.pop();
         long leftBound = st.empty() ? 0 : st.top() + 1;
         leftBounds[i] = leftBound;
         st.push(i);
      }
      //rightBound
      long res = 0;
      st = stack<int>();
      for (int i = len - 1; i >= 0; --i)
      {
         long num = A[i];
         //handle equal elements specially
         while (st.size() && A[st.top()] >= num)
            st.pop();
         long rightBound = st.empty() ? len - 1 : st.top() - 1;
         st.push(i);
         res += (num * (((rightBound - i + 1) * (i - leftBounds[i] + 1)) % MOD)) % MOD;
         res %= MOD;
      }
      return res;
   }
};