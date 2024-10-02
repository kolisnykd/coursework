#include "Seller.h"
#include "Admin.h"
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
System::Void kurs::Seller::InitializeDatabaseConnection()
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
System::Void kurs::Seller::CloseDatabaseConnection()
{
    if (this->res != nullptr) delete this->res;
    if (this->pstmt != nullptr) delete this->pstmt;
    if (this->stmt != nullptr) delete this->stmt;
    if (this->con != nullptr) delete this->con;
}
System::Void kurs::Seller::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    authForm^ auth = gcnew authForm();
    auth->Show();
}
System::Void kurs::Seller::buttonRevision_Click(System::Object^ sender, System::EventArgs^ e)
{
    buttonAdd->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonEdit->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonDel->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonReq->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonRevision->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold | FontStyle::Underline);
    this->groupBox1->Visible = true;
    this->groupBox1->Enabled = true;
    this->groupBox2->Visible = false;
    this->groupBox2->Enabled = false;
    this->groupBox3->Visible = false;
    this->groupBox3->Enabled = false;
    this->groupBox4->Visible = false;
    this->groupBox4->Enabled = false;
    this->groupBox5->Visible = false;
    this->groupBox5->Enabled = false;
    this->groupBoxRevBuy->Visible = false;
    this->groupBoxRevBuy->Enabled = false;
    this->groupBoxAddBuy->Visible = false;
    this->groupBoxAddBuy->Enabled = false;
    this->groupBoxEdBuy->Visible = false;
    this->groupBoxEdBuy->Enabled = false;
    this->groupBoxDelBuy->Visible = false;
    this->groupBoxDelBuy->Enabled = false;
}
System::Void kurs::Seller::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    buttonAdd->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold | FontStyle::Underline);
    buttonEdit->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonDel->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonReq->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonRevision->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    this->groupBox1->Visible = true;
    this->groupBox1->Enabled = true;
    this->groupBox2->Visible = true;
    this->groupBox2->Enabled = true;
    this->groupBox3->Visible = false;
    this->groupBox3->Enabled = false;
    this->groupBox4->Visible = false;
    this->groupBox4->Enabled = false;
    this->groupBox5->Visible = false;
    this->groupBox5->Enabled = false;
    this->groupBoxRevBuy->Visible = false;
    this->groupBoxRevBuy->Enabled = false;
    this->groupBoxAddBuy->Visible = false;
    this->groupBoxAddBuy->Enabled = false;
    this->groupBoxEdBuy->Visible = false;
    this->groupBoxEdBuy->Enabled = false;
    this->groupBoxDelBuy->Visible = false;
    this->groupBoxDelBuy->Enabled = false;
}
System::Void kurs::Seller::buttonEdit_Click(System::Object^ sender, System::EventArgs^ e)
{
    buttonAdd->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonEdit->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold | FontStyle::Underline);
    buttonDel->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonReq->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonRevision->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    this->groupBox1->Visible = true;
    this->groupBox1->Enabled = true;
    this->groupBox2->Visible = true;
    this->groupBox2->Enabled = true;
    this->groupBox3->Visible = true;
    this->groupBox3->Enabled = true;
    this->groupBox4->Visible = false;
    this->groupBox4->Enabled = false;
    this->groupBox5->Visible = false;
    this->groupBox5->Enabled = false;
    this->groupBoxRevBuy->Visible = false;
    this->groupBoxRevBuy->Enabled = false;
    this->groupBoxAddBuy->Visible = false;
    this->groupBoxAddBuy->Enabled = false;
    this->groupBoxEdBuy->Visible = false;
    this->groupBoxEdBuy->Enabled = false;
    this->groupBoxDelBuy->Visible = false;
    this->groupBoxDelBuy->Enabled = false;
}
System::Void kurs::Seller::buttonDel_Click(System::Object^ sender, System::EventArgs^ e)
{
    buttonAdd->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonEdit->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonDel->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold | FontStyle::Underline);
    buttonReq->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonRevision->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    this->groupBox1->Visible = true;
    this->groupBox1->Enabled = true;
    this->groupBox2->Visible = true;
    this->groupBox2->Enabled = true;
    this->groupBox3->Visible = true;
    this->groupBox3->Enabled = true;
    this->groupBox4->Visible = true;
    this->groupBox4->Enabled = true;
    this->groupBox5->Visible = false;
    this->groupBox5->Enabled = false;
    this->groupBoxRevBuy->Visible = false;
    this->groupBoxRevBuy->Enabled = false;
    this->groupBoxAddBuy->Visible = false;
    this->groupBoxAddBuy->Enabled = false;
    this->groupBoxEdBuy->Visible = false;
    this->groupBoxEdBuy->Enabled = false;
    this->groupBoxDelBuy->Visible = false;
    this->groupBoxDelBuy->Enabled = false;
}
System::Void kurs::Seller::buttonReq_Click(System::Object^ sender, System::EventArgs^ e)
{
    buttonAdd->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonEdit->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonDel->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    buttonReq->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold | FontStyle::Underline);
    buttonRevision->Font = gcnew System::Drawing::Font("Arial", 18, FontStyle::Bold);
    this->groupBox1->Visible = true;
    this->groupBox1->Enabled = true;
    this->groupBox2->Visible = true;
    this->groupBox2->Enabled = true;
    this->groupBox3->Visible = true;
    this->groupBox3->Enabled = true;
    this->groupBox4->Visible = true;
    this->groupBox4->Enabled = true;
    this->groupBox5->Visible = true;
    this->groupBox5->Enabled = true;
    this->groupBoxRevBuy->Visible = false;
    this->groupBoxRevBuy->Enabled = false;
    this->groupBoxAddBuy->Visible = false;
    this->groupBoxAddBuy->Enabled = false;
    this->groupBoxEdBuy->Visible = false;
    this->groupBoxEdBuy->Enabled = false;
    this->groupBoxDelBuy->Visible = false;
    this->groupBoxDelBuy->Enabled = false;
    this->dgvReq1->Visible = false;
    this->dgvReq3->Visible = false;
    this->textReq4->Visible = false;
    this->dgvReq5->Visible = false;
    this->textReq6->Visible = false;
    this->dgvReq7->Visible = false;
    this->dgvReq8->Visible = false;
    this->dgvReq9->Visible = false;
}
System::Void kurs::Seller::buttonBuyer_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->groupBoxRevBuy->Visible = true;
    this->groupBoxRevBuy->Enabled = true;
    this->groupBoxRevPur->Visible = false;
    this->groupBoxRevPur->Enabled = false;
    this->groupBoxRevBS->Visible = false;
    this->groupBoxRevBS->Enabled = false;
    this->groupBoxRevB->Visible = false;
    this->groupBoxRevB->Enabled = false;
    this->groupBoxRevV->Visible = false;
    this->groupBoxRevV->Enabled = false;
    try
    {
        pstmt = con->prepareStatement("SELECT login.login, login.password, buyer.name, buyer.contact_number FROM login INNER JOIN buyer ON login.login = buyer.login");
        res = pstmt->executeQuery();
        System::Data::DataTable^ dt = gcnew System::Data::DataTable();
        dt->Columns->Add("Login");
        dt->Columns->Add("Password");
        dt->Columns->Add("Name");
        dt->Columns->Add("Contact_Number");
        while (res->next())
        {
            DataRow^ row = dt->NewRow();
            row["Login"] = gcnew System::String(res->getString("login").c_str());
            row["Password"] = gcnew System::String(res->getString("password").c_str());
            row["Name"] = gcnew System::String(res->getString("name").c_str());
            row["Contact_Number"] = gcnew System::String(res->getString("contact_number").c_str());
            dt->Rows->Add(row);
        }
        dgvRevBuy->DataSource = dt;
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonSearch_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearch->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        pstmt = con->prepareStatement("SELECT login.login, login.password, buyer.name, buyer.contact_number FROM login INNER JOIN buyer ON login.login = buyer.login WHERE login.login = ?");
        pstmt->setString(1, search);
        res = pstmt->executeQuery();
        System::Data::DataTable^ dt = gcnew System::Data::DataTable();
        dt->Columns->Add("Login");
        dt->Columns->Add("Password");
        dt->Columns->Add("Name");
        dt->Columns->Add("Contact_Number");
        while (res->next())
        {
            DataRow^ row = dt->NewRow();
            row["Login"] = gcnew System::String(res->getString("login").c_str());
            row["Password"] = gcnew System::String(res->getString("password").c_str());
            row["Name"] = gcnew System::String(res->getString("name").c_str());
            row["Contact_Number"] = gcnew System::String(res->getString("contact_number").c_str());
            dt->Rows->Add(row);
        }
        dgvRevBuy->DataSource = dt;
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonPurchase_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxRevBuy->Visible = true;
        this->groupBoxRevBuy->Enabled = true;
        this->groupBoxRevPur->Visible = true;
        this->groupBoxRevPur->Enabled = true;
        this->groupBoxRevBS->Visible = false;
        this->groupBoxRevBS->Enabled = false;
        this->groupBoxRevB->Visible = false;
        this->groupBoxRevB->Enabled = false;
        this->groupBoxRevV->Visible = false;
        this->groupBoxRevV->Enabled = false;
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("purchase_id");
            dt->Columns->Add("loginRevPurBuy");
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
                row["loginRevPurBuy"] = gcnew System::String(res->getString("login").c_str());
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
System::Void kurs::Seller::buttonSearch2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearch2->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn WHERE purchase.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("purchase_id");
            dt->Columns->Add("loginRevPurBuy");
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
                row["loginRevPurBuy"] = gcnew System::String(res->getString("login").c_str());
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
System::Void kurs::Seller::buttonPurCal_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        System::DateTime selectedDateTime1 = datePur1->Value;
        System::String^ selectedDateStr = selectedDateTime1.ToString("yyyy-MM-dd");
        std::string selectedDateSstr = msclr::interop::marshal_as<std::string>(selectedDateStr);
        System::DateTime selectedDateTime2 = datePur2->Value;
        System::String^ selectedDateStr2 = selectedDateTime2.ToString("yyyy-MM-dd");
        std::string selectedDateSstr2 = msclr::interop::marshal_as<std::string>(selectedDateStr2);
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn WHERE purchase_book.date BETWEEN ? AND ?");
            pstmt->setString(1, selectedDateSstr);
            pstmt->setString(2, selectedDateSstr2);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("purchase_id");
            dt->Columns->Add("loginRevPurBuy");
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
                row["loginRevPurBuy"] = gcnew System::String(res->getString("login").c_str());
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
System::Void kurs::Seller::buttonBookstore_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxRevBuy->Visible = true;
        this->groupBoxRevBuy->Enabled = true;
        this->groupBoxRevPur->Visible = true;
        this->groupBoxRevPur->Enabled = true;
        this->groupBoxRevBS->Visible = true;
        this->groupBoxRevBS->Enabled = true;
        this->groupBoxRevB->Visible = false;
        this->groupBoxRevB->Enabled = false;
        this->groupBoxRevV->Visible = false;
        this->groupBoxRevV->Enabled = false;
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
System::Void kurs::Seller::buttonSearch4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearch4->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT bookstore.name, bookstore.contact_number, bookstore.address, bookstore.work_schedule FROM bookstore WHERE bookstore.name = ?");
            pstmt->setString(1, search);
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
System::Void kurs::Seller::buttonBook_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxRevBuy->Visible = true;
        this->groupBoxRevBuy->Enabled = true;
        this->groupBoxRevPur->Visible = true;
        this->groupBoxRevPur->Enabled = true;
        this->groupBoxRevBS->Visible = true;
        this->groupBoxRevBS->Enabled = true;
        this->groupBoxRevB->Visible = true;
        this->groupBoxRevB->Enabled = true;
        this->groupBoxRevV->Visible = false;
        this->groupBoxRevV->Enabled = false;
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
System::Void kurs::Seller::buttonSearch5_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Seller::buttonSearchRevCost_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        Decimal selectedCost1 = numericUpDownRev1->Value;
        System::String^ selectedCcost1 = selectedCost1.ToString();
        std::string selectedCccost1 = msclr::interop::marshal_as<std::string>(selectedCcost1);
        Decimal selectedCost2 = numericUpDownRev2->Value;
        System::String^ selectedCcost2 = selectedCost2.ToString();
        std::string selectedCccost2 = msclr::interop::marshal_as<std::string>(selectedCcost2);
        try
        {
            pstmt = con->prepareStatement("SELECT book.isbn, book.name, book.author, book.cost, book.genre, book.publishing_house FROM book WHERE book.cost BETWEEN ? AND ?");
            pstmt->setString(1, selectedCccost1);
            pstmt->setString(2, selectedCccost2);
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
System::Void kurs::Seller::buttonVisit_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxRevBuy->Visible = true;
        this->groupBoxRevBuy->Enabled = true;
        this->groupBoxRevPur->Visible = true;
        this->groupBoxRevPur->Enabled = true;
        this->groupBoxRevBS->Visible = true;
        this->groupBoxRevBS->Enabled = true;
        this->groupBoxRevB->Visible = true;
        this->groupBoxRevB->Enabled = true;
        this->groupBoxRevV->Visible = true;
        this->groupBoxRevV->Enabled = true;
        try
        {
            pstmt = con->prepareStatement("SELECT visit.login, bookstore.name, visit.date_visit, visit.time_visit, visit.note FROM visit INNER JOIN bookstore ON visit.contact_number = bookstore.contact_number");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginRevVBuy");
            dt->Columns->Add("nameRevVBS");
            dt->Columns->Add("date_visitRev");
            dt->Columns->Add("time_visitRev");
            dt->Columns->Add("noteRev");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginRevVBuy"] = gcnew System::String(res->getString("login").c_str());
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
System::Void kurs::Seller::buttonSearch7_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearch7->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT visit.login, bookstore.name, visit.date_visit, visit.time_visit, visit.note FROM visit INNER JOIN bookstore ON visit.contact_number = bookstore.contact_number WHERE visit.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginRevVBuy");
            dt->Columns->Add("nameRevVBS");
            dt->Columns->Add("date_visitRev");
            dt->Columns->Add("time_visitRev");
            dt->Columns->Add("noteRev");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginRevVBuy"] = gcnew System::String(res->getString("login").c_str());
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
System::Void kurs::Seller::buttonVCal_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        System::DateTime selectedDateTime1 = dateV1->Value;
        System::String^ selectedDateStr = selectedDateTime1.ToString("yyyy-MM-dd");
        std::string selectedDateSstr = msclr::interop::marshal_as<std::string>(selectedDateStr);
        System::DateTime selectedDateTime2 = dateV2->Value;
        System::String^ selectedDateStr2 = selectedDateTime2.ToString("yyyy-MM-dd");
        std::string selectedDateSstr2 = msclr::interop::marshal_as<std::string>(selectedDateStr2);
        try
        {
            pstmt = con->prepareStatement("SELECT visit.login, bookstore.name, visit.date_visit, visit.time_visit, visit.note FROM visit INNER JOIN bookstore ON visit.contact_number = bookstore.contact_number WHERE visit.date_visit BETWEEN ? AND ?");
            pstmt->setString(1, selectedDateSstr);
            pstmt->setString(2, selectedDateSstr2);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginRevVBuy");
            dt->Columns->Add("nameRevVBS");
            dt->Columns->Add("date_visitRev");
            dt->Columns->Add("time_visitRev");
            dt->Columns->Add("noteRev");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginRevVBuy"] = gcnew System::String(res->getString("login").c_str());
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
System::Void kurs::Seller::buttonBuyer2_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->groupBoxAddBuy->Visible = true;
    this->groupBoxAddBuy->Enabled = true;
    this->groupBoxAddPur->Visible = false;
    this->groupBoxAddPur->Enabled = false;
    this->groupBoxAddB->Visible = false;
    this->groupBoxAddB->Enabled = false;
    try
    {
        pstmt = con->prepareStatement("SELECT login.login, login.password, buyer.name, buyer.contact_number FROM login INNER JOIN buyer ON login.login = buyer.login");
        res = pstmt->executeQuery();
        System::Data::DataTable^ dt = gcnew System::Data::DataTable();
        dt->Columns->Add("loginAddBuy");
        dt->Columns->Add("passwordAddBuy");
        dt->Columns->Add("nameAddBuy");
        dt->Columns->Add("contact_numberAddBuy");
        while (res->next())
        {
            DataRow^ row = dt->NewRow();
            row["loginAddBuy"] = gcnew System::String(res->getString("login").c_str());
            row["passwordAddBuy"] = gcnew System::String(res->getString("password").c_str());
            row["nameAddBuy"] = gcnew System::String(res->getString("name").c_str());
            row["contact_numberAddBuy"] = gcnew System::String(res->getString("contact_number").c_str());
            dt->Rows->Add(row);
        }
        dgvAddBuy->DataSource = dt;
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonSearchAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ SearchInput = textSearchAdd->Text;
    std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
    try
    {
        pstmt = con->prepareStatement("SELECT login.login, login.password, buyer.name, buyer.contact_number FROM login INNER JOIN buyer ON login.login = buyer.login WHERE login.login = ?");
        pstmt->setString(1, search);
        res = pstmt->executeQuery();
        System::Data::DataTable^ dt = gcnew System::Data::DataTable();
        dt->Columns->Add("loginAddBuy");
        dt->Columns->Add("passwordAddBuy");
        dt->Columns->Add("nameAddBuy");
        dt->Columns->Add("contact_numberAddBuy");
        while (res->next())
        {
            DataRow^ row = dt->NewRow();
            row["loginAddBuy"] = gcnew System::String(res->getString("login").c_str());
            row["passwordAddBuy"] = gcnew System::String(res->getString("password").c_str());
            row["nameAddBuy"] = gcnew System::String(res->getString("name").c_str());
            row["contact_numberAddBuy"] = gcnew System::String(res->getString("contact_number").c_str());
            dt->Rows->Add(row);
        }
        dgvAddBuy->DataSource = dt;
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonAddBuy_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ loginInput = textAddBuyLog->Text;
    std::string login = msclr::interop::marshal_as<std::string>(loginInput);
    String^ passwordInput = textAddBuyPass->Text;
    std::string passwordInp = msclr::interop::marshal_as<std::string>(passwordInput);
    String^ NameInput = textAddBuyName->Text;
    std::string name = msclr::interop::marshal_as<std::string>(NameInput);
    String^ NumberInput = textAddBuyNum->Text;
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
        pstmt = con->prepareStatement("SELECT * FROM login WHERE login = ?");
        pstmt->setString(1, login);
        res = pstmt->executeQuery();
        if (!res->next()) {
            try
            {
            }
            catch (sql::SQLException e)
            {
                MessageBox::Show("Error DB!", "Info");
            }
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
            buttonBuyer2_Click(sender, e);
        }
        else {
            MessageBox::Show("Login busy!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonPurchase2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxAddBuy->Visible = true;
        this->groupBoxAddBuy->Enabled = true;
        this->groupBoxAddPur->Visible = true;
        this->groupBoxAddPur->Enabled = true;
        this->groupBoxAddB->Visible = false;
        this->groupBoxAddB->Enabled = false;
        comboAddPurLogBuy->Items->Clear();
        comboAddPurB->Items->Clear();
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("idAddPur");
            dt->Columns->Add("loginAddPur");
            dt->Columns->Add("loginEmpAddPur");
            dt->Columns->Add("bookAddPur");
            dt->Columns->Add("costAddPur");
            dt->Columns->Add("quantityAddPur");
            dt->Columns->Add("dateAddPur");
            dt->Columns->Add("timeAddPur");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["idAddPur"] = gcnew System::String(res->getString("purchase_id").c_str());
                row["loginAddPur"] = gcnew System::String(res->getString("login").c_str());
                row["loginEmpAddPur"] = gcnew System::String(res->getString("login_employee").c_str());
                row["bookAddPur"] = gcnew System::String(res->getString("name").c_str());
                row["costAddPur"] = gcnew System::String(res->getString("cost").c_str());
                row["quantityAddPur"] = gcnew System::String(res->getString("quantity").c_str());
                row["dateAddPur"] = gcnew System::String(res->getString("date").c_str());
                row["timeAddPur"] = gcnew System::String(res->getString("time").c_str());
                dt->Rows->Add(row);
            }
            dgvAddPur->DataSource = dt;
            pstmt = con->prepareStatement("SELECT buyer.login FROM buyer");
            res = pstmt->executeQuery();
            while (res->next())
            {
                comboAddPurLogBuy->Items->Add(gcnew System::String(res->getString("login").c_str()));
            }
            pstmt = con->prepareStatement("SELECT book.name FROM book");
            res = pstmt->executeQuery();
            while (res->next())
            {
                comboAddPurB->Items->Add(gcnew System::String(res->getString("name").c_str()));
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
System::Void kurs::Seller::buttonSearchAdd2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchAdd2->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn WHERE purchase.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("idAddPur");
            dt->Columns->Add("loginAddPur");
            dt->Columns->Add("loginEmpAddPur");
            dt->Columns->Add("bookAddPur");
            dt->Columns->Add("costAddPur");
            dt->Columns->Add("quantityAddPur");
            dt->Columns->Add("dateAddPur");
            dt->Columns->Add("timeAddPur");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["idAddPur"] = gcnew System::String(res->getString("purchase_id").c_str());
                row["loginAddPur"] = gcnew System::String(res->getString("login").c_str());
                row["loginEmpAddPur"] = gcnew System::String(res->getString("login_employee").c_str());
                row["bookAddPur"] = gcnew System::String(res->getString("name").c_str());
                row["costAddPur"] = gcnew System::String(res->getString("cost").c_str());
                row["quantityAddPur"] = gcnew System::String(res->getString("quantity").c_str());
                row["dateAddPur"] = gcnew System::String(res->getString("date").c_str());
                row["timeAddPur"] = gcnew System::String(res->getString("time").c_str());
                dt->Rows->Add(row);
            }
            dgvAddPur->DataSource = dt;
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
System::Void kurs::Seller::buttonAddPur_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ loginInput = comboAddPurLogBuy->Text;
    std::string logInp = msclr::interop::marshal_as<std::string>(loginInput);
    String^ loginEmpInput = comboAddPurLogEmp->Text;
    std::string logEmpInp = msclr::interop::marshal_as<std::string>(loginEmpInput);
    String^ bookInput = comboAddPurB->Text;
    std::string bInp = msclr::interop::marshal_as<std::string>(bookInput);
    String^ quaInput = numericAddPurQua->Text;
    std::string qInp = msclr::interop::marshal_as<std::string>(quaInput);
    int intqInp = std::stoi(qInp);
    System::DateTime selectedDateTime1 = dateAddPurDate->Value;
    System::String^ selectedDateStr = selectedDateTime1.ToString("yyyy-MM-dd");
    std::string selectedDateSstr = msclr::interop::marshal_as<std::string>(selectedDateStr);
    System::DateTime selectedDateTime = timeAddPurTime->Value;
    System::String^ selectedTimeStr = selectedDateTime.ToString("HH:mm");
    std::string selectedTimeStdStr = msclr::interop::marshal_as<std::string>(selectedTimeStr);
    if (logInp.empty() || logEmpInp.empty() || bInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("INSERT INTO purchase(login, login_employee) VALUES(?,?)");
        pstmt->setString(1, logInp);
        pstmt->setString(2, logEmpInp);
        pstmt->execute();
        pstmt = con->prepareStatement("SELECT book.isbn, book.cost FROM book WHERE book.name = ?");
        pstmt->setString(1, bInp);
        res = pstmt->executeQuery();
        std::string isbnInp;
        std::string totalCostString;
        while (res->next())
        {
            String^ isbnInput = gcnew System::String(res->getString("isbn").c_str());
            isbnInp = msclr::interop::marshal_as<std::string>(isbnInput);
            float totalCostInput = intqInp * (res->getDouble("cost"));
            totalCostString = std::to_string(totalCostInput);
        }
        pstmt = con->prepareStatement("SELECT purchase.purchase_id FROM purchase WHERE purchase_id = (SELECT MAX(purchase_id) FROM purchase);");
        res = pstmt->executeQuery();
        std::string idInp;
        String^ purchase_idInput;
        while (res->next())
        {
            purchase_idInput = gcnew System::String(res->getString("purchase_id").c_str());
            idInp = msclr::interop::marshal_as<std::string>(purchase_idInput);
        }
        pstmt = con->prepareStatement("INSERT INTO transaction(purchase_id, date, time, amount) VALUES(?,?,?,?)");
        pstmt->setString(1, idInp);
        pstmt->setString(2, selectedDateSstr);
        pstmt->setString(3, selectedTimeStdStr);
        pstmt->setString(4, totalCostString);
        pstmt->execute();
        pstmt = con->prepareStatement("INSERT INTO purchase_book(purchase_id, isbn, date, time, quantity, cost) VALUES(?,?,?,?,?,?)");
        pstmt->setString(1, idInp);
        pstmt->setString(2, isbnInp);
        pstmt->setString(3, selectedDateSstr);
        pstmt->setString(4, selectedTimeStdStr);
        pstmt->setString(5, qInp);
        pstmt->setString(6, totalCostString);
        pstmt->execute();
        buttonPurchase2_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Seller::buttonBook2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxAddBuy->Visible = true;
        this->groupBoxAddBuy->Enabled = true;
        this->groupBoxAddPur->Visible = true;
        this->groupBoxAddPur->Enabled = true;
        this->groupBoxAddB->Visible = true;
        this->groupBoxAddB->Enabled = true;
        try
        {
            pstmt = con->prepareStatement("SELECT book.isbn, book.name, book.author, book.cost, book.genre, book.publishing_house FROM book");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("isbnAddB");
            dt->Columns->Add("nameAddB");
            dt->Columns->Add("authorAddB");
            dt->Columns->Add("costAddB");
            dt->Columns->Add("genreAddB");
            dt->Columns->Add("publishing_houseAddB");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["isbnAddB"] = gcnew System::String(res->getString("isbn").c_str());
                row["nameAddB"] = gcnew System::String(res->getString("name").c_str());
                row["authorAddB"] = gcnew System::String(res->getString("author").c_str());
                row["costAddB"] = gcnew System::String(res->getString("cost").c_str());
                row["genreAddB"] = gcnew System::String(res->getString("genre").c_str());
                row["publishing_houseAddB"] = gcnew System::String(res->getString("publishing_house").c_str());
                dt->Rows->Add(row);
            }
            dgvAddB->DataSource = dt;
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
System::Void kurs::Seller::buttonSearchAdd5_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchAdd5->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT book.isbn, book.name, book.author, book.cost, book.genre, book.publishing_house FROM book WHERE book.name = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("isbnAddB");
            dt->Columns->Add("nameAddB");
            dt->Columns->Add("authorAddB");
            dt->Columns->Add("costAddB");
            dt->Columns->Add("genreAddB");
            dt->Columns->Add("publishing_houseAddB");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["isbnAddB"] = gcnew System::String(res->getString("isbn").c_str());
                row["nameAddB"] = gcnew System::String(res->getString("name").c_str());
                row["authorAddB"] = gcnew System::String(res->getString("author").c_str());
                row["costAddB"] = gcnew System::String(res->getString("cost").c_str());
                row["genreAddB"] = gcnew System::String(res->getString("genre").c_str());
                row["publishing_houseAddB"] = gcnew System::String(res->getString("publishing_house").c_str());
                dt->Rows->Add(row);
            }
            dgvAddB->DataSource = dt;
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
System::Void kurs::Seller::buttonAddB_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ nameInput = textAddBName->Text;
    std::string nameInp = msclr::interop::marshal_as<std::string>(nameInput);
    String^ authorInput = textAddBAuthor->Text;
    std::string authorInp = msclr::interop::marshal_as<std::string>(authorInput);
    String^ costInput = textAddBCost->Text;
    std::string costInp = msclr::interop::marshal_as<std::string>(costInput);
    String^ genreInput = textAddBGenre->Text;
    std::string genreInp = msclr::interop::marshal_as<std::string>(genreInput);
    String^ phInput = textAddBPH->Text;
    std::string phInp = msclr::interop::marshal_as<std::string>(phInput);
    if (nameInp.empty() || costInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("INSERT INTO book(name, author, cost, genre, publishing_house) VALUES(?,?,?,?,?)");
        pstmt->setString(1, nameInp);
        pstmt->setString(2, authorInp);
        pstmt->setString(3, costInp);
        pstmt->setString(4, genreInp);
        pstmt->setString(5, phInp);
        pstmt->execute();
        buttonBook2_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Seller::buttonBuyer3_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->groupBoxEdBuy->Visible = true;
    this->groupBoxEdBuy->Enabled = true;
    this->groupBoxEdPur->Visible = false;
    this->groupBoxEdPur->Enabled = false;
    this->groupBoxEdB->Visible = false;
    this->groupBoxEdB->Enabled = false;
    try
    {
        pstmt = con->prepareStatement("SELECT login.login, login.password, buyer.name, buyer.contact_number FROM login INNER JOIN buyer ON login.login = buyer.login");
        res = pstmt->executeQuery();
        System::Data::DataTable^ dt = gcnew System::Data::DataTable();
        dt->Columns->Add("loginEdBuy");
        dt->Columns->Add("passwordEdBuy");
        dt->Columns->Add("nameEdBuy");
        dt->Columns->Add("contact_NumberEdBuy");
        while (res->next())
        {
            DataRow^ row = dt->NewRow();
            row["loginEdBuy"] = gcnew System::String(res->getString("login").c_str());
            row["passwordEdBuy"] = gcnew System::String(res->getString("password").c_str());
            row["nameEdBuy"] = gcnew System::String(res->getString("name").c_str());
            row["contact_NumberEdBuy"] = gcnew System::String(res->getString("contact_number").c_str());
            dt->Rows->Add(row);
        }
        dgvEdBuy->DataSource = dt;
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonSearchEd_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ SearchInput = textSearchEd->Text;
    std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
    try
    {
        pstmt = con->prepareStatement("SELECT login.login, login.password, buyer.name, buyer.contact_number FROM login INNER JOIN buyer ON login.login = buyer.login WHERE login.login = ?");
        pstmt->setString(1, search);
        res = pstmt->executeQuery();
        System::Data::DataTable^ dt = gcnew System::Data::DataTable();
        dt->Columns->Add("loginEdBuy");
        dt->Columns->Add("passwordEdBuy");
        dt->Columns->Add("nameEdBuy");
        dt->Columns->Add("contact_NumberEdBuy");
        while (res->next())
        {
            DataRow^ row = dt->NewRow();
            row["loginEdBuy"] = gcnew System::String(res->getString("login").c_str());
            row["passwordEdBuy"] = gcnew System::String(res->getString("password").c_str());
            row["nameEdBuy"] = gcnew System::String(res->getString("name").c_str());
            row["contact_NumberEdBuy"] = gcnew System::String(res->getString("contact_number").c_str());
            dt->Rows->Add(row);
        }
        dgvEdBuy->DataSource = dt;
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::dgvEdBuy_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0)
    {
        DataGridViewRow^ selectedRow = dgvEdBuy->Rows[e->RowIndex];
        textEdBuyLog->Text = selectedRow->Cells["loginEdBuy"]->Value->ToString();
        textEdBuyPass->Text = selectedRow->Cells["passwordEdBuy"]->Value->ToString();
        textEdBuyName->Text = selectedRow->Cells["nameEdBuy"]->Value->ToString();
        textEdBuyNum->Text = selectedRow->Cells["contact_NumberEdBuy"]->Value->ToString();
    }
}
System::Void kurs::Seller::buttonEdBuy_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ loginInput = textEdBuyLog->Text;
    std::string login = msclr::interop::marshal_as<std::string>(loginInput);
    String^ passwordInput = textEdBuyPass->Text;
    std::string passwordInp = msclr::interop::marshal_as<std::string>(passwordInput);
    String^ NameInput = textEdBuyName->Text;
    std::string name = msclr::interop::marshal_as<std::string>(NameInput);
    String^ NumberInput = textEdBuyNum->Text;
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
        buttonBuyer3_Click(sender, e);
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonPurchase3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxEdBuy->Visible = true;
        this->groupBoxEdBuy->Enabled = true;
        this->groupBoxEdPur->Visible = true;
        this->groupBoxEdPur->Enabled = true;
        this->groupBoxEdB->Visible = false;
        this->groupBoxEdB->Enabled = false;
        comboEdPurLogBuy->Items->Clear();
        comboEdPurB->Items->Clear();
        String^ loginEmpInput = comboEdPurLogEmp->Text;
        std::string logEmpInp = msclr::interop::marshal_as<std::string>(loginEmpInput);
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn WHERE purchase.login_employee = ?");
            pstmt->setString(1, logEmpInp);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("idEdPur");
            dt->Columns->Add("loginEdPur");
            dt->Columns->Add("loginEmpEdPur");
            dt->Columns->Add("bookEdPur");
            dt->Columns->Add("costEdPur");
            dt->Columns->Add("quantityEdPur");
            dt->Columns->Add("dateEdPur");
            dt->Columns->Add("timeEdPur");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["idEdPur"] = gcnew System::String(res->getString("purchase_id").c_str());
                row["loginEdPur"] = gcnew System::String(res->getString("login").c_str());
                row["loginEmpEdPur"] = gcnew System::String(res->getString("login_employee").c_str());
                row["bookEdPur"] = gcnew System::String(res->getString("name").c_str());
                row["costEdPur"] = gcnew System::String(res->getString("cost").c_str());
                row["quantityEdPur"] = gcnew System::String(res->getString("quantity").c_str());
                row["dateEdPur"] = gcnew System::String(res->getString("date").c_str());
                row["timeEdPur"] = gcnew System::String(res->getString("time").c_str());
                dt->Rows->Add(row);
            }
            dgvEdPur->DataSource = dt;
            pstmt = con->prepareStatement("SELECT buyer.login FROM buyer");
            res = pstmt->executeQuery();
            while (res->next())
            {
                comboEdPurLogBuy->Items->Add(gcnew System::String(res->getString("login").c_str()));
            }
            pstmt = con->prepareStatement("SELECT book.name FROM book");
            res = pstmt->executeQuery();
            while (res->next())
            {
                comboEdPurB->Items->Add(gcnew System::String(res->getString("name").c_str()));
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
System::Void kurs::Seller::buttonSearchEd2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ loginEmpInput = comboEdPurLogEmp->Text;
        std::string logEmpInp = msclr::interop::marshal_as<std::string>(loginEmpInput);
        String^ SearchInput = textSearchEd2->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn WHERE purchase.login = ? AND purchase.login_employee = ?");
            pstmt->setString(1, search);
            pstmt->setString(2, logEmpInp);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("idEdPur");
            dt->Columns->Add("loginEdPur");
            dt->Columns->Add("loginEmpEdPur");
            dt->Columns->Add("bookEdPur");
            dt->Columns->Add("costEdPur");
            dt->Columns->Add("quantityEdPur");
            dt->Columns->Add("dateEdPur");
            dt->Columns->Add("timeEdPur");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["idEdPur"] = gcnew System::String(res->getString("purchase_id").c_str());
                row["loginEdPur"] = gcnew System::String(res->getString("login").c_str());
                row["loginEmpEdPur"] = gcnew System::String(res->getString("login_employee").c_str());
                row["bookEdPur"] = gcnew System::String(res->getString("name").c_str());
                row["costEdPur"] = gcnew System::String(res->getString("cost").c_str());
                row["quantityEdPur"] = gcnew System::String(res->getString("quantity").c_str());
                row["dateEdPur"] = gcnew System::String(res->getString("date").c_str());
                row["timeEdPur"] = gcnew System::String(res->getString("time").c_str());
                dt->Rows->Add(row);
            }
            dgvEdPur->DataSource = dt;
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
System::Void kurs::Seller::dgvEdPur_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0)
    {
        DataGridViewRow^ selectedRow = dgvEdPur->Rows[e->RowIndex];
        textEdPurId->Text = selectedRow->Cells["idEdPur"]->Value->ToString();
        comboEdPurLogBuy->Text = selectedRow->Cells["loginEdPur"]->Value->ToString();
        comboEdPurB->Text = selectedRow->Cells["bookEdPur"]->Value->ToString();
        textEdPurCost->Text = selectedRow->Cells["costEdPur"]->Value->ToString();
        numericEdPurQua->Text = selectedRow->Cells["quantityEdPur"]->Value->ToString();
        dateEdPurDate->Text = selectedRow->Cells["dateEdPur"]->Value->ToString();
        timeEdPurTime->Text = selectedRow->Cells["timeEdPur"]->Value->ToString();
    }
}
System::Void kurs::Seller::buttonEdPur_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ loginInput = comboEdPurLogBuy->Text;
    std::string logInp = msclr::interop::marshal_as<std::string>(loginInput);
    String^ loginEmpInput = comboEdPurLogEmp->Text;
    std::string logEmpInp = msclr::interop::marshal_as<std::string>(loginEmpInput);
    String^ idInput = textEdPurId->Text;
    std::string idInp = msclr::interop::marshal_as<std::string>(idInput);
    String^ bookInput = comboEdPurB->Text;
    std::string bInp = msclr::interop::marshal_as<std::string>(bookInput);
    String^ quaInput = numericEdPurQua->Text;
    std::string qInp = msclr::interop::marshal_as<std::string>(quaInput);
    int intqInp = std::stoi(qInp);
    System::DateTime selectedDateTime1 = dateEdPurDate->Value;
    System::String^ selectedDateStr = selectedDateTime1.ToString("yyyy-MM-dd");
    std::string selectedDateSstr = msclr::interop::marshal_as<std::string>(selectedDateStr);
    System::DateTime selectedDateTime = timeEdPurTime->Value;
    System::String^ selectedTimeStr = selectedDateTime.ToString("HH:mm");
    std::string selectedTimeStdStr = msclr::interop::marshal_as<std::string>(selectedTimeStr);
    if (logInp.empty() || logEmpInp.empty() || bInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("UPDATE bookstore.purchase SET login = ?, login_employee = ? WHERE purchase_id = ?");
        pstmt->setString(1, logInp);
        pstmt->setString(2, logEmpInp);
        pstmt->setString(3, idInp);
        pstmt->execute();
        pstmt = con->prepareStatement("SELECT book.isbn, book.cost FROM book WHERE book.name = ?");
        pstmt->setString(1, bInp);
        res = pstmt->executeQuery();
        std::string isbnInp;
        std::string totalCostString;
        while (res->next())
        {
            String^ isbnInput = gcnew System::String(res->getString("isbn").c_str());
            isbnInp = msclr::interop::marshal_as<std::string>(isbnInput);
            float totalCostInput = intqInp * (res->getDouble("cost"));
            totalCostString = std::to_string(totalCostInput);
        }
        pstmt = con->prepareStatement("UPDATE bookstore.transaction SET date = ?, time = ?, amount = ? WHERE purchase_id = ?");
        pstmt->setString(1, selectedDateSstr);
        pstmt->setString(2, selectedTimeStdStr);
        pstmt->setString(3, totalCostString);
        pstmt->setString(4, idInp);
        pstmt->execute();
        pstmt = con->prepareStatement("UPDATE bookstore.purchase_book SET isbn = ?, date = ?, time = ?, quantity = ?, cost = ? WHERE purchase_id = ?");
        pstmt->setString(1, isbnInp);
        pstmt->setString(2, selectedDateSstr);
        pstmt->setString(3, selectedTimeStdStr);
        pstmt->setString(4, qInp);
        pstmt->setString(5, totalCostString);
        pstmt->setString(6, idInp);
        pstmt->execute();
        buttonPurchase3_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Seller::buttonBook3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxEdBuy->Visible = true;
        this->groupBoxEdBuy->Enabled = true;
        this->groupBoxEdPur->Visible = true;
        this->groupBoxEdPur->Enabled = true;
        this->groupBoxEdB->Visible = true;
        this->groupBoxEdB->Enabled = true;
        try
        {
            pstmt = con->prepareStatement("SELECT book.isbn, book.name, book.author, book.cost, book.genre, book.publishing_house FROM book");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("isbnEdB");
            dt->Columns->Add("nameEdB");
            dt->Columns->Add("authorEdB");
            dt->Columns->Add("costEdB");
            dt->Columns->Add("genreEdB");
            dt->Columns->Add("publishing_houseEdB");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["isbnEdB"] = gcnew System::String(res->getString("isbn").c_str());
                row["nameEdB"] = gcnew System::String(res->getString("name").c_str());
                row["authorEdB"] = gcnew System::String(res->getString("author").c_str());
                row["costEdB"] = gcnew System::String(res->getString("cost").c_str());
                row["genreEdB"] = gcnew System::String(res->getString("genre").c_str());
                row["publishing_houseEdB"] = gcnew System::String(res->getString("publishing_house").c_str());
                dt->Rows->Add(row);
            }
            dgvEdB->DataSource = dt;
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
System::Void kurs::Seller::buttonSearchEd5_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchEd5->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT book.isbn, book.name, book.author, book.cost, book.genre, book.publishing_house FROM book WHERE book.name = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("isbnEdB");
            dt->Columns->Add("nameEdB");
            dt->Columns->Add("authorEdB");
            dt->Columns->Add("costEdB");
            dt->Columns->Add("genreEdB");
            dt->Columns->Add("publishing_houseEdB");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["isbnEdB"] = gcnew System::String(res->getString("isbn").c_str());
                row["nameEdB"] = gcnew System::String(res->getString("name").c_str());
                row["authorEdB"] = gcnew System::String(res->getString("author").c_str());
                row["costEdB"] = gcnew System::String(res->getString("cost").c_str());
                row["genreEdB"] = gcnew System::String(res->getString("genre").c_str());
                row["publishing_houseEdB"] = gcnew System::String(res->getString("publishing_house").c_str());
                dt->Rows->Add(row);
            }
            dgvEdB->DataSource = dt;
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
System::Void kurs::Seller::dgvEdB_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0)
    {
        DataGridViewRow^ selectedRow = dgvEdB->Rows[e->RowIndex];
        textEdBIsbn->Text = selectedRow->Cells["isbnEdB"]->Value->ToString();
        textEdBName->Text = selectedRow->Cells["nameEdB"]->Value->ToString();
        textEdBAuthor->Text = selectedRow->Cells["authorEdB"]->Value->ToString();
        textEdBCost->Text = selectedRow->Cells["costEdB"]->Value->ToString();
        textEdBGenre->Text = selectedRow->Cells["genreEdB"]->Value->ToString();
        textEdBPH->Text = selectedRow->Cells["publishing_houseEdB"]->Value->ToString();
    }
}
System::Void kurs::Seller::buttonEdB_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ nameInput = textEdBName->Text;
    std::string nameInp = msclr::interop::marshal_as<std::string>(nameInput);
    String^ authorInput = textEdBAuthor->Text;
    std::string authorInp = msclr::interop::marshal_as<std::string>(authorInput);
    String^ costInput = textEdBCost->Text;
    std::string costInp = msclr::interop::marshal_as<std::string>(costInput);
    String^ genreInput = textEdBGenre->Text;
    std::string genreInp = msclr::interop::marshal_as<std::string>(genreInput);
    String^ phInput = textEdBPH->Text;
    std::string phInp = msclr::interop::marshal_as<std::string>(phInput);
    String^ isbnInput = textEdBIsbn->Text;
    std::string isbnInp = msclr::interop::marshal_as<std::string>(isbnInput);
    if (nameInp.empty() || costInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("UPDATE bookstore.book SET name = ?, author = ?, cost = ?, genre = ?, publishing_house = ? WHERE isbn = ?");
        pstmt->setString(1, nameInp);
        pstmt->setString(2, authorInp);
        pstmt->setString(3, costInp);
        pstmt->setString(4, genreInp);
        pstmt->setString(5, phInp);
        pstmt->setString(6, isbnInp);
        pstmt->execute();
        buttonBook3_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Seller::buttonBuyer4_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->groupBoxDelBuy->Visible = true;
    this->groupBoxDelBuy->Enabled = true;
    this->groupBoxDelPur->Visible = false;
    this->groupBoxDelPur->Enabled = false;
    this->groupBoxDelB->Visible = false;
    this->groupBoxDelB->Enabled = false;
    try
    {
        pstmt = con->prepareStatement("SELECT login.login, login.password, buyer.name, buyer.contact_number FROM login INNER JOIN buyer ON login.login = buyer.login");
        res = pstmt->executeQuery();
        System::Data::DataTable^ dt = gcnew System::Data::DataTable();
        dt->Columns->Add("loginDelBuy");
        dt->Columns->Add("passwordDelBuy");
        dt->Columns->Add("nameDelBuy");
        dt->Columns->Add("contact_NumberDelBuy");
        while (res->next())
        {
            DataRow^ row = dt->NewRow();
            row["loginDelBuy"] = gcnew System::String(res->getString("login").c_str());
            row["passwordDelBuy"] = gcnew System::String(res->getString("password").c_str());
            row["nameDelBuy"] = gcnew System::String(res->getString("name").c_str());
            row["contact_NumberDelBuy"] = gcnew System::String(res->getString("contact_number").c_str());
            dt->Rows->Add(row);
        }
        dgvDelBuy->DataSource = dt;
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonSearchDel_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ SearchInput = textSearchDel->Text;
    std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
    try
    {
        pstmt = con->prepareStatement("SELECT login.login, login.password, buyer.name, buyer.contact_number FROM login INNER JOIN buyer ON login.login = buyer.login WHERE login.login = ?");
        pstmt->setString(1, search);
        res = pstmt->executeQuery();
        System::Data::DataTable^ dt = gcnew System::Data::DataTable();
        dt->Columns->Add("loginDelBuy");
        dt->Columns->Add("passwordDelBuy");
        dt->Columns->Add("nameDelBuy");
        dt->Columns->Add("contact_NumberDelBuy");
        while (res->next())
        {
            DataRow^ row = dt->NewRow();
            row["loginDelBuy"] = gcnew System::String(res->getString("login").c_str());
            row["passwordDelBuy"] = gcnew System::String(res->getString("password").c_str());
            row["nameDelBuy"] = gcnew System::String(res->getString("name").c_str());
            row["contact_NumberDelBuy"] = gcnew System::String(res->getString("contact_number").c_str());
            dt->Rows->Add(row);
        }
        dgvDelBuy->DataSource = dt;
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonDelBuy_Click(System::Object^ sender, System::EventArgs^ e)
{
    bool checkVisit = true, checkPurchase = true;
    String^ Input = dgvDelBuy->CurrentRow->Cells["loginDelBuy"]->Value->ToString();
    std::string Inp = msclr::interop::marshal_as<std::string>(Input);
    try
    {
        pstmt = con->prepareStatement("SELECT visit.login FROM visit WHERE visit.login = ?");
        pstmt->setString(1, Inp);
        res = pstmt->executeQuery();
        if (!res->next()) {
            checkVisit = false;
        }
        pstmt = con->prepareStatement("SELECT purchase.login FROM purchase WHERE purchase.login = ?");
        pstmt->setString(1, Inp);
        res = pstmt->executeQuery();
        if (!res->next()) {
            checkPurchase = false;
        }
        if (checkVisit) {
            MessageBox::Show("The buyer has a visit. They must be removed first.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
            //buttonVisit4_Click(sender, e);
        }
        if (checkPurchase) {
            MessageBox::Show("The buyer has a purchase. They must be removed first.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
            buttonPurchase4_Click(sender, e);
        }
        if (!checkVisit && !checkPurchase) {
            pstmt = con->prepareStatement("DELETE FROM buyer WHERE login = ?");
            pstmt->setString(1, Inp);
            pstmt->execute();
            pstmt = con->prepareStatement("DELETE FROM login WHERE login = ?");
            pstmt->setString(1, Inp);
            pstmt->execute();
            buttonBuyer4_Click(sender, e);
        }
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonPurchase4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxDelBuy->Visible = true;
        this->groupBoxDelBuy->Enabled = true;
        this->groupBoxDelPur->Visible = true;
        this->groupBoxDelPur->Enabled = true;
        this->groupBoxDelB->Visible = false;
        this->groupBoxDelB->Enabled = false;
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("idDelPur");
            dt->Columns->Add("loginDelPur");
            dt->Columns->Add("loginEmpDelPur");
            dt->Columns->Add("bookDelPur");
            dt->Columns->Add("costDelPur");
            dt->Columns->Add("quantityDelPur");
            dt->Columns->Add("dateDelPur");
            dt->Columns->Add("timeDelPur");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["idDelPur"] = gcnew System::String(res->getString("purchase_id").c_str());
                row["loginDelPur"] = gcnew System::String(res->getString("login").c_str());
                row["loginEmpDelPur"] = gcnew System::String(res->getString("login_employee").c_str());
                row["bookDelPur"] = gcnew System::String(res->getString("name").c_str());
                row["costDelPur"] = gcnew System::String(res->getString("cost").c_str());
                row["quantityDelPur"] = gcnew System::String(res->getString("quantity").c_str());
                row["dateDelPur"] = gcnew System::String(res->getString("date").c_str());
                row["timeDelPur"] = gcnew System::String(res->getString("time").c_str());
                dt->Rows->Add(row);
            }
            dgvDelPur->DataSource = dt;
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
System::Void kurs::Seller::buttonSearchDel2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchDel2->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn WHERE purchase.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("idDelPur");
            dt->Columns->Add("loginDelPur");
            dt->Columns->Add("loginEmpDelPur");
            dt->Columns->Add("bookDelPur");
            dt->Columns->Add("costDelPur");
            dt->Columns->Add("quantityDelPur");
            dt->Columns->Add("dateDelPur");
            dt->Columns->Add("timeDelPur");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["idDelPur"] = gcnew System::String(res->getString("purchase_id").c_str());
                row["loginDelPur"] = gcnew System::String(res->getString("login").c_str());
                row["loginEmpDelPur"] = gcnew System::String(res->getString("login_employee").c_str());
                row["bookDelPur"] = gcnew System::String(res->getString("name").c_str());
                row["costDelPur"] = gcnew System::String(res->getString("cost").c_str());
                row["quantityDelPur"] = gcnew System::String(res->getString("quantity").c_str());
                row["dateDelPur"] = gcnew System::String(res->getString("date").c_str());
                row["timeDelPur"] = gcnew System::String(res->getString("time").c_str());
                dt->Rows->Add(row);
            }
            dgvDelPur->DataSource = dt;
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
System::Void kurs::Seller::buttonDelPur_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ Input = dgvDelPur->CurrentRow->Cells["idDelPur"]->Value->ToString();
    std::string Inp = msclr::interop::marshal_as<std::string>(Input);
    try
    {
        pstmt = con->prepareStatement("DELETE FROM purchase_book WHERE purchase_id = ?");
        pstmt->setString(1, Inp);
        pstmt->execute();
        pstmt = con->prepareStatement("DELETE FROM transaction WHERE purchase_id = ?");
        pstmt->setString(1, Inp);
        pstmt->execute();
        pstmt = con->prepareStatement("DELETE FROM purchase WHERE purchase_id = ?");
        pstmt->setString(1, Inp);
        pstmt->execute();
        buttonPurchase4_Click(sender, e);
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonBook4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxDelBuy->Visible = true;
        this->groupBoxDelBuy->Enabled = true;
        this->groupBoxDelPur->Visible = true;
        this->groupBoxDelPur->Enabled = true;
        this->groupBoxDelB->Visible = true;
        this->groupBoxDelB->Enabled = true;
        try
        {
            pstmt = con->prepareStatement("SELECT book.isbn, book.name, book.author, book.cost, book.genre, book.publishing_house FROM book");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("isbnDelB");
            dt->Columns->Add("nameDelB");
            dt->Columns->Add("authorDelB");
            dt->Columns->Add("costDelB");
            dt->Columns->Add("genreDelB");
            dt->Columns->Add("publishing_houseDelB");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["isbnDelB"] = gcnew System::String(res->getString("isbn").c_str());
                row["nameDelB"] = gcnew System::String(res->getString("name").c_str());
                row["authorDelB"] = gcnew System::String(res->getString("author").c_str());
                row["costDelB"] = gcnew System::String(res->getString("cost").c_str());
                row["genreDelB"] = gcnew System::String(res->getString("genre").c_str());
                row["publishing_houseDelB"] = gcnew System::String(res->getString("publishing_house").c_str());
                dt->Rows->Add(row);
            }
            dgvDelB->DataSource = dt;
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
System::Void kurs::Seller::buttonSearchDel5_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchDel5->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT book.isbn, book.name, book.author, book.cost, book.genre, book.publishing_house FROM book WHERE book.name = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("isbnDelB");
            dt->Columns->Add("nameDelB");
            dt->Columns->Add("authorDelB");
            dt->Columns->Add("costDelB");
            dt->Columns->Add("genreDelB");
            dt->Columns->Add("publishing_houseDelB");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["isbnDelB"] = gcnew System::String(res->getString("isbn").c_str());
                row["nameDelB"] = gcnew System::String(res->getString("name").c_str());
                row["authorDelB"] = gcnew System::String(res->getString("author").c_str());
                row["costDelB"] = gcnew System::String(res->getString("cost").c_str());
                row["genreDelB"] = gcnew System::String(res->getString("genre").c_str());
                row["publishing_houseDelB"] = gcnew System::String(res->getString("publishing_house").c_str());
                dt->Rows->Add(row);
            }
            dgvDelB->DataSource = dt;
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
System::Void kurs::Seller::buttonDelB_Click(System::Object^ sender, System::EventArgs^ e)
{
    bool checkPurchase = true;
    String^ Input = dgvDelB->CurrentRow->Cells["isbnDelB"]->Value->ToString();
    std::string Inp = msclr::interop::marshal_as<std::string>(Input);
    try
    {
        pstmt = con->prepareStatement("SELECT purchase_book.isbn FROM purchase_book WHERE purchase_book.isbn = ?");
        pstmt->setString(1, Inp);
        res = pstmt->executeQuery();
        if (!res->next()) {
            checkPurchase = false;
        }
        if (checkPurchase) {
            MessageBox::Show("This book has purchase. They must be removed first.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
            buttonPurchase4_Click(sender, e);
        }
        if (!checkPurchase) {
            pstmt = con->prepareStatement("DELETE FROM book WHERE isbn = ?");
            pstmt->setString(1, Inp);
            pstmt->execute();
            buttonBook4_Click(sender, e);
        }
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Seller::buttonReq1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = true;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        String^ SearchInput = textReq1->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, buyer.login, book.name, purchase_book.date, purchase_book.time, purchase_book.quantity, purchase_book.cost FROM buyer JOIN purchase ON buyer.login = purchase.login JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id JOIN book ON purchase_book.isbn = book.isbn WHERE book.name = ? ORDER BY purchase_book.date DESC, purchase_book.time DESC");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("IDReq1");
            dt->Columns->Add("loginReq1");
            dt->Columns->Add("nameReq1");
            dt->Columns->Add("dateReq1");
            dt->Columns->Add("timeReq1");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["IDReq1"] = gcnew System::String(res->getString("purchase_id").c_str());
                row["LoginReq1"] = gcnew System::String(res->getString("login").c_str());
                row["nameReq1"] = gcnew System::String(res->getString("name").c_str());
                row["dateReq1"] = gcnew System::String(res->getString("date").c_str());
                row["timeReq1"] = gcnew System::String(res->getString("time").c_str());
                dt->Rows->Add(row);
            }
            dgvReq1->DataSource = dt;
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
System::Void kurs::Seller::buttonReq3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq3->Visible = true;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        System::DateTime selectedDateTime1 = date1Req3->Value;
        System::String^ selectedDateStr = selectedDateTime1.ToString("yyyy-MM-dd");
        std::string selectedDateSstr = msclr::interop::marshal_as<std::string>(selectedDateStr);
        System::DateTime selectedDateTime2 = date2Req3->Value;
        System::String^ selectedDateStr2 = selectedDateTime2.ToString("yyyy-MM-dd");
        std::string selectedDateSstr2 = msclr::interop::marshal_as<std::string>(selectedDateStr2);
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, buyer.login, book.name, purchase_book.date, purchase_book.time, purchase_book.cost FROM buyer JOIN purchase ON buyer.login = purchase.login JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id JOIN book ON purchase_book.isbn = book.isbn WHERE purchase_book.date BETWEEN ? AND ? ORDER BY purchase_book.date, purchase_book.time");
            pstmt->setString(1, selectedDateSstr);
            pstmt->setString(2, selectedDateSstr2);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("IDReq3");
            dt->Columns->Add("loginReq3");
            dt->Columns->Add("nameReq3");
            dt->Columns->Add("dateReq3");
            dt->Columns->Add("timeReq3");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["IDReq3"] = gcnew System::String(res->getString("purchase_id").c_str());
                row["LoginReq3"] = gcnew System::String(res->getString("login").c_str());
                row["nameReq3"] = gcnew System::String(res->getString("name").c_str());
                row["dateReq3"] = gcnew System::String(res->getString("date").c_str());
                row["timeReq3"] = gcnew System::String(res->getString("time").c_str());
                dt->Rows->Add(row);
            }
            dgvReq3->DataSource = dt;
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
System::Void kurs::Seller::buttonReq4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = true;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        try
        {
            pstmt = con->prepareStatement("SELECT COUNT(*) FROM purchase_book WHERE purchase_book.date BETWEEN DATE_SUB(CURDATE(), INTERVAL 7 DAY) AND CURDATE(); ");
            res = pstmt->executeQuery();
            while (res->next())
            {
                String^ message = "In the last week, buyers made " + (gcnew System::String(res->getString("COUNT(*)").c_str())) + " purchases";
                this->textReq4->Text = message;
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
System::Void kurs::Seller::buttonReq5_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = true;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        try
        {
            pstmt = con->prepareStatement("SELECT  buyer.login, COUNT(*) FROM buyer JOIN purchase ON buyer.login = purchase.login JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id GROUP BY buyer.login ORDER BY COUNT(*) DESC");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginReq5");
            dt->Columns->Add("countReq5");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginReq5"] = gcnew System::String(res->getString("login").c_str());
                row["countReq5"] = gcnew System::String(res->getString("COUNT(*)").c_str());
                dt->Rows->Add(row);
            }
            dgvReq5->DataSource = dt;
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
System::Void kurs::Seller::buttonReq6_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = true;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        try
        {
            pstmt = con->prepareStatement("SELECT * FROM buyer WHERE login = ALL(SELECT login FROM purchase GROUP BY login HAVING COUNT(purchase_id) = (SELECT MAX(purchase_count) FROM(SELECT COUNT(purchase_id) AS purchase_count FROM purchase GROUP BY login) AS purchase_counts))");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            while (res->next())
            {
                String^ message = "Buyer with the largest number of purchases: " + (gcnew System::String(res->getString("login").c_str()));
                this->textReq6->Text = message;
                return;
            }
            String^ message = "Buyer with the largest number of purchases: There are several more buyers";
            this->textReq6->Text = message;
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
System::Void kurs::Seller::buttonReq7_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = true;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        try
        {
            pstmt = con->prepareStatement("SELECT bookstore.name, buyer.login, (SELECT COUNT(*) FROM visit WHERE visit.login = buyer.login AND visit.contact_number = bookstore.contact_number) AS visit_count FROM bookstore JOIN visit ON bookstore.contact_number = visit.contact_number JOIN buyer ON visit.login = buyer.login GROUP BY bookstore.contact_number, buyer.login");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("nameReq7");
            dt->Columns->Add("loginReq7");
            dt->Columns->Add("visitReq7");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["nameReq7"] = gcnew System::String(res->getString("name").c_str());
                row["loginReq7"] = gcnew System::String(res->getString("login").c_str());
                row["visitReq7"] = gcnew System::String(res->getString("visit_count").c_str());
                dt->Rows->Add(row);
            }
            dgvReq7->DataSource = dt;
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
System::Void kurs::Seller::buttonReq8_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = true;
        this->dgvReq9->Visible = false;
        try
        {
            pstmt = con->prepareStatement("SELECT buyer.login, buyer.contact_number FROM buyer WHERE buyer.login NOT IN (SELECT visit.login FROM visit WHERE WEEK (visit.date_visit) = WEEK(CURDATE()))");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginReq8");
            dt->Columns->Add("numberReq8");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginReq8"] = gcnew System::String(res->getString("login").c_str());
                row["numberReq8"] = gcnew System::String(res->getString("contact_number").c_str());
                dt->Rows->Add(row);
            }
            dgvReq8->DataSource = dt;
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
System::Void kurs::Seller::buttonReq9_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = true;
        try
        {
            pstmt = con->prepareStatement("SELECT buyer.login AS buyer_name,'Made a purchase' AS comment FROM buyer WHERE buyer.login IN(SELECT purchase.login FROM purchase) UNION SELECT buyer.login AS buyer_name, 'Did not make a purchase' AS comment FROM buyer WHERE buyer.login NOT IN(SELECT purchase.login FROM purchase)");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginReq9");
            dt->Columns->Add("comReq9");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginReq9"] = gcnew System::String(res->getString("buyer_name").c_str());
                row["comReq9"] = gcnew System::String(res->getString("comment").c_str());
                dt->Rows->Add(row);
            }
            dgvReq9->DataSource = dt;
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
