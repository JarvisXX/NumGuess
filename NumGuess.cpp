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
		cout << "��������²������" << endl;
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
		{	cout << "��ϲ����¶���" << endl;
			++T_time;
			break; 
		}
		cout << p << 'A' << q << 'B' << endl;
		++m;
		if (m == 7)
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
		if (choice == 'Y') play_the_game();
		if (choice == 'N') break;
		else continue;
	}
	total_time = T_time + F_time;
	cout << "��һ������" << total_time << "�֣�Ӯ��" << T_time << "�֣�����" << F_time << "��"; 
	return 0;
} 
