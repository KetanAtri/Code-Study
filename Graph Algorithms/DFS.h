#include <vector>
#include <queue>
#include <stdio.h>

class Graph
{
    std::vector<std::vector<int> > adj_list;

    public:
    //to construct a graph with 'vertices' number of vertices
    Graph(int vertices)
    {
        std::vector<int> temp;
        adj_list.assign(vertices, temp);
    }
    //function to connet to vertices of a graph
    void connect(int a, int b)
    {
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    //function to perform DFS on graph
    void DFS()
    {
        std::vector<int> visited;
        visited.assign(adj_list.size(), 0);
        for(int q=0; q!=adj_list.size(); q++){
            if(!visited[q]){
                std::cout<<"Currently exploring: "<<q<<std::endl;
                DFSexplore(q, visited);
                std::cout<<"Exploration done"<<std::endl;
            }
        }
    }
    void DFSexplore(int source, std::vector<int> &visited)
    {
        visited[source] = 1;
        std::cout<<source<<" ";
        for(int q=0; q!=adj_list[source].size(); q++){
            int new_source = adj_list[source][q];
            if(!visited[new_source])
                DFSexplore(new_source, visited);
        }
    }
};

