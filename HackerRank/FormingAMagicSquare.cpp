//question link https://www.hackerrank.com/challenges/magic-square-forming/problem
/*
* The strategy is to generate all magic squares of size 3x3, *
* then check the cost of converting the given square to the  *
* generated magic squares; finally the least of these costs  *
* is considered as the answer                                *
* Note - The sqaures have been defined as a 9x1 vector       *
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
//magic_squares stores all the magic sqaure which are generated
vector<vi> magic_squares;

//function for checking whether the given 9x1 vector forms a magic sqaure or not
bool is_magic_square(vi &given)
{
    //first row from top sum
    int sum1 = given[0] + given[1] + given[2];
    //second row
    int sum2 = given[3] + given[4] + given[5];
    if(sum1!=sum2) return false;
    //third row
    int sum3 = given[6] + given[7] + given[8];
    if(sum3!=sum2) return false;
    //first column from left
    int sum4 = given[0] + given[3] + given[6];
    if(sum4!=sum3) return false;
    //second column
    int sum5 = given[1] + given[4] + given[7];
    if(sum5!=sum4) return false;
    //third column
    int sum6 = given[2] + given[5] + given[8];
    if(sum6!=sum5) return false;
    //left diagonal
    int sum7 = given[0] + given[4] + given[8];
    if(sum7!=sum6) return false;
    //right diagonal
    int sum8 = given[2] + given[4] + given[6];
    if(sum8!=sum7) return false;
    return true;
}

//function for generating the magic squares
//only distinct integers are considered as the question mentions in the note,
//that the resulting magic square should have distinct integers in the range [1,9]
void generate_magic_squares()
{
    //filling the 9x1 vector with smallest permutation of [1,9] distinct values
    vi square;
    f(q, 1, 10)
        pb(square, q);

    do{
        //check if current permutation forms a magic square
        if(is_magic_square(square))
            pb(magic_squares, square);
        //next_permutation is an inbuilt routine
    }while(next_permutation(square.begin(), square.end()));
}

//function to find the minimum cost
int find_min_cost(vi &given)
{
    int min_ = INT_MAX;
    generate_magic_squares();
    //iterate through the different magic squares
    f(q, 0, magic_squares.size()){
        //compute the difference between given square and current magic square
        int diff = 0;
        f(w, 0, 9)
            diff+=abs(magic_squares[q][w]-given[w]);
        if(diff<min_)
            min_ = diff;
    }
    return min_;
}

int main()
{
    /*int t;
    cin>>t;
    while(t--){
    }*/
    //input too is stored in the form of 9x1 vector
    vi given;
    f(q, 0, 9){
        int x;
        cin>>x;
        pb(given, x);
    }
    int ans = find_min_cost(given);
    cout<<ans<<endl;
}

