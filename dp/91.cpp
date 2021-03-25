class Solution {
    int numDecodings(string s, int idx, vector<int>& dp) {
        if (idx == s.length()) {
            return dp[idx] = 1;
        }

        if (dp[idx] != 0)
            return dp[idx];

        char ch1 = s[idx];
        if (ch1 == '0')
            return 0;

        int count = 0;
        count += numDecodings(s, idx + 1, dp);

        if (idx < s.length() - 1) {
            char ch2 = s[idx+1];
            int num = (ch1 - '0') * 10 + (ch2 - '0');
            if (num <= 26)
                count += numDecodings(s, idx + 2, dp);
        }
        return dp[idx] = count;
    }
    int numDecodings(string s) {
        vector<int>dp(s.length()+1,0);
        return numDecodings(s,0,dp);
    }
};