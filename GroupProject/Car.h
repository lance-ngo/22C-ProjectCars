#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
#include <iomanip>

class Car
{
private:
	std::string make, model, body, trans;
	int msrp, hp, seats, stock;
public:
	Car()
	{}
	Car(std::string mke, std::string mdl, int price, int power, int stck, std::string bdy = "", int sts = 0, std::string t = "") {
		make = mke;
		model = mdl;
		body = bdy;
		trans = t;
		msrp = price;
		hp = power;
		seats = sts;
		stock = stck;
	}

	std::string getMake() const {
		return make;
	}

	std::string getModel() const {
		return model;
	}

	int getMsrp() const {
		return msrp;
	}

	int getHp() const {
		return hp;
	}

	int getStock() const {
		return stock;
	}

	void setBody(std::string bdy) {
		body = bdy;
	}

	std::string getBody() const {
		return body;
	}

	void setSeats(int sts) {
		seats = sts;
	}

	int getSeats() const {
		return seats;
	}

	void setTrans(std::string t) {
		trans = t;
	}

	std::string getTrans() const {
		return trans;
	}

	int operator/(const Car x) const {	//compare two cars, neg value means second car is more expensive
		return msrp - x.getMsrp();
	}

	void operator+(int x) {				//to easily add stock
		stock += x;
	}

	void operator-(int x) {				//to easily subtract stock
		stock -= x;
		if (stock < 0)
			stock = 0;
	}
	Car& operator=(const Car x)
	{
		make = x.getMake();
		model = x.getModel();
		body = x.getBody();
		trans = x.getTrans();
		msrp = x.getMsrp();
		hp = x.getHp();
		seats = x.getSeats();
		stock = x.getStock();
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const Car& x) {		//print car details
		out << std::setw(10) << std::left << x.make << std::setw(16) << std::left << x.model << std::setw(6) << std::right << x.msrp
			<< std::setw(5) << std::right << x.hp << "  " << std::setw(11) << std::left << x.body << std::setw(5) << x.seats
			<< std::setw(5) << x.trans << std::setw(5) << x.stock;
		return out;
	}

};

#endif
