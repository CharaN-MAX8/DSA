class Solution {
public:
    int NcR(int n, int r){
        long long res = 1;
        for(int i=0; i<r; i++){
            res = res * (n - i);
            res = res / (i + 1);
        }
        return (int)res;
    }

    vector<int> getRow(int rowIndex) {
        int N = rowIndex+1;
        vector<int> ans;
        ans.push_back(1);
        for(int c=2; c<N; c++){
            ans.push_back(NcR(N-1, c-1));
        }
        if(rowIndex != 0)ans.push_back(1);
        return ans;
    }
};