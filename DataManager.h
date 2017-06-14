template<typename T>
class DataManager
{
private:
	T data[100];
	int curInd;
	//HashMap
	//BST
	//LinkedList
public:
	DataManager()
	{
		curInd = 0;
	}
	void Add(T x)
	{
		data[curInd] = x;
		//HashMap.Insert(&data[curInd]);
		//BST.Insert(&data[curInd]);
		//LinkedList.Insert(&data[curInd]);
		curInd++;
	}
	void Remove(int key, string value)
	{
		T* tar = Find(key, value);
		//HashMap, BST, LinkedList.Remove(tar)
	}
	T* Find(int key, value)
	{
		//Search in different ADT for different keys
	}
};