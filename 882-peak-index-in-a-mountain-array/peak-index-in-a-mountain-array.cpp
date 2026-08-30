class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        vector<int> copy = arr;
        sort(arr.begin(), arr.end());
        int t = arr[arr.size()-1];

         for(int i=0; i<arr.size(); i++){
            if(t == copy[i]) return i;
         }
         return -1;
    }
};