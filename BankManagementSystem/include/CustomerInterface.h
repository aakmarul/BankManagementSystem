#ifndef CUSTOMERINTERFACE_H
#define CUSTOMERINTERFACE_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Account.h"

class CustomerInterface
{
    public:
        CustomerInterface();
        virtual ~CustomerInterface();

        typedef enum USER_CHOICE
        {
            NO_CHOICE = 0,
            CREATE_NEW_ACCOUNT = 1,
            SHOW_ACCOUNT_DETAILS = 2,
            DEPOSIT_MONEY = 3,
            WITHDRAW_MONEY = 4,
            EXIT = 5,
            INVALID_INPUT = 6
        }USER_CHOICE;

        void static initializeCustomerInterfaceSystem();

        void AccountCreatorInterface(Account* account);

        USER_CHOICE getUserInputs();

        bool checkInputisInteger(std::string);

        bool getInvalidInputFlag()
        {
            return m_invalidInputFlag;
        }

        void setInvalidInputFlag(bool flag)
        {
            m_invalidInputFlag = flag;
        }

    protected:

    private:
        //FLAGS
        bool m_invalidInputFlag;
        ///////
        int op;
};

#endif // CUSTOMERINTERFACE_H
