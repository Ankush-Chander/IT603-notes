#include <iostream>

using namespace std;

constexp int x(){
	return 27;
}

unsigned buf_size = 1024; 
// int buf_size = 2;
int ia1[4 * 7 - 14]; // allowed
int ia2[x()]; // allowed
int ia3[buf_size]; // not allowed


int main(){
	return 0;
}