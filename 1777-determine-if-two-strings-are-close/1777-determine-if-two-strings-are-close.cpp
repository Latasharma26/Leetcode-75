
#include <array>
#include <string>
using namespace std;

class Solution {
    
    inline static const int ALPHABET_SIZE = 26;

public:
    // C++20: ...(string_view wordOne, string_view wordTwo)..., if 'wordOne' and 'wordTwo' are not modified in the method
    bool closeStrings(const string& wordOne, const string& wordTwo) const {
        if (wordOne.length() != wordTwo.length()) {
            return false;
        }

        array<int, ALPHABET_SIZE> frequencyWordTwo{};
        array<int, ALPHABET_SIZE> frequencyWordOne{};
        for (int i = 0; i < wordOne.length(); ++i) {
            ++frequencyWordTwo[wordOne[i] - 'a'];
            ++frequencyWordOne[wordTwo[i] - 'a'];
        }

        return wordsHaveSameUniqueLettersRegardlessOfFrequency(frequencyWordTwo, frequencyWordOne)
                && wordsHaveSameFrequencyPatternRegardlessOfLetters(frequencyWordTwo, frequencyWordOne);
    }

private:
    // C++20: ...(span<const int> frequencyWordOne, span<const int> frequencyWordTwo)...
    bool wordsHaveSameUniqueLettersRegardlessOfFrequency(const array<int, ALPHABET_SIZE>& frequencyWordOne, const array<int, ALPHABET_SIZE>& frequencyWordTwo) const {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (frequencyWordOne[i] == 0 ^ frequencyWordTwo[i] == 0) {
                return false;
            }
        }
        return true;
    }

    // ...(span<int>...) does not work without significant modifications of the method.
    // class span does not implement the comparison operators, thus spans can not be compared with '=='
    bool wordsHaveSameFrequencyPatternRegardlessOfLetters(array<int, ALPHABET_SIZE>& frequencyWordOne, array<int, ALPHABET_SIZE>& frequencyWordTwo) const {
        // C++20: std::ranges::sort(frequenyWordOne); std::ranges::sort(frequenyWordTwo);
        sort(frequencyWordOne.begin(), frequencyWordOne.end());
        sort(frequencyWordTwo.begin(), frequencyWordTwo.end());
        return frequencyWordOne == frequencyWordTwo;
    }
};