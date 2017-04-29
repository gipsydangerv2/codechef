#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<queue>
#include<fstream>
using namespace std;
vector<int> lowestPrime(1000001,0);
vector<long long int> lowestPrimes[100001];
vector<int> primes;

class compare{
	public:
		bool operator ()(const pair<long long int,int> & p1,const pair<long long int,int> &p2){
			return p1.second < p2.second;
		}
};
void findLowestPrime(long long int root){
	lowestPrime[1] = 0;
    for(long long int i=2;i<=root;i++){
        if(lowestPrime[i]==0){
        	lowestPrime[i] = i;
        	primes.push_back(i);
            for(long long int j=i*i;j<=root;j+= i){
                if(lowestPrime[j]==0)
                    lowestPrime[j] = i;
            }
        }
    }
}
void segmentedSieve(long long int left,long long int right){

     for(vector<int>::iterator itr = primes.begin(); itr != primes.end(); itr++){
    	int prime = *itr; 
        long long int num = ceil(left * 1.0 / prime) * prime;
        for(long long int k = num ;k <= right; k += prime){
        	lowestPrimes[k-left].push_back(prime);
        }
    }
    for(long long int i = left ;i <= right;i++){
    	if(lowestPrimes[i-left].size() == 0){
    		lowestPrimes[i-left].push_back(i);
    	}
	}
}
priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,compare> factorize(long long int left, long long int  num){
    priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,compare> pq;
    int index = num - left;
    int len = lowestPrimes[index].size();
    long long int temp = num;
    for(int i = 0;i < len;i++){
    	int count = 0;
    	int pr = lowestPrimes[index][i];
    	while(temp % pr == 0){
    		count++;
    		temp = temp / pr;
		}
		if (count > 0) 
			pq.push(make_pair(pr,count));
	}
	if(temp != 1)
		pq.push(make_pair(temp,1));
    return pq;
}
int getPathLength(long long int left,long long int num){
    if (num == 1) return 0;
    if(lowestPrimes[num-left][0] == num) return 2;
    priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,compare> pq = factorize(left,num);
    long long int sum = 0;
    bool flag = false;
    while(!pq.empty()){
        pair<long long int,int> max_exp = pq.top();
        map<long long int,int> m;
        int propDivisor = 1;
        while(!pq.empty()){
            pair<long long int,int> p = pq.top(); // 999999900000 1000000000000
            pq.pop();
            m[p.first] = p.second;
            propDivisor *= (p.second + 1);
        }
        if(max_exp.second > 1){
                pq.push(make_pair(max_exp.first, max_exp.second - 1));
        }
        for(map<long long int,int>::iterator itr = m.begin(); itr != m.end(); itr++){
            if(itr->first != max_exp.first){
                pq.push(make_pair(itr->first,itr->second));
            }
        }
    }
    return sum;
}
int main(){
    long long int a,b;
    cin >> a >> b;
    long long int range = b-a+1;
    long long int root = sqrt(b) + 1; // to find primes until root of b
    findLowestPrime(root);
    segmentedSieve(a,b);
    long long int sum = 0;
    for(long long int i=a;i<=b;i++){
    	long long int result = getPathLength(a,i);
        sum += result;
    }
    cout << sum <<"\n";
    return 0;
}
