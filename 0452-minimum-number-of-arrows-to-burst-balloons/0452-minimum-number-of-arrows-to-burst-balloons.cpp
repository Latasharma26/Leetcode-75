class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            if(a[0] != b[0]){
                return a[0] < b[0];
            }
            else {
                return a[1] < b[1];
            }
        });

        int arrowCount = 1;
        int prevEnd = points[0][1];

        for(int i = 1; i < points.size(); i++){
            if(prevEnd < points[i][0]){
                prevEnd = points[i][1];
                arrowCount++;
            }
            else {
                if(prevEnd > points[i][1]) prevEnd = points[i][1];
            }
        }

        return arrowCount;
    }
};
