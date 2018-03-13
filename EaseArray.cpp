#include <iostream>
#include <queue>
using namespace std;

void easeArray(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        cout << "hi: " << arr[i] << '\n';
        int next = i + 1;
        if(arr[i] != 0 && arr[next] == arr[i]){
            arr[i] *= 2;
            cout << "arr[i]: " << arr[i] << '\n';
        }
    }
    int pos = 0;
    queue<int> tracker;
    for(int i = 0; i < size; i++){
        if(arr[i] == 0){
            tracker.push(i);
        }
        else if(arr[i] != 0 && !tracker.empty()){
            int new_pos = tracker.front();
            cout << "test: " << new_pos << '\n';
            int temp = arr[i];
            cout << "test temp: " << temp << '\n';
            arr[i] = 0;
            arr[new_pos] = temp;
        }
    }
}
int main() {
	//code
	int t_cases;
	cin >> t_cases;
	int size;
	for(int i = 0; i < t_cases; i++){
	    cin >> size;
	    int arr[size];
	    for(int j = 0; j < size; j++){
	        cin >> arr[j];
	       // cout << "test arr[size]: " << arr[size] << '\n';
	    }
	    easeArray(arr, size);
	    for(int i = 0; i < size; i++){
	        cout << arr[i] << ' ';
	    }
	    cout << '\n';
	}
	return 0;
}