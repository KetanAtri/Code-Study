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

//check if distance x positioning is possible
int func(vi &st, int x, int cows)
{
    int temp = 1;
    //place first cow in the first stall
    int prev = st[0];
    f(q, 1, st.size())
        //place the next cow in the earliest possible
        //correct position
        if(st[q]-prev>=x){
            temp++;
            //if all the cows have been placed
            if(temp==cows) return 1;
            prev = st[q];
        }
    //if all the cows cannot be placed
    return 0;
}

//perform binary search on the largest minimum distance
//the range is [0, st[last]-st[first]]
//any point in this range is checked greedily by the above function
void binarySearch(vi &st, int cows)
{
    int l = 0;
    int u = st[st.size()-1] - st[0];
    while(l<=u){
        int mid = (l+u)/2;
        if(func(st, mid, cows)) l = mid+1;
        else u = mid-1;
    }
    //'l' will exceed 'u' by 1, if mid=u was the correct answer
    //that is why display is done one behind the last correct 'l'
    //l = 0 is an edge case
    if(l!=0)
        cout<<l-1<<endl;
    else cout<<l<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int stalls, cows;
        cin>>stalls>>cows;
        vi st;
        f(q, 0, stalls){
            int x;
            cin>>x;
            pb(st, x);
        }
        sort(st.begin(), st.end());
        binarySearch(st, cows);
    }
}
