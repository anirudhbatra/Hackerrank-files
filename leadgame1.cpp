
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int N;
	cin>>N;
	int S[N],T[N],lead[N];
	char lname[N];
	for(int i=0;i<N;i++)	cin>>S[i]>>T[i];
	for(int i=0;i<N;i++) {
	S[i]+=S[i-1];
	T[i]+=T[i-1];
	if(S[i]>T[i]){
		lead[i]=S[i]-T[i];
		lname[i]='1';
		}
	else{
		lead[i]=T[i]-S[i];
		lname[i]='2';
		}
	}
	int flag=0,max=0;
	for(int i=0;i<N;i++) {
	if(lead[i]>max){
		max=lead[i];
		flag=i;	
		}
	}
	cout<<lname[flag]<<"\t"<<lead[flag];
    return 0;
}
