class Solution {
public:
    vector<int> perRow(int numRows){
        long long res = 1;
        vector<int> ans;
        ans.push_back(1);
        for(int col=1; col<numRows; col++){
            res = res * (numRows - col);
            res = res / (col);
            ans.push_back(res);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(perRow(i));
        }
        return ans;
    }
};