class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int n = s.length();

        for(int start=0; start<n; start++){
            if(goal[start] != s[0]) continue;
            string ans = "";
            int i = start;
            int count = s.length();
            while(count > 0){
                if(i == s.length()) i = 0;
                ans += goal[i];
                i++;
                count--;
            }

            if(ans == s) return true; 
        }
        return false;
    }
};