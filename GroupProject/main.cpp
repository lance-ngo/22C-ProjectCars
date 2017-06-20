#include <iostream>
#include "DataManager.h"
#include "BST.h"
#include "HashTable.h"
#include "List.h"
using namespace std;

void prompt()
{
	cout << "Select from followng menu: (Enter the index number)" << endl;
	cout << "1. Add new car record" << endl;
	cout << "2. Delete car record by model" << endl;
	cout << "3. Find and print car by model" << endl;
	cout << "4. Print cars by hash table" << endl;
	//cout << "5. Print cars in hash key sequence" << endl;
	cout << "6. Print BST indented tree" << endl;//done
	cout << "7. Display efficiency for 3 ADTs" << endl;
	cout << "8. Display cars within range of min and max price" << endl;//done
	cout << "9. Display cars with minimum horsepower" << endl;
	cout << "10. Add/Subtract from car inventory by model" << endl;
	cout << "0. Exit" << endl;
}

void updateInv(){
	string model;
	int change;
	cout << "Please enter car model to update inventory (lower case)" << endl;
	getline(cin, model);
	cout << "Please enter int for change in inventory (negative int to subtract)" << endl;
	cin >> change;
	
	
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
	/*cout<<"-------"<<endl;
	hst.printTable();
	cout<<"-------"<<endl;
	list.print();
	cout << "-------" << endl;
	bstree.Print();*/

	int choice;
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
			//call bool:addRecord(), addRecord will prompt user for data fieds and return true if added
			break;
		}
		case 2:
		{
			string t;
			cin>>t;
			
			break;
		}
		case 3:
		{
			//call void:find2print(), find2print() will prompt user for model, find and print car
			break;
		}
		case 4:
		{
			hst.printTable();
			break;
		}
		case 5:
		{
			list.print(0);
			break;
		}
		case 6:
		{
			bstree.Print();
			break;
		}
		case 7:
		{
			//eff
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
			//call void:carsByPower(), carsByPower() will promp user for min horsepower, print cars higher than that
			break;
		}
		case 10:
		{
			//prompt model name;
			updateInv();
			break;
		}
		case 0:
		{
			cout<<"Please input output file name"<<endl;
			string t;
			cin>>t;
			if(!list.saveToFile(t))
				cout<<"Save to file failed"<<endl;
			cout<<"Saving complete"<<endl;
			break;
		}
	}
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
