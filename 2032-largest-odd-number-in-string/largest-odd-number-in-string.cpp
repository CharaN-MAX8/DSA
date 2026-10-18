class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int i = 0;
        for(i=num.length()-1; i>=0; i--){
            int n = num[i] - '0';
            if(n % 2 != 0){
                break;
            }
        }
        return num.substr(0, i+1);
    }
};