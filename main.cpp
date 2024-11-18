#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll N, K;

bool Check(ll h, ll m, ll s) {
  if (h == K || m == K || s == K) {
    return true;
  }

  if (h % 10 == K || m % 10 == K || s % 10 == K) {
    return true;
  }

  if (h / 10 == K || m / 10 == K || s / 10 == K) {
    return true;
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N >> K;
  ll ans = 0;
  ll h = 0;
  ll m = 0;
  ll s = 0;
  while (h <= N) {
    if (Check(h, m, s)) {
      ++ans;
    }

    ++s;
    if (s == 60) {
      ++m;
      s = 0;
    }

    if (m == 60) {
      ++h;
      m = 0;
    }
  }

  cout << ans;

  return 0;
}