#include <iostream>
#include <vector>

std::vector<int> findIntersect(const std::vector<int> &s1, const std::vector<int> &s2){
	int i1 = 0;
	int i2 = 0;
	int m = s1.size();
	int n = s2.size();
	std::vector<int> intersection;

	while(i1 < m && i2 < n){
		if(s1[i1] < s2[i2]){
			i1++;
		}
		else if(s1[i1] > s2[i2]){
			i2++;
		}
		else{
			intersection.push_back(s1[i1]);
			i1++;
			i2++;
		}
	}
	return intersection;

}
int main(){
	int set1_ints[] = {1, 2, 3, 4, 5, 6};
	std::vector<int> set1(set1_ints, set1_ints + sizeof(set1_ints)/sizeof(int));

	int set2_ints[] = {3, 5, 6};
	std::vector<int> set2(set2_ints, set2_ints + sizeof(set2_ints)/sizeof(int));
	std::vector<int> result = findIntersect(set1, set2);

}