#include <iostream>
#include <vector>
#include <string>
#include <queue>

class IGraph{
public:
    virtual size_t size()=0;
    virtual void AddEdge(int to, int from)=0;
    virtual std::vector<int> GetEdge(int v)=0;
};

class OrMGraph : IGraph{
private:
    std::vector<std::vector<bool>> matrix{};

public:
    OrMGraph(int n):matrix(n, std::vector<bool>(n, false)){}

    size_t size() override {return matrix.size();}

    void AddEdge (int to, int from) override{
        matrix[from][to] = true;
    }

    std::vector<int> GetEdge(int v) override{
        std::vector<int> edges{};
        for(int i=0; i < matrix.size(); ++i){
            if(matrix[v][i])
                edges.push_back(i);
        }
        return edges;
    }
};


void dfs(IGraph& g, int v, int p){
    std::vector<std::string> color(g.size());
    color[v] = "gray";
    for(int i: g.GetEdge(v)){
        if (color[i] == "white")
            dfs(g, i, v);
    }
    color[v] = "black";
}

void bfs(IGraph& g, int v){
    std::vector<std::string> colors(g.size(), "white");
    std::queue<int> q;
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        for(auto i: g.GetEdge(v))
            if(colors[i]=="white")
                q.push(v);
    }
}

std::vector<int> BFS(IGraph& G, int v){
    std::vector<int> dist (G.size() - 1);
    std::vector<std::string> colors(G.size(), "white");
    std::queue<std::pair<int, int>> q;
    q.push({v, 0});
    while(!q.empty()){
        std::pair<int,int> tmp = q.front();
        v = tmp.first;
        int d = tmp.second;
        colors[v] = "black";
        for (int i: G.GetEdge(v)){
            if (colors[i]=="white")
                q.push({i, d+1});
        }
        dist[v] = d;
        q.pop();
    }
    return dist;
}

int main() {
    int v_num, e_num;
    int s, l, m;
    std::cin >> v_num >> e_num;
    OrMGraph G(v_num);
    //auto

    //for(int i = )
}
