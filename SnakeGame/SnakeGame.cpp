#include <iostream>
#include<Windows.h>
#include <conio.h>
using namespace std;

bool gameStatus;
const int height = 20;
const int width = 20;
int head;
int tail;
int appleX, appleY;
int score;

int temp_head[100];
int temp_tail[100];
int temp_head1[100];
int temp_tail2[100];

enum Position
{
	STOP = 0, LEFT, RIGHT, UP, DOWN
};
Position dir;

void Start()
{
	gameStatus = true;
	dir = STOP;
	head = 10;
	tail = 10;
	appleX = rand() % width;
	appleY = rand() % height;
}

void Walls()
{

	system("cls");
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (i == 0 || i == 19)
			{
				cout << "*";
			}
			else
			{
				if (j == 0 || j == 19)
				{
					cout << "*";
				}
				cout << " ";
			}
			if (i == head && j == tail)
			{
				cout << "O";
			}
			else if (i == appleX && j == appleY)
			{
				cout << "@";
			}
			else
			{
				cout << " ";
			}
		}

		cout << endl;
	}
	cout << "Your Score: " << score;
}

void PlayerInput()          // Gets input from keyboard
{

	if (_getch() == 'a')
	{

		dir = LEFT;
	}
	else if (_getch() == 'w')
	{

		dir = UP;
	}
	else if (_getch() == 's')
	{

		dir = DOWN;
	}
	else if (_getch() == 'd')
	{

		dir = RIGHT;
	}
	else if (_getch() == 'x')
	{

		gameStatus = false;

	}

}

void Direct()
{
	if (dir == LEFT)
	{

		tail--;

	}
	else if (dir == RIGHT)
	{

		tail++;
	}
	else if (dir == UP)
	{

		head--;
	}
	else if (dir == DOWN)
	{

		head++;
	}
	if (head > width || head<0 || tail > height || tail < 0)
	{
		cout << "Game over: ";
		gameStatus = false;
	}
	if (head == appleX && tail == appleY)
	{
		temp_head[0] = tail;
		temp_head1[0] = temp_head[0];
		score++;
		appleX = rand() % width;
		appleY = rand() % height;
	}
}


int  main() {

	//PlaySound(TEXT("piano.wav"), NULL, SND_FILENAME | SND_ASYNC);      // if you want the music to play
	Start();

	while (gameStatus == true)
	{
		Walls();
		PlayerInput();
		Direct();
	}
	return 0;

}