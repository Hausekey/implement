#include <iostream>
#include <vector>
#include <stdlib.h> 
using namespace std;


enum class Tile_type {mine, safe};
enum class Difficulty {easy, medium, hard};

class Minesweeper{
	int adjTiles[8][2] = {
		{ 1,  1},
		{ 0,  1},
		{-1, -1},
		{ 0, -1},
		{ 1,  0},
		{-1,  0},
		{-1,  1},
		{ 1, -1}
	};
	int mine_count;
	int mines_revealed;
	int board_size;
	bool game_over;
	struct Tile{
		bool mine;
		char disp;
		int adj_mines;
	};
	vector<vector<Tile> > mines;
	//do i want to make it a bool or not decisions
	//would i want to determine if the mine is safe or not in one go?
	public:


	Minesweeper(Difficulty n){
		switch(n){
			case Difficulty::easy: 
				mine_count = 10;
				board_size = 8;
				break;
			case Difficulty::medium:
				mine_count = 40;
				board_size = 16;
				break;
			case Difficulty::hard:
				mine_count = 99;
				board_size = 24;
				break;
			default:
				mine_count = 10;
				board_size = 8;
				break;
		}
	}

	void initialize_board(){
		int i = 0;
		for(int i = 0; i < board_size; i++){
			vector<Tile> row;
			for(int j = 0; j < board_size; j++){
				Tile new_tile;
				new_tile.mine = false;
				new_tile.disp = '-';
				new_tile.adj_mines = 0;
				row.push_back(new_tile);
			}
			mines.push_back(row);
		}
		while(i < mine_count){
			int x = rand() % board_size;
			int y = rand() % board_size;
			if(!mines[x][y].mine){
				mines[x][y].mine = true;
				i++;
			}
		}
	}
	void disp(){
		for(int i = 0; i < board_size; i++){
			for(int j = 0; j < board_size; j++){
				cout << '[' << mines[i][j].disp << ']';
			}
			cout << '\n';
		}
	}
	int mines_left(){
		return mine_count - mines_revealed;
	}
	bool click(int x, int y){
		if(mines[x][y]){
			game_over = true;
		}
		else{
			//check adjacent
		}
		return true;
		//return false if out of bounds
	}

	void check_adj(int x, int y){

	}

};
int main(){
	Minesweeper test(Difficulty::easy);
	test.initialize_board();
	bool interrupt = false;
	char x, y;
	while(test.mines_left() > 0 && !interrupt){
		test.disp();
		cout << "\n\nNext move: " << '\n';
		cin >> x >> y;
		if(x == 'q'){
			interrupt = true;
			cout << "Goodbye\n";
		}
		else{
			int x_int = x - '0';
			int y_int = y - '0';
		}
	}
}