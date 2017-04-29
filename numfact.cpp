#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
vector<long long int>lowestPrime(1000001,0);
vector<long long int>prime;
#define lli long long int
void sieve(){
	long long int max = 1000001;
	lowestPrime[0] = 0;
	lowestPrime[1] = 0;
	for(long long int i=2;i<max;i+=2)
		lowestPrime[i] = 2;
	for(long long int i=3;i<max;i+=2){
		if(lowestPrime[i] == 0){
			lowestPrime[i] = i;
			for(long long int j = i * i ; j < max ; j += i )
				if(lowestPrime[j] == 0)
					lowestPrime[j] = i;
		}
	}
		
}
map<long long int,long long int> factorize(long long int num){
	map<long long int,long long int> m;
	long long int temp = num;
	while(temp != 1){
		if(m.find(lowestPrime[temp]) != m.end())
			m[lowestPrime[temp]] ++;
		else
			m[lowestPrime[temp]] = 1;
		temp = temp / lowestPrime[temp];
	}
	
	return m;
}
long long int getFactors(vector<long long int> vec){
	map<long long int,long long int> m;
	int len = vec.size();
	map<lli,lli>::iterator itr ;
	for(long long int i = 0;i<len;i++){
		map<lli,lli> primeFactor = factorize(vec[i]);
		for(itr = primeFactor.begin() ; itr != primeFactor.end();itr++){
			if(m.find(itr->first) != m.end())
				m[itr->first] += itr->second;
			else
				m[itr->first] = itr->second;
		}
	}
	long long int factorCount = 1;
	for(itr = m.begin() ; itr != m.end() ; itr++){
		factorCount *= (itr->second + 1);
	}
	return factorCount;
}
int main(){
	ios::sync_with_stdio(false);
	sieve();
	long long int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		vector<long long int> vec;
		long long int num,sum =0;
		for(int i=0;i<n;i++){
			cin >> num;
			vec.push_back(num);
		}
		sum = getFactors(vec);
		cout <<sum <<"\n";
	}
	return 0;
}
