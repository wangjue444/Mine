/*
Problem Statement
????
You found n Magic Diamonds in the mountain. You are now thinking about transfering them to your home. The only way you can transfer Magic Diamonds is to use Transfer Magic one or more times.  The Magic Diamonds are very strange. For any positive integer x you can use Transfer Magic to transfer x Magic Diamonds at once. However, if x is a prime number, the Magic Diamonds will disappear instead of getting transferred. You are not allowed to lose any of the Magic Diamonds, therefore you may never use Transfer Magic on a prime number of Magic Diamonds. Your task is to transfer all Magic Diamonds using Transfer Magic as few times as possible.  You are given a long long n. Return the minimal number of Transfer Magic usages you need to transfer n Magic Diamonds.
Definition
????
Class:
MagicDiamonds
Method:
minimalTransfer
Parameters:
long long
Returns:
long long
Method signature:
long long minimalTransfer(long long n)
(be sure your method is public)
????

Notes
-
A positive integer x is a prime number if and only if it has exactly 2 divisors: 1 and x. Note that 1 is not a prime number.
-
Your task can always be accomplished. For example, you can use Transfer Magic n times and transfer 1 Magic Diamond each time.
Constraints
-
n will be between 1 and 1,000,000,000,000 (10^12), inclusive.
Examples
0)

????
2
Returns: 2
We have to use Transfer Magic twice, each time we transfer 1 Magic Diamond.
1)

????
4294967297
Returns: 1
We just need to use Transfer Magic once, because 4294967297 is not a prime. We have 4294967297 = 641 * 6700417.
2)

????
2147483647
Returns: 2
This time n is a prime, so we have to use Transfer Magic at least twice. We have 2147483647 = 2147400000 + 83647 (83647 = 233 * 359, which is not a prime), thus the answer is 2.
3)

????
1
Returns: 1

 
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/


#include <iostream>
#include <math.h>
using namespace std;

long num;
class MagicDiamonds
{
	
public:
	
	long  minimalTransfer(long  n);
	bool isPrime(long n);
	void Divide(long n,long parts);
};



 long MagicDiamonds::minimalTransfer( long n)
{

	 if(isPrime(n)==false)
		 return 1;
	 
	 for(int i=1;i<n;i++)
	{
		if((!isPrime(i))&&(!isPrime(n-i)))
		{
			return 2;
		}
	}

	return 3;
}

bool MagicDiamonds::isPrime(long n)
 {
	printf("prime");
	if(n==1)
		return false;
	if(n==2)
		return true;
	 for(long i=2;i<sqrt(n);i++)
	 {
		// printf("!");
		
			 if(n%i==0)
			 {
				 return false;
			 }

		 

	 }
	 return true;
 }
void MagicDiamonds::Divide(long n,long parts)
{
	for(int i=1;i<n;i++)
	{
		if((!isPrime(i))&&(!isPrime(n-i)))
		{
			return ;
		}
	}

}



int main()
{

	printf("final");
	MagicDiamonds a;
	cout<<a.minimalTransfer(2147483647);
}

/*
#include <iostream>
#include <cstdio>
using namespace std;

const int M=1000005;
long long prime[M]
*/


