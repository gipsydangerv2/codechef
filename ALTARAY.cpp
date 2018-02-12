
#include <bits/stdc++.h>
using namespace std;
int las[100001];
int main()
{
    int t,n;
    int arr[100001];
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> arr[i];
        las[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            if((arr[i] > 0 && arr[i+1] < 0) || (arr[i] < 0 && arr[i+1] > 0))
                las[i] = las[i+1] + 1;
            else
                las[i] = 1;

        }
        for(int i=0;i<n;i++)
            cout << las[i] << " ";
        cout << "\n";
    }
    return 0;
}
