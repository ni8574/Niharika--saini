class Solution {
public:
    int climbStairs(int n) {
        int first = 0,second = 1,next;
        
        for(int i = 0;i < n;i++){
            next = first + second;
            first = second;
            second = next;

            

        }
        return next;
    }
};
