#include "iostream"
#include "vector"
#include "queue"


class IGraph{
public:
    virtual size_t size() = 0;
    virtual void AddEdge(int to, int from) = 0;
    virtual std::vector<int> GetEdge(int v) = 0;
};


class OrMGraph : public IGraph{
private:
    std::vector<std::vector<bool>> matrix {};

public:
    OrMGraph(int n): matrix(n, std::vector<bool> (n, false)) {};

    size_t size() override  { return matrix.size();};

    void AddEdge(int to, int from){
        matrix[from][to] = true;
    }

    std::vector<int> GetEdge(int v) override{
        std::vector<int> edges{};
        for (int i = 0; i < matrix.size(); ++i){
            if (matrix[v][i])
                edges.push_back(i);
        }
        return edges;
    }
};


void dfs(IGraph& g, int v, int p){
    std::vector<std::string> color(g.size());
    color[v] = "gray";

    for (int i: g.GetEdge(v)){
        if (color[i] == "white")
            dfs(g, i, v);
    }
    color[v] = "black";
}


auto bfs(IGraph& g, int v){
    std::vector<int> dist (g.size() - 1);
    std::vector<std::string> color(g.size(), "white");
    std::queue<std::pair<int, int>> q;

    q.push({v, 0});

    while ( !q.empty() ){
        auto tmp = q.front();
        v = tmp.first;
        int d = tmp.second;
        color[v] = "black";

        for (auto i: g.GetEdge(v)){
            if (color[i] == "white")
                q.push({i, d + 1});
        }
        dist[v] = d;
        q.pop();
    }
    return dist;
}




int main(){
    int v_num, e_num;
    int S, L, M;
    std::cin >> v_num >> e_num;
    OrMGraph G(v_num);

    auto s_length = bfs(G, S);
    auto l_length = bfs(G, L);
    auto m_length = bfs(G, M);

    int min_dist = s_length[0] + m_length[0] + l_length[0];

    for (int i = 0; i < v_num; ++i){
        min_dist = std::min(min_dist, s_length[i] + m_length[i] + l_length[i]);
    }
    std::cout << min_dist;
    return 0;
}