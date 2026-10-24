class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        long long expect = n*(n+1)/2;
        long long actual = 0;
        for(int i=0; i<n; i++){
            actual += nums[i];
        }
        return expect - actual;
    }
};