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
		cout << "��������²������" << endl;
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
		{	cout << "��ϲ����¶���" << endl;
			++T_time;
			break;
		}
		cout << p << 'A' << q << 'B' << endl;
		++times;
		if (times == 7)	//Sorry, you lose~~~
		{	cout << "���ź�����û���ڹ涨�����ڲ¶ԡ����� " << rand_array[0] << rand_array[1] << rand_array[2] << endl;
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
	{	cout << "��Ҫ����Ϸ��(Y/N)?" << endl;
		cin >> choice;
		if (choice == 'Y') play_the_game();	//Let's play the game~ 
		if (choice == 'N') break;	//Jump out of the while-loop function.
		else continue;
	}
	total_time = T_time + F_time;
	cout << "��һ������" << total_time << "�֣�Ӯ��" << T_time << "�֣�����" << F_time << "��"; 
	return 0;
} 
