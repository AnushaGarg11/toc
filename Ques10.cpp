//Q7
#include <iostream>
#include <stack>
using namespace std;

int state1(string w, int i, stack<string> &stk);
int state2(string w, int i, stack<string> &stk);
int state3(string w, int i, stack<string> &stk);
int state4(string w, int i, stack<string> &stk);
int state5(string w, int i, stack<string> &stk);

int main() {
    string w;
    stack<string> stk;
    stk.push("0"); 
    cout << "Enter string: ";
    cin >> w;
    state1(w, 0, stk); 
    return 0;
}

int state1(string w, int i, stack<string> &stk) {
    cout << "\nState 1\n";
    if (i == w.length()+1) {
        cout << "\nString is rejected\n";
        return 0;
    } else {
        cout<<i;
        if (w[i] == 'a' && stk.top() == "0") {
            stk.push("a");
            return state2(w, i + 1, stk);
        }
        if (w[i] == 'b') {
            return state5(w, i + 1, stk);
        }
    }
    return 0;
}

int state2(string w, int i, stack<string> &stk) {
    cout << "\nState 2\n";
    if (i == w.length()+1) {
        cout << "\nString is rejected\n";
        return 0;
    } else {
        cout<<i;
        if (w[i] == 'a' && stk.top() == "a") {
            stk.push("a");
            return state2(w, i + 1, stk);
        }
        
        if (w[i] == 'b' && stk.top() == "a") {
            stk.pop();
            return state3(w, i + 1, stk);
        }
        
        if(stk.top()!="a"){
            return state5(w, i + 1, stk);
        }
        
    }
    return 0;
}

int state3(string w, int i, stack<string> &stk) {
    cout << "\nState 3\n";
    if (i == w.length()+1) {
        cout << "\nString is rejected\n";
        return 0;
    } else {
        cout<<i;
        if (w[i] == 'b' && stk.top() == "a") {
            stk.pop();
            return state3(w, i + 1, stk);
        }
        
        if (i ==  w.length() && stk.top() == "0") {
            stk.pop();
            return state4(w, i+1, stk);
        }else{
            return state5(w, i + 1, stk);
        }
        
    }
    return 0;
}

int state4(string w, int i, stack<string> &stk) {
    cout << "\nState 4\n";
    cout<<i;
    if (i == w.length()+1) {
        cout << "\nString is accepted\n";
        return 1;
    }else{
        return state5(w, i + 1, stk);
    }
        
    return 0;
}

int state5(string w, int i, stack<string> &stk) {
    cout << "\nState 5\n";
    if (i == w.length()+1) {
        cout << "\nString is rejected\n";
        return 0;
    }else{
        return state5(w, i + 1, stk);
    }
        
    return 0;
}

/*
//Q8
#include <iostream>
#include <stack>
using namespace std;


int state1(string w, int i, stack<char> &stk);
int state2(string w, int i, stack<char> &stk);
int state3(string w, int i, stack<char> &stk);
int state4(string w, int i, stack<char> &stk);
int state5(string w, int i, stack<char> &stk);

int main() {
    string w;
    stack<char> stk;
    stk.push('0'); 
    cout << "Enter string: ";
    cin >> w;
    state1(w, 0, stk); 
    return 0;
}

int state1(string w, int i, stack<char> &stk) {
    cout << "\nState 1\n";
    if (i == w.length()+1) {
        cout << "\nString is rejected\n";
        return 0;
    } else {
        if ((w[i] == 'a' || w[i] == 'b') && stk.top() == '0') {
            stk.push(w[i]);
            return state2(w, i + 1, stk);
        }else{
            return state5(w, i + 1, stk);
        }
        }

    return 0;
}

int state2(string w, int i, stack<char> &stk) {
    cout << "\nState 2\n";
    if (i == w.length()+1) {
        cout << "\nString is rejected\n";
        return 0;
    } else {
        if (w[i] == 'a' || w[i] == 'b') {
            stk.push(w[i]);
            return state2(w, i + 1, stk);
        }
        
         if ((w[i] != 'a' && w[i] != 'b')) {
            return state3(w, i + 1, stk);
        }
        
    }
    return 0;
}

int state3(string w, int i, stack<char> &stk) {
    cout << "\nState 3\n";
    if (i == w.length()+1) {
        cout << "\nString is rejected\n";
        return 0;
    } else {
       
        if (w[i] == 'a' || w[i] == 'b') {
            if(w[i]==stk.top()){
                stk.pop();
                return state3(w, i+1, stk);
            }else{
                return state5(w, i+1, stk);
            }
            }
            
            if(i == w.length() && stk.top()=='0'){
                return state4(w, i+1, stk);
            }else{
                return state5(w, i+1, stk);
            }
        }
    return 0;
}

int state4(string w, int i, stack<char> &stk) {
    cout << "\nState 4\n";
    
    if (i == w.length()+1 && stk.top()=='0') {
        cout << "\nString is accepted\n";
        return 1;
    }else{
        return state5(w, i + 1, stk);
    }
        
    return 0;
}

int state5(string w, int i, stack<char> &stk) {
    cout << "\nState 5\n";
   
    if (i == w.length()+1) {
        cout << "\nString is rejected\n";
        return 0;
    }else{
        return state5(w, i + 1, stk);
    }
        
    return 0;
}



//Q9
#include <iostream>
#include <vector>

using namespace std;

int state1(string w, int i, vector<char> &stk);
int state2(string w, int i, vector<char> &stk);
int state3(string w, int i, vector<char> &stk);
int state4(string w, int i, vector<char> &stk);
int state5(string w, int i, vector<char> &stk);
int state6(string w, int i, vector<char> &stk);

int main() {
    string w;
    vector<char> stk;
    cout << "Enter string: ";
    cin >> w;
    for(int i=0;i<w.length();i++){
        stk.push_back(w[i]);
    }
    state1(w, 0, stk); 
    return 0;
}                                  //i==head

int state1(string w, int i, vector<char> &stk) {
    cout << "\nState 1\n";
    
        if (stk[i] == 'a') {
            stk[i] = 'x';
            return state2(w, i + 1, stk);
        }
        
        if(stk[i] == 'x'){
            return state1(w, i + 1, stk);
        }
        
         if(stk[i] != 'x' && stk[i] != 'a'){
            return state6(w, i + 1, stk);
        }
        
        int flag=0;
    for(int i=0;i<w.length();i++) {
        if(stk[i]!='a' && stk[i]!='b' && stk[i]!='c'  ){
            flag=0;
        }else{
            flag=1;
            break;   
        }  
        }
        if(flag==0){
            cout<<"accepted";
        }else{
            cout<<"rejected";
        }
    return 0;
}

int state2(string w, int i, vector<char> &stk) {
    cout << "\nState 2\n";
    
        if (stk[i] == 'a' || stk[i] == 'y') {
            return state2(w, i + 1, stk);
        }
         if (stk[i] == 'b') {
             stk[i] = 'y';
            return state3(w, i + 1, stk);
        }
        
         if(stk[i] != 'b' && stk[i] != 'y' && stk[i] != 'a' ){
            return state6(w, i + 1, stk);
        }
         
    return 0;
}

int state3(string w, int i, vector<char> &stk) {
    cout << "\nState 3\n";
       
        if (stk[i] == 'b' || stk[i] == 'z') {
            return state3(w, i + 1, stk);
        }
        
         if (stk[i] == 'c') {
             stk[i] = 'z';
            return state4(w, i + 1, stk);
        }
        
        if(stk[i] != 'b' && stk[i] != 'z' && stk[i] != 'c' ){
            return state6(w, i + 1, stk);
        }
    return 0;
}

int state4(string w, int i, vector<char> &stk) {
    cout << "\nState 4\n";
    
    
        if (stk[i] == 'c' ) {
            return state5(w,i+1, stk);
        }else{
             int flag=0;
    for(int i=0;i<w.length();i++) {
        if(stk[i]!='a' && stk[i]!='b' && stk[i]!='c'  ){
            flag=0;
        }else{
            flag=1;
            break;
            
        }  
        }
        if(flag==0){
            cout<<"accepted";
        }else{
            cout<<"rejected";
        }
        }
     return i;
}

int state5(string w, int i, vector<char> &stk) {
    cout << "\nState 5\n";
   
     if (stk[i] == 'c' ) {
            return state5(w,i+1, stk);
        }
        
         if(i==w.length()){
            return state1(w,0, stk);
        }
        
        if(stk[i] != 'c' ){
            return state6(w, i + 1, stk);
        } 
    return 0;
}

int state6(string w, int i, vector<char> &stk) {
    cout << "\nState 6\n";
   
     cout<<"\nrejected";  
        
    return 0;
}

//Q10
#include <iostream>
#include <vector>

using namespace std;



int state1(string w, int i, vector<char> &stk);
int state2(string w, int i, vector<char> &stk);


int main() {
    string w;
    vector<char> stk;
    cout << "Enter string: ";
    cin >> w;
    for(int i=0;i<w.length();i++){
        stk.push_back(w[i]);
    }
 
    state1(w, w.length()-1, stk); 
    return 0;
}                                  //i==head

int state1(string w, int i, vector<char> &stk) {
   
    
      if(i==-1){
           return state2(w,0, stk);
       }
    
        if (stk[i] == '0' && i==w.length()-1) {
            stk[i] = '1';
            return state2(w, 0, stk);
        }
        
        if(stk[i] == '1' && i==0){
            stk[i] = '0';
            stk.insert(stk.begin(),'1');
            return state2(w,0, stk);
        }
        
        if(stk[i] == '1'){
            stk[i] = '0';
            return state1(w, i-1, stk);
        }
        
        if(stk[i] == '0'){
            stk[i] = '1';
            return state2(w, i-1, stk);
        }
      
    return 0;
}

int state2(string w, int i, vector<char> &stk) {
    cout<<"\n";
    for(int i=0;i<w.length()+1;i++){
        cout<<stk[i];
    }
    
    return 0;
}


*/
