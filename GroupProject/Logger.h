#include <iostream>
class Logger
{
private:
	int totOp, opCount;
public:
	Logger()
	{
		totOp = 0;
		opCount = 0;
	}
	void Record(int count)
	{
		totOp += count;
		opCount++;
	}
	void Clear()
	{
		totOp = 0;
		opCount = 0;
	}
	void Print()
	{
		std::cout << totOp << " " << opCount << " " << totOp * 1.0 / opCount<<std::endl;
	}
};