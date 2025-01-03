//#include<bits/stdc++.h>
#include<iostream>
#include<utility>
#include<set>
#include<map>
//dung duoc voi ca so am , duong
using namespace std;
int main(){
	//day la vi du ve 1 chuoi roi 
	//2
	//java
	//python....
	int n;cin>>n;
	set<string>s;
	cin.ignore();
	for(int i=0;i<n;i++){
		string str;
		getline(cin,str);
		s.insert(str);
	}
	//in cac cai tu do ra
	for(string x : s){
	cout<<x<<endl;
	}
	//set luon sap xep theo thu tu tu dien tang dan or ham tuy chon
	cout<<s.size()<<endl;
}
