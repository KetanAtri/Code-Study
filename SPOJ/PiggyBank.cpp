//question link - http://www.spoj.com/problems/PIGBANK/
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

//for storing the values and weights of coins
vi val, wt;
//DP memory
int memory[10010];
//flag for checking if total weight can be consumed
bool flag;

//DP solution
int minVal(int W)
{
    //if the entire weight has been consumed
    if(W==0){
        //set the flag
        flag = true;
        //base condition
        return 0;
    }
    //if the value has been computed
    if(memory[W]!=INT_MAX) return memory[W];
    int n = val.size();
    //iterate through all the coins
    f(q, 0, n)
        //if the weight of current coin can be accomodated
        if(wt[q]<=W){
            int temp2 = minVal(W-wt[q]);
            //flag is set if the entire weight has been consumed
            //memory[W] is set to -1 if W=0 cannot be achieved,
            //otherwise it tells the minimum value possible
            if(flag || temp2!=-1){
                //unset the flag
                flag = false;
                memory[W] = min(memory[W], val[q]+temp2);
            }
        }
    //if no updation was performed on memory[W]
    //it means that no combination results in complete consumption of weight
    //at that time the memory[W] is set to -1 to indicate impossible weight
    if(memory[W]==INT_MAX) memory[W] = -1;
    return memory[W];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        //initializing
        val.clear();
        wt.clear();
        f(q, 0, 10010)
            memory[q] = INT_MAX;
        flag = false;
        //reading input
        int E, F, N, x, W;
        cin>>E>>F>>N;
        W = F-E;
        f(q, 0, N){
            cin>>x;
            pb(val, x);
            cin>>x;
            pb(wt, x);
        }
        //procedure call
        int min = minVal(W);
        if(min==-1)
            cout<<"This is impossible."<<endl;
        else
            cout<<"The minimum amount of money in the piggy-bank is "<<min<<"."<<endl;
    }
}
