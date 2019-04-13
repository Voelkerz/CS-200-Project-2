//Banker_Util.cpp
#include "Banker_Util.h"
Banker_Util::Banker_Util()
{
	
}

bool Banker_Util::menu(int currentUser, User* userList[], int userMax, int userPos, Customer* custList, int maxCust)
{
	int option;
	double amount;
	string password, id, id2;
	do {
	system("CLS");
	cout << "\t\tBanker Utility\n"
		 << "\t\t==============\n"
		 << "\t1. Change password of account\n"
		 << "\t2. Deposit to customer account\n"
		 << "\t3. Withdraw from customer account\n"
		 << "\t4. Transfer funds\n"
		 << "\t5. Exit\n"
		 << "Enter an option: ";
	cin >> option;
	system("CLS");
	
	switch (option)
	{
		case 1:
		//	Admin_Util::fromLoginFile(userList);
	    	cout <<"Enter new password: ";
	    	cin >>password;
	    //	userList[currentUser]->loginInfo.setPassword(password);
	    //	Admin_Util::toLoginFile(userList, userPos);
	    	break;
		case 2:
			//Depost to Customer account
			system("CLS");
			cout << "Enter the id of the customer: ";
			cin >> id;
			for (int i = 0; i < maxCust; i++)
			{
				if (custList[i].getID() == id)
					{
						cout << custList[i].getName() << "Account\n"
							 << "==================================\n"
							 << "Enter the deposit amount: ";
						cin >> amount;
						Transactions::deposit(custList, userPos, userMax, id, amount);
						cout << "\nTransaction succesful"
						 	 << "\nAccount Balance: " << custList[i].acc[0].getBalance();
					};
			};
			break;
		case 3:
			//Withdraw from Customer account
			system("CLS");
			cout << "Enter the id of the customer: ";
			cin >> id;
			for (int i = 0; i < maxCust; i++)
			{
				if (custList[i].getID() == id)
				{
					cout << custList[i].getName() << "Account\n"
						 <<"==================================\n"
						 << "Enter the withdraw amount: ";
					cin >> amount;
					/*if (amount > userList[i]->acc.getBalance())
					{
						cout << "\nERROR: NOT ENOUGH FUNDS";
					};
					else
					{*/
					Transactions::withdraw(custList, userPos, maxCust, id, amount);
					cout << "\nTransaction succesful"
						 << "\nAccount Balance: " << custList[i].acc[0].getBalance();
					//};
				};
			};
			break;
		case 4:
			//Transfer funds between Customer accounts
			system("CLS");
			cout << "Enter the id of the customer that is transfering the funds: ";
			cin >> id;
			cout << "\nEnter the amount that is being transfered: ";
			cin >> amount;
			cout << "\nEnter the id of the customer that is receiving the funds: ";
			cin >> id2;
			for (int i = 0; i < maxCust; i++)
			{
				if (custList[i].getID() == id)
				{
					if (amount > custList[i].acc[0].getBalance())
					{
						cout << "\nERROR: NOT ENOUGH FUNDS";
					}
					else
					{
						Transactions::withdraw(custList, userPos, maxCust, id, amount);
					};
				};
			};
			for (int i = 0; i < maxCust; i++)
			{
				if (custList[i].getID() == id2)
				{
					Transactions::deposit(custList, userPos, maxCust, id2, amount);
				};
			};
			cout << "\nTransfer Succesful";
			break;
		case 5:
			system("CLS");
			cout << "Good Bye !!";
			break;
		default:
			system("CLS");
			cout << "ERROR: INVALID OPTION";			
	}
} while (option != 5);
	return false;
};
