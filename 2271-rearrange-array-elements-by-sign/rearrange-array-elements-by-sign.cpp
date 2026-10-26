class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> posi;
        vector<int> nega;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0){
                posi.push_back(nums[i]);
            } else {
                nega.push_back(nums[i]);
            }
        }
        vector<int> res;
        int i = 0;
        int j = 0;
        while(i < posi.size() || j < nega.size()){
            res.push_back(posi[i]);
            res.push_back(nega[j]);
            i++;
            j++;
        }
        return res;
    }
};