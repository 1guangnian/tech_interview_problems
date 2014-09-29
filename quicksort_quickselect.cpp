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
void random_sh(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++) {
        int j = rand()%(i+1);
        swap(a[i], a[j]);
    }
}
#define N 100
int medianOfThree(vector<int> &a, int l, int r)
{
    int mid = (l + r) >> 1;
    if (a[r] < a[l])
        swap(a[l], a[r]);
    if (a[mid] < a[l])
        swap(a[l], a[mid]);
    if (a[r] < a[mid])
        swap(a[mid], a[r]);
    return mid;
}
int partition(vector<int> &a, int l ,int r)
{
    if (l + 2 > r) {
        if(a[l] > a[r])
            swap(a[l], a[r]);
        return r;
    }
    int pivotIndex = medianOfThree(a, l, r);
    int storeIndex = l;
    swap(a[pivotIndex], a[r]);
    for (int i = l; i < r; i++) {
        if (a[i] < a[r])
            swap(a[i], a[storeIndex++]);
    }
    swap(a[storeIndex], a[r]);
    return storeIndex;
}
void quickSort(vector<int> &a, int l, int r)
{
    if (l < r) {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}
int quickSelect(vector<int> &a, int l, int r, int K)
{
    int p = partition(a, l, r);
    if (p - l + 1 == K)
        return a[p];
    else if (p - l + 1 > K)
        return quickSelect(a, l, p - 1, K);
    else
        return quickSelect(a, p + 1, r, K - (p - l + 1));
}
int main()
{
    srand(time(0));
    int T = 1000;
    while (T--) {
        vector<int> a;
        for (int i = 0; i < N; i++)
            a.push_back(i);
        random_sh(a);
        quickSort(a, 0, N - 1);
        for (int i = 0;  i < N; i++)
            assert(i == a[i]);
        int K = rand() % N + 1;
        random_sh(a);
        int  x = quickSelect(a, 0, N - 1, K);
        quickSort(a, 0, N - 1);
        assert(x == a[K-1]);
    }
    cout << "over" << endl;
}