class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> extra;

        for(int i=0; i<n; i++){
            extra[nums[i]]++;
            if(extra[nums[i]] > n/2){
                return nums[i];
            }
        }
        return -1;
    }
};