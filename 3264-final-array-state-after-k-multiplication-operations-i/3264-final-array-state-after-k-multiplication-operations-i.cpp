class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int min = INT_MAX;
        int index = 0;
        
        while(k--)
        {
            min= INT_MAX;
            for(int i=0; i<nums.size(); i++)
            {
                
                if(nums[i]<min)
                {
                    min = nums[i];
                    index = i;
                }
            }
            
            nums[index] = min * multiplier;
        }
        
        return nums;
    }
};