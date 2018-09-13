/*
 * 打飞机_游戏 by Yao J.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>



char board [10][10] = {
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
};


int generateDirection(){
	srand(time(NULL));
	int direction = rand() % 4; // 0 is up, 1 is down, 2, is left, 3 is right.
	return direction;
}

typedef struct {
	int x;
	int y;
	char symbol;
}cockpit;




cockpit plane[10];

int generateZ(){
	srand (time(NULL));
	int z = rand() % 9 + 1;
	return z;
}

int generateY (){
	srand (time(NULL));
	int y = rand() % 6 + 2;
	return y;
}

int generateX () {
	srand (time(NULL));
	int x = (rand() + generateZ())% 7;
	return x;
}



cockpit* generatePlane (cockpit *plane){
	
	plane [0].x = generateX();
	plane [0].y = plane[3].y= plane[6].y= plane[8].y = generateY();
	int i = plane[0].x;
	int j = plane[0].y;
	//x of a b c d e
	plane[1].x =plane[2].x = plane[3].x = plane[4].x = plane[5].x = i+1;
	//x of f
	plane[6].x = i + 2;
	//x of g h i
	plane[7].x = plane[8].x = plane[9].x = i+3;
	//y of b g 
	plane[2].y = plane[7].y = j - 1; 
	//y of d i
	plane[4].y = plane[9].y = j + 1;
	plane[1].y = j-2;
	plane[5].y = j+2; 

	plane[0].symbol = '@';
	
	for (int n = 1; n < 10; n++){
		plane[n].symbol = '+';
	}

	return plane;
}


void rotatePlane (cockpit *plane){
	int direction = generateDirection();

	for (int i = 0; i < 10; i++){
		int x = plane[i].x;
		int y = plane[i].y;
		
		int temp; 

		switch (direction){
			case 1:  // down
				x = 9 - x;
				break;
			case 2:   // left
				temp = y; 
				y = x; 
				x = 9 - temp;
				break;
			case 3: // right  0, 3 -> 3 9
				temp = x;
				x = y;
				y = 9 - temp;
				break;
			default:
				break;
		}

		plane[i].x = x;
		plane[i].y = y;

	}


}

void display (){
	system("clear");
	printf ("    0 1 2 3 4 5 6 7 8 9 \n");
	for (int i = 0; i< 10 ; i++){
		printf ("%d->", i);
		for (int j = 0; j < 10 ; j++){
			printf ("|%c", board[i][j]);
		}
		printf ("|\n");
	}
}



// wait for function
void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}



// return whether the plane was hit and explode. 
void renderHitpoint (cockpit hitpoint){
	if (hitpoint.symbol == '@'){
		for (int i = 0; i < 10; i++){
			board[plane[i].x][plane[i].y] = '@';
		}
	}else{
		board[hitpoint.x][hitpoint.y] = hitpoint.symbol;
	}
}


// takes x and y of a hit and change plane array accordingly then return hitpoint, which will be accepted by renderHitpoint()
cockpit hit (int i, int j){
	cockpit hitpoint; 
	hitpoint.x = i;
	hitpoint.y = j;
	hitpoint.symbol = 'o';

	for (int n = 0; n < 10; n++){
		if (plane[n].x == i && plane[n].y == j){
			hitpoint.x = plane[n].x;
			hitpoint.y = plane[n].y;
			hitpoint.symbol = plane[n].symbol;
			break;
		}
	}

	return hitpoint;
}



int main (){
	
	
	cockpit *readytofly1 = generatePlane(plane);
	rotatePlane(readytofly1);


 
	int x, y;
	bool flag = true;
	display();
	while (flag == true){

		scanf("%d, %d", &x, &y);
		hit(x, y);
		if (hit(x, y).symbol == '@'){
			flag = false;
		}
		renderHitpoint(hit(x, y));
		//printf ("\n");
		//printf ("%d %d %c", plane[0].x, plane[0].y, plane[0].symbol);
		display();
	}


	// waitFor(1);
	// readytofly1 = generatePlane(plane);
	// rotatePlane(readytofly1);
	// setPlane(readytofly1);
	// display();

	return 0;
}
