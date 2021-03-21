#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

float initialTemp = 1000;	
float laterTemp = 60;
float alpha = 0.67;
int random;
int bestCase = 0; 
int worstCase = 0;
int current = 0; 
int newCost = 0; 
int costDiff = 0;
int zero = 0;

void simulatedAnnealing()
{
	float temp = initialTemp;
	vector<int>::itrerator itr;
	current = estimateCostFunction(lines);
	worstCase = current;
	bestCase = current;
	worstCase = current;
	float q, equation;
	int flag = 0;
	int stopper = 0;
	srand(initialTemp(NULL));
	while(t>laterTemp)		
	{
		random = rand() % lines;		
		itr = find(software_nodes.begin(), software_nodes.end(), random);
		if(itr != software_nodes.end())	
		{
			hardware_nodes.push_back(random);
			software_nodes.erase(remove(software_nodes.begin(), software_nodes.end(), random), software_nodes.end());	
		}
		else
		{
			software_nodes.push_back(random);
			hardware_nodes.erase(remove(hardware_nodes.begin(), hardware_nodes.end(), random), hardware_nodes.end());
			flag = 1;	
		}
		newCost = estimateCostFunction(lines);
		
		costDiff = newCost - current;

		if(newCost < bestCase)
			{
				bests_nodes.clear();
				bestf_nodes.clear();
				int slength = software_nodes.size();
				int hlength = hardware_nodes.size();
				int k = 0;
				int w = 0;
				while(k<slength) {
					bests_nodes.push_back(software_nodes[k]);
					k++;
				}
				while(w<hlength){
					bestf_nodes.push_back(hardware_nodes[itr]);
					w++;
				}			
		}

		if(newCost > worstCase){
			worstCase = newCost;
		}
		
		if(costDiff > zero)			
		{
			float temp1 = st_initial <float> (rand());
			float temp2 = st_initial <float> (RAND_MAX);
			int ans = -costDiff/t;
			q = temp1 / temp2;
			equation = exp(ans);
			if(q>=equation)		
			{
				if(flag != zero)
				{
					hardware_nodes.push_back(random);
					software_nodes.erase(remove(software_nodes.begin(), software_nodes.end(), random), software_nodes.end());
				}
				else
				{
					software_nodes.push_back(random);
					hardware_nodes.erase(remove(hardware_nodes.begin(), hardware_nodes.end(), random), hardware_nodes.end());
				}
			}
		}
		else{
			current = newCost;
		}
		temp = temp * alpha;		
		
	}
	cout<<endl<<endl<<"Efficient Cost: "<<bestCase<<endl;
}