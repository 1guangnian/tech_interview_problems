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
void goToMinimum(TreeNode *& root)
{
    while (root && root->left) {
        TreeNode *pre = root->left;
        while (pre->right) {
            pre = pre->right;
        }
        
        pre->right = root;
        root = root->left;
    }
}
void goToNext(TreeNode * & root, int &flag)
{
    if (flag == 1) {
        flag = 0;
        root = root->right;
    } else {
        if (root->left) {
            TreeNode *pre = root->left;
            while (pre->right && pre->right != root) {
                pre = pre->right;
            }
            if (pre->right == root) {
                pre->right = NULL;
                flag = 1;
                return;
            } else {
                pre->right = root;
                root = root->left;
            }
        } else {
            root = root->right;
        }
    }
    if (root && root->left)
        goToNext(root, flag);
}
vector<int> gao(TreeNode *r1, TreeNode *r2)
{
    vector<int> res;
    if (!r1 || !r2)
        return res;
    goToMinimum(r1);
    goToMinimum(r2);
    int flag1 = 0, flag2 = 0;
    while (r1 && r2) {
        //cout << r1->val << " " << r2->val << endl;
        if (r1->val == r2->val) {
            res.push_back(r1->val);
        }
        if (r1->val <= r2->val) {
            goToNext(r1, flag1);
        } else {
            goToNext(r2, flag2);
        }
    }
    return res;
}
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
    //cout << root->val << endl;
    dfs(root->right);
}
void random_sh(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++) {
        int j = rand()%(i+1);
        swap(a[i], a[j]);
    }
}
int main()
{
    srand((unsigned)time(0));
    int T = 1000;
    while (T--) {
        TreeNode *r1 = NULL, *r2 = NULL;
        vector<int> a;
        for (int i = 0; i < 10; i++)
            a.push_back(i);
        random_shuffle(a.begin(), a.end());
        random_sh(a);
        //int x[10] = {9,0,6,5,2,4,3,8,1,7};
        int x[10] = {6, 7, 0, 3, 1, 5, 2, 4, 8, 9};
        for (int i = 0; i < 10; i++)
            insert(r1, a[i]);
        dfs(r1);
        //cout << ".........." << endl;
        for (int i = 0; i < 10; i++)
            a[i] = i;
        random_shuffle(a.begin(), a.end());
        random_sh(a);
        //int y[10] = {9,7,5,8,4,0,6,3,2,1};
        int y[10] = {0, 8, 9, 6, 7, 4, 2, 5, 1, 3};
        for (int i = 0; i < 10; i++)
            insert(r2, a[i]);
        dfs(r2);
        //cout << "##########" << endl;
        vector<int> res = gao(r1, r2);
        set<int>S;
        for (auto x: res)
            S.insert(x);
        assert(S.size() == 10);
        //for (auto x: res)
        //  cout << x << endl;
        assert(res.size() == 10);
    }
    cout << "over" << endl;
    return 0;
}
