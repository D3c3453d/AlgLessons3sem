//kosaraju's algorithm strong connection components

#include <vector>
#include <algorithm>
#include <iostream>

void dfs(std::vector<std::vector<int>>& graph, int v, std::vector<bool>& visited, std::vector<int>& order) {
    visited[v] = true;
    for (auto& i : graph[v])
        if (!visited[i])
            dfs(graph, i, visited, order);

    order.push_back(v);
}

std::vector<std::vector<int>> get_SCC(std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> inverted(graph.size());
    for (int i = 0; i< graph.size(); ++i) {
        for (auto& v : graph[i]) {
            inverted[v].push_back(i);
        }
    }


    std::vector<int> order;
    std::vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i])
            dfs(graph, i, visited, order);
    }


    std::reverse(order.begin(), order.end());
    std::vector<std::vector<int>> SCC;
    visited.assign(graph.size(), false);

    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]){
            std::vector<int> group;
            dfs(inverted, i, visited, group);

            SCC.push_back(group);
        }

    }

    return SCC;
}