#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class bankaccount
{
public:
	char banktype;
	char name[99];
	int accountnumber;
	int deposit;

public:
	void create_account();
	void showmy_account() const;
	int return_accountnumber() const;
	void depositformula(int);
	void withdrawformula(int);
	void transferformula(int, int);
	int return_deposit() const;
	char return_banktype() const;
	void complete_table() const;
	void edit();
};

void bankaccount::create_account()
{
	cout << "\n\t*********************************";
	cout << "\n\t*                               *";
	cout << "\n\t*      CREATING AN ACCOUNT      *";
	cout << "\n\t*                               *";
	cout << "\n\t*********************************";
	cout << "\n\tEnter type of bank account \n\t (Type: S-savings/C- current): ";
	cin >> banktype;
	cout << "\n\n\t\t\t\tEnter account no. : ";
	cin >> accountnumber;
	cout << "\n\n\t\t\t\tEnter account holder name : ";
	cin.ignore();
	cin.getline(name, 99);
	cout << "\n\n\t\t\t\tEnter the initial amount(min. 250 saving, 3000 current) : ";
	cin >> deposit;
	cout << " " << endl;
	cout << "\n\n\t\t\t\tAccount has successfully created...";
}
void bankaccount::showmy_account() const
{
	cout << "\n\n\t\t\t\tAccount number: " << accountnumber;
	cout << "\n\n\t\t\t\tAccount holder name: " << name;
	cout << "\n\n\t\t\t\tAccount type: " << banktype;
	cout << "\n\n\t\t\t\tBalance amount: " << deposit;
}

void write_account_toFiles()
{
	bankaccount a;
	ofstream myFile;
	myFile.open("bank.txt", ios::binary | ios::app);
	a.create_account();
	myFile.write(reinterpret_cast<char *>(&a), sizeof(bankaccount));
	myFile.close();
}
int bankaccount::return_accountnumber() const
{
	return accountnumber;
} // assurance acnumber is constact
void bankaccount::depositformula(int Amount)
{
	deposit = deposit + Amount;
} // deposit
void bankaccount::withdrawformula(int Amount)
{
	deposit = deposit - Amount;
} // withdraw
void bankaccount::edit()
{
	cout << "\n\n\t\t\t\tNew account number: " << accountnumber;
	cout << "\n\n\t\t\t\tChange Account name: ";
	cin.ignore();
	cin.getline(name, 99);
	cout << "\n\n\t\t\t\tChange Account Type(S/C): ";
	cin >> banktype;
	cout << "\n\n\t\t\t\tChange Account Balance: ";
	cin >> deposit;
} // edit/change account
void bankaccount::complete_table() const
{
	cout << accountnumber << setw(10) << " " << name << setw(10) << " " << banktype << setw(8) << deposit << endl;
}
void bankaccount::transferformula(int receiver, int amount)
{
	bankaccount a;
	bool meet = false;
	fstream myFile;
	myFile.open("bank.txt", ios::binary | ios::in | ios::out);
	if (!myFile)
	{
		cout << "\n\n\t\t\t\t\tError: File could not be identified or reopened." << endl;
		cout << "\n\n\t\t\t\t\tPress ENTER key to continue...";
		return;
	}
	while (!myFile.eof() && meet == false)
	{
		myFile.read(reinterpret_cast<char *>(&a), sizeof(bankaccount));
		if (a.return_accountnumber() == receiver)
		{
			if (receiver == receiver)
			{
				int balance = a.return_deposit() + amount;
				// error minimum balance
				if ((balance < 250 && a.return_banktype() == 'S') || (balance < 3000 && a.return_banktype() == 'C'))
				{
					cout << "\n\n\t\t\t\tNot Enough Balance..";
				}
				else
				{
					a.depositformula(amount);
				}
			}
			int position = (-1) * static_cast<int>(sizeof(a));
			myFile.seekp(position, ios::cur); // to current position
			myFile.write(reinterpret_cast<char *>(&a), sizeof(bankaccount));
			cout << "\n\n\t\t\t\tBalance Updated... ";
			meet = true;
		}
	} // while
	myFile.close();
	if (meet == false)
	{
		cout << "\n\n\t\t\t\tFailed: Incorrect information...";
	}
} // transfer money
int bankaccount::return_deposit() const
{
	return deposit;
} // assurance deposit is constant

char bankaccount::return_banktype() const
{
	return banktype;
} // assurance banktype is constant

void depowith_account(int number0, int zero)
{
	int amount;
	bankaccount a;
	bool meet = false;
	fstream myFile;
	myFile.open("bank.txt", ios::binary | ios::in | ios::out);
	if (!myFile)
	{
		cout << "\n\n\t\t\t\t\tError: File could not be identified or reopened." << endl;
		cout << "\n\n\t\t\t\t\tPress ENTER key to continue...";
		return;
	}
	while (!myFile.eof() && meet == false)
	{
		myFile.read(reinterpret_cast<char *>(&a), sizeof(bankaccount));
		if (a.return_accountnumber() == number0)
		{
			system("cls");
			if (zero == 0)
			{
				cout << "\n\t\t\t\t=======================================================";
				cout << "\n\t\t\t\t\t DEPOSIT FORM ";
				cout << "\n\n\t\t\t\t=======================================================";
			}
			else if (zero == 1)
			{
				cout << "\n\t\t\t\t=======================================================";
				cout << "\n\t\t\t\t\t WITHDRAW FORM ";
				cout << "\n\n\t\t\t\t=======================================================";
			}
			a.showmy_account();
			// deposit option
			if (zero == 0)
			{

				cout << "\n\n\t\t\t\tAmount to deposit: ";
				cin >> amount;
				a.depositformula(amount);
			} // withdraw option
			if (zero == 1)
			{
				cout << "\n\n\t\t\t\tAmount to withdraw: ";
				cin >> amount;
				int balance = a.return_deposit() - amount;
				// error minimum balance
				if ((balance < 250 && a.return_banktype() == 'S') || (balance < 3000 && a.return_banktype() == 'C'))
				{
					cout << "\n\n\t\t\t\tNot Enough Balance..";
				}
				else
				{
					a.withdrawformula(amount);
				}
			}
			int position = (-1) * static_cast<int>(sizeof(a));
			myFile.seekp(position, ios::cur); // to current position
			myFile.write(reinterpret_cast<char *>(&a), sizeof(bankaccount));
			cout << "\n\n\t\t\t\tBalance Updated... ";
			meet = true;
		}
	} // while
	myFile.close();
	if (meet == false)
	{
		cout << "\n\n\t\t\t\tFailed: Incorrect information...";
	}
} // void deposit withdraw function

void balanceInquiry(int number)
{
	bankaccount a;
	bool meet = false;
	ifstream myFile;
	myFile.open("bank.txt", ios::binary | ios::in);
	if (!myFile)
	{
		cout << "\n\n\t\t\t\tERROR: File could not be retrieved." << endl;
		cout << "\n\n\t\t\t\tPress ENTER key to continue...";
		return;
	}
	while (myFile.read(reinterpret_cast<char *>(&a), sizeof(bankaccount)))
	{
		if (a.return_accountnumber() == number)
		{
			system("cls");
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\t\t\t\t\t BALANCE INQUIRY FORM ";
			cout << "\n\n\t\t\t\t=======================================================";
			a.showmy_account();
			meet = true;
		}
	}
	myFile.close();
	if (meet == false)
	{
		cout << "\n\n\t\t\t\tERROR: Account number doesn't match...";
	}
	return;
} // void balance inquiry

void transfer_money(int number0)
{
	int amount, receiver;
	bankaccount a;
	bool meet = false;
	fstream myFile;
	myFile.open("bank.txt", ios::binary | ios::in | ios::out);
	if (!myFile)
	{
		cout << "\n\n\t\t\t\t\tError: File could not be identified or reopened." << endl;
		cout << "\n\n\t\t\t\t\tPress ENTER key to continue...";
		return;
	}
	while (!myFile.eof() && meet == false)
	{
		myFile.read(reinterpret_cast<char *>(&a), sizeof(bankaccount));
		if (a.return_accountnumber() == number0)
		{

			a.showmy_account();
			if (number0 == number0)
			{
				cout << "\n\n\t\t\t\tAccount number of the receiver: ";
				cin >> receiver;
				cout << "\n\n\t\t\t\tAmount to transfer: ";
				cin >> amount;
				a.transferformula(receiver, amount);
				int balance = a.return_deposit() - amount;
				// error minimum balance
				if ((balance < 250 && a.return_banktype() == 'S') || (balance < 3000 && a.return_banktype() == 'C'))
				{
					cout << "\n\n\t\t\t\tNot Enough Balance..";
				}
				else
				{
					a.withdrawformula(amount);
				}
			}
			int position = (-1) * static_cast<int>(sizeof(a));
			myFile.seekp(position, ios::cur); // to current position
			myFile.write(reinterpret_cast<char *>(&a), sizeof(bankaccount));
			cout << "\n\n\t\t\t\tBalance Updated... ";
			meet = true;
		}
	} // while
	myFile.close();
	if (meet == false)
	{
		cout << "\n\n\t\t\t\tFailed: Incorrect information...";
	}

} // void transfer money
void reportmy_completetable()
{
	bankaccount a;
	ifstream myFile;
	myFile.open("bank.txt", ios::binary);
	if (!myFile)
	{
		cout << "\n\n\t\t\t\t\tError: File could not be identified or reopened.";
		return;
	}
	cout << "\n\n\t ACCOUNT HOLDER MASTERLIST" << endl;
	cout << "\nAccount No. Name Type Balance\n";
	while (myFile.read(reinterpret_cast<char *>(&a), sizeof(bankaccount)))
	{
		a.complete_table();
	}
	myFile.close();
} // masterlist

