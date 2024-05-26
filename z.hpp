#include <vector>

using namespace std;

// z[i] = longest common prefix of s[0...] and s[i...]
template <class T>
void build_z(const T * first, const T * last, vector<int> & z)
{
	const T * & s = first;
	const int n = last - first;
	z.resize(n);
	z[0] = n;
	for (int i = 1, k, l = 0, r = 0; i < n; i++)
	{
		for (k = (i < r ? min(z[i - l], r - i) : 0); i + k < n && s[i + k] == s[k]; k++);
		z[i] = k;
		if (r < i + k)
			l = i, r = i + k;
	}
}
