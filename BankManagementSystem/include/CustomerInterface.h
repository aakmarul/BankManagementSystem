#ifndef CUSTOMERINTERFACE_H
#define CUSTOMERINTERFACE_H

#include <iostream>

class CustomerInterface
{
    public:
        CustomerInterface();
        virtual ~CustomerInterface();

        void static initializeCustomerInterfaceSystem();
        void getUserInputs();

        bool getInvalidInputFlag()
        {
            return m_invalidInputFlag;
        }

    protected:

    private:
        //FLAGS
        bool m_invalidInputFlag;

        int op;
};

#endif // CUSTOMERINTERFACE_H
