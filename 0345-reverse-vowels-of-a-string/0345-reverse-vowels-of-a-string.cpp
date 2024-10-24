class Solution {
public:
    string reverseVowels(string s) {
        // Define a set of vowels for easy checking
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        // Two pointers approach
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            // Move left pointer until we find a vowel
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                ++left;
            }
            // Move right pointer until we find a vowel
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                --right;
            }
            // Swap the vowels
            if (left < right) {
                swap(s[left], s[right]);
                ++left;
                --right;
            }
        }
        
        return s;
    }
};
