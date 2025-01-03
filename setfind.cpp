#include<bits/stdc++.h>
#include<set>
using namespace std;
/*int main(){
	set<int> s;
	for(int i=0;i<10;i++){
		s.insert(i);	
	}
	if(s.find(11)!=s.end()){
		cout<<"Found!\n";
	}else{
		cout<<"Not found!\n";
	}
	return 0;
}*/
//ham tim kiem phan tu trong set find
int main(){
set<int> s;
for(int i=0;i<10;i++){
	s.insert(i);
}
//Duyet qua cac phan tu cua mang dung vecto 
for(int x : s){
	cout<<x<<" ";
}
cout<<endl;
s.erase(5);
for(int x:s){
	cout<<x<<" ";
}
return 0;
}
//ham xoa erase 
