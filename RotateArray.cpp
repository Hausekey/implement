#include <vector>

void rotateArray(std::vector<int> &i1, int shift){
	//check if shift length is bigger than array length
	for(int i = 0; i < i1.size(); i++){
		int temp = i1[i];
		i1[i] = i1[i+shift];
		i1[i+shift] = i[i];
	}
}
int main(){
	int arr[] = {2, 3, 4, 5, 6};
	std::vector<int> i1(arr, sizeof(arr)/sizeof(int));

}