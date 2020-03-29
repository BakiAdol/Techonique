#include <bits/stdc++.h>
using namespace std;

void parentheses(int open, int close, string s)
{
	if(open==close and open==0)
	{
		cout << "\"" << s << "\"" << endl;
		return;
	}
	if(open>0) parentheses(open-1,close,s+"(");
	if(close>open) parentheses(open,close-1,s+")");
}


int main(){
    
    int n;
    n=3;
    cout << "Diffrent way to make " << n << " balanced parentheses\n";
    parentheses(n,n,"");
    
    return 0;
}
