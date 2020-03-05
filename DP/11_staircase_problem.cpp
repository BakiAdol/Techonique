#include <bits/stdc++.h>

using namespace std;

#define		mod		1000000007

/**
*	Problem 01:
*	You are climbing a stairecse. It's take n steps to reach to the top.
*	Each time you can either climb 1 or 2 steps. In how many distinct ways you can climb to the top.
**/
int dp[700];

int staircase(int steps)
{
	if(steps==0) return 1;
	if(steps<0) return 0;
	if(dp[steps]) return dp[steps];
	return dp[steps]=(staircase(steps-1)+staircase(steps-2))%mod;
}

/**
*	Top down dp approach.
*	n=5
*	You clibm 1 or 2 steps. So think about how you reach 5, maybe you climb 1 steps from 4 or 2 step from 3.
*	Again how you rech 4 climb 1 steps from 3 or 2 step from 2.
*	So,    	    									f(5)
*							f(4)--------------------------------------------f(3)
*				f(3)--------------------f(2)------------------f(2)------------------------f(1)
*    	 f(2)-----------f(1)-----f(1)------------f(0)----f(1)-----------f(0)-----f(0)--------------f(-1)
*	f(1)-----f(0)---f(0)--f(-1)--f(0)---f(-1)         f(0)---f(-1)                     
*f(0)---f(-1)
* 1-----------1------1------0-----1--------0------1----1--------0--------1--------1------------------0
*	Diffrent 8 ways.
*	all f(-1) is invalid combination, and f(0) means you finally reach n steps
**/

/**
*	Problem 02:
*	What about if you are given a constraint in this same problem. Constraint like you jump only k times.
*	For example n=5, k=4;
*	There are five steps and you can jump either 1 or 2 and your number of jumps not greater than k.
*
*	Think abour in step 5, you get step 5 at most 4 jump. So Maybe you reach 5 step from 4 step make 1 jump
*	or reach 5 from 3 step make 1 jump. So in 4 step you have 4 jump remain and 3 step you have 4 jump remain. 
*
*	       	    									f(5)(4)
*							f(4)(3)------------------------------------------f(3)(3)
*				f(3)(2)--------------------f(2)(2)------------------f(2)(2)--------------------f(1)(2)
*    	f(2)(1)-----------f(1)(1)--------f(1)(1)-----f(0)(1)---f(1)(1)-------f(0)(1)----f(0)(1)------------f(-1)(1)
* f(1)(0)---f(0)(0)--f(0)(0)-f(-1)(0)--f(0)(0)-f(-1)(0)     f(0)(0)---f(-1)(0)                     
* 0-----------1---------1------0----------1------0------1------1---------0-------1---------1------------------0
*	Diffrent 7 ways.
*	Here all f(3) is not equal or all f(2) is not equal like previous on, because of it's depends on moves
**/

int memo[500][500];

int f(int steps, int remainJumps)
{
	if(steps==0) return 1;
	if(steps<0) return 0;
	if(remainJumps==0) return 0;
	if(memo[steps][remainJumps]) return memo[steps][remainJumps];
	return memo[steps][remainJumps]=(f(steps-1,remainJumps-1)+f(steps-2,remainJumps-1))%mod;
}

int main()
{
    printf("%d\n",staircase(5)); // diffrent ways to reach 5 steps
    printf("%d\n",f(5,4)); // diffrent ways to reach 5 steps only 4 jumps
    
    return 0;
}


