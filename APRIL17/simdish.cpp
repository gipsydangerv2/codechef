#include<cstdio>
#include<iostream>
#include<set>
using namespace std;

int main(){
	int size;
	cin >> size;
	while(size--){
		set<string> ingredients;
		string input;
		for(int i=0;i<4;i++){
			cin >> input;
			ingredients.insert(input);
		}
		for(int i=0;i<4;i++){
			cin >>input;
			ingredients.insert(input);
		}
		if(ingredients.size()>6)
			cout<<"dissimilar\n";
		else
			cout <<"similar\n";
	}
	return 0;
};
