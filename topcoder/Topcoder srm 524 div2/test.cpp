/*
Problem Statement
????
You want to ship N cubes abroad. The size of each cube is 1 x 1 x 1. You can only ship the cubes by filling them into a single cuboid box. The cost of shipping a cuboid box with dimensions a x b x c is equal to (a+b+c).  You can't leave any empty space in the box, because the cubes would shift and get damaged during the transfer.  You are given an int N. Return the minimal cost of shipping N cubes.
Definition
????
Class:
ShippingCubes
Method:
minimalCost
Parameters:
int
Returns:
int
Method signature:
int minimalCost(int N)
(be sure your method is public)
????

Constraints
-
N will be between 1 and 200, inclusive.
Examples
0)

????
1
Returns: 3
The only way is to use a box with dimensions 1 x 1 x 1.
1)

????
6
Returns: 6
This time one optimal solution is to send a box with dimensions 1 x 2 x 3. The cost of sending this box is 1+2+3 = 6. Any other option is at least as expensive as this one. For example, sending a box with dimensions 6 x 1 x 1 has the cost 6+1+1 = 8.
2)

????
7
Returns: 9

3)

????
200
Returns: 18

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/


#include <iostream>

using namespace std;
class ShippingCubes
{
public:
	int	minimalCost(int N);
};

int ShippingCubes::minimalCost(int N)
{
	int cost=0;
	bool isfirst=1;
	for(int x=1;x<=N;x++)
	{
		for(int y=1;y<=N;y++)
		{
			for(int z=1;z<=N;z++)
			{
				if(isfirst==1&&x*y*z==N)
				{
					cost=x+y+z;
					isfirst=0;
				}
				if(x*y*z==N&&(x+y+z)<cost)
					cost=x+y+z;
				
			}
		}
	}
	return cost;
}




int main()
{
	ShippingCubes a;
	cout<<a.minimalCost(1);
}