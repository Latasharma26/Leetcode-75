class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; // Start pointer
        int right = height.size() - 1; // End pointer
        int maxArea = 0; // Variable to track the maximum area

        // Loop until the two pointers meet
        while (left < right) {
            // Calculate the area
            int currentHeight = min(height[left], height[right]);
            int currentWidth = right - left;
            int area = currentHeight * currentWidth;

            // Update maxArea if the current area is greater
            maxArea = max(maxArea, area);

            // Move the pointer of the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea; // Return the maximum area found
    }
};
