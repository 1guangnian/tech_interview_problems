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
int a[55], n;
int main()
{
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int l = 0, r = n - 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            int midmid = (mid + r) / 2;
            //mid may equal midmid
            if (a[mid] <= a[midmid])
                l = mid;
            else
                r = midmid;
        }
        //cout << l << " " << r << endl;
        if (a[l] < a[r])
            l = r;
        cout << a[l] << endl;
    }
}
/*
 8
 3 5 7 14 9 8 2 1
 */