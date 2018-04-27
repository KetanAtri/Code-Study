// question link - http://www.spoj.com/problems/PARTY/
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

int main()
{
    /*int t;
    cin>>t;
    while(t--){
    }*/
    int budget, n_parties;
    while(cin>>budget>>n_parties){
        if(budget==0 && n_parties==0) return 0;
        int cost[n_parties], fun[n_parties];
        f(q, 0, n_parties)
            cin>>cost[q]>>fun[q];
        //the dp table is created in bottom up fashion
        //it stores the maximum fun that can be attained using q parties and w available weight
        int dp[n_parties+1][budget+1];
        f(q, 0, n_parties+1)
            f(w, 0, budget+1){
                //if the weight is 0 or no parties are considered then fun is 0
                if(q==0 || w==0) dp[q][w] = 0;
                //if the current party's cost can be accomodated within available cost
                //then the fun attainable is maximum of:
                //a. fun attained at this party + fun attained with n-1 parties and w - cost of this party
                //b. fun attained with n-1 parties only
                else if(cost[q-1]<=w) dp[q][w] = max(fun[q-1] + dp[q-1][w-cost[q-1]], dp[q-1][w]);
                //if the cost of the current party cannot be accomodated within the available cost
                else dp[q][w] = dp[q-1][w];
            }
        //the maximum fun attained is sotred at this position in the dp table
        int total_fun = dp[n_parties][budget];
        int min_cost = 0;
        //the cost should be minimized
        f(q, 0, budget+1){
            if(dp[n_parties][q]==total_fun){
                min_cost = q;
                break;
            }
        }
        cout<<min_cost<<" "<<total_fun<<endl;
    }
}

