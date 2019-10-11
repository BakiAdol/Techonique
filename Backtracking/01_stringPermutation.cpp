#include <bits/stdc++.h>
using namespace std;
string s;
int len;
char ans[100];
bool used[100];

void permutation(int position){
    if(position==len){
        for(int i=0; i<len; i++){
            cout << ans[i];
        }
        cout << endl;
        return;
    }
    for(int i=0; i<len; i++){
        if(!used[i]){
            ans[position]=s[i];
            used[i]=1;
            permutation(position+1);
            used[i]=0;
        }
    }
}

int main(){
    cout << "Enter a string : ";
    cin >> s;
    len=s.length();
    permutation(0);
    return 0;
}
