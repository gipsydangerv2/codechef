#include<iostream>
#include<set>
using namespace std;
 
int main(){
	int t,n,k;
	cin >> t;
	while(t--){
		set<int> items;
		int num,input;
		cin >> n >> k;
		int flag = 0;
		for(int i=0;i<n;i++){
			cin >> num;
			for(int j=0;j<num;j++){
                cin >> input;
                items.insert(input);
			}
			if(flag == 0 && items.size() == k && i!=n-1){
                flag = 1;
			}
		}
		if(items.size() != k)
            cout <<"sad\n";
        else if(flag==1)
            cout <<"some\n";
        else
            cout <<"all\n";
	}
	return 0;
};
