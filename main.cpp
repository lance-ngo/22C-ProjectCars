#include "Car.h"
#include <string>
#include <fstream>
#include <cstdlib>

//#include "List.h"
//#include "Hash.h"
//#include "Bst.h"

using namespace std;

void populate3(){ //the 3 parameters should be each of the instances of the 3 adts

	ifstream carsIn("carInventory.csv");
	if (carsIn.fail())
	{
		cerr << "could not open cars file";
		exit(1);
	}

	string buffer, make, model, body, trans;
	int msrp, hp, cap, stock;
	size_t p1, p2, p3, p4, p5, p6, p7;

	while (!carsIn.eof())
	{
		getline(carsIn, buffer);
		p1 = buffer.find(',');
		p2 = buffer.find(',', p1 + 1);
		p3 = buffer.find(',', p2 + 1);
		p4 = buffer.find(',', p3 + 1);
		p5 = buffer.find(',', p4 + 1);
		p6 = buffer.find(',', p5 + 1);
		p7 = buffer.find(',', p6 + 1);

		make = buffer.substr(0, p1);
		model = buffer.substr(p1 + 1, p2 - (p1 + 1));
		msrp = stoi(buffer.substr(p2 + 1, p3 - (p2 + 1)));
		hp = stoi(buffer.substr(p3 + 1, p4 - (p3 + 1)));
		body = buffer.substr(p4 + 1, p5 - (p4 + 1));
		cap = stoi(buffer.substr(p5 + 1, p6 - (p5 + 1)));
		trans = buffer.substr(p6 + 1, p7 - (p6 + 1));
		stock = stoi(buffer.substr(p7 + 1));

		//how will we create a new Car here and have the node from all 3 ADT's point to it?

	}

}

int main(){
	
	List carsList;
	Bst carsBst;
	Hash carsHash; //of ~70 elements

	populate3(carsList, carsBst, carsHash);

	/*
	Car one("porsche", "panamera turbo", 150500, 432, 3, "crossover", 5, "auto");
	Car two("toyota", "sienna", 30100, 234, 1);
	Car three("honda", "accord", 34000, 290, 10);

	//out << std::setw(10) << std::left << x.make << std::setw(16) << std::left << x.model << std::setw(6) << std::right << x.msrp
		//<< std::setw(5) << std::right << x.hp << "  " << std::setw(11) << std::left << x.body << std::setw(5) << x.seats
		//<< std::setw(5) << x.trans << std::setw(5) << x.stock;

	cout << setw(10) << left << "Make" << setw(16) << left << "Model" << setw(6) << right << "MSRP $"
		<< setw(5) << right << "hPow" << "  " << setw(11) << left << "Body" << setw(5) << "cap"
		<< setw(5) << "tran" << setw(5) << "stock" << endl;
	cout << "============================================================================" << endl;
	cout << one << endl;
	cout << two << endl;
	cout << three << endl;

	two - 1;
	cout << two << endl;
	two - 1;
	cout << two << endl;
	one + 3;
	three - 3;
	cout << one << endl;
	cout << three << endl;
	*/
	cin.get();
}

