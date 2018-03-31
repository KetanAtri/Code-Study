// question link - http://www.spoj.com/problems/PT07Z/
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
//ans stores the longest path
int ans = 0;
//done[q] = true, if node q has been visited
bool done[10009] = {false};

int dfs(vector<int> *v, int root)
{
    //temp stores the length of the longest path in a tree rooted at root - 1
    //l1 stores the longest path
    //l2 stores the second longest path
    int temp, l1=-1, l2=-1;
    //root has been visited
    done[root] = true;
    //go through all the children of root
    f(q, 0, v[root].size()){
        if(!done[v[root][q]]){
            //store the longest path from root in temp
            temp = dfs(v, v[root][q]);
            //if the path is longes than the longest
            //rearrange l1 and l2 to store the longest and 2nd longes paths respectively
            if(temp>=l1){
                l2 = l1;
                l1 = temp;
            }
            //if the path is longer than 2nd longest only
            else if(temp>l2) l2 = temp;
        }
    }
    //2 is added to the sum of longest and 2nd longest path for
    //the 2 edges which connect these to the root
    ans = max(ans, l1+l2+2);
    //l1 + 1 is returned to accout for the edge between the root
    //and longest path
    return l1+1;
}

int main()
{
    /*int t;
    cin>>t;
    while(t--){
    }*/
    int n;
    cin>>n;
    vector<int> v[n+5];
    f(q, 0, n-1){
        int a, b;
        cin>>a>>b;
        pb(v[a], b);
        pb(v[b], a);
    }
    dfs(v, 1);
    cout<<ans<<endl;
}
