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

        typedef enum PROCESS_STATUS{
            INVALID_CHOICE,
            NEW_ACCOUNT_CREATED,
            ACCOUNT_ALREADY_EXIST,
            ACCOUNT_CREATION_FAILED,
            ACCOUNT_DOES_NOT_FOUND,
            ACCOUNT_DETAILS_SHOWED,
            MONEY_DEPOSITED,
            MONEY_WITHDRAWN,
            MONEY_GREATER_THAN_ACC_CASH,
            EXIT_THE_SYSTEM
        }PROCESS_STATUS;

        PROCESS_STATUS run();

        PROCESS_STATUS callTheOperations(CustomerInterface::USER_CHOICE);

        PROCESS_STATUS createNewAccount();

        PROCESS_STATUS showAccountDetails();

        PROCESS_STATUS makeTransaction(TRANSACTION_TYPE);

        PROCESS_STATUS executeTransactionProcess(TRANSACTION_TYPE);

        void writeNewInformationToAccount();

        PROCESS_STATUS readAccountDetails(std::string);

        PROCESS_STATUS checkAccountExistence(std::string);

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

        CustomerInterface* getCustomerInterface()
        {
            return m_customerInterface;
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
