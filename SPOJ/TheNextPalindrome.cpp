//question link http://www.spoj.com/problems/PALIN/
/*
* If the input comprises of all 9's then the answer is 1 followed by n-1 0's *
* and then 1 (here n is the number of digits in the given number             *
* For other cases the documentation with the code does the explanation       *
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
    //reading input
    int t;
    cin>>t;
    while(t--){
        //since input size is large it is read as a string and then converted to number
        string s;
        cin>>s;
        int num[1000010], n = s.size();
        //boolean variable for checking the all digits as 9 case
        bool all9 = true;
        f(q, 0, n){
            num[q] = int(s[q]) - int('0');
            if(all9 && num[q]!=9) all9 = false;
        }
        //dealing with the all 9's scenario
        if(all9){
            cout<<"1";
            f(q, 0, n){
                if(q==n-1) cout<<"1";
                else cout<<"0";
            }
            cout<<endl;
            continue;
        }
        /*
        * now the number is split into two halves, 123 has 1 and 3 as two halves and 1234 has 12 and 34 *
        * similarly the mid is comprised of 2 in 123 and 23 in 1234. Following this scenario three      *
        * conditions arise:
        * 1. The number is palindrome
        * 2. The left half can be copied to right half and problem is complete
        * 3. The left half is copied to the right half but the resulting number is smaller than original*
        * For cases 1 and 3 we will need to increment the mid, if mid is 9 then the increment will have *
        * to be cascaded futher down; in all 3 cases we first create a mirror of the left half in the   *
        * right half and then proceed for further computation.                                          *
        */
        //finding the left half and right half
        int mid = n/2, left = mid-1;
        int right = n%2? mid+1: mid;
        bool increment = false;
        //if the number is a palindrome case is checked here
        while(left>-1 && num[left]==num[right]){
            left--;
            right++;
        }
        /*
        * if left<0 it means we have scanned the whole array and the two halves were equal meaning the *
        * number is a palindrome, otherwise we check if the left half is smaller, which corresponds to *
        * case 3, either of these two will mean that we need to increment the mid hence the boolean    *
        * variable increment is set to true if either one of them is true                              *
        */
        if(left<0 || num[left]<num[right]) increment = true;
        //copy the left half to the right half
        while(left>=0) num[right++] = num[left--];
        //case 1 and 3 are handled here
        if(increment){
            int add = 1;
            left = mid-1;
            //if the number of digits is odd
            if(n%2!=0){
                num[mid]+=add;
                //add will be 1 if num[mid] was 9 otherwise no cascading required
                add = num[mid]/10;
                //if num[mid] was 9 this step will make it 0 after incrementation
                num[mid]%=10;
                right = mid+1;
            }
            else right = mid;
            //cascade the effect of incrementing mid, note that this only takes place if mid is comprised of 9 or 99
            //same logic as above is carried out here
            while(left>=0){
                num[left]+=add;
                add = num[left]/10;
                num[left]%=10;
                num[right++] = num[left--];
            }
        }
        //displaying the output
        f(q, 0, n)
            cout<<num[q];
        cout<<endl;
    }
}
