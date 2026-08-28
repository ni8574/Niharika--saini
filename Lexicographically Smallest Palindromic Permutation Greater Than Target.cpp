class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s) cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1) return "";

        vector<int> h(26);
        for (int i = 0; i < 26; i++)
            h[i] = cnt[i] / 2;

        int m = n / 2;
        string half;

        function<bool()> build = [&]() {
            if (half.size() == m) {
                string r = half;
                reverse(r.begin(), r.end());

                string ans = half;
                if (n % 2) ans += mid;
                ans += r;

                if (ans > target) {
                    half = ans;
                    return true;
                }
                return false;
            }

            for (int c = 0; c < 26; c++) {
                if (h[c]) {
                    h[c]--;
                    half += char('a' + c);

                    if (build()) return true;

                    half.pop_back();
                    h[c]++;
                }
            }
            return false;
        };

        if (build()) return half;
        return "";
    }
};
