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
System::Void kurs::Admin::InitializeDatabaseConnection()
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
System::Void kurs::Admin::CloseDatabaseConnection()
{
        if (this->res != nullptr) delete this->res;
        if (this->pstmt != nullptr) delete this->pstmt;
        if (this->stmt != nullptr) delete this->stmt;
        if (this->con != nullptr) delete this->con;
}
System::Void kurs::Admin::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    authForm^ auth = gcnew authForm();
    auth->Show();
}
System::Void kurs::Admin::buttonRevision_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonBuyer_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->groupBoxRevBuy->Visible = true;
    this->groupBoxRevBuy->Enabled = true;
    this->groupBoxRevPur->Visible = false;
    this->groupBoxRevPur->Enabled = false;
    this->groupBoxRevEmp->Visible = false;
    this->groupBoxRevEmp->Enabled = false;
    this->groupBoxRevBS->Visible = false;
    this->groupBoxRevBS->Enabled = false;
    this->groupBoxRevB->Visible = false;
    this->groupBoxRevB->Enabled = false;
    this->groupBoxRevA->Visible = false;
    this->groupBoxRevA->Enabled = false;
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
System::Void kurs::Admin::buttonEdit_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonDel_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonReq_Click(System::Object^ sender, System::EventArgs^ e)
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
}
System::Void kurs::Admin::buttonSearch_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonPurchase_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxRevBuy->Visible = true;
        this->groupBoxRevBuy->Enabled = true;
        this->groupBoxRevPur->Visible = true;
        this->groupBoxRevPur->Enabled = true;
        this->groupBoxRevEmp->Visible = false;
        this->groupBoxRevEmp->Enabled = false;
        this->groupBoxRevBS->Visible = false;
        this->groupBoxRevBS->Enabled = false;
        this->groupBoxRevB->Visible = false;
        this->groupBoxRevB->Enabled = false;
        this->groupBoxRevA->Visible = false;
        this->groupBoxRevA->Enabled = false;
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
System::Void kurs::Admin::buttonSearch2_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonPurCal_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonEmployee_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxRevBuy->Visible = true;
        this->groupBoxRevBuy->Enabled = true;
        this->groupBoxRevPur->Visible = true;
        this->groupBoxRevPur->Enabled = true;
        this->groupBoxRevEmp->Visible = true;
        this->groupBoxRevEmp->Enabled = true;
        this->groupBoxRevBS->Visible = false;
        this->groupBoxRevBS->Enabled = false;
        this->groupBoxRevB->Visible = false;
        this->groupBoxRevB->Enabled = false;
        this->groupBoxRevA->Visible = false;
        this->groupBoxRevA->Enabled = false;
        this->groupBoxRevV->Visible = false;
        this->groupBoxRevV->Enabled = false;
        try
        {
            pstmt = con->prepareStatement("SELECT employee.login, login.password, employee.nameE, bookstore.name, employee.track_number, schedule.working_days_of_the_week, schedule.additional_days_off FROM employee INNER JOIN schedule ON employee.login = schedule.login INNER JOIN bookstore ON employee.contact_number = bookstore.contact_number INNER JOIN login ON employee.login = login.login");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginRevEmpEmp");
            dt->Columns->Add("passwordRevEmp");
            dt->Columns->Add("nameRevEmpEmp");
            dt->Columns->Add("nameRevEmpBS");
            dt->Columns->Add("track_numberRevEmp");
            dt->Columns->Add("working_days_of_the_week");
            dt->Columns->Add("additional_days_off");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginRevEmpEmp"] = gcnew System::String(res->getString("login").c_str());
                row["passwordRevEmp"] = gcnew System::String(res->getString("password").c_str());
                row["nameRevEmpEmp"] = gcnew System::String(res->getString("nameE").c_str());
                row["nameRevEmpBS"] = gcnew System::String(res->getString("name").c_str());
                row["track_numberRevEmp"] = gcnew System::String(res->getString("track_number").c_str());
                row["working_days_of_the_week"] = gcnew System::String(res->getString("working_days_of_the_week").c_str());
                row["additional_days_off"] = gcnew System::String(res->getString("additional_days_off").c_str());
                dt->Rows->Add(row);
            }
            dgvRevEmp->DataSource = dt;
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
System::Void kurs::Admin::buttonSearch3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearch3->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT employee.login, login.password, employee.nameE, bookstore.name, employee.track_number, schedule.working_days_of_the_week, schedule.additional_days_off FROM employee INNER JOIN schedule ON employee.login = schedule.login INNER JOIN bookstore ON employee.contact_number = bookstore.contact_number INNER JOIN login ON employee.login = login.login WHERE employee.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginRevEmpEmp");
            dt->Columns->Add("passwordRevEmp");
            dt->Columns->Add("nameRevEmpEmp");
            dt->Columns->Add("nameRevEmpBS");
            dt->Columns->Add("track_numberRevEmp");
            dt->Columns->Add("working_days_of_the_week");
            dt->Columns->Add("additional_days_off");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginRevEmpEmp"] = gcnew System::String(res->getString("login").c_str());
                row["passwordRevEmp"] = gcnew System::String(res->getString("password").c_str());
                row["nameRevEmpEmp"] = gcnew System::String(res->getString("nameE").c_str());
                row["nameRevEmpBS"] = gcnew System::String(res->getString("name").c_str());
                row["track_numberRevEmp"] = gcnew System::String(res->getString("track_number").c_str());
                row["working_days_of_the_week"] = gcnew System::String(res->getString("working_days_of_the_week").c_str());
                row["additional_days_off"] = gcnew System::String(res->getString("additional_days_off").c_str());
                dt->Rows->Add(row);
            }
            dgvRevEmp->DataSource = dt;
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
System::Void kurs::Admin::buttonBookstore_Click_1(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxRevBuy->Visible = true;
        this->groupBoxRevBuy->Enabled = true;
        this->groupBoxRevPur->Visible = true;
        this->groupBoxRevPur->Enabled = true;
        this->groupBoxRevEmp->Visible = true;
        this->groupBoxRevEmp->Enabled = true;
        this->groupBoxRevBS->Visible = true;
        this->groupBoxRevBS->Enabled = true;
        this->groupBoxRevB->Visible = false;
        this->groupBoxRevB->Enabled = false;
        this->groupBoxRevA->Visible = false;
        this->groupBoxRevA->Enabled = false;
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
System::Void kurs::Admin::buttonSearch4_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonBook_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxRevBuy->Visible = true;
        this->groupBoxRevBuy->Enabled = true;
        this->groupBoxRevPur->Visible = true;
        this->groupBoxRevPur->Enabled = true;
        this->groupBoxRevEmp->Visible = true;
        this->groupBoxRevEmp->Enabled = true;
        this->groupBoxRevBS->Visible = true;
        this->groupBoxRevBS->Enabled = true;
        this->groupBoxRevB->Visible = true;
        this->groupBoxRevB->Enabled = true;
        this->groupBoxRevA->Visible = false;
        this->groupBoxRevA->Enabled = false;
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
System::Void kurs::Admin::buttonSearch5_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonSearchRevCost_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonLogin_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxRevBuy->Visible = true;
        this->groupBoxRevBuy->Enabled = true;
        this->groupBoxRevPur->Visible = true;
        this->groupBoxRevPur->Enabled = true;
        this->groupBoxRevEmp->Visible = true;
        this->groupBoxRevEmp->Enabled = true;
        this->groupBoxRevBS->Visible = true;
        this->groupBoxRevBS->Enabled = true;
        this->groupBoxRevB->Visible = true;
        this->groupBoxRevB->Enabled = true;
        this->groupBoxRevA->Visible = true;
        this->groupBoxRevA->Enabled = true;
        this->groupBoxRevV->Visible = false;
        this->groupBoxRevV->Enabled = false;
        try
        {
            pstmt = con->prepareStatement("SELECT login.login, login.password FROM login WHERE login.rights = ?");
            pstmt->setString(1, "1");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginRevA");
            dt->Columns->Add("passwordRevA");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginRevA"] = gcnew System::String(res->getString("login").c_str());
                row["passwordRevA"] = gcnew System::String(res->getString("password").c_str());
                dt->Rows->Add(row);
            }
            dgvRevA->DataSource = dt;
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
System::Void kurs::Admin::buttonSearch6_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearch6->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT login.login, login.password FROM login WHERE login.rights = ? AND login.login = ?");
            pstmt->setString(1, "1");
            pstmt->setString(2, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginRevA");
            dt->Columns->Add("passwordRevA");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginRevA"] = gcnew System::String(res->getString("login").c_str());
                row["passwordRevA"] = gcnew System::String(res->getString("password").c_str());
                dt->Rows->Add(row);
            }
            dgvRevA->DataSource = dt;
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
System::Void kurs::Admin::buttonVisit_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxRevBuy->Visible = true;
        this->groupBoxRevBuy->Enabled = true;
        this->groupBoxRevPur->Visible = true;
        this->groupBoxRevPur->Enabled = true;
        this->groupBoxRevEmp->Visible = true;
        this->groupBoxRevEmp->Enabled = true;
        this->groupBoxRevBS->Visible = true;
        this->groupBoxRevBS->Enabled = true;
        this->groupBoxRevB->Visible = true;
        this->groupBoxRevB->Enabled = true;
        this->groupBoxRevA->Visible = true;
        this->groupBoxRevA->Enabled = true;
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
System::Void kurs::Admin::buttonSearch7_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonVCal_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonBuyer2_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->groupBoxAddBuy->Visible = true;
    this->groupBoxAddBuy->Enabled = true;
    this->groupBoxAddPur->Visible = false;
    this->groupBoxAddPur->Enabled = false;
    this->groupBoxAddEmp->Visible = false;
    this->groupBoxAddEmp->Enabled = false;
    this->groupBoxAddBS->Visible = false;
    this->groupBoxAddBS->Enabled = false;
    this->groupBoxAddB->Visible = false;
    this->groupBoxAddB->Enabled = false;
    this->groupBoxAddA->Visible = false;
    this->groupBoxAddA->Enabled = false;
    this->groupBoxAddV->Visible = false;
    this->groupBoxAddV->Enabled = false;
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
System::Void kurs::Admin::buttonSearchAdd_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonAddBuy_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonPurchase2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxAddBuy->Visible = true;
        this->groupBoxAddBuy->Enabled = true;
        this->groupBoxAddPur->Visible = true;
        this->groupBoxAddPur->Enabled = true;
        this->groupBoxAddEmp->Visible = false;
        this->groupBoxAddEmp->Enabled = false;
        this->groupBoxAddBS->Visible = false;
        this->groupBoxAddBS->Enabled = false;
        this->groupBoxAddB->Visible = false;
        this->groupBoxAddB->Enabled = false;
        this->groupBoxAddA->Visible = false;
        this->groupBoxAddA->Enabled = false;
        this->groupBoxAddV->Visible = false;
        this->groupBoxAddV->Enabled = false;
        comboAddPurLogBuy->Items->Clear();
        comboAddPurLogEmp->Items->Clear();
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
            pstmt = con->prepareStatement("SELECT employee.login FROM employee");
            res = pstmt->executeQuery();
            while (res->next())
            {
                comboAddPurLogEmp->Items->Add(gcnew System::String(res->getString("login").c_str()));
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
System::Void kurs::Admin::buttonSearchAdd2_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonAddPur_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonEmployee2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
    this->groupBoxAddBuy->Visible = true;
    this->groupBoxAddBuy->Enabled = true;
    this->groupBoxAddPur->Visible = true;
    this->groupBoxAddPur->Enabled = true;
    this->groupBoxAddEmp->Visible = true;
    this->groupBoxAddEmp->Enabled = true;
    this->groupBoxAddBS->Visible = false;
    this->groupBoxAddBS->Enabled = false;
    this->groupBoxAddB->Visible = false;
    this->groupBoxAddB->Enabled = false;
    this->groupBoxAddA->Visible = false;
    this->groupBoxAddA->Enabled = false;
    this->groupBoxAddV->Visible = false;
    this->groupBoxAddV->Enabled = false;
    comboAddEmpBSName->Items->Clear();
    try
    {
        pstmt = con->prepareStatement("SELECT employee.login, login.password, employee.nameE, bookstore.name, employee.track_number, schedule.working_days_of_the_week, schedule.additional_days_off FROM employee INNER JOIN schedule ON employee.login = schedule.login INNER JOIN bookstore ON employee.contact_number = bookstore.contact_number INNER JOIN login ON employee.login = login.login");
        res = pstmt->executeQuery();
        System::Data::DataTable^ dt = gcnew System::Data::DataTable();
        dt->Columns->Add("loginAddEmp");
        dt->Columns->Add("passwordAddEmp");
        dt->Columns->Add("nameAddEmp");
        dt->Columns->Add("nameBSAddEmp");
        dt->Columns->Add("track_numberAddEmp");
        dt->Columns->Add("working_days_of_the_weekAddEmp");
        dt->Columns->Add("additional_days_offAddEmp");
        while (res->next())
        {
            DataRow^ row = dt->NewRow();
            row["loginAddEmp"] = gcnew System::String(res->getString("login").c_str());
            row["passwordAddEmp"] = gcnew System::String(res->getString("password").c_str());
            row["nameAddEmp"] = gcnew System::String(res->getString("nameE").c_str());
            row["nameBSAddEmp"] = gcnew System::String(res->getString("name").c_str());
            row["track_numberAddEmp"] = gcnew System::String(res->getString("track_number").c_str());
            row["working_days_of_the_weekAddEmp"] = gcnew System::String(res->getString("working_days_of_the_week").c_str());
            row["additional_days_offAddEmp"] = gcnew System::String(res->getString("additional_days_off").c_str());
            dt->Rows->Add(row);
        }
        dgvAddEmp->DataSource = dt;
        pstmt = con->prepareStatement("SELECT bookstore.name FROM bookstore");
        res = pstmt->executeQuery();
        while (res->next())
        {
            comboAddEmpBSName->Items->Add(gcnew System::String(res->getString("name").c_str()));
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
System::Void kurs::Admin::buttonSearchAdd3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchAdd3->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT employee.login, login.password, employee.nameE, bookstore.name, employee.track_number, schedule.working_days_of_the_week, schedule.additional_days_off FROM employee INNER JOIN schedule ON employee.login = schedule.login INNER JOIN bookstore ON employee.contact_number = bookstore.contact_number INNER JOIN login ON employee.login = login.login WHERE employee.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginAddEmp");
            dt->Columns->Add("passwordAddEmp");
            dt->Columns->Add("nameAddEmp");
            dt->Columns->Add("nameBSAddEmp");
            dt->Columns->Add("track_numberAddEmp");
            dt->Columns->Add("working_days_of_the_weekAddEmp");
            dt->Columns->Add("additional_days_offAddEmp");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginAddEmp"] = gcnew System::String(res->getString("login").c_str());
                row["passwordAddEmp"] = gcnew System::String(res->getString("password").c_str());
                row["nameAddEmp"] = gcnew System::String(res->getString("nameE").c_str());
                row["nameBSAddEmp"] = gcnew System::String(res->getString("name").c_str());
                row["track_numberAddEmp"] = gcnew System::String(res->getString("track_number").c_str());
                row["working_days_of_the_weekAddEmp"] = gcnew System::String(res->getString("working_days_of_the_week").c_str());
                row["additional_days_offAddEmp"] = gcnew System::String(res->getString("additional_days_off").c_str());
                dt->Rows->Add(row);
            }
            dgvAddEmp->DataSource = dt;
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
System::Void kurs::Admin::buttonAddEmp_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ loginEmpInput = textAddEmpLogin->Text;
    std::string logEmpInp = msclr::interop::marshal_as<std::string>(loginEmpInput);
    String^ nameInput = textAddEmpName->Text;
    std::string nameInp = msclr::interop::marshal_as<std::string>(nameInput);
    String^ bsInput = comboAddEmpBSName->Text;
    std::string bsInp = msclr::interop::marshal_as<std::string>(bsInput);
    String^ tnInput = textAddEmpTrack_number->Text;
    std::string tnInp = msclr::interop::marshal_as<std::string>(tnInput);
    String^ wdInput = textAddEmpWorking_days_of_the_week->Text;
    std::string wdInp = msclr::interop::marshal_as<std::string>(wdInput);
    String^ adInput = numericAddEmpAdditional_days_off->Text;
    std::string adInp = msclr::interop::marshal_as<std::string>(adInput);
    String^ passInput = textAddEmpPass->Text;
    std::string passInp = msclr::interop::marshal_as<std::string>(passInput);
    if (logEmpInp.empty() || nameInp.empty() || bsInp.empty() || passInp.empty() || wdInp.empty() || adInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("INSERT INTO login(login, password, rights) VALUES(?,?,?)");
        pstmt->setString(1, logEmpInp);
        pstmt->setString(2, passInp);
        pstmt->setInt(3, 2);
        pstmt->execute();
        pstmt = con->prepareStatement("SELECT bookstore.contact_number FROM bookstore WHERE bookstore.name = ?");
        pstmt->setString(1, bsInp);
        res = pstmt->executeQuery();
        std::string cnInp;
        while (res->next())
        {
            String^ cnInput = gcnew System::String(res->getString("contact_number").c_str());
            cnInp = msclr::interop::marshal_as<std::string>(cnInput);
        }
        pstmt = con->prepareStatement("INSERT INTO employee(login, contact_number, nameE, track_number) VALUES(?,?,?,?)");
        pstmt->setString(1, logEmpInp);
        pstmt->setString(2, cnInp);
        pstmt->setString(3, nameInp);
        pstmt->setString(4, tnInp);
        pstmt->execute();
        pstmt = con->prepareStatement("INSERT INTO schedule(login, working_days_of_the_week, additional_days_off) VALUES(?,?,?)");
        pstmt->setString(1, logEmpInp);
        pstmt->setString(2, wdInp);
        pstmt->setString(3, adInp);
        pstmt->execute();
        buttonEmployee2_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Admin::buttonBookstore2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxAddBuy->Visible = true;
        this->groupBoxAddBuy->Enabled = true;
        this->groupBoxAddPur->Visible = true;
        this->groupBoxAddPur->Enabled = true;
        this->groupBoxAddEmp->Visible = true;
        this->groupBoxAddEmp->Enabled = true;
        this->groupBoxAddBS->Visible = true;
        this->groupBoxAddBS->Enabled = true;
        this->groupBoxAddB->Visible = false;
        this->groupBoxAddB->Enabled = false;
        this->groupBoxAddA->Visible = false;
        this->groupBoxAddA->Enabled = false;
        this->groupBoxAddV->Visible = false;
        this->groupBoxAddV->Enabled = false;
        try
        {
            pstmt = con->prepareStatement("SELECT bookstore.name, bookstore.contact_number, bookstore.address, bookstore.work_schedule FROM bookstore");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("nameAddBS");
            dt->Columns->Add("contact_numberAddBS");
            dt->Columns->Add("addressAddBS");
            dt->Columns->Add("work_scheduleAddBS");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["nameAddBS"] = gcnew System::String(res->getString("name").c_str());
                row["contact_numberAddBS"] = gcnew System::String(res->getString("contact_number").c_str());
                row["addressAddBS"] = gcnew System::String(res->getString("address").c_str());
                row["work_scheduleAddBS"] = gcnew System::String(res->getString("work_schedule").c_str());
                dt->Rows->Add(row);
            }
            dgvAddBS->DataSource = dt;
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
System::Void kurs::Admin::buttonSearchAdd4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchAdd4->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT bookstore.name, bookstore.contact_number, bookstore.address, bookstore.work_schedule FROM bookstore WHERE bookstore.name = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("nameAddBS");
            dt->Columns->Add("contact_numberAddBS");
            dt->Columns->Add("addressAddBS");
            dt->Columns->Add("work_scheduleAddBS");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["nameAddBS"] = gcnew System::String(res->getString("name").c_str());
                row["contact_numberAddBS"] = gcnew System::String(res->getString("contact_number").c_str());
                row["addressAddBS"] = gcnew System::String(res->getString("address").c_str());
                row["work_scheduleAddBS"] = gcnew System::String(res->getString("work_schedule").c_str());
                dt->Rows->Add(row);
            }
            dgvAddBS->DataSource = dt;
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
System::Void kurs::Admin::buttonAddBS_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ nameInput = textAddBSName->Text;
    std::string nameInp = msclr::interop::marshal_as<std::string>(nameInput);
    String^ numbInput = textAddBSNumber->Text;
    std::string numbInp = msclr::interop::marshal_as<std::string>(numbInput);
    String^ addressInput = textAddBSAddress->Text;
    std::string addressInp = msclr::interop::marshal_as<std::string>(addressInput);
    String^ WSInput = textAddBSWS->Text;
    std::string WSInp = msclr::interop::marshal_as<std::string>(WSInput);
    if (numbInp.length() != 12 || numbInp.substr(0, 3) != "380") {
        MessageBox::Show("Not valid!", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    if (nameInp.empty() || numbInp.empty() || addressInp.empty() || WSInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("INSERT INTO bookstore(contact_number, name, address, work_schedule) VALUES(?,?,?,?)");
        pstmt->setString(1, numbInp);
        pstmt->setString(2, nameInp);
        pstmt->setString(3, addressInp);
        pstmt->setString(4, WSInp);
        pstmt->execute();
        buttonBookstore2_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Admin::buttonBook2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxAddBuy->Visible = true;
        this->groupBoxAddBuy->Enabled = true;
        this->groupBoxAddPur->Visible = true;
        this->groupBoxAddPur->Enabled = true;
        this->groupBoxAddEmp->Visible = true;
        this->groupBoxAddEmp->Enabled = true;
        this->groupBoxAddBS->Visible = true;
        this->groupBoxAddBS->Enabled = true;
        this->groupBoxAddB->Visible = true;
        this->groupBoxAddB->Enabled = true;
        this->groupBoxAddA->Visible = false;
        this->groupBoxAddA->Enabled = false;
        this->groupBoxAddV->Visible = false;
        this->groupBoxAddV->Enabled = false;
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
System::Void kurs::Admin::buttonSearchAdd5_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonAddB_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonLogin2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxAddBuy->Visible = true;
        this->groupBoxAddBuy->Enabled = true;
        this->groupBoxAddPur->Visible = true;
        this->groupBoxAddPur->Enabled = true;
        this->groupBoxAddEmp->Visible = true;
        this->groupBoxAddEmp->Enabled = true;
        this->groupBoxAddBS->Visible = true;
        this->groupBoxAddBS->Enabled = true;
        this->groupBoxAddB->Visible = true;
        this->groupBoxAddB->Enabled = true;
        this->groupBoxAddA->Visible = true;
        this->groupBoxAddA->Enabled = true;
        this->groupBoxAddV->Visible = false;
        this->groupBoxAddV->Enabled = false;
        try
        {
            pstmt = con->prepareStatement("SELECT login.login, login.password FROM login WHERE login.rights = ?");
            pstmt->setString(1, "1");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginAddA");
            dt->Columns->Add("passwordAddA");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginAddA"] = gcnew System::String(res->getString("login").c_str());
                row["passwordAddA"] = gcnew System::String(res->getString("password").c_str());
                dt->Rows->Add(row);
            }
            dgvAddA->DataSource = dt;
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
System::Void kurs::Admin::buttonSearchAdd6_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchAdd6->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT login.login, login.password FROM login WHERE login.rights = ? AND login.login = ?");
            pstmt->setString(1, "1");
            pstmt->setString(2, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginAddA");
            dt->Columns->Add("passwordAddA");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginAddA"] = gcnew System::String(res->getString("login").c_str());
                row["passwordAddA"] = gcnew System::String(res->getString("password").c_str());
                dt->Rows->Add(row);
            }
            dgvAddA->DataSource = dt;
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
System::Void kurs::Admin::buttonAddA_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ loginInput = textAddALog->Text;
    std::string loginInp = msclr::interop::marshal_as<std::string>(loginInput);
    String^ passwordInput = textAddAPass->Text;
    std::string passwordInp = msclr::interop::marshal_as<std::string>(passwordInput);
    if (loginInp.empty() || passwordInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("INSERT INTO login(login, password, rights) VALUES(?,?,?)");
        pstmt->setString(1, loginInp);
        pstmt->setString(2, passwordInp);
        pstmt->setInt(3, 1);
        pstmt->execute();
        buttonLogin2_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Admin::buttonVisit2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxAddBuy->Visible = true;
        this->groupBoxAddBuy->Enabled = true;
        this->groupBoxAddPur->Visible = true;
        this->groupBoxAddPur->Enabled = true;
        this->groupBoxAddEmp->Visible = true;
        this->groupBoxAddEmp->Enabled = true;
        this->groupBoxAddBS->Visible = true;
        this->groupBoxAddBS->Enabled = true;
        this->groupBoxAddB->Visible = true;
        this->groupBoxAddB->Enabled = true;
        this->groupBoxAddA->Visible = true;
        this->groupBoxAddA->Enabled = true;
        this->groupBoxAddV->Visible = true;
        this->groupBoxAddV->Enabled = true;
        comboAddVLog->Items->Clear();
        comboAddVName->Items->Clear();
        try
        {
            pstmt = con->prepareStatement("SELECT visit.login, bookstore.name, visit.date_visit, visit.time_visit, visit.note FROM visit INNER JOIN bookstore ON visit.contact_number = bookstore.contact_number");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginAddV");
            dt->Columns->Add("nameAddV");
            dt->Columns->Add("date_visitAddV");
            dt->Columns->Add("time_visitAddV");
            dt->Columns->Add("noteAddV");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginAddV"] = gcnew System::String(res->getString("login").c_str());
                row["nameAddV"] = gcnew System::String(res->getString("name").c_str());
                row["date_visitAddV"] = gcnew System::String(res->getString("date_visit").c_str());
                row["time_visitAddV"] = gcnew System::String(res->getString("time_visit").c_str());
                row["noteAddV"] = gcnew System::String(res->getString("note").c_str());
                dt->Rows->Add(row);
            }
            dgvAddV->DataSource = dt;
            pstmt = con->prepareStatement("SELECT buyer.login FROM buyer");
            res = pstmt->executeQuery();
            while (res->next())
            {
                comboAddVLog->Items->Add(gcnew System::String(res->getString("login").c_str()));
            }
            pstmt = con->prepareStatement("SELECT bookstore.name FROM bookstore");
            res = pstmt->executeQuery();
            while (res->next())
            {
                comboAddVName->Items->Add(gcnew System::String(res->getString("name").c_str()));
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
System::Void kurs::Admin::buttonSearchAdd7_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchAdd7->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT visit.login, bookstore.name, visit.date_visit, visit.time_visit, visit.note FROM visit INNER JOIN bookstore ON visit.contact_number = bookstore.contact_number WHERE visit.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginAddV");
            dt->Columns->Add("nameAddV");
            dt->Columns->Add("date_visitAddV");
            dt->Columns->Add("time_visitAddV");
            dt->Columns->Add("noteAddV");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginAddV"] = gcnew System::String(res->getString("login").c_str());
                row["nameAddV"] = gcnew System::String(res->getString("name").c_str());
                row["date_visitAddV"] = gcnew System::String(res->getString("date_visit").c_str());
                row["time_visitAddV"] = gcnew System::String(res->getString("time_visit").c_str());
                row["noteAddV"] = gcnew System::String(res->getString("note").c_str());
                dt->Rows->Add(row);
            }
            dgvAddV->DataSource = dt;
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
System::Void kurs::Admin::buttonAddV_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ loginInput = comboAddVLog->Text;
    std::string logInp = msclr::interop::marshal_as<std::string>(loginInput);
    String^ nameInput = comboAddVName->Text;
    std::string nameInp = msclr::interop::marshal_as<std::string>(nameInput);
    String^ noteInput = textAddANote->Text;
    std::string noteInp = msclr::interop::marshal_as<std::string>(noteInput);
    System::DateTime selectedDateTime1 = dateAddVDate->Value;
    System::String^ selectedDateStr = selectedDateTime1.ToString("yyyy-MM-dd");
    std::string selectedDateSstr = msclr::interop::marshal_as<std::string>(selectedDateStr);
    System::DateTime selectedDateTime = timeAddVTime->Value;
    System::String^ selectedTimeStr = selectedDateTime.ToString("HH:mm");
    std::string selectedTimeStdStr = msclr::interop::marshal_as<std::string>(selectedTimeStr);
    if (logInp.empty() || nameInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("SELECT bookstore.contact_number FROM bookstore WHERE bookstore.name = ?");
        pstmt->setString(1, nameInp);
        res = pstmt->executeQuery();
        std::string numberInp;
        while (res->next())
        {
            String^ numberInput = gcnew System::String(res->getString("contact_number").c_str());
            numberInp = msclr::interop::marshal_as<std::string>(numberInput);
        }
        pstmt = con->prepareStatement("INSERT INTO visit(date_visit, time_visit, login, contact_number, note) VALUES(?,?,?,?,?)");
        pstmt->setString(1, selectedDateSstr);
        pstmt->setString(2, selectedTimeStdStr);
        pstmt->setString(3, logInp);
        pstmt->setString(4, numberInp);
        pstmt->setString(5, noteInp);
        pstmt->execute();
        buttonVisit2_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Admin::buttonBuyer3_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->groupBoxEdBuy->Visible = true;
    this->groupBoxEdBuy->Enabled = true;
    this->groupBoxEdPur->Visible = false;
    this->groupBoxEdPur->Enabled = false;
    this->groupBoxEdEmp->Visible = false;
    this->groupBoxEdEmp->Enabled = false;
    this->groupBoxEdBS->Visible = false;
    this->groupBoxEdBS->Enabled = false;
    this->groupBoxEdB->Visible = false;
    this->groupBoxEdB->Enabled = false;
    this->groupBoxEdA->Visible = false;
    this->groupBoxEdA->Enabled = false;
    this->groupBoxEdV->Visible = false;
    this->groupBoxEdV->Enabled = false;
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
System::Void kurs::Admin::buttonSearchEd_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::dgvEdBuy_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
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
System::Void kurs::Admin::buttonEdBuy_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonPurchase3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxEdBuy->Visible = true;
        this->groupBoxEdBuy->Enabled = true;
        this->groupBoxEdPur->Visible = true;
        this->groupBoxEdPur->Enabled = true;
        this->groupBoxEdEmp->Visible = false;
        this->groupBoxEdEmp->Enabled = false;
        this->groupBoxEdBS->Visible = false;
        this->groupBoxEdBS->Enabled = false;
        this->groupBoxEdB->Visible = false;
        this->groupBoxEdB->Enabled = false;
        this->groupBoxEdA->Visible = false;
        this->groupBoxEdA->Enabled = false;
        this->groupBoxEdV->Visible = false;
        this->groupBoxEdV->Enabled = false;
        comboEdPurLogBuy->Items->Clear();
        comboEdPurLogEmp->Items->Clear();
        comboEdPurB->Items->Clear();
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn");
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
            pstmt = con->prepareStatement("SELECT employee.login FROM employee");
            res = pstmt->executeQuery();
            while (res->next())
            {
                comboEdPurLogEmp->Items->Add(gcnew System::String(res->getString("login").c_str()));
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
System::Void kurs::Admin::buttonSearchEd2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchEd2->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT purchase.purchase_id, purchase.login, purchase.login_employee, book.name, purchase_book.cost, purchase_book.quantity, purchase_book.date, purchase_book.time FROM purchase INNER JOIN purchase_book ON purchase.purchase_id = purchase_book.purchase_id INNER JOIN book ON purchase_book.isbn = book.isbn WHERE purchase.login = ?");
            pstmt->setString(1, search);
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
System::Void kurs::Admin::dgvEdPur_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0)
    {
        DataGridViewRow^ selectedRow = dgvEdPur->Rows[e->RowIndex];
        textEdPurId->Text = selectedRow->Cells["idEdPur"]->Value->ToString();
        comboEdPurLogBuy->Text = selectedRow->Cells["loginEdPur"]->Value->ToString();
        comboEdPurLogEmp->Text = selectedRow->Cells["loginEmpEdPur"]->Value->ToString();
        comboEdPurB->Text = selectedRow->Cells["bookEdPur"]->Value->ToString();
        textEdPurCost->Text = selectedRow->Cells["costEdPur"]->Value->ToString();
        numericEdPurQua->Text = selectedRow->Cells["quantityEdPur"]->Value->ToString();
        dateEdPurDate->Text = selectedRow->Cells["dateEdPur"]->Value->ToString();
        timeEdPurTime->Text = selectedRow->Cells["timeEdPur"]->Value->ToString();
    }
}
System::Void kurs::Admin::buttonEdPur_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonEmployee3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxEdBuy->Visible = true;
        this->groupBoxEdBuy->Enabled = true;
        this->groupBoxEdPur->Visible = true;
        this->groupBoxEdPur->Enabled = true;
        this->groupBoxEdEmp->Visible = true;
        this->groupBoxEdEmp->Enabled = true;
        this->groupBoxEdBS->Visible = false;
        this->groupBoxEdBS->Enabled = false;
        this->groupBoxEdB->Visible = false;
        this->groupBoxEdB->Enabled = false;
        this->groupBoxEdA->Visible = false;
        this->groupBoxEdA->Enabled = false;
        this->groupBoxEdV->Visible = false;
        this->groupBoxEdV->Enabled = false;
        comboEdEmpBSName->Items->Clear();
        try
        {
            pstmt = con->prepareStatement("SELECT employee.login, login.password, employee.nameE, bookstore.name, employee.track_number, schedule.working_days_of_the_week, schedule.additional_days_off FROM employee INNER JOIN schedule ON employee.login = schedule.login INNER JOIN bookstore ON employee.contact_number = bookstore.contact_number INNER JOIN login ON employee.login = login.login");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginEdEmp");
            dt->Columns->Add("passwordEdEmp");
            dt->Columns->Add("nameEdEmp");
            dt->Columns->Add("nameBSEdEmp");
            dt->Columns->Add("track_numberEdEmp");
            dt->Columns->Add("working_days_of_the_weekEdEmp");
            dt->Columns->Add("additional_days_offEdEmp");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginEdEmp"] = gcnew System::String(res->getString("login").c_str());
                row["passwordEdEmp"] = gcnew System::String(res->getString("password").c_str());
                row["nameEdEmp"] = gcnew System::String(res->getString("nameE").c_str());
                row["nameBSEdEmp"] = gcnew System::String(res->getString("name").c_str());
                row["track_numberEdEmp"] = gcnew System::String(res->getString("track_number").c_str());
                row["working_days_of_the_weekEdEmp"] = gcnew System::String(res->getString("working_days_of_the_week").c_str());
                row["additional_days_offEdEmp"] = gcnew System::String(res->getString("additional_days_off").c_str());
                dt->Rows->Add(row);
            }
            dgvEdEmp->DataSource = dt;
            pstmt = con->prepareStatement("SELECT bookstore.name FROM bookstore");
            res = pstmt->executeQuery();
            while (res->next())
            {
                comboEdEmpBSName->Items->Add(gcnew System::String(res->getString("name").c_str()));
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
System::Void kurs::Admin::buttonSearchEd3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchEd3->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT employee.login, login.password, employee.nameE, bookstore.name, employee.track_number, schedule.working_days_of_the_week, schedule.additional_days_off FROM employee INNER JOIN schedule ON employee.login = schedule.login INNER JOIN bookstore ON employee.contact_number = bookstore.contact_number INNER JOIN login ON employee.login = login.login WHERE employee.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginEdEmp");
            dt->Columns->Add("passwordEdEmp");
            dt->Columns->Add("nameEdEmp");
            dt->Columns->Add("nameBSEdEmp");
            dt->Columns->Add("track_numberEdEmp");
            dt->Columns->Add("working_days_of_the_weekEdEmp");
            dt->Columns->Add("additional_days_offEdEmp");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginEdEmp"] = gcnew System::String(res->getString("login").c_str());
                row["passwordEdEmp"] = gcnew System::String(res->getString("password").c_str());
                row["nameEdEmp"] = gcnew System::String(res->getString("nameE").c_str());
                row["nameBSEdEmp"] = gcnew System::String(res->getString("name").c_str());
                row["track_numberEdEmp"] = gcnew System::String(res->getString("track_number").c_str());
                row["working_days_of_the_weekEdEmp"] = gcnew System::String(res->getString("working_days_of_the_week").c_str());
                row["additional_days_offEdEmp"] = gcnew System::String(res->getString("additional_days_off").c_str());
                dt->Rows->Add(row);
            }
            dgvEdEmp->DataSource = dt;
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
System::Void kurs::Admin::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0)
    {
        DataGridViewRow^ selectedRow = dgvEdEmp->Rows[e->RowIndex];
        textEdEmpLogin->Text = selectedRow->Cells["loginEdEmp"]->Value->ToString();
        textEdEmpPass->Text = selectedRow->Cells["passwordEdEmp"]->Value->ToString();
        textEdEmpName->Text = selectedRow->Cells["nameEdEmp"]->Value->ToString();
        comboEdEmpBSName->Text = selectedRow->Cells["nameBSEdEmp"]->Value->ToString();
        textEdEmpTrack_number->Text = selectedRow->Cells["track_numberEdEmp"]->Value->ToString();
        textEdEmpWorking_days_of_the_week->Text = selectedRow->Cells["working_days_of_the_weekEdEmp"]->Value->ToString();
        numericEdEmpAdditional_days_off->Text = selectedRow->Cells["additional_days_offEdEmp"]->Value->ToString();
    } 
}
System::Void kurs::Admin::buttonEdEmp_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ loginEmpInput = textEdEmpLogin->Text;
    std::string logEmpInp = msclr::interop::marshal_as<std::string>(loginEmpInput);
    String^ nameInput = textEdEmpName->Text;
    std::string nameInp = msclr::interop::marshal_as<std::string>(nameInput);
    String^ bsInput = comboEdEmpBSName->Text;
    std::string bsInp = msclr::interop::marshal_as<std::string>(bsInput);
    String^ tnInput = textEdEmpTrack_number->Text;
    std::string tnInp = msclr::interop::marshal_as<std::string>(tnInput);
    String^ wdInput = textEdEmpWorking_days_of_the_week->Text;
    std::string wdInp = msclr::interop::marshal_as<std::string>(wdInput);
    String^ adInput = numericEdEmpAdditional_days_off->Text;
    std::string adInp = msclr::interop::marshal_as<std::string>(adInput);
    String^ passInput = textEdEmpPass->Text;
    std::string passInp = msclr::interop::marshal_as<std::string>(passInput);
    if (logEmpInp.empty() || nameInp.empty() || bsInp.empty() || passInp.empty() || wdInp.empty() || adInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("UPDATE bookstore.login SET password = ? WHERE login = ?");
        pstmt->setString(1, passInp);
        pstmt->setString(2, logEmpInp);
        pstmt->execute();
        pstmt = con->prepareStatement("SELECT bookstore.contact_number FROM bookstore WHERE bookstore.name = ?");
        pstmt->setString(1, bsInp);
        res = pstmt->executeQuery();
        std::string cnInp;
        while (res->next())
        {
            String^ cnInput = gcnew System::String(res->getString("contact_number").c_str());
            cnInp = msclr::interop::marshal_as<std::string>(cnInput);
        }
        pstmt = con->prepareStatement("UPDATE bookstore.employee SET contact_number = ?, nameE = ?, track_number = ? WHERE login = ?");
        pstmt->setString(1, cnInp);
        pstmt->setString(2, nameInp);
        pstmt->setString(3, tnInp);
        pstmt->setString(4, logEmpInp);
        pstmt->execute();
        pstmt = con->prepareStatement("UPDATE bookstore.schedule SET working_days_of_the_week = ?, additional_days_off = ? WHERE login = ?");
        pstmt->setString(1, wdInp);
        pstmt->setString(2, adInp);
        pstmt->setString(3, logEmpInp);
        pstmt->execute();
        buttonEmployee3_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Admin::buttonBookstore3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxEdBuy->Visible = true;
        this->groupBoxEdBuy->Enabled = true;
        this->groupBoxEdPur->Visible = true;
        this->groupBoxEdPur->Enabled = true;
        this->groupBoxEdEmp->Visible = true;
        this->groupBoxEdEmp->Enabled = true;
        this->groupBoxEdBS->Visible = true;
        this->groupBoxEdBS->Enabled = true;
        this->groupBoxEdB->Visible = false;
        this->groupBoxEdB->Enabled = false;
        this->groupBoxEdA->Visible = false;
        this->groupBoxEdA->Enabled = false;
        this->groupBoxEdV->Visible = false;
        this->groupBoxEdV->Enabled = false;
        try
        {
            pstmt = con->prepareStatement("SELECT bookstore.name, bookstore.contact_number, bookstore.address, bookstore.work_schedule FROM bookstore");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("nameEdBS");
            dt->Columns->Add("contact_numberEdBS");
            dt->Columns->Add("addressEdBS");
            dt->Columns->Add("work_scheduleEdBS");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["nameEdBS"] = gcnew System::String(res->getString("name").c_str());
                row["contact_numberEdBS"] = gcnew System::String(res->getString("contact_number").c_str());
                row["addressEdBS"] = gcnew System::String(res->getString("address").c_str());
                row["work_scheduleEdBS"] = gcnew System::String(res->getString("work_schedule").c_str());
                dt->Rows->Add(row);
            }
            dgvEdBS->DataSource = dt;
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
System::Void kurs::Admin::buttonSearchEd4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchEd4->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT bookstore.name, bookstore.contact_number, bookstore.address, bookstore.work_schedule FROM bookstore WHERE bookstore.name = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("nameEdBS");
            dt->Columns->Add("contact_numberEdBS");
            dt->Columns->Add("addressEdBS");
            dt->Columns->Add("work_scheduleEdBS");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["nameEdBS"] = gcnew System::String(res->getString("name").c_str());
                row["contact_numberEdBS"] = gcnew System::String(res->getString("contact_number").c_str());
                row["addressEdBS"] = gcnew System::String(res->getString("address").c_str());
                row["work_scheduleEdBS"] = gcnew System::String(res->getString("work_schedule").c_str());
                dt->Rows->Add(row);
            }
            dgvEdBS->DataSource = dt;
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
System::Void kurs::Admin::dataGridView1_CellClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0)
    {
        DataGridViewRow^ selectedRow = dgvEdBS->Rows[e->RowIndex];
        textEdBSName->Text = selectedRow->Cells["nameEdBS"]->Value->ToString();
        textEdBSNumber->Text = selectedRow->Cells["contact_numberEdBS"]->Value->ToString();
        textEdBSAddress->Text = selectedRow->Cells["addressEdBS"]->Value->ToString();
        textEdBSWS->Text = selectedRow->Cells["work_scheduleEdBS"]->Value->ToString();
    }
}
System::Void kurs::Admin::buttonEdBS_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ nameInput = textEdBSName->Text;
    std::string nameInp = msclr::interop::marshal_as<std::string>(nameInput);
    String^ numbInput = textEdBSNumber->Text;
    std::string numbInp = msclr::interop::marshal_as<std::string>(numbInput);
    String^ addressInput = textEdBSAddress->Text;
    std::string addressInp = msclr::interop::marshal_as<std::string>(addressInput);
    String^ WSInput = textEdBSWS->Text;
    std::string WSInp = msclr::interop::marshal_as<std::string>(WSInput);
    if (numbInp.length() != 12 || numbInp.substr(0, 3) != "380") {
        MessageBox::Show("Not valid!", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    if (nameInp.empty() || numbInp.empty() || addressInp.empty() || WSInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("UPDATE bookstore.bookstore SET name = ?, address = ?, work_schedule = ? WHERE contact_number = ?");
        pstmt->setString(1, nameInp);
        pstmt->setString(2, addressInp);
        pstmt->setString(3, WSInp);
        pstmt->setString(4, numbInp);
        pstmt->execute();
        buttonBookstore3_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Admin::buttonBook3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxEdBuy->Visible = true;
        this->groupBoxEdBuy->Enabled = true;
        this->groupBoxEdPur->Visible = true;
        this->groupBoxEdPur->Enabled = true;
        this->groupBoxEdEmp->Visible = true;
        this->groupBoxEdEmp->Enabled = true;
        this->groupBoxEdBS->Visible = true;
        this->groupBoxEdBS->Enabled = true;
        this->groupBoxEdB->Visible = true;
        this->groupBoxEdB->Enabled = true;
        this->groupBoxEdA->Visible = false;
        this->groupBoxEdA->Enabled = false;
        this->groupBoxEdV->Visible = false;
        this->groupBoxEdV->Enabled = false;
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
System::Void kurs::Admin::buttonSearchEd5_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::dgvEdB_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
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
System::Void kurs::Admin::buttonEdB_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonLogin3_Click(System::Object^ sender, System::EventArgs^ e)
{
   try
    {
        this->groupBoxEdBuy->Visible = true;
        this->groupBoxEdBuy->Enabled = true;
        this->groupBoxEdPur->Visible = true;
        this->groupBoxEdPur->Enabled = true;
        this->groupBoxEdEmp->Visible = true;
        this->groupBoxEdEmp->Enabled = true;
        this->groupBoxEdBS->Visible = true;
        this->groupBoxEdBS->Enabled = true;
        this->groupBoxEdB->Visible = true;
        this->groupBoxEdB->Enabled = true;
        this->groupBoxEdA->Visible = true;
        this->groupBoxEdA->Enabled = true;
        this->groupBoxEdV->Visible = false;
        this->groupBoxEdV->Enabled = false;
        try
        {
            pstmt = con->prepareStatement("SELECT login.login, login.password FROM login WHERE login.rights = ?");
            pstmt->setString(1, "1");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginEdA");
            dt->Columns->Add("passwordEdA");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginEdA"] = gcnew System::String(res->getString("login").c_str());
                row["passwordEdA"] = gcnew System::String(res->getString("password").c_str());
                dt->Rows->Add(row);
            }
            dgvEdA->DataSource = dt;
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
System::Void kurs::Admin::buttonSearchEd6_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchEd6->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT login.login, login.password FROM login WHERE login.rights = ? AND login.login = ?");
            pstmt->setString(1, "1");
            pstmt->setString(2, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginEdA");
            dt->Columns->Add("passwordEdA");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginEdA"] = gcnew System::String(res->getString("login").c_str());
                row["passwordEdA"] = gcnew System::String(res->getString("password").c_str());
                dt->Rows->Add(row);
            }
            dgvEdA->DataSource = dt;
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
System::Void kurs::Admin::dgvEdA_CellClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0)
    {
        DataGridViewRow^ selectedRow = dgvEdA->Rows[e->RowIndex];
        textEdALog->Text = selectedRow->Cells["loginEdA"]->Value->ToString();
        textEdAPass->Text = selectedRow->Cells["passwordEdA"]->Value->ToString();
    }
}
System::Void kurs::Admin::buttonEdA_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ loginInput = textEdALog->Text;
    std::string loginInp = msclr::interop::marshal_as<std::string>(loginInput);
    String^ passwordInput = textEdAPass->Text;
    std::string passwordInp = msclr::interop::marshal_as<std::string>(passwordInput);
    if (loginInp.empty() || passwordInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("UPDATE bookstore.login SET password = ? WHERE login = ? AND rights = ?");
        pstmt->setString(1, passwordInp);
        pstmt->setString(2, loginInp);
        pstmt->setInt(3, 1);
        pstmt->execute();
        buttonLogin3_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Admin::buttonVisit3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxEdBuy->Visible = true;
        this->groupBoxEdBuy->Enabled = true;
        this->groupBoxEdPur->Visible = true;
        this->groupBoxEdPur->Enabled = true;
        this->groupBoxEdEmp->Visible = true;
        this->groupBoxEdEmp->Enabled = true;
        this->groupBoxEdBS->Visible = true;
        this->groupBoxEdBS->Enabled = true;
        this->groupBoxEdB->Visible = true;
        this->groupBoxEdB->Enabled = true;
        this->groupBoxEdA->Visible = true;
        this->groupBoxEdA->Enabled = true;
        this->groupBoxEdV->Visible = true;
        this->groupBoxEdV->Enabled = true;
        comboEdVLog->Items->Clear();
        comboEdVName->Items->Clear();
        try
        {
            pstmt = con->prepareStatement("SELECT visit.login, bookstore.name, visit.date_visit, visit.time_visit, visit.note FROM visit INNER JOIN bookstore ON visit.contact_number = bookstore.contact_number");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginEdV");
            dt->Columns->Add("nameEdV");
            dt->Columns->Add("date_visitEdV");
            dt->Columns->Add("time_visitEdV");
            dt->Columns->Add("noteEdV");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginEdV"] = gcnew System::String(res->getString("login").c_str());
                row["nameEdV"] = gcnew System::String(res->getString("name").c_str());
                row["date_visitEdV"] = gcnew System::String(res->getString("date_visit").c_str());
                row["time_visitEdV"] = gcnew System::String(res->getString("time_visit").c_str());
                row["noteEdV"] = gcnew System::String(res->getString("note").c_str());
                dt->Rows->Add(row);
            }
            dgvEdV->DataSource = dt;
            pstmt = con->prepareStatement("SELECT buyer.login FROM buyer");
            res = pstmt->executeQuery();
            while (res->next())
            {
                comboEdVLog->Items->Add(gcnew System::String(res->getString("login").c_str()));
            }
            pstmt = con->prepareStatement("SELECT bookstore.name FROM bookstore");
            res = pstmt->executeQuery();
            while (res->next())
            {
                comboEdVName->Items->Add(gcnew System::String(res->getString("name").c_str()));
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
System::Void kurs::Admin::buttonSearchEd7_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchEd7->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT visit.login, bookstore.name, visit.date_visit, visit.time_visit, visit.note FROM visit INNER JOIN bookstore ON visit.contact_number = bookstore.contact_number WHERE visit.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginEdV");
            dt->Columns->Add("nameEdV");
            dt->Columns->Add("date_visitEdV");
            dt->Columns->Add("time_visitEdV");
            dt->Columns->Add("noteEdV");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginEdV"] = gcnew System::String(res->getString("login").c_str());
                row["nameEdV"] = gcnew System::String(res->getString("name").c_str());
                row["date_visitEdV"] = gcnew System::String(res->getString("date_visit").c_str());
                row["time_visitEdV"] = gcnew System::String(res->getString("time_visit").c_str());
                row["noteEdV"] = gcnew System::String(res->getString("note").c_str());
                dt->Rows->Add(row);
            }
            dgvEdV->DataSource = dt;
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
System::Void kurs::Admin::dataGridView1_CellClick_2(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0)
    {
        DataGridViewRow^ selectedRow = dgvEdV->Rows[e->RowIndex];
        comboEdVLog->Text = selectedRow->Cells["loginEdV"]->Value->ToString();
        comboEdVName->Text = selectedRow->Cells["nameEdV"]->Value->ToString();
        dateEdVDate->Text = selectedRow->Cells["date_visitEdV"]->Value->ToString();
        timeEdVTime->Text = selectedRow->Cells["time_visitEdV"]->Value->ToString();
        textEdVNote->Text = selectedRow->Cells["noteEdV"]->Value->ToString();
        textBox1->Text = selectedRow->Cells["loginEdV"]->Value->ToString();
        textBox2->Text = selectedRow->Cells["nameEdV"]->Value->ToString();
        textBox3->Text = selectedRow->Cells["date_visitEdV"]->Value->ToString();
        textBox4->Text = selectedRow->Cells["time_visitEdV"]->Value->ToString();
    }
}
System::Void kurs::Admin::buttonEdV_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ loginInput = comboEdVLog->Text;
    std::string logInp = msclr::interop::marshal_as<std::string>(loginInput);
    String^ nameInput = comboEdVName->Text;
    std::string nameInp = msclr::interop::marshal_as<std::string>(nameInput);
    String^ noteInput = textEdVNote->Text;
    std::string noteInp = msclr::interop::marshal_as<std::string>(noteInput);
    System::DateTime selectedDateTime1 = dateEdVDate->Value;
    System::String^ selectedDateStr = selectedDateTime1.ToString("yyyy-MM-dd");
    std::string selectedDateSstr = msclr::interop::marshal_as<std::string>(selectedDateStr);
    System::DateTime selectedDateTime = timeEdVTime->Value;
    System::String^ selectedTimeStr = selectedDateTime.ToString("HH:mm");
    std::string selectedTimeStdStr = msclr::interop::marshal_as<std::string>(selectedTimeStr);
    String^ tb1Input = textBox1->Text;
    std::string tb1Inp = msclr::interop::marshal_as<std::string>(tb1Input);
    String^ tb2Input = textBox2->Text;
    std::string tb2Inp = msclr::interop::marshal_as<std::string>(tb2Input);
    String^ tb3Input = textBox3->Text;
    std::string tb3Inp = msclr::interop::marshal_as<std::string>(tb3Input);
    String^ tb4Input = textBox4->Text;
    std::string tb4Inp = msclr::interop::marshal_as<std::string>(tb4Input);
    if (logInp.empty() || nameInp.empty()) {
        MessageBox::Show("You did not keep all the data", "Repeat the request", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }
    sql::Statement* stmt;
    try
    {
        pstmt = con->prepareStatement("SELECT bookstore.contact_number FROM bookstore WHERE bookstore.name = ?");
        pstmt->setString(1, nameInp);
        res = pstmt->executeQuery();
        std::string numberInp;
        while (res->next())
        {
            String^ numberInput = gcnew System::String(res->getString("contact_number").c_str());
            numberInp = msclr::interop::marshal_as<std::string>(numberInput);
        }
        pstmt = con->prepareStatement("SELECT bookstore.contact_number FROM bookstore WHERE bookstore.name = ?");
        pstmt->setString(1, tb2Inp);
        res = pstmt->executeQuery();
        std::string number2Inp;
        while (res->next())
        {
            String^ number2Input = gcnew System::String(res->getString("contact_number").c_str());
            number2Inp = msclr::interop::marshal_as<std::string>(number2Input);
        }
        pstmt = con->prepareStatement("UPDATE bookstore.visit SET date_visit = ?, time_visit = ?, login = ?, contact_number = ?, note = ? WHERE date_visit = ? AND time_visit = ? AND login = ? AND contact_number = ?");
        pstmt->setString(1, selectedDateSstr);
        pstmt->setString(2, selectedTimeStdStr);
        pstmt->setString(3, logInp);
        pstmt->setString(4, numberInp);
        pstmt->setString(5, noteInp);
        pstmt->setString(6, tb3Inp);
        pstmt->setString(7, tb4Inp);
        pstmt->setString(8, tb1Inp);
        pstmt->setString(9, number2Inp);
        pstmt->execute();
        buttonVisit3_Click(sender, e);
    }
    catch (sql::SQLException& ex)
    {
        System::String^ error = gcnew System::String(ex.what());
        MessageBox::Show(error, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
System::Void kurs::Admin::buttonBuyer4_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->groupBoxDelBuy->Visible = true;
    this->groupBoxDelBuy->Enabled = true;
    this->groupBoxDelPur->Visible = false;
    this->groupBoxDelPur->Enabled = false;
    this->groupBoxDelEmp->Visible = false;
    this->groupBoxDelEmp->Enabled = false;
    this->groupBoxDelBS->Visible = false;
    this->groupBoxDelBS->Enabled = false;
    this->groupBoxDelB->Visible = false;
    this->groupBoxDelB->Enabled = false;
    this->groupBoxDelA->Visible = false;
    this->groupBoxDelA->Enabled = false;
    this->groupBoxDelV->Visible = false;
    this->groupBoxDelV->Enabled = false;
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
System::Void kurs::Admin::buttonSearchDel_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonDelBuy_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonPurchase4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxDelBuy->Visible = true;
        this->groupBoxDelBuy->Enabled = true;
        this->groupBoxDelPur->Visible = true;
        this->groupBoxDelPur->Enabled = true;
        this->groupBoxDelEmp->Visible = false;
        this->groupBoxDelEmp->Enabled = false;
        this->groupBoxDelBS->Visible = false;
        this->groupBoxDelBS->Enabled = false;
        this->groupBoxDelB->Visible = false;
        this->groupBoxDelB->Enabled = false;
        this->groupBoxDelA->Visible = false;
        this->groupBoxDelA->Enabled = false;
        this->groupBoxDelV->Visible = false;
        this->groupBoxDelV->Enabled = false;
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
System::Void kurs::Admin::buttonSearchDel2_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonDelPur_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonEmployee4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxDelBuy->Visible = true;
        this->groupBoxDelBuy->Enabled = true;
        this->groupBoxDelPur->Visible = true;
        this->groupBoxDelPur->Enabled = true;
        this->groupBoxDelEmp->Visible = true;
        this->groupBoxDelEmp->Enabled = true;
        this->groupBoxDelBS->Visible = false;
        this->groupBoxDelBS->Enabled = false;
        this->groupBoxDelB->Visible = false;
        this->groupBoxDelB->Enabled = false;
        this->groupBoxDelA->Visible = false;
        this->groupBoxDelA->Enabled = false;
        this->groupBoxDelV->Visible = false;
        this->groupBoxDelV->Enabled = false;
        comboEdEmpBSName->Items->Clear();
        try
        {
            pstmt = con->prepareStatement("SELECT employee.login, login.password, employee.nameE, bookstore.name, employee.track_number, schedule.working_days_of_the_week, schedule.additional_days_off FROM employee INNER JOIN schedule ON employee.login = schedule.login INNER JOIN bookstore ON employee.contact_number = bookstore.contact_number INNER JOIN login ON employee.login = login.login");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginDelEmp");
            dt->Columns->Add("passwordDelEmp");
            dt->Columns->Add("nameDelEmp");
            dt->Columns->Add("nameBSDelEmp");
            dt->Columns->Add("track_numberDelEmp");
            dt->Columns->Add("working_days_of_the_weekDelEmp");
            dt->Columns->Add("additional_days_offDelEmp");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginDelEmp"] = gcnew System::String(res->getString("login").c_str());
                row["passwordDelEmp"] = gcnew System::String(res->getString("password").c_str());
                row["nameDelEmp"] = gcnew System::String(res->getString("nameE").c_str());
                row["nameBSDelEmp"] = gcnew System::String(res->getString("name").c_str());
                row["track_numberDelEmp"] = gcnew System::String(res->getString("track_number").c_str());
                row["working_days_of_the_weekDelEmp"] = gcnew System::String(res->getString("working_days_of_the_week").c_str());
                row["additional_days_offDelEmp"] = gcnew System::String(res->getString("additional_days_off").c_str());
                dt->Rows->Add(row);
            }
            dgvDelEmp->DataSource = dt;
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
System::Void kurs::Admin::buttonSearchDel3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchDel3->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT employee.login, login.password, employee.nameE, bookstore.name, employee.track_number, schedule.working_days_of_the_week, schedule.additional_days_off FROM employee INNER JOIN schedule ON employee.login = schedule.login INNER JOIN bookstore ON employee.contact_number = bookstore.contact_number INNER JOIN login ON employee.login = login.login WHERE employee.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginDelEmp");
            dt->Columns->Add("passwordDelEmp");
            dt->Columns->Add("nameDelEmp");
            dt->Columns->Add("nameBSDelEmp");
            dt->Columns->Add("track_numberDelEmp");
            dt->Columns->Add("working_days_of_the_weekDelEmp");
            dt->Columns->Add("additional_days_offDelEmp");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginDelEmp"] = gcnew System::String(res->getString("login").c_str());
                row["passwordDelEmp"] = gcnew System::String(res->getString("password").c_str());
                row["nameDelEmp"] = gcnew System::String(res->getString("nameE").c_str());
                row["nameBSDelEmp"] = gcnew System::String(res->getString("name").c_str());
                row["track_numberDelEmp"] = gcnew System::String(res->getString("track_number").c_str());
                row["working_days_of_the_weekDelEmp"] = gcnew System::String(res->getString("working_days_of_the_week").c_str());
                row["additional_days_offDelEmp"] = gcnew System::String(res->getString("additional_days_off").c_str());
                dt->Rows->Add(row);
            }
            dgvDelEmp->DataSource = dt;
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
System::Void kurs::Admin::buttonDelEmp_Click(System::Object^ sender, System::EventArgs^ e)
{
    bool checkPurchase = true;
    String^ Input = dgvDelEmp->CurrentRow->Cells["loginDelEmp"]->Value->ToString();
    std::string Inp = msclr::interop::marshal_as<std::string>(Input);
    try
    {
        pstmt = con->prepareStatement("SELECT purchase.login_employee FROM purchase WHERE purchase.login_employee = ?");
        pstmt->setString(1, Inp);
        res = pstmt->executeQuery();
        if (!res->next()) {
            checkPurchase = false;
        }
        if (checkPurchase) {
            MessageBox::Show("The seller has sales. They must be removed first.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
            buttonPurchase4_Click(sender, e);
        }
        if (!checkPurchase) {
            pstmt = con->prepareStatement("DELETE FROM schedule WHERE login = ?");
            pstmt->setString(1, Inp);
            pstmt->execute();
            pstmt = con->prepareStatement("DELETE FROM employee WHERE login = ?");
            pstmt->setString(1, Inp);
            pstmt->execute();
            pstmt = con->prepareStatement("DELETE FROM login WHERE login = ?");
            pstmt->setString(1, Inp);
            pstmt->execute();
            buttonEmployee4_Click(sender, e);
        }
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Admin::buttonBookstore4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxDelBuy->Visible = true;
        this->groupBoxDelBuy->Enabled = true;
        this->groupBoxDelPur->Visible = true;
        this->groupBoxDelPur->Enabled = true;
        this->groupBoxDelEmp->Visible = true;
        this->groupBoxDelEmp->Enabled = true;
        this->groupBoxDelBS->Visible = true;
        this->groupBoxDelBS->Enabled = true;
        this->groupBoxDelB->Visible = false;
        this->groupBoxDelB->Enabled = false;
        this->groupBoxDelA->Visible = false;
        this->groupBoxDelA->Enabled = false;
        this->groupBoxDelV->Visible = false;
        this->groupBoxDelV->Enabled = false;
        try
        {
            pstmt = con->prepareStatement("SELECT bookstore.name, bookstore.contact_number, bookstore.address, bookstore.work_schedule FROM bookstore");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("nameDelBS");
            dt->Columns->Add("contact_numberDelBS");
            dt->Columns->Add("addressDelBS");
            dt->Columns->Add("work_scheduleDelBS");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["nameDelBS"] = gcnew System::String(res->getString("name").c_str());
                row["contact_numberDelBS"] = gcnew System::String(res->getString("contact_number").c_str());
                row["addressDelBS"] = gcnew System::String(res->getString("address").c_str());
                row["work_scheduleDelBS"] = gcnew System::String(res->getString("work_schedule").c_str());
                dt->Rows->Add(row);
            }
            dgvDelBS->DataSource = dt;
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
System::Void kurs::Admin::buttonSearchDel4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchDel4->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT bookstore.name, bookstore.contact_number, bookstore.address, bookstore.work_schedule FROM bookstore WHERE bookstore.name = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("nameDelBS");
            dt->Columns->Add("contact_numberDelBS");
            dt->Columns->Add("addressDelBS");
            dt->Columns->Add("work_scheduleDelBS");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["nameDelBS"] = gcnew System::String(res->getString("name").c_str());
                row["contact_numberDelBS"] = gcnew System::String(res->getString("contact_number").c_str());
                row["addressDelBS"] = gcnew System::String(res->getString("address").c_str());
                row["work_scheduleDelBS"] = gcnew System::String(res->getString("work_schedule").c_str());
                dt->Rows->Add(row);
            }
            dgvDelBS->DataSource = dt;
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
System::Void kurs::Admin::buttonDelBS_Click(System::Object^ sender, System::EventArgs^ e)
{
    bool checkVisit = true, checkEmployee = true;
    String^ Input = dgvDelBS->CurrentRow->Cells["contact_numberDelBS"]->Value->ToString();
    std::string Inp = msclr::interop::marshal_as<std::string>(Input);
    try
    {
        pstmt = con->prepareStatement("SELECT employee.contact_number FROM employee WHERE employee.contact_number = ?");
        pstmt->setString(1, Inp);
        res = pstmt->executeQuery();
        if (!res->next()) {
            checkEmployee = false;
        }
        pstmt = con->prepareStatement("SELECT visit.contact_number FROM visit WHERE visit.contact_number = ?");
        pstmt->setString(1, Inp);
        res = pstmt->executeQuery();
        if (!res->next()) {
            checkVisit = false;
        }
        if (checkVisit) {
            MessageBox::Show("The bookstore has a visit. They must be removed first.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
            //buttonVisit4_Click(sender, e);
        }
        if (checkEmployee) {
            MessageBox::Show("This bookstore has employee. They must be removed first.", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
            buttonEmployee4_Click(sender, e);
        }
        if (!checkVisit && !checkEmployee) {
            pstmt = con->prepareStatement("DELETE FROM bookstore WHERE contact_number = ?");
            pstmt->setString(1, Inp);
            pstmt->execute();
            buttonBookstore4_Click(sender, e);
        }
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Admin::buttonBook4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxDelBuy->Visible = true;
        this->groupBoxDelBuy->Enabled = true;
        this->groupBoxDelPur->Visible = true;
        this->groupBoxDelPur->Enabled = true;
        this->groupBoxDelEmp->Visible = true;
        this->groupBoxDelEmp->Enabled = true;
        this->groupBoxDelBS->Visible = true;
        this->groupBoxDelBS->Enabled = true;
        this->groupBoxDelB->Visible = true;
        this->groupBoxDelB->Enabled = true;
        this->groupBoxDelA->Visible = false;
        this->groupBoxDelA->Enabled = false;
        this->groupBoxDelV->Visible = false;
        this->groupBoxDelV->Enabled = false;
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
System::Void kurs::Admin::buttonSearchDel5_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonDelB_Click(System::Object^ sender, System::EventArgs^ e)
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
System::Void kurs::Admin::buttonLogin4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxDelBuy->Visible = true;
        this->groupBoxDelBuy->Enabled = true;
        this->groupBoxDelPur->Visible = true;
        this->groupBoxDelPur->Enabled = true;
        this->groupBoxDelEmp->Visible = true;
        this->groupBoxDelEmp->Enabled = true;
        this->groupBoxDelBS->Visible = true;
        this->groupBoxDelBS->Enabled = true;
        this->groupBoxDelB->Visible = true;
        this->groupBoxDelB->Enabled = true;
        this->groupBoxDelA->Visible = true;
        this->groupBoxDelA->Enabled = true;
        this->groupBoxDelV->Visible = false;
        this->groupBoxDelV->Enabled = false;
        try
        {
            pstmt = con->prepareStatement("SELECT login.login, login.password FROM login WHERE login.rights = ?");
            pstmt->setString(1, "1");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginDelA");
            dt->Columns->Add("passwordDelA");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginDelA"] = gcnew System::String(res->getString("login").c_str());
                row["passwordDelA"] = gcnew System::String(res->getString("password").c_str());
                dt->Rows->Add(row);
            }
            dgvDelA->DataSource = dt;
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
System::Void kurs::Admin::buttonSearchDel6_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchDel6->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT login.login, login.password FROM login WHERE login.rights = ? AND login.login = ?");
            pstmt->setString(1, "1");
            pstmt->setString(2, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginDelA");
            dt->Columns->Add("passwordDelA");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginDelA"] = gcnew System::String(res->getString("login").c_str());
                row["passwordDelA"] = gcnew System::String(res->getString("password").c_str());
                dt->Rows->Add(row);
            }
            dgvDelA->DataSource = dt;
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
System::Void kurs::Admin::buttonDelA_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ Input = dgvDelA->CurrentRow->Cells["loginDelA"]->Value->ToString();
    std::string Inp = msclr::interop::marshal_as<std::string>(Input);
    try
    {
            pstmt = con->prepareStatement("DELETE FROM login WHERE login = ?");
            pstmt->setString(1, Inp);
            pstmt->execute();
            buttonLogin4_Click(sender, e);
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Admin::buttonVisit4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        this->groupBoxDelBuy->Visible = true;
        this->groupBoxDelBuy->Enabled = true;
        this->groupBoxDelPur->Visible = true;
        this->groupBoxDelPur->Enabled = true;
        this->groupBoxDelEmp->Visible = true;
        this->groupBoxDelEmp->Enabled = true;
        this->groupBoxDelBS->Visible = true;
        this->groupBoxDelBS->Enabled = true;
        this->groupBoxDelB->Visible = true;
        this->groupBoxDelB->Enabled = true;
        this->groupBoxDelA->Visible = true;
        this->groupBoxDelA->Enabled = true;
        this->groupBoxDelV->Visible = true;
        this->groupBoxDelV->Enabled = true;
        try
        {
            pstmt = con->prepareStatement("SELECT visit.login, bookstore.name, visit.date_visit, visit.time_visit, visit.note FROM visit INNER JOIN bookstore ON visit.contact_number = bookstore.contact_number");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginDelV");
            dt->Columns->Add("nameDelV");
            dt->Columns->Add("date_visitDelV");
            dt->Columns->Add("time_visitDelV");
            dt->Columns->Add("noteDelV");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginDelV"] = gcnew System::String(res->getString("login").c_str());
                row["nameDelV"] = gcnew System::String(res->getString("name").c_str());
                row["date_visitDelV"] = gcnew System::String(res->getString("date_visit").c_str());
                row["time_visitDelV"] = gcnew System::String(res->getString("time_visit").c_str());
                row["noteDelV"] = gcnew System::String(res->getString("note").c_str());
                dt->Rows->Add(row);
            }
            dgvDelV->DataSource = dt;
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
System::Void kurs::Admin::buttonSearchDel7_Click(System::Object^ sender, System::EventArgs^ e)
{
    try
    {
        String^ SearchInput = textSearchDel7->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT visit.login, bookstore.name, visit.date_visit, visit.time_visit, visit.note FROM visit INNER JOIN bookstore ON visit.contact_number = bookstore.contact_number WHERE visit.login = ?");
            pstmt->setString(1, search);
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginDelV");
            dt->Columns->Add("nameDelV");
            dt->Columns->Add("date_visitDelV");
            dt->Columns->Add("time_visitDelV");
            dt->Columns->Add("noteDelV");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginDelV"] = gcnew System::String(res->getString("login").c_str());
                row["nameDelV"] = gcnew System::String(res->getString("name").c_str());
                row["date_visitDelV"] = gcnew System::String(res->getString("date_visit").c_str());
                row["time_visitDelV"] = gcnew System::String(res->getString("time_visit").c_str());
                row["noteDelV"] = gcnew System::String(res->getString("note").c_str());
                dt->Rows->Add(row);
            }
            dgvDelV->DataSource = dt;
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
System::Void kurs::Admin::buttonDelV_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ Input1 = dgvDelV->CurrentRow->Cells["loginDelV"]->Value->ToString();
    std::string Inp1 = msclr::interop::marshal_as<std::string>(Input1);
    String^ Input2 = dgvDelV->CurrentRow->Cells["nameDelV"]->Value->ToString();
    std::string Inp2 = msclr::interop::marshal_as<std::string>(Input2);
    String^ Input3 = dgvDelV->CurrentRow->Cells["date_visitDelV"]->Value->ToString();
    std::string Inp3 = msclr::interop::marshal_as<std::string>(Input3);
    String^ Input4 = dgvDelV->CurrentRow->Cells["time_visitDelV"]->Value->ToString();
    std::string Inp4 = msclr::interop::marshal_as<std::string>(Input4);
    std::string Inp22;
    pstmt = con->prepareStatement("SELECT bookstore.contact_number FROM bookstore WHERE name = ?");
    pstmt->setString(1, Inp2);
    res = pstmt->executeQuery();
    while (res->next())
    {
        String^ Input22 = gcnew System::String(res->getString("contact_number").c_str());
        Inp22 = msclr::interop::marshal_as<std::string>(Input22);
    }
    try
    {
        pstmt = con->prepareStatement("DELETE FROM visit WHERE date_visit = ? AND time_visit = ? AND login = ? AND contact_number = ?");
        pstmt->setString(1, Inp3);
        pstmt->setString(2, Inp4);
        pstmt->setString(3, Inp1);
        pstmt->setString(4, Inp22);
        pstmt->execute();
        buttonVisit4_Click(sender, e);
    }
    catch (sql::SQLException e)
    {
        MessageBox::Show("Error DB!", "Info");
    }
}
System::Void kurs::Admin::buttonReq1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = true;
        this->dgvReq2->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        this->dgvReq10->Visible = false;
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
System::Void kurs::Admin::buttonReq2_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq2->Visible = true;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        this->dgvReq10->Visible = false;
        String^ SearchInput = textReq2->Text;
        std::string search = msclr::interop::marshal_as<std::string>(SearchInput);
        try
        {
            pstmt = con->prepareStatement("SELECT buyer.login, buyer.name, buyer.contact_number FROM buyer WHERE buyer.name LIKE ? ORDER BY buyer.name ASC");
            pstmt->setString(1, search+"%");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginReq2");
            dt->Columns->Add("nameReq2");
            dt->Columns->Add("numberReq2");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginReq2"] = gcnew System::String(res->getString("login").c_str());
                row["nameReq2"] = gcnew System::String(res->getString("name").c_str());
                row["numberReq2"] = gcnew System::String(res->getString("contact_number").c_str());
                dt->Rows->Add(row);
            }
            dgvReq2->DataSource = dt;
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
System::Void kurs::Admin::buttonReq3_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq2->Visible = false;
        this->dgvReq3->Visible = true;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        this->dgvReq10->Visible = false;
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
System::Void kurs::Admin::buttonReq4_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq2->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = true;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        this->dgvReq10->Visible = false;
        try
        {
            pstmt = con->prepareStatement("SELECT COUNT(*) FROM purchase_book WHERE purchase_book.date BETWEEN DATE_SUB(CURDATE(), INTERVAL 7 DAY) AND CURDATE(); ");
            res = pstmt->executeQuery();
            while (res->next())
            {
                String ^ message = "In the last week, buyers made " + (gcnew System::String(res->getString("COUNT(*)").c_str()))+" purchases";
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
System::Void kurs::Admin::buttonReq5_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq2->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = true;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        this->dgvReq10->Visible = false;
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
System::Void kurs::Admin::buttonReq6_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq2->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = true;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        this->dgvReq10->Visible = false;
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
System::Void kurs::Admin::buttonReq7_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq2->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = true;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        this->dgvReq10->Visible = false;
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
System::Void kurs::Admin::buttonReq8_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq2->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = true;
        this->dgvReq9->Visible = false;
        this->dgvReq10->Visible = false;
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
System::Void kurs::Admin::buttonReq9_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq2->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = true;
        this->dgvReq10->Visible = false;
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
System::Void kurs::Admin::buttonReq10_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        this->dgvReq1->Visible = false;
        this->dgvReq2->Visible = false;
        this->dgvReq3->Visible = false;
        this->textReq4->Visible = false;
        this->dgvReq5->Visible = false;
        this->textReq6->Visible = false;
        this->dgvReq7->Visible = false;
        this->dgvReq8->Visible = false;
        this->dgvReq9->Visible = false;
        this->dgvReq10->Visible = true;
        try
        {
            pstmt = con->prepareStatement("SELECT employee.login, employee.nameE, COUNT(purchase.purchase_id) FROM employee LEFT JOIN purchase ON employee.login = purchase.login_employee GROUP BY employee.login, employee.nameE");
            res = pstmt->executeQuery();
            System::Data::DataTable^ dt = gcnew System::Data::DataTable();
            dt->Columns->Add("loginReq10");
            dt->Columns->Add("nameReq10");
            dt->Columns->Add("purchasesReq10");
            while (res->next())
            {
                DataRow^ row = dt->NewRow();
                row["loginReq10"] = gcnew System::String(res->getString("login").c_str());
                row["nameReq10"] = gcnew System::String(res->getString("nameE").c_str());
                row["purchasesReq10"] = gcnew System::String(res->getString("COUNT(purchase.purchase_id)").c_str());
                dt->Rows->Add(row);
            }
            dgvReq10->DataSource = dt;
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
