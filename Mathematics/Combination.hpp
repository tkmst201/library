#ifndef INCLUDE_GUARD_COMBINATION_HPP
#define INCLUDE_GUARD_COMBINATION_HPP

/*
last-updated: 2020/01/15

# 仕様
template引数 には ModInt を渡す。(require get_mod())

Construct : Amortized Θ(max k + (logM)^2 ) ??
Query : Amortized Θ(1) ?? 謎

Comination(size_type sz = 1) :
	sz! を計算できるだけ前計算

T fact(size_type k) :
	k! を求める

T finv(size_type k) :
	(k!)^-1 を求める

T inv(size_type k) :
	k^-1 を求める

:private:
void build(size_type k) :
	k! が計算できるように確保
*/

#include <vector>
#include <cassert>
#include <algorithm>

template<typename T>
struct Combination {
public:
	using size_type = std::size_t;
	
	Combination(size_type sz = 1) : _fact(1, 1), _finv(1, 1), _inv(1, 1) { build(sz); }
	
	T fact(size_type k) { if (k >= T::get_mod()) return 0; build(k); return _fact[k]; }
	T finv(size_type k) { assert(k < T::get_mod()); build(k); return _finv[k]; }
	T inv(size_type k) { assert(k > 0 && k < T::get_mod()); build(k); return _inv[k]; }
	
	T operator ()(int n, int r) { return c(n, r); }
	T c(int n, int r) {
		if (r < 0 || n < r) return 0;
		return fact(n) * finv(r) * finv(n - r);
	}
	
private:
	std::vector<T> _fact, _finv, _inv;
	static constexpr size_type MAX_LIMIT = 50000000;
	
	void build(size_type k) {
		if (_fact.size() > k) return;
		assert(k < MAX_LIMIT);
		size_type sz = std::min({MAX_LIMIT, static_cast<size_type>(T::get_mod()), std::max(_fact.size() * 2, k + 1)});
		size_type presz = _fact.size();
		_fact.resize(sz);
		_finv.resize(sz);
		_inv.resize(sz);
		
		for (size_type i = presz; i < sz; ++i) _fact[i] = _fact[i - 1] * i;
		_finv[sz - 1] = T(_fact[sz - 1]).inverse();
		for (size_type i = sz - 1; i > presz; --i) {
			_finv[i - 1] = _finv[i] * i;
			_inv[i] = _fact[i - 1] * _finv[i];
		}
		_inv[presz] = _fact[presz - 1] * _finv[presz];
	}
};

#endif // INCLUDE_GUARD_COMBINATION_HPP