class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0; // Pointer to write to the compressed array
        int read = 0;  // Pointer to read from the original array

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // Count the occurrences of currentChar
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = currentChar;

            // Write the count if greater than 1
            if (count > 1) {
                for (char digit : to_string(count)) {
                    chars[write++] = digit;
                }
            }
        }

        return write; // The new length of the compressed array
    }
};
