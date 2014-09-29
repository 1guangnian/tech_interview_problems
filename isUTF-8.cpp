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
char res[3][12] = {"is utf-8", "is ascii", "don't know"};
int isUTF_8(const char *s, int len)
{
    int isAsc = true;
    int i = 0;
    while (i < len) {
        char x = *(s + i);
        if (x & 0x80) {
            isAsc = false;
            int nbytes = 0;
            while (x & 0x80) {
                nbytes++;
                x <<= 1;
            }
            if (nbytes < 2 || nbytes > 6)
                return 2;
            if (i + nbytes > len)
                return 2;
            for (int j = 1; j < nbytes; j++) {
                x = *(s + i + j);
                if ((x & 0xC0) != 0x80)
                    return 2;
            }
            i += nbytes;
        }
        else {
            i++;
        }
    }
    
    if (isAsc)
        return 1;
    else
        return 0;
}
int main ()
{
    /*char x = 0x87;
     for (int i = 0; i < 12; i++) {
     x <<= 1;
     cout << (x&1) << endl;
     }*/
    cout << res[isUTF_8("纠结", strlen("纠结"))] << endl;
    cout << res[isUTF_8("jerry", strlen("jerry"))] << endl;
    cout << res[isUTF_8("หนังสือ", strlen("หนังสือ"))] << endl;
    return 0;
}
