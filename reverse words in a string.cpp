#include<bits/stdc++.h>
using namespace std;

int main(){
	cout<<"Enter input: "<<endl;
	string str;
	vector<string> v1;
	while(cin>>str){
		v1.push_back(str);
	}
	
	for(vector<string>::iterator it=v1.begin(); it!=v1.end(); it++){
		cout<<*it;
	}
	return 0;
}
