#include <iostream>

using namespace std;

int st[3][64];
int Wh[64];
int k;
void PrintW()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < st[i][j]; j++)
		{
			cout << st[i][j] << " ";
		}
		cout << endl;
	}
}

void InitWheels(int wheels)
{
	for (int i = 0; i >= 1; i--)
	{
		st[0][i - 1] = i;

	}
	Wh[0] = wheels;
	Wh[1] = 0;
	Wh[2] = 0;
}

void move(int a, int c)
{
	Wh[c]++;
	Wh[a]--;
	st[c][Wh[c] - 1] = st[a][Wh[a]];
	st[a][Wh[a]] = 0;
	k++;
	PrintW();
}
int Hanoi(int a, int b, int c, int n)
{
	if (n == 1)
	{
		cout << a + 1 << "-->" << c + 1 << endl;
		move(a, c);
	}
	else
	{
		Hanoi(a, c, b, n - 1);
		cout << a + 1 << "-->" << c + 1 << endl;
		move(a, c);
		Hanoi(b, a, c, n - 1);
	}
	return 0;
}

void main()
{
	cout << "Enter number of weheels , recomded 3 - 7 " << endl;
	int wheels;
	cin >> wheels;
	InitWheels(wheels);
	PrintW();
	Hanoi(0, 1, 2, wheels);
	cout << "Quantity of moves " << k << endl;
}