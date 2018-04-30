#include <bits/stdc++.h>
#include "GraphAdjacencyList.h"
#include "BFS.h"
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

int main()
{
    /*int t;
    cin>>t;
    while(t--){
    }*/
    Graph my_graph(5);
    my_graph.connect(0, 1);
    my_graph.connect(0, 3);
    my_graph.connect(1, 3);
    my_graph.connect(1, 2);
    my_graph.connect(3, 4);
    my_graph.BFS(0);
}
