#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        // Mapping from digits to corresponding letters
        std::vector<std::string> digitToLetters = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        std::vector<std::string> result;
        if (digits.empty()) {
            return result; // return empty list for empty input
        }

        // Start the backtracking process
        backtrack(digits, digitToLetters, result, "", 0);
        return result;
    }
    
private:
    void backtrack(const std::string &digits, const std::vector<std::string> &digitToLetters,
                   std::vector<std::string> &result, std::string current, int index) {
        // If the current combination is the same length as digits
        if (current.length() == digits.length()) {
            result.push_back(current); // Add the combination to the result
            return;
        }

        // Get the current digit and its corresponding letters
        int digit = digits[index] - '0'; // Convert char to int
        const std::string &letters = digitToLetters[digit];

        // Explore each letter for the current digit
        for (char letter : letters) {
            backtrack(digits, digitToLetters, result, current + letter, index + 1);
        }
    }
};
