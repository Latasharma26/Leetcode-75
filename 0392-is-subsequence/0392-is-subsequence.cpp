class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0; // Pointer for string s
        int tIndex = 0; // Pointer for string t

        // Loop until either pointer reaches the end of its string
        while (sIndex < s.length() && tIndex < t.length()) {
            // If characters match, move the s pointer
            if (s[sIndex] == t[tIndex]) {
                sIndex++;
            }
            // Always move the t pointer
            tIndex++;
        }

        // If we have traversed all characters of s, it is a subsequence
        return sIndex == s.length();
    }
};
