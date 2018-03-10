//question link http://www.spoj.com/problems/PT07Y/
/*
* Data structure used UFDS                               *
* UFDS - Union Find Disjoint Set                         *
* Way of representing a number of disjoint sets, this DS *
* supports union, findSet, isSameSet operation in nearly *
* O(1) time, the implementation has been borrowed from   *
* the book Competitive Programming 3 by Steven and Felix *
* Halim, this UFDS follows rank heuristic for union of   *
* two sets                                               *
*                                                        *
* Using this DS we create n (n=number of nodes) disjoint *
* sets, then unite two based on the edges given in the   *
* question. If at any point of time an edge between two  *
* previously connected components is received, the DS    *
* helps with its quick identification of such scenarios  *
*/
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

class UFDS
{
    //array based representation for parents and ranks
    vi parent, rank;
    public:
    //constructor
    UFDS(int N)
    {
        rank.assign(N, 0);
        parent.assign(N, 0);
        f(q, 0, N) parent[q] = q;
    }
    //finding the representative element of set of elemenet x
    int findSet(int x) { return parent[x]==x? x: (parent[x] = findSet(parent[x])); }
    bool isSameSet(int x, int y) { return findSet(x)==findSet(y); }
    //uniting two sets based on rank heuristic
    void unionSet(int x, int y)
    {
        if(!isSameSet(x, y)){
            int a = findSet(x);
            int b = findSet(y);
            if(rank[a]>rank[b]) parent[b] = a;
            else{
                parent[a] = b;
                if(rank[a]==rank[b]) rank[b]++;
            }
        }
    }
};

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    UFDS graph(nodes);
    f(q, 0, edges){
        int a, b;
        cin>>a>>b;
        //if a and b are previously connected via some edge
        if(graph.isSameSet(a, b)){
            cout<<"NO"<<endl;
            return 0;
        }
        graph.unionSet(a, b);
    }
    //if none of the edges form a cycle
    cout<<"YES"<<endl;
}

