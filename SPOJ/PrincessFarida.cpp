// question link - http://www.spoj.com/problems/FARIDA/
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

//DP is used to get the solution
vi coins;
long long memory[10010];

//DP function
long long maximize(int index)
{
    //if the value has been computed
    if(memory[index]!=-1) return memory[index];
    //base cases
    //if first element is checked
    if(index==0) memory[index] = coins[index];
    //if the first two elemenst are checked
    else if(index==1) memory[index] = max(coins[1], coins[0]);
    //current maximum is max of:
    //current val + maximum from sub array not having previous element
    //maximum from sub array having previous element
    else memory[index] = max(coins[index]+maximize(index-2), maximize(index-1));
    return memory[index];
}

int main()
{
    int t;
    cin>>t;
    int counter = 1;
    while(t--){
        coins.clear();
        int n, x;
        cin>>n;
        //initializing the memory for DP
        f(q, 0, 10010) memory[q] = -1;
        f(q, 0, n){
            cin>>x;
            pb(coins, x);
        }
        cout<<"Case "<<counter<<": "<<maximize(n-1)<<endl;
        counter++;
    }
}

