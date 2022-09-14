//https://leetcode.com/problems/course-schedule-ii/

#include <vector>
#include <algorithm>

class Solution {
public:
    enum class Colors{
        White = 1,
        Gray,
        Black
    };
    bool is_cicle = false;
    std::vector<Colors> colors;
    std::vector<std::vector<int>> graph;

    void dfs(int v, std::vector<int>& order) {
        colors[v] = Colors::Gray;
        for (auto& i : graph[v]) {
            if (colors[i] == Colors::White)
                dfs(i, order);
            else if (colors[i] == Colors::Gray)
                is_cicle =  true;
            if (is_cicle)
                return;
        }
        colors[v] = Colors::Black;
        order.push_back(v);
    }

    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        colors.resize(numCourses, Colors::White);
        graph.resize(numCourses);
        for (auto i : prerequisites)
            graph[i[1]].push_back(i[0]);
        std::vector<int> order;
        for (int i = 0; i < graph.size(); ++i)
            if (colors[i] == Colors::White)
                dfs(i, order);
        if (is_cicle)
            return {};
        reverse(order.begin(), order.end());
        return order;
    }
};