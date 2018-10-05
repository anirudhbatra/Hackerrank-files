#include<iostream>
using namespace std;

int main(){
	string str="9+10=19";
	int a[5],j=0;
	for(int i=0;i<str.length();i++){
		if(str[i]=='=' || str[i]=='+')
			continue;
		a[j++]=str[i]-'0';
	}
	
	for(int i=0;i<j;i++)	cout<<a[i];
	return 0;
}
