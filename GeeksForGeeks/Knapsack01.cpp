//question link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
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

vi wt, val;
int memory[110][110];

//solution using DP
int kSack(int w, int n)
{
    //if all the items have been checked
    //or the weight is 0
    if(n==-1 || w==0) return 0;
    //if the values has been computed
    if(memory[w][n]!=-1) return memory[w][n];
    //if the weight of the current item is greater than remaining weight
    //then leave this item
    if(wt[n]>w){
        memory[w][n] = kSack(w, n-1);
        return memory[w][n];
    }
    //the answer for the given weight and number of items is maximum of
    //including the current item, reducing total weight and adding its value and
    //excluding the current item
    memory[w][n] = max(val[n] + kSack(w-wt[n], n-1), kSack(w, n-1));
    return memory[w][n];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, w, x;
        cin>>n>>w;
        wt.clear();
        val.clear();
        f(q, 0, n){
            cin>>x;
            pb(val, x);
        }
        f(q, 0, n){
            cin>>x;
            pb(wt, x);
        }
        //initializing memory
        f(q, 0, 110)
            f(e, 0, 110)
                memory[q][e] = -1;
        cout<<kSack(w, n-1)<<endl;
    }
}

