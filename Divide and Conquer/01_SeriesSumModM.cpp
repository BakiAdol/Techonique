#include<bits/stdc++.h>

using namespace std;

int bigMod(int num, int power, int mod)
{
    if(power==0) return 1;
    int v=bigMod(num,power/2,mod);
    v= (v*v)%mod;
    if((power&1)==1) v=(v*num)%mod;
    return v;
}

int seriesSum(int x, int element, int mod)
{
	int ans=0;
	if(element&1) ans=bigMod(x,element,mod);
	if(element>1)
	{
		int ans2=seriesSum(x,element/2,mod);
		ans=(ans+ans2)%mod;
		ans2=(bigMod(x,element/2,mod)*ans2)%mod;
		ans=(ans+ans2)%mod;
	}
	return ans;
}

int main()
{
	
	cout << seriesSum(55,86,100) << endl;
	
	return 0;
}
