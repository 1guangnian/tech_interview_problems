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
/*
 * give unique numbers in range [l, r], find the missing ones
 * gao({1,3}, 1, 4) will return {2,4}
 */
vector<int> gao(vector<int> a, int l ,int r) {
    
    if (l == r) {
        return vector<int> {l};
    }
    int N = r - l + 1;
    int sqrN = sqrt(N);
    int tot = N / sqrN + (N % sqrN != 0);
    //cout << "l=" << l << " r=" << r << endl;for (auto t: a)cout << t << " ";    cout << endl;
    //cout << "sqrN=" << sqrN << " tot=" << tot << endl;
    vector<int> sum(tot, 0);
    for (int i = 0; i < a.size(); i++) {
        int idx = (a[i] - l) / sqrN;
        sum[idx] += a[i];
    }
    for (int i = l; i <= r; i++) {
        int idx = (i - l) / sqrN;
        sum[idx] -= i;
    }
    vector<int> section;
    for (int i = 0; i < tot; i++) {
        //cout << "i=" << i << " sum[i]=" << sum[i] << endl;
        if (sum[i] != 0)
            section.push_back(i);
    }
    vector<int> res;
    int idx = 0;
    for (int i = 0; i < section.size(); i++) {
        int j = section[i];
        int first = l + sqrN * j;
        int last = min(r, l + sqrN * j + sqrN - 1);
        vector<int> x;
        //need a to be sorted
        while (idx < a.size() && a[idx] < first)
            idx++;
        while (idx < a.size() && a[idx] <= last)
            x.push_back(a[idx++]);
        x = gao(x, first, last);
        for (auto t: x) {
            res.push_back(t);
        }
    }
    return res;
}
int main()
{
    srand(time(0));
    int T = 200;
    while (T--) {
        int n = rand() % 100 + 2;
        int i = rand() % n + 1;
        int K = rand() % n + 1; //how many missing numbers;
        set<int> s;
        vector<int> missing;
        while (K--) {
            int j = rand() % n + 1;
            while (s.find(j) != s.end())
                j = rand() % n + 1;
            s.insert(j);
            missing.push_back(j);
        }
        sort(missing.begin(), missing.end());
        vector<int> a;
        for (int k = 1; k <= n; k++) {
            if (s.find(k) == s.end())
                a.push_back(k);
        }
        sort(a.begin(), a.end());
        //cout << "n=" << n << endl;for (auto x: a)cout << x << " ";cout << endl;
        vector<int> res = gao(a, 1, n);
        //cout << res[0] << " " << res[1] << endl;
        assert(res.size() == missing.size());
        for (i = 0; i < res.size(); i++) {
            //cout << "i=" << i << " res[i]= " << res[i] << " missing[i] = " << missing[i] << endl;
            assert(res[i] == missing[i]);
        }
    }
    cout << "over" << endl;
    return 0;
}
