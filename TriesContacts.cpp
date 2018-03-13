#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Trie{
    class Node{
        public:
            unordered_map<char, Node*> children;
            bool isCompleteWord;
           // vector<char> totalChildren; //indirect children
            int countChildren;
    };

    Node* root = new Node;
    public:
        Trie(){
            root->isCompleteWord  = true;
        }
    
        void addWord(string name){
            Node *ptr = root;
            for(int i = 0; i < name.length(); i++){
                ++(ptr->countChildren);
                if(ptr->children.find(name[i]) == ptr->children.end()){
                  //  ptr->totalChildren.push_back(name[i]);
                    Node *new_char = new Node;
                    ptr->children[name[i]] = new_char;
                    ptr = new_char;
                }
                else{
                    ptr = ptr->children[name[i]];
                }
            }
            if(!ptr->isCompleteWord){
                ptr->isCompleteWord = true;
                ++(ptr->countChildren);
                //ptr->totalChildren.push_back('*');            
            }
        }

        Node* findWord(string name){
            Node *ptr = root;
            for(int i = 0; i < name.length(); i++){
                if(ptr != NULL && ptr->children.find(name[i]) != ptr->children.end()){
                    ptr = ptr->children[name[i]];
                }
                else{
                    return NULL;
                }
            } 
            return ptr;
        }
        int findChildren(string name){
            Node *ptr = findWord(name);
            // queue<Node*> q;
            // if(ptr == NULL){
            //     return 0;
            // }
            // q.push(ptr);
            // while(!q.empty()){
            //     Node *check = q.front();
            //     q.pop();
            //     for(int i = 0; i < check->totalChildren.size(); i++){
            //         if(check->totalChildren[i] == '*'){
            //             children++;
            //         }
            //         else{
            //             q.push(check->children[check->totalChildren[i]]);
            //         }
            //     }
            // }
            return ptr == NULL ? 0 : ptr->countChildren;
        }
        
    
};

int main(){
    int n;
    cin >> n;
    Trie contactList;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op == "add"){
            contactList.addWord(contact);
        }
        else if(op == "find"){
            cout << contactList.findChildren(contact) << '\n';
        }
    }
    return 0;
}
