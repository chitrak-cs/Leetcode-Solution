class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<long long> rem(24, 0);

        for (auto h : hours) {
            rem[h % 24]++;
        }

        long long ans = 0;

        int f0 = rem[0];
        ans +=1LL * f0 * (f0 - 1) / 2;

        int f12 = rem[12];
        ans +=  1LL * f12 * (f12 - 1) / 2;

        for (int i = 1; i < 12; i++) {
            ans += 1LL * rem[i] * rem[24 - i];
        }

        return ans;
    }
};