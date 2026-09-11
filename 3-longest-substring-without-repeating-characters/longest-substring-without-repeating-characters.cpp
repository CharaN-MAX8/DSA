class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        vector<int> mpp(256, -1);

        while(right < s.size()){
            if(mpp[s[right]] != -1){
                if(mpp[s[right]] >= left){
                    left = mpp[s[right]] + 1;
                }
            }

            int len = right - left + 1;
            maxLen = max(len, maxLen);
            mpp[s[right]] = right;
            right++;
        }
        return maxLen;
        
    }
};