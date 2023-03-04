#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    public:
        unordered_map<int, list<int>> g;
        void addEdge(int u, int v, bool direction)
        {
            g[u].push_back(v);
            // if undirected graph
            if (!direction)g[v].push_back(u);
        }
        void printAdjList(){
            for(auto i:g){
                cout << i.first <<" -> ";
                for(auto j:i.second){
                    cout << j << ", ";
                }
                cout << endl;
            }
        }
};

int main(){
    int n;
    cout << "Enter Number of Nodes : ";
    cin >> n;
    int m;
    cout << "Enter Number of Edges : ";
    cin >> m;
    graph g;
    for (int i = 0; i < m;i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false);
    }
    g.printAdjList();
    return 0;
}
