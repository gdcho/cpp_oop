#include <iostream>

using namespace std;

class Account
{ public: virtual ~Account() { } };

class BankAccount : public virtual Account
{ public: virtual ~BankAccount() { } };

class OnlineAccount : public virtual Account
{ public: virtual ~OnlineAccount() { } };

class ChequingAccount : public BankAccount, public OnlineAccount
{ public: virtual ~ChequingAccount() { } };

class SavingsAccount : public BankAccount, public OnlineAccount 
{public: virtual ~SavingsAccount() { } };

int main()
{
	Account a;
	BankAccount b;
	OnlineAccount o;
	ChequingAccount c;
	SavingsAccount s;

	Account * account_pointer = dynamic_cast<Account *>(&c); // Pointer upcast
	account_pointer = dynamic_cast<Account *>(&b); // Pointer upcast
	account_pointer = dynamic_cast<Account *>(&o); // Pointer upcast
	account_pointer = &c; // Upcasting implictly. will &a work?

	try
	{
		OnlineAccount * oa = dynamic_cast<OnlineAccount *>(&s); // Pointer upcast
		SavingsAccount * sa = dynamic_cast<SavingsAccount *>(oa);  // Pointer downcast

		BankAccount * ba = dynamic_cast<BankAccount *>(&c); // Pointer upcast
		oa = dynamic_cast<OnlineAccount *>(ba); // Pointer cross cast!

        //---ERROR scenarios---
        //o is an online account object, SavingsAccount pointer should not be able to point to it
        SavingsAccount *saPtr = dynamic_cast<SavingsAccount *>(&o);
        if(saPtr == nullptr) {
            cout << "downcast fail" << endl;
        }
        else
        {
            cout << "downcast success" << endl;
        }
		//SavingsAccount &saRef = dynamic_cast<SavingsAccount &>(o); //trying to cast online account to savings account. ERROR - throws bad cast exception
        //SavingsAccount &saCCast = (SavingsAccount &)o; //C-style downcast of online account to savings account. No compiler error, but result is undefined
	}
		catch ( const std::exception& e )
	{
		cerr << e.what();
	}


	return 0;
}