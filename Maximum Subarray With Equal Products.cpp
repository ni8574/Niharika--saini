
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            __int128 product = 1;
            long long g = 0, l = 1;

            for (int j = i; j < n; j++) {

                product *= nums[j];

                g = gcd(g, (long long)nums[j]);

                l = l / gcd(l, (long long)nums[j]) * nums[j];

                if (product == (__int128)g * l) {
                    ans = max(ans, j - i + 1);
                }

                // Once product is greater than GCD * LCM,
                // it can never become equal again.
                if (product > (__int128)g * l)
                    break;
            }
        }

        return ans;
    }
};


