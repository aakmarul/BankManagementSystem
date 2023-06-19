#include "Bank.h"

Bank::Bank()
{
    //Call the Customer Interface and Account classes
    setAccount(new Account());
    setCustomerInterface(new CustomerInterface);
}

Bank::~Bank()
{
    //dtor
}

void Bank::initializeBankSystem()
{
    //First call interface system
    m_customerInterface->initializeCustomerInterfaceSystem();
    while(m_customerInterface->getInvalidInputFlag() == true)
    {
        m_customerInterface->getUserInputs();
    }
}
