#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // Step 1: Sort the products
        sort(products.begin(), products.end());
        vector<vector<string>> suggestions;
        
        string prefix = "";
        
        // Step 2: Iterate through each character of the search word
        for (char c : searchWord) {
            prefix += c;
            vector<string> currentSuggestions;
            
            // Step 3: Find matching products for the current prefix
            for (const string& product : products) {
                if (product.find(prefix) == 0) { // Check if product starts with the prefix
                    currentSuggestions.push_back(product);
                    if (currentSuggestions.size() == 3) { // We only need the top 3 suggestions
                        break;
                    }
                }
            }
            
            // Add the current suggestions to the result
            suggestions.push_back(currentSuggestions);
        }
        
        return suggestions;
    }
};
