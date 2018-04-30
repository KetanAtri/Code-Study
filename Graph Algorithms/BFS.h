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
    void BFS(int source)
    {
        //keeps track of vertices which have been visited
        std::vector<int> visited;
        visited.assign(adj_list.size(), 0);

        visited[source] = 1;
        //queue used in BFS
        std::queue<int> useful;
        useful.push(source);
        while(!useful.empty()){
            int explore = useful.front();
            std::cout<<"Currently expanding: "<<explore<<std::endl;
            useful.pop();
            std::cout<<"new neighbours found:"<<std::endl;
            for(int q=0; q!=adj_list[explore].size(); q++){
                int current = adj_list[explore][q];
                if(!visited[current]){
                    std::cout<<current<<" ";
                    useful.push(current);
                    visited[current] = 1;
                }
            }
            std::cout<<std::endl;
        }
    }
};
