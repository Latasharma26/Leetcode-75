class Solution {
public:
    string reverseWords(string s) {
        // Initialize a stringstream to handle the input string
        stringstream ss(s);
        string word;
        vector<string> words;

        // Extract each word, ignoring any extra spaces
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Join the words back into a single string with spaces
        return join(words, " ");
    }

private:
    // Helper function to join the words with a single space
    string join(const vector<string>& words, const string& delimiter) {
        string result;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) result += delimiter;
            result += words[i];
        }
        return result;
    }
};
