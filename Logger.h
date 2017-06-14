#include <fstream>
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
	friend std::ofstream& operator<<(std::ofstream &x, Logger &a)
	{
		x << a.totOp << " " << a.opCount << " " << a.totOp * 1.0 / a.opCount;
	}
};