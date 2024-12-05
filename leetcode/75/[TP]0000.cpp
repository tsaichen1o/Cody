#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
#include <stdexcept>

// Function to find the in-degree of each node
std::unordered_map<std::string, int> find_indegree(const std::unordered_map<std::string, std::vector<std::string>>& graph) {
    std::unordered_map<std::string, int> indegree;
    for (const auto& [node, neighbors] : graph) {
        indegree[node] = 0;
    }
    for (const auto& [node, neighbors] : graph) {
        for (const auto& neighbor : neighbors) {
            indegree[neighbor] += 1;
        }
    }
    return indegree;
}

// Function to perform topological sort
std::vector<std::string> topo_sort(const std::unordered_map<std::string, std::vector<std::string>>& graph) {
    std::vector<std::string> result;
    std::queue<std::string> q;
    std::unordered_map<std::string, int> indegree = find_indegree(graph);

    // Add nodes with zero in-degree to the queue
    for (const auto& [node, node_indegree] : indegree) {
        if (node_indegree == 0) {
            q.emplace(node);
        }
    }

    // Process the nodes
    while (!q.empty()) {
        std::string node = q.front();
        q.pop();
        result.emplace_back(node);

        for (const auto& neighbor : graph.at(node)) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.emplace(neighbor);
            }
        }
    }

    // Check if all nodes are processed
    if (result.size() == graph.size()) {
        return result;
    } else {
        throw std::runtime_error{"Invalid topo sort: graph contains a cycle"};
    }
}

// Function to perform task scheduling
std::vector<std::string> task_scheduling(const std::vector<std::string>& tasks, const std::vector<std::vector<std::string>>& requirements) {
    std::unordered_map<std::string, std::vector<std::string>> graph;

    // Initialize the graph
    for (const auto& task : tasks) {
        graph[task] = {};
    }

    // Add the requirements to the graph
    for (const auto& req : requirements) {
        graph[req[0]].emplace_back(req[1]);
    }

    // Perform topological sort
    return topo_sort(graph);
}

int main() {
    std::vector<std::string> tasks = {"a", "b", "c", "d"};
    std::vector<std::vector<std::string>> requirements = {{"a", "b"}, {"c", "b"}, {"b", "d"}};

    try {
        std::vector<std::string> result = task_scheduling(tasks, requirements);
        for (const auto& task : result) {
            std::cout << task << " ";
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
