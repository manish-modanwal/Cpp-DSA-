class Solution {
public:
    int rob(vector<int>& nums)
    {  
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);  
        int curr = prev2;

        for (int i = 2; i < n; i++)
        {   
            int take = prev1 + nums[i];   
            int skip = prev2;             
            curr = std::max(take, skip);

            prev1 = prev2;
            prev2 = curr;
        }

        return curr;
    }
};
