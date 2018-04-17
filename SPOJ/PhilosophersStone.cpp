// question link - http://www.spoj.com/problems/NGM/
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

//memory for DP
int memory[110][110];

int explore(vector<vi>& grid, int row, int col)
{
    //if the current row and column have already been discovered
    if(memory[row][col]!=-1) return memory[row][col];
    //exploring the three possible paths
    int a = col-1>=0? explore(grid, row+1, col-1): -1;
    int b = explore(grid, row+1, col);
    int c = col+1<grid[row].size()? explore(grid, row+1, col+1): -1;
    //chosing the path with maximum number of stones
    memory[row][col] = grid[row][col] + max(a, max(b, c));
    return memory[row][col];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int h, w;
        //initalizing the memory with -1
        f(q, 0, 110)
            f(e, 0, 110)
                memory[q][e] = -1;
        cin>>h>>w;
        vector<vi> grid;
        grid.assign(h, vector<int>(w, 0));
        f(q, 0, h)
            f(e, 0, w){
                cin>>grid[q][e];
                //the last row of the grid fills the memory as well
                if(q==h-1) memory[q][e] = grid[q][e];
            }
        int ans = 0;
        //explore each column of the first row
        f(q, 0, w){
            int temp = explore(grid, 0, q);
            if(temp>ans) ans = temp;
        }
        cout<<ans<<endl;
    }
}
