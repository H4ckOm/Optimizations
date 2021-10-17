/*

                      HAIL TLRX
 .----------------.   .----------------.   .----------------.
| .--------------. | | .--------------. | | .--------------. |
| |  _______     | | | |  _________   | | | |  ____  ____  | |
| | |_   __ \    | | | | |_   ___  |  | | | | |_  _||_  _| | |
| |   | |__) |   | | | |   | |_  \_|  | | | |   \ \  / /   | |
| |   |  __ /    | | | |   |  _|  _   | | | |    > `' <    | |
| |  _| |  \ \_  | | | |  _| |___/ |  | | | |  _/ /'`\ \_  | |
| | |____| |___| | | | | |_________|  | | | | |____||____| | |
| |              | | | |              | | | |              | |
| '--------------' | | '--------------' | | '--------------' |
 '----------------'   '----------------'   '----------------'

* @Author: Kunal Verma

CodeForces - kunalverma19
CodeChef   - kunalverma_19
AtCoder    - TLKunalVermaRX

* @Last Modified by:   hereiskunalverma
* @Modified Time: 2021-10-17 08:28:49  (IST)


*/


#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1000000007;
double eps = 1e-12;
#define ln "\n"
#define printVector(a) for(int i=0; i<a.size(); i++){cout<<a[i]<<" ";}cout<<ln;
#define print_array(a,n) for(int i=0; i<n; i++){cout<<a[i]<<" ";}cout<<ln;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define take_vector(a) for(auto &x:a)cin>>x;
#define take_array(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define take_matrix(a,m,n) for(int i=0; i<m; i++){for(int j=0; j<n; j++){cin>>a[i][j];}}
#define print_matrix(a,m,n) for(int i=0; i<m; i++){for(int j=0; j<n; j++){cout<<a[i][j]<<" ";}cout<<ln;}
#define fi first
#define se second
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b
#define el_count(a,x) count(a.begin(), a.end(),x)
#define max_ele(a) *max_element(a.begin(), a.end())
#define min_ele(a) *min_element(a.begin(), a.end())
#define setbit(x)  __builtin_popcount(x)
#define debug(s) cout<<s<<ln
const int bit = 32;

// Useful Templates
string operator*(const string& s, unsigned int n) {
	stringstream out;
	while (n--)
		out << s;
	return out.str();
}
string operator*(unsigned int n, const string& s) { return s * n; }

// check if all same elements
template<class T>
bool equal_ele(const T& a) {
	if (adjacent_find(all(a), not_equal_to<>()) == a.end())
		return true;
	return false;
}

// Pythonic way of getting size/length
size_t GetLength(const string s) {return s.size();}
size_t GetLength(const v32 a) {return a.size();}
size_t GetLength(const v64 a) {return a.size();}
template<typename T>
int len(T s) {
	return GetLength(s);
}

// without regex approach
// replace all occureces of string to other
// example : s = "hi I am here",
// replaceAll(s," ", "this");
// output : "hithisIamthis"
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}

// Useful Functions
ll getSum(string str)
{
	// to get sum of digits of number (upto 10^18)
	ll sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		sum = sum + str[i] - 48;
	}
	return sum;
}
double round_up(double value, int decimal_places)
{
	const double multiplier = std::pow(10.0, decimal_places);
	return std::ceil(value * multiplier) / multiplier;
}
bool ispowerof2(ll x) {
	return (x & (x - 1)) == 0;
}
void sort_even_first_then_odd(vector<int> &a)
{
	sort(a.begin(), a.end(), [](int x, int y)
	{
		return x % 2 < y % 2;
	});
}
// return strings with exactly k length
string ok(string s, int k) {
	int n = s.size();
	string ans = "";
	for (int i = 0; i < k; i++) {
		ans += (char)(s[i % n]);
	}
	return ans;
}

// to check prime number
bool is_prime(int n) {
	if (n == 1) {
		return false;
	}

	int i = 2;
	while (i * i <= n) {
		if (n % i == 0) {
			return false;
		}
		i += 1;
	}
	return true;
}
ll getProduct(string str)
{
	ll product = 1;

	// Traversing through the string
	for (ll i = 0; i < str.length(); i++) {
		// Since ascii value of
		// numbers starts from 48
		// so we subtract it from sum
		product = product * (str[i] - 48);
	}
	return product;
}
bool customSort(const p32 &a, const p32 &b) {
	if (a.fi == b.fi)
		return a.se < b.se;
	return a.fi > b.fi;
}

void solve()
{
	// Here I am, Beautiful

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast_cin();
	ll t = 1;
	cin >> t;
	for (int it = 1; it <= t; it++)
	{
		// // cout << "Case #" << it << ": ";
		// solve();
		int n;
		cin >> n;
		string s;
		cin >> s;
		int res = 0;
		int x = 0, y = 0;
		int dp[n] = {};
		if (s[0] == 'X')
			x = 1;
		else if (s[0] == 'O')
			y = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] == 'X') {
				x = i + 1;
				if (s[i - 1] == 'X') {
					dp[i] = dp[i - 1];
					continue;
				}
				dp[i] = ((y > 0 ? dp[y - 1] : 0) + dp[i] + y) % MOD;
			}
			else if (s[i] == 'O') {
				y = i + 1;
				if (s[i - 1] == 'O') {
					dp[i] = dp[i - 1];
					continue;
				}
				dp[i] = ((x > 0 ? dp[x - 1] : 0) + dp[i] + x) % MOD;
			}
			else {
				dp[i] = dp[i - 1];
			}
		}
		for (int i = 0; i < n; i++) {
			res = (res + dp[i]) % MOD;
		}
		cout << "Case #" << it << ": " << res << ln;
	}
	return 0;
}

