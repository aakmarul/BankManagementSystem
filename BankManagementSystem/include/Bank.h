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

        typedef enum TRANSACTION_TYPE{
            DEPOSIT = 0,
            WITHDRAW = 1
        }TRANSACTION_TYPE;

        void initializeBankSystem();

        void callTheOperations(CustomerInterface::USER_CHOICE);

        void createNewAccount();

        void showAccountDetails();

        void makeTransaction(TRANSACTION_TYPE);

        void executeTransactionProcess(TRANSACTION_TYPE);

        void writeNewInformationToAccount();

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

        CustomerInterface::USER_CHOICE getUserChoice()
        {
            return m_userChoice;
        }

        void setUserChoice(CustomerInterface::USER_CHOICE userChoice)
        {
            m_userChoice = userChoice;
        }

    protected:

    private:
        CustomerInterface::USER_CHOICE m_userChoice;
         std::string ssNumber;
         Account* m_account;
         CustomerInterface* m_customerInterface;
};

#endif // BANK_H
