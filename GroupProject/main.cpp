#include <iostream>
#include "DataManager.h"
#include "BST.h"
#include "HashTable.h"
#include "List.h"
using namespace std;

bool checkIsNull(Car* t)
{
	if (t == nullptr)
	{
		cout << "Cannot found given model name in database, please check your spelling and type in again." << endl;
		return false;
	}
	return true;
}

void prompt()
{
	cout << "Select from followng menu: (Enter the index number)" << endl;
	cout << "1. Add new car record" << endl;
	cout << "2. Delete car record by model" << endl;
	cout << "3. Find and print car by model" << endl;
	cout << "4. Print cars by hash table" << endl;
	cout << "5. Print cars sorted by HP" << endl;
	cout << "6. Print BST indented tree" << endl;//done
	cout << "7. Display efficiency for 3 ADTs" << endl;
	cout << "8. Display cars within range of min and max price" << endl;//done
	cout << "9. Display cars with minimum horsepower" << endl;
	cout << "10. Add/Subtract from car inventory by model" << endl;
	cout << "0. Exit" << endl;
}

void updateInv(Hashtable<Car> &hst){
	string model;
	int change;
	Car* temp;
	cout << "Please enter car model to update inventory (lower case)" << endl;
	cin.ignore();
	getline(cin, model);
	temp = hst.find(model);
	if (checkIsNull(temp))
	{
		cout << "Please enter int for change in inventory (negative int to subtract)" << endl;
		cin >> change;

		temp->changeInv(change);
		cout << (*temp) << endl;
	}
}

int main()
{
	BST bstree;
	Hashtable<Car> hst;
	List<Car> list;
	DataManager manager;
	manager.SetBST(&bstree);
	manager.SetList(&list);
	manager.SetHashTable(&hst);
	manager.ReadFile("carinv.txt");

	int choice;
	bool exitThisTime = false;
	prompt();
	while(cin >> choice)
	{
	switch(choice)
	{
		case 1:
		{
			string buffer, make, model, body, trans;
			int msrp, hp, cap, stock;
			cout<<"Please input the following data, seperated by one space."<<endl;
			cout << setw(10) << left << "Make" << setw(16) << left << "Model" << setw(6) << right << "MSRP"
				<< setw(5) << right << "HP" << "  " << setw(11) << left << "Body" << setw(6) << "Seats"
				<< setw(8) << "Trans" << setw(5) << "Stock" << endl;
			cin>>make>> model>> msrp>> hp>> stock>> body>> cap>> trans;
			Car* tempCar = new Car(make, model, msrp, hp, stock, body, cap, trans);
			manager.Add(tempCar);
			break;
		}
		case 2:
		{
			string t;
			cin.ignore();
			getline(cin,t);
			Car* tar = hst.find(t);
			if (checkIsNull(tar))
			{
				manager.Remove(tar);
			}
			break;
		}
		case 3:
		{
			string model;
			cin.ignore();
			getline(cin, model);
			Car* t = hst.find(model);
			if (checkIsNull(t))
			{
				cout << *t << endl;
			}
			break;
		}
		case 4:
		{
			hst.printTable();
			break;
		}
		case 5:
		{
			list.print();
			break;
		}
		case 6:
		{
			bstree.Print();
			break;
		}
		case 7:
		{
			cout << "AVL efficiency data:" << endl;
			bstree.GetPerformance();
			cout << endl;
			cout << "HashTable efficiency data:" << endl;
			hst.printEfficiencyData();
			cout << endl;
			cout << "LinkedList efficiency data:" << endl;
			list.printEfficiency();
			break;
		}
		case 8:
		{
			int l,r;
			cout<<"Please enter minimum price and maximum price(two integers)"<<endl;
			cin>>l>>r;
			bstree.Print_Range(l,r);
			break;
		}
		case 9:
		{
			int hp;
			cout << "Please enter a integer to get all cars have higher horse power" << endl;
			cin >> hp;
			list.findByHp(hp);
			break;
		}
		case 10:
		{
			updateInv(hst);
			break;
		}
		case 0:
		{
			bool f;
			cout << "Do you want to save current data to file?(1=yes/0=no)" << endl;
			cin >> f;
			if (f)
			{
				cout << "Please input output file name" << endl;
				string t;
				cin >> t;
				if (!list.saveToFile(t))
					cout << "Save to file failed" << endl;
				cout << "Saving complete" << endl;
			}
			exitThisTime = true;
		}
		
	}
	if (exitThisTime)
		break;
	exitThisTime = false;
	#ifdef _WIN32
	system("pause");
	system("cls");
	#elif _WIN64
	system("pause");
	system("cls");
	#else
	system("read -rsp $'Press any key to continue...\\n' -n 1 key");
	system("clear");
	#endif
	prompt();
	}
	
	cout << "Thank you for using CarsRecord Program." << endl;
}
