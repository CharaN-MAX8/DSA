class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<int> freq(26, 0);
        for(int i=0; i<s.length(); i++){
            int idx = s[i] - 'a';
            freq[idx]++;
        }

        for(int i=0; i<s.length(); i++){
            int idx = t[i] - 'a';
            if(freq[idx] == 0) return false;
            freq[idx]--;
        }
        return true;
    }
};