class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
unordered_map<int, int> freq;

        // Frequency of nums2 values
        for (int x : nums2) {
            freq[x]++;
        }

        long long ans = 0;

        for (int x : nums1) {

            // x must be divisible by k
            if (x % k != 0)
                continue;

            x /= k;

            // Find all divisors of x
            for (int d = 1; d * d <= x; d++) {

                if (x % d == 0) {

                    // d is a divisor
                    if (freq.count(d))
                        ans += freq[d];

                    // x/d is another divisor
                    if (d != x / d && freq.count(x / d))
                        ans += freq[x / d];
                }
            }
        }

        return (int)ans;
    }
};