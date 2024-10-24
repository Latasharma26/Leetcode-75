class RecentCounter {
private:
    queue<int> requests;  // Queue to store timestamps of requests

public:
    RecentCounter() {
        // Constructor initializes the queue
    }
    
    int ping(int t) {
        // Add the current ping to the queue
        requests.push(t);
        
        // Remove requests that are older than t - 3000 milliseconds
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();  // Remove the oldest request
        }
        
        // Return the number of requests in the last 3000 milliseconds
        return requests.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */