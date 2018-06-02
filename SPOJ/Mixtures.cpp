//question link - http://www.spoj.com/problems/MIXTURES/
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

//stores the initial colours
vi colour;
//DP memory for colours of mixtures
ull col_memory[110][110];
//DP memory for smoke of mixtures
ull smoke_memory[110][110];

//using MCM logic
//minSmoke(a, b) finds the minimum smoke that can be generated for mixtures in range [a, b]
ull minSmoke(int a, int b)
{
    //if minimum smoke for range [a, b] has been calculated
    if(smoke_memory[a][b]!=-1) return smoke_memory[a][b];
    ull min = ULONG_MAX;
    //k defines the grouping
    f(k, a, b){
        //smoke for range [a,b] is calculated using
        //smoke for range [a,k] + smoke for range [k+1, b] + smoke for combination of resulting mixtures
        //col_memory stores the resulting colours of the range after the mixture is made
        ull smoke = minSmoke(a, k) + minSmoke(k+1, b) + (col_memory[a][k]*col_memory[k+1][b]);
        if(smoke < min){
            min = smoke;
            //col_memory is updated for a range when minimum smoke is found
            col_memory[a][b] = (col_memory[a][k] + col_memory[k+1][b])%100;
        }
    }
    //smoke for the range is the minimum smoke obtained after trying different groupings
    smoke_memory[a][b] = min;
    return smoke_memory[a][b];
}

int main()
{
    /*int t;
    cin>>t;
    while(t--){
    }*/
    int n;
    while(cin>>n){
        colour.clear();
        int x;
        //reading input
        f(q, 0, n){
            cin>>x;
            pb(colour, x);
        }
        //initializing memory
        f(q, 0, n)
            f(w, 0, n){
                //smoke for single mixture is 0
                //colour for single mixture is its own colour
                if(q==w){
                    smoke_memory[q][w] = 0;
                    col_memory[q][w] = colour[q];
                }
                //initializing with null values
                else{
                    smoke_memory[q][w] = -1;
                    col_memory[q][w] = -1;
                }
            }
        cout<<minSmoke(0, n-1)<<endl;
    }
}

