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
void insert(TreeNode *&root, int x) {
    TreeNode *t = new TreeNode(x);
    TreeNode *cur = root, *pre = NULL;
    while (cur) {
        pre = cur;
        if (x < cur->val)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (pre == NULL) {
        root = t;
        //cout << "root:" << x << endl;
    }
    else if (pre->val > x) {
        pre->left = t;
        //cout << pre->val << " <- " << x << endl;
    } else {
        pre->right = t;
        //cout << pre->val << " -> " << x<< endl;
    }
}
void dfs(TreeNode *root)
{
    if (!root)
        return;
    dfs(root->left);
    cout << root->val << " ";
    dfs(root->right);
}
void random_sh(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++) {
        int j = rand()%(i+1);
        swap(a[i], a[j]);
    }
}
TreeNode *find(TreeNode *root, int val) {
    TreeNode *t = root;
    while (t) {
        if (t->val == val)
            return t;
        if (t->val > val)
            t = t->left;
        else
            t = t->right;
    }
    return NULL;
}
TreeNode *findParent(TreeNode *root, int val)
{
    if (root->val == val)
        return NULL;
    TreeNode *pre = NULL;
    TreeNode *t = root;
    while (t->val != val) {
        pre = t;
        if (t->val > val)
            t = t->left;
        else
            t = t->right;
    }
    return pre;
}
TreeNode *findSuccessor(TreeNode *t)
{
    t = t->right;
    if (!t)
        return NULL;
    while (t->left) {
        t = t->left;
    }
    return t;
}
void deleteNode(TreeNode *&root, TreeNode *t)
{
    TreeNode *whoToDelete  = t;
    if (t->left && t->right)
        whoToDelete = findSuccessor(t);
    TreeNode *child;
    if (whoToDelete->left)
        child = whoToDelete->left;
    else
        child = whoToDelete->right;
    TreeNode *parent = findParent(root, whoToDelete->val);
    if (parent == NULL) {
        root = child;
    } else {
        if (parent->left == whoToDelete)
            parent->left = child;
        else
            parent->right = child;
    }
    if (t != whoToDelete)
        t->val = whoToDelete->val;
}
#define N 10
int main()
{
    cout << 9.0 / 14.0 << endl;
    srand((unsigned)time(0));
    TreeNode *root = NULL;
    vector<int> a;
    for (int i = 0; i < N; i++)
        a.push_back(i);
    random_sh(a);
    for (int i = 0; i < N; i++)
        insert(root, a[i]);
    for (int i = 0; i < N; i++) {
        TreeNode *t = find(root, i);
        deleteNode(root, t);
        dfs(root);
        cout << endl;
    }
    cout << "over" << endl;
    return 0;
}
