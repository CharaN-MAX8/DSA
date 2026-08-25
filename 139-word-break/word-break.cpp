class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();

        int max_len = 0;
        for(string word : wordDict){
            max_len = max(max_len, (int)word.size());
        }

        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i=1; i<=n; i++){

            for(int j=i-1; j>=max(0, i-max_len); j--){
                if(dp[j] && dict.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};