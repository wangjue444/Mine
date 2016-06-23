/*
Problem Statement
????
Your task is to find the minimal positive integer x such that: 1. x is an integer multiple of N. 2. The decimal representation of x doesn't contain any forbidden digits. You will be given the forbidden digits as a vector <int> forbiddenDigits.   If there is no solution, you should return the string "IMPOSSIBLE" (quotes for clarity). If there is a solution and its number of digits is strictly less than 9, you should return a string containing the integer x in base 10, with no leading zeros. Otherwise, you should return a string of the form "abc...def(g digits)" (quotes for clarity). In the return value, abc are the first three digits of the smallest valid integer x, def are its last three digits, and g is the number of digits in x (a base-10 integer with no leading zeros).
Definition
????
Class:
MultiplesWithLimit
Method:
minMultiples
Parameters:
int, vector <int>
Returns:
string
Method signature:
string minMultiples(int N, vector <int> forbiddenDigits)
(be sure your method is public)
????

Constraints
-
N will be between 1 and 10000, inclusive.
-
forbiddenDigits will contain between 0 and 10 elements, inclusive.
-
Each element of forbiddenDigits will be between 0 and 9, inclusive.
-
The elements of forbiddenDigits will be pairwise distinct.
Examples
0)

????
8
{2,3,4,5,6,7,8,9}
Returns: "1000"
The smallest positive multiple of 8 that only contains digits 0 and 1 is 1000.
1)

????
9
{1,3,4,5,6,7,8,9}
Returns: "222...222(9 digits)"

2)

????
524
{5,2,4}
Returns: "3668"

3)

????
10000
{0}
Returns: "IMPOSSIBLE"

4)

????
1
{0,1,2,3,4,5,6,7,8,9}
Returns: "IMPOSSIBLE"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MultiplesWithLimit
{
public:
	string minMultiples(int N,vector<int> forbiddenDigits);
};

string MultiplesWithLimit::minMultiples(int N,vector<int> forbiddenDigits)
{
	
	return "a";
}

int main()
{
}