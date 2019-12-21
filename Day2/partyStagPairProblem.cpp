#include<iostream>
using namespace std;


/*

This is N party problem i.e. in a party there may be N people the condition is that either they can go alone or by making a couple 
the problem is to find the total number of possible combination so that person is stag or couple.

*/


int partyStagPairProblem(int num_of_people)
{
	
	if(num_of_people==1||num_of_people==2)
	{
		return num_of_people;
	}
	
	int stag_people = partyStagPairProblem(num_of_people-1);
	int pair_people = partyStagPairProblem(num_of_people-2);
	
	return stag_people+pair_people*(num_of_people-1);
	
	
}


int main()
{
	
	cout<<partyStagPairProblem(3)<<endl;//4 output
	cout<<partyStagPairProblem(4)<<endl;//10 output
	

	
	return 0;
}
