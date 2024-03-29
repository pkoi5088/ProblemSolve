#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f;

int n;
vector<pair<ll, ll>> p;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	ll s, e;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		p.push_back(make_pair(s, e));
	}
	sort(p.begin(), p.end());
	ll ans = 0;
	s = -INF, e = -INF;
	for(int i=0;i<p.size(); i++){
		auto cur = p[i];
		ll ns = cur.first, ne = cur.second;
		if (s <= ns && ne <= e)continue;	// case 1
		ans += ne - ns;
		if (ns < e) {				// case 2
			ans -= (e - ns);
		}
		s = ns;
		e = ne;
	}
	cout << ans;
}