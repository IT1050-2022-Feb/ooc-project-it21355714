#include <iostream>
#include <cstring>
using namespace std;


class guestuser {                //GUESTUSER CLASS
protected:                       // BASE CLASS OF USER CLASS
    char name[20];
    char gender[20];
    char country[30];
    char dob[10];
    char email[30];

public:
    guestuser();
    guestuser(const char pname[], const char pgender[],
        const char pcountry[], const char pdob[], const char pemail[]) {
        strcpy_s(name, pname);
        strcpy_s(gender, pgender);
        strcpy_s(country, pcountry);
        strcpy_s(dob, pdob);
        strcpy_s(email, pemail);

    }

};

class bankaccount {             //BANK ACCOUNT CLASS
private:
    int accountno;
    char accountname[20];
    char bankname[20];
    char branchname[20];
    char country[20];

public:
    bankaccount(int paccountno, const char paccountname[], const char pbankname[], const char pbranchname[], const char ppcountry[]) {
        accountno = paccountno;
        strcpy_s(accountname, paccountname);
        strcpy_s(bankname, pbankname);
        strcpy_s(branchname, pbranchname);
        strcpy_s(country, ppcountry);

    }
    void display() {
        cout << "----------------BANK ACCOUNT DETAILS-----------" << endl;
        cout << "account number:" << accountno << endl;
        cout << "account name :" << accountname << endl;
        cout << "bank name :" << bankname << endl;
        cout << "branch name :" << branchname << endl;
        cout << "country : " << country << endl << endl;
    }

};

class user :public guestuser {          //USER CLASS 
private:                               //DERIVEDCLASS OF GUESTUSERCLASS
    char username[30];
    char userid[30];
    char userpw[30];
    bankaccount* bank;                //CALL BANKACCOUNT CLASS FOR COMPOSITION RELATIONSHIP 

public:
    user() {}
    user(int paccountno, const char paccountname[], const char pbankname[], const char pbranchname[],
        const char ppcountry[], const char pusername[], const char puserid[], const char puserpw[],
        const char pname[], const char pgender[], const char pcountry[], const char pdob[],
        const char pemail[]) :guestuser(pname, pgender, pcountry, pdob, pemail) {
        bank = new bankaccount(paccountno, paccountname, pbankname, pbranchname, ppcountry);
        strcpy_s(username, pusername);
        strcpy_s(userid, puserid);
        strcpy_s(userpw, puserpw);

    }






    void displaydetails() {
        cout << "----------------USER DEATILS------------------------------" << endl << endl;
        cout << "name : " << name << endl;
        cout << "gender : " << gender << endl;
        cout << "country : " << country << endl;
        cout << "date of birth : " << dob << endl;
        cout << "email : " << email << endl;
        cout << "user name : " << username << endl;
        cout << "user id : " << userid << endl;
        cout << "user password : " << userpw << endl << endl;

    }
    void displaybank() {
        bank->display();                       //CALLING BANK ACCOUNT CLASS DISPLAY FUNCTION
    }


};

//account class
class account {
private:
    char username[30];
    char userpw[30];
    char accounttype[30];
public:
    void set_accountdetails(const char uname[], const char upw[], const char acctype[]);


    void display();
};


void account::set_accountdetails(const char uname[], const char upw[], const char acctype[]) {
    strcpy_s(username, uname);
    strcpy_s(userpw, upw);
    strcpy_s(accounttype, acctype);
}
void account::display() {
    cout << "--------------ACCOUNT DEATILS-------------------------------" << endl << endl;
    cout << "user name  :" << username << endl;
    cout << "userpw  :" << userpw << endl;
    cout << "account type :" << accounttype << endl;
    cout << "-----------------------------------------------" << endl << endl;
}
int main()
{

    account a1;

    user* u1;
    u1 = new user(45064, "KAMAL", "CURRENT ACCOUNT", "BANK OF CEYLON", "SRILANKA", "KAMAL98", "KAMAL22", "KAMAL@#$%", "KAMAL", "MALE", "SRILANKA", "22-5-1998", "KAMAL@gmail.com");
    u1->displaybank();
    u1->displaydetails();
    a1.set_accountdetails("KAMAL98", "KAMAL@#$%", "REGISTERED USER");
    a1.display();
    return 0;
}
