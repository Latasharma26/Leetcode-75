class Solution {
public:
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph;

    void addEdge(const std::string& a, const std::string& b, double value) {
        graph[a].emplace_back(b, value);
        graph[b].emplace_back(a, 1.0 / value);
    }

    double dfs(const std::string& start, const std::string& end, std::unordered_set<std::string>& visited) {
        if (start == end) return 1.0;
        visited.insert(start);
        
        for (const auto& neighbor : graph[start]) {
            const auto& nextNode = neighbor.first;
            double weight = neighbor.second;

            if (visited.count(nextNode) == 0) {
                double product = dfs(nextNode, end, visited);
                if (product != -1.0) {
                    return product * weight;
                }
            }
        }
        return -1.0;
    }

    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, 
                                      std::vector<double>& values, 
                                      std::vector<std::vector<std::string>>& queries) {
        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            addEdge(equations[i][0], equations[i][1], values[i]);
        }
        
        std::vector<double> results;
        for (const auto& query : queries) {
            const std::string& start = query[0];
            const std::string& end = query[1];
            
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                results.push_back(-1.0);
            } else {
                std::unordered_set<std::string> visited;
                double result = dfs(start, end, visited);
                results.push_back(result);
            }
        }
        
        return results;
    }
};