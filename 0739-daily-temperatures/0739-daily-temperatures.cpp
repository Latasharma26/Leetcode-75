class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> past_t;
        vector<int> ans(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            
            while(!past_t.empty()){//不是空的
                
                int cur_t = temperatures[past_t.top()];//stack最上面的溫度
                if( cur_t < temperatures[i] ){//stack最上方小於當天溫度
                    int day = i - past_t.top();//天數相減
                    ans[past_t.top()] =day; 
                    past_t.pop();
                }else{
                    break;
                }
            }
            past_t.push(i);//push index
        }
        
        return ans;
    }
};