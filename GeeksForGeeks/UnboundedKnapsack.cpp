//question link - https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
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

vi val, wt;
//1D memory for DP
int memory[1010];

//DP solution
int ub_ksack(int W)
{
    //base condition
    if(W==0) return 0;
    //if the answer has been calculated
    if(memory[W]!=0) return memory[W];
    int n = val.size();
    f(q, 0, n){
        //if the current value's weight is within the permissible weight
        if(wt[q]<=W)
            //the answer is the max of the values found so far
            //and the current value
            memory[W] = max(memory[W], val[q] + ub_ksack(W-wt[q]));
    }
    return memory[W];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, W, x;
        cin>>n>>W;
        val.clear();
        wt.clear();
        //reading input
        f(q, 0, n){
            cin>>x;
            pb(val, x);
        }
        f(q, 0, n){
            cin>>x;
            pb(wt, x);
        }
        //initialising memory
        f(q, 0, 1010)
            memory[q] = 0;
        cout<<ub_ksack(W)<<endl;
    }
}

