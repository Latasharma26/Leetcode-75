class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for (int i = 0; i < len && n > 0; ++i) {
            // Check if the current spot is empty and can plant a flower
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty or if we're at the boundaries
                bool emptyLeft = (i == 0 || flowerbed[i - 1] == 0);
                bool emptyRight = (i == len - 1 || flowerbed[i + 1] == 0);
                
                if (emptyLeft && emptyRight) {
                    // Plant a flower here
                    flowerbed[i] = 1;
                    --n;  // Reduce the number of flowers we need to plant
                }
            }
        }
        return n == 0; // Return true if we've successfully planted all flowers
    }
};
