#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//recursive call
class kitchenTracker{
	//keep track of smallest pours of all rounds
	int min_pours;

	//keep track of the current pours in the round
	//int pours;

	vector<int> cups;
	int V;
	vector<vector<int> > possibleSolutions;
	vector<int> solutionIP;
	public:
	kitchenTracker(vector<int> cups_in, int V_in){
		cups = cups_in;
		V = V_in;
		min_pours = -1;
	}


	int subsetsDifference(vector<int> cups, int built_diff, int goal_diff, int i){
		if(built_diff == goal_diff){
			possibleSolutions.push_back(solutionIP);
			solutionIP.pop_back();
			return 1;
		}

		else if(built_diff < 0){
			solutionIP.pop_back();
			return 0;
		}

		else if(i > cups.size() - 1){
			solutionIP.pop_back();
			return 0;
		}

		else{
			solutionIP.push_back(cups[i]);
			int total = subsetsDifference(cups, built_diff % cups[i], goal_diff, i + 1)
				+ subsetsDifference(cups, built_diff, goal_diff, i + 1);
		}

	}
	bool subsetsDifferenceSetup(vector<int> cups, int diff){
		for(int i = 0; i < cups.size(); i++){
			int starting_diff = cups[i];
			solutionIP.push_back(starting_diff);
			subsetsDifference(cups, starting_diff, diff, i + 1);
		}
		return false;
	}
	void kitchenMeasure(vector<int> cups, int V){
		//V is 0
		int difference = cups[0] - V;
		subsetsDifferenceSetup(cups, difference);
		//so biggest cup holds different
		int total_pours = 0;
		int min_total_pours = -1;
		//int min_pour_ind = 0;
		int offset;
		if(!possibleSolutions.size()){
			cout << "impossible" << '\n';
			return;
		}
		for(int i = 0; i < possibleSolutions.size(); i++){
			int biggest_cup = possibleSolutions[i][0];
			if(biggest_cup != cups[0]){
				total_pours += biggest_cup;
			}
			else{
				total_pours += difference;
			}
			for(int j = 1; j < possibleSolutions[i].size(); j++){
				total_pours += 2 * possibleSolutions[i][j];
			}
			if(total_pours < min_total_pours || min_total_pours == -1){
				min_total_pours = total_pours;
			//	min_pour_ind = i;
			}		
			total_pours = 0;
		}
		if(min_total_pours == -1){
			
		}
		else{
			cout << min_total_pours << '\n';
		}

	}
};


//i = cups.size();

int main(){
	int n; //num of cups
	int cup;
	int V; //desired volume
	int pours = 0;
	vector<int> cups;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> cup;
		cups.push_back(cup);
	}
	cin >> V;
	kitchenTracker k(cups, V);
	k.kitchenMeasure(cups, V);
}