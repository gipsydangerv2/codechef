#include <iostream>
#include <vector>
using namespace std;
char str[100001];
int main()
{
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int len = str.length();
        vector<int> dist_time;
        vector<int> stop_time;
        int ones_count = 0;
        for(int i=len-1;i>=0;i--){
            if(str.at(i)=='1'){
                // length of stop vector will be same as
                // ones_count value
                int len2 = stop_time.size();
                dist_time.push_back(len-1-ones_count-i);
                if(i==len-1)
                    stop_time.push_back(0);
                else if(i+1 < len && str.at(i+1)=='1'){
                    stop_time.push_back(stop_time[ones_count-1]);
                }
                else if(i+1 < len && str.at(i+1)=='0' && stop_time.size()==0){
                    stop_time.push_back(1);
                }
                else if(i+1 < len && str.at(i+1)=='0'){
                    stop_time.push_back(stop_time[ones_count-1]+1);
                }
                ones_count++;

            }
        }
        if(stop_time.size()==0)
            cout << 0 << "\n";
        else{
            long long int sum = 0;
            for(int i=0;i<ones_count;i++){
                sum = sum + dist_time[i] + stop_time[i];
            }
            cout <<sum <<"\n";
        }
    }
    return 0;
};


