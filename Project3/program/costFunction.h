#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int codeLines;
struct Node
{
	int NodeId;
	vector<int> edges;
	int softwareInfo;
	int hardwareInfo;	
};

Node *best;
Node *current;

void readInput()
{
	ifstream filter;
	string codeLines;
	filter.open("input.txt", ios::in);
	filter.seekg(0);
	getline(filter, line);
	string::type size_t;	
	lines = stoi(line, &size_t);
	Curr_Solution = new Node[lines];
	int itr = 0;
	while(itr < lines) {
		getline(filter, line);
		istringstream iss(line);
		String wordDict;
		current[itr].softwareInfo = stoi(word, &size_t);
		iss>>wordDict;
		current[itr].hardwareInfo = stoi(word, &size_t);
		iss>>wordDict;
		while(iss>>wordDict)
		{
			int edges;
			edges = stoi(wordDict);
			current[itr].edges.push_back(edges);
		}
		itr++;
	}
	filter.close();
}

void printNodes(int lines)
{
	int itr = 0;
	while(itr<lines){
		cout << " Node Number:" << current[i].NodeId <<endl;
		cout << " Software Info:" << current[i].softwareInfo<<endl;
		cout << " Hwardware info:" << current[i].hardwareInfo<<endl;
		cout << " NodeEdges:";
		int k=0;
		while(k<current[itr].edges.size()){
			cout<<" ("<<current[i].NodeId<<", "<<current[i].edges[k]<<")";
			k++;
		}
	}
}

int estimateCostFunction(int lines)
{
	int mac = 8;
	int mac_lim=0;
	float q1 = 1;
	float q2 = 0.01;
	float q3 = 1;
	int flash = 256;
	int cflash = 1;
	int flashLim = 0;
  
    int k = 0;
    int j = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    float tMac = 0;
    float tFlash = 0;
    long costFunction = 0;
    int hardware_sum = 0; 
    int software_sum = 0;
    int nr = 0;
    while(nr < lines) {
    	if (current[nr].mac != 0) {
            mac++;
        }
    	nr++;
    }

    int swlooplimit = software_nodes.size();
	int hwlooplimit = hardware_nodes.size();
	int k = 0;

    while(k<mac_lim){
    	tMac = tMac + mac / ci_mac;
    	k++;
   	}

	int j = 0;
    while(j<lines){
    	total_flash = total_flash * current[j].ciFlash;
    	k++;
   	}

   	int l = 0;
    while(l<hwlooplimit){
    	hardware_sum += current[hardware_nodes[l]].hardware_sum;
    	l++;
   	}
    
    if (int hwlooplimit = hardware_nodes.size(); != 0)		
    {		
        hardware_sum = hardware_sum / int hwlooplimit = hardware_nodes.size();;		
    }
    
    for (m = 0; m < swlooplimit; m++) {
        software_sum += current[software_nodes[m]].software_sum;
        
    } 
    
    if (swlooplimit != 0)		
    {		
        software_sum /= swlooplimit;		
    }
    
    costFunction = (Q2 * flash) + (Q1 * mac_lim) - (Q3 * (hardware_sum - software_sum));
    return costFunction;
}
