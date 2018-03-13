#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>
#include<string>

int rec_topdown(const std::vector<int> &v_in, int total, int i, 
	std::unordered_map<std::string, int> &mem){
	std::stringstream ss;
	ss << total << ':' << i;
	std::string key = ss.str();
	if(mem.find(key) != mem.end()){
		return mem[key];
	}
	else if(total == 0){
		return 1;
	}
	else if(total < 0){
		return 0;
	}
	else if(i < 0){
		return 0;
	}
	else if(total < v_in[i]){
		return rec_topdown(v_in, total, i - 1, mem);
	}
	else if(total >= v_in[i]){
		return rec_topdown(v_in, total - v_in[i], i - 1, mem)
			+ rec_topdown(v_in, total, i - 1, mem);
	}
	//int sums[1] = v_in[0];

}

int rec_bottomup(const std::vector<int> &v_in, int total){
	// int sums[v_in.size()^2];
	// sums[0] = 0;
	std::unordered_map<std::string, int> mem;
	std::stringstream ss;
	int i = v_in.size();
	int sum = 0;
	ss << 0 << ':' << 0;
	std::string key = ss.str();
	//clear the stringstream
	mem[key] = 1;
	ss.str("");
	//can't think of anything other than using binary
	//just gonna binary it
	for(int i = 0; i < v_in.size() - 1; i++){
		for(int j = 0; j < v_in.size() - 1; j++){
			int ind = v_in.size() * i + j;
			while(ind/2 != 0){
				if(ind % 2 == 1){
					sum += 1;
				}
			}
			ss << v_in[i] - v_in[i] << ':' << i - 1;
			key = ss.str();
			ss.str("");
			int sum;
			int count;
			if(v_in[i] == sum){
			}
 
			int count = mem[key];
			ss << v_in[i] << ':' << i;
			key = ss.str();
			ss.str("");

		}
		// for(int j = 0; j < 2^i; j++){
		// 	sum += v_in[i];
		// 	//make a stringstream
		// 	std::stringstream ss;
		// 	ss << sum << ':' << i;
		// 	std::string key = ss.str();
		// 	std::stringstream ss2;
		// 	ss << sum << ':' << i;
		// 	std::string prev_key = ss.str();

		// 	//clear the stringstream
		// 	if(sum == v_in[i]){
		// 		mem[key] = mem[prev_key] + 1;
		// 	}
		// 	else{
		// 		mem[key] = mem[prev_key];
		// 	}

		// }
		// std::stringstream ss;
		// if(sum == total){
			
		// 	ss << total - vin[i] << ':' << i;
		// 	std::string prev_key = ss.str();
		// 	mem[key] = 1 + mem[prev_key];
		// }
		// else{

		// }
	//	sums[i] = v_in[i-1] + sums[i-1];
	}
}
int main(){
	int n;
	int x;
	std::vector<int> inp;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> x;
		inp.push_back(x);
	}

}