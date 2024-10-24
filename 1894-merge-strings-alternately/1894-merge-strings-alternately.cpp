class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int n1 = word1.size(), n2 = word2.size();
        int i = 0, j = 0;

        // Loop through both strings and append characters alternately
        while (i < n1 || j < n2) {
            if (i < n1) result += word1[i++];
            if (j < n2) result += word2[j++];
        }
        
        return result;
    }
};
