#include "Bank.h"

Bank::Bank()
{
    //Call the Customer Interface and Account classes
    Bank::setAccount(new Account());
    Bank::setCustomerInterface(new CustomerInterface);
}

Bank::~Bank()
{
    //dtor
}

void Bank::initializeBankSystem()
{
    //First clear the console screen
    //system("cls");

    //First call interface system
    m_customerInterface->initializeCustomerInterfaceSystem();

    CustomerInterface::USER_CHOICE userChoice = CustomerInterface::NO_CHOICE;
    while(m_customerInterface->getInvalidInputFlag() == true)
    {
        userChoice = m_customerInterface->getUserInputs();
    }
    //Later call the execute and seperate initialization and functional operations
    //TODO Bank::execute(userChoice)
    m_customerInterface->setInvalidInputFlag(true); //Flag set true to call interface later again take user inputs
    callTheOperations(userChoice);

}

void Bank::callTheOperations(CustomerInterface::USER_CHOICE userChoice)
{
    switch(userChoice)
    {
    case CustomerInterface::NO_CHOICE:
    case CustomerInterface::INVALID_INPUT:
        std::cout<<"This is an ERROR case! Operation shutting down!"<<std::endl; //TODO: implement shut down operation
        break;
    case CustomerInterface::CREATE_NEW_ACCOUNT:
        createNewAccount();
        break;
    case CustomerInterface::SHOW_ACCOUNT_DETAILS:
        std::cout<<"Showing account details"<<std::endl; //TODO implement show account details method
        showAccountDetails();
        break;
    case CustomerInterface::DEPOSIT_MONEY:
        std::cout<<"Enter the money to deposit"<<std::endl; //TODO implement deposit money input and deposit methods
        break;
    case CustomerInterface::WITHDRAW_MONEY:
        std::cout<<"Enter the money withdraw"<<std::endl; //TODO implement withdraw money input and withdraw methods
        break;
    case CustomerInterface::EXIT:
        std::cout<<"Exiting"<<std::endl; //TODO implement exit operation
    default:
        break;

    }
}

void Bank::showAccountDetails()
{
    std::string ssNumber; 
    ssNumber = this->m_customerInterface->ShowAccountDetailsInterface();
    readAccountDetails(ssNumber);
    std::cout<<"Social Security Number: "<<this->getAccount().getSocialSecurityNumber()<<
                "\tCash: "<<this->getAccount().getCash()<<"\tName: "<<this->getAccount().getCustomerName()<<
                "\tSurname: "<<this->getAccount().getCustomerSurname()<<std::endl;
}

void Bank::readAccountDetails(std::string ssNumber)
{
    std::ifstream file;
    std::string path = accountPath+ssNumber+".txt";

    std::string details;

    file.open(path);
    if(!file)
    {
        std::cout<<"THERE IS NO RECORD RELATED WITH THESE SSNUMBER"; //TODO validate ssNumber is suitable or not? 9-digit integer.
    }
    else
    {
        std::string name;
        std::string surname;
        float cash;

        file >> ssNumber >> cash >> name >> surname; 
        //std::getline(file, details);
        std::cout<<"Social Security Number: "<<ssNumber<<"\tCash: "<<cash<<"\tName: "<<name<<"\tSurname: "<<surname<<std::endl;
        this->getAccount().setSocialSecurityNumber(ssNumber);
        this->getAccount().setCash(cash);
        this->getAccount().setCustomerName(name);
        this->getAccount().setCustomerSurname(surname);
    }

    file.close();
}

void Bank::createNewAccount()
{
    //Receive the necessary information from customer to open new account
    m_customerInterface->AccountCreatorInterface(m_account);
    //All information received
    //Check entered social security number has an account or not, If there is return error and asks to load existing account
    std::string ssNumber = m_account->getSocialSecurityNumber();
    if(checkAccountExistence(ssNumber)) //if this returns true we can create the new account.
    {
        system("cls");
        std::cout<<"NEW ACCOUNT CREATED!"<<std::endl;
        initializeBankSystem();
    }
    else
    {
        system("cls");
        std::cout<<"Account Already Exist!"<<std::endl;
        initializeBankSystem();
    }


}

bool Bank::checkAccountExistence(std::string str)
{
    std::fstream file;

    std::string path= accountPath + str + ".txt";

    file.open(path);

    if(!file)
    {
        //if file does not exist we can create it! First close the input file object
        file.open(path, std::fstream::in | std::fstream::out | std::fstream::trunc);

        //Then fill the informations
        file <<m_account->getSocialSecurityNumber()<<"\t"<<m_account->getCash()<<"\t"
            <<m_account->getCustomerName()<<"\t"<<m_account->getCustomerSurname();
        file.close();
        return true;
    }
    else{
        return false;
    }
}
