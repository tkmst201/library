#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "DataStructure/SegmentTree.cpp"
#include "Mathematics/ModInt.cpp"

#include <cstdio>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	using mint = ModInt<998244353>;
	using pmm = std::pair<mint, mint>;
	
	SegmentTree<pmm> seg(N, [](const pmm & a, const pmm & b) -> pmm {
		return {a.first * b.first, b.first * a.second + b.second};
	}, pmm(1, 0));
	
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		seg.set(i, {a, b});
	}
	
	while (Q--) {
		int q, a, b, c;
		scanf("%d %d %d %d", &q, &a, &b, &c);
		if (q == 0) {
			seg.set(a, {b, c});
		}
		else {
			pmm v = seg.fold(a, b);
			mint ans = v.first * c + v.second;
			printf("%lld\n", ans.get());
		}
	}
}