#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverseUsingRecursive(string str);
string reverseUsingLoop(string s);
string reverseUsingSplit(string s);

int main() {
	cout<<"Enter a String"<<endl;
	string str;
	cin>>str;
	cout<<"Reverse using loop : "<< reverseUsingLoop(str)<<endl;
	cout<<"Reverse using recursive : "<< reverseUsingRecursive(str)<<endl;
	cout<<"Reverse using split : "<< reverseUsingSplit(str)<<endl;
}

string reverseUsingLoop(string s) {
	//Time Complexity Log(n)
	//Space Complexity Log(n)
	string str = "";
	int n =     s.length();
	for(int i = 0; i<n; i++) {
		str += s[n-1-i];
	}
	return str;
}

string reverseUsingRecursive(string str){
	//Time Complexity Log(n)
	//Space Complexity Log(n)
	int n = str.length();
	if(n==0){
		return "";
	}
	return (str.substr(n-1)+reverseUsingRecursive(str.substr(0,n-1)));
}

string reverseUsingSplit(string str){
	if(str.empty()){
		return "";
	}
	int n = str.length();
	int l=0,r=n-1;
	while(l<r)	{
		char c = str[l];
		str[l]= str[r];
		str[r] = c;
		l++;
		r--;
	}
	return str;
}
