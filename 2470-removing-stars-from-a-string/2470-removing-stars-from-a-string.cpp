#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> charStack;

        for (char c : s) {
            if (c == '*') {
                if (!charStack.empty()) {
                    charStack.pop(); // Remove the closest non-star character
                }
            } else {
                charStack.push(c); // Push regular characters onto the stack
            }
        }

        // Build the result string from the stack
        string result;
        while (!charStack.empty()) {
            result += charStack.top(); // Add characters to the result
            charStack.pop(); // Remove from stack
        }

        // Since we added characters from the stack, reverse the result to maintain order
        reverse(result.begin(), result.end());

        return result;
    }
};
