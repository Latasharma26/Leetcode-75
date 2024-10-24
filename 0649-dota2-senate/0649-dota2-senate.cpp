class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();
        
        // Fill the queues with the indices of each senator
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        // Process the rounds
        while (!radiant.empty() && !dire.empty()) {
            int rIndex = radiant.front();
            int dIndex = dire.front();

            radiant.pop();
            dire.pop();

            // The senator with the smaller index can ban the other
            if (rIndex < dIndex) {
                radiant.push(rIndex + n); // Add n to make the index larger for the next round
            } else {
                dire.push(dIndex + n); // Add n to make the index larger for the next round
            }
        }

        // Determine the winner
        return radiant.empty() ? "Dire" : "Radiant";
    }
};