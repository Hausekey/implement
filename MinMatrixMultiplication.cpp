#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <list>
#include <unordered_map>

using namespace std;

struct matrix{
    string key;
    int min_ops;
    tuple<int, int> dimens;
};

int minMatrixMul(vector<matrix>& matrices, 
	unordered_map<string, int>& op_map){
    if(matrices.size() == 1){
        return 0;
    }
    else if(matrices.size() == 2){
        //check if it exists in hash table
        //IMPLEMENT HASH
        matrix mergedMat;
        mergedMat.key = matrices[0].key + matrices[1].key;

        if(matrices[0].key.length() == 1 && matrices[1].key.length() == 1 
        	&& op_map.find(mergedMat.key) != op_map.end()){
        	return op_map[mergedMat.key];
        }

        int ops = get<1>(matrices[0].dimens) * get<0>(matrices[0].dimens) 
        	* get<1>(matrices[1].dimens) + matrices[0].min_ops + matrices[1].min_ops;
        //add to hash
	    if(op_map.find(mergedMat.key) != op_map.end()){
	        if(ops < op_map[mergedMat.key]){
		        op_map[mergedMat.key] = ops;
   		    }
   		    else{
   		    	ops = op_map[mergedMat.key];
   		    }
        }
        else{
        	op_map[mergedMat.key] = ops;
        }

        return ops;
    }
    else{
    	for(int i = 0; i < matrices.size() - 1; i++){
    		vector<matrix> mergedMats(matrices.size() - 1);
    		int ops;
    		for(int j = 0; j < i; j++){
    			mergedMats[j] = matrices[j];
    		}
    		//pair up the two matrices
    		matrix mergedMat;
    		mergedMat.key = matrices[i].key + matrices[i+1].key;

    		if(matrices[i].key.length() == 1 && matrices[i+1].key.length() == 1){ //if it's just one pair - one answer
    			if(op_map.find(mergedMat.key) != op_map.end()){
    				ops = op_map[mergedMat.key];
    			}
    			else{
    				ops = get<1>(matrices[i].dimens) * get<0>(matrices[i].dimens)
    					* get<1>(matrices[i+1].dimens) + matrices[i].min_ops + matrices[i+1].min_ops; 
    				op_map[mergedMat.key] = ops;
    			}
    		}
    		else{ //otherwise, calculate
	    		ops = get<1>(matrices[i].dimens) * get<0>(matrices[i].dimens)
    				* get<1>(matrices[i+1].dimens) + matrices[i].min_ops + matrices[i+1].min_ops;
    			if(op_map.find(mergedMat.key) != op_map.end()){
    				if(ops < op_map[mergedMat.key]){
    					op_map[mergedMat.key] = ops;
    				}
    				else{
    					ops = op_map[mergedMat.key];
    				}
    			}
    			else{
    				op_map[mergedMat.key] = ops;
    			}
    		}
    		//once calculation is complete, merge the two matrices
    		mergedMat.dimens = make_tuple(get<0>(matrices[i].dimens), 
    			get<1>(matrices[i+1].dimens));
    		mergedMat.min_ops = ops;
    		mergedMats[i] = mergedMat;
    		//fill rest of vector
    		for(int j = i + 1; j < matrices.size() - 1; j++){
    			mergedMats[j] = matrices[j + 1];
    		}
    		minMatrixMul(mergedMats, op_map);
    	} 

	    string completeMatx;
    	for(int si = 0; si < matrices.size(); si++){
    		completeMatx += si + '0';
    	}
    	return op_map[completeMatx];
    }
    
}
int main() {
	//code
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; a0++){
	    int arrSize;
	    cin >> arrSize;
	    int arr[arrSize];
	    for(int a1 = 0; a1 < arrSize; a1++){
	        int matSize;
	        cin >> matSize;
	        arr[a1] = matSize; 
	    }
	   // list<matrix> matrixList;
	    vector<matrix> matrices(arrSize - 1);
        unordered_map<string, int> ops_map;

	    for(int i = 0; i < arrSize - 1; i++){
	        matrix m;
	        m.key.assign(1, i + '0');
	        m.min_ops = 0;
	        m.dimens = make_tuple(arr[i], arr[i+1]);
	        
	        matrices[i] = m;
	    }
	    cout << minMatrixMul(matrices, ops_map) << '\n';
	    
	}
	return 0;
}