// question link - http://www.spoj.com/problems/BUGLIFE/
#include <bits/stdc++.h>
using namespace std;

#define f(q, a, b) for(int q = int(a); q<int(b); q++)
#define fb(q, a, b) for(int q = int(a); q>int(b); q--)
#define pb(v, x) v.push_back(x)
#define A first
#define B second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef map<int, int> mii;

//ifstream in("input");
//ofstream out("output");

// read string with spaces, string is a char array here
// scanf ("%[^\n]%*c", string)

class Graph
{
    std::vector<std::vector<int> > adj_list;

    public:
    //to construct a graph with 'vertices' number of vertices
    Graph(int vertices)
    {
        std::vector<int> temp;
        adj_list.assign(vertices+1, temp);
    }
    //function to connet to vertices of a graph
    void connect(int a, int b)
    {
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    //function to check whether the graph is bipartite or not using BFS
    bool BFS_check(int source)
    {
        //'visited' keeps track of vertices which have been visited
        //'colour' - each node is assigned a color (1 or 2) to signify
        //which set in the bipartite graph it belongs to, initially all
        //nodes have colour 0 i.e. no colour
        std::vector<int> visited, colour;
        visited.assign(adj_list.size()+1, 0);
        colour.assign(adj_list.size()+1, 0);

        visited[source] = 1;
        //queue used in BFS
        std::queue<int> useful;
        useful.push(source);
        while(!useful.empty()){
            int explore = useful.front(), use_colour = 1;
            //cout<<"Exploring: "<<explore<<endl;
            useful.pop();
            //if the current node has not been coloured
            if(colour[explore]==0){
                colour[explore] = 1;
                use_colour = 2;
            }
            //the neighbours are assigned colour opposite to colour of the current node
            else use_colour = colour[explore]==1? 2: 1;
            for(int q=0; q!=adj_list[explore].size(); q++){
                int current = adj_list[explore][q];
                //if neighbour has the same colour as the current node
                //then bipartite property of graph is not satisfied
                if(colour[current]==colour[explore]) return false;
                //colour the neighbour with opposite colour
                else if(colour[current]==0) colour[current] = use_colour;
                if(!visited[current]){
                    useful.push(current);
                    visited[current] = 1;
                }
            }
        }
        //bipartite property holds
        return true;
    }
};

int main()
{
    int t, scenario = 1;
    cin>>t;
    while(t--){
        int n, i, a, b;
        cin>>n>>i;
        Graph bug_i(n);
        f(q, 0, i){
            cin>>a>>b;
            bug_i.connect(a, b);
        }
        cout<<"Scenario #"<<scenario++<<":"<<endl;
        if(i==0 || bug_i.BFS_check(a)) cout<<"No suspicious bugs found!"<<endl;
        else cout<<"Suspicious bugs found!"<<endl;
    }
}
