class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> composite(n, false);
        int limit = sqrt(n);
        for(int i=2; i<=limit; i++){
            if(!composite[i]){
                for(int j=i*i; j<n; j+=i){
                    composite[j] = true;
                }
            }
        }
        int count=0;
        for(int i=2; i<n; i++){
            if(!composite[i]) count++;
        }
        return count;
    }
};