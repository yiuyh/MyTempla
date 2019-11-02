#include <bits/stdc++.h>
using namespace std;
priority_queue<int> a, b;
main () {
	int64_t ans = 0;
	int n, l, w; cin >> n >> l >> w;
	for(int i = 1; i <= n; i ++) {
		int p, w; cin >> p >> w;
		if(w == 1) a.push(-p);
		else 	   b.push(-p - l);
	}
	while(a.size()) {
		auto it = -a.top(); a.pop();
		while(b.size() and -b.top() <= it) b.pop();
		while(b.size() and abs(it - b.top()) / (-b.top() - it) >= w) b.pop();
		ans += b.size();
	}
	cout << ans;
}
