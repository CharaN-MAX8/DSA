class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;
        if(x == 0) return true;
        if(x < 0) return false;
        while(x > 0){
            int t = x % 10;
            arr.push_back(t);
            x = x / 10;
        }

        for(int i=0; i<arr.size(); i++){
            int j = arr.size()-i-1;
            if(arr[i] != arr[j]) return false;
        }

        return true;
    }
};