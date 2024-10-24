class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If str1 + str2 is not equal to str2 + str1, there's no common divisor string
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        // Find the gcd of the lengths of str1 and str2
        int gcdLength = gcd(str1.length(), str2.length());
        // Return the prefix of str1 up to the gcd length
        return str1.substr(0, gcdLength);
    }
};;