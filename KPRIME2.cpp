
#include <bits/stdc++.h>
using namespace std;
#define maxval 100005
int isPrime[100005];
int marked[100005];
int table[100005][6];
//ofstream fout;
void sieve(){
    for(int i=0;i<maxval;i++){
        marked[i] = 0;
        isPrime[i] = 1;
    }
    for(int i=2;i<maxval;i++){
        if(isPrime[i] == 1){
            marked[i] = 1;
            //cout << "prime:" << i << "\n";
            //fout << i << "\n";
            for(int j = 2*i;j<maxval;j+=i){
                isPrime[j] = 0;
                marked[j] ++;
            }
        }
    }
    /*for(int i=1;i<maxval;i++){
        //cout << "marked["<<i<<"]:" << marked[i]<< "\n";
        fout << marked[i]<< " ";
        if(i % 10 == 0) fout << "\n";
    }*/
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
