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

    //CustomerInterface::USER_CHOICE userChoice = CustomerInterface::NO_CHOICE;
    while(m_customerInterface->getInvalidInputFlag() == true)
    {
        setUserChoice(m_customerInterface->getUserInputs());
    }
    //Later call the execute and seperate initialization and functional operations
    //TODO Bank::execute(userChoice)
    m_customerInterface->setInvalidInputFlag(true); //Flag set true to call interface later again take user inputs
    callTheOperations(getUserChoice());

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
        std::cout<<"Showing account details"<<std::endl;
        showAccountDetails();
        break;
    case CustomerInterface::DEPOSIT_MONEY:
        std::cout<<"Enter the money to deposit"<<std::endl; //TODO implement deposit money input and deposit methods
        makeTransaction(DEPOSIT);
        break;
    case CustomerInterface::WITHDRAW_MONEY:
        std::cout<<"Enter the money withdraw"<<std::endl; //TODO implement withdraw money input and withdraw methods
        makeTransaction(WITHDRAW);
        break;
    case CustomerInterface::EXIT:
        std::cout<<"Exiting"<<std::endl; //TODO implement exit operation
    default:
        break;

    }
}

void Bank::makeTransaction(TRANSACTION_TYPE ttype)
{
    ssNumber = this->m_customerInterface->ShowAccountDetailsInterface();
    readAccountDetails(ssNumber);
    executeTransactionProcess(ttype);
}

void Bank::executeTransactionProcess(TRANSACTION_TYPE ttype)
{
    if(ttype == DEPOSIT) //
    {
        double money;
        
        system("cls");
        std::cout<<"Enter the money to deposit your account!"<<std::endl;
        std::cout<<">> ";
        std::cin>> money; //TODO check money is valid double format or not?
        m_account->setCash(m_account->getCash() + money);
        std::cout<<"The new cash is :"<<m_account->getCash()<<std::endl;
        writeNewInformationToAccount();
    }
    else //WITHDRAW operation
    {
        double money; 

        //system("cls");
        std::cout<<"Enter the money withdraw from your account!"<<std::endl;
        std::cout<<">> ";
        std::cin>> money; //TODO check money is valid double format or not?
        if(money > m_account->getCash())
        {
            //TODO throw error/warning. Entered money cannot be greater than cash value of the related account
            system("cls");
            std::cout<<"The amount to be withdrawn cannot be higher than the cash value in the account."<<std::endl;
            //callTheOperations(CustomerInterface::WITHDRAW_MONEY); This pass eill be studied for now it ends the program.
        }
        else{
            m_account->setCash(m_account->getCash()-money);
            std::cout<<"The new cash is :"<<m_account->getCash()<<std::endl;
            writeNewInformationToAccount();
        }
    }
}

void Bank::writeNewInformationToAccount()
{
    std::ofstream file; //opening ofstream file without ios::app flag erase all the info's in the .txt file.
    std::string path = accountPath+m_account->getSocialSecurityNumber()+".txt";

    file.open(path);
    file<< m_account->getSocialSecurityNumber()<<"\t" << m_account->getCash() <<"\t"<<
        m_account->getCustomerName() <<"\t"<< m_account->getCustomerSurname();
}

void Bank::showAccountDetails()
{
    ssNumber = this->m_customerInterface->ShowAccountDetailsInterface();
    readAccountDetails(ssNumber);
    std::cout<<"Social Security Number: "<<m_account->getSocialSecurityNumber()<<
                "\tCash: "<<this->getAccount().getCash()<<"\tName: "<<this->getAccount().getCustomerName()<<
                "\tSurname: "<<this->getAccount().getCustomerSurname()<<std::endl;
}

void Bank::readAccountDetails(std::string ssNumber)
{
    std::ifstream file;
    std::string path = accountPath+ssNumber+".txt";

    file.open(path);
    if(!file)
    {
        std::cout<<"THERE IS NO RECORD RELATED WITH THESE SSNUMBER"; //TODO validate ssNumber is suitable or not? 9-digit integer.
    }
    else
    {
        std::string name;
        std::string surname;
        double cash;

        file >> ssNumber >> cash >> name >> surname;
        //std::getline(file, details);
        //std::cout<<"Social Security Number: "<<ssNumber<<"\tCash: "<<cash<<"\tName: "<<name<<"\tSurname: "<<surname<<std::endl;
        // TODO asagisi calismiyor incele daah sonra eclipse debug ile.
        //std::cout<<"Buradan sonra bozuyor."<<std::endl;
        /*
        this->getAccount().setSocialSecurityNumber(ssNumber);
        this->getAccount().setCash(cash);
        this->getAccount().setCustomerName(name);
        this->getAccount().setCustomerSurname(surname);
        */
        m_account->setSocialSecurityNumber(ssNumber);
        m_account->setCash(cash);
        m_account->setCustomerName(name);
        m_account->setCustomerSurname(surname);
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
        //initializeBankSystem(); upper class or main must be call this !!!!!
    }
    else
    {
        system("cls");
        std::cout<<"Account Already Exist!"<<std::endl;
        //initializeBankSystem(); upper class or main must be call this !!!!!
    }


}

bool Bank::checkAccountExistence(std::string str)
{
    std::fstream file;

    std::string path= accountPath + str + ".txt";

    file.open(path);

    if(!file)
    {
        //if file does not exist and userChoice is CREATE_ACCOUNT we can create it!
        if(getUserChoice() == CustomerInterface::CREATE_NEW_ACCOUNT)
        {
            file.open(path, std::fstream::in | std::fstream::out | std::fstream::trunc);

            //Then fill the informations
            file <<m_account->getSocialSecurityNumber()<<"\t"<<m_account->getCash()<<"\t"
                <<m_account->getCustomerName()<<"\t"<<m_account->getCustomerSurname();
            file.close();
        }
        else //Another operations are selected such as DEPOSIT, WITHDRAW
        {
            std::cout<<"There is no account related with given Social Security Number"<<std::endl;
        }

        return true;
    }
    else{
        file.close();
        return false;
    }
}
