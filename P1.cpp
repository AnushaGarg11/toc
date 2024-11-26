#include <iostream>
#include <string.h>
using namespace std;

void x1(int num, int n, string s);
void x2(int num, int n, string s);
void x3(int num, int n, string s);
void x4(int num, int n, string s);

void func(string s,int n){
    int num=0;
    x1(num,n,s);
}
void x1(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
        return;
    }
    char var=s[num];
    num++;
    if(var=='0'){
        x1(num,n,s);
    }
    else{
        x2(num,n,s);
    }
}

void x2(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
    return;
    }
    char var=s[num];
    num++;
    if(var=='0'){
        x1(num,n,s);
    }
    else{
        x3(num,n,s);
    }
}

void x3(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
        return;
    }
    char var=s[num];
    num++;
    if(var=='0'){
        x1(num,n,s);
    }
    else{
        x4(num,n,s);
    }
}

void x4(int num,int n,string s){
    if(num==n){
        cout<< "Accepted";
        return;
    }
    char var=s[num];
    num++;
    if(var=='1'){
        x4(num,n,s);
    }
    else{
        x4(num,n,s);
    }
}

int main(){
    int m;
    cout<<"Enter number of test cases: ";
    cin>>m;
    for(int i=0;i<m;i++){
    	string s;
    	cout<<"Enter input string = ";
    	cin>>s;
    	int n=s.length();
		func(s,n);
		cout<<endl;
	}
    
}


