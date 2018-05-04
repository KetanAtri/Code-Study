// question link - http://www.spoj.com/problems/NHAY/
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

//the code uses KMP algorithm
//the following function is to create LPS
//or longest proper prefix which is also a suffix array
void constructLPS(int* lps, string &pat)
{
    //inital value
    lps[0] = 0;
    int len = 0, i = 1;
    while(i<pat.size()){
        //if a match is found
        if(pat[len]==pat[i]){
            len++;
            lps[i] = len;
            i++;
        }
        //if no match is found
        else{
            //this part is akin to KMP
            //len is set as back as the lps value
            if(len!=0)
                len = lps[len-1];
            //if len is at 0 there is no match so lps is set to 0
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    /*int t;
    cin>>t;
    while(t--){
    }*/
    int len;
    while(cin>>len){
        string pat;
        cin>>pat;
        int lps[pat.size()];
        constructLPS(lps, pat);
        int j = 0, i = 0;
        char x;
        //for reading \n after string input
        x = getchar();
        //reading the first character of haystack/text
        x = getchar();
        while(x!='\n'){
            //if a match is found read the next character
            if(pat[j]==x){
                j++;
                x = getchar();
                i++;
            }
            //if pat.size() matches are found then an occurrence is found
            if(j==pat.size()){
                cout<<i-j<<endl;
                //backtrack j using lps to avoid rechecking
                //i is currently at the next character after the match
                j = lps[j-1];
            }
            //if no match is found
            else if(pat[j]!=x){
                //backtrack j using lps
                if(j!=0) j = lps[j-1];
                //if j cannot be backtraced further
                //read the next character and check from there
                else{
                    x = getchar();
                    i++;
                }
            }
        }
        cout<<endl;
    }
}

