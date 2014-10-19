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

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define inf (1<<30)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
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
int main()
{
    srand(time(0));
    int T = 1000;
    while (T--) {
        int n = rand() % 10 + 1;
        int m = rand() % 10 + 1;
        vector<int> x;
        vector<int> y;
        vector<int> a;
        x.clear();
        y.clear();
        a.clear();
        for (int i = 0; i < n; i++)
            x.push_back(rand() % 100 + 1);
        sort(x.begin(), x.end());
        for (int i = 0; i < m; i++)
            y.push_back(rand() % x[n-1]);
        sort(y.begin(), y.end());
        for (int i = 0; i < n; i++)
            a.push_back(x[i]);
        for (int i = m - 1; i >= 0; i--)
            a.push_back(y[i]);
        int goal = a[n-1];
        n += m;
        m = 0;
        for (int i = 0; i < n; i++)
            if (i == 0 || a[i] != a[i-1])
                a[m++] = a[i];
        n = m;
        int l = 0, r = n - 1;
        while (l + 2 < r) {
            int mid = (l + r) / 2;
            int midmid = (mid + r) / 2;
            //cout << "l=" << l << " r=" << r << endl;
            //cout << "mid=" << a[mid] << " midmid=" << a[midmid] << endl;
            //mid may equal midmid
            if (a[mid] < a[midmid])
                l = mid;
            else
                r = midmid;
        }
        //cout << l << " " << r << endl;
        int res = a[l];
        if (l + 1 <= n - 1 && res < a[l+1])
            res = a[l+1];
        if (l + 2 <= n - 1 && res < a[l+2])
            res = a[l+2];
        //for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
        //cout << res << " " << goal << endl;
        assert(res == goal);
        //cout << a[l] << endl;
    }
    cout << "over" << endl;
}
/*
 8
 3 5 7 14 9 8 2 1
 */