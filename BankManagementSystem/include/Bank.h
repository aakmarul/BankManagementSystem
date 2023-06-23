#ifndef BANK_H
#define BANK_H

#include <Account.h>
#include <CustomerInterface.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>

class Bank
{
    public:
        Bank();
        virtual ~Bank();

        const std::string accountPath = "C:\\CodeblocksWorkspace\\BankManagementSystem\\src\\accounts\\";

        void initializeBankSystem();

        void callTheOperations(CustomerInterface::USER_CHOICE);

        void createNewAccount();

        void showAccountDetails();

        void readAccountDetails(std::string);

        bool checkAccountExistence(std::string);

        void setAccount(Account* account)
        {
            m_account = account;
        }

        Account getAccount()
        {
            return *m_account;
        }

        void setCustomerInterface(CustomerInterface* customerInterface)
        {
            m_customerInterface = customerInterface;
        }

        CustomerInterface getCustomerInterface()
        {
            return *m_customerInterface;
        }

    protected:

    private:
         Account* m_account;
         CustomerInterface* m_customerInterface;
};

#endif // BANK_H
