#include <iostream>
#include <string>


#include "ToDo.h"
using namespace std;

int main()
{
	char next = 'y';
	string item;
	ToDo list;

	while(next != 'x')
	{
		cout << "Add to list (a)" << endl;
		cout << "Done list item (d)" << endl;
		cout << "Print list (p)" << endl;
		cout << "Exit todo list app (x)" << endl;
		cout << "What do you want to do: ";
		cin >> next;

		switch(next)
		{
			case 'a':
				
				cout << "What do you want to add to the list: ";
				cin.ignore();
				getline(cin, item);
				list.add(item);
				break;
			case 'd':
				int itemNumber;
				cout << "Please enter the item you wish to mark done: ", cin >> itemNumber;
				itemNumber--;
				list.done(itemNumber);
				break;
			case 'p':
				list.print();
				break;
			//All done with the todo list
			case 'x':
				break;
		}
	}

	return 0;
}