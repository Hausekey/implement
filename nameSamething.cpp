#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

bool nameSamething(string s1, string s2){
	if(s1.length() != s2.length()){
		return false;
	}
	//error handling
	else if(s1.empty() || s1.length() == 1){
		return true;
	}

	unordered_map<char, char> charMap;
	for(int i = 0; i < s1.length(); i++){
		//so if it's in the map
		if(charMap.find(s1[i]) != charMap.end()){
			if(s2[i] != charMap[s1[i]]){
				return false;
			}
		}
		else{
			charMap[s1[i]] = s2[i];
		}
	}
	return true;
}

int main(){
	//cout << nameSamething("", ""); << '\n';
	cout << nameSamething("pop", "bob");
	return 0;
}