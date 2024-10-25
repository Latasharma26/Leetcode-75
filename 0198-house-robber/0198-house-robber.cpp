class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
        vector<int>money(nums.size(),0);
        money[0] = nums[0];
        money[1] = max(nums[0],nums[1]);
        //第3個最大= 搶1,3 不搶2 or 搶2 不搶1,3  = max(1+3,2)   -> rob(n) = max(rob(n-2)+rob(n),rob(n-1))
        for(int i=2;i<nums.size();i++){
            money[i] = max(money[i-1],nums[i]+money[i-2]);
            //cout << i+1 << " " << money[i] << endl;
        }
        
        // for(auto m:money)
        //     cout << m << " ";
        
        
        return money.back();
    }
};