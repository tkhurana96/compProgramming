#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define FORI(i, n) for (int(i) = 1; (i) <= (n); ++(i))
#define IN(x, y) ((y).find((x)) != (y).end())
#define ALL(t) t.begin(), t.end()
#define FOREACH(i, t) for (typeof(t.begin()) i = t.begin(); i != t.end(); i++)
#define REP(i, a, b) for (int(i) = (a); (i) <= (b); ++i)
#define REPD(i, a, b) for (int(i) = (a); (i) >= (b); --i)
#define REMAX(a, b) (a) = max((a), (b));
#define REMIN(a, b) (a) = min((a), (b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari << " = " << (vari) << endl;

typedef long long ll;
const int INF = 1e9;

const int T = 11000;
const int N = 1e6;
const int K = 1e6;

int main() {
  ios_base::sync_with_stdio(0);
  int sumn = 0;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    assert(n >= 1 && n <= N);
    assert(k >= 0 && k <= K);
    sumn += n;
    string a;
    cin >> a;
    assert(a.length() == n);
    int cost01 = 0;
    int cost10 = 0;
    FOR(i, n) {
      if (i % 2 == 0) {
        if (a[i] == '0')
          cost10++;
        else
          cost01++;
      } else {
        if (a[i] == '0')
          cost01++;
        else
          cost10++;
      }
    }
    if (min(cost01, cost10) <= k) {
      cout << 1 << endl;
      continue;
    }

    vi runs;
    int run_len = 1;
    REP(i, 1, n - 1) {
      if (a[i] != a[i - 1]) {
        runs.pb(run_len);
        run_len = 1;
      } else {
        run_len++;
      }
    }
    runs.pb(run_len);
    int lo = 2, hi = n;
    int res = n;
    while (lo <= hi) {
      int block_size = (lo + hi) / 2;
      int cost = 0;
      for (int len : runs) {
        cost += len / (block_size + 1);
      }
      if (cost <= k) {
        REMIN(res, block_size);
        hi = block_size - 1;
      } else {
        lo = block_size + 1;
      }
    }
    cout << res << endl;
  }

  return 0;
}