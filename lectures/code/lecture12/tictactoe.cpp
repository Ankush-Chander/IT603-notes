#include <iostream>
using namespace std;

// print board
void print_board(char board[][3]){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}


char check_winner(char board[][3]){
// check if game over(1)
for(int i = 0; i < 3; i++){
	// check ith row
	if(board[i][0] == board[i][1] &&
	 board[i][0] == board[i][2]){
		return board[i][0];
	}
	// check ith column
	if(board[0][i] == board[1][i] &&
	 board[0][i] == board[2][i]){
		return board[0][i];
	}
}


// check if game over(2)
// check diagonals
if(board[0][0] == board[1][1] && 
   board[0][0] == board[2][2]){
	return board[0][0];
}
if(board[0][2] == board[1][1] && 
   board[0][2] == board[2][0]){
	return board[0][2];

}
return ' ';
}


int main(){
// setup board
string cells = "123456789";
char board[3][3];
for (int i = 0; i < 3; i++){
	for (int j = 0; j < 3; j++){
		board[i][j] = cells[i*3 + j];
	}
}

// board looks like
//1 2 3
//4 5 6
//7 8 9
// game play
char inp[2]= {'X', 'O'};
int turn = 0;
int num, x, y;
print_board(board);
// cout << check_winner(board) << endl;
while(check_winner(board) == ' '){
	cout << "Player " << (turn%2) + 1 << ", enter cell number: ";
	cin >> num;
	// valiate num
	if (num < 1 || num > 9){
		cout << "Invalid input" << endl;
		continue;
	}
	if (board[(num-1)/3][(num-1)%3] != cells[(num-1)]){
		cout << "Cell already filled" << endl;
		continue;
	}

	// convert input into coordinates
	x = (num-1) / 3;
	y = (num-1) %3 ;
	cout << x << " " <<y << endl;
	board[x][y] = inp[(turn%2)];
	print_board(board);
	turn++;
}
cout << check_winner(board)  << "won!" << endl;
}