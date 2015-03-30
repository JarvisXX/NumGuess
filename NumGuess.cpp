# include <cstdlib> 
# include <ctime> 
# include <iostream>
# include <cstring>
using namespace std;

int T_time, F_time;	//To record the time of wins and loses.
bool mark[10] = {0};	//To record which number has been created.
 
int rand_num()	//Give me a random number from 0 to 9.
{	int num;
	srand(time(0));
	do
	{	num = rand()%10;
    } while(mark[num] == 1);
	mark[num] = 1;
	return num;
} 

int play_the_game() 
{	int rand_array[3], input_array[3];
	int times, p, q;
	int k, i, j;
	times = 0; 
	memset(mark,0,sizeof(mark));
	for (k=0; k<3; ++k) rand_array[k] = rand_num();
	//cout << rand_array[0] << rand_array[1] << rand_array[2] << endl;	/*I'd like to call it GOD's VIEW.*/ 
	while (times < 7)
	{	p = 0;
		q = 0;
		cout << "请输入你猜测的数字" << endl;
		cin >> input_array[0] >> input_array[1] >> input_array[2];
		for (i=0; i<3; ++i)
		{	for (j=0; j<3; ++j)
			{	if (input_array[i] == rand_array[j]) ++q;	//Right number, but wrong position. 
			}
			if (input_array[i] == rand_array[i])	//Right number, and right position
			{	++p;
				--q;
			}
		}
		if (p == 3)	//Congratilations! You win~~~
		{	cout << "恭喜，你猜对了" << endl;
			++T_time;
			break;
		}
		cout << p << 'A' << q << 'B' << endl;
		++times;
		if (times == 7)	//Sorry, you lose~~~
		{	cout << "很遗憾，你没有在规定次数内猜对。答案是 " << rand_array[0] << rand_array[1] << rand_array[2] << endl;
			++F_time;
		}
	}		
}

int main()
{ 	char choice;
	int total_time;
	T_time = 0;
	F_time = 0;
	while (true)
	{	cout << "需要玩游戏吗(Y/N)?" << endl;
		cin >> choice;
		if (choice == 'Y') play_the_game();	//Let's play the game~ 
		if (choice == 'N') break;	//Jump out of the while-loop function.
		else continue;
	}
	total_time = T_time + F_time;
	cout << "你一共玩了" << total_time << "局，赢了" << T_time << "局，输了" << F_time << "局"; 
	return 0;
} 
