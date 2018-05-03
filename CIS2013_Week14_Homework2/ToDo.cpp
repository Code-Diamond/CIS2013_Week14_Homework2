#include "ToDo.h"
#include <fstream>

using namespace std;

	ToDo::ToDo()
	{
		ifstream inputStream;

		inputStream.open("list.dat");


		string line;
		while (getline(inputStream, line))
		{
			if(line != "")
			{
				numberOfLines++;	
			}
	        
		}
		inputStream.close();


		if (numberOfLines == 0)
		{
			cout << "Creating new list. . ." << endl;
			int l;
			cout << "How long would you like the list?";
			cin >> l;
			list = new string[l];
		}
		else
		{
			inputStream.open("list.dat");
			list = new string[numberOfLines];
			for(int i = 0; i < numberOfLines; i++)
			{

				inputStream >> line;
				list[i] = line;
			}    
			inputStream.close();
			
		}




	}
	//Destructor (~ automatically calls when out of scope)
	ToDo::~ToDo()
	{
		ofstream outputStream;

		outputStream.open("list.dat");
		//Error check and close program
		if (outputStream.fail())
		{
			cout << "Unable to open file list.dat";
			exit(1);
		}

		for(int i = 0; i < length; i++)
		{
			outputStream << list[i] << endl;
		}

		outputStream.close();
		delete [] list;
	}

	//Add item to list		
	void ToDo::add(string i)
	{
		if(next < length)
		{
			list[next] = i;
			next++;
		}

	}
	//Finish the last item in list
	void ToDo::done(int itemNumber)
	{
		list[itemNumber] = "";
	}
	//Print the list
	void ToDo::print()
	{
		if(next > 0)
		{
			for(int i = 0; i < next; i++)
			{
				cout << " * " << list[i] << endl;
			}			
		}
		else
		{
			for(int i = 0; i < numberOfLines; i++)
			{
				cout << " * " << list[i] << endl;
			}
		}

	}