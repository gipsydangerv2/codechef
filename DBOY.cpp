#include <bits/stdc++.h>
using namespace std;
void fillTable(int distance,int dist[],int fuel[],int n){
    int table[n][distance+1];
    for(int i=0;i<n;i++)
        for(int j=0;j<=distance;j++)
            table[i][j] = INT_MAX;
    for(int i=0;i<n;i++)
        table[i][0] = 0;

    for(int j=0;j<n;j++){
        for(int i=1;i<=distance;i++){
            if(j > 0){
                table[j][i] = table[j-1][i];
            }
            if(fuel[j] <= i){
                int value = table[j][i - fuel[j]];
                if(value != INT_MAX && value +  1 < table[j][i])
                    table[j][i] = value + 1;
            }
        }
    }
    int sum = 0;
    /*for(int i=0;i<n;i++){
        for(int j=0;j<=distance;j++){
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }*/
    for(int i=0;i<n;i++){
        sum += table[n-1][2*dist[i]];
    }
     cout << sum << "\n";
}
int main()
{
    int t,n,dis;
    ios::sync_with_stdio(false);

    cin >> t;
    while(t--){
        cin >> n;
        int fuel[n],dist[n];
        int maxdist = 0,sum=0;
        for(int i=0;i<n;i++){
            cin >> dist[i];
            if(maxdist < dist[i])
                maxdist = dist[i];
        }
        for(int j=0;j<n;j++)
            cin >> fuel[j];
        fillTable(2*maxdist,dist,fuel,n);
    }
    return 0;
}
