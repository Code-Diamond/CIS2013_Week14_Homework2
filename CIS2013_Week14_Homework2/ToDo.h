#include <iostream>
#include <string>

using namespace std;

class ToDo 
{
private:
	string *list;
	int length = 0;
	int next = 0;
	int numberOfLines = 0;
public:
	//Create list of length l
	ToDo();
	//Add item to list		
	void add(string i);
	//Finish the last item in list
	void done(int itemNumber);
	//Print the list
	void print();
	//Destroy our list
	~ToDo();
};