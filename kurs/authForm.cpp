#include "authForm.h"
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
#include "Registration.h"
#include "Admin.h"
#include "Seller.h"
#include "Buyer.h"
#include "SellerC.h"
#include "BuyerC.h"
#include "Account.h"
#include "BookstoreC.h"
#include "BookC.h"
#include "VisitC.h"
#include "PurchaseC.h"
using namespace kurs;
using namespace std;
[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew authForm);
	return 0;
}
System::Void kurs::authForm::buttonLog_Click(System::Object^ sender, System::EventArgs^ e)
{
    const string server = "tcp://127.0.0.1:3306";
    const string username = "root";
    const string password = "admin";
    String^ loginInput = textLog->Text;
    std::string login = msclr::interop::marshal_as<std::string>(loginInput);
    String^ passwordInput = textPass->Text;
    std::string passwordInp = msclr::interop::marshal_as<std::string>(passwordInput);
    if (login.empty() || passwordInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Driver* driver;
    sql::Connection* con;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* res;
    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
        con->setSchema("bookstore");
        pstmt = con->prepareStatement("SELECT * FROM login WHERE login = ? AND password = ?");
        pstmt->setString(1, login);
        pstmt->setString(2, passwordInp);
        res = pstmt->executeQuery();
        if (res->next()) {
            MessageBox::Show("Login successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            int rightsValue = res->getInt("rights");
            switch (res->getInt("rights"))
            {
            case 1:
                {
                    String^ login = this->textLog->Text;
                    this->Hide();
                    Admin^ adminForm = gcnew Admin(login);
                    adminForm->Show();
                    break;
                }
            case 2:
                {
                String^ login = this->textLog->Text;
                this->Hide();
                Seller^ sellerForm = gcnew Seller(login);
                sellerForm->Show();
                break;
                }
            case 3:
                {
                String^ login = this->textLog->Text;
                this->Hide();
                Buyer^ buyerForm = gcnew Buyer(login);
                buyerForm->Show();
                break;
                }
            }
        }
        else {
            MessageBox::Show("Invalid login or password!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        delete res;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
	return System::Void();
}
System::Void kurs::authForm::buttonReg_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    Registration^ registrationForm = gcnew Registration();
    registrationForm->Show();
}