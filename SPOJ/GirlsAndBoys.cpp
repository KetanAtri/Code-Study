// question link - http://www.spoj.com/problems/GIRLSNBS/
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
    int g, b;
    while(cin>>g>>b){
        if(g==-1 && b==-1) return 0;
        int x = g>b? g: b;
        int y = g<b? g: b;
        //edge case
        if(x==y){
            if(x==0) cout<<0<<endl;
            else cout<<1<<endl;
        }
        //using the pigeonhole principle
        //x items are to be put in y+1 gaps
        //all the gaps will contain the average number of items if the gaps
        //can be filled evenly otherwise, at least on gap will have one more item
        else{
            if(x%(y+1)==0) cout<<x/(y+1)<<endl;
            else cout<<(x/(y+1))+1<<endl;
        }
    }
}

