class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minI = 0;
        int maxI = 0;

        for(int i = 0;i < n;i++){
            if(nums[i] < nums[minI])
            minI = i;

            if(nums[i] > nums[maxI])
            maxI = i;
        }
        int left = min(minI,maxI);
        int right = max(minI,maxI);

        int fromfront = right + 1;

        int fromBack = n - left;

        int fromBoth = (left + 1)+(n - right);
        return min({fromfront,fromBack,fromBoth});

    }
};
