class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, char> st, ts;

        for(int i=0; i<s.length(); i++){
            char a = s[i], b = t[i];

            if(st.count(a) && st[a] != b) return false;
            if(ts.count(b) && ts[b] != a) return false;

            st[a] = b;
            ts[b] = a;
        }
        return true;
    }
};