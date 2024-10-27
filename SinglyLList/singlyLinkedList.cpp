#include<iostream>
#include<string>
using namespace std;

struct Node {
public:
	int info;
	Node* next;

};
class LinkedList {
private:
	Node* head=nullptr;
	Node* tail=nullptr;
public:
	void insertionAtStart(int data)
	{
		Node* newNode = new Node();//info set
		newNode->info = data;

		if (isEmpty())
		{
			newNode->next = nullptr;
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}
	void insertAtEnd(int data)
	{
		Node* newNode = new Node();
		newNode->info = data;
		newNode->next = nullptr;


		if (isEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	
	}
	void insertAfter(int data,int position)
	{
		if (position < 1)
		{
			cout << "Invalid Position\n";
			return;
		}
		if (isEmpty())
		{
			cout << "List is Empty!"<<endl;
			return ;
		}
		Node* newNode = new Node();//info set
		newNode->info = data;
		Node* currentptr = head;
		int currentposition = 1;
		while (currentptr && currentposition < position)
		{
			currentptr = currentptr->next;
			currentposition++;
		}
		if (currentptr == nullptr)  // position out of range
		{
			cout << "Position out of range\n";
			delete newNode;  
			return;
		}
		newNode->next = currentptr->next;
		currentptr->next = newNode;
		if (newNode->next == nullptr)
		{
			tail = newNode;
		}
		
	}
	int deletionAtStart()
	{

		if (isEmpty())
		{
			cout << "List is Empty\n";
			return -1;
		}
		int data;
		Node* temp=head;
		data = head->info;
		head = head->next;
		delete temp;
		return data;
	}
	int deletionAtEnd() {

		if (isEmpty()) {
			cout << "List is Empty\n";
			return -1;
		}
		int data = tail->info;  
		Node* temp = tail;  
		if (head == tail) {
			head = tail = nullptr;  
			delete temp;  
			return data;
		}

		Node* currentptr = head;
		while (currentptr->next != tail) {
			currentptr = currentptr->next;
		}

		tail = currentptr;
		tail->next = nullptr;  
		delete temp;  
		return data;
	}

	int deleteAfter(int position)
	{
		if  (isEmpty())
		{
			cout << "List is Empty\n";
			return -1;
		}
		Node* currentptr=head;
		int currentposition = 1;
		while (currentptr && currentposition<position)
		{
			currentptr = currentptr->next;
			currentposition++;
		}
		if (currentptr==nullptr || currentptr->next == nullptr)
		{
			cout << "\nCant Delete anything after tail\n";
			return -1;
		}
		Node* temp = currentptr->next;
		int saveData = temp->info;
		currentptr->next = temp->next;

		if (temp->next == nullptr)
		{
			tail = currentptr;
			currentptr ->next = nullptr;
		}
		delete temp;
		return saveData;
	}
	bool isEmpty()
	{
		if (head == nullptr)
		{
			return true;
		}

		else
		return false;
	}
	void printList() {
		cout << "\nList:\n";
		if (isEmpty()) { cout << "List is Empty!"; }

		Node* curr = head;
		int i = 1;
		while (curr != nullptr) {
			cout << i << ". ";
			cout<< curr->info << " " << endl;
			curr = curr->next;
			i++;
		}
		cout << endl;
	}
	~LinkedList()
	{ 
		while (!isEmpty()) 
		{
			deletionAtStart();
		}
	}
};

int main()
{
	LinkedList sllist;
	string option;
	sllist.printList();

	cout << "******** Choose Options from the following: *********"<< endl;
	do
	{
		cout << "Enter\n1.Insertion at Start.\n2.Insert in Middle\n3.Insert at Tail\n4.Delete from Head\n5.Delete from Middle\n6.Delete from Tail\nEnter no to exit: ";
		getline(cin, option);
		if(option=="no")
		{
				cout << "Exiting \n";
				break;
		}
		else if (option == "1")
		{
			int value=0;
			cout << "Enter Value of NewNode: ";
			while (true)
			{
				if (cin >> value)
				{
					if (value > 0)//terminating condition
					{
						break;
					}
					else
					{
						cout << "Error: Enter a positive integer: " << endl;
					}
				}
				else
				{
					cout << "Error: Enter a valid integer: " << endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
			}
		
			sllist.insertionAtStart(value);
			sllist.printList();

		}
		else if (option == "2")
		{
			int value = 0,position=0;
			cout << "Enter Value: ";
			while (true)
			{
				if (cin >> value)
				{
					if (value > 0)
					{
						break;
					}
					else
					{
						cout << "Error: Enter a positive integer: " << endl;
					}
				}
				else
				{
					cout << "Error: Enter a valid integer: " << endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
			}
			cout << "Enter Position: ";
			while (true)
			{
				if (cin >> position)
				{
					if (position > 0)
					{
						break;
					}
					else
					{
						cout << "Error: Enter a positive integer: " << endl;
					}
				}
				else
				{
					cout << "Error: Enter a valid integer: " << endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
			}			sllist.insertAfter(value, position);
			sllist.printList();

		}
		else if (option == "3")
		{
			int value = 0;
			cout << "Enter Value of New Tail: ";
			while (true)
			{
				if (cin >> value)
				{
					if (value > 0)
					{
						break;
					}
					else
					{
						cout << "Error: Enter a positive integer: " << endl;
					}
				}
				else
				{
					cout << "Error: Enter a valid integer: " << endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
			}			sllist.insertAtEnd(value);
			sllist.printList();

		}
		else if (option == "4")
		{
			cout << "Deleting from Head: \n";
			cout<<"Deleted Node had Info = "<<sllist.deletionAtStart()<<endl;
			sllist.printList();
		}
		else if (option == "5")
		{
			int position = 0;
			cout << "Enter Position of the Node After which you want to delete: ";
			while (true)
			{
				if (cin >> position)
				{
					if (position > 0)
					{
						break;
					}
					else
					{
						cout << "Error: Enter a positive integer: " << endl;
					}
				}
				else
				{
					cout << "Error: Enter a valid integer: " << endl;
					cin.clear();
					cin.ignore(123, '\n');
				}
			}			cout << "Deleted Node had Info = " <<sllist.deleteAfter(position)<<endl;
			sllist.printList();

		}
		else if (option == "6")
		{
			cout << "Deleting from tail: \n";
			cout << "Deleted Node had Info = " << sllist.deletionAtEnd();
			sllist.printList();
		}
		else if (option == "no")
		{
			return 0;
		}
		else
		{
			cout << "Invalid Option!";
        }
		cin.ignore();
	} while (option != "no");

	return 0;
}