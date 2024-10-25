/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;  // Start of the range
        int right = n; // End of the range

        while (left <= right) {
            int mid = left + (right - left) / 2; // Calculate the midpoint

            int result = guess(mid); // Make a guess

            if (result == 0) {
                return mid; // Correct guess
            } else if (result == -1) {
                right = mid - 1; // The guessed number is too high
            } else {
                left = mid + 1; // The guessed number is too low
            }
        }

        return -1; // This should not be reached since we will always find the number in the given range
    }
};
