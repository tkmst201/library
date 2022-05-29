---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SuccintBitVector.hpp
    title: "\u7C21\u6F54\u30D3\u30C3\u30C8\u30D9\u30AF\u30C8\u30EB"
  - icon: ':heavy_check_mark:'
    path: DataStructure/WaveletMatrix.hpp
    title: Wavelet Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C
  bundledCode: "#line 1 \"Test/WaveletMatrix.select.range_k.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C\"\r\n\r\
    \n#line 1 \"DataStructure/WaveletMatrix.hpp\"\n\n\n\r\n#line 1 \"DataStructure/SuccintBitVector.hpp\"\
    \n\n\n\r\n#include <vector>\r\n#include <cstdint>\r\n#include <algorithm>\r\n\
    #include <cassert>\r\n\r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/SuccintBitVector.hpp\r\
    \n */\r\nstruct SuccintBitVector {\r\n\tusing size_type = std::size_t;\r\n\tusing\
    \ uint32 = std::uint32_t;\r\n\t\r\nprivate:\r\n\tusing uint8 = std::uint8_t;\r\
    \n\t\r\n\tstatic constexpr size_type LARGE = 8;\r\n\tstatic constexpr size_type\
    \ SMALL = 3;\r\n\t\r\nprivate:\r\n\tsize_type n;\r\n\tstd::vector<uint8> bits;\r\
    \n\tstd::vector<uint32> large;\r\n\tstd::vector<uint8> small;\r\n\t\r\npublic:\r\
    \n\texplicit SuccintBitVector(size_type n)\r\n\t\t: n(n), bits(n == 0 ? 0 : ((n\
    \ - 1) >> SMALL) + 1, 0u) {}\r\n\t\r\n\texplicit SuccintBitVector(const std::vector<uint8>\
    \ & bits)\r\n\t\t: n(bits.size() << SMALL), bits(bits) {}\r\n\t\r\n\tvoid build()\
    \ {\r\n\t\tlarge.assign(((n - 1) >> LARGE) + 1, 0);\r\n\t\tsmall.assign(((n -\
    \ 1) >> SMALL) + 1, 0);\r\n\t\tfor (uint32 i = 0, lidx = 0; i < bits.size(); i\
    \ += 1u << (LARGE - SMALL), ++lidx) {\r\n\t\t\tif (lidx > 0) large[lidx] = large[lidx\
    \ - 1] + small[i - 1] + pop_count(bits[i - 1]);\r\n\t\t\tsmall[i] = 0;\r\n\t\t\
    \tfor (uint32 j = i + 1; j < std::min<uint32>(bits.size(), i + (1u << (LARGE -\
    \ SMALL))); ++j) {\r\n\t\t\t\tsmall[j] = small[j - 1] + pop_count(bits[j - 1]);\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tsize_type size() const noexcept {\r\n\t\t\
    return n;\r\n\t}\r\n\t\r\n\tvoid set(size_type i) noexcept {\r\n\t\tassert(i <\
    \ n);\r\n\t\tbits[i >> SMALL] |= 1u << (i & ~(~0u << SMALL));\r\n\t}\r\n\t\r\n\
    \tvoid reset(size_type i) noexcept {\r\n\t\tassert(i < n);\r\n\t\tbits[i >> SMALL]\
    \ &= ~(1u << (i & ~(~0u << SMALL)));\r\n\t}\r\n\t\r\n\tbool access(size_type i)\
    \ const noexcept {\r\n\t\tassert(i < n);\r\n\t\treturn bits[i >> SMALL] >> (i\
    \ & ~(~0u << SMALL)) & 1;\r\n\t}\r\n\t\r\n\tuint32 rank1(size_type i) const noexcept\
    \ {\r\n\t\tassert(i <= n);\r\n\t\tif (i == 0) return 0;\r\n\t\t--i;\r\n\t\treturn\
    \ large[i >> LARGE] + small[i >> SMALL] + pop_count(bits[i >> SMALL] & ~(~0u <<\
    \ ((i & (~(~0u << SMALL))) + 1)));\r\n\t}\r\n\t\r\n\tuint32 rank0(size_type i)\
    \ const noexcept {\r\n\t\tassert(i <= n);\r\n\t\treturn i - rank1(i);\r\n\t}\r\
    \n\t\r\n\tsize_type select1(size_type k) const noexcept {\r\n\t\tif (k == 0) return\
    \ size() + 1;\r\n\t\tuint32 l = 0, r = large.size();\r\n\t\twhile (l + 1 < r)\
    \ {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(large[m] < k ? l : r) =\
    \ m;\r\n\t\t}\r\n\t\tuint32 cnt = large[l];\r\n\t\tl = l << (LARGE - SMALL); r\
    \ = std::min<uint32>(small.size(), l + (1u << (LARGE - SMALL)));\r\n\t\twhile\
    \ (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(cnt + small[m]\
    \ < k ? l : r) = m;\r\n\t\t}\r\n\t\tcnt += small[l];\r\n\t\tconst uint32 idx =\
    \ l;\r\n\t\tl = 0; r = size() < l * (1u << SMALL) + 8 ? ((size() - 1) & ~(0u <<\
    \ SMALL)) + 1 : 8;\r\n\t\tif (cnt + pop_count(bits[idx] & ~(~0u << r)) < k) return\
    \ size() + 1;\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >>\
    \ 1;\r\n\t\t\t(cnt + pop_count(bits[idx] & ~(~0u << m)) < k ? l : r) = m;\r\n\t\
    \t}\r\n\t\treturn (idx << SMALL) + r;\r\n\t}\r\n\t\r\n\tsize_type select0(size_type\
    \ k) const noexcept {\r\n\t\tif (k == 0) return size() + 1;\r\n\t\tuint32 l =\
    \ 0, r = large.size();\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l\
    \ + r) >> 1;\r\n\t\t\t(m * (1 << LARGE) - large[m] < k ? l : r) = m;\r\n\t\t}\r\
    \n\t\tuint32 cnt = l * (1 << LARGE) - large[l];\r\n\t\tl = l << (LARGE - SMALL);\
    \ r = std::min<uint32>(small.size(), l + (1u << (LARGE - SMALL)));\r\n\t\twhile\
    \ (l + 1 < r) {\r\n\t\t\tconst uint32 m = (l + r) >> 1;\r\n\t\t\t(cnt + (m & ~(~0u\
    \ << (LARGE - SMALL))) * (1u << SMALL) - small[m] < k ? l : r) = m;\r\n\t\t}\r\
    \n\t\tcnt += (l & ~(~0u << (LARGE - SMALL))) * (1u << SMALL) - small[l];\r\n\t\
    \tconst uint32 idx = l;\r\n\t\tl = 0; r = size() < l * (1u << SMALL) + 8 ? ((size()\
    \ - 1) & ~(0u << SMALL)) + 1 : 8;\r\n\t\tif (cnt + pop_count(~bits[idx] & ~(~0u\
    \ << r)) < k) return size() + 1;\r\n\t\twhile (l + 1 < r) {\r\n\t\t\tconst uint32\
    \ m = (l + r) >> 1;\r\n\t\t\t(cnt + pop_count(~bits[idx] & ~(~0u << m)) < k ?\
    \ l : r) = m;\r\n\t\t}\r\n\t\treturn (idx << SMALL) + r;\r\n\t}\r\n\t\r\nprivate:\r\
    \n\tstatic constexpr uint8 table[1u << (1u << SMALL)] {\r\n\t\t0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,\r\
    \n\t\t1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t\
    1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\
    \n\t\t1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,\r\n\t\t\
    2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\n\t\t2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,\r\
    \n\t\t3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8\r\n\t};\r\
    \n\t\r\n\tstatic constexpr uint8 pop_count(uint8 x) noexcept {\r\n\t\treturn table[x];\r\
    \n\t}\r\n};\r\n\r\n\n#line 5 \"DataStructure/WaveletMatrix.hpp\"\n\r\n#line 9\
    \ \"DataStructure/WaveletMatrix.hpp\"\n#include <tuple>\r\n#include <stack>\r\n\
    \r\n/**\r\n * @brief https://tkmst201.github.io/Library/DataStructure/WaveletMatrix.hpp\r\
    \n */\r\ntemplate<typename T, int BITS>\r\nstruct WaveletMatrix {\r\n\tstatic_assert(std::is_integral<T>::value\
    \ == true);\r\n\tstatic_assert(BITS > 0);\r\n\tstatic_assert(BITS <= 64);\r\n\t\
    static_assert(BITS <= 8 * sizeof(T));\r\n\t\r\n\tusing size_type = std::size_t;\r\
    \n\tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\n\
    \tusing bv_type = SuccintBitVector;\r\n\t\r\nprivate:\r\n\tusing uint32 = std::uint32_t;\r\
    \n\t\r\n\tsize_type n;\r\n\tstd::vector<bv_type> bit_vector;\r\n\tstd::vector<uint32>\
    \ zero;\r\n\t\r\npublic:\r\n\texplicit WaveletMatrix(const std::vector<value_type>\
    \ & v) {\r\n\t\tbuild(v);\r\n\t}\r\n\t\r\nprivate:\r\n\tvoid build(const std::vector<value_type>\
    \ & v) {\r\n\t\tassert(!v.empty());\r\n\t\tn = v.size();\r\n\t\tfor (uint32 i\
    \ = 0; i < n; ++i) assert((v[i] >> BITS) == 0);\r\n\t\tbit_vector.assign(BITS,\
    \ bv_type(n));\r\n\t\tzero.assign(BITS, 0);\r\n\t\tstd::vector<value_type> ord(n),\
    \ nex_ord(n);\r\n\t\tord = v;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i) {\r\n\
    \t\t\tfor (uint32 j = 0; j < n; ++j) {\r\n\t\t\t\tif (ord[j] >> i & 1) bit_vector[i].set(j);\r\
    \n\t\t\t\telse nex_ord[zero[i]++] = ord[j];\r\n\t\t\t}\r\n\t\t\tbit_vector[i].build();\r\
    \n\t\t\tif (i == 0) break;\r\n\t\t\tuint32 p1 = zero[i];\r\n\t\t\tfor (uint32\
    \ j = 0; j < n; ++j) if (ord[j] >> i & 1) nex_ord[p1++] = ord[j];\r\n\t\t\tstd::swap(ord,\
    \ nex_ord);\r\n\t\t}\r\n\t}\r\n\t\r\npublic:\r\n\tsize_type size() const noexcept\
    \ {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvalue_type access(size_type k) const noexcept\
    \ {\r\n\t\tassert(k < n);\r\n\t\tvalue_type res = 0;\r\n\t\tfor (int i = BITS\
    \ - 1; i >= 0; --i) {\r\n\t\t\tif (bit_vector[i].access(k)) {\r\n\t\t\t\tres |=\
    \ 1ull << i;\r\n\t\t\t\tk = bit_vector[i].rank1(k) + zero[i];\r\n\t\t\t}\r\n\t\
    \t\telse k = bit_vector[i].rank0(k);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\
    \n\tstd::tuple<uint32, uint32, uint32> rank_all(size_type l, size_type r, const_reference\
    \ x) const noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= n);\r\n\t\tassert((x\
    \ >> BITS) == 0);\r\n\t\tif (l == r) return {0, 0, 0};\r\n\t\tuint32 rank_lt =\
    \ 0, rank_mt = 0;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i) {\r\n\t\t\tconst\
    \ uint32 l1 = bit_vector[i].rank1(l), r1 = bit_vector[i].rank1(r);\r\n\t\t\tif\
    \ (x >> i & 1) {\r\n\t\t\t\trank_lt += (r - l) - (r1 - l1);\r\n\t\t\t\tl = l1\
    \ + zero[i];\r\n\t\t\t\tr = r1 + zero[i];\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\
    \trank_mt += r1 - l1;\r\n\t\t\t\tl -= l1;\r\n\t\t\t\tr -= r1;\r\n\t\t\t}\r\n\t\
    \t}\r\n\t\treturn {rank_lt, r - l, rank_mt};\r\n\t}\r\n\t\r\n\tuint32 rank_less_than(size_type\
    \ l, size_type r, const_reference x) const noexcept {\r\n\t\tassert(l <= r);\r\
    \n\t\tassert(r <= n);\r\n\t\tassert((x >> BITS) == 0);\r\n\t\treturn std::get<0>(rank_all(l,\
    \ r, x));\r\n\t}\r\n\t\r\n\tuint32 rank(size_type l, size_type r, const_reference\
    \ x) const noexcept {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= n);\r\n\t\tassert((x\
    \ >> BITS) == 0);\r\n\t\treturn std::get<1>(rank_all(l, r, x));\r\n\t}\r\n\t\r\
    \n\tuint32 rank_more_than(size_type l, size_type r, const_reference x) const noexcept\
    \ {\r\n\t\tassert(l <= r);\r\n\t\tassert(r <= n);\r\n\t\tassert((x >> BITS) ==\
    \ 0);\r\n\t\treturn std::get<2>(rank_all(l, r, x));\r\n\t}\r\n\t\r\n\tsize_type\
    \ select(uint32 k, const_reference x) const noexcept {\r\n\t\tassert((x >> BITS)\
    \ == 0);\r\n\t\tif (k == 0 || k > size()) return size() + 1;\r\n\t\tuint32 pos\
    \ = 0;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i) {\r\n\t\t\tif (x >> i & 1) pos\
    \ = bit_vector[i].rank1(pos) + zero[i];\r\n\t\t\telse pos = bit_vector[i].rank0(pos);\r\
    \n\t\t}\r\n\t\tpos += k;\r\n\t\tif (pos > size()) return size() + 1;\r\n\t\tfor\
    \ (int i = 0; i < BITS; ++i) {\r\n\t\t\tif (x >> i & 1) {\r\n\t\t\t\tif (pos <=\
    \ zero[i]) return size() + 1;\r\n\t\t\t\tpos = bit_vector[i].select1(pos - zero[i]);\r\
    \n\t\t\t}\r\n\t\t\telse pos = bit_vector[i].select0(pos);\r\n\t\t\tif (pos > size())\
    \ return size() + 1;\r\n\t\t}\r\n\t\treturn pos;\r\n\t}\r\n\t\r\n\tvalue_type\
    \ quantile(size_type l, size_type r, uint32 k) const noexcept {\r\n\t\tassert(l\
    \ < r);\r\n\t\tassert(r <= size());\r\n\t\tassert(0 < k);\r\n\t\tassert(k <= r\
    \ - l);\r\n\t\tvalue_type res = 0;\r\n\t\tfor (int i = BITS - 1; i >= 0; --i)\
    \ {\r\n\t\t\tconst uint32 l1 = bit_vector[i].rank1(l), r1 = bit_vector[i].rank1(r);\r\
    \n\t\t\tconst uint32 c = (r - l) - (r1 - l1);\r\n\t\t\tif (k <= c) {\r\n\t\t\t\
    \tl -= l1;\r\n\t\t\t\tr -= r1;\r\n\t\t\t}\r\n\t\t\telse {\r\n\t\t\t\tl = l1 +\
    \ zero[i];\r\n\t\t\t\tr = r1 + zero[i];\r\n\t\t\t\tk -= c;\r\n\t\t\t\tres |= 1ull\
    \ << i;\r\n\t\t\t}\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tsize_type range_frequency(size_type\
    \ l, size_type r, value_type val_l, value_type val_r) const noexcept {\r\n\t\t\
    assert(r <= size());\r\n\t\tassert(((val_r - 1) >> BITS) == 0);\r\n\t\tif (l >=\
    \ r || val_l >= val_r) return 0;\r\n\t\treturn rank_less_than(l, r, val_r) - rank_less_than(l,\
    \ r, val_l);\r\n\t}\r\n\t\r\nprivate:\r\n\tstruct Data {\r\n\t\tint i;\r\n\t\t\
    uint32 l, r;\r\n\t\tbool f;\r\n\t\tvalue_type val;\r\n\t\tData(int i, uint32 l,\
    \ uint32 r, bool f, const value_type & val)\r\n\t\t\t: i(i), l(l), r(r), f(f),\
    \ val(val) {}\r\n\t};\r\n\t\r\npublic:\r\n\tstd::vector<std::pair<value_type,\
    \ uint32>> range_min_k(\r\n\t\tsize_type l, size_type r, value_type val_l, value_type\
    \ val_r, uint32 k) const {\r\n\t\tassert(r <= size());\r\n\t\tassert(((val_r -\
    \ 1) >> BITS) == 0);\r\n\t\tif (l >= r || val_l >= val_r || k == 0) return {};\r\
    \n\t\tstd::vector<std::pair<value_type, uint32>> res;\r\n\t\tstd::stack<Data>\
    \ stk;\r\n\t\tstk.emplace(BITS - 1, l, r, true, 0);\r\n\t\twhile (!stk.empty())\
    \ {\r\n\t\t\tconst Data dat = stk.top();\r\n\t\t\tstk.pop();\r\n\t\t\tif (dat.i\
    \ == -1) {\r\n\t\t\t\tif (dat.val < val_r) {\r\n\t\t\t\t\tres.emplace_back(dat.val,\
    \ dat.r - dat.l);\r\n\t\t\t\t\tif (res.size() == k) break;\r\n\t\t\t\t\tcontinue;\r\
    \n\t\t\t\t}\r\n\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t\tconst uint32 l1 = bit_vector[dat.i].rank1(dat.l),\
    \ r1 = bit_vector[dat.i].rank1(dat.r);\r\n\t\t\tconst uint32 l0 = dat.l - l1,\
    \ r0 = dat.r - r1;\r\n\t\t\tconst bool bit = val_l >> dat.i & 1;\r\n\t\t\tif (l1\
    \ != r1) stk.emplace(dat.i - 1, l1 + zero[dat.i], r1 + zero[dat.i], dat.f & bit,\
    \ dat.val | (1ull << dat.i));\r\n\t\t\tif (!(dat.f && bit) && l0 != r0) stk.emplace(dat.i\
    \ - 1, l0, r0, dat.f, dat.val);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\t\
    std::vector<std::pair<value_type, size_type>> range_max_k(\r\n\t\tsize_type l,\
    \ size_type r, value_type val_l, value_type val_r, uint32 k) const {\r\n\t\tassert(r\
    \ <= size());\r\n\t\tassert(((val_r - 1) >> BITS) == 0);\r\n\t\tif (l >= r ||\
    \ val_l >= val_r || k == 0) return {};\r\n\t\t--val_r;\r\n\t\tstd::vector<std::pair<value_type,\
    \ size_type>> res;\r\n\t\tstd::stack<Data> stk;\r\n\t\tstk.emplace(BITS - 1, l,\
    \ r, true, 0);\r\n\t\twhile (!stk.empty()) {\r\n\t\t\tconst Data dat = stk.top();\r\
    \n\t\t\tstk.pop();\r\n\t\t\tif (dat.i == -1) {\r\n\t\t\t\tif (dat.val >= val_l)\
    \ {\r\n\t\t\t\t\tres.emplace_back(dat.val, dat.r - dat.l);\r\n\t\t\t\t\tif (res.size()\
    \ == k) break;\r\n\t\t\t\t\tcontinue;\r\n\t\t\t\t}\r\n\t\t\t\tbreak;\r\n\t\t\t\
    }\r\n\t\t\tconst uint32 l1 = bit_vector[dat.i].rank1(dat.l), r1 = bit_vector[dat.i].rank1(dat.r);\r\
    \n\t\t\tconst uint32 l0 = dat.l - l1, r0 = dat.r - r1;\r\n\t\t\tconst bool bit\
    \ = val_r >> dat.i & 1;\r\n\t\t\tif (l0 != r0) stk.emplace(dat.i - 1, l0, r0,\
    \ dat.f & !bit, dat.val);\r\n\t\t\tif (!(dat.f && !bit) && l1 != r1) stk.emplace(dat.i\
    \ - 1, l1 + zero[dat.i], r1 + zero[dat.i], dat.f, dat.val | (1ull << dat.i));\r\
    \n\t\t}\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tstd::pair<value_type, bool> next_value(size_type\
    \ l, size_type r, value_type val_l, value_type val_r) const {\r\n\t\tconst auto\
    \ res = range_min_k(l, r, val_l, val_r, 1);\r\n\t\tif (res.empty()) return {0,\
    \ false};\r\n\t\treturn {res[0].first, true};\r\n\t}\r\n\t\r\n\tstd::pair<value_type,\
    \ bool> prev_value(size_type l, size_type r, value_type val_l, value_type val_r)\
    \ const {\r\n\t\tconst auto res = range_max_k(l, r, val_l, val_r, 1);\r\n\t\t\
    if (res.empty()) return {0, false};\r\n\t\treturn {res[0].first, true};\r\n\t\
    }\r\n\t\r\n\tstd::vector<std::pair<value_type, size_type>> get_rect(size_type\
    \ l, size_type r, value_type val_l, value_type val_r) const {\r\n\t\tauto points\
    \ = range_min_k(l, r, val_l, val_r, r - l);\r\n\t\tstd::vector<std::pair<value_type,\
    \ size_type>> res;\r\n\t\tfor (const auto & p : points) {\r\n\t\t\tconst uint32\
    \ c = rank(0, l, p.first);\r\n\t\t\tfor (uint32 i = 0; i < p.second; ++i) res.emplace_back(p.first,\
    \ select(c + i + 1, p.first) - 1);\r\n\t\t}\r\n\t\treturn res;\r\n\t}\r\n};\r\n\
    \r\n\n#line 4 \"Test/WaveletMatrix.select.range_k.test.cpp\"\n\r\n#include <cstdio>\r\
    \n#line 7 \"Test/WaveletMatrix.select.range_k.test.cpp\"\n\r\nconstexpr int INF\
    \ = 1'000'000'001;\r\n\r\nint main() {\r\n\tint N;\r\n\tscanf(\"%d\", &N);\r\n\
    \t\r\n\tstd::vector<int> x(N), y(N), cx, cy;\r\n\tfor (int i = 0; i < N; ++i)\
    \ scanf(\"%d %d\", &x[i], &y[i]);\r\n\t\r\n\tauto compress = [](auto &&v, auto\
    \ &&cv) -> void {\r\n\t\tfor (auto &&u : v) cv.emplace_back(u);\r\n\t\tcv.emplace_back(INF);\r\
    \n\t\tcv.emplace_back(-INF);\r\n\t\tstd::sort(begin(cv), end(cv));\r\n\t\tcv.erase(std::unique(begin(cv),\
    \ end(cv)), std::end(cv));\r\n\t\tfor (auto &&u : v) u = std::lower_bound(begin(cv),\
    \ end(cv), u) - std::begin(cv);\r\n\t};\r\n\t\r\n\tcompress(x, cx);\r\n\tcompress(y,\
    \ cy);\r\n\t\r\n\t// \u540C\u3058 x \u5EA7\u6A19\u3067\u3082 wavelet matrix \u4E0A\
    \u3067\u306F\u7570\u306A\u308B index \u306B\u306A\u308B\u3088\u3046\u306B\u4FEE\
    \u6B63\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\tstd::vector<int> sum(cx.size());\
    \ // [i] := x[j] \u304C i \u4EE5\u4E0B\u3067\u3042\u308B\u3088\u3046\u306A j \u306E\
    \u500B\u6570\r\n\tfor (int i = 0; i < x.size(); ++i) ++sum[x[i]];\r\n\tfor (int\
    \ i = 1; i < sum.size(); ++i) sum[i] += sum[i - 1];\r\n\t\r\n\tstd::vector<int>\
    \ cnt(cx.size()), sy(N); // sy[i] := x \u5EA7\u6A19\u304C i \u756A\u76EE\u306B\
    \u5C0F\u3055\u3044\u70B9\u306E y \u5EA7\u6A19(x \u5EA7\u6A19\u304C\u540C\u4E00\
    \u306E\u5834\u5408\u306B\u3082\u5DEE\u3092\u3064\u3051\u308B)\r\n\tstd::vector<int>\
    \ idx_map(N);\r\n\t\r\n\tfor (int i = 0; i < x.size(); ++i) {\r\n\t\tsy[sum[x[i]\
    \ - 1] + cnt[x[i]]] = y[i];\r\n\t\tidx_map[sum[x[i] - 1] + cnt[x[i]]] = i;\r\n\
    \t\t++cnt[x[i]];\r\n\t}\r\n\t\r\n\tWaveletMatrix<int, 19> wm(sy);\r\n\t\r\n\t\
    auto compress_get = [](auto &&cv, auto &&x) {\r\n\t\treturn std::lower_bound(begin(cv),\
    \ end(cv), x) - std::begin(cv);\r\n\t};\r\n\t\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\
    \n\tfor (int i = 0; i < Q; ++i) {\r\n\t\tint sty, stx, edy, edx;\r\n\t\tscanf(\"\
    %d %d %d %d\", &stx, &edx, &sty, &edy);\r\n\t\t++edx; ++edy;\r\n\t\tsty = compress_get(cy,\
    \ sty);\r\n\t\tstx = compress_get(cx, stx); stx = sum[stx - 1];\r\n\t\tedy = compress_get(cy,\
    \ edy);\r\n\t\tedx = compress_get(cx, edx); edx = sum[edx - 1];\r\n\r\n\t\tauto\
    \ points = wm.get_rect(stx, edx, sty, edy);\r\n\t\t// test range_min_k\r\n\t\t\
    {\r\n\t\t\tfor (int j = 1; j < points.size(); ++j) {\r\n\t\t\t\tassert(points[j\
    \ - 1].first <= points[j].first);\r\n\t\t\t\tif (points[j - 1].first == points[j].first)\
    \ assert(points[j - 1].second < points[j].second);\r\n\t\t\t}\r\n\t\t\tfor (const\
    \ auto [v, idx] : points) {\r\n\t\t\t\tassert(idx >= stx && idx < edx);\r\n\t\t\
    \t\tassert(wm.access(idx) == v);\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<int> ans;\r\
    \n\t\tfor (auto &p : points) ans.emplace_back(idx_map[p.second]);\r\n\t\tstd::sort(begin(ans),\
    \ end(ans));\r\n\t\tfor (int j = 0; j < ans.size(); ++j) printf(\"%d\\n\", ans[j]);\r\
    \n\t\tputchar('\\n');\r\n\t\t\r\n\t\t// test range_max_k\r\n\t\t{\r\n\t\t\tauto\
    \ t_points = wm.range_max_k(stx, edx, sty, edy, edx - stx);\r\n\t\t\tusing wm_type\
    \ = WaveletMatrix<int, 19>;\r\n\t\t\tstd::vector<std::pair<wm_type::value_type,\
    \ wm_type::size_type>> res;\r\n\t\t\tfor (const auto & p : t_points) {\r\n\t\t\
    \t\tconst unsigned int c = wm.rank(0, stx, p.first);\r\n\t\t\t\tfor (int j = 0;\
    \ j < p.second; ++j) res.emplace_back(p.first, wm.select(c + j + 1, p.first) -\
    \ 1);\r\n\t\t\t}\r\n\t\t\tfor (int j = 1; j < res.size(); ++j) {\r\n\t\t\t\tassert(res[j\
    \ - 1].first >= res[j].first);\r\n\t\t\t\tif (res[j - 1].first == res[j].first)\
    \ assert(res[j - 1].second < res[j].second);\r\n\t\t\t}\r\n\t\t\tfor (const auto\
    \ [v, idx] : res) {\r\n\t\t\t\tassert(idx >= stx && idx < edx);\r\n\t\t\t\tassert(wm.access(idx)\
    \ == v);\r\n\t\t\t}\r\n\t\t\tassert(points.size() == res.size());\r\n\t\t}\r\n\
    \t}\r\n}\r\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C\"\
    \r\n\r\n#include \"DataStructure/WaveletMatrix.hpp\"\r\n\r\n#include <cstdio>\r\
    \n#include <vector>\r\n\r\nconstexpr int INF = 1'000'000'001;\r\n\r\nint main()\
    \ {\r\n\tint N;\r\n\tscanf(\"%d\", &N);\r\n\t\r\n\tstd::vector<int> x(N), y(N),\
    \ cx, cy;\r\n\tfor (int i = 0; i < N; ++i) scanf(\"%d %d\", &x[i], &y[i]);\r\n\
    \t\r\n\tauto compress = [](auto &&v, auto &&cv) -> void {\r\n\t\tfor (auto &&u\
    \ : v) cv.emplace_back(u);\r\n\t\tcv.emplace_back(INF);\r\n\t\tcv.emplace_back(-INF);\r\
    \n\t\tstd::sort(begin(cv), end(cv));\r\n\t\tcv.erase(std::unique(begin(cv), end(cv)),\
    \ std::end(cv));\r\n\t\tfor (auto &&u : v) u = std::lower_bound(begin(cv), end(cv),\
    \ u) - std::begin(cv);\r\n\t};\r\n\t\r\n\tcompress(x, cx);\r\n\tcompress(y, cy);\r\
    \n\t\r\n\t// \u540C\u3058 x \u5EA7\u6A19\u3067\u3082 wavelet matrix \u4E0A\u3067\
    \u306F\u7570\u306A\u308B index \u306B\u306A\u308B\u3088\u3046\u306B\u4FEE\u6B63\
    \u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\tstd::vector<int> sum(cx.size());\
    \ // [i] := x[j] \u304C i \u4EE5\u4E0B\u3067\u3042\u308B\u3088\u3046\u306A j \u306E\
    \u500B\u6570\r\n\tfor (int i = 0; i < x.size(); ++i) ++sum[x[i]];\r\n\tfor (int\
    \ i = 1; i < sum.size(); ++i) sum[i] += sum[i - 1];\r\n\t\r\n\tstd::vector<int>\
    \ cnt(cx.size()), sy(N); // sy[i] := x \u5EA7\u6A19\u304C i \u756A\u76EE\u306B\
    \u5C0F\u3055\u3044\u70B9\u306E y \u5EA7\u6A19(x \u5EA7\u6A19\u304C\u540C\u4E00\
    \u306E\u5834\u5408\u306B\u3082\u5DEE\u3092\u3064\u3051\u308B)\r\n\tstd::vector<int>\
    \ idx_map(N);\r\n\t\r\n\tfor (int i = 0; i < x.size(); ++i) {\r\n\t\tsy[sum[x[i]\
    \ - 1] + cnt[x[i]]] = y[i];\r\n\t\tidx_map[sum[x[i] - 1] + cnt[x[i]]] = i;\r\n\
    \t\t++cnt[x[i]];\r\n\t}\r\n\t\r\n\tWaveletMatrix<int, 19> wm(sy);\r\n\t\r\n\t\
    auto compress_get = [](auto &&cv, auto &&x) {\r\n\t\treturn std::lower_bound(begin(cv),\
    \ end(cv), x) - std::begin(cv);\r\n\t};\r\n\t\r\n\tint Q;\r\n\tscanf(\"%d\", &Q);\r\
    \n\tfor (int i = 0; i < Q; ++i) {\r\n\t\tint sty, stx, edy, edx;\r\n\t\tscanf(\"\
    %d %d %d %d\", &stx, &edx, &sty, &edy);\r\n\t\t++edx; ++edy;\r\n\t\tsty = compress_get(cy,\
    \ sty);\r\n\t\tstx = compress_get(cx, stx); stx = sum[stx - 1];\r\n\t\tedy = compress_get(cy,\
    \ edy);\r\n\t\tedx = compress_get(cx, edx); edx = sum[edx - 1];\r\n\r\n\t\tauto\
    \ points = wm.get_rect(stx, edx, sty, edy);\r\n\t\t// test range_min_k\r\n\t\t\
    {\r\n\t\t\tfor (int j = 1; j < points.size(); ++j) {\r\n\t\t\t\tassert(points[j\
    \ - 1].first <= points[j].first);\r\n\t\t\t\tif (points[j - 1].first == points[j].first)\
    \ assert(points[j - 1].second < points[j].second);\r\n\t\t\t}\r\n\t\t\tfor (const\
    \ auto [v, idx] : points) {\r\n\t\t\t\tassert(idx >= stx && idx < edx);\r\n\t\t\
    \t\tassert(wm.access(idx) == v);\r\n\t\t\t}\r\n\t\t}\r\n\t\tstd::vector<int> ans;\r\
    \n\t\tfor (auto &p : points) ans.emplace_back(idx_map[p.second]);\r\n\t\tstd::sort(begin(ans),\
    \ end(ans));\r\n\t\tfor (int j = 0; j < ans.size(); ++j) printf(\"%d\\n\", ans[j]);\r\
    \n\t\tputchar('\\n');\r\n\t\t\r\n\t\t// test range_max_k\r\n\t\t{\r\n\t\t\tauto\
    \ t_points = wm.range_max_k(stx, edx, sty, edy, edx - stx);\r\n\t\t\tusing wm_type\
    \ = WaveletMatrix<int, 19>;\r\n\t\t\tstd::vector<std::pair<wm_type::value_type,\
    \ wm_type::size_type>> res;\r\n\t\t\tfor (const auto & p : t_points) {\r\n\t\t\
    \t\tconst unsigned int c = wm.rank(0, stx, p.first);\r\n\t\t\t\tfor (int j = 0;\
    \ j < p.second; ++j) res.emplace_back(p.first, wm.select(c + j + 1, p.first) -\
    \ 1);\r\n\t\t\t}\r\n\t\t\tfor (int j = 1; j < res.size(); ++j) {\r\n\t\t\t\tassert(res[j\
    \ - 1].first >= res[j].first);\r\n\t\t\t\tif (res[j - 1].first == res[j].first)\
    \ assert(res[j - 1].second < res[j].second);\r\n\t\t\t}\r\n\t\t\tfor (const auto\
    \ [v, idx] : res) {\r\n\t\t\t\tassert(idx >= stx && idx < edx);\r\n\t\t\t\tassert(wm.access(idx)\
    \ == v);\r\n\t\t\t}\r\n\t\t\tassert(points.size() == res.size());\r\n\t\t}\r\n\
    \t}\r\n}\r\n"
  dependsOn:
  - DataStructure/WaveletMatrix.hpp
  - DataStructure/SuccintBitVector.hpp
  isVerificationFile: true
  path: Test/WaveletMatrix.select.range_k.test.cpp
  requiredBy: []
  timestamp: '2021-03-18 15:32:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/WaveletMatrix.select.range_k.test.cpp
layout: document
redirect_from:
- /verify/Test/WaveletMatrix.select.range_k.test.cpp
- /verify/Test/WaveletMatrix.select.range_k.test.cpp.html
title: Test/WaveletMatrix.select.range_k.test.cpp
---