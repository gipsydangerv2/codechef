#include <bits/stdc++.h>
using namespace std;
#define maxval 100005
int isPrime[100005];
int marked[100005];
int table[100005][6];

void sieve(){
    for(int i=0;i<maxval;i++){
        isPrime[i] = 1;
        marked[i] = 0;
    }
    for(int i=2;i<maxval;i+=2){
        isPrime[i] = 0;
        marked[i]++;
    }
    isPrime[0] = 0;
    isPrime[1] = 0;
    isPrime[2] = 1;
    for(int i=3;i*i<maxval;i++){
        if(isPrime[i] == 1){
            marked[i]++;
            for(int j = 2*i;j<maxval;j+=i){
                isPrime[j] = 0;
                marked[j] ++;
            }
        }
    }
}
void createTable(){
    for(int i=0;i<maxval;i++)
        for(int j=0;j<6;j++)
            table[i][j] = 0;
    for(int j=2;j<maxval;j++){
        for(int i=1;i<=5;i++){
            table[j][i] = table[j-1][i];
        }
        int v = marked[j];
        if(v>= 1 && v <= 5)
            table[j][v]++;
    }
}
int main()
{
    int t,a,b,k;
    ios::sync_with_stdio(false);
    sieve();
    createTable();
    cin >> t;
    while(t--){
        cin >> a >> b >> k;
        cout << table[b][k] - table[a-1][k] << "\n";
    }
    return 0;
}
