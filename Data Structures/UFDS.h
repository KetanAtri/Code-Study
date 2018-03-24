/*
* UFDS - Union Find Disjoint Set                         *
* Way of representing a number of disjoint sets, this DS *
* supports union, findSet, isSameSet operation in nearly *
* O(1) time, the implementation has been borrowed from   *
* the book Competitive Programming 3 by Steven and Felix *
* Halim, this UFDS follows rank heuristic for union of   *
* two sets                                               *
*/
#include <vector>

#define f(q, a, b) for(int q=int(a); q!=int(b); q++)

typedef std::vector<int> vi;

class UFDS
{
    //array based representation for parents and ranks
    //setSize is the size of set to which an element belongs
    vi parent, rank, setSize;
    //number of disjoint sets present
    int numSets;
    public:
    //constructor
    UFDS(int N)
    {
        rank.assign(N, 0);
        setSize.assign(N, 1);
        parent.assign(N, 0);
        f(q, 0, N) parent[q] = q;
        numSets = N;
    }
    //finding the representative element of set of elemenet x
    int findSet(int x) { return parent[x]==x? x: (parent[x] = findSet(parent[x])); }
    bool isSameSet(int x, int y) { return findSet(x)==findSet(y); }
    //uniting two sets based on rank heuristic
    void unionSet(int x, int y)
    {
        if(!isSameSet(x, y)){
            numSets--;
            int a = findSet(x);
            int b = findSet(y);
            if(rank[a]>rank[b]){
                parent[b] = a;
                setSize[a]+=setSize[b];
            }
            else{
                parent[a] = b;
                setSize[b]+=setSize[a];
                if(rank[a]==rank[b]) rank[b]++;
            }
        }
    }
    //find the size of the set contatining element a
    int sizeOfSet(int a){
        int x = findSet(a);
        return setSize[x];
    }
    int numDisjointSets() { return numSets; }
};


