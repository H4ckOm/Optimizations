
int countOrders(int n) {
	long long result = 1ll;
	int sum[2*n];
	sum[0] = 0;
	for(int i=1; i<2*n; i++) {
		sum[i] = (i + (sum[i-1]))%mod;
		if (i&1) {
			result = (result * sum[i])%mod;
		}
	}

	return result;
}