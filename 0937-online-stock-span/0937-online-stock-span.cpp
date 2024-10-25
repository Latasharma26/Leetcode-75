class StockSpanner {
public:
    stack<pair<int,int>>A;
     int count;
    int c;
    StockSpanner() {
       count=0;
       c=0;
    }
     
    int next(int price) {
       
        count++;
       
        while(!A.empty() && A.top().first<=price)
        {
            A.pop();
        }
        c= !A.empty()?count-A.top().second:count;
        A.push(make_pair(price,count));
        return c;
    }
};