#include <iostream>

using namespace std;

struct car_salon
{
	char marka[20];
	char model[20];
	char gearbox_type[30];
	int graduation_year;
	int price;
};

void Show(car_salon car)
{
	cout << "\tMarka :          " << car.marka << endl;
	cout << "\tModel :          " << car.model << endl;
	cout << "\tGearbox type :   " << car.gearbox_type << endl;
	cout << "\tGradution year : " << car.graduation_year << endl;
	cout << "\tPrice :          " << car.price << " $" << endl;
}

void SearchByMarka(car_salon car[], char marka[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(car[i].marka, marka) == 0)
		{
			Show(car[i]);
			cout << endl;
		}
	}
}

void SearchByModel(car_salon car[], char model[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(car[i].model, model) == 0)
		{
			Show(car[i]);
			cout << endl;
		}
	}
}

void SearchByGraduationYear(car_salon car[], int graduation_year, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (car[i].graduation_year == graduation_year)
		{
			Show(car[i]);
			cout << endl;
		}
	}
}

void SortByPrice(car_salon car[], int size, int option)
{
	if (option == 0)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (car[j].price > car[j + 1].price)
				{
					int tmp = car[j].price;
					car[j].price = car[j + 1].price;
					car[j + 1].price = tmp;
				}
				if (car[j].price < car[j + 1].price)
				{
					int tmp = car[j].price;
					car[j].price = car[j + 1].price;
					car[j + 1].price = tmp;
				}
			}
		}
	}
	else if (option == 1)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (car[j].price < car[j + 1].price)
				{
					int tmp = car[j].price;
					car[j].price = car[j + 1].price;
					car[j + 1].price = tmp;
				}
				if (car[j].price > car[j + 1].price)
				{
					int tmp = car[j].price;
					car[j].price = car[j + 1].price;
					car[j + 1].price = tmp;
				}
			}
		}
	}
}



void main()
{

	const int size = 20;
	car_salon car[size] = {
		{"Mazda","6","automatic",2021,27000},
		{"Mazda","3","automatic",2020,20500},
		{"Audi""A6","automatic",2019,43000},
		{"Audi","A8","automatic",2018,36000},
		{"Audi","A3","automatic",2017,19000},
		{"BMW","X5","automatic",2017,38000},
		{"BMW","X1","automatic",2019,25000},
		{"Chevrolet","Camaro","automatic",2017,29000},
		{"Chevrolet","Cruze","automatic",2017,10700},
		{"Ford","Mustang","automatic",2019,47500},
		{"Ford","Ranger","automatic",2022,71000},
		{"Mersedes-Benz","E 220","autimatic",2021,70000},
		{"Peugeot","580","automatic",2022,39000},
		{"Peugeot","301","manual",2022,19600},
		{"Peugeot","208","automatic",2021,20600},
		{"Scoda","Octavia","manual",2022,35200},
		{"Renault","Logan","manual",2021,13900},
		{"Subaru","Legacy","automatic",2020,18500},
		{"Subaru","Forester","variable speed drive",2021,40000},
		{"Toyota","Corolla","automatic",2021, 18000}
	};
	int option;
	int num;
	do
	{
		cout << "\t______________Menu______________" << endl;
		cout << "\tShow all                     [1]" << endl;
		cout << "\tSearch by marka              [2]" << endl;
		cout << "\tSearch by model              [3]" << endl;
		cout << "\tSearch by graduation year    [4]" << endl;
		cout << "\tSort by price                [5]" << endl;
		cout << "\tExit                         [0]" << endl;
		cin >> num;
		switch (num)
		{
		case 1:
			for (int i = 0; i < size; i++)
			{
				Show(car[i]);
				cout << endl;
			}
			break;
		case 2:
			cout << "Enter marka of car : ";
			char marka[20];
			cin >> marka;
			SearchByMarka(car, marka, size);
			break;
		case 3:
			cout << "Enter model of car : ";
			char model[20];
			cin >> model;
			SearchByModel(car, model, size);
			break;
		case 4:
			cout << "Enter graduation year of car (2017-2022): ";
			int graduation_year;
			cin >> graduation_year;
			SearchByGraduationYear(car, graduation_year, size);
			break;
		case 5:
			cout << "\nChoose to sort:\nEnter 0 - in descending order\nEnter 1 - ascending" << endl;
			cin >> option;
			if (option == 0 || option == 1)
			{
				SortByPrice(car, size, option);
				for (int i = 0; i < size; i++)
				{
					Show(car[i]);
					cout << endl;
				}
			}
			break;
		case 0:
			cout << "____Goodbuy____" << endl;
			exit(0);
		default:
			cout << "Error input. Enter your choice..." << endl;
			break;
		}
	} while (num != 0);
}