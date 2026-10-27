class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex + 1;
        vector<int> ans;
        ans.push_back(1);
        long long res = 1;
        for(int i=1; i<n; i++){
            res = res * (n-i);
            res = res / i;
            ans.push_back((int)res);
        }
        return ans;
    }
};