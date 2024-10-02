#include "Buyer.h"
#include "authForm.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
#include <Windows.h>
#include <string.h>
#include <msclr/marshal_cppstd.h>
#include <stdlib.h>
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cliext/utility>
#include "SellerC.h"
#include "BuyerC.h"
#include "Account.h"
#include "BookstoreC.h"
#include "BookC.h"
#include "VisitC.h"
#include "PurchaseC.h"
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace std;
System::Void kurs::Buyer::InitializeDatabaseConnection()
{
    serverr = "tcp://127.0.0.1:3306";
    usernamee = "root";
    passwordd = "password";
    try
    {
        std::string serverStr = msclr::interop::marshal_as<std::string>(serverr->ToString());
        std::string usernameStr = msclr::interop::marshal_as<std::string>(usernamee->ToString());
        std::string passwordStr = msclr::interop::marshal_as<std::string>(passwordd->ToString());
        driver = get_driver_instance();
        con = driver->connect(serverStr, usernameStr, passwordStr);
        con->setSchema("bookstore");
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Buyer::CloseDatabaseConnection()
{
    if (this->res != nullptr) delete this->res;
    if (this->pstmt != nullptr) delete this->pstmt;
    if (this->stmt != nullptr) delete this->stmt;
    if (this->con != nullptr) delete this->con;
}
System::Void kurs::Buyer::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    authForm^ auth = gcnew authForm();
    auth->Show();
}
System::Void kurs::Buyer::buttonPur_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = labelLogin->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        this->dgvRevPur->Visible = true;
        this->label5->Visible = true;
        this->label3->Visible = true;
        this->datePur1->Visible = true;
        this->datePur2->Visible = true;
        this->buttonPurCal->Visible = true;
        this->dgvRevBS->Visible = false;
        this->dgvRevB->Visible = false;
        this->buttonSearch5->Visible = false;
        this->textSearch5->Visible = false;
        this->label8->Visible = false;
        this->dgvRevV->Visible = false;
        this->buttonVCal->Visible = false;
        this->dateV1->Visible = false;
        this->dateV2->Visible = false;
        this->textLogEd->Visible = false;
        this->textPassEd->Visible = false;
        this->textNameEd->Visible = false;
        this->textNumberEd->Visible = false;
        this->label4->Visible = false;
        this->label6->Visible = false;
        this->label7->Visible = false;
        this->label9->Visible = false;
        this->buttonEdAcc->Visible = false;
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn WHERE purchase.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("purchase_id");
            dt->Columns->Add("loginRevPurEmp");
            dt->Columns->Add("book");
            dt->Columns->Add("cost");
            dt->Columns->Add("quantity");
            dt->Columns->Add("date");
            dt->Columns->Add("time");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["purchase_id"] = gcnew System::String(res->getString("purchase_id").c_str());
                row["loginRevPurEmp"] = gcnew System::String(res->getString("login_employee").c_str());
                row["book"] = gcnew System::String(res->getString("name").c_str());
                row["cost"] = gcnew System::String(res->getString("cost").c_str());
                row["quantity"] = gcnew System::String(res->getString("quantity").c_str());
                row["date"] = gcnew System::String(res->getString("date").c_str());
                row["time"] = gcnew System::String(res->getString("time").c_str());
                dt->Rows->Add(row);
            }
            dgvRevPur->DataSource = dt;
        }
        catch (sql::SQLException& ex)
        {
            System::String^ error = gcnew System::String(ex.what());
            MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (System::Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Buyer::buttonPurCal_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = labelLogin->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        System::DateTime selectedDateTime1 = datePur1->Value;
        System::String^ selectedDateStr = selectedDateTime1.ToString("yyyy-MM-dd");
        std::string selectedDateSstr = msclr::interop::marshal_as<std::string>(selectedDateStr);
        System::DateTime selectedDateTime2 = datePur2->Value;
        System::String^ selectedDateStr2 = selectedDateTime2.ToString("yyyy-MM-dd");
        std::string selectedDateSstr2 = msclr::interop::marshal_as<std::string>(selectedDateStr2);
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn WHERE purchase_book.date BETWEEN ? AND ? AND purchase.login = ?");
            pstmt->setString(1, selectedDateSstr);
            pstmt->setString(2, selectedDateSstr2);
            pstmt->setString(3, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("purchase_id");
            dt->Columns->Add("loginRevPurEmp");
            dt->Columns->Add("book");
            dt->Columns->Add("cost");
            dt->Columns->Add("quantity");
            dt->Columns->Add("date");
            dt->Columns->Add("time");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["purchase_id"] = gcnew System::String(res->getString("purchase_id").c_str());
                row["loginRevPurEmp"] = gcnew System::String(res->getString("login_employee").c_str());
                row["book"] = gcnew System::String(res->getString("name").c_str());
                row["cost"] = gcnew System::String(res->getString("cost").c_str());
                row["quantity"] = gcnew System::String(res->getString("quantity").c_str());
                row["date"] = gcnew System::String(res->getString("date").c_str());
                row["time"] = gcnew System::String(res->getString("time").c_str());
                dt->Rows->Add(row);
            }
            dgvRevPur->DataSource = dt;
        }
        catch (sql::SQLException& ex)
        {
            System::String^ error = gcnew System::String(ex.what());
            MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (System::Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Buyer::buttonBS_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->dgvRevPur->Visible = false;
        this->label5->Visible = false;
        this->label3->Visible = false;
        this->datePur1->Visible = false;
        this->datePur2->Visible = false;
        this->buttonPurCal->Visible = false;
        this->dgvRevBS->Visible = true;
        this->dgvRevB->Visible = false;
        this->buttonSearch5->Visible = false;
        this->textSearch5->Visible = false;
        this->label8->Visible = false;
        this->dgvRevV->Visible = false;
        this->buttonVCal->Visible = false;
        this->dateV1->Visible = false;
        this->dateV2->Visible = false;
        this->textLogEd->Visible = false;
        this->textPassEd->Visible = false;
        this->textNameEd->Visible = false;
        this->textNumberEd->Visible = false;
        this->label4->Visible = false;
        this->label6->Visible = false;
        this->label7->Visible = false;
        this->label9->Visible = false;
        this->buttonEdAcc->Visible = false;
        try
        {
            pstmt = con->prepareStatement("SELECT bookstore.name, bookstore.contact_number, bookstore.address, bookstore.work_schedule FROM bookstore");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("nameRevBS");
            dt->Columns->Add("contact_numberRevBS");
            dt->Columns->Add("addressRevBS");
            dt->Columns->Add("work_scheduleRev");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["nameRevBS"] = gcnew System::String(res->getString("name").c_str());
                row["contact_numberRevBS"] = gcnew System::String(res->getString("contact_number").c_str());
                row["addressRevBS"] = gcnew System::String(res->getString("address").c_str());
                row["work_scheduleRev"] = gcnew System::String(res->getString("work_schedule").c_str());
                dt->Rows->Add(row);
            }
            dgvRevBS->DataSource = dt;
        }
        catch (sql::SQLException& ex)
        {
            System::String^ error = gcnew System::String(ex.what());
            MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (System::Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Buyer::buttonB_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->dgvRevPur->Visible = false;
        this->label5->Visible = false;
        this->label3->Visible = false;
        this->datePur1->Visible = false;
        this->datePur2->Visible = false;
        this->buttonPurCal->Visible = false;
        this->dgvRevBS->Visible = false;
        this->dgvRevB->Visible = true;
        this->buttonSearch5->Visible = true;
        this->textSearch5->Visible = true;
        this->label8->Visible = true;
        this->dgvRevV->Visible = false;
        this->buttonVCal->Visible = false;
        this->dateV1->Visible = false;
        this->dateV2->Visible = false;
        this->textLogEd->Visible = false;
        this->textPassEd->Visible = false;
        this->textNameEd->Visible = false;
        this->textNumberEd->Visible = false;
        this->label4->Visible = false;
        this->label6->Visible = false;
        this->label7->Visible = false;
        this->label9->Visible = false;
        this->buttonEdAcc->Visible = false;
        try
        {
            pstmt = con->prepareStatement("SELECT book.isbn, book.name, book.author, book.cost, book.genre, book.publishing_house FROM book");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("isbnRev");
            dt->Columns->Add("nameRevB");
            dt->Columns->Add("authorRev");
            dt->Columns->Add("costRevB");
            dt->Columns->Add("genreRev");
            dt->Columns->Add("publishing_houseRev");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["isbnRev"] = gcnew System::String(res->getString("isbn").c_str());
                row["nameRevB"] = gcnew System::String(res->getString("name").c_str());
                row["authorRev"] = gcnew System::String(res->getString("author").c_str());
                row["costRevB"] = gcnew System::String(res->getString("cost").c_str());
                row["genreRev"] = gcnew System::String(res->getString("genre").c_str());
                row["publishing_houseRev"] = gcnew System::String(res->getString("publishing_house").c_str());
                dt->Rows->Add(row);
            }
            dgvRevB->DataSource = dt;
        }
        catch (sql::SQLException& ex)
        {
            System::String^ error = gcnew System::String(ex.what());
            MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (System::Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Buyer::buttonSearch5_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearch5->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT book.isbn, book.name, book.author, book.cost, book.genre, book.publishing_house FROM book WHERE book.name = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("isbnRev");
            dt->Columns->Add("nameRevB");
            dt->Columns->Add("authorRev");
            dt->Columns->Add("costRevB");
            dt->Columns->Add("genreRev");
            dt->Columns->Add("publishing_houseRev");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["isbnRev"] = gcnew System::String(res->getString("isbn").c_str());
                row["nameRevB"] = gcnew System::String(res->getString("name").c_str());
                row["authorRev"] = gcnew System::String(res->getString("author").c_str());
                row["costRevB"] = gcnew System::String(res->getString("cost").c_str());
                row["genreRev"] = gcnew System::String(res->getString("genre").c_str());
                row["publishing_houseRev"] = gcnew System::String(res->getString("publishing_house").c_str());
                dt->Rows->Add(row);
            }
            dgvRevB->DataSource = dt;
        }
        catch (sql::SQLException& ex)
        {
            System::String^ error = gcnew System::String(ex.what());
            MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (System::Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Buyer::buttonV_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = labelLogin->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        this->dgvRevPur->Visible = false;
        this->label5->Visible = true;
        this->label3->Visible = true;
        this->datePur1->Visible = false;
        this->datePur2->Visible = false;
        this->buttonPurCal->Visible = false;
        this->dgvRevBS->Visible = false;
        this->dgvRevB->Visible = false;
        this->buttonSearch5->Visible = false;
        this->textSearch5->Visible = false;
        this->label8->Visible = false;
        this->dgvRevV->Visible = true;
        this->buttonVCal->Visible = true;
        this->dateV1->Visible = true;
        this->dateV2->Visible = true;
        this->textLogEd->Visible = false;
        this->textPassEd->Visible = false;
        this->textNameEd->Visible = false;
        this->textNumberEd->Visible = false;
        this->label4->Visible = false;
        this->label6->Visible = false;
        this->label7->Visible = false;
        this->label9->Visible = false;
        this->buttonEdAcc->Visible = false;
        try
        {
            pstmt = con->prepareStatement("SELECT bookstore.name, visit.date_visit, visit.time_visit, visit.note FROM visit INNER JOIN bookstore ON visit.contact_number = bookstore.contact_number WHERE visit.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("nameRevVBS");
            dt->Columns->Add("date_visitRev");
            dt->Columns->Add("time_visitRev");
            dt->Columns->Add("noteRev");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["nameRevVBS"] = gcnew System::String(res->getString("name").c_str());
                row["date_visitRev"] = gcnew System::String(res->getString("date_visit").c_str());
                row["time_visitRev"] = gcnew System::String(res->getString("time_visit").c_str());
                row["noteRev"] = gcnew System::String(res->getString("note").c_str());
                dt->Rows->Add(row);
            }
            dgvRevV->DataSource = dt;
        }
        catch (sql::SQLException& ex)
        {
            System::String^ error = gcnew System::String(ex.what());
            MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (System::Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Buyer::buttonVCal_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = labelLogin->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        System::DateTime selectedDateTime1 = dateV1->Value;
        System::String^ selectedDateStr = selectedDateTime1.ToString("yyyy-MM-dd");
        std::string selectedDateSstr = msclr::interop::marshal_as<std::string>(selectedDateStr);
        System::DateTime selectedDateTime2 = dateV2->Value;
        System::String^ selectedDateStr2 = selectedDateTime2.ToString("yyyy-MM-dd");
        std::string selectedDateSstr2 = msclr::interop::marshal_as<std::string>(selectedDateStr2);
        try
        {
            pstmt = con->prepareStatement("SELECT bookstore.name, visit.date_visit, visit.time_visit, visit.note FROM visit INNER JOIN bookstore ON visit.contact_number = bookstore.contact_number WHERE visit.date_visit BETWEEN ? AND ? AND visit.login = ?");
            pstmt->setString(1, selectedDateSstr);
            pstmt->setString(2, selectedDateSstr2);
            pstmt->setString(3, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("nameRevVBS");
            dt->Columns->Add("date_visitRev");
            dt->Columns->Add("time_visitRev");
            dt->Columns->Add("noteRev");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["nameRevVBS"] = gcnew System::String(res->getString("name").c_str());
                row["date_visitRev"] = gcnew System::String(res->getString("date_visit").c_str());
                row["time_visitRev"] = gcnew System::String(res->getString("time_visit").c_str());
                row["noteRev"] = gcnew System::String(res->getString("note").c_str());
                dt->Rows->Add(row);
            }
            dgvRevV->DataSource = dt;
        }
        catch (sql::SQLException& ex)
        {
            System::String^ error = gcnew System::String(ex.what());
            MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (System::Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Buyer::buttonEd_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->dgvRevPur->Visible = false;
    this->label5->Visible = false;
    this->label3->Visible = false;
    this->datePur1->Visible = false;
    this->datePur2->Visible = false;
    this->buttonPurCal->Visible = false;
    this->dgvRevBS->Visible = false;
    this->dgvRevB->Visible = false;
    this->buttonSearch5->Visible = false;
    this->textSearch5->Visible = false;
    this->label8->Visible = false;
    this->dgvRevV->Visible = false;
    this->buttonVCal->Visible = false;
    this->dateV1->Visible = false;
    this->dateV2->Visible = false;
    this->textLogEd->Visible = true;
    this->textPassEd->Visible = true;
    this->textNameEd->Visible = true;
    this->textNumberEd->Visible = true;
    this->label4->Visible = true;
    this->label6->Visible = true;
    this->label7->Visible = true;
    this->label9->Visible = true;
    this->buttonEdAcc->Visible = true;
    textLogEd->Text = labelLogin->Text;
    try
    {
        String^ SearchInput = labelLogin->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT login.password, buyer.name, buyer.contact_number FROM login INNER JOIN buyer ON login.login = buyer.login WHERE login.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            while (res->next())
            {
                textPassEd->Text = gcnew System::String(res->getString("password").c_str());
                textNameEd->Text = gcnew System::String(res->getString("name").c_str());
                textNumberEd->Text = gcnew System::String(res->getString("contact_number").c_str());
            }
        }
        catch (sql::SQLException& ex)
        {
            System::String^ error = gcnew System::String(ex.what());
            MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (System::Exception^ ex)
    {
        MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Buyer::buttonEdAcc_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ loginInput = labelLogin->Text;
    std::string login = msclr::interop::marshal_as<std::string>(loginInput);
    String^ passwordInput = textPassEd->Text;
    std::string passwordInp = msclr::interop::marshal_as<std::string>(passwordInput);
    String^ NameInput = textNameEd->Text;
    std::string name = msclr::interop::marshal_as<std::string>(NameInput);
    String^ NumberInput = textNumberEd->Text;
    std::string number = msclr::interop::marshal_as<std::string>(NumberInput);
    if (number.length() != 12 || number.substr(0, 3) != "380") {
        MessageBox::Show("Not valid!", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    if (login.empty() || passwordInp.empty() || name.empty() || number.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("UPDATE bookstore.login SET password = ? WHERE login = ?");
        pstmt->setString(1, passwordInp);
        pstmt->setString(2, login);
        pstmt->execute();
        pstmt = con->prepareStatement("UPDATE bookstore.buyer SET name = ?, contact_number = ? WHERE login = ?");
        pstmt->setString(1, name);
        pstmt->setString(2, number);
        pstmt->setString(3, login);
        pstmt->execute();
        buttonEd_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}