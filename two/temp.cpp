// star pattern

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 7;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < i+1; j++){
            cout << "*";
        }
        cout<<endl;
    }
    return 0;
}