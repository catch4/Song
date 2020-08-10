#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities){
	int answer =0;
	vector<string> cache;
	for(int i=0;i<cities.size();i++)
	{
		string str = cities[i];
		std::transform(str.begin(),str.end(),str.begin(),::toupper);
		auto iter = find(cache.begin(),cache.end(),str);
		if(iter!=cache.end())
		{
			cache.erase(iter);
			cache.push_back(str);
			answer+=1;
		}
		else{
			if(cache.size()<cacheSize)
				cache.push_back(str);
			else{
				cache.erase(find(cache.begin(),cache.end(),cache[0]));
				cache.push_back(str);
			}
			answer+=5;

		}
		std::cout<<i<<"번 째"<<'\n';
		for(int i=0;i<cache.size();i++)
			std::cout<<cache[i]<<" ";
		std::cout<<'\n';

	}


	return answer;
}

int main(){
	int cacheSize=0;
	vector<string> cities;
	cities.push_back("Jeju");
	cities.push_back("Pangyo");
	cities.push_back("Seoul");
	cities.push_back("NewYork");
	//cities.push_back("newyork");
	cities.push_back("LA");
	//cities.push_back("Jeju");
	//cities.push_back("Pangyo");
	//cities.push_back("Seoul");
	//cities.push_back("Jeju");
	//cities.push_back("Pangyo");
	//cities.push_back("Seoul");
	std::cout<<solution(cacheSize,cities);
}


