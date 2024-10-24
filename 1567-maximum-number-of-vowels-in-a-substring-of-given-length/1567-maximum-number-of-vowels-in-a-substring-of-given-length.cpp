class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowelCount = 0;
        int currentVowelCount = 0;
        
        // Define the set of vowel characters
        const string vowels = "aeiou";

        // Step 1: Count vowels in the first 'k' characters
        for (int i = 0; i < k; ++i) {
            if (vowels.find(s[i]) != string::npos) {
                currentVowelCount++;
            }
        }
        maxVowelCount = currentVowelCount; // Initialize maxVowelCount with the first window's count

        // Step 2: Slide the window through the string
        for (int i = k; i < s.length(); ++i) {
            // Check the new character entering the window
            if (vowels.find(s[i]) != string::npos) {
                currentVowelCount++;
            }
            // Check the character exiting the window
            if (vowels.find(s[i - k]) != string::npos) {
                currentVowelCount--;
            }

            // Update maxVowelCount if current count is greater
            maxVowelCount = max(maxVowelCount, currentVowelCount);
        }

        return maxVowelCount;
    }
};