# include <cstdlib> 
# include <ctime> 
# include <iostream>
using namespace std;

int a, b, c;
int T_time, F_time;
 
int rand_num_1()
{	srand(time(0));
    a = rand()%10;
    return a;
}
    
int rand_num_2()
{	srand(time(0));
	do 
	{b = rand()%10;
    } while(b == a);
    return b;
}

int rand_num_3()
{	srand(time(0));
	do 
	{c = rand()%10;
    } while (c == a or c == b);
    return c;
}

int play_the_game() 
{	int rand_array[3], input_array[3];
	int m, i, j, p, q;
	m = 0;
	rand_array[0] = rand_num_1();
	rand_array[1] = rand_num_2();
	rand_array[2] = rand_num_3();
	//cout << rand_array[0] << rand_array[1] << rand_array[2] << endl;
	while (m < 7)
	{	p = 0;
		q = 0;
		cout << "请输入你猜测的数字" << endl;
		cin >> input_array[0] >> input_array[1] >> input_array[2];
		for (i=0; i<3; ++i)
		{	for (j=0; j<3; ++j)
			{	if (input_array[i] == rand_array[j]) ++q;
			}
			if (input_array[i] == rand_array[i]) 
			{	++p;
				--q; 
			}
		}
		if (p == 3)
		{	cout << "恭喜，你猜对了" << endl;
			++T_time;
			break; 
		}
		cout << p << 'A' << q << 'B' << endl;
		++m;
		if (m == 7)
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
		if (choice == 'Y') play_the_game();
		if (choice == 'N') break;
		else continue;
	}
	total_time = T_time + F_time;
	cout << "你一共玩了" << total_time << "局，赢了" << T_time << "局，输了" << F_time << "局"; 
	return 0;
} 
