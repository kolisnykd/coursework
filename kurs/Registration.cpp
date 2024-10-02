#include "Registration.h"
#include <Windows.h>
#include <string.h>
#include <msclr/marshal_cppstd.h>
#include "authForm.h"
#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include "SellerC.h"
#include "BuyerC.h"
#include "Account.h"
#include "BookstoreC.h"
#include "BookC.h"
#include "VisitC.h"
#include "PurchaseC.h"
using namespace kurs;
using namespace std;
System::Void kurs::Registration::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    authForm^ auth = gcnew authForm();
    auth->Show();
}
System::Void kurs::Registration::buttonReg2_Click(System::Object^ sender, System::EventArgs^ e)
{
    const string server = "tcp://127.0.0.1:3306";
    const string username = "root";
    const string password = "password";
    String^ loginInput = textLog->Text;
    std::string login = msclr::interop::marshal_as<std::string>(loginInput);
    String^ passwordInput = textPass->Text;
    std::string passwordInp = msclr::interop::marshal_as<std::string>(passwordInput);
    String^ NameInput = textName->Text;
    std::string name = msclr::interop::marshal_as<std::string>(NameInput);
    String^ NumberInput = textNumber->Text;
    std::string number = msclr::interop::marshal_as<std::string>(NumberInput);
    if (number.length() != 12 || number.substr(0, 3) != "380") {
        MessageBox::Show("Not valid!", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
        }
    if (login.empty() || passwordInp.empty() || name.empty() || number.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* res;
    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        con->setSchema("bookstore");
        pstmt = con->prepareStatement("SELECT * FROM login WHERE login = ?");
        pstmt->setString(1, login);
        res = pstmt->executeQuery();
        if (!res->next()) {
            try
            {
                driver = get_driver_instance();
                con = driver->connect(server, username, password);
            }
            catch (sql::SQLException e)
            {
                MessageBox::Show("Error DB!", "Info");
            }
            con->setSchema("bookstore");
            pstmt = con->prepareStatement("INSERT INTO login(login, password, rights) VALUES(?,?,?)");
            pstmt->setString(1, login);
            pstmt->setString(2, passwordInp);
            pstmt->setInt(3, 3);
            pstmt->execute();
            pstmt = con->prepareStatement("INSERT INTO buyer(login, name, contact_number) VALUES(?,?,?)");
            pstmt->setString(1, login);
            pstmt->setString(2, name);
            pstmt->setString(3, number);
            pstmt->execute();
            delete pstmt;
            delete con;
            MessageBox::Show("You have registered", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            this->Hide();
            authForm^ auth = gcnew authForm();
            auth->Show();
        }
        else {
            MessageBox::Show("Login busy!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        delete res;
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
