#include <iostream>
#include <string.h>
using namespace std;

void x1(int num, int n, string s);
void x2(int num, int n, string s);
void x3(int num, int n, string s);
void x4(int num, int n, string s);
void x5(int num, int n, string s);
void x6(int num, int n, string s);
void x7(int num, int n, string s);
void x8(int num, int n, string s);
void x9(int num, int n, string s);
void x10(int num, int n, string s);
void x11(int num, int n, string s);
void x12(int num, int n, string s);
void x13(int num, int n, string s);
void x14(int num, int n, string s);
void x15(int num, int n, string s);

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
    if(var=='a'){
        x2(num,n,s);
    }
    else{
        x9(num,n,s);
    }
}

void x2(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
    return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x3(num,n,s);
    }
    else{
        x6(num,n,s);
    }
}

void x3(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x4(num,n,s);
    }
    else{
        x3(num,n,s);
    }
}

void x4(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x5(num,n,s);
    }
    else{
        x3(num,n,s);
    }
}

void x5(int num,int n,string s){
    if(num==n){
        cout<< "Accepted";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x5(num,n,s);
    }
    else{
    	x3(num,n,s);
	}
}

void x6(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x7(num,n,s);
    }
    else{
        x6(num,n,s);
    }
}

void x7(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x7(num,n,s);
    }
    else{
        x8(num,n,s);
    }
}

void x8(int num,int n,string s){
    if(num==n){
        cout<< "Accepted";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x7(num,n,s);
    }
    else{
        x6(num,n,s);
    }
}

void x9(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x10(num,n,s);
    }
    else{
        x13(num,n,s);
    }
}

void x10(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x10(num,n,s);
    }
    else{
        x11(num,n,s);
    }
}

void x11(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x12(num,n,s);
    }
    else{
        x11(num,n,s);
    }
}

void x12(int num,int n,string s){
    if(num==n){
        cout<< "Accepted";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x10(num,n,s);
    }
    else{
        x11(num,n,s);
    }
}

void x13(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x13(num,n,s);
    }
    else{
        x14(num,n,s);
    }
}

void x14(int num,int n,string s){
    if(num==n){
        cout<< "Rejected";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x13(num,n,s);
    }
    else{
        x15(num,n,s);
    }
}

void x15(int num,int n,string s){
    if(num==n){
        cout<< "Accepted";
        return;
    }
    char var=s[num];
    num++;
    if(var=='a'){
        x13(num,n,s);
    }
    else{
        x15(num,n,s);
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

