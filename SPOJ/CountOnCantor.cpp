// question link - http://www.spoj.com/problems/CANTON/
/*
* Following are the first 25 terms in the enumeration:      *
* 1/1 1/2 2/1 3/1 2/2                                       *
* 1/3 1/4 2/3 3/2 4/1                                       *
* 5/1 4/2 3/3 2/4 1/5                                       *
* 1/6 2/5 3/4 4/3 5/2                                       *
* 6/1 7/1 6/2 5/3 4/4                                       *
* From these the pattern is easily observable, first the    *
* denominator is increased and numerator is decreased, till *
* the numerator is equal to 1, once this is reached, the    *
* roles are inverted, i.e. the denominator is decreased and *
* numerator is increased till again the denominator reaches *
* 1. Note that after 1 is reached one iteration is continued*
* for increasing the numerator/denominator by 1.            *
*/
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

int main()
{
    int t;
    cin>>t;
    while(t--){
        //num - numerator, den = denominator, term = term of the enumeration
        int n, num = 1, den = 1, term = 1;
        //first the denominator is increased
        bool inc_den = true;
        cin>>n;
        //implementation of the above pattern
        while(term!=n){
            //denominator is being increased
            while(inc_den && term!=n){
                term++;
                //den is increased once even when num = 1
                den++;
                //if numerator is not 1 it is decreased
                if(num>1) num--;
                //if denominator is increased when numerator is 1, switch of roles takes place
                else { inc_den = false; break;}
            }
            //same logic as above with roles switched
            while(!inc_den && term!=n){
                term++;
                num++;
                if(den>1) den--;
                else { inc_den = true; break;}
            }
        }
        //displaying the output
        cout<<"TERM "<<n<<" IS "<<num<<"/"<<den<<endl;
    }
}

