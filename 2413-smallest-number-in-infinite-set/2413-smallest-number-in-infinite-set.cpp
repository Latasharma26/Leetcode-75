#include <queue>
#include <unordered_set>

class SmallestInfiniteSet {
private:
    int next; // The next smallest integer that will be popped
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Min-heap for added back numbers
    std::unordered_set<int> addedBack; // To track added back numbers

public:
    SmallestInfiniteSet() : next(1) { } // Initialize next to 1

    int popSmallest() {
        if (!minHeap.empty()) {
            int smallest = minHeap.top(); // Get the smallest number from the heap
            minHeap.pop();
            addedBack.erase(smallest); // Remove from the set of added back numbers
            return smallest;
        }
        return next++; // If the heap is empty, return the current next and increment it
    }

    void addBack(int num) {
        if (num < next && addedBack.find(num) == addedBack.end()) {
            minHeap.push(num); // Add num to the heap
            addedBack.insert(num); // Mark it as added back
        }
    }
};
