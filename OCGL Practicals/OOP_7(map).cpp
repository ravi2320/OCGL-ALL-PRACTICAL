#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int n, p;
	string state;
	typedef map<string, int> mapType;
	mapType pMap;
	
	cout<<"\nEnter the no of state do you want : ";
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cout<<"\nEnter the state name : ";
		cin>>state;
		
		cout<<"\nEnter the "<<state<<"'s Population : ";
		cin>>p;
		
		pMap.insert(pair<string, int>(state, p));
	}
	
	mapType::iterator iter;
	cout<<"\nAll State Data : ";
	cout<<"\n\nState\tPopulation";
	for(iter=pMap.begin(); iter!=pMap.end(); iter++)
	{
		cout<<"\n"<<iter->first<<"\t"<<iter->second;
	}
	
	cout<<"\nEnter the state to find the population : "<<endl;
	cin>>state;
	
	iter = pMap.find(state);
	if(iter!= pMap.end())
		cout<<state<<"'s population is : "<<iter->second<<" millions\n";
	else
		cout<<state<<" data not found in map";
	return 0;
}
