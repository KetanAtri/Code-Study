// question link - http://www.spoj.com/problems/BISHOPS/
// the answer to the solution is n + n-2
// this can be obtained by observing the pattern in smaller test cases
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

//since n can be upto 100 digits
struct BigInt
{
    //integer is for storing the number, n is for storing the size
    int integer[110], n;
    //construction using string
    BigInt(string s)
    {
        memset(integer, 0, sizeof(integer));
        n = s.size();
        int last = 109;
        //units place is the last element
        fb(q, n-1, -1){
            integer[last] = int(s[q]) - int('0');
            last--;
        }
    }
    //function to subtract 2 from Big Integer
    void subtract_2()
    {
        int last = 109;
        //dealing with carry over case
        if(integer[last]<2){
            integer[last]+=10;
            last--;
            //multiple carry overs
            while(integer[last]==0){
                integer[last]+=9;
                last--;
            }
            integer[last]--;
        }
        last = 109;
        //subtraction after carry over has been taken care of
        integer[last] = integer[last]-2;

    }
    //function to add two big integers
    void add(BigInt b)
    {
        int lim = 110-n;
        int index = 109, carry = 0;
        while(index>=lim){
            //add two digits and the carry value
            int sum = integer[index] + b.integer[index] + carry;
            int dg = sum%10;
            carry = sum/10;
            integer[index] = dg;
            index--;
        }
        //if carry is available after complete addition
        if(carry!=0){
            integer[index]+=carry;
            n++;
        }

    }
    //function to print the big integer
    void print()
    {
        int start = 110 - n;
        bool flag = true;
        f(q, start, 110){
            //to deal with leading zeroes
            if(n>1 && flag && integer[q]==0) continue;
            else if(integer[q]!=0) flag = false;
            cout<<integer[q];
        }
    }
};

int main()
{
    string s;
    while(cin>>s){
        if(s=="1"){ cout<<1<<endl; continue; }
        BigInt n(s), temp(s);
        n.subtract_2();
        n.add(temp);
        n.print();
        cout<<endl;
    }
}

