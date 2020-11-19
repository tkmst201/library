---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.hpp
    title: DataStructure/SegmentTree.hpp
  - icon: ':heavy_check_mark:'
    path: GraphTheory/HeavyLightDecomposition.hpp
    title: GraphTheory/HeavyLightDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: GraphTheory/HeavyLightDecomposition_Query.hpp
    title: GraphTheory/HeavyLightDecomposition_Query.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\r\
    \n\r\n#line 1 \"DataStructure/SegmentTree.hpp\"\n\n\n\r\n/*\r\nlast-updated: 2020/09/18\r\
    \n\r\nmax_right: verified(https://atcoder.jp/contests/practice2/submissions/16664880)\r\
    \nmin_left: unverified\r\n\r\n# \u4ED5\u69D8\r\nSegmentTree()\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u7A7A\u306E\u30BB\u30B0\u6728\u3092\u4F5C\u6210\
    \r\n\t\u4F55\u304B\u64CD\u4F5C\u3092\u884C\u3063\u305F\u5834\u5408\u306E\u52D5\
    \u4F5C\u306F\u672A\u5B9A\u7FA9\r\n\r\nSegmentTree(size_type n, const_reference\
    \ id_elem, const F & f)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u8981\
    \u7D20\u6570 n, \u5358\u4F4D\u5143 id_elem, \u4E8C\u9805\u6F14\u7B97 f \u3067\u521D\
    \u671F\u5316\r\n\r\nSegmentTree(std::vector<value_type> v, const_reference id_elem,\
    \ const F & f)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u914D\u5217\
    \ v \u3067\u521D\u671F\u5316\r\n\t\u4ED6\u306E\u5F15\u6570\u306B\u3064\u3044\u3066\
    \u306F\u4E0A\u8A18\u306E\u901A\u308A\r\n\r\nsize_type size() const noexcept\r\n\
    \t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u8981\u7D20\u6570\u3092\u8FD4\
    \u3059(\\neq \u5185\u90E8\u306E\u30CE\u30FC\u30C9\u6570)\r\n\r\nvoid set(size_type\
    \ i, const_reference x)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(log n)\r\n\
    \ti \u756A\u76EE(0 \\leq i < n) \u306E\u8981\u7D20\u306B x \u3092\u4EE3\u5165\r\
    \n\r\nconst_reference get(size_type i) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\ti \u756A\u76EE(0 \\leq i < n) \u306E\u8981\u7D20\u3092\u8FD4\u3059\
    \r\n\r\nvalue_type fold(size_type l, size_type r) const\r\n\t\u6642\u9593\u8A08\
    \u7B97\u91CF: O(log n)\r\n\t[l, r) (0 \\leq l \\leq r \\leq n) \u3092 fold \u3057\
    \u305F\u7D50\u679C\u3092\u8FD4\u3059\r\n\tl = r \u306E\u3068\u304D\u306F id_elem\
    \ \u3092\u8FD4\u3059\r\n\r\nconst_reference fold_all() const\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(1)\r\n\tfold(0, n) \u306E\u7D50\u679C\u3092\u8FD4\u3059\
    \r\n\r\nsize_type max_right(size_type l, std::function<bool(const_reference)>\
    \ g) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t0 \\leq l \\leq\
    \ n\r\n\tg \u306F\u5358\u8ABF\u306A\u95A2\u6570\r\n\t\u6B21\u306E\u6761\u4EF6\u3092\
    \u6E80\u305F\u3059\u6700\u5C0F\u306E r \u3092\u8FD4\u3059\r\n\t\tl \\leq i \\\
    leq r \u3067\u306F g(fold(l, i)) = true\r\n\t\tg(fold(l, r + 1)) = false\r\n\t\
    g(fold(l, n)) = true \u306E\u3068\u304D\u306F r = n\r\n\r\nsize_type min_left(size_type\
    \ r, std::function<bool(const_reference)> g) const\r\n\t\u6642\u9593\u8A08\u7B97\
    \u91CF: O(log n)\r\n\t0 \\leq r \\leq n\r\n\tg \u306F\u5358\u8ABF\u306A\u95A2\u6570\
    \r\n\t\u6B21\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u5927\u306E l \u3092\
    \u8FD4\u3059\r\n\t\tl \\leq i \\leq r \u3067\u306F g(fold(i, r)) = true\r\n\t\t\
    g(fold(l - 1, r)) = false\r\n\tg(fold(0, r)) = true \u306E\u3068\u304D\u306F l\
    \ = 0\r\n\r\n# \u53C2\u8003\r\nhttps://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf,\
    \ 2020/04/08\r\nAC Library, 2020/09/13\r\n*/\r\n\r\n#include <vector>\r\n#include\
    \ <algorithm>\r\n#include <cassert>\r\n#include <functional>\r\n\r\ntemplate<typename\
    \ T>\r\nstruct SegmentTree {\r\n\tusing value_type = T;\r\n\tusing const_reference\
    \ = const value_type &;\r\n\tusing F = std::function<value_type(const_reference,\
    \ const_reference)>;\r\n\tusing size_type = std::size_t;\r\n\t\r\nprivate:\r\n\
    \tsize_type n, n_;\r\n\tvalue_type id_elem;\r\n\tF f;\r\n\tstd::vector<value_type>\
    \ node;\r\n\t\r\npublic:\r\n\tSegmentTree() = default;\r\n\t\r\n\tSegmentTree(size_type\
    \ n, const_reference id_elem, const F & f) : n(n), id_elem(id_elem), f(f) {\r\n\
    \t\tn_ = 1;\r\n\t\twhile (n_ < n) n_ <<= 1;\r\n\t\tnode.resize(2 * n_, id_elem);\r\
    \n\t}\r\n\t\r\n\tSegmentTree(std::vector<value_type> v, const_reference id_elem,\
    \ const F & f) :\r\n\t\t\tSegmentTree(v.size(), id_elem, f) {\r\n\t\tfor (size_type\
    \ i = 0; i < v.size(); ++i) node[i + n_] = v[i];\r\n\t\tfor (size_type i = n_\
    \ - 1; i > 0; --i) node[i] = f(node[i << 1], node[i << 1 | 1]);\r\n\t}\r\n\t\r\
    \n\tsize_type size() const noexcept {\r\n\t\treturn n;\r\n\t}\r\n\t\r\n\tvoid\
    \ set(size_type i, const_reference x) {\r\n\t\tassert(i < size());\r\n\t\tnode[i\
    \ += n_] = x;\r\n\t\twhile (i > 1) {\r\n\t\t\ti >>= 1;\r\n\t\t\tnode[i] = f(node[i\
    \ << 1], node[i << 1 | 1]);\r\n\t\t}\r\n\t}\r\n\t\r\n\tconst_reference get(size_type\
    \ i) const {\r\n\t\tassert(i < size());\r\n\t\treturn node[i + n_];\r\n\t}\r\n\
    \t\r\n\tvalue_type fold(size_type l, size_type r) const {\r\n\t\tassert(l <= r);\r\
    \n\t\tassert(r <= size());\r\n\t\tvalue_type lv = id_elem, rv = id_elem;\r\n\t\
    \tfor (l += n_, r += n_; l < r; l >>= 1, r >>= 1) {\r\n\t\t\tif (l & 1) lv = f(lv,\
    \ node[l++]);\r\n\t\t\tif (r & 1) rv = f(node[r - 1], rv);\r\n\t\t}\r\n\t\treturn\
    \ f(lv, rv);\r\n\t}\r\n\t\r\n\tconst_reference fold_all() const {\r\n\t\treturn\
    \ node[1];\r\n\t}\r\n\t\r\n\tsize_type max_right(size_type l, std::function<bool(const_reference)>\
    \ g) const {\r\n\t\tassert(l <= size());\r\n\t\tassert(g(id_elem));\r\n\t\tif\
    \ (l == size()) return size();\r\n\t\tl += n_;\r\n\t\tvalue_type sum = id_elem;\r\
    \n\t\twhile (true) {\r\n\t\t\twhile (~l & 1) l >>= 1;\r\n\t\t\tconst value_type\
    \ nex_sum = f(sum, node[l]);\r\n\t\t\tif (g(nex_sum)) { sum = nex_sum; ++l; }\r\
    \n\t\t\telse break;\r\n\t\t\tif ((l & -l) == l) return size();\r\n\t\t}\r\n\t\t\
    while (l < n_) {\r\n\t\t\tconst value_type nex_sum = f(sum, node[l << 1]);\r\n\
    \t\t\tl <<= 1;\r\n\t\t\tif (g(nex_sum)) { sum = nex_sum; l |= 1; }\r\n\t\t}\r\n\
    \t\treturn l - n_;\r\n\t}\r\n\t\r\n\tsize_type min_left(size_type r, std::function<bool(const_reference)>\
    \ g) const {\r\n\t\tassert(r <= size());\r\n\t\tassert(g(id_elem));\r\n\t\tif\
    \ (r == 0) return 0;\r\n\t\tr += n_;\r\n\t\tvalue_type sum = id_elem;\r\n\t\t\
    while (true) {\r\n\t\t\t--r;\r\n\t\t\twhile (r > 1 && (r & 1)) r >>= 1;\r\n\t\t\
    \tconst value_type nex_sum = f(node[r], sum);\r\n\t\t\tif (g(nex_sum)) sum = nex_sum;\r\
    \n\t\t\telse break;\r\n\t\t\tif ((r & -r) == r) return 0;\r\n\t\t}\r\n\t\twhile\
    \ (r < n_) {\r\n\t\t\tconst value_type nex_sum = f(node[r << 1 | 1], sum);\r\n\
    \t\t\tr <<= 1;\r\n\t\t\tif (!g(nex_sum)) r |= 1;\r\n\t\t\telse sum = nex_sum;\r\
    \n\t\t}\r\n\t\treturn r + 1 - n_;\r\n\t}\r\n};\r\n\r\n\n#line 1 \"GraphTheory/HeavyLightDecomposition.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/09/18\r\n\r\nHL \u5206\u89E3 + EulerTour\r\n\
    \u5358\u7D14\u306A\u68EE\u306B\u5BFE\u5FDC(\u81EA\u5DF1\u30EB\u30FC\u30D7, \u591A\
    \u91CD\u8FBA\u306A\u3057)\r\n\r\n# \u7528\u8A9E\r\nlca: \u6700\u8FD1\u5171\u901A\
    \u7956\u5148\r\nheavy-path: heavy-edge \u306E\u307F\u901A\u3063\u3066\u79FB\u52D5\
    \u53EF\u80FD\u306A\u9802\u70B9\u96C6\u5408\r\n\r\n# \u89E3\u8AAC\r\ndfs \u3059\
    \u308B\u969B\u306B heavy-edge \u3092\u512A\u5148\u3057\u3066\u901A\u308B\u3088\
    \u3046\u306B\u3059\u308B\u3068\u3001\u540C\u4E00 heavy-path \u5185\u306E\u9802\
    \u70B9\u306E EulerTour \u9806\u304C\u9023\u7D9A\u3059\u308B\r\n\r\n\u9802\u70B9\
    \ v \u304B\u3089\u540C\u4E00 heavy-path \u5185\u3067\u6839\u306B\u4E0A\u3063\u305F\
    \u3068\u304D\u306B\u901A\u308B\u9802\u70B9\u306F \u533A\u9593 [ in[head[heavy_map[v]],\
    \ in[v] ] \u306B\u5BFE\u5FDC\r\n\u90E8\u5206\u6728 v \u5185\u306E\u9802\u70B9\u306F\
    \ [in[v], out[v]) \u306B\u5BFE\u5FDC\r\n\r\nHL \u5206\u89E3\u3067\u30D1\u30B9\u30AF\
    \u30A8\u30EA\u3001\u90E8\u5206\u6728\u30AF\u30A8\u30EA\u306E\u4E21\u65B9\u3092\
    \u634C\u3051\u308B\u3088\u3046\u306B\u306A\u308B\r\n\r\n\u30D1\u30B9\u30AF\u30A8\
    \u30EA\u3067\u30A2\u30FC\u30D9\u30EB\u7FA4\u306A\u3089 EulerTour \u5358\u4F53\u3092\
    \u4F7F\u304A\u3046( HL \u5206\u89E3\u3067\u306F log \u304C 1 \u3064\u591A\u3044\
    )\r\n\r\n# \u4ED5\u69D8\r\nHeavyLightDecomposition(const Graph & g, bool use_lca\
    \ = false)\r\n\t\u6642\u9593\u8A08\u7B97\u91CF:\r\n\t\tuse_lca = false : \u0398\
    (n)\r\n\t\tuse_lca = true: \u0398(n loglog n)\r\n\t\r\n\t\u30B0\u30E9\u30D5 g\
    \ \u3092 HL \u5206\u89E3\u3059\u308B\r\n\t\u4E00\u5EA6\u6E21\u3057\u305F g \u306F\
    \u5909\u66F4\u3057\u3066\u306F\u3044\u3051\u306A\u3044\r\n\tuse_lca = false \u306E\
    \u3068\u304D\u306F lca \u95A2\u9023\u306E\u6A5F\u80FD\u304C\u4F7F\u3048\u306A\u3044\
    \r\n\r\nHeavyLightDecomposition(const Graph & g, size_type root, bool use_lca)\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: \u4E0A\u3068\u540C\u4E00\r\n\t\u30B0\u30E9\
    \u30D5 g \u304C\u6728\u3067\u3042\u308B\u3068\u304D\u3001\u6839\u3092 root \u3068\
    \u3057\u3066 HL \u5206\u89E3\u3092\u884C\u3046\r\n\t\u90E8\u5206\u6728\u30AF\u30A8\
    \u30EA\u3092\u51E6\u7406\u3057\u305F\u3044\u3068\u304D\u306B\u5FC5\u8981\r\n\r\
    \nstd::pair<size_type, size_type> get_lca_path(size_type x, size_type y) const\r\
    \n\t\u6642\u9593\u8A08\u7B97\u91CF: O(loglog n)\r\n\tuse_lca = true \u3067\u3042\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\t\u5206\u89E3\u524D\u306E\u30B0\u30E9\
    \u30D5\u306E\u9802\u70B9 x, y \u304C\u5C5E\u3059\u308B heavy-path \u306E lca heavy-path\
    \ \u3092 L \u3068\u3059\u308B\r\n\t\u9802\u70B9 x, y \u304C heavy-path L \u306B\
    \u5C5E\u3059\u308B\u9802\u70B9\u306B\u5230\u9054\u3059\u308B\u307E\u3067\u4E0A\
    \u3063\u305F\u3068\u304D\u306B\u521D\u3081\u3066\u5230\u9054\u3059\u308B\u9802\
    \u70B9\u306E\u7D44\u3092\u8FD4\u3059\r\n\r\nsize_type get_lca(size_type x, size_type\
    \ y) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(loglog n)\r\n\tuse_lca = true\
    \ \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\t\u9802\u70B9 x, y \u306E\
    \ lca \u3092\u8FD4\u3059\r\n\r\n\u4EE5\u4E0B\u3001\u5168\u3066 \u6642\u9593\u8A08\
    \u7B97\u91CF \u0398(1)\r\n\r\nsize_type bf_size() const noexcept: \u30B0\u30E9\
    \u30D5\u306E\u9802\u70B9\u6570\u3092\u8FD4\u3059\r\nsize_type af_size() const\
    \ noexcept: heavy-path \u306E\u500B\u6570\u3092\u8FD4\u3059\r\n\r\nsize_type par(size_type\
    \ v) const: \u9802\u70B9 v \u306E\u89AA\u3092\u8FD4\u3059(k \u304C\u6839\u306A\
    \u3089 k \u3092\u8FD4\u3059)\r\nsize_type sub_size(size_type v) const: \u9802\u70B9\
    \ v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u5C5E\u3059\u308B\u9802\
    \u70B9\u6570\u3092\u8FD4\u3059\r\nsize_type depth(size_type v) const: \u9802\u70B9\
    \ v \u306E\u6839\u304B\u3089\u306E\u8DDD\u96E2(0-indexed)\u3092\u8FD4\u3059\r\n\
    \r\nsize_type tree_id(size_type v) const: \u9802\u70B9 v \u304C\u5C5E\u3059\u308B\
    \u6728\u306E id \u3092\u8FD4\u3059\r\nsize_type tree_cnt() const noexcept: \u30B0\
    \u30E9\u30D5 g \u306B\u542B\u307E\u308C\u3066\u3044\u308B\u6728\u306E\u500B\u6570\
    \u3092\u8FD4\u3059\r\nconst std::vector<size_type> & trees() const noexcept: \u30B0\
    \u30E9\u30D5 g \u306B\u542B\u307E\u308C\u3066\u3044\u308B\u6728\u306E\u6839\u306E\
    \u30EA\u30B9\u30C8\u3092\u8FD4\u3059\r\n\r\nsize_type heavy_map(size_type v) const:\
    \ \u9802\u70B9 v \u304C\u5C5E\u3059\u308B heavy-path id \u3092\u8FD4\u3059\r\n\
    size_type head(size_type k) const: heavy-path k \u5185\u306E\u6700\u3082\u6839\
    \u306B\u8FD1\u3044\u9802\u70B9(= EulerTour \u9806\u3067\u6700\u5C0F) \u3092\u8FD4\
    \u3059\r\nsize_type heavy_size(size_type k) const: heavy-path k \u306B\u5C5E\u3059\
    \u308B\u9802\u70B9\u6570\u3092\u8FD4\u3059\r\nsize_type heavy_depth(size_type\
    \ k) const: heavy-path k \u304B\u3089\u6839\u307E\u3067\u306B\u901A\u308B light-edge\
    \ \u306E\u500B\u6570\u3092\u8FD4\u3059\r\n\r\nsize_type in(size_type v) const:\
    \ \u9802\u70B9 v \u306E EulerTour \u9806\u5E8F(\u540C\u4E00 heavy-path \u5185\u3067\
    \u306F\u9023\u7D9A) \u3092\u8FD4\u3059\r\nsize_typsize_type out(size_type v) conste\
    \ in(size_type v) const: \u9802\u70B9 v \u304B\u3089\u51FA\u308B\u3068\u304D\u306E\
    \ EulerTour \u9806\u5E8F\r\nsize_type euler_map(size_type k) const: EulerTour\
    \ \u9806\u5E8F\u304C i \u3067\u3042\u308B\u3088\u3046\u306A\u9802\u70B9\u3092\u8FD4\
    \u3059\r\n\r\nconst std::vector<std::vector<size_type>> & par_dblng() const\r\n\
    \tuse_lca = true \u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n\t\u6B21\u306E\
    \u3088\u3046\u306A 2 \u6B21\u5143\u914D\u5217\u3092\u8FD4\u3059\r\n\t[k][i] :=\
    \ heavy-path i \u304B\u3089 2^k \u56DE light-edge \u3092\u4E0A\u3063\u305F\u3068\
    \u304D\u3001\u6700\u521D\u306B\u5230\u9054\u3059\u308B\u9802\u70B9\r\n\r\n\r\n\
    # \u53C2\u8003\r\nhttps://qiita.com/ageprocpp/items/8dfe768218da83314989, 2020/04/19\r\
    \nhttps://math314.hateblo.jp/entry/2014/06/24/220107, 2020/04/19\r\nhttps://codeforces.com/blog/entry/53170,\
    \ 2020/09/18\r\n*/\r\n\r\n#line 86 \"GraphTheory/HeavyLightDecomposition.hpp\"\
    \n#include <cstdint>\r\n#include <stack>\r\n#include <utility>\r\n#line 90 \"\
    GraphTheory/HeavyLightDecomposition.hpp\"\n\r\nstruct HeavyLightDecomposition\
    \ {\r\n\tusing size_type = std::uint_fast32_t;\r\n\tusing Graph = std::vector<std::vector<size_type>>;\r\
    \n\t\r\nprivate:\r\n\tsize_type bf_n; // \u30B0\u30E9\u30D5\u306E\u9802\u70B9\u6570\
    \r\n\t\r\n\tstd::vector<size_type> par_; // [v] := \u9802\u70B9 v \u306E\u89AA\
    \u306E\u9802\u70B9\u756A\u53F7(\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u81EA\
    \u5206\u81EA\u8EAB)\r\n\tstd::vector<size_type> sub_size_; // [v] := \u9802\u70B9\
    \ v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\r\
    \n\tstd::vector<size_type> depth_; // [v] := \u9802\u70B9 v \u306E\u5143\u306E\
    \u30B0\u30E9\u30D5\u3067\u306E\u6DF1\u3055\r\n\t\r\n\tstd::vector<size_type> tree_id_;\
    \ // [v] := \u9802\u70B9 v \u304C\u5C5E\u3059\u308B\u6728\u306E id\r\n\tstd::vector<size_type>\
    \ roots_; // [i] := i \u756A\u76EE\u306E\u6728\u306E root\r\n\t\r\n\tstd::vector<size_type>\
    \ heavy_map_; // [v] := \u9802\u70B9 v \u304C\u5C5E\u3059\u308B heavy-path id\r\
    \n\tstd::vector<size_type> head_; // [i] := heavy-path i \u306E\u6700\u3082\u6839\
    \u306B\u8FD1\u3044\u9802\u70B9\u756A\u53F7\r\n\tstd::vector<size_type> heavy_size_\
    \ ; // [i] := heavy-path i \u306B\u5C5E\u3059\u308B\u9802\u70B9\u306E\u500B\u6570\
    \r\n\tstd::vector<size_type> heavy_depth_; // [i] := heavy-path i \u304B\u3089\
    \u6839\u307E\u3067\u306B\u901A\u308B light-edge \u306E\u500B\u6570\r\n\t\r\n\t\
    // euler-tour\r\n\tstd::vector<size_type> in_; // [v] := \u9802\u70B9 v \u306E\
    \ EulerTour \u9806\u5E8F(\u540C\u4E00 heavy-path \u5185\u3067\u306F\u9023\u7D9A\
    )\r\n\tstd::vector<size_type> out_; // [v] := \u9802\u70B9 v \u304B\u3089\u51FA\
    \u308B\u3068\u304D\u306E EulerTour \u9806\u5E8F\r\n\tstd::vector<size_type> euler_map_;\
    \ // [i] := EulerTour \u9806\u5E8F\u304C i \u3067\u3042\u308B\u3088\u3046\u306A\
    \u9802\u70B9\r\n\t\r\n\t// heavy-path doubling\r\n\tstd::vector<std::vector<size_type>>\
    \ par_dblng_; // [k][i] := heavy-path i \u304B\u3089 2^k \u56DE light-edge \u3092\
    \u4E0A\u3063\u305F\u5148\u306E\u9802\u70B9\r\n\t\r\npublic:\r\n\tHeavyLightDecomposition(const\
    \ Graph & g, bool use_lca = false) : HeavyLightDecomposition(g, g.size(), use_lca)\
    \ {}\r\n\tHeavyLightDecomposition(const Graph & g, size_type root, bool use_lca)\
    \ : bf_n(g.size()) {\r\n\t\tpar_.resize(bf_size());\r\n\t\tsub_size_.resize(bf_size());\r\
    \n\t\tdepth_.resize(bf_size());\r\n\t\ttree_id_.assign(bf_size(), bf_size());\r\
    \n\t\tstd::vector<size_type> next(bf_size()); // [v] := \u9802\u70B9 v \u3068\u540C\
    \u4E00 heavy-path \u5185\u3067 v \u3088\u308A 1 \u3064\u8449\u5074\u306E\u9802\
    \u70B9(\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u81EA\u5206\u81EA\u8EAB)\r\n\
    \t\t\r\n\t\tfor (size_type i = 0; i < bf_size(); ++i) {\r\n\t\t\tif (tree_id_[i]\
    \ != bf_size()) continue;\r\n\t\t\tif (root != bf_size() && i != root) continue;\r\
    \n\t\t\t\r\n\t\t\tstd::stack<std::pair<size_type, size_type>> stk;\r\n\t\t\tpar_[i]\
    \ = i;\r\n\t\t\tdepth_[i] = 0;\r\n\t\t\ttree_id_[i] = roots_.size();\r\n\t\t\t\
    stk.emplace(i, 0);\r\n\t\t\t\r\n\t\t\twhile (!stk.empty()) {\r\n\t\t\t\tconst\
    \ size_type u = stk.top().first, i = stk.top().second; stk.pop();\r\n\t\t\t\t\
    if (i < g[u].size()) {\r\n\t\t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\t\tconst\
    \ size_type v = g[u][i];\r\n\t\t\t\t\tif (v == par_[u]) continue;\r\n\t\t\t\t\t\
    par_[v] = u;\r\n\t\t\t\t\tdepth_[v] = depth_[u] + 1;\r\n\t\t\t\t\ttree_id_[v]\
    \ = roots_.size();\r\n\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t}\r\n\t\t\t\telse\
    \ {\r\n\t\t\t\t\tsize_type mx = 0;\r\n\t\t\t\t\tnext[u] = u;\r\n\t\t\t\t\tsub_size_[u]\
    \ = 1;\r\n\t\t\t\t\tfor (size_type v : g[u]) {\r\n\t\t\t\t\t\tif (v == par_[u])\
    \ continue;\r\n\t\t\t\t\t\tsub_size_[u] += sub_size_[v];\r\n\t\t\t\t\t\tif (mx\
    \ < sub_size_[v]) {\r\n\t\t\t\t\t\t\tmx = sub_size_[v];\r\n\t\t\t\t\t\t\tnext[u]\
    \ = v;\r\n\t\t\t\t\t\t}\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t\troots_.emplace_back(i);\r\
    \n\t\t}\r\n\t\t\r\n\t\theavy_map_.resize(bf_size());\r\n\t\tin_.resize(bf_size());\r\
    \n\t\tout_.resize(bf_size());\r\n\t\teuler_map_.reserve(bf_size());\r\n\t\t\r\n\
    \t\tfor (size_type root : roots_) {\r\n\t\t\tstd::stack<std::pair<size_type, size_type>>\
    \ stk;\r\n\t\t\t\r\n\t\t\theavy_map_[root] = head_.size();\r\n\t\t\thead_.emplace_back(root);\r\
    \n\t\t\theavy_size_.emplace_back(1);\r\n\t\t\theavy_depth_.emplace_back(0);\r\n\
    \t\t\tstk.emplace(root, 0);\r\n\t\t\t\r\n\t\t\twhile (!stk.empty()) {\r\n\t\t\t\
    \tconst size_type u = stk.top().first, i = stk.top().second; stk.pop();\r\n\t\t\
    \t\tif (i < g[u].size()) {\r\n\t\t\t\t\tstk.emplace(u, i + 1);\r\n\t\t\t\t\tconst\
    \ size_type v = g[u][i];\r\n\t\t\t\t\tif (v != par_[u] && v != next[u]) {\r\n\t\
    \t\t\t\t\theavy_map_[v] = head_.size();\r\n\t\t\t\t\t\thead_.emplace_back(v);\r\
    \n\t\t\t\t\t\theavy_size_.emplace_back(1);\r\n\t\t\t\t\t\theavy_depth_.emplace_back(heavy_depth_[heavy_map_[u]]\
    \ + 1);\r\n\t\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\
    \tif (i == 0) {\r\n\t\t\t\t\tin_[u] = euler_map_.size();\r\n\t\t\t\t\teuler_map_.emplace_back(u);\r\
    \n\t\t\t\t\tconst size_type v = next[u];\r\n\t\t\t\t\tif (v != u) {\r\n\t\t\t\t\
    \t\theavy_map_[v] = heavy_map_[u];\r\n\t\t\t\t\t\t++heavy_size_[heavy_map_[u]];\r\
    \n\t\t\t\t\t\tstk.emplace(v, 0);\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\tif (i\
    \ == g[u].size()) out_[u] = euler_map_.size();\r\n\t\t\t}\r\n\t\t}\r\n\t\t\r\n\
    \t\tif (!use_lca) return;\r\n\t\tsize_type max_depth = *std::max_element(begin(heavy_depth_),\
    \ end(heavy_depth_));\r\n\t\tsize_type lglg_n = 0;\r\n\t\twhile ((1 << lglg_n)\
    \ < max_depth) ++lglg_n;\r\n\t\t\r\n\t\tpar_dblng_.assign(lglg_n + 1, std::vector<size_type>(af_size()));\r\
    \n\t\tfor (size_type i = 0; i < af_size(); ++i) par_dblng_[0][i] = par_[head_[i]];\r\
    \n\t\tfor (size_type i = 0; i < lglg_n; ++i) {\r\n\t\t\tfor (size_type j = 0;\
    \ j < af_size(); ++j) {\r\n\t\t\t\tpar_dblng_[i + 1][j] = par_dblng_[i][heavy_map_[par_dblng_[i][j]]];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\t\r\n\tsize_type bf_size() const noexcept { return\
    \ bf_n; }\r\n\tsize_type af_size() const noexcept { return head_.size(); }\r\n\
    \t\r\n\tsize_type par(size_type v) const { assert(v < bf_size()); return par_[v];\
    \ }\r\n\tsize_type sub_size(size_type v) const { assert(v < bf_size()); return\
    \ sub_size_[v]; }\r\n\tsize_type depth(size_type v) const { assert(v < bf_size());\
    \ return depth_[v]; }\r\n\t\r\n\tsize_type tree_id(size_type v) const { assert(v\
    \ < bf_size()); return tree_id_[v]; }\r\n\tsize_type tree_cnt() const noexcept\
    \ { return roots_.size(); }\r\n\tconst std::vector<size_type> & trees() const\
    \ noexcept { return roots_; }\r\n\t\r\n\tsize_type heavy_map(size_type v) const\
    \ { assert(v < bf_size()); return heavy_map_[v]; }\r\n\tsize_type head(size_type\
    \ k) const { assert(k < af_size()); return head_[k]; }\r\n\tsize_type heavy_size(size_type\
    \ k) const { assert(k < af_size()); return heavy_size_[k]; }\r\n\tsize_type heavy_depth(size_type\
    \ k) const { assert(k < af_size()); return heavy_depth_[k]; }\r\n\t\r\n\tsize_type\
    \ in(size_type v) const { assert(v < bf_size()); return in_[v]; }\r\n\tsize_type\
    \ out(size_type v) const { assert(v < bf_size()); return out_[v]; }\r\n\tsize_type\
    \ euler_map(size_type k) const { assert(k < bf_size()); return euler_map_[k];\
    \ }\r\n\t\r\n\tconst std::vector<std::vector<size_type>> & par_dblng() const {\r\
    \n\t\tassert(!par_dblng_.empty());\r\n\t\treturn par_dblng_;\r\n\t}\r\n\t\r\n\t\
    std::pair<size_type, size_type> get_lca_path(size_type x, size_type y) const {\r\
    \n\t\tassert(!par_dblng_.empty());\r\n\t\tassert(x < bf_size());\r\n\t\tassert(y\
    \ < bf_size());\r\n\t\tassert(tree_id_[x] == tree_id_[y]);\r\n\t\tif (heavy_map_[x]\
    \ == heavy_map_[y]) return {x, y};\r\n\t\t\r\n\t\tbool isswap = heavy_depth_[heavy_map_[x]]\
    \ < heavy_depth_[heavy_map_[y]];\r\n\t\tif (isswap) std::swap(x, y);\r\n\t\t\r\
    \n\t\tconst size_type diff = heavy_depth_[heavy_map_[x]] - heavy_depth_[heavy_map_[y]];\r\
    \n\t\tfor (size_type i = par_dblng_.size(); i > 0; --i) {\r\n\t\t\tif (diff >>\
    \ (i - 1) & 1) x = par_dblng_[i - 1][heavy_map_[x]];\r\n\t\t}\r\n\t\tif (heavy_map_[x]\
    \ == heavy_map_[y]) return isswap ? std::make_pair(y, x) : std::make_pair(x, y);\r\
    \n\t\t\r\n\t\tfor (size_type i = par_dblng_.size(); i > 0; --i) {\r\n\t\t\tconst\
    \ size_type p1 = par_dblng_[i - 1][heavy_map_[x]], p2 = par_dblng_[i - 1][heavy_map_[y]];\r\
    \n\t\t\tif (heavy_map_[p1] != heavy_map_[p2]) x = p1, y = p2;\r\n\t\t}\r\n\t\t\
    x = par_dblng_[0][heavy_map_[x]];\r\n\t\ty = par_dblng_[0][heavy_map_[y]];\r\n\
    \t\treturn isswap ? std::make_pair(y, x) : std::make_pair(x, y);\r\n\t}\r\n\t\r\
    \n\tsize_type get_lca(size_type x, size_type y) {\r\n\t\tassert(!par_dblng_.empty());\r\
    \n\t\tassert(x < bf_size());\r\n\t\tassert(y < bf_size());\r\n\t\tstd::pair<size_type,\
    \ size_type> res = get_lca_path(x, y);\r\n\t\treturn in_[res.first] < in_[res.second]\
    \ ? res.first : res.second;\r\n\t}\r\n};\r\n\r\n\n#line 1 \"GraphTheory/HeavyLightDecomposition_Query.hpp\"\
    \n\n\n\r\n/*\r\nlast-updated: 2020/09/18\r\n\r\n\u68EE\u4E0A\u3067 1 \u70B9\u66F4\
    \u65B0, \u30D1\u30B9\u30AF\u30A8\u30EA\u3084\u90E8\u5206\u6728\u30AF\u30A8\u30EA\
    \u3092 HL \u5206\u89E3\u3092\u7528\u3044\u3066\u89E3\u3044\u3066\u304F\u308C\u308B\
    \u4FBF\u5229\u30C7\u30FC\u30BF\u69CB\u9020\r\n\u9802\u70B9\u5C5E\u6027(\u9802\u70B9\
    \u306B\u5024\u3092\u6301\u3064), \u8FBA\u5C5E\u6027(\u8FBA\u306B\u5024\u3092\u6301\
    \u3064) \u3069\u3061\u3089\u306B\u3082\u5BFE\u5FDC\r\n\u30D1\u30B9\u30AF\u30A8\
    \u30EA\u306E\u5834\u5408\u3001\u6F14\u7B97\u304C\u975E\u53EF\u63DB\u3067\u3082\
    \ ok (\u30BB\u30B0\u6728\u3082\u975E\u53EF\u63DB\u306B\u5BFE\u5FDC\u3057\u3066\
    \u3044\u308B\u5FC5\u8981\u304C\u3042\u308B)\r\n\r\n\u30D1\u30B9\u66F4\u65B0\u306E\
    \u5834\u5408\u306F\u5C11\u3057\u5909\u66F4\u3059\u308B\u3053\u3068\u3067 LazySegmentTree\
    \ \u3092\u7528\u3044\u3066\u89E3\u3051\u308B(\u30CF\u30BA)\r\n\r\n# \u4ED5\u69D8\
    \r\n\u6B21\u306E\u8A08\u7B97\u91CF\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\r\
    \n- HeavyLightDecomposition \u306E\u69CB\u7BC9\u3092 \u0398(n)\r\n- \u5024\u306E\
    \u6F14\u7B97\u3092 \u0398(1)\r\n- SegmentTree:\r\n-- \u521D\u671F\u5024\u6307\u5B9A\
    \u521D\u671F\u5316: \u0398(n)\r\n-- set, fold: O(log n)\r\n-- get \u304C \u0398\
    (1)\r\n\r\ntemplate \u5F15\u6570:\r\n\tclass HLD: HeavyLightDecomposition(Library\
    \ \u5185\u306E lca \u95A2\u9023\u3092\u9664\u304F\u6A5F\u80FD\u3092\u8981\u6C42\
    )\r\n\ttypename T: \u6271\u3046\u5024\u306E\u578B\r\n\ttemplate<typename> class\
    \ SEG>: T \u3092 template \u5F15\u6570\u306B\u6301\u3064 SegmentTree(set, get,\
    \ fold \u3092\u8981\u6C42)\r\n\r\nHeavyLightDecomposition_Query(\r\n\tconst Graph\
    \ & g: \u30B0\u30E9\u30D5\r\n\tsize_type root: \u30B0\u30E9\u30D5\u304C\u6728\u3067\
    \u3042\u308B\u3068\u304D\u3001\u305D\u306E\u6839(\u7701\u7565\u53EF)\r\n\tconst\
    \ value_type & id_elem: \u5358\u4F4D\u5143\r\n\tconst F & f : \u4E8C\u9805\u6F14\
    \u7B97\r\n\tbool value_on_vertex : \u9802\u70B9\u5C5E\u6027\u304B\u3069\u3046\u304B\
    (true - \u9802\u70B9\u5C5E\u6027, false - \u8FBA\u5C5E\u6027) )\r\n\t\u6642\u9593\
    \u8A08\u7B97\u91CF: \u0398(n)\r\n\t\u30B0\u30E9\u30D5 g \u3092 HL \u5206\u89E3\
    \u3057\u3001\u5404(\u9802\u70B9 or \u8FBA) \u306E\u5024\u3092\u5358\u4F4D\u5143\
    \ id_elem \u3067\u521D\u671F\u5316\r\n\r\ntemplate<typename U>\r\nHeavyLightDecomposition_Query(\r\
    \n\tconst Graph & g: \u30B0\u30E9\u30D5\r\n\tsize_type root: \u30B0\u30E9\u30D5\
    \u304C\u6728\u3067\u3042\u308B\u3068\u304D\u3001\u305D\u306E\u6839(\u7701\u7565\
    \u53EF)\r\n\tconst std::vector<U> & v: \u5404\u9802\u70B9\u306E\u5024\u306E\u521D\
    \u671F\u5024\r\n\tconst value_type & id_elem: \u5358\u4F4D\u5143\r\n\tconst F\
    \ & f : \u4E8C\u9805\u6F14\u7B97 )\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398\
    (n)\r\n\t\u30B0\u30E9\u30D5 g \u3092 HL \u5206\u89E3\u3057\u3001\u5168\u3066\u306E\
    \u9802\u70B9\u306E\u5024\u3092 v \u3067\u521D\u671F\u5316\u3059\u308B\r\n\t\u8FBA\
    \u5C5E\u6027\u306E\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u521D\u671F\u5316\
    \u306B\u306F\u5BFE\u5FDC\u3057\u3066\u3044\u306A\u3044\r\n\r\nconst hld_type &\
    \ get_hld() const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\u5185\u90E8\
    \u3067\u6271\u3063\u3066\u3044\u308B HeavyLightDecomposition \u30A4\u30F3\u30B9\
    \u30BF\u30F3\u30B9\u3092\u8FD4\u3059\r\n\r\n- \u9802\u70B9\u5C5E\u6027\r\n\tvoid\
    \ set(size_type v, const_reference x)\r\n\t\t\u6642\u9593\u8A08\u7B97\u91CF: O(log\
    \ n)\r\n\t\t\u9802\u70B9 v \u306E\u5024\u3092 x \u306B\u5909\u66F4\u3059\u308B\
    \r\n\r\n\tvalue_type get(size_type v) const\r\n\t\t\u6642\u9593\u8A08\u7B97\u91CF\
    : \u0398(1)\r\n\t\t\u9802\u70B9 v \u306E\u5024\u3092\u8FD4\u3059\r\n\r\n- \u8FBA\
    \u5C5E\u6027\r\n\tvoid set(size_type u, size_type v, const_reference x)\r\n\t\t\
    \u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\n\t\t\u8FBA u-v \u306E\u5024\u3092\
    \ x \u306B\u5909\u66F4\u3059\u308B\r\n\r\n\tvalue_type get(size_type u, size_type\
    \ v) const\r\n\t\t\u6642\u9593\u8A08\u7B97\u91CF: \u0398(1)\r\n\t\t\u8FBA u-v\
    \ \u306E\u5024\u3092\u8FD4\u3059\r\n\r\nvalue_type fold(size_type u, size_type\
    \ v) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O((log n)^2)\r\n\t\u9802\u70B9\
    \u5C5E\u6027\u306E\u5834\u5408\u306F u-v \u30D1\u30B9\u4E0A\u306E\u9802\u70B9\
    (\u7AEF\u70B9\u542B\u3080)\u306E\u5024\u306E fold \u3057\u305F\u5024\u3092\u8FD4\
    \u3059\r\n\t\u8FBA\u5C5E\u6027\u306E\u5834\u5408\u306F u-v \u30D1\u30B9\u4E0A\u306E\
    \u8FBA\u306E\u5024\u306E fold \u3057\u305F\u5024\u3092\u8FD4\u3059\r\n\r\nvalue_type\
    \ subtree_sum(size_type v) const\r\n\t\u6642\u9593\u8A08\u7B97\u91CF: O(log n)\r\
    \n\t\u9802\u70B9 v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u5185\u306E\
    \u5024\u306E\u5408\u8A08\u3092\u6C42\u3081\u308B\r\n\r\n# \u53C2\u8003\r\n\u8FBA\
    \u5C5E\u6027 verify(2020/09/18): https://atcoder.jp/contests/abc133/submissions/16817431\r\
    \n*/\r\n\r\n#line 88 \"GraphTheory/HeavyLightDecomposition_Query.hpp\"\n\r\ntemplate<class\
    \ HLD, typename T, template<typename> class SEG>\r\nstruct HeavyLightDecomposition_Query\
    \ {\r\n\tusing value_type = T;\r\n\tusing const_reference = const value_type &;\r\
    \n\tusing seg_type = SEG<value_type>;\r\n\tusing hld_type = HLD;\r\n\tusing size_type\
    \ = std::uint_fast32_t;\r\n\tusing Graph = typename hld_type::Graph;\r\n\tusing\
    \ F = std::function<value_type(const_reference, const_reference)>;\r\n\t\r\nprivate:\r\
    \n\tvalue_type id_elem;\r\n\tF f;\r\n\thld_type hld;\r\n\tseg_type seg, rseg;\r\
    \n\tbool value_on_vertex;\r\n\t\r\npublic:\r\n\tHeavyLightDecomposition_Query(const\
    \ Graph & g, const value_type & id_elem, const F & f, bool value_on_vertex)\r\n\
    \t\t: HeavyLightDecomposition_Query(g, g.size(), id_elem, f, value_on_vertex)\
    \ {}\r\n\t\r\n\tHeavyLightDecomposition_Query(const Graph & g, size_type root,\
    \ const value_type & id_elem, const F & f, bool value_on_vertex)\r\n\t\t: id_elem(id_elem),\
    \ f(f), hld(g, root, false), value_on_vertex(value_on_vertex) {\r\n\t\tseg = seg_type{\
    \ hld.bf_size(), id_elem, f };\r\n\t\trseg = seg_type{ hld.bf_size(), id_elem,\
    \ f };\r\n\t}\r\n\t\r\n\ttemplate<typename U>\r\n\tHeavyLightDecomposition_Query(const\
    \ Graph & g, const std::vector<U> & v, const value_type & id_elem, const F & f)\r\
    \n\t\t: HeavyLightDecomposition_Query(g, g.size(), v, id_elem, f) {}\r\n\t\r\n\
    \ttemplate<typename U>\r\n\tHeavyLightDecomposition_Query(const Graph & g, size_type\
    \ root, const std::vector<U> & v, const value_type & id_elem, const F & f)\r\n\
    \t\t: id_elem(id_elem), f(f), hld(g, root, false), value_on_vertex(true) {\r\n\
    \t\tstd::vector<value_type> init(hld.bf_size());\r\n\t\tfor (size_type i = 0;\
    \ i < hld.bf_size(); ++i) init[i] = v[hld.euler_map(i)];\r\n\t\tseg = seg_type{\
    \ init, id_elem, f };\r\n\t\t\r\n\t\tfor (size_type i = 0; i < hld.af_size();\
    \ ++i) {\r\n\t\t\tconst size_type fidx = hld.in(hld.head(i));\r\n\t\t\tstd::reverse(begin(init)\
    \ + fidx, begin(init) + fidx + hld.heavy_size(i));\r\n\t\t}\r\n\t\trseg = seg_type{\
    \ init, id_elem, f };\r\n\t}\r\n\t\r\n\tconst hld_type & get_hld() const {\r\n\
    \t\treturn hld;\r\n\t}\r\n\t\r\n\tvoid set(size_type v, const_reference x) {\r\
    \n\t\tassert(value_on_vertex);\r\n\t\tassert(v < hld.bf_size());\r\n\t\tset_(v,\
    \ x);\r\n\t}\r\n\t\r\n\tvalue_type get(size_type v) const {\r\n\t\tassert(value_on_vertex);\r\
    \n\t\tassert(v < hld.bf_size());\r\n\t\treturn get_(v);\r\n\t}\r\n\t\r\n\tvoid\
    \ set(size_type u, size_type v, const_reference x) {\r\n\t\tassert(!value_on_vertex);\r\
    \n\t\tassert(u < hld.bf_size());\r\n\t\tassert(v < hld.bf_size());\r\n\t\tassert(hld.par(u)\
    \ == v || hld.par(v) == u);\r\n\t\tset_(hld.par(u) == v ? u : v, x);\r\n\t}\r\n\
    \t\r\n\tvalue_type get(size_type u, size_type v) const {\r\n\t\tassert(!value_on_vertex);\r\
    \n\t\tassert(u < hld.bf_size());\r\n\t\tassert(v < hld.bf_size());\r\n\t\tassert(hld.par(u)\
    \ == v || hld.par(v) == u);\r\n\t\treturn get_(hld.par(u) == v ? u : v);\r\n\t\
    }\r\n\t\r\nprivate:\r\n\tvoid set_(size_type v, const_reference x) {\r\n\t\tseg.set(hld.in(v),\
    \ x);\r\n\t\trseg.set(reverse_idx(v), x);\r\n\t}\r\n\t\r\n\tvalue_type get_(size_type\
    \ v) const {\r\n\t\treturn seg.get(hld.in(v));\r\n\t}\r\n\t\r\npublic:\r\n\tvalue_type\
    \ fold(size_type u, size_type v) const {\r\n\t\tassert(u < hld.bf_size());\r\n\
    \t\tassert(v < hld.bf_size());\r\n\t\tassert(hld.tree_id(u) == hld.tree_id(v));\r\
    \n\t\tvalue_type lv = id_elem, rv = id_elem;\r\n\t\t\r\n\t\twhile (hld.heavy_map(u)\
    \ != hld.heavy_map(v)) {\r\n\t\t\tif (hld.heavy_depth(hld.heavy_map(u)) >= hld.heavy_depth(hld.heavy_map(v)))\
    \ {\r\n\t\t\t\tconst size_type head = hld.head(hld.heavy_map(u));\r\n\t\t\t\t\
    lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(head) + 1));\r\n\t\t\t\tu = hld.par(head);\r\
    \n\t\t\t}\r\n\t\t\tif (hld.heavy_map(u) == hld.heavy_map(v)) break;\r\n\t\t\t\
    if (hld.heavy_depth(hld.heavy_map(u)) <= hld.heavy_depth(hld.heavy_map(v))) {\r\
    \n\t\t\t\tconst size_type head = hld.head(hld.heavy_map(v));\r\n\t\t\t\trv = f(seg.fold(hld.in(head),\
    \ hld.in(v) + 1), rv);\r\n\t\t\t\tv = hld.par(head);\r\n\t\t\t}\r\n\t\t}\r\n\t\
    \t\r\n\t\tconst size_type id = hld.heavy_map(u);\r\n\t\tif (hld.in(u) < hld.in(v))\
    \ rv = f(seg.fold(hld.in(u) + !value_on_vertex, hld.in(v) + 1), rv);\r\n\t\telse\
    \ lv = f(lv, rseg.fold(reverse_idx(u), reverse_idx(v) + value_on_vertex));\r\n\
    \t\treturn f(lv, rv);\r\n\t}\r\n\t\r\n\tvalue_type subtree_sum(size_type v) const\
    \ {\r\n\t\treturn seg.fold(hld.in(v), hld.out(v));\r\n\t}\r\n\t\r\nprivate:\r\n\
    \tsize_type reverse_idx(size_type v) const {\r\n\t\tconst size_type id = hld.heavy_map(v);\r\
    \n\t\treturn (hld.in(hld.head(id)) << 1) + hld.heavy_size(id) - hld.in(v) - 1;\r\
    \n\t}\r\n};\r\n\r\n\n#line 6 \"Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp\"\
    \n\r\n#include <cstdio>\r\n#line 9 \"Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp\"\
    \n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"%d %d\", &N, &Q);\r\n\t\r\n\tstd::vector<int>\
    \ A(N);\r\n\tfor (int i = 0; i < N; ++i) scanf(\"%d\", &A[i]);\r\n\t\r\n\tHeavyLightDecomposition::Graph\
    \ g(N);\r\n\tfor (int i = 1; i < N; ++i) {\r\n\t\tint p;\r\n\t\tscanf(\"%d\",\
    \ &p);\r\n\t\tg[p].emplace_back(i);\r\n\t}\r\n\t\r\n\tusing ll = long long;\r\n\
    \tHeavyLightDecomposition_Query<HeavyLightDecomposition, ll, SegmentTree> hld(g,\
    \ A, 0, [](ll a, ll b) { return a + b; });\r\n\t\r\n\twhile (Q--) {\r\n\t\tint\
    \ q;\r\n\t\tscanf(\"%d\", &q);\r\n\t\tif (q == 0) {\r\n\t\t\tint u, x;\r\n\t\t\
    \tscanf(\"%d %d\", &u, &x);\r\n\t\t\thld.set(u, hld.get(u) + x);\r\n\t\t}\r\n\t\
    \telse {\r\n\t\t\tint u;\r\n\t\t\tscanf(\"%d\", &u);\r\n\t\t\tprintf(\"%lld\\\
    n\", hld.subtree_sum(u));\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \r\n\r\n#include \"DataStructure/SegmentTree.hpp\"\r\n#include \"GraphTheory/HeavyLightDecomposition.hpp\"\
    \r\n#include \"GraphTheory/HeavyLightDecomposition_Query.hpp\"\r\n\r\n#include\
    \ <cstdio>\r\n#include <vector>\r\n\r\nint main() {\r\n\tint N, Q;\r\n\tscanf(\"\
    %d %d\", &N, &Q);\r\n\t\r\n\tstd::vector<int> A(N);\r\n\tfor (int i = 0; i < N;\
    \ ++i) scanf(\"%d\", &A[i]);\r\n\t\r\n\tHeavyLightDecomposition::Graph g(N);\r\
    \n\tfor (int i = 1; i < N; ++i) {\r\n\t\tint p;\r\n\t\tscanf(\"%d\", &p);\r\n\t\
    \tg[p].emplace_back(i);\r\n\t}\r\n\t\r\n\tusing ll = long long;\r\n\tHeavyLightDecomposition_Query<HeavyLightDecomposition,\
    \ ll, SegmentTree> hld(g, A, 0, [](ll a, ll b) { return a + b; });\r\n\t\r\n\t\
    while (Q--) {\r\n\t\tint q;\r\n\t\tscanf(\"%d\", &q);\r\n\t\tif (q == 0) {\r\n\
    \t\t\tint u, x;\r\n\t\t\tscanf(\"%d %d\", &u, &x);\r\n\t\t\thld.set(u, hld.get(u)\
    \ + x);\r\n\t\t}\r\n\t\telse {\r\n\t\t\tint u;\r\n\t\t\tscanf(\"%d\", &u);\r\n\
    \t\t\tprintf(\"%lld\\n\", hld.subtree_sum(u));\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\
    \n}"
  dependsOn:
  - DataStructure/SegmentTree.hpp
  - GraphTheory/HeavyLightDecomposition.hpp
  - GraphTheory/HeavyLightDecomposition_Query.hpp
  isVerificationFile: true
  path: Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 15:28:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
layout: document
redirect_from:
- /verify/Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
- /verify/Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp.html
title: Test/HeavyLightDecomposition_Query.SubtreeQuery.test.cpp
---