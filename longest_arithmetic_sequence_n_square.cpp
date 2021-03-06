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
const int N = 100;
int dp[N][N];
int bruteForce(vector<int> a)
{
    int res = min(2, (int)a.size());
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            int k = j + 1;
            int tp = 2;
            int pre = a[j], d = a[j] - a[i];
            while (k < a.size()) {
                if (a[k] == pre + d) {
                    tp++;
                    pre = a[k];
                }
                k++;
            }
            //if (res < tp) cout << i << " " << j << endl;
            res = max(res, tp);
            
        }
    }
    return res;
}
int gao(vector<int> a)
{
    int n = a.size();
    int res = min(2, n);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            dp[j][i] = 2;
        }
    }
    unordered_map<int, int> mp;
    /*
     * for each a[i], each d, we only care about two numbers: the closest two numbers x that |x-a[i]| = d
     * x1 is before a[i], x2 is after a[i]
     */
    for (int i = 1; i < n - 1; i++) {
        mp.clear();
        for (int j = i - 1; j >= 0; j--) {
            int d = a[i] - a[j];
            if (mp.find(d) == mp.end())
                mp[d] = j;
        }
        for (int j = i + 1; j < n; j++) {
            int d = a[j] - a[i];
            if (mp.find(d) != mp.end()) {
                dp[i][j] = max(dp[i][j], dp[mp[d]][i] + 1);
                res = max(res, dp[i][j]);
                /*
                 * if there are multiple a[i] + d after a[i], we only need to update the furthest one, as it will be
                 * the nearest one before the next number in the sequence
                 * but how do we know which one it is, if there are multiples?
                 * for example, if a[i] is 1, d is 2, we may have vector a like {-1, 1, 3, 5, 3}
                 * if we only update the last 3, it is wrong, because we don't know where 5 is
                 */
                //mp.erase(d);
            }
        }
        
    }
    return res;
}
int main ()
{
    srand(time(0));
    int T = 100;
    while (T--) {
        vector<int> a;
        int n = rand() % N + 1;
        //n = 40;
        for (int i = 1; i <= n; i++) {
            a.push_back(rand() % 100);
        }
        //sort(a.begin(), a.end()); //if the order doesn't matter
        int x = bruteForce(a);
        int y = gao(a);
        //for (auto t: a) cout << t << " "; cout << endl;
        //cout << "x=" << x << " y=" << y << endl;
        assert(x == y);
    }
    cout << "over" << endl;
    return 0;
}