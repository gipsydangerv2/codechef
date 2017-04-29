#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<long long int>isPrime(100001,1);
vector<long long int>prime;
void sieve(){
	long long int max = 100001;
	isPrime[0] = 0;
	isPrime[1] = 0;
	for(long long int i=2;i<max;i+=2)
		isPrime[i] = 0;
	prime.push_back(2);
	for(long long int i=3;i<max;i+=2){
		if(isPrime[i]){
			prime.push_back(i);
			for(long long int j = i * i ; j < max ; j += i )
				isPrime[j] = 0;
		}
	}
		
}
void segmentedSieve(long long int left, long long int right){
	vector<long long int> primes(right-left+1,1);
	//long long int root = sqrt(right);
	
	if(left == 1) 
		left++;
		
	long long int len = prime.size();
	for(long long int i = 0 ;prime[i] * prime[i] <= right and i<len;i++){
		long long int pr = prime[i];
		long long int num = ceil(1.0 * left / pr) * pr ;
		//cout << "num "<< num << endl;
		for(long long int j = num; j<=right; j += pr){
			//cout << "num:" << j << " ";
			if( j!=pr && primes[j-left] == 1){
				primes[j-left] = 0;
				//cout << " , " << j << " ";
			}	
		}
		//cout << endl;
	}
	for(long long int i = left ;i<=right;i++){
		if(primes[i-left])
			cout << i << endl;
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	sieve();
	long long int t,a,b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		segmentedSieve(a,b);
	}
	return 0;
}
