class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int count[51] = {0};
        for(int i = 0; i + k <= nums.size(); i++) {
                        bool seen[51] = {false};


            for(int j = i ; j < i+k;j++){
                seen[nums[j]] = true;
            }
            for(int nums = 0 ; nums <= 50;nums++){
                if(seen[nums])
                {
                count[nums]++;
            }
        }
        
        }
        for(int nums = 50;nums >= 0;nums--){
            if(count[nums] == 1){
                return nums;
            }
        }
        return -1;
    }
};
