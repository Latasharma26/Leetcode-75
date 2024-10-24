class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;  // Stack to hold the counts of repetitions
        stack<string> result; // Stack to hold the results as we build them
        string currentString; // Current string being built
        int k = 0; // Current number of repetitions

        for (char ch : s) {
            if (isdigit(ch)) {
                // If the character is a digit, update k
                k = k * 10 + (ch - '0'); // Handle multi-digit numbers
            } else if (ch == '[') {
                // Push current count and string onto stacks
                counts.push(k);
                result.push(currentString);
                k = 0; // Reset k for the next number
                currentString.clear(); // Reset current string
            } else if (ch == ']') {
                // Pop count and previous string from the stacks
                string temp = currentString;
                currentString = result.top();
                result.pop();
                int count = counts.top();
                counts.pop();

                // Append the decoded string the appropriate number of times
                for (int i = 0; i < count; ++i) {
                    currentString += temp;
                }
            } else {
                // If it's a letter, add it to the current string
                currentString += ch;
            }
        }

        return currentString;
    }
};

