#include <iostream>
#include <vector>

void floyd(std::vector<std::vector<int>>& G){
    for(int k = 0; k < G.size(); ++k)
        for(int i = 0; i < G.size(); ++i) {
            if (i == k)
                continue;
            if (G[i][k])
                for (int j = 0; j < G.size(); ++j)
                    G[i][j] = G[i][j] | G[k][j];
        }
}

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> G(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            char c;
            std::cin>>c;
            G[i][j] = int(c - '0');
        }
    floyd(G);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            std::cout<<G[i][j];
        std::cout<<std::endl;
    }
}