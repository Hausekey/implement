#include<vector>
#include <iostream>
bool isArrRotated(std::vector<int> &i1, std::vector<int> &i2){
	//use index 0 in i1, then find same index in i2
	//what if array was sorted (repeats welcomed)
	if(i1.size() != i2.size()){
		return false;
	}
	int ind1 = 0;
	int ind2 = 0;
	int temp_counter = 0;
	while(i1[ind1] != i2[ind2] && ind2 < i2.size()){
		ind2++;
	}

	for(int j = 0; j < i1.size(); j++){
		if(i1[ind1++] != i2[ind2++]){
			return false;
		}

		if(ind2 >= i2.size()){
			ind2 = 0;
		}

	}

	return true;
}
int main(){
	int test1_int[] = {1, 2, 3, 4, 5, 6};
	int test2_int[] = {3, 4, 5, 6, 1, 2};
	int test3_int[] = {4, 5, 1, 6, 1, 3};
	std::vector<int> test1(test1_int, test1_int + sizeof(test1_int)/sizeof(int));
	std::vector<int> test2(test2_int, test2_int + sizeof(test2_int)/sizeof(int));
	std::vector<int> test3(test3_int, test3_int + sizeof(test3_int)/sizeof(int));
	std::cout << isArrRotated(test1, test2);
	std::cout << isArrRotated(test1, test3);

}