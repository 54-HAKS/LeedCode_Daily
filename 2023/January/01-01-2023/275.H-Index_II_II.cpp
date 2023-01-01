class Solution {
 public:
  int hIndex(vector<int>& v) {
	auto it=lower_bound(v.begin(), v.end(), v.size(), [&v](int& elt, const int &n)
	{ int idx=&elt-&v[0];  return elt+idx<n; });
	return distance(it, v.end());
}
};
