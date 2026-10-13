class Solution {
public:
    int reverse(int x) {
        long long n = llabs((long long)x);
        if(n == 0) return 0;

        int count = -1;
        long long t = n;
        while(t > 0){
            t = t / 10;
            count++;
        }

        long long p = 1;
        for(int i=0; i<count; i++) p *= 10;

        long long ans = 0;
        long long m = n;
        while(m > 0){
            ans += ((m % 10)*p);
            m = m / 10;
            p = p / 10;
        }

        if(x < 0) ans = -ans;

        if(ans > INT_MAX || ans < INT_MIN) return 0;

        return (int)ans;
    }
};