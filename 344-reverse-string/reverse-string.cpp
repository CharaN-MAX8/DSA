class Solution {
public:
    void func(vector<char>& s,int i){
        if(i >= s.size()/2){
            return;
        }



        swap(s[i], s[s.size()-i-1]);
        return func(s, i+1);
    }
    void reverseString(vector<char>& s) {
        func(s, 0);
        
    }
};