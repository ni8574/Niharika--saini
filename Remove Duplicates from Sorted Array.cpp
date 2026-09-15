class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 0; 
        int i = 0;
        while(i < n){
            nums[k++] = nums[i];
            int low = i,high = n;
            while(low < high){
                int mid = low + (high - low)/2;
                if(nums[mid] == nums[i])
                low = mid +1;
                else
                high = mid;
            }
            i = low;
        }
        return k;
    }
};