void editaccount(int number)
{
	bankaccount a;
	bool meet = false;
	fstream myFile;
	myFile.open("bank.txt", ios::binary | ios::out | ios::in);
	if (!myFile)
	{
		cout << "\n\n\t\t\t\t\tError: File could not be identified or reopened.";
		return;
	}
	while (!myFile.eof() && meet == false)
	{
		myFile.read(reinterpret_cast<char *>(&a), sizeof(bankaccount));
		if (a.return_accountnumber() == number)
		{
			system("cls");
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\t\t\t\t\t EDIT/CHANGE ACCOUNT ";
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\n\t\t\t\t\tEnter new account informations: ";
			a.showmy_account();
			a.edit();
			int position = (-1) * static_cast<int>(sizeof(bankaccount));
			myFile.seekp(position, ios::cur);
			myFile.write(reinterpret_cast<char *>(&a), sizeof(bankaccount));
			cout << "\n\n\t\t\t\t\tAccount Updated... ";
			meet = true;
		}
	} // while
	myFile.close();
	if (meet == false)
	{
		cout << "\n\n\t\t\t\t\tAccount is invalid. Please kindly check your input... ";
	}
} // editaccount
void deleteaccount(int number)
{
	bankaccount a;
	ifstream myFile;
	ofstream omyFile;
	myFile.open("bank.txt", ios::binary);
	if (!myFile)
	{
		cout << "\n\n\t\t\t\t\tError: File could not be identified or reopened.";
		return;
	}
	omyFile.open("exbank.txt", ios::binary);
	myFile.seekg(0, ios::beg);
	while (myFile.read(reinterpret_cast<char *>(&a), sizeof(bankaccount)))
	{
		if (a.return_accountnumber() != number)
		{
			omyFile.write(reinterpret_cast<char *>(&a), sizeof(bankaccount));
		} // if
	} // while
	myFile.close();
	omyFile.close();
	remove("bank.txt");
	rename("exbank.txt", "bank.txt");
	cout << "\n\n\t\t\t\t\tRecord list updated...";
} // deleteaccount()

void welcome()
{
	cout << "\n\t*************MENU****************";
	cout << "\n\t*                               *";
	cout << "\n\t*          WELCOME USER         *";
	cout << "\n\t*                               *";
	cout << "\n\t*                               *";
	cout << "\n\t*   Press any key to continue   *";
	cout << "\n\t*                               *";
	cout << "\n\t*                               *";
	cout << "\n\t*                               *";
	cout << "\n\t*********************************";
	cout << " ";
	cin.get();
}
int menu()
{
	int select;
	cout << "\n\t *** PLEASE CHOOSE AN OPTION ***";
	cout << "\n\t\t\t\t\t ";
	cout << "\n\t 1. CREATE NEW ACCOUNT";
	cout << "\n\t 2  DEPOSIT MONEY";
	cout << "\n\t 3. WITHDRAW MONEY";
	cout << "\n\t 4. BALANCE INQUIRY";
	cout << "\n\t 5. TRANSFER MONEY TO OTHER ACCCOUNT";
	cout << "\n\t 6. ACCOUNT HOLDER MASTERLIST";
	cout << "\n\t 7. EDIT/CHANGE AN ACCOUNT";
	cout << "\n\t 8. DELETE AN ACCOUNT";
	cout << "\n\t 0. EXIT";
	cout << "\n\t\t\t\t\t  ";
	cout << "\n\t PRESS KEY (0-8): ";
	cin >> select;
	return select;
}
int main()
{
	int number;
	int fromMenu;
	// double number;
	welcome();
	system("cls");

	do
	{
		fromMenu = menu();
		system("cls");

		switch (fromMenu)
		{
		case 1:
			write_account_toFiles();
			break;
		case 2:
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\t\t\t\t\t DEPOSIT FORM ";
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\n\t\t\t\tEnter account no. : ";
			cin >> number;
			depowith_account(number, 0);
			break;
		case 3:
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\t\t\t\t\t WITHDRAW FORM ";
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\n\t\t\t\tEnter account no. : ";
			cin >> number;
			depowith_account(number, 1);
			break;
		case 4:
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\t\t\t\t\t BALANCE INQUIRY FORM ";
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\n\t\t\t\tEnter account no. : ";
			cin >> number;
			balanceInquiry(number);
			break;
		case 5:
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\t\t\t\t\t TRANSFER MONEY OPTION ";
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\n\t\t\t\tEnter account no. : ";
			cin >> number;
			transfer_money(number);
			break;
		case 6:
			reportmy_completetable();
			break;
		case 7:
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\t\t\t\t\t EDIT/CHANGE ACCOUNT ";
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\n\t\t\t\tEnter account no. : ";
			cin >> number;
			editaccount(number);
			break;
		case 8:
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\t\t\t\t\t DELETE ACCOUNT ";
			cout << "\n\t\t\t\t=======================================================";
			cout << "\n\n\t\t\t\tEnter account no. : ";
			cin >> number;
			deleteaccount(number);
			break;
		case 0:
			cout << "\n\t\t\t   Thank you for using our Bank!";
			cout << "\n\n\t\t\t	Customer Service no: +1123332211";
			break;
		default:
			cout << "\n\n\t\t\t\tERROR: Option key doesn't match... ";
		}
		cin.ignore();
		cin.get();
		system("cls");
	} while (fromMenu != 0);
	return 0;
}
