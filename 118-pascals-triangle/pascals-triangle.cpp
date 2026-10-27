class Solution {
public:
    int NcR(int n, int r){
        //if(n == 0 || r == 0) return 1;

        long long res = 1;
        for(int i=0; i<r; i++){
            res = res * (n - i);
            res = res / (i + 1);
        }
        return (int)res;
    }

    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            vector<int> arr;
            //arr.push_back(1);
            for(int j=1; j<=i; j++){
                arr.push_back(NcR(i-1, j-1));
            }
            ans.push_back(arr);
        }
        return ans;
    }
};