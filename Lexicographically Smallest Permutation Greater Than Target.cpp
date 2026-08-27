class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Frequency of characters in s
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Try making the answer greater at position i
        for (int i = n - 1; i >= 0; i--) {

            // We need target[0...i-1] to be exactly the same.
            vector<int> cnt = freq;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                cnt[x]--;

                if (cnt[x] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            // Find smallest character > target[i]
            int current = target[i] - 'a';
            int bigger = -1;

            for (int c = current + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            // Construct answer
            string ans = target.substr(0, i);

            ans += char('a' + bigger);
            cnt[bigger]--;

            // Add remaining characters in sorted order
            for (int c = 0; c < 26; c++) {
                while (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;
                }
            }

            return ans;
        }

        return "";
    }
};
