class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans = (ans xor nums[i]);
        }
        
        //cout << (2 xor 2) ;
        return ans;
    }
};