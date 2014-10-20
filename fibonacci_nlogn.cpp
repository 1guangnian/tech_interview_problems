#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define inf (1<<30)

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};
struct M {
    int n, m;
    int a[2][2];
    M() {}
    M(int n, int m): n(n), m(m){}
};
M mul(M x, M y)
{
    M res(x.n, y.m);
    for (int i = 0; i < x.n; i++) {
        for (int j = 0; j < y.m; j++) {
            res.a[i][j] = 0;
            for (int k = 0; k < x.m; k++) {
                res.a[i][j] += x.a[i][k] * y.a[k][j];
            }
        }
    }
    return res;
}
M matrix_pow(M x, int n)
{
    M base(2, 2);
    base.a[0][0] = base.a[1][1] = 1;
    base.a[0][1] = base.a[1][0] = 0;
    while (n) {
        if (n & 1)
            base = mul(base, x);
        x = mul(x, x);
        n >>= 1;
    }
    return base;
}
int f[100];
int main()
{
    M x(2, 2);
    x.a[0][0] = 0;
    x.a[0][1] = 1;
    x.a[1][0] = x.a[1][1] = 1;
    f[0] = 0; f[1] = 1;
    for (int i = 2; i <= 40; i++)
        f[i] = f[i-1] + f[i-2];
    int n;
    int T = 40;
    for (n = 0; n <= T; n++) {
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        
        M p = matrix_pow(x, n - 1);
        //cout << p.a[1][1] << endl;
        assert(p.a[1][1] == f[n]);
    }
    cout << "over" << endl;
}