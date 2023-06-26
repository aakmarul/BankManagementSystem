#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
    public:
        Account();
        virtual ~Account();

        std::string getSocialSecurityNumber() const
        {
            return m_socialSecurityNumber;
        }

        void setSocialSecurityNumber(std::string socialSecurityNumber)
        {
             m_socialSecurityNumber = socialSecurityNumber;
        }

        std::string getCustomerName()
        {
            return m_name;
        }

        void setCustomerName(std::string name)
        {
            m_name = name;
        }

        std::string getCustomerSurname()
        {
            return m_surName;
        }

        void setCustomerSurname(std::string customerSurname)
        {
            m_surName = customerSurname;
        }

        double getCash() const
        {
            return m_cash;
        }

        void setCash(double newCash)
        {
            m_cash = newCash;
        }

    private:
        std::string m_socialSecurityNumber;
        std::string m_name;
        std::string m_surName;
        double m_cash;
};

#endif // ACCOUNT_H
