#pragma once
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
namespace kurs {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для Seller
	/// </summary>
	public ref class Seller : public System::Windows::Forms::Form
	{
	public:
		Seller(String^ login)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->labelLogin->Text = login;
            this->comboAddPurLogEmp->Text = login;
            this->comboEdPurLogEmp->Text = login;
            InitializeDatabaseConnection();
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Seller()
		{
			if (components)
			{
				delete components;
			}
            CloseDatabaseConnection();
		}
    private:
        System::String^ serverr;
        System::String^ usernamee;
        System::String^ passwordd;
        sql::Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::PreparedStatement* pstmt;
    private: System::Windows::Forms::TextBox^ comboAddPurLogEmp;
    private: System::Windows::Forms::TextBox^ comboEdPurLogEmp;
           sql::ResultSet* res;
        void InitializeDatabaseConnection();
        void CloseDatabaseConnection();
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вихідToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ проПрограмуToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonReq;
    private: System::Windows::Forms::Button^ buttonRevision;
	private: System::Windows::Forms::Label^ Label1;
    private: System::Windows::Forms::Button^ buttonDel;
    private: System::Windows::Forms::Button^ buttonAdd;
    private: System::Windows::Forms::Button^ buttonEdit;
	private: System::Windows::Forms::Label^ labelLogin;
    private: System::Windows::Forms::GroupBox^ groupBox1;
    private: System::Windows::Forms::GroupBox^ groupBox2;
    private: System::Windows::Forms::GroupBox^ groupBox3;
    private: System::Windows::Forms::GroupBox^ groupBox4;
    private: System::Windows::Forms::GroupBox^ groupBox5;
    private: System::Windows::Forms::GroupBox^ groupBox14;
    private: System::Windows::Forms::DataGridView^ dgvReq9;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginReq9;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ comReq9;
    private: System::Windows::Forms::Button^ buttonReq9;
    private: System::Windows::Forms::GroupBox^ groupBox13;
    private: System::Windows::Forms::DataGridView^ dgvReq8;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginReq8;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ numberReq8;
    private: System::Windows::Forms::Button^ buttonReq8;
    private: System::Windows::Forms::GroupBox^ groupBox12;
    private: System::Windows::Forms::DataGridView^ dgvReq7;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameReq7;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginReq7;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ visitReq7;
    private: System::Windows::Forms::Button^ buttonReq7;
    private: System::Windows::Forms::GroupBox^ groupBox11;
    private: System::Windows::Forms::TextBox^ textReq6;
    private: System::Windows::Forms::Button^ buttonReq6;
    private: System::Windows::Forms::GroupBox^ groupBox10;
    private: System::Windows::Forms::DataGridView^ dgvReq5;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginReq5;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ countReq5;
    private: System::Windows::Forms::Button^ buttonReq5;
    private: System::Windows::Forms::GroupBox^ groupBox9;
    private: System::Windows::Forms::TextBox^ textReq4;
    private: System::Windows::Forms::Button^ buttonReq4;
    private: System::Windows::Forms::GroupBox^ groupBox8;
    private: System::Windows::Forms::DataGridView^ dgvReq3;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ IDReq3;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginReq3;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameReq3;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dateReq3;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ timeReq3;
    private: System::Windows::Forms::Label^ label107;
    private: System::Windows::Forms::Button^ buttonReq3;
    private: System::Windows::Forms::DateTimePicker^ date1Req3;
    private: System::Windows::Forms::Label^ label106;
    private: System::Windows::Forms::DateTimePicker^ date2Req3;
    private: System::Windows::Forms::GroupBox^ groupBox6;
    private: System::Windows::Forms::DataGridView^ dgvReq1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ IDReq1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginReq1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameReq1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dateReq1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ timeReq1;
    private: System::Windows::Forms::TextBox^ textReq1;
    private: System::Windows::Forms::Button^ buttonReq1;
    private: System::Windows::Forms::GroupBox^ groupBoxDelBuy;
    private: System::Windows::Forms::GroupBox^ groupBoxDelPur;
    private: System::Windows::Forms::GroupBox^ groupBoxDelB;
    private: System::Windows::Forms::DataGridView^ dgvDelB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ isbnDelB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameDelB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ authorDelB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ costDelB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ genreDelB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ publishing_houseDelB;
    private: System::Windows::Forms::Button^ buttonDelB;
    private: System::Windows::Forms::Label^ label102;
    private: System::Windows::Forms::TextBox^ textSearchDel5;
    private: System::Windows::Forms::Button^ buttonSearchDel5;
    private: System::Windows::Forms::DataGridView^ dgvDelPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ idDelPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginDelPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginEmpDelPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ bookDelPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ costDelPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ quantityDelPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dateDelPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ timeDelPur;
    private: System::Windows::Forms::Button^ buttonDelPur;
    private: System::Windows::Forms::Label^ label99;
    private: System::Windows::Forms::TextBox^ textSearchDel2;
    private: System::Windows::Forms::Button^ buttonSearchDel2;
    private: System::Windows::Forms::DataGridView^ dgvDelBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginDelBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ passwordDelBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameDelBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ contact_numberDelBuy;
    private: System::Windows::Forms::Button^ buttonDelBuy;
    private: System::Windows::Forms::Label^ label104;
    private: System::Windows::Forms::TextBox^ textSearchDel;
    private: System::Windows::Forms::Button^ buttonSearchDel;
    private: System::Windows::Forms::Button^ buttonBuyer4;
    private: System::Windows::Forms::Button^ buttonPurchase4;
    private: System::Windows::Forms::Button^ buttonBook4;
    private: System::Windows::Forms::GroupBox^ groupBoxEdBuy;
    private: System::Windows::Forms::GroupBox^ groupBoxEdPur;
    private: System::Windows::Forms::GroupBox^ groupBoxEdB;
    private: System::Windows::Forms::TextBox^ textEdBIsbn;
    private: System::Windows::Forms::DataGridView^ dgvEdB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ isbnEdB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameEdB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ authorEdB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ costEdB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ genreEdB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ publishing_houseEdB;
    private: System::Windows::Forms::TextBox^ textEdBPH;
    private: System::Windows::Forms::Label^ label89;
    private: System::Windows::Forms::TextBox^ textEdBGenre;
    private: System::Windows::Forms::TextBox^ textEdBAuthor;
    private: System::Windows::Forms::TextBox^ textEdBCost;
    private: System::Windows::Forms::TextBox^ textBox5;
    private: System::Windows::Forms::Label^ label79;
    private: System::Windows::Forms::TextBox^ textEdBName;
    private: System::Windows::Forms::ComboBox^ comboBox2;
    private: System::Windows::Forms::Label^ label81;
    private: System::Windows::Forms::Label^ label82;
    private: System::Windows::Forms::Label^ label83;
    private: System::Windows::Forms::Button^ buttonEdB;
    private: System::Windows::Forms::Label^ label88;
    private: System::Windows::Forms::TextBox^ textSearchEd5;
    private: System::Windows::Forms::Button^ buttonSearchEd5;
    private: System::Windows::Forms::TextBox^ textEdPurId;
    private: System::Windows::Forms::Label^ label69;
    private: System::Windows::Forms::TextBox^ textEdPurCost;
    private: System::Windows::Forms::Label^ label68;
    private: System::Windows::Forms::ComboBox^ comboEdPurB;
    private: System::Windows::Forms::ComboBox^ comboEdPurLogBuy;
    private: System::Windows::Forms::NumericUpDown^ numericEdPurQua;
    private: System::Windows::Forms::DateTimePicker^ timeEdPurTime;
    private: System::Windows::Forms::DateTimePicker^ dateEdPurDate;
    private: System::Windows::Forms::Label^ label67;
    private: System::Windows::Forms::DataGridView^ dgvEdPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ idEdPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginEdPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginEmpEdPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ bookEdPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ costEdPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ quantityEdPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dateEdPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ timeEdPur;
    private: System::Windows::Forms::Label^ label65;
    private: System::Windows::Forms::Label^ label64;
    private: System::Windows::Forms::Label^ label63;
    private: System::Windows::Forms::Label^ label62;
    private: System::Windows::Forms::Button^ buttonEdPur;
    private: System::Windows::Forms::Label^ label66;
    private: System::Windows::Forms::TextBox^ textSearchEd2;
    private: System::Windows::Forms::Button^ buttonSearchEd2;
    private: System::Windows::Forms::Label^ label61;
    private: System::Windows::Forms::Label^ label60;
    private: System::Windows::Forms::Label^ label59;
    private: System::Windows::Forms::Label^ label58;
    private: System::Windows::Forms::Button^ buttonEdBuy;
    private: System::Windows::Forms::TextBox^ textEdBuyNum;
    private: System::Windows::Forms::TextBox^ textEdBuyName;
    private: System::Windows::Forms::TextBox^ textEdBuyPass;
    private: System::Windows::Forms::TextBox^ textEdBuyLog;
    private: System::Windows::Forms::Label^ label57;
    private: System::Windows::Forms::TextBox^ textSearchEd;
    private: System::Windows::Forms::Button^ buttonSearchEd;
    private: System::Windows::Forms::DataGridView^ dgvEdBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginEdBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ passwordEdBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameEdBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ contact_numberEdBuy;
    private: System::Windows::Forms::Button^ buttonBuyer3;
    private: System::Windows::Forms::Button^ buttonPurchase3;
    private: System::Windows::Forms::Button^ buttonBook3;
    private: System::Windows::Forms::GroupBox^ groupBoxAddBuy;
    private: System::Windows::Forms::GroupBox^ groupBoxAddPur;
    private: System::Windows::Forms::GroupBox^ groupBoxAddB;
    private: System::Windows::Forms::TextBox^ textAddBPH;
    private: System::Windows::Forms::Label^ label48;
    private: System::Windows::Forms::TextBox^ textAddBGenre;
    private: System::Windows::Forms::Label^ label47;
    private: System::Windows::Forms::DataGridView^ dgvAddB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ isbnAddB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameAddB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ authorAddB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ costAddB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ genreAddB;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ publishing_houseAddB;
    private: System::Windows::Forms::TextBox^ textAddBCost;
    private: System::Windows::Forms::TextBox^ textAddBAuthor;
    private: System::Windows::Forms::TextBox^ textAddBName;
    private: System::Windows::Forms::Label^ label39;
    private: System::Windows::Forms::Label^ label40;
    private: System::Windows::Forms::Label^ label45;
    private: System::Windows::Forms::Button^ buttonAddB;
    private: System::Windows::Forms::Label^ label46;
    private: System::Windows::Forms::TextBox^ textSearchAdd5;
    private: System::Windows::Forms::Button^ buttonSearchAdd5;
    private: System::Windows::Forms::ComboBox^ comboAddPurB;
    private: System::Windows::Forms::ComboBox^ comboAddPurLogBuy;
    private: System::Windows::Forms::NumericUpDown^ numericAddPurQua;
    private: System::Windows::Forms::DateTimePicker^ timeAddPurTime;
    private: System::Windows::Forms::DateTimePicker^ dateAddPurDate;
    private: System::Windows::Forms::Label^ label28;
    private: System::Windows::Forms::Label^ label27;
    private: System::Windows::Forms::DataGridView^ dgvAddPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ idAddPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginAddPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginEmpAddPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ bookAddPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ costAddPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ quantityAddPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ dateAddPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ timeAddPur;
    private: System::Windows::Forms::Label^ label22;
    private: System::Windows::Forms::Label^ label23;
    private: System::Windows::Forms::Label^ label24;
    private: System::Windows::Forms::Label^ label25;
    private: System::Windows::Forms::Button^ buttonAddPur;
    private: System::Windows::Forms::Label^ label26;
    private: System::Windows::Forms::TextBox^ textSearchAdd2;
    private: System::Windows::Forms::Button^ buttonSearchAdd2;
    private: System::Windows::Forms::Label^ label21;
    private: System::Windows::Forms::Label^ label20;
    private: System::Windows::Forms::Label^ label19;
    private: System::Windows::Forms::Label^ label18;
    private: System::Windows::Forms::Button^ buttonAddBuy;
    private: System::Windows::Forms::TextBox^ textAddBuyNum;
    private: System::Windows::Forms::TextBox^ textAddBuyName;
    private: System::Windows::Forms::TextBox^ textAddBuyPass;
    private: System::Windows::Forms::TextBox^ textAddBuyLog;
    private: System::Windows::Forms::Label^ label17;
    private: System::Windows::Forms::TextBox^ textSearchAdd;
    private: System::Windows::Forms::Button^ buttonSearchAdd;
    private: System::Windows::Forms::DataGridView^ dgvAddBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginAddBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ passwordAddBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameAddBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ contact_numberAddBuy;
    private: System::Windows::Forms::Button^ buttonBuyer2;
    private: System::Windows::Forms::Button^ buttonPurchase2;
    private: System::Windows::Forms::Button^ buttonBook2;
    private: System::Windows::Forms::GroupBox^ groupBoxRevBuy;
    private: System::Windows::Forms::GroupBox^ groupBoxRevPur;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Button^ buttonPurCal;
    private: System::Windows::Forms::DateTimePicker^ datePur2;
    private: System::Windows::Forms::DateTimePicker^ datePur1;
    private: System::Windows::Forms::Button^ buttonSearch2;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::TextBox^ textSearch2;
    private: System::Windows::Forms::DataGridView^ dgvRevPur;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ purchase_id;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginRevPurBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginRevPurEmp;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ book;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ cost;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ quantity;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ date;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ time;
    private: System::Windows::Forms::Button^ buttonSearch;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::TextBox^ textSearch;
    private: System::Windows::Forms::DataGridView^ dgvRevBuy;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ login;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ password;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ contact_number;
    private: System::Windows::Forms::Button^ buttonBuyer;
    private: System::Windows::Forms::Button^ buttonBookstore;
    private: System::Windows::Forms::Button^ buttonVisit;
    private: System::Windows::Forms::Button^ buttonPurchase;
    private: System::Windows::Forms::Button^ buttonBook;
private: System::Windows::Forms::GroupBox^ groupBoxRevBS;
private: System::Windows::Forms::GroupBox^ groupBoxRevB;
private: System::Windows::Forms::GroupBox^ groupBoxRevV;
private: System::Windows::Forms::Button^ buttonVCal;
private: System::Windows::Forms::DateTimePicker^ dateV2;
private: System::Windows::Forms::DateTimePicker^ dateV1;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Button^ buttonSearch7;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::TextBox^ textSearch7;
private: System::Windows::Forms::DataGridView^ dgvRevV;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginRevVBuy;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameRevVBS;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ date_visitRev;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ time_visitRev;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ noteRev;
private: System::Windows::Forms::Button^ buttonSearchRevCost;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::NumericUpDown^ numericUpDownRev2;
private: System::Windows::Forms::NumericUpDown^ numericUpDownRev1;
private: System::Windows::Forms::Button^ buttonSearch5;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::TextBox^ textSearch5;
private: System::Windows::Forms::DataGridView^ dgvRevB;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ isbnRev;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameRevB;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ authorRev;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ costRevB;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ genreRev;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ publishing_houseRev;
private: System::Windows::Forms::Button^ buttonSearch4;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::TextBox^ textSearch4;
private: System::Windows::Forms::DataGridView^ dgvRevBS;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameRevBS;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ contact_numberRevBS;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ addressRevBS;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ work_scheduleRev;
    protected:
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Seller::typeid));
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->labelLogin = (gcnew System::Windows::Forms::Label());
            this->buttonReq = (gcnew System::Windows::Forms::Button());
            this->buttonRevision = (gcnew System::Windows::Forms::Button());
            this->Label1 = (gcnew System::Windows::Forms::Label());
            this->buttonDel = (gcnew System::Windows::Forms::Button());
            this->buttonAdd = (gcnew System::Windows::Forms::Button());
            this->buttonEdit = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->проПрограмуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox14 = (gcnew System::Windows::Forms::GroupBox());
            this->dgvReq9 = (gcnew System::Windows::Forms::DataGridView());
            this->loginReq9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->comReq9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonReq9 = (gcnew System::Windows::Forms::Button());
            this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
            this->dgvReq8 = (gcnew System::Windows::Forms::DataGridView());
            this->loginReq8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->numberReq8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonReq8 = (gcnew System::Windows::Forms::Button());
            this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
            this->textReq6 = (gcnew System::Windows::Forms::TextBox());
            this->buttonReq6 = (gcnew System::Windows::Forms::Button());
            this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
            this->dgvReq7 = (gcnew System::Windows::Forms::DataGridView());
            this->nameReq7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->loginReq7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->visitReq7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonReq7 = (gcnew System::Windows::Forms::Button());
            this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
            this->dgvReq3 = (gcnew System::Windows::Forms::DataGridView());
            this->IDReq3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->loginReq3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->nameReq3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dateReq3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->timeReq3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->label107 = (gcnew System::Windows::Forms::Label());
            this->buttonReq3 = (gcnew System::Windows::Forms::Button());
            this->date1Req3 = (gcnew System::Windows::Forms::DateTimePicker());
            this->label106 = (gcnew System::Windows::Forms::Label());
            this->date2Req3 = (gcnew System::Windows::Forms::DateTimePicker());
            this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
            this->dgvReq5 = (gcnew System::Windows::Forms::DataGridView());
            this->loginReq5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->countReq5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonReq5 = (gcnew System::Windows::Forms::Button());
            this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
            this->textReq4 = (gcnew System::Windows::Forms::TextBox());
            this->buttonReq4 = (gcnew System::Windows::Forms::Button());
            this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
            this->dgvReq1 = (gcnew System::Windows::Forms::DataGridView());
            this->IDReq1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->loginReq1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->nameReq1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dateReq1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->timeReq1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonReq1 = (gcnew System::Windows::Forms::Button());
            this->textReq1 = (gcnew System::Windows::Forms::TextBox());
            this->groupBoxDelBuy = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxDelPur = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxDelB = (gcnew System::Windows::Forms::GroupBox());
            this->dgvDelB = (gcnew System::Windows::Forms::DataGridView());
            this->isbnDelB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->nameDelB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->authorDelB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->costDelB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->genreDelB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->publishing_houseDelB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonDelB = (gcnew System::Windows::Forms::Button());
            this->label102 = (gcnew System::Windows::Forms::Label());
            this->textSearchDel5 = (gcnew System::Windows::Forms::TextBox());
            this->buttonSearchDel5 = (gcnew System::Windows::Forms::Button());
            this->dgvDelPur = (gcnew System::Windows::Forms::DataGridView());
            this->idDelPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->loginDelPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->loginEmpDelPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->bookDelPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->costDelPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->quantityDelPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dateDelPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->timeDelPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonDelPur = (gcnew System::Windows::Forms::Button());
            this->label99 = (gcnew System::Windows::Forms::Label());
            this->textSearchDel2 = (gcnew System::Windows::Forms::TextBox());
            this->buttonSearchDel2 = (gcnew System::Windows::Forms::Button());
            this->dgvDelBuy = (gcnew System::Windows::Forms::DataGridView());
            this->loginDelBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->passwordDelBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->nameDelBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->contact_numberDelBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonDelBuy = (gcnew System::Windows::Forms::Button());
            this->label104 = (gcnew System::Windows::Forms::Label());
            this->textSearchDel = (gcnew System::Windows::Forms::TextBox());
            this->buttonSearchDel = (gcnew System::Windows::Forms::Button());
            this->buttonBuyer4 = (gcnew System::Windows::Forms::Button());
            this->buttonPurchase4 = (gcnew System::Windows::Forms::Button());
            this->buttonBook4 = (gcnew System::Windows::Forms::Button());
            this->groupBoxEdBuy = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxEdPur = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxEdB = (gcnew System::Windows::Forms::GroupBox());
            this->textEdBIsbn = (gcnew System::Windows::Forms::TextBox());
            this->dgvEdB = (gcnew System::Windows::Forms::DataGridView());
            this->isbnEdB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->nameEdB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->authorEdB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->costEdB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->genreEdB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->publishing_houseEdB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->textEdBPH = (gcnew System::Windows::Forms::TextBox());
            this->label89 = (gcnew System::Windows::Forms::Label());
            this->textEdBGenre = (gcnew System::Windows::Forms::TextBox());
            this->textEdBAuthor = (gcnew System::Windows::Forms::TextBox());
            this->textEdBCost = (gcnew System::Windows::Forms::TextBox());
            this->textBox5 = (gcnew System::Windows::Forms::TextBox());
            this->label79 = (gcnew System::Windows::Forms::Label());
            this->textEdBName = (gcnew System::Windows::Forms::TextBox());
            this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
            this->label81 = (gcnew System::Windows::Forms::Label());
            this->label82 = (gcnew System::Windows::Forms::Label());
            this->label83 = (gcnew System::Windows::Forms::Label());
            this->buttonEdB = (gcnew System::Windows::Forms::Button());
            this->label88 = (gcnew System::Windows::Forms::Label());
            this->textSearchEd5 = (gcnew System::Windows::Forms::TextBox());
            this->buttonSearchEd5 = (gcnew System::Windows::Forms::Button());
            this->textEdPurId = (gcnew System::Windows::Forms::TextBox());
            this->label69 = (gcnew System::Windows::Forms::Label());
            this->textEdPurCost = (gcnew System::Windows::Forms::TextBox());
            this->label68 = (gcnew System::Windows::Forms::Label());
            this->comboEdPurLogEmp = (gcnew System::Windows::Forms::TextBox());
            this->comboEdPurB = (gcnew System::Windows::Forms::ComboBox());
            this->comboEdPurLogBuy = (gcnew System::Windows::Forms::ComboBox());
            this->numericEdPurQua = (gcnew System::Windows::Forms::NumericUpDown());
            this->timeEdPurTime = (gcnew System::Windows::Forms::DateTimePicker());
            this->dateEdPurDate = (gcnew System::Windows::Forms::DateTimePicker());
            this->label67 = (gcnew System::Windows::Forms::Label());
            this->dgvEdPur = (gcnew System::Windows::Forms::DataGridView());
            this->idEdPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->loginEdPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->loginEmpEdPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->bookEdPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->costEdPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->quantityEdPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dateEdPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->timeEdPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->label65 = (gcnew System::Windows::Forms::Label());
            this->label64 = (gcnew System::Windows::Forms::Label());
            this->label63 = (gcnew System::Windows::Forms::Label());
            this->label62 = (gcnew System::Windows::Forms::Label());
            this->buttonEdPur = (gcnew System::Windows::Forms::Button());
            this->label66 = (gcnew System::Windows::Forms::Label());
            this->textSearchEd2 = (gcnew System::Windows::Forms::TextBox());
            this->buttonSearchEd2 = (gcnew System::Windows::Forms::Button());
            this->label61 = (gcnew System::Windows::Forms::Label());
            this->label60 = (gcnew System::Windows::Forms::Label());
            this->label59 = (gcnew System::Windows::Forms::Label());
            this->label58 = (gcnew System::Windows::Forms::Label());
            this->buttonEdBuy = (gcnew System::Windows::Forms::Button());
            this->textEdBuyNum = (gcnew System::Windows::Forms::TextBox());
            this->textEdBuyName = (gcnew System::Windows::Forms::TextBox());
            this->textEdBuyPass = (gcnew System::Windows::Forms::TextBox());
            this->textEdBuyLog = (gcnew System::Windows::Forms::TextBox());
            this->label57 = (gcnew System::Windows::Forms::Label());
            this->textSearchEd = (gcnew System::Windows::Forms::TextBox());
            this->buttonSearchEd = (gcnew System::Windows::Forms::Button());
            this->dgvEdBuy = (gcnew System::Windows::Forms::DataGridView());
            this->loginEdBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->passwordEdBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->nameEdBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->contact_numberEdBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonBuyer3 = (gcnew System::Windows::Forms::Button());
            this->buttonPurchase3 = (gcnew System::Windows::Forms::Button());
            this->buttonBook3 = (gcnew System::Windows::Forms::Button());
            this->groupBoxAddBuy = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxAddPur = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxAddB = (gcnew System::Windows::Forms::GroupBox());
            this->textAddBPH = (gcnew System::Windows::Forms::TextBox());
            this->label48 = (gcnew System::Windows::Forms::Label());
            this->textAddBGenre = (gcnew System::Windows::Forms::TextBox());
            this->label47 = (gcnew System::Windows::Forms::Label());
            this->dgvAddB = (gcnew System::Windows::Forms::DataGridView());
            this->isbnAddB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->nameAddB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->authorAddB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->costAddB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->genreAddB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->publishing_houseAddB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->textAddBCost = (gcnew System::Windows::Forms::TextBox());
            this->textAddBAuthor = (gcnew System::Windows::Forms::TextBox());
            this->textAddBName = (gcnew System::Windows::Forms::TextBox());
            this->label39 = (gcnew System::Windows::Forms::Label());
            this->label40 = (gcnew System::Windows::Forms::Label());
            this->label45 = (gcnew System::Windows::Forms::Label());
            this->buttonAddB = (gcnew System::Windows::Forms::Button());
            this->label46 = (gcnew System::Windows::Forms::Label());
            this->textSearchAdd5 = (gcnew System::Windows::Forms::TextBox());
            this->buttonSearchAdd5 = (gcnew System::Windows::Forms::Button());
            this->comboAddPurB = (gcnew System::Windows::Forms::ComboBox());
            this->comboAddPurLogEmp = (gcnew System::Windows::Forms::TextBox());
            this->comboAddPurLogBuy = (gcnew System::Windows::Forms::ComboBox());
            this->numericAddPurQua = (gcnew System::Windows::Forms::NumericUpDown());
            this->timeAddPurTime = (gcnew System::Windows::Forms::DateTimePicker());
            this->dateAddPurDate = (gcnew System::Windows::Forms::DateTimePicker());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->label27 = (gcnew System::Windows::Forms::Label());
            this->dgvAddPur = (gcnew System::Windows::Forms::DataGridView());
            this->idAddPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->loginAddPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->loginEmpAddPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->bookAddPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->costAddPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->quantityAddPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->dateAddPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->timeAddPur = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->label25 = (gcnew System::Windows::Forms::Label());
            this->buttonAddPur = (gcnew System::Windows::Forms::Button());
            this->label26 = (gcnew System::Windows::Forms::Label());
            this->textSearchAdd2 = (gcnew System::Windows::Forms::TextBox());
            this->buttonSearchAdd2 = (gcnew System::Windows::Forms::Button());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->buttonAddBuy = (gcnew System::Windows::Forms::Button());
            this->textAddBuyNum = (gcnew System::Windows::Forms::TextBox());
            this->textAddBuyName = (gcnew System::Windows::Forms::TextBox());
            this->textAddBuyPass = (gcnew System::Windows::Forms::TextBox());
            this->textAddBuyLog = (gcnew System::Windows::Forms::TextBox());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->textSearchAdd = (gcnew System::Windows::Forms::TextBox());
            this->buttonSearchAdd = (gcnew System::Windows::Forms::Button());
            this->dgvAddBuy = (gcnew System::Windows::Forms::DataGridView());
            this->loginAddBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->passwordAddBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->nameAddBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->contact_numberAddBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonBuyer2 = (gcnew System::Windows::Forms::Button());
            this->buttonPurchase2 = (gcnew System::Windows::Forms::Button());
            this->buttonBook2 = (gcnew System::Windows::Forms::Button());
            this->groupBoxRevBuy = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxRevPur = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxRevBS = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxRevB = (gcnew System::Windows::Forms::GroupBox());
            this->groupBoxRevV = (gcnew System::Windows::Forms::GroupBox());
            this->buttonVCal = (gcnew System::Windows::Forms::Button());
            this->dateV2 = (gcnew System::Windows::Forms::DateTimePicker());
            this->dateV1 = (gcnew System::Windows::Forms::DateTimePicker());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->buttonSearch7 = (gcnew System::Windows::Forms::Button());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->textSearch7 = (gcnew System::Windows::Forms::TextBox());
            this->dgvRevV = (gcnew System::Windows::Forms::DataGridView());
            this->loginRevVBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->nameRevVBS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->date_visitRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->time_visitRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->noteRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonSearchRevCost = (gcnew System::Windows::Forms::Button());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->numericUpDownRev2 = (gcnew System::Windows::Forms::NumericUpDown());
            this->numericUpDownRev1 = (gcnew System::Windows::Forms::NumericUpDown());
            this->buttonSearch5 = (gcnew System::Windows::Forms::Button());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->textSearch5 = (gcnew System::Windows::Forms::TextBox());
            this->dgvRevB = (gcnew System::Windows::Forms::DataGridView());
            this->isbnRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->nameRevB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->authorRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->costRevB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->genreRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->publishing_houseRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonSearch4 = (gcnew System::Windows::Forms::Button());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->textSearch4 = (gcnew System::Windows::Forms::TextBox());
            this->dgvRevBS = (gcnew System::Windows::Forms::DataGridView());
            this->nameRevBS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->contact_numberRevBS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->addressRevBS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->work_scheduleRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->buttonPurCal = (gcnew System::Windows::Forms::Button());
            this->datePur2 = (gcnew System::Windows::Forms::DateTimePicker());
            this->datePur1 = (gcnew System::Windows::Forms::DateTimePicker());
            this->buttonSearch2 = (gcnew System::Windows::Forms::Button());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->textSearch2 = (gcnew System::Windows::Forms::TextBox());
            this->dgvRevPur = (gcnew System::Windows::Forms::DataGridView());
            this->purchase_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->loginRevPurBuy = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->loginRevPurEmp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->book = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->cost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->quantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonSearch = (gcnew System::Windows::Forms::Button());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->textSearch = (gcnew System::Windows::Forms::TextBox());
            this->dgvRevBuy = (gcnew System::Windows::Forms::DataGridView());
            this->login = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->password = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->contact_number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->buttonBuyer = (gcnew System::Windows::Forms::Button());
            this->buttonBookstore = (gcnew System::Windows::Forms::Button());
            this->buttonVisit = (gcnew System::Windows::Forms::Button());
            this->buttonPurchase = (gcnew System::Windows::Forms::Button());
            this->buttonBook = (gcnew System::Windows::Forms::Button());
            this->panel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->menuStrip1->SuspendLayout();
            this->groupBox1->SuspendLayout();
            this->groupBox2->SuspendLayout();
            this->groupBox3->SuspendLayout();
            this->groupBox4->SuspendLayout();
            this->groupBox5->SuspendLayout();
            this->groupBox14->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq9))->BeginInit();
            this->groupBox13->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq8))->BeginInit();
            this->groupBox11->SuspendLayout();
            this->groupBox12->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq7))->BeginInit();
            this->groupBox8->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq3))->BeginInit();
            this->groupBox10->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq5))->BeginInit();
            this->groupBox9->SuspendLayout();
            this->groupBox6->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq1))->BeginInit();
            this->groupBoxDelBuy->SuspendLayout();
            this->groupBoxDelPur->SuspendLayout();
            this->groupBoxDelB->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDelB))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDelPur))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDelBuy))->BeginInit();
            this->groupBoxEdBuy->SuspendLayout();
            this->groupBoxEdPur->SuspendLayout();
            this->groupBoxEdB->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEdB))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericEdPurQua))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEdPur))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEdBuy))->BeginInit();
            this->groupBoxAddBuy->SuspendLayout();
            this->groupBoxAddPur->SuspendLayout();
            this->groupBoxAddB->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAddB))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericAddPurQua))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAddPur))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAddBuy))->BeginInit();
            this->groupBoxRevBuy->SuspendLayout();
            this->groupBoxRevPur->SuspendLayout();
            this->groupBoxRevBS->SuspendLayout();
            this->groupBoxRevB->SuspendLayout();
            this->groupBoxRevV->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevV))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownRev2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownRev1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevB))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevBS))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevPur))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevBuy))->BeginInit();
            this->SuspendLayout();
            // 
            // button2
            // 
            this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->button2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->button2->FlatAppearance->BorderSize = 0;
            this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
            this->button2->Location = System::Drawing::Point(206, 1010);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(30, 29);
            this->button2->TabIndex = 12;
            this->button2->Text = L"←";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &Seller::button2_Click);
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::SystemColors::ControlDark;
            this->panel1->Controls->Add(this->labelLogin);
            this->panel1->Controls->Add(this->buttonReq);
            this->panel1->Controls->Add(this->buttonRevision);
            this->panel1->Controls->Add(this->Label1);
            this->panel1->Controls->Add(this->buttonDel);
            this->panel1->Controls->Add(this->buttonAdd);
            this->panel1->Controls->Add(this->buttonEdit);
            this->panel1->Controls->Add(this->label2);
            this->panel1->Controls->Add(this->pictureBox1);
            this->panel1->Controls->Add(this->button2);
            this->panel1->Controls->Add(this->menuStrip1);
            this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(239, 1041);
            this->panel1->TabIndex = 13;
            // 
            // labelLogin
            // 
            this->labelLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->labelLogin->AutoSize = true;
            this->labelLogin->BackColor = System::Drawing::SystemColors::ControlDark;
            this->labelLogin->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold));
            this->labelLogin->Location = System::Drawing::Point(82, 983);
            this->labelLogin->Name = L"labelLogin";
            this->labelLogin->Size = System::Drawing::Size(54, 23);
            this->labelLogin->TabIndex = 14;
            this->labelLogin->Text = L"Login";
            // 
            // buttonReq
            // 
            this->buttonReq->BackColor = System::Drawing::SystemColors::ControlDarkDark;
            this->buttonReq->FlatAppearance->BorderSize = 0;
            this->buttonReq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonReq->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonReq->Location = System::Drawing::Point(29, 566);
            this->buttonReq->Name = L"buttonReq";
            this->buttonReq->Size = System::Drawing::Size(177, 52);
            this->buttonReq->TabIndex = 23;
            this->buttonReq->Text = L"Запити";
            this->buttonReq->UseVisualStyleBackColor = false;
            this->buttonReq->Click += gcnew System::EventHandler(this, &Seller::buttonReq_Click);
            // 
            // buttonRevision
            // 
            this->buttonRevision->BackColor = System::Drawing::SystemColors::ControlDarkDark;
            this->buttonRevision->FlatAppearance->BorderSize = 0;
            this->buttonRevision->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonRevision->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonRevision->Location = System::Drawing::Point(29, 248);
            this->buttonRevision->Name = L"buttonRevision";
            this->buttonRevision->Size = System::Drawing::Size(177, 52);
            this->buttonRevision->TabIndex = 19;
            this->buttonRevision->Text = L"Перегляд";
            this->buttonRevision->UseVisualStyleBackColor = false;
            this->buttonRevision->Click += gcnew System::EventHandler(this, &Seller::buttonRevision_Click);
            // 
            // Label1
            // 
            this->Label1->AutoSize = true;
            this->Label1->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold));
            this->Label1->Location = System::Drawing::Point(60, 164);
            this->Label1->Name = L"Label1";
            this->Label1->Size = System::Drawing::Size(120, 37);
            this->Label1->TabIndex = 18;
            this->Label1->Text = L"МЕНЮ";
            // 
            // buttonDel
            // 
            this->buttonDel->BackColor = System::Drawing::SystemColors::ControlDarkDark;
            this->buttonDel->FlatAppearance->BorderSize = 0;
            this->buttonDel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonDel->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonDel->Location = System::Drawing::Point(29, 488);
            this->buttonDel->Name = L"buttonDel";
            this->buttonDel->Size = System::Drawing::Size(177, 52);
            this->buttonDel->TabIndex = 22;
            this->buttonDel->Text = L"Видалення";
            this->buttonDel->UseVisualStyleBackColor = false;
            this->buttonDel->Click += gcnew System::EventHandler(this, &Seller::buttonDel_Click);
            // 
            // buttonAdd
            // 
            this->buttonAdd->BackColor = System::Drawing::SystemColors::ControlDarkDark;
            this->buttonAdd->FlatAppearance->BorderSize = 0;
            this->buttonAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonAdd->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonAdd->Location = System::Drawing::Point(29, 325);
            this->buttonAdd->Name = L"buttonAdd";
            this->buttonAdd->Size = System::Drawing::Size(177, 52);
            this->buttonAdd->TabIndex = 20;
            this->buttonAdd->Text = L"Додавання";
            this->buttonAdd->UseVisualStyleBackColor = false;
            this->buttonAdd->Click += gcnew System::EventHandler(this, &Seller::buttonAdd_Click);
            // 
            // buttonEdit
            // 
            this->buttonEdit->BackColor = System::Drawing::SystemColors::ControlDarkDark;
            this->buttonEdit->FlatAppearance->BorderSize = 0;
            this->buttonEdit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonEdit->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonEdit->Location = System::Drawing::Point(29, 408);
            this->buttonEdit->Name = L"buttonEdit";
            this->buttonEdit->Size = System::Drawing::Size(177, 52);
            this->buttonEdit->TabIndex = 21;
            this->buttonEdit->Text = L"Редагування";
            this->buttonEdit->UseVisualStyleBackColor = false;
            this->buttonEdit->Click += gcnew System::EventHandler(this, &Seller::buttonEdit_Click);
            // 
            // label2
            // 
            this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold));
            this->label2->Location = System::Drawing::Point(82, 1014);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(99, 23);
            this->label2->TabIndex = 17;
            this->label2->Text = L"Продавець";
            // 
            // pictureBox1
            // 
            this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(3, 971);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(73, 70);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 16;
            this->pictureBox1->TabStop = false;
            // 
            // menuStrip1
            // 
            this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
            this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
            this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                this->вихідToolStripMenuItem,
                    this->проПрограмуToolStripMenuItem
            });
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(239, 24);
            this->menuStrip1->TabIndex = 15;
            this->menuStrip1->Text = L"menuStrip1";
            // 
            // вихідToolStripMenuItem
            // 
            this->вихідToolStripMenuItem->Name = L"вихідToolStripMenuItem";
            this->вихідToolStripMenuItem->Size = System::Drawing::Size(48, 20);
            this->вихідToolStripMenuItem->Text = L"Вихід";
            this->вихідToolStripMenuItem->Click += gcnew System::EventHandler(this, &Seller::вихідToolStripMenuItem_Click);
            // 
            // проПрограмуToolStripMenuItem
            // 
            this->проПрограмуToolStripMenuItem->Name = L"проПрограмуToolStripMenuItem";
            this->проПрограмуToolStripMenuItem->Size = System::Drawing::Size(99, 20);
            this->проПрограмуToolStripMenuItem->Text = L"Про програму";
            this->проПрограмуToolStripMenuItem->Click += gcnew System::EventHandler(this, &Seller::проПрограмуToolStripMenuItem_Click);
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->groupBox2);
            this->groupBox1->Controls->Add(this->groupBoxRevBuy);
            this->groupBox1->Controls->Add(this->buttonBuyer);
            this->groupBox1->Controls->Add(this->buttonBookstore);
            this->groupBox1->Controls->Add(this->buttonVisit);
            this->groupBox1->Controls->Add(this->buttonPurchase);
            this->groupBox1->Controls->Add(this->buttonBook);
            this->groupBox1->Enabled = false;
            this->groupBox1->Location = System::Drawing::Point(244, 0);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(1659, 1029);
            this->groupBox1->TabIndex = 15;
            this->groupBox1->TabStop = false;
            this->groupBox1->Visible = false;
            // 
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->groupBox3);
            this->groupBox2->Controls->Add(this->groupBoxAddBuy);
            this->groupBox2->Controls->Add(this->buttonBuyer2);
            this->groupBox2->Controls->Add(this->buttonPurchase2);
            this->groupBox2->Controls->Add(this->buttonBook2);
            this->groupBox2->Enabled = false;
            this->groupBox2->Location = System::Drawing::Point(0, 0);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(1659, 1029);
            this->groupBox2->TabIndex = 15;
            this->groupBox2->TabStop = false;
            this->groupBox2->Visible = false;
            // 
            // groupBox3
            // 
            this->groupBox3->Controls->Add(this->groupBox4);
            this->groupBox3->Controls->Add(this->groupBoxEdBuy);
            this->groupBox3->Controls->Add(this->buttonBuyer3);
            this->groupBox3->Controls->Add(this->buttonPurchase3);
            this->groupBox3->Controls->Add(this->buttonBook3);
            this->groupBox3->Enabled = false;
            this->groupBox3->Location = System::Drawing::Point(0, 0);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(1659, 1029);
            this->groupBox3->TabIndex = 16;
            this->groupBox3->TabStop = false;
            this->groupBox3->Visible = false;
            // 
            // groupBox4
            // 
            this->groupBox4->Controls->Add(this->groupBox5);
            this->groupBox4->Controls->Add(this->groupBoxDelBuy);
            this->groupBox4->Controls->Add(this->buttonBuyer4);
            this->groupBox4->Controls->Add(this->buttonPurchase4);
            this->groupBox4->Controls->Add(this->buttonBook4);
            this->groupBox4->Enabled = false;
            this->groupBox4->Location = System::Drawing::Point(0, 0);
            this->groupBox4->Name = L"groupBox4";
            this->groupBox4->Size = System::Drawing::Size(1659, 1029);
            this->groupBox4->TabIndex = 16;
            this->groupBox4->TabStop = false;
            this->groupBox4->Visible = false;
            // 
            // groupBox5
            // 
            this->groupBox5->Controls->Add(this->groupBox14);
            this->groupBox5->Controls->Add(this->groupBox13);
            this->groupBox5->Controls->Add(this->groupBox11);
            this->groupBox5->Controls->Add(this->groupBox12);
            this->groupBox5->Controls->Add(this->groupBox8);
            this->groupBox5->Controls->Add(this->groupBox10);
            this->groupBox5->Controls->Add(this->groupBox9);
            this->groupBox5->Controls->Add(this->groupBox6);
            this->groupBox5->Enabled = false;
            this->groupBox5->Location = System::Drawing::Point(0, 0);
            this->groupBox5->Name = L"groupBox5";
            this->groupBox5->Size = System::Drawing::Size(1659, 1029);
            this->groupBox5->TabIndex = 17;
            this->groupBox5->TabStop = false;
            this->groupBox5->Visible = false;
            // 
            // groupBox14
            // 
            this->groupBox14->Controls->Add(this->dgvReq9);
            this->groupBox14->Controls->Add(this->buttonReq9);
            this->groupBox14->Location = System::Drawing::Point(836, 819);
            this->groupBox14->Name = L"groupBox14";
            this->groupBox14->Size = System::Drawing::Size(812, 150);
            this->groupBox14->TabIndex = 57;
            this->groupBox14->TabStop = false;
            // 
            // dgvReq9
            // 
            this->dgvReq9->AllowUserToAddRows = false;
            this->dgvReq9->AllowUserToDeleteRows = false;
            this->dgvReq9->AllowUserToResizeColumns = false;
            this->dgvReq9->AllowUserToResizeRows = false;
            this->dgvReq9->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvReq9->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvReq9->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->loginReq9, this->comReq9 });
            this->dgvReq9->Location = System::Drawing::Point(315, 9);
            this->dgvReq9->Name = L"dgvReq9";
            this->dgvReq9->Size = System::Drawing::Size(494, 135);
            this->dgvReq9->TabIndex = 63;
            this->dgvReq9->Visible = false;
            // 
            // loginReq9
            // 
            this->loginReq9->DataPropertyName = L"loginReq9";
            this->loginReq9->HeaderText = L"Логін покупця";
            this->loginReq9->Name = L"loginReq9";
            this->loginReq9->ReadOnly = true;
            this->loginReq9->Width = 250;
            // 
            // comReq9
            // 
            this->comReq9->DataPropertyName = L"comReq9";
            this->comReq9->HeaderText = L"Номер телефону";
            this->comReq9->Name = L"comReq9";
            this->comReq9->ReadOnly = true;
            this->comReq9->Width = 200;
            // 
            // buttonReq9
            // 
            this->buttonReq9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonReq9->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonReq9->FlatAppearance->BorderSize = 0;
            this->buttonReq9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonReq9->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonReq9->Location = System::Drawing::Point(4, 9);
            this->buttonReq9->Name = L"buttonReq9";
            this->buttonReq9->Size = System::Drawing::Size(293, 135);
            this->buttonReq9->TabIndex = 37;
            this->buttonReq9->Text = L"Покупці які здійснили покупку та покупці, які не здійснили покупку.";
            this->buttonReq9->UseVisualStyleBackColor = false;
            this->buttonReq9->Click += gcnew System::EventHandler(this, &Seller::buttonReq9_Click);
            // 
            // groupBox13
            // 
            this->groupBox13->Controls->Add(this->dgvReq8);
            this->groupBox13->Controls->Add(this->buttonReq8);
            this->groupBox13->Location = System::Drawing::Point(836, 581);
            this->groupBox13->Name = L"groupBox13";
            this->groupBox13->Size = System::Drawing::Size(812, 150);
            this->groupBox13->TabIndex = 56;
            this->groupBox13->TabStop = false;
            // 
            // dgvReq8
            // 
            this->dgvReq8->AllowUserToAddRows = false;
            this->dgvReq8->AllowUserToDeleteRows = false;
            this->dgvReq8->AllowUserToResizeColumns = false;
            this->dgvReq8->AllowUserToResizeRows = false;
            this->dgvReq8->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvReq8->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvReq8->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->loginReq8, this->numberReq8 });
            this->dgvReq8->Location = System::Drawing::Point(314, 10);
            this->dgvReq8->Name = L"dgvReq8";
            this->dgvReq8->Size = System::Drawing::Size(494, 135);
            this->dgvReq8->TabIndex = 62;
            this->dgvReq8->Visible = false;
            // 
            // loginReq8
            // 
            this->loginReq8->DataPropertyName = L"loginReq8";
            this->loginReq8->HeaderText = L"Логін покупця";
            this->loginReq8->Name = L"loginReq8";
            this->loginReq8->ReadOnly = true;
            this->loginReq8->Width = 250;
            // 
            // numberReq8
            // 
            this->numberReq8->DataPropertyName = L"numberReq8";
            this->numberReq8->HeaderText = L"Номер телефону";
            this->numberReq8->Name = L"numberReq8";
            this->numberReq8->ReadOnly = true;
            this->numberReq8->Width = 200;
            // 
            // buttonReq8
            // 
            this->buttonReq8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonReq8->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonReq8->FlatAppearance->BorderSize = 0;
            this->buttonReq8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonReq8->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonReq8->Location = System::Drawing::Point(3, 9);
            this->buttonReq8->Name = L"buttonReq8";
            this->buttonReq8->Size = System::Drawing::Size(293, 135);
            this->buttonReq8->TabIndex = 34;
            this->buttonReq8->Text = L"Покупці які не\r\nвідвідували жодну \r\nкнигарню на\r\nцьому тижні.";
            this->buttonReq8->UseVisualStyleBackColor = false;
            this->buttonReq8->Click += gcnew System::EventHandler(this, &Seller::buttonReq8_Click);
            // 
            // groupBox11
            // 
            this->groupBox11->Controls->Add(this->textReq6);
            this->groupBox11->Controls->Add(this->buttonReq6);
            this->groupBox11->Location = System::Drawing::Point(11, 819);
            this->groupBox11->Name = L"groupBox11";
            this->groupBox11->Size = System::Drawing::Size(812, 150);
            this->groupBox11->TabIndex = 54;
            this->groupBox11->TabStop = false;
            // 
            // textReq6
            // 
            this->textReq6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textReq6->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textReq6->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textReq6->Location = System::Drawing::Point(315, 10);
            this->textReq6->Multiline = true;
            this->textReq6->Name = L"textReq6";
            this->textReq6->Size = System::Drawing::Size(493, 134);
            this->textReq6->TabIndex = 62;
            this->textReq6->Visible = false;
            // 
            // buttonReq6
            // 
            this->buttonReq6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonReq6->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonReq6->FlatAppearance->BorderSize = 0;
            this->buttonReq6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonReq6->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonReq6->Location = System::Drawing::Point(3, 9);
            this->buttonReq6->Name = L"buttonReq6";
            this->buttonReq6->Size = System::Drawing::Size(293, 135);
            this->buttonReq6->TabIndex = 35;
            this->buttonReq6->Text = L"Покупець у якого найбільше купівель.";
            this->buttonReq6->UseVisualStyleBackColor = false;
            this->buttonReq6->Click += gcnew System::EventHandler(this, &Seller::buttonReq6_Click);
            // 
            // groupBox12
            // 
            this->groupBox12->Controls->Add(this->dgvReq7);
            this->groupBox12->Controls->Add(this->buttonReq7);
            this->groupBox12->Location = System::Drawing::Point(836, 339);
            this->groupBox12->Name = L"groupBox12";
            this->groupBox12->Size = System::Drawing::Size(812, 150);
            this->groupBox12->TabIndex = 55;
            this->groupBox12->TabStop = false;
            // 
            // dgvReq7
            // 
            this->dgvReq7->AllowUserToAddRows = false;
            this->dgvReq7->AllowUserToDeleteRows = false;
            this->dgvReq7->AllowUserToResizeColumns = false;
            this->dgvReq7->AllowUserToResizeRows = false;
            this->dgvReq7->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvReq7->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvReq7->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
                this->nameReq7, this->loginReq7,
                    this->visitReq7
            });
            this->dgvReq7->Location = System::Drawing::Point(316, 10);
            this->dgvReq7->Name = L"dgvReq7";
            this->dgvReq7->Size = System::Drawing::Size(493, 135);
            this->dgvReq7->TabIndex = 61;
            this->dgvReq7->Visible = false;
            // 
            // nameReq7
            // 
            this->nameReq7->DataPropertyName = L"nameReq7";
            this->nameReq7->HeaderText = L"Назва книгарні";
            this->nameReq7->Name = L"nameReq7";
            this->nameReq7->ReadOnly = true;
            this->nameReq7->Width = 150;
            // 
            // loginReq7
            // 
            this->loginReq7->DataPropertyName = L"loginReq7";
            this->loginReq7->HeaderText = L"Логін покупця";
            this->loginReq7->Name = L"loginReq7";
            this->loginReq7->ReadOnly = true;
            this->loginReq7->Width = 150;
            // 
            // visitReq7
            // 
            this->visitReq7->DataPropertyName = L"visitReq7";
            this->visitReq7->HeaderText = L"Відвідувань";
            this->visitReq7->Name = L"visitReq7";
            this->visitReq7->ReadOnly = true;
            this->visitReq7->Width = 150;
            // 
            // buttonReq7
            // 
            this->buttonReq7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonReq7->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonReq7->FlatAppearance->BorderSize = 0;
            this->buttonReq7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonReq7->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonReq7->Location = System::Drawing::Point(5, 9);
            this->buttonReq7->Name = L"buttonReq7";
            this->buttonReq7->Size = System::Drawing::Size(293, 135);
            this->buttonReq7->TabIndex = 36;
            this->buttonReq7->Text = L"Кількість відвідувань \r\nкожного покупця у \r\nкожній книгарні.";
            this->buttonReq7->UseVisualStyleBackColor = false;
            this->buttonReq7->Click += gcnew System::EventHandler(this, &Seller::buttonReq7_Click);
            // 
            // groupBox8
            // 
            this->groupBox8->Controls->Add(this->dgvReq3);
            this->groupBox8->Controls->Add(this->label107);
            this->groupBox8->Controls->Add(this->buttonReq3);
            this->groupBox8->Controls->Add(this->date1Req3);
            this->groupBox8->Controls->Add(this->label106);
            this->groupBox8->Controls->Add(this->date2Req3);
            this->groupBox8->Location = System::Drawing::Point(836, 20);
            this->groupBox8->Name = L"groupBox8";
            this->groupBox8->Size = System::Drawing::Size(812, 231);
            this->groupBox8->TabIndex = 51;
            this->groupBox8->TabStop = false;
            // 
            // dgvReq3
            // 
            this->dgvReq3->AllowUserToAddRows = false;
            this->dgvReq3->AllowUserToDeleteRows = false;
            this->dgvReq3->AllowUserToResizeColumns = false;
            this->dgvReq3->AllowUserToResizeRows = false;
            this->dgvReq3->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvReq3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvReq3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
                this->IDReq3, this->loginReq3,
                    this->nameReq3, this->dateReq3, this->timeReq3
            });
            this->dgvReq3->Location = System::Drawing::Point(315, 9);
            this->dgvReq3->Name = L"dgvReq3";
            this->dgvReq3->Size = System::Drawing::Size(494, 216);
            this->dgvReq3->TabIndex = 60;
            this->dgvReq3->Visible = false;
            // 
            // IDReq3
            // 
            this->IDReq3->DataPropertyName = L"IDReq3";
            this->IDReq3->HeaderText = L"ID";
            this->IDReq3->Name = L"IDReq3";
            this->IDReq3->ReadOnly = true;
            this->IDReq3->Width = 30;
            // 
            // loginReq3
            // 
            this->loginReq3->DataPropertyName = L"loginReq3";
            this->loginReq3->HeaderText = L"Логін покупця";
            this->loginReq3->Name = L"loginReq3";
            this->loginReq3->ReadOnly = true;
            this->loginReq3->Width = 150;
            // 
            // nameReq3
            // 
            this->nameReq3->DataPropertyName = L"nameReq3";
            this->nameReq3->HeaderText = L"Книга";
            this->nameReq3->Name = L"nameReq3";
            this->nameReq3->ReadOnly = true;
            this->nameReq3->Width = 140;
            // 
            // dateReq3
            // 
            this->dateReq3->DataPropertyName = L"dateReq3";
            this->dateReq3->HeaderText = L"Дата";
            this->dateReq3->Name = L"dateReq3";
            this->dateReq3->ReadOnly = true;
            this->dateReq3->Width = 80;
            // 
            // timeReq3
            // 
            this->timeReq3->DataPropertyName = L"timeReq3";
            this->timeReq3->HeaderText = L"Час";
            this->timeReq3->Name = L"timeReq3";
            this->timeReq3->ReadOnly = true;
            this->timeReq3->Width = 50;
            // 
            // label107
            // 
            this->label107->AutoSize = true;
            this->label107->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label107->Location = System::Drawing::Point(16, 196);
            this->label107->Name = L"label107";
            this->label107->Size = System::Drawing::Size(52, 29);
            this->label107->TabIndex = 47;
            this->label107->Text = L"До:";
            // 
            // buttonReq3
            // 
            this->buttonReq3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonReq3->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonReq3->FlatAppearance->BorderSize = 0;
            this->buttonReq3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonReq3->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonReq3->Location = System::Drawing::Point(4, 9);
            this->buttonReq3->Name = L"buttonReq3";
            this->buttonReq3->Size = System::Drawing::Size(295, 135);
            this->buttonReq3->TabIndex = 32;
            this->buttonReq3->Text = L"Список покупців, \r\nякі здійснили покупки протягом заданого періоду.";
            this->buttonReq3->UseVisualStyleBackColor = false;
            this->buttonReq3->Click += gcnew System::EventHandler(this, &Seller::buttonReq3_Click);
            // 
            // date1Req3
            // 
            this->date1Req3->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->date1Req3->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->date1Req3->Location = System::Drawing::Point(81, 149);
            this->date1Req3->Name = L"date1Req3";
            this->date1Req3->Size = System::Drawing::Size(219, 35);
            this->date1Req3->TabIndex = 44;
            this->date1Req3->Value = System::DateTime(2024, 6, 1, 0, 0, 0, 0);
            // 
            // label106
            // 
            this->label106->AutoSize = true;
            this->label106->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label106->Location = System::Drawing::Point(16, 157);
            this->label106->Name = L"label106";
            this->label106->Size = System::Drawing::Size(59, 29);
            this->label106->TabIndex = 46;
            this->label106->Text = L"Від:";
            // 
            // date2Req3
            // 
            this->date2Req3->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->date2Req3->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->date2Req3->Location = System::Drawing::Point(81, 190);
            this->date2Req3->Name = L"date2Req3";
            this->date2Req3->Size = System::Drawing::Size(219, 35);
            this->date2Req3->TabIndex = 45;
            this->date2Req3->Value = System::DateTime(2024, 6, 1, 0, 0, 0, 0);
            // 
            // groupBox10
            // 
            this->groupBox10->Controls->Add(this->dgvReq5);
            this->groupBox10->Controls->Add(this->buttonReq5);
            this->groupBox10->Location = System::Drawing::Point(10, 581);
            this->groupBox10->Name = L"groupBox10";
            this->groupBox10->Size = System::Drawing::Size(812, 150);
            this->groupBox10->TabIndex = 53;
            this->groupBox10->TabStop = false;
            // 
            // dgvReq5
            // 
            this->dgvReq5->AllowUserToAddRows = false;
            this->dgvReq5->AllowUserToDeleteRows = false;
            this->dgvReq5->AllowUserToResizeColumns = false;
            this->dgvReq5->AllowUserToResizeRows = false;
            this->dgvReq5->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvReq5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvReq5->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->loginReq5, this->countReq5 });
            this->dgvReq5->Location = System::Drawing::Point(315, 9);
            this->dgvReq5->Name = L"dgvReq5";
            this->dgvReq5->Size = System::Drawing::Size(494, 135);
            this->dgvReq5->TabIndex = 61;
            this->dgvReq5->Visible = false;
            // 
            // loginReq5
            // 
            this->loginReq5->DataPropertyName = L"loginReq5";
            this->loginReq5->HeaderText = L"Логін покупця";
            this->loginReq5->Name = L"loginReq5";
            this->loginReq5->ReadOnly = true;
            this->loginReq5->Width = 300;
            // 
            // countReq5
            // 
            this->countReq5->DataPropertyName = L"countReq5";
            this->countReq5->HeaderText = L"Кількість купівель";
            this->countReq5->Name = L"countReq5";
            this->countReq5->ReadOnly = true;
            this->countReq5->Width = 150;
            // 
            // buttonReq5
            // 
            this->buttonReq5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonReq5->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonReq5->FlatAppearance->BorderSize = 0;
            this->buttonReq5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonReq5->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonReq5->Location = System::Drawing::Point(4, 9);
            this->buttonReq5->Name = L"buttonReq5";
            this->buttonReq5->Size = System::Drawing::Size(295, 135);
            this->buttonReq5->TabIndex = 30;
            this->buttonReq5->Text = L"Підрахунок кількості покупок, здійснених кожним покупцем.";
            this->buttonReq5->UseVisualStyleBackColor = false;
            this->buttonReq5->Click += gcnew System::EventHandler(this, &Seller::buttonReq5_Click);
            // 
            // groupBox9
            // 
            this->groupBox9->Controls->Add(this->textReq4);
            this->groupBox9->Controls->Add(this->buttonReq4);
            this->groupBox9->Location = System::Drawing::Point(10, 339);
            this->groupBox9->Name = L"groupBox9";
            this->groupBox9->Size = System::Drawing::Size(812, 150);
            this->groupBox9->TabIndex = 52;
            this->groupBox9->TabStop = false;
            // 
            // textReq4
            // 
            this->textReq4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textReq4->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textReq4->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textReq4->Location = System::Drawing::Point(316, 9);
            this->textReq4->Multiline = true;
            this->textReq4->Name = L"textReq4";
            this->textReq4->Size = System::Drawing::Size(493, 135);
            this->textReq4->TabIndex = 61;
            this->textReq4->Visible = false;
            // 
            // buttonReq4
            // 
            this->buttonReq4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonReq4->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonReq4->FlatAppearance->BorderSize = 0;
            this->buttonReq4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonReq4->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonReq4->Location = System::Drawing::Point(4, 9);
            this->buttonReq4->Name = L"buttonReq4";
            this->buttonReq4->Size = System::Drawing::Size(295, 135);
            this->buttonReq4->TabIndex = 33;
            this->buttonReq4->Text = L"Кількість покупців,\r\nякі здійснили покупки протягом останнього тижня.";
            this->buttonReq4->UseVisualStyleBackColor = false;
            this->buttonReq4->Click += gcnew System::EventHandler(this, &Seller::buttonReq4_Click);
            // 
            // groupBox6
            // 
            this->groupBox6->Controls->Add(this->dgvReq1);
            this->groupBox6->Controls->Add(this->buttonReq1);
            this->groupBox6->Controls->Add(this->textReq1);
            this->groupBox6->Location = System::Drawing::Point(11, 20);
            this->groupBox6->Name = L"groupBox6";
            this->groupBox6->Size = System::Drawing::Size(812, 231);
            this->groupBox6->TabIndex = 49;
            this->groupBox6->TabStop = false;
            // 
            // dgvReq1
            // 
            this->dgvReq1->AllowUserToAddRows = false;
            this->dgvReq1->AllowUserToDeleteRows = false;
            this->dgvReq1->AllowUserToResizeColumns = false;
            this->dgvReq1->AllowUserToResizeRows = false;
            this->dgvReq1->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvReq1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvReq1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
                this->IDReq1, this->loginReq1,
                    this->nameReq1, this->dateReq1, this->timeReq1
            });
            this->dgvReq1->Location = System::Drawing::Point(314, 9);
            this->dgvReq1->Name = L"dgvReq1";
            this->dgvReq1->Size = System::Drawing::Size(494, 214);
            this->dgvReq1->TabIndex = 59;
            this->dgvReq1->Visible = false;
            // 
            // IDReq1
            // 
            this->IDReq1->DataPropertyName = L"IDReq1";
            this->IDReq1->HeaderText = L"ID";
            this->IDReq1->Name = L"IDReq1";
            this->IDReq1->ReadOnly = true;
            this->IDReq1->Width = 30;
            // 
            // loginReq1
            // 
            this->loginReq1->DataPropertyName = L"loginReq1";
            this->loginReq1->HeaderText = L"Логін покупця";
            this->loginReq1->Name = L"loginReq1";
            this->loginReq1->ReadOnly = true;
            this->loginReq1->Width = 150;
            // 
            // nameReq1
            // 
            this->nameReq1->DataPropertyName = L"nameReq1";
            this->nameReq1->HeaderText = L"Книга";
            this->nameReq1->Name = L"nameReq1";
            this->nameReq1->ReadOnly = true;
            this->nameReq1->Width = 140;
            // 
            // dateReq1
            // 
            this->dateReq1->DataPropertyName = L"dateReq1";
            this->dateReq1->HeaderText = L"Дата";
            this->dateReq1->Name = L"dateReq1";
            this->dateReq1->ReadOnly = true;
            this->dateReq1->Width = 80;
            // 
            // timeReq1
            // 
            this->timeReq1->DataPropertyName = L"timeReq1";
            this->timeReq1->HeaderText = L"Час";
            this->timeReq1->Name = L"timeReq1";
            this->timeReq1->ReadOnly = true;
            this->timeReq1->Width = 50;
            // 
            // buttonReq1
            // 
            this->buttonReq1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonReq1->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonReq1->FlatAppearance->BorderSize = 0;
            this->buttonReq1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonReq1->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonReq1->Location = System::Drawing::Point(3, 9);
            this->buttonReq1->Name = L"buttonReq1";
            this->buttonReq1->Size = System::Drawing::Size(305, 137);
            this->buttonReq1->TabIndex = 29;
            this->buttonReq1->Text = L"Всі покупки книги \r\nз заданою назвою, \r\nвідсортовані за датою\r\n та часом покупки."
                L"\r\n";
            this->buttonReq1->UseVisualStyleBackColor = false;
            this->buttonReq1->Click += gcnew System::EventHandler(this, &Seller::buttonReq1_Click);
            // 
            // textReq1
            // 
            this->textReq1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textReq1->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textReq1->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textReq1->Location = System::Drawing::Point(3, 169);
            this->textReq1->Name = L"textReq1";
            this->textReq1->Size = System::Drawing::Size(305, 35);
            this->textReq1->TabIndex = 38;
            // 
            // groupBoxDelBuy
            // 
            this->groupBoxDelBuy->Controls->Add(this->groupBoxDelPur);
            this->groupBoxDelBuy->Controls->Add(this->dgvDelBuy);
            this->groupBoxDelBuy->Controls->Add(this->buttonDelBuy);
            this->groupBoxDelBuy->Controls->Add(this->label104);
            this->groupBoxDelBuy->Controls->Add(this->textSearchDel);
            this->groupBoxDelBuy->Controls->Add(this->buttonSearchDel);
            this->groupBoxDelBuy->Enabled = false;
            this->groupBoxDelBuy->Location = System::Drawing::Point(0, 88);
            this->groupBoxDelBuy->Name = L"groupBoxDelBuy";
            this->groupBoxDelBuy->Size = System::Drawing::Size(1659, 941);
            this->groupBoxDelBuy->TabIndex = 40;
            this->groupBoxDelBuy->TabStop = false;
            this->groupBoxDelBuy->Visible = false;
            // 
            // groupBoxDelPur
            // 
            this->groupBoxDelPur->Controls->Add(this->groupBoxDelB);
            this->groupBoxDelPur->Controls->Add(this->dgvDelPur);
            this->groupBoxDelPur->Controls->Add(this->buttonDelPur);
            this->groupBoxDelPur->Controls->Add(this->label99);
            this->groupBoxDelPur->Controls->Add(this->textSearchDel2);
            this->groupBoxDelPur->Controls->Add(this->buttonSearchDel2);
            this->groupBoxDelPur->Enabled = false;
            this->groupBoxDelPur->Location = System::Drawing::Point(0, 0);
            this->groupBoxDelPur->Name = L"groupBoxDelPur";
            this->groupBoxDelPur->Size = System::Drawing::Size(1659, 941);
            this->groupBoxDelPur->TabIndex = 41;
            this->groupBoxDelPur->TabStop = false;
            this->groupBoxDelPur->Visible = false;
            // 
            // groupBoxDelB
            // 
            this->groupBoxDelB->Controls->Add(this->dgvDelB);
            this->groupBoxDelB->Controls->Add(this->buttonDelB);
            this->groupBoxDelB->Controls->Add(this->label102);
            this->groupBoxDelB->Controls->Add(this->textSearchDel5);
            this->groupBoxDelB->Controls->Add(this->buttonSearchDel5);
            this->groupBoxDelB->Enabled = false;
            this->groupBoxDelB->Location = System::Drawing::Point(0, 0);
            this->groupBoxDelB->Name = L"groupBoxDelB";
            this->groupBoxDelB->Size = System::Drawing::Size(1659, 941);
            this->groupBoxDelB->TabIndex = 44;
            this->groupBoxDelB->TabStop = false;
            this->groupBoxDelB->Visible = false;
            // 
            // dgvDelB
            // 
            this->dgvDelB->AllowUserToAddRows = false;
            this->dgvDelB->AllowUserToDeleteRows = false;
            this->dgvDelB->AllowUserToResizeColumns = false;
            this->dgvDelB->AllowUserToResizeRows = false;
            this->dgvDelB->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvDelB->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvDelB->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
                this->isbnDelB, this->nameDelB,
                    this->authorDelB, this->costDelB, this->genreDelB, this->publishing_houseDelB
            });
            this->dgvDelB->Location = System::Drawing::Point(24, 60);
            this->dgvDelB->Name = L"dgvDelB";
            this->dgvDelB->Size = System::Drawing::Size(1243, 857);
            this->dgvDelB->TabIndex = 37;
            // 
            // isbnDelB
            // 
            this->isbnDelB->DataPropertyName = L"isbnDelB";
            this->isbnDelB->HeaderText = L"ISBN";
            this->isbnDelB->Name = L"isbnDelB";
            this->isbnDelB->ReadOnly = true;
            // 
            // nameDelB
            // 
            this->nameDelB->DataPropertyName = L"nameDelB";
            this->nameDelB->HeaderText = L"Назва книги";
            this->nameDelB->Name = L"nameDelB";
            this->nameDelB->ReadOnly = true;
            this->nameDelB->Width = 400;
            // 
            // authorDelB
            // 
            this->authorDelB->DataPropertyName = L"authorDelB";
            this->authorDelB->HeaderText = L"Автор";
            this->authorDelB->Name = L"authorDelB";
            this->authorDelB->ReadOnly = true;
            this->authorDelB->Width = 300;
            // 
            // costDelB
            // 
            this->costDelB->DataPropertyName = L"costDelB";
            this->costDelB->HeaderText = L"Ціна";
            this->costDelB->Name = L"costDelB";
            this->costDelB->ReadOnly = true;
            // 
            // genreDelB
            // 
            this->genreDelB->DataPropertyName = L"genreDelB";
            this->genreDelB->HeaderText = L"Жанр";
            this->genreDelB->Name = L"genreDelB";
            this->genreDelB->ReadOnly = true;
            // 
            // publishing_houseDelB
            // 
            this->publishing_houseDelB->DataPropertyName = L"publishing_houseDelB";
            this->publishing_houseDelB->HeaderText = L"Видавництво";
            this->publishing_houseDelB->Name = L"publishing_houseDelB";
            this->publishing_houseDelB->ReadOnly = true;
            this->publishing_houseDelB->Width = 200;
            // 
            // buttonDelB
            // 
            this->buttonDelB->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonDelB->FlatAppearance->BorderSize = 0;
            this->buttonDelB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonDelB->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonDelB->Location = System::Drawing::Point(1422, 343);
            this->buttonDelB->Name = L"buttonDelB";
            this->buttonDelB->Size = System::Drawing::Size(120, 35);
            this->buttonDelB->TabIndex = 11;
            this->buttonDelB->Text = L"Видалити";
            this->buttonDelB->UseVisualStyleBackColor = false;
            this->buttonDelB->Click += gcnew System::EventHandler(this, &Seller::buttonDelB_Click);
            // 
            // label102
            // 
            this->label102->AutoSize = true;
            this->label102->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label102->Location = System::Drawing::Point(19, 22);
            this->label102->Name = L"label102";
            this->label102->Size = System::Drawing::Size(228, 29);
            this->label102->TabIndex = 6;
            this->label102->Text = L"Пошук за назвою:";
            // 
            // textSearchDel5
            // 
            this->textSearchDel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearchDel5->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearchDel5->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearchDel5->Location = System::Drawing::Point(261, 19);
            this->textSearchDel5->Name = L"textSearchDel5";
            this->textSearchDel5->Size = System::Drawing::Size(332, 35);
            this->textSearchDel5->TabIndex = 5;
            // 
            // buttonSearchDel5
            // 
            this->buttonSearchDel5->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearchDel5->FlatAppearance->BorderSize = 0;
            this->buttonSearchDel5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearchDel5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearchDel5->Location = System::Drawing::Point(602, 19);
            this->buttonSearchDel5->Name = L"buttonSearchDel5";
            this->buttonSearchDel5->Size = System::Drawing::Size(75, 35);
            this->buttonSearchDel5->TabIndex = 4;
            this->buttonSearchDel5->Text = L"→";
            this->buttonSearchDel5->UseVisualStyleBackColor = false;
            this->buttonSearchDel5->Click += gcnew System::EventHandler(this, &Seller::buttonSearchDel5_Click);
            // 
            // dgvDelPur
            // 
            this->dgvDelPur->AllowUserToAddRows = false;
            this->dgvDelPur->AllowUserToDeleteRows = false;
            this->dgvDelPur->AllowUserToResizeColumns = false;
            this->dgvDelPur->AllowUserToResizeRows = false;
            this->dgvDelPur->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvDelPur->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvDelPur->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
                this->idDelPur, this->loginDelPur,
                    this->loginEmpDelPur, this->bookDelPur, this->costDelPur, this->quantityDelPur, this->dateDelPur, this->timeDelPur
            });
            this->dgvDelPur->Location = System::Drawing::Point(24, 60);
            this->dgvDelPur->Name = L"dgvDelPur";
            this->dgvDelPur->Size = System::Drawing::Size(1243, 857);
            this->dgvDelPur->TabIndex = 38;
            // 
            // idDelPur
            // 
            this->idDelPur->DataPropertyName = L"idDelPur";
            this->idDelPur->HeaderText = L"ID";
            this->idDelPur->Name = L"idDelPur";
            this->idDelPur->ReadOnly = true;
            // 
            // loginDelPur
            // 
            this->loginDelPur->DataPropertyName = L"loginDelPur";
            this->loginDelPur->HeaderText = L"Логін покупця";
            this->loginDelPur->Name = L"loginDelPur";
            this->loginDelPur->ReadOnly = true;
            this->loginDelPur->Width = 250;
            // 
            // loginEmpDelPur
            // 
            this->loginEmpDelPur->DataPropertyName = L"loginEmpDelPur";
            this->loginEmpDelPur->HeaderText = L"Логін продавця";
            this->loginEmpDelPur->Name = L"loginEmpDelPur";
            this->loginEmpDelPur->ReadOnly = true;
            this->loginEmpDelPur->Width = 250;
            // 
            // bookDelPur
            // 
            this->bookDelPur->DataPropertyName = L"bookDelPur";
            this->bookDelPur->HeaderText = L"Книга";
            this->bookDelPur->Name = L"bookDelPur";
            this->bookDelPur->ReadOnly = true;
            // 
            // costDelPur
            // 
            this->costDelPur->DataPropertyName = L"costDelPur";
            this->costDelPur->HeaderText = L"Ціна";
            this->costDelPur->Name = L"costDelPur";
            this->costDelPur->ReadOnly = true;
            // 
            // quantityDelPur
            // 
            this->quantityDelPur->DataPropertyName = L"quantityDelPur";
            this->quantityDelPur->HeaderText = L"Кількість";
            this->quantityDelPur->Name = L"quantityDelPur";
            this->quantityDelPur->ReadOnly = true;
            // 
            // dateDelPur
            // 
            this->dateDelPur->DataPropertyName = L"dateDelPur";
            this->dateDelPur->HeaderText = L"Дата";
            this->dateDelPur->Name = L"dateDelPur";
            this->dateDelPur->ReadOnly = true;
            this->dateDelPur->Width = 150;
            // 
            // timeDelPur
            // 
            this->timeDelPur->DataPropertyName = L"timeDelPur";
            this->timeDelPur->HeaderText = L"Час";
            this->timeDelPur->Name = L"timeDelPur";
            this->timeDelPur->ReadOnly = true;
            this->timeDelPur->Width = 150;
            // 
            // buttonDelPur
            // 
            this->buttonDelPur->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonDelPur->FlatAppearance->BorderSize = 0;
            this->buttonDelPur->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonDelPur->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonDelPur->Location = System::Drawing::Point(1422, 343);
            this->buttonDelPur->Name = L"buttonDelPur";
            this->buttonDelPur->Size = System::Drawing::Size(120, 35);
            this->buttonDelPur->TabIndex = 11;
            this->buttonDelPur->Text = L"Видалити";
            this->buttonDelPur->UseVisualStyleBackColor = false;
            this->buttonDelPur->Click += gcnew System::EventHandler(this, &Seller::buttonDelPur_Click);
            // 
            // label99
            // 
            this->label99->AutoSize = true;
            this->label99->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label99->Location = System::Drawing::Point(19, 22);
            this->label99->Name = L"label99";
            this->label99->Size = System::Drawing::Size(233, 29);
            this->label99->TabIndex = 6;
            this->label99->Text = L"Пошук за логіном:";
            // 
            // textSearchDel2
            // 
            this->textSearchDel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearchDel2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearchDel2->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearchDel2->Location = System::Drawing::Point(261, 19);
            this->textSearchDel2->Name = L"textSearchDel2";
            this->textSearchDel2->Size = System::Drawing::Size(332, 35);
            this->textSearchDel2->TabIndex = 5;
            // 
            // buttonSearchDel2
            // 
            this->buttonSearchDel2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearchDel2->FlatAppearance->BorderSize = 0;
            this->buttonSearchDel2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearchDel2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearchDel2->Location = System::Drawing::Point(602, 19);
            this->buttonSearchDel2->Name = L"buttonSearchDel2";
            this->buttonSearchDel2->Size = System::Drawing::Size(75, 35);
            this->buttonSearchDel2->TabIndex = 4;
            this->buttonSearchDel2->Text = L"→";
            this->buttonSearchDel2->UseVisualStyleBackColor = false;
            this->buttonSearchDel2->Click += gcnew System::EventHandler(this, &Seller::buttonSearchDel2_Click);
            // 
            // dgvDelBuy
            // 
            this->dgvDelBuy->AllowUserToAddRows = false;
            this->dgvDelBuy->AllowUserToDeleteRows = false;
            this->dgvDelBuy->AllowUserToResizeColumns = false;
            this->dgvDelBuy->AllowUserToResizeRows = false;
            this->dgvDelBuy->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvDelBuy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvDelBuy->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
                this->loginDelBuy,
                    this->passwordDelBuy, this->nameDelBuy, this->contact_numberDelBuy
            });
            this->dgvDelBuy->Location = System::Drawing::Point(24, 60);
            this->dgvDelBuy->Name = L"dgvDelBuy";
            this->dgvDelBuy->Size = System::Drawing::Size(1243, 857);
            this->dgvDelBuy->TabIndex = 36;
            // 
            // loginDelBuy
            // 
            this->loginDelBuy->DataPropertyName = L"loginDelBuy";
            this->loginDelBuy->HeaderText = L"Логін";
            this->loginDelBuy->Name = L"loginDelBuy";
            this->loginDelBuy->ReadOnly = true;
            this->loginDelBuy->Width = 300;
            // 
            // passwordDelBuy
            // 
            this->passwordDelBuy->DataPropertyName = L"passwordDelBuy";
            this->passwordDelBuy->HeaderText = L"Пароль";
            this->passwordDelBuy->Name = L"passwordDelBuy";
            this->passwordDelBuy->ReadOnly = true;
            this->passwordDelBuy->Width = 350;
            // 
            // nameDelBuy
            // 
            this->nameDelBuy->DataPropertyName = L"nameDelBuy";
            this->nameDelBuy->HeaderText = L"ПІБ";
            this->nameDelBuy->Name = L"nameDelBuy";
            this->nameDelBuy->ReadOnly = true;
            this->nameDelBuy->Width = 350;
            // 
            // contact_numberDelBuy
            // 
            this->contact_numberDelBuy->DataPropertyName = L"contact_numberDelBuy";
            this->contact_numberDelBuy->HeaderText = L"Номер";
            this->contact_numberDelBuy->Name = L"contact_numberDelBuy";
            this->contact_numberDelBuy->ReadOnly = true;
            this->contact_numberDelBuy->Width = 200;
            // 
            // buttonDelBuy
            // 
            this->buttonDelBuy->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonDelBuy->FlatAppearance->BorderSize = 0;
            this->buttonDelBuy->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonDelBuy->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonDelBuy->Location = System::Drawing::Point(1422, 343);
            this->buttonDelBuy->Name = L"buttonDelBuy";
            this->buttonDelBuy->Size = System::Drawing::Size(120, 35);
            this->buttonDelBuy->TabIndex = 11;
            this->buttonDelBuy->Text = L"Видалити";
            this->buttonDelBuy->UseVisualStyleBackColor = false;
            this->buttonDelBuy->Click += gcnew System::EventHandler(this, &Seller::buttonDelBuy_Click);
            // 
            // label104
            // 
            this->label104->AutoSize = true;
            this->label104->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label104->Location = System::Drawing::Point(19, 22);
            this->label104->Name = L"label104";
            this->label104->Size = System::Drawing::Size(233, 29);
            this->label104->TabIndex = 6;
            this->label104->Text = L"Пошук за логіном:";
            // 
            // textSearchDel
            // 
            this->textSearchDel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearchDel->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearchDel->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearchDel->Location = System::Drawing::Point(261, 19);
            this->textSearchDel->Name = L"textSearchDel";
            this->textSearchDel->Size = System::Drawing::Size(332, 35);
            this->textSearchDel->TabIndex = 5;
            // 
            // buttonSearchDel
            // 
            this->buttonSearchDel->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearchDel->FlatAppearance->BorderSize = 0;
            this->buttonSearchDel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearchDel->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearchDel->Location = System::Drawing::Point(602, 19);
            this->buttonSearchDel->Name = L"buttonSearchDel";
            this->buttonSearchDel->Size = System::Drawing::Size(75, 35);
            this->buttonSearchDel->TabIndex = 4;
            this->buttonSearchDel->Text = L"→";
            this->buttonSearchDel->UseVisualStyleBackColor = false;
            this->buttonSearchDel->Click += gcnew System::EventHandler(this, &Seller::buttonSearchDel_Click);
            // 
            // buttonBuyer4
            // 
            this->buttonBuyer4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonBuyer4->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonBuyer4->FlatAppearance->BorderSize = 0;
            this->buttonBuyer4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonBuyer4->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonBuyer4->Location = System::Drawing::Point(238, 20);
            this->buttonBuyer4->Name = L"buttonBuyer4";
            this->buttonBuyer4->Size = System::Drawing::Size(190, 43);
            this->buttonBuyer4->TabIndex = 27;
            this->buttonBuyer4->Text = L"Покупці";
            this->buttonBuyer4->UseVisualStyleBackColor = false;
            this->buttonBuyer4->Click += gcnew System::EventHandler(this, &Seller::buttonBuyer4_Click);
            // 
            // buttonPurchase4
            // 
            this->buttonPurchase4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonPurchase4->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonPurchase4->FlatAppearance->BorderSize = 0;
            this->buttonPurchase4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonPurchase4->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonPurchase4->Location = System::Drawing::Point(732, 20);
            this->buttonPurchase4->Name = L"buttonPurchase4";
            this->buttonPurchase4->Size = System::Drawing::Size(190, 43);
            this->buttonPurchase4->TabIndex = 28;
            this->buttonPurchase4->Text = L"Купівлі";
            this->buttonPurchase4->UseVisualStyleBackColor = false;
            this->buttonPurchase4->Click += gcnew System::EventHandler(this, &Seller::buttonPurchase4_Click);
            // 
            // buttonBook4
            // 
            this->buttonBook4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonBook4->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonBook4->FlatAppearance->BorderSize = 0;
            this->buttonBook4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonBook4->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonBook4->Location = System::Drawing::Point(1232, 20);
            this->buttonBook4->Name = L"buttonBook4";
            this->buttonBook4->Size = System::Drawing::Size(190, 43);
            this->buttonBook4->TabIndex = 30;
            this->buttonBook4->Text = L"Книги";
            this->buttonBook4->UseVisualStyleBackColor = false;
            this->buttonBook4->Click += gcnew System::EventHandler(this, &Seller::buttonBook4_Click);
            // 
            // groupBoxEdBuy
            // 
            this->groupBoxEdBuy->Controls->Add(this->groupBoxEdPur);
            this->groupBoxEdBuy->Controls->Add(this->label61);
            this->groupBoxEdBuy->Controls->Add(this->label60);
            this->groupBoxEdBuy->Controls->Add(this->label59);
            this->groupBoxEdBuy->Controls->Add(this->label58);
            this->groupBoxEdBuy->Controls->Add(this->buttonEdBuy);
            this->groupBoxEdBuy->Controls->Add(this->textEdBuyNum);
            this->groupBoxEdBuy->Controls->Add(this->textEdBuyName);
            this->groupBoxEdBuy->Controls->Add(this->textEdBuyPass);
            this->groupBoxEdBuy->Controls->Add(this->textEdBuyLog);
            this->groupBoxEdBuy->Controls->Add(this->label57);
            this->groupBoxEdBuy->Controls->Add(this->textSearchEd);
            this->groupBoxEdBuy->Controls->Add(this->buttonSearchEd);
            this->groupBoxEdBuy->Controls->Add(this->dgvEdBuy);
            this->groupBoxEdBuy->Location = System::Drawing::Point(0, 88);
            this->groupBoxEdBuy->Margin = System::Windows::Forms::Padding(2);
            this->groupBoxEdBuy->Name = L"groupBoxEdBuy";
            this->groupBoxEdBuy->Padding = System::Windows::Forms::Padding(2);
            this->groupBoxEdBuy->Size = System::Drawing::Size(1659, 941);
            this->groupBoxEdBuy->TabIndex = 26;
            this->groupBoxEdBuy->TabStop = false;
            // 
            // groupBoxEdPur
            // 
            this->groupBoxEdPur->Controls->Add(this->groupBoxEdB);
            this->groupBoxEdPur->Controls->Add(this->textEdPurId);
            this->groupBoxEdPur->Controls->Add(this->label69);
            this->groupBoxEdPur->Controls->Add(this->textEdPurCost);
            this->groupBoxEdPur->Controls->Add(this->label68);
            this->groupBoxEdPur->Controls->Add(this->comboEdPurLogEmp);
            this->groupBoxEdPur->Controls->Add(this->comboEdPurB);
            this->groupBoxEdPur->Controls->Add(this->comboEdPurLogBuy);
            this->groupBoxEdPur->Controls->Add(this->numericEdPurQua);
            this->groupBoxEdPur->Controls->Add(this->timeEdPurTime);
            this->groupBoxEdPur->Controls->Add(this->dateEdPurDate);
            this->groupBoxEdPur->Controls->Add(this->label67);
            this->groupBoxEdPur->Controls->Add(this->dgvEdPur);
            this->groupBoxEdPur->Controls->Add(this->label65);
            this->groupBoxEdPur->Controls->Add(this->label64);
            this->groupBoxEdPur->Controls->Add(this->label63);
            this->groupBoxEdPur->Controls->Add(this->label62);
            this->groupBoxEdPur->Controls->Add(this->buttonEdPur);
            this->groupBoxEdPur->Controls->Add(this->label66);
            this->groupBoxEdPur->Controls->Add(this->textSearchEd2);
            this->groupBoxEdPur->Controls->Add(this->buttonSearchEd2);
            this->groupBoxEdPur->Location = System::Drawing::Point(0, 0);
            this->groupBoxEdPur->Margin = System::Windows::Forms::Padding(2);
            this->groupBoxEdPur->Name = L"groupBoxEdPur";
            this->groupBoxEdPur->Padding = System::Windows::Forms::Padding(2);
            this->groupBoxEdPur->Size = System::Drawing::Size(1659, 941);
            this->groupBoxEdPur->TabIndex = 27;
            this->groupBoxEdPur->TabStop = false;
            // 
            // groupBoxEdB
            // 
            this->groupBoxEdB->Controls->Add(this->textEdBIsbn);
            this->groupBoxEdB->Controls->Add(this->dgvEdB);
            this->groupBoxEdB->Controls->Add(this->textEdBPH);
            this->groupBoxEdB->Controls->Add(this->label89);
            this->groupBoxEdB->Controls->Add(this->textEdBGenre);
            this->groupBoxEdB->Controls->Add(this->textEdBAuthor);
            this->groupBoxEdB->Controls->Add(this->textEdBCost);
            this->groupBoxEdB->Controls->Add(this->textBox5);
            this->groupBoxEdB->Controls->Add(this->label79);
            this->groupBoxEdB->Controls->Add(this->textEdBName);
            this->groupBoxEdB->Controls->Add(this->comboBox2);
            this->groupBoxEdB->Controls->Add(this->label81);
            this->groupBoxEdB->Controls->Add(this->label82);
            this->groupBoxEdB->Controls->Add(this->label83);
            this->groupBoxEdB->Controls->Add(this->buttonEdB);
            this->groupBoxEdB->Controls->Add(this->label88);
            this->groupBoxEdB->Controls->Add(this->textSearchEd5);
            this->groupBoxEdB->Controls->Add(this->buttonSearchEd5);
            this->groupBoxEdB->Location = System::Drawing::Point(0, 0);
            this->groupBoxEdB->Margin = System::Windows::Forms::Padding(2);
            this->groupBoxEdB->Name = L"groupBoxEdB";
            this->groupBoxEdB->Padding = System::Windows::Forms::Padding(2);
            this->groupBoxEdB->Size = System::Drawing::Size(1659, 941);
            this->groupBoxEdB->TabIndex = 36;
            this->groupBoxEdB->TabStop = false;
            // 
            // textEdBIsbn
            // 
            this->textEdBIsbn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdBIsbn->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdBIsbn->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdBIsbn->Location = System::Drawing::Point(1326, 503);
            this->textEdBIsbn->Name = L"textEdBIsbn";
            this->textEdBIsbn->Size = System::Drawing::Size(257, 35);
            this->textEdBIsbn->TabIndex = 37;
            this->textEdBIsbn->Visible = false;
            // 
            // dgvEdB
            // 
            this->dgvEdB->AllowUserToAddRows = false;
            this->dgvEdB->AllowUserToDeleteRows = false;
            this->dgvEdB->AllowUserToResizeColumns = false;
            this->dgvEdB->AllowUserToResizeRows = false;
            this->dgvEdB->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvEdB->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvEdB->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
                this->isbnEdB, this->nameEdB,
                    this->authorEdB, this->costEdB, this->genreEdB, this->publishing_houseEdB
            });
            this->dgvEdB->Location = System::Drawing::Point(24, 60);
            this->dgvEdB->Name = L"dgvEdB";
            this->dgvEdB->Size = System::Drawing::Size(1243, 857);
            this->dgvEdB->TabIndex = 36;
            this->dgvEdB->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Seller::dgvEdB_CellClick);
            // 
            // isbnEdB
            // 
            this->isbnEdB->DataPropertyName = L"isbnEdB";
            this->isbnEdB->HeaderText = L"ISBN";
            this->isbnEdB->Name = L"isbnEdB";
            this->isbnEdB->ReadOnly = true;
            // 
            // nameEdB
            // 
            this->nameEdB->DataPropertyName = L"nameEdB";
            this->nameEdB->HeaderText = L"Назва книги";
            this->nameEdB->Name = L"nameEdB";
            this->nameEdB->ReadOnly = true;
            this->nameEdB->Width = 400;
            // 
            // authorEdB
            // 
            this->authorEdB->DataPropertyName = L"authorEdB";
            this->authorEdB->HeaderText = L"Автор";
            this->authorEdB->Name = L"authorEdB";
            this->authorEdB->ReadOnly = true;
            this->authorEdB->Width = 300;
            // 
            // costEdB
            // 
            this->costEdB->DataPropertyName = L"costEdB";
            this->costEdB->HeaderText = L"Ціна";
            this->costEdB->Name = L"costEdB";
            this->costEdB->ReadOnly = true;
            // 
            // genreEdB
            // 
            this->genreEdB->DataPropertyName = L"genreEdB";
            this->genreEdB->HeaderText = L"Жанр";
            this->genreEdB->Name = L"genreEdB";
            this->genreEdB->ReadOnly = true;
            // 
            // publishing_houseEdB
            // 
            this->publishing_houseEdB->DataPropertyName = L"publishing_houseEdB";
            this->publishing_houseEdB->HeaderText = L"Видавництво";
            this->publishing_houseEdB->Name = L"publishing_houseEdB";
            this->publishing_houseEdB->ReadOnly = true;
            this->publishing_houseEdB->Width = 200;
            // 
            // textEdBPH
            // 
            this->textEdBPH->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdBPH->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdBPH->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdBPH->Location = System::Drawing::Point(1326, 385);
            this->textEdBPH->Name = L"textEdBPH";
            this->textEdBPH->Size = System::Drawing::Size(257, 35);
            this->textEdBPH->TabIndex = 35;
            // 
            // label89
            // 
            this->label89->AutoSize = true;
            this->label89->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label89->Location = System::Drawing::Point(1322, 352);
            this->label89->Name = L"label89";
            this->label89->Size = System::Drawing::Size(181, 29);
            this->label89->TabIndex = 34;
            this->label89->Text = L"Видавництво:";
            // 
            // textEdBGenre
            // 
            this->textEdBGenre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdBGenre->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdBGenre->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdBGenre->Location = System::Drawing::Point(1325, 315);
            this->textEdBGenre->Name = L"textEdBGenre";
            this->textEdBGenre->Size = System::Drawing::Size(257, 35);
            this->textEdBGenre->TabIndex = 33;
            this->textEdBGenre->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Seller::textEdBGenre_KeyPress);
            // 
            // textEdBAuthor
            // 
            this->textEdBAuthor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdBAuthor->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdBAuthor->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdBAuthor->Location = System::Drawing::Point(1326, 169);
            this->textEdBAuthor->Name = L"textEdBAuthor";
            this->textEdBAuthor->Size = System::Drawing::Size(257, 35);
            this->textEdBAuthor->TabIndex = 32;
            this->textEdBAuthor->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Seller::textEdBAuthor_KeyPress);
            // 
            // textEdBCost
            // 
            this->textEdBCost->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdBCost->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdBCost->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdBCost->Location = System::Drawing::Point(1325, 242);
            this->textEdBCost->Name = L"textEdBCost";
            this->textEdBCost->Size = System::Drawing::Size(257, 35);
            this->textEdBCost->TabIndex = 31;
            this->textEdBCost->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Seller::textEdBCost_KeyPress);
            // 
            // textBox5
            // 
            this->textBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textBox5->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textBox5->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textBox5->Location = System::Drawing::Point(1326, 169);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(257, 35);
            this->textBox5->TabIndex = 30;
            // 
            // label79
            // 
            this->label79->AutoSize = true;
            this->label79->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label79->Location = System::Drawing::Point(1321, 282);
            this->label79->Name = L"label79";
            this->label79->Size = System::Drawing::Size(84, 29);
            this->label79->TabIndex = 28;
            this->label79->Text = L"Жанр:";
            // 
            // textEdBName
            // 
            this->textEdBName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdBName->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdBName->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdBName->Location = System::Drawing::Point(1325, 93);
            this->textEdBName->Name = L"textEdBName";
            this->textEdBName->Size = System::Drawing::Size(257, 35);
            this->textEdBName->TabIndex = 27;
            // 
            // comboBox2
            // 
            this->comboBox2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->comboBox2->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->comboBox2->ForeColor = System::Drawing::SystemColors::InfoText;
            this->comboBox2->FormattingEnabled = true;
            this->comboBox2->Location = System::Drawing::Point(1325, 316);
            this->comboBox2->Name = L"comboBox2";
            this->comboBox2->Size = System::Drawing::Size(255, 35);
            this->comboBox2->Sorted = true;
            this->comboBox2->TabIndex = 25;
            // 
            // label81
            // 
            this->label81->AutoSize = true;
            this->label81->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label81->Location = System::Drawing::Point(1321, 132);
            this->label81->Name = L"label81";
            this->label81->Size = System::Drawing::Size(93, 29);
            this->label81->TabIndex = 15;
            this->label81->Text = L"Автор:";
            // 
            // label82
            // 
            this->label82->AutoSize = true;
            this->label82->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label82->Location = System::Drawing::Point(1321, 60);
            this->label82->Name = L"label82";
            this->label82->Size = System::Drawing::Size(164, 29);
            this->label82->TabIndex = 14;
            this->label82->Text = L"Назва книги:";
            // 
            // label83
            // 
            this->label83->AutoSize = true;
            this->label83->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label83->Location = System::Drawing::Point(1321, 209);
            this->label83->Name = L"label83";
            this->label83->Size = System::Drawing::Size(73, 29);
            this->label83->TabIndex = 13;
            this->label83->Text = L"Ціна:";
            // 
            // buttonEdB
            // 
            this->buttonEdB->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonEdB->FlatAppearance->BorderSize = 0;
            this->buttonEdB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonEdB->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonEdB->Location = System::Drawing::Point(1423, 435);
            this->buttonEdB->Name = L"buttonEdB";
            this->buttonEdB->Size = System::Drawing::Size(75, 35);
            this->buttonEdB->TabIndex = 12;
            this->buttonEdB->Text = L"→";
            this->buttonEdB->UseVisualStyleBackColor = false;
            this->buttonEdB->Click += gcnew System::EventHandler(this, &Seller::buttonEdB_Click);
            // 
            // label88
            // 
            this->label88->AutoSize = true;
            this->label88->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label88->Location = System::Drawing::Point(19, 22);
            this->label88->Name = L"label88";
            this->label88->Size = System::Drawing::Size(228, 29);
            this->label88->TabIndex = 7;
            this->label88->Text = L"Пошук за назвою:";
            // 
            // textSearchEd5
            // 
            this->textSearchEd5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearchEd5->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearchEd5->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearchEd5->Location = System::Drawing::Point(261, 19);
            this->textSearchEd5->Name = L"textSearchEd5";
            this->textSearchEd5->Size = System::Drawing::Size(332, 35);
            this->textSearchEd5->TabIndex = 6;
            // 
            // buttonSearchEd5
            // 
            this->buttonSearchEd5->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearchEd5->FlatAppearance->BorderSize = 0;
            this->buttonSearchEd5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearchEd5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearchEd5->Location = System::Drawing::Point(602, 19);
            this->buttonSearchEd5->Name = L"buttonSearchEd5";
            this->buttonSearchEd5->Size = System::Drawing::Size(75, 35);
            this->buttonSearchEd5->TabIndex = 5;
            this->buttonSearchEd5->Text = L"→";
            this->buttonSearchEd5->UseVisualStyleBackColor = false;
            this->buttonSearchEd5->Click += gcnew System::EventHandler(this, &Seller::buttonSearchEd5_Click);
            // 
            // textEdPurId
            // 
            this->textEdPurId->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdPurId->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdPurId->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdPurId->Location = System::Drawing::Point(1324, 642);
            this->textEdPurId->Name = L"textEdPurId";
            this->textEdPurId->ReadOnly = true;
            this->textEdPurId->Size = System::Drawing::Size(257, 35);
            this->textEdPurId->TabIndex = 29;
            this->textEdPurId->Visible = false;
            // 
            // label69
            // 
            this->label69->AutoSize = true;
            this->label69->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label69->Location = System::Drawing::Point(1322, 285);
            this->label69->Name = L"label69";
            this->label69->Size = System::Drawing::Size(73, 29);
            this->label69->TabIndex = 28;
            this->label69->Text = L"Ціна:";
            // 
            // textEdPurCost
            // 
            this->textEdPurCost->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdPurCost->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdPurCost->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdPurCost->Location = System::Drawing::Point(1325, 319);
            this->textEdPurCost->Name = L"textEdPurCost";
            this->textEdPurCost->ReadOnly = true;
            this->textEdPurCost->Size = System::Drawing::Size(257, 35);
            this->textEdPurCost->TabIndex = 27;
            // 
            // label68
            // 
            this->label68->AutoSize = true;
            this->label68->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label68->Location = System::Drawing::Point(1321, 503);
            this->label68->Name = L"label68";
            this->label68->Size = System::Drawing::Size(63, 29);
            this->label68->TabIndex = 26;
            this->label68->Text = L"Час:";
            // 
            // comboEdPurLogEmp
            // 
            this->comboEdPurLogEmp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->comboEdPurLogEmp->BackColor = System::Drawing::SystemColors::ControlDark;
            this->comboEdPurLogEmp->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->comboEdPurLogEmp->Location = System::Drawing::Point(1325, 170);
            this->comboEdPurLogEmp->Name = L"comboEdPurLogEmp";
            this->comboEdPurLogEmp->ReadOnly = true;
            this->comboEdPurLogEmp->Size = System::Drawing::Size(257, 35);
            this->comboEdPurLogEmp->TabIndex = 37;
            // 
            // comboEdPurB
            // 
            this->comboEdPurB->BackColor = System::Drawing::SystemColors::ControlDark;
            this->comboEdPurB->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->comboEdPurB->ForeColor = System::Drawing::SystemColors::InfoText;
            this->comboEdPurB->FormattingEnabled = true;
            this->comboEdPurB->Location = System::Drawing::Point(1326, 246);
            this->comboEdPurB->Name = L"comboEdPurB";
            this->comboEdPurB->Size = System::Drawing::Size(255, 35);
            this->comboEdPurB->Sorted = true;
            this->comboEdPurB->TabIndex = 25;
            // 
            // comboEdPurLogBuy
            // 
            this->comboEdPurLogBuy->BackColor = System::Drawing::SystemColors::ControlDark;
            this->comboEdPurLogBuy->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->comboEdPurLogBuy->ForeColor = System::Drawing::SystemColors::InfoText;
            this->comboEdPurLogBuy->FormattingEnabled = true;
            this->comboEdPurLogBuy->Location = System::Drawing::Point(1325, 93);
            this->comboEdPurLogBuy->Name = L"comboEdPurLogBuy";
            this->comboEdPurLogBuy->Size = System::Drawing::Size(256, 35);
            this->comboEdPurLogBuy->Sorted = true;
            this->comboEdPurLogBuy->TabIndex = 23;
            // 
            // numericEdPurQua
            // 
            this->numericEdPurQua->BackColor = System::Drawing::SystemColors::ControlDark;
            this->numericEdPurQua->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->numericEdPurQua->Location = System::Drawing::Point(1326, 391);
            this->numericEdPurQua->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->numericEdPurQua->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numericEdPurQua->Name = L"numericEdPurQua";
            this->numericEdPurQua->Size = System::Drawing::Size(255, 35);
            this->numericEdPurQua->TabIndex = 22;
            this->numericEdPurQua->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // timeEdPurTime
            // 
            this->timeEdPurTime->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->timeEdPurTime->Format = System::Windows::Forms::DateTimePickerFormat::Time;
            this->timeEdPurTime->Location = System::Drawing::Point(1326, 535);
            this->timeEdPurTime->Name = L"timeEdPurTime";
            this->timeEdPurTime->Size = System::Drawing::Size(255, 35);
            this->timeEdPurTime->TabIndex = 21;
            // 
            // dateEdPurDate
            // 
            this->dateEdPurDate->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->dateEdPurDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dateEdPurDate->Location = System::Drawing::Point(1325, 465);
            this->dateEdPurDate->Name = L"dateEdPurDate";
            this->dateEdPurDate->Size = System::Drawing::Size(256, 35);
            this->dateEdPurDate->TabIndex = 20;
            // 
            // label67
            // 
            this->label67->AutoSize = true;
            this->label67->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label67->Location = System::Drawing::Point(1321, 433);
            this->label67->Name = L"label67";
            this->label67->Size = System::Drawing::Size(74, 29);
            this->label67->TabIndex = 18;
            this->label67->Text = L"Дата:";
            // 
            // dgvEdPur
            // 
            this->dgvEdPur->AllowUserToAddRows = false;
            this->dgvEdPur->AllowUserToDeleteRows = false;
            this->dgvEdPur->AllowUserToResizeColumns = false;
            this->dgvEdPur->AllowUserToResizeRows = false;
            this->dgvEdPur->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvEdPur->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvEdPur->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
                this->idEdPur, this->loginEdPur,
                    this->loginEmpEdPur, this->bookEdPur, this->costEdPur, this->quantityEdPur, this->dateEdPur, this->timeEdPur
            });
            this->dgvEdPur->Location = System::Drawing::Point(24, 60);
            this->dgvEdPur->Name = L"dgvEdPur";
            this->dgvEdPur->Size = System::Drawing::Size(1243, 857);
            this->dgvEdPur->TabIndex = 17;
            this->dgvEdPur->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Seller::dgvEdPur_CellClick);
            // 
            // idEdPur
            // 
            this->idEdPur->DataPropertyName = L"idEdPur";
            this->idEdPur->HeaderText = L"ID";
            this->idEdPur->Name = L"idEdPur";
            this->idEdPur->ReadOnly = true;
            // 
            // loginEdPur
            // 
            this->loginEdPur->DataPropertyName = L"loginEdPur";
            this->loginEdPur->HeaderText = L"Логін покупця";
            this->loginEdPur->Name = L"loginEdPur";
            this->loginEdPur->ReadOnly = true;
            this->loginEdPur->Width = 250;
            // 
            // loginEmpEdPur
            // 
            this->loginEmpEdPur->DataPropertyName = L"loginEmpEdPur";
            this->loginEmpEdPur->HeaderText = L"Логін продавця";
            this->loginEmpEdPur->Name = L"loginEmpEdPur";
            this->loginEmpEdPur->ReadOnly = true;
            this->loginEmpEdPur->Width = 250;
            // 
            // bookEdPur
            // 
            this->bookEdPur->DataPropertyName = L"bookEdPur";
            this->bookEdPur->HeaderText = L"Книга";
            this->bookEdPur->Name = L"bookEdPur";
            this->bookEdPur->ReadOnly = true;
            // 
            // costEdPur
            // 
            this->costEdPur->DataPropertyName = L"costEdPur";
            this->costEdPur->HeaderText = L"Ціна";
            this->costEdPur->Name = L"costEdPur";
            this->costEdPur->ReadOnly = true;
            // 
            // quantityEdPur
            // 
            this->quantityEdPur->DataPropertyName = L"quantityEdPur";
            this->quantityEdPur->HeaderText = L"Кількість";
            this->quantityEdPur->Name = L"quantityEdPur";
            this->quantityEdPur->ReadOnly = true;
            // 
            // dateEdPur
            // 
            this->dateEdPur->DataPropertyName = L"dateEdPur";
            this->dateEdPur->HeaderText = L"Дата";
            this->dateEdPur->Name = L"dateEdPur";
            this->dateEdPur->ReadOnly = true;
            this->dateEdPur->Width = 150;
            // 
            // timeEdPur
            // 
            this->timeEdPur->DataPropertyName = L"timeEdPur";
            this->timeEdPur->HeaderText = L"Час";
            this->timeEdPur->Name = L"timeEdPur";
            this->timeEdPur->ReadOnly = true;
            this->timeEdPur->Width = 150;
            // 
            // label65
            // 
            this->label65->AutoSize = true;
            this->label65->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label65->Location = System::Drawing::Point(1321, 359);
            this->label65->Name = L"label65";
            this->label65->Size = System::Drawing::Size(130, 29);
            this->label65->TabIndex = 16;
            this->label65->Text = L"Кількість:";
            // 
            // label64
            // 
            this->label64->AutoSize = true;
            this->label64->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label64->Location = System::Drawing::Point(1321, 215);
            this->label64->Name = L"label64";
            this->label64->Size = System::Drawing::Size(88, 29);
            this->label64->TabIndex = 15;
            this->label64->Text = L"Книга:";
            // 
            // label63
            // 
            this->label63->AutoSize = true;
            this->label63->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label63->Location = System::Drawing::Point(1321, 138);
            this->label63->Name = L"label63";
            this->label63->Size = System::Drawing::Size(208, 29);
            this->label63->TabIndex = 14;
            this->label63->Text = L"Логін продавця:";
            // 
            // label62
            // 
            this->label62->AutoSize = true;
            this->label62->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label62->Location = System::Drawing::Point(1321, 61);
            this->label62->Name = L"label62";
            this->label62->Size = System::Drawing::Size(190, 29);
            this->label62->TabIndex = 13;
            this->label62->Text = L"Логін покупця:";
            // 
            // buttonEdPur
            // 
            this->buttonEdPur->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonEdPur->FlatAppearance->BorderSize = 0;
            this->buttonEdPur->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonEdPur->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonEdPur->Location = System::Drawing::Point(1423, 582);
            this->buttonEdPur->Name = L"buttonEdPur";
            this->buttonEdPur->Size = System::Drawing::Size(75, 35);
            this->buttonEdPur->TabIndex = 12;
            this->buttonEdPur->Text = L"→";
            this->buttonEdPur->UseVisualStyleBackColor = false;
            this->buttonEdPur->Click += gcnew System::EventHandler(this, &Seller::buttonEdPur_Click);
            // 
            // label66
            // 
            this->label66->AutoSize = true;
            this->label66->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label66->Location = System::Drawing::Point(19, 22);
            this->label66->Name = L"label66";
            this->label66->Size = System::Drawing::Size(233, 29);
            this->label66->TabIndex = 7;
            this->label66->Text = L"Пошук за логіном:";
            // 
            // textSearchEd2
            // 
            this->textSearchEd2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearchEd2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearchEd2->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearchEd2->Location = System::Drawing::Point(261, 19);
            this->textSearchEd2->Name = L"textSearchEd2";
            this->textSearchEd2->Size = System::Drawing::Size(332, 35);
            this->textSearchEd2->TabIndex = 6;
            // 
            // buttonSearchEd2
            // 
            this->buttonSearchEd2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearchEd2->FlatAppearance->BorderSize = 0;
            this->buttonSearchEd2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearchEd2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearchEd2->Location = System::Drawing::Point(602, 19);
            this->buttonSearchEd2->Name = L"buttonSearchEd2";
            this->buttonSearchEd2->Size = System::Drawing::Size(75, 35);
            this->buttonSearchEd2->TabIndex = 5;
            this->buttonSearchEd2->Text = L"→";
            this->buttonSearchEd2->UseVisualStyleBackColor = false;
            this->buttonSearchEd2->Click += gcnew System::EventHandler(this, &Seller::buttonSearchEd2_Click);
            // 
            // label61
            // 
            this->label61->AutoSize = true;
            this->label61->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label61->Location = System::Drawing::Point(1321, 283);
            this->label61->Name = L"label61";
            this->label61->Size = System::Drawing::Size(99, 29);
            this->label61->TabIndex = 16;
            this->label61->Text = L"Номер:";
            // 
            // label60
            // 
            this->label60->AutoSize = true;
            this->label60->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label60->Location = System::Drawing::Point(1321, 206);
            this->label60->Name = L"label60";
            this->label60->Size = System::Drawing::Size(61, 29);
            this->label60->TabIndex = 15;
            this->label60->Text = L"ПІБ:";
            // 
            // label59
            // 
            this->label59->AutoSize = true;
            this->label59->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label59->Location = System::Drawing::Point(1321, 135);
            this->label59->Name = L"label59";
            this->label59->Size = System::Drawing::Size(109, 29);
            this->label59->TabIndex = 14;
            this->label59->Text = L"Пароль:";
            // 
            // label58
            // 
            this->label58->AutoSize = true;
            this->label58->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label58->Location = System::Drawing::Point(1321, 64);
            this->label58->Name = L"label58";
            this->label58->Size = System::Drawing::Size(84, 29);
            this->label58->TabIndex = 13;
            this->label58->Text = L"Логін:";
            // 
            // buttonEdBuy
            // 
            this->buttonEdBuy->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonEdBuy->FlatAppearance->BorderSize = 0;
            this->buttonEdBuy->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonEdBuy->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonEdBuy->Location = System::Drawing::Point(1423, 366);
            this->buttonEdBuy->Name = L"buttonEdBuy";
            this->buttonEdBuy->Size = System::Drawing::Size(75, 35);
            this->buttonEdBuy->TabIndex = 12;
            this->buttonEdBuy->Text = L"→";
            this->buttonEdBuy->UseVisualStyleBackColor = false;
            this->buttonEdBuy->Click += gcnew System::EventHandler(this, &Seller::buttonEdBuy_Click);
            // 
            // textEdBuyNum
            // 
            this->textEdBuyNum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdBuyNum->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdBuyNum->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdBuyNum->Location = System::Drawing::Point(1325, 316);
            this->textEdBuyNum->Name = L"textEdBuyNum";
            this->textEdBuyNum->Size = System::Drawing::Size(256, 35);
            this->textEdBuyNum->TabIndex = 11;
            this->textEdBuyNum->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Seller::textEdBuyNum_KeyPress);
            // 
            // textEdBuyName
            // 
            this->textEdBuyName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdBuyName->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdBuyName->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdBuyName->Location = System::Drawing::Point(1325, 239);
            this->textEdBuyName->Name = L"textEdBuyName";
            this->textEdBuyName->Size = System::Drawing::Size(256, 35);
            this->textEdBuyName->TabIndex = 10;
            this->textEdBuyName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Seller::textEdBuyName_KeyPress);
            // 
            // textEdBuyPass
            // 
            this->textEdBuyPass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdBuyPass->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdBuyPass->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdBuyPass->Location = System::Drawing::Point(1326, 169);
            this->textEdBuyPass->Name = L"textEdBuyPass";
            this->textEdBuyPass->Size = System::Drawing::Size(256, 35);
            this->textEdBuyPass->TabIndex = 9;
            // 
            // textEdBuyLog
            // 
            this->textEdBuyLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textEdBuyLog->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textEdBuyLog->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textEdBuyLog->Location = System::Drawing::Point(1325, 93);
            this->textEdBuyLog->Name = L"textEdBuyLog";
            this->textEdBuyLog->ReadOnly = true;
            this->textEdBuyLog->Size = System::Drawing::Size(256, 35);
            this->textEdBuyLog->TabIndex = 8;
            // 
            // label57
            // 
            this->label57->AutoSize = true;
            this->label57->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label57->Location = System::Drawing::Point(19, 22);
            this->label57->Name = L"label57";
            this->label57->Size = System::Drawing::Size(233, 29);
            this->label57->TabIndex = 7;
            this->label57->Text = L"Пошук за логіном:";
            // 
            // textSearchEd
            // 
            this->textSearchEd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearchEd->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearchEd->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearchEd->Location = System::Drawing::Point(261, 19);
            this->textSearchEd->Name = L"textSearchEd";
            this->textSearchEd->Size = System::Drawing::Size(332, 35);
            this->textSearchEd->TabIndex = 6;
            // 
            // buttonSearchEd
            // 
            this->buttonSearchEd->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearchEd->FlatAppearance->BorderSize = 0;
            this->buttonSearchEd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearchEd->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearchEd->Location = System::Drawing::Point(602, 19);
            this->buttonSearchEd->Name = L"buttonSearchEd";
            this->buttonSearchEd->Size = System::Drawing::Size(75, 35);
            this->buttonSearchEd->TabIndex = 5;
            this->buttonSearchEd->Text = L"→";
            this->buttonSearchEd->UseVisualStyleBackColor = false;
            this->buttonSearchEd->Click += gcnew System::EventHandler(this, &Seller::buttonSearchEd_Click);
            // 
            // dgvEdBuy
            // 
            this->dgvEdBuy->AllowUserToAddRows = false;
            this->dgvEdBuy->AllowUserToDeleteRows = false;
            this->dgvEdBuy->AllowUserToResizeColumns = false;
            this->dgvEdBuy->AllowUserToResizeRows = false;
            this->dgvEdBuy->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvEdBuy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvEdBuy->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
                this->loginEdBuy,
                    this->passwordEdBuy, this->nameEdBuy, this->contact_numberEdBuy
            });
            this->dgvEdBuy->Location = System::Drawing::Point(24, 60);
            this->dgvEdBuy->Name = L"dgvEdBuy";
            this->dgvEdBuy->Size = System::Drawing::Size(1243, 857);
            this->dgvEdBuy->TabIndex = 2;
            this->dgvEdBuy->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Seller::dgvEdBuy_CellClick);
            // 
            // loginEdBuy
            // 
            this->loginEdBuy->DataPropertyName = L"loginEdBuy";
            this->loginEdBuy->HeaderText = L"Логін";
            this->loginEdBuy->Name = L"loginEdBuy";
            this->loginEdBuy->ReadOnly = true;
            this->loginEdBuy->Width = 300;
            // 
            // passwordEdBuy
            // 
            this->passwordEdBuy->DataPropertyName = L"passwordEdBuy";
            this->passwordEdBuy->HeaderText = L"Пароль";
            this->passwordEdBuy->Name = L"passwordEdBuy";
            this->passwordEdBuy->ReadOnly = true;
            this->passwordEdBuy->Width = 350;
            // 
            // nameEdBuy
            // 
            this->nameEdBuy->DataPropertyName = L"nameEdBuy";
            this->nameEdBuy->HeaderText = L"ПІБ";
            this->nameEdBuy->Name = L"nameEdBuy";
            this->nameEdBuy->ReadOnly = true;
            this->nameEdBuy->Width = 350;
            // 
            // contact_numberEdBuy
            // 
            this->contact_numberEdBuy->DataPropertyName = L"contact_numberEdBuy";
            this->contact_numberEdBuy->HeaderText = L"Номер";
            this->contact_numberEdBuy->Name = L"contact_numberEdBuy";
            this->contact_numberEdBuy->ReadOnly = true;
            this->contact_numberEdBuy->Width = 200;
            // 
            // buttonBuyer3
            // 
            this->buttonBuyer3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonBuyer3->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonBuyer3->FlatAppearance->BorderSize = 0;
            this->buttonBuyer3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonBuyer3->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonBuyer3->Location = System::Drawing::Point(238, 20);
            this->buttonBuyer3->Name = L"buttonBuyer3";
            this->buttonBuyer3->Size = System::Drawing::Size(190, 43);
            this->buttonBuyer3->TabIndex = 19;
            this->buttonBuyer3->Text = L"Покупці";
            this->buttonBuyer3->UseVisualStyleBackColor = false;
            this->buttonBuyer3->Click += gcnew System::EventHandler(this, &Seller::buttonBuyer3_Click);
            // 
            // buttonPurchase3
            // 
            this->buttonPurchase3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonPurchase3->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonPurchase3->FlatAppearance->BorderSize = 0;
            this->buttonPurchase3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonPurchase3->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonPurchase3->Location = System::Drawing::Point(732, 20);
            this->buttonPurchase3->Name = L"buttonPurchase3";
            this->buttonPurchase3->Size = System::Drawing::Size(190, 43);
            this->buttonPurchase3->TabIndex = 20;
            this->buttonPurchase3->Text = L"Купівлі";
            this->buttonPurchase3->UseVisualStyleBackColor = false;
            this->buttonPurchase3->Click += gcnew System::EventHandler(this, &Seller::buttonPurchase3_Click);
            // 
            // buttonBook3
            // 
            this->buttonBook3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonBook3->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonBook3->FlatAppearance->BorderSize = 0;
            this->buttonBook3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonBook3->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonBook3->Location = System::Drawing::Point(1232, 20);
            this->buttonBook3->Name = L"buttonBook3";
            this->buttonBook3->Size = System::Drawing::Size(190, 43);
            this->buttonBook3->TabIndex = 23;
            this->buttonBook3->Text = L"Книги";
            this->buttonBook3->UseVisualStyleBackColor = false;
            this->buttonBook3->Click += gcnew System::EventHandler(this, &Seller::buttonBook3_Click);
            // 
            // groupBoxAddBuy
            // 
            this->groupBoxAddBuy->Controls->Add(this->groupBoxAddPur);
            this->groupBoxAddBuy->Controls->Add(this->label21);
            this->groupBoxAddBuy->Controls->Add(this->label20);
            this->groupBoxAddBuy->Controls->Add(this->label19);
            this->groupBoxAddBuy->Controls->Add(this->label18);
            this->groupBoxAddBuy->Controls->Add(this->buttonAddBuy);
            this->groupBoxAddBuy->Controls->Add(this->textAddBuyNum);
            this->groupBoxAddBuy->Controls->Add(this->textAddBuyName);
            this->groupBoxAddBuy->Controls->Add(this->textAddBuyPass);
            this->groupBoxAddBuy->Controls->Add(this->textAddBuyLog);
            this->groupBoxAddBuy->Controls->Add(this->label17);
            this->groupBoxAddBuy->Controls->Add(this->textSearchAdd);
            this->groupBoxAddBuy->Controls->Add(this->buttonSearchAdd);
            this->groupBoxAddBuy->Controls->Add(this->dgvAddBuy);
            this->groupBoxAddBuy->Enabled = false;
            this->groupBoxAddBuy->Location = System::Drawing::Point(0, 88);
            this->groupBoxAddBuy->Name = L"groupBoxAddBuy";
            this->groupBoxAddBuy->Size = System::Drawing::Size(1659, 941);
            this->groupBoxAddBuy->TabIndex = 17;
            this->groupBoxAddBuy->TabStop = false;
            this->groupBoxAddBuy->Visible = false;
            // 
            // groupBoxAddPur
            // 
            this->groupBoxAddPur->Controls->Add(this->groupBoxAddB);
            this->groupBoxAddPur->Controls->Add(this->comboAddPurB);
            this->groupBoxAddPur->Controls->Add(this->comboAddPurLogEmp);
            this->groupBoxAddPur->Controls->Add(this->comboAddPurLogBuy);
            this->groupBoxAddPur->Controls->Add(this->numericAddPurQua);
            this->groupBoxAddPur->Controls->Add(this->timeAddPurTime);
            this->groupBoxAddPur->Controls->Add(this->dateAddPurDate);
            this->groupBoxAddPur->Controls->Add(this->label28);
            this->groupBoxAddPur->Controls->Add(this->label27);
            this->groupBoxAddPur->Controls->Add(this->dgvAddPur);
            this->groupBoxAddPur->Controls->Add(this->label22);
            this->groupBoxAddPur->Controls->Add(this->label23);
            this->groupBoxAddPur->Controls->Add(this->label24);
            this->groupBoxAddPur->Controls->Add(this->label25);
            this->groupBoxAddPur->Controls->Add(this->buttonAddPur);
            this->groupBoxAddPur->Controls->Add(this->label26);
            this->groupBoxAddPur->Controls->Add(this->textSearchAdd2);
            this->groupBoxAddPur->Controls->Add(this->buttonSearchAdd2);
            this->groupBoxAddPur->Enabled = false;
            this->groupBoxAddPur->Location = System::Drawing::Point(0, 0);
            this->groupBoxAddPur->Name = L"groupBoxAddPur";
            this->groupBoxAddPur->Size = System::Drawing::Size(1659, 941);
            this->groupBoxAddPur->TabIndex = 18;
            this->groupBoxAddPur->TabStop = false;
            this->groupBoxAddPur->Visible = false;
            // 
            // groupBoxAddB
            // 
            this->groupBoxAddB->Controls->Add(this->textAddBPH);
            this->groupBoxAddB->Controls->Add(this->label48);
            this->groupBoxAddB->Controls->Add(this->textAddBGenre);
            this->groupBoxAddB->Controls->Add(this->label47);
            this->groupBoxAddB->Controls->Add(this->dgvAddB);
            this->groupBoxAddB->Controls->Add(this->textAddBCost);
            this->groupBoxAddB->Controls->Add(this->textAddBAuthor);
            this->groupBoxAddB->Controls->Add(this->textAddBName);
            this->groupBoxAddB->Controls->Add(this->label39);
            this->groupBoxAddB->Controls->Add(this->label40);
            this->groupBoxAddB->Controls->Add(this->label45);
            this->groupBoxAddB->Controls->Add(this->buttonAddB);
            this->groupBoxAddB->Controls->Add(this->label46);
            this->groupBoxAddB->Controls->Add(this->textSearchAdd5);
            this->groupBoxAddB->Controls->Add(this->buttonSearchAdd5);
            this->groupBoxAddB->Enabled = false;
            this->groupBoxAddB->Location = System::Drawing::Point(0, 0);
            this->groupBoxAddB->Name = L"groupBoxAddB";
            this->groupBoxAddB->Size = System::Drawing::Size(1659, 941);
            this->groupBoxAddB->TabIndex = 34;
            this->groupBoxAddB->TabStop = false;
            this->groupBoxAddB->Visible = false;
            // 
            // textAddBPH
            // 
            this->textAddBPH->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textAddBPH->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textAddBPH->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textAddBPH->Location = System::Drawing::Point(1326, 385);
            this->textAddBPH->Name = L"textAddBPH";
            this->textAddBPH->Size = System::Drawing::Size(256, 35);
            this->textAddBPH->TabIndex = 37;
            // 
            // label48
            // 
            this->label48->AutoSize = true;
            this->label48->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label48->Location = System::Drawing::Point(1322, 352);
            this->label48->Name = L"label48";
            this->label48->Size = System::Drawing::Size(181, 29);
            this->label48->TabIndex = 36;
            this->label48->Text = L"Видавництво:";
            // 
            // textAddBGenre
            // 
            this->textAddBGenre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textAddBGenre->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textAddBGenre->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textAddBGenre->Location = System::Drawing::Point(1325, 315);
            this->textAddBGenre->Name = L"textAddBGenre";
            this->textAddBGenre->Size = System::Drawing::Size(256, 35);
            this->textAddBGenre->TabIndex = 35;
            this->textAddBGenre->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Seller::textAddBGenre_KeyPress);
            // 
            // label47
            // 
            this->label47->AutoSize = true;
            this->label47->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label47->Location = System::Drawing::Point(1321, 282);
            this->label47->Name = L"label47";
            this->label47->Size = System::Drawing::Size(84, 29);
            this->label47->TabIndex = 34;
            this->label47->Text = L"Жанр:";
            // 
            // dgvAddB
            // 
            this->dgvAddB->AllowUserToAddRows = false;
            this->dgvAddB->AllowUserToDeleteRows = false;
            this->dgvAddB->AllowUserToResizeColumns = false;
            this->dgvAddB->AllowUserToResizeRows = false;
            this->dgvAddB->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvAddB->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvAddB->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
                this->isbnAddB, this->nameAddB,
                    this->authorAddB, this->costAddB, this->genreAddB, this->publishing_houseAddB
            });
            this->dgvAddB->Location = System::Drawing::Point(24, 60);
            this->dgvAddB->Name = L"dgvAddB";
            this->dgvAddB->Size = System::Drawing::Size(1243, 857);
            this->dgvAddB->TabIndex = 33;
            // 
            // isbnAddB
            // 
            this->isbnAddB->DataPropertyName = L"isbnAddB";
            this->isbnAddB->HeaderText = L"ISBN";
            this->isbnAddB->Name = L"isbnAddB";
            this->isbnAddB->ReadOnly = true;
            // 
            // nameAddB
            // 
            this->nameAddB->DataPropertyName = L"nameAddB";
            this->nameAddB->HeaderText = L"Назва книги";
            this->nameAddB->Name = L"nameAddB";
            this->nameAddB->ReadOnly = true;
            this->nameAddB->Width = 400;
            // 
            // authorAddB
            // 
            this->authorAddB->DataPropertyName = L"authorAddB";
            this->authorAddB->HeaderText = L"Автор";
            this->authorAddB->Name = L"authorAddB";
            this->authorAddB->ReadOnly = true;
            this->authorAddB->Width = 300;
            // 
            // costAddB
            // 
            this->costAddB->DataPropertyName = L"costAddB";
            this->costAddB->HeaderText = L"Ціна";
            this->costAddB->Name = L"costAddB";
            this->costAddB->ReadOnly = true;
            // 
            // genreAddB
            // 
            this->genreAddB->DataPropertyName = L"genreAddB";
            this->genreAddB->HeaderText = L"Жанр";
            this->genreAddB->Name = L"genreAddB";
            this->genreAddB->ReadOnly = true;
            // 
            // publishing_houseAddB
            // 
            this->publishing_houseAddB->DataPropertyName = L"publishing_houseAddB";
            this->publishing_houseAddB->HeaderText = L"Видавництво";
            this->publishing_houseAddB->Name = L"publishing_houseAddB";
            this->publishing_houseAddB->ReadOnly = true;
            this->publishing_houseAddB->Width = 200;
            // 
            // textAddBCost
            // 
            this->textAddBCost->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textAddBCost->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textAddBCost->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textAddBCost->Location = System::Drawing::Point(1325, 242);
            this->textAddBCost->Name = L"textAddBCost";
            this->textAddBCost->Size = System::Drawing::Size(256, 35);
            this->textAddBCost->TabIndex = 28;
            this->textAddBCost->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Seller::textAddBCost_KeyPress);
            // 
            // textAddBAuthor
            // 
            this->textAddBAuthor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textAddBAuthor->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textAddBAuthor->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textAddBAuthor->Location = System::Drawing::Point(1325, 165);
            this->textAddBAuthor->Name = L"textAddBAuthor";
            this->textAddBAuthor->Size = System::Drawing::Size(256, 35);
            this->textAddBAuthor->TabIndex = 27;
            this->textAddBAuthor->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Seller::textAddBAuthor_KeyPress);
            // 
            // textAddBName
            // 
            this->textAddBName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textAddBName->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textAddBName->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textAddBName->Location = System::Drawing::Point(1325, 93);
            this->textAddBName->Name = L"textAddBName";
            this->textAddBName->Size = System::Drawing::Size(256, 35);
            this->textAddBName->TabIndex = 26;
            // 
            // label39
            // 
            this->label39->AutoSize = true;
            this->label39->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label39->Location = System::Drawing::Point(1321, 209);
            this->label39->Name = L"label39";
            this->label39->Size = System::Drawing::Size(82, 29);
            this->label39->TabIndex = 14;
            this->label39->Text = L"Ціна*:";
            // 
            // label40
            // 
            this->label40->AutoSize = true;
            this->label40->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label40->Location = System::Drawing::Point(1321, 132);
            this->label40->Name = L"label40";
            this->label40->Size = System::Drawing::Size(93, 29);
            this->label40->TabIndex = 13;
            this->label40->Text = L"Автор:";
            // 
            // label45
            // 
            this->label45->AutoSize = true;
            this->label45->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label45->Location = System::Drawing::Point(1321, 60);
            this->label45->Name = L"label45";
            this->label45->Size = System::Drawing::Size(173, 29);
            this->label45->TabIndex = 12;
            this->label45->Text = L"Назва книги*:";
            // 
            // buttonAddB
            // 
            this->buttonAddB->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonAddB->FlatAppearance->BorderSize = 0;
            this->buttonAddB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonAddB->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonAddB->Location = System::Drawing::Point(1423, 435);
            this->buttonAddB->Name = L"buttonAddB";
            this->buttonAddB->Size = System::Drawing::Size(75, 35);
            this->buttonAddB->TabIndex = 11;
            this->buttonAddB->Text = L"→";
            this->buttonAddB->UseVisualStyleBackColor = false;
            this->buttonAddB->Click += gcnew System::EventHandler(this, &Seller::buttonAddB_Click);
            // 
            // label46
            // 
            this->label46->AutoSize = true;
            this->label46->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label46->Location = System::Drawing::Point(19, 22);
            this->label46->Name = L"label46";
            this->label46->Size = System::Drawing::Size(228, 29);
            this->label46->TabIndex = 6;
            this->label46->Text = L"Пошук за назвою:";
            // 
            // textSearchAdd5
            // 
            this->textSearchAdd5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearchAdd5->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearchAdd5->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearchAdd5->Location = System::Drawing::Point(261, 19);
            this->textSearchAdd5->Name = L"textSearchAdd5";
            this->textSearchAdd5->Size = System::Drawing::Size(332, 35);
            this->textSearchAdd5->TabIndex = 5;
            // 
            // buttonSearchAdd5
            // 
            this->buttonSearchAdd5->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearchAdd5->FlatAppearance->BorderSize = 0;
            this->buttonSearchAdd5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearchAdd5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearchAdd5->Location = System::Drawing::Point(602, 19);
            this->buttonSearchAdd5->Name = L"buttonSearchAdd5";
            this->buttonSearchAdd5->Size = System::Drawing::Size(75, 35);
            this->buttonSearchAdd5->TabIndex = 4;
            this->buttonSearchAdd5->Text = L"→";
            this->buttonSearchAdd5->UseVisualStyleBackColor = false;
            this->buttonSearchAdd5->Click += gcnew System::EventHandler(this, &Seller::buttonSearchAdd5_Click);
            // 
            // comboAddPurB
            // 
            this->comboAddPurB->BackColor = System::Drawing::SystemColors::ControlDark;
            this->comboAddPurB->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->comboAddPurB->ForeColor = System::Drawing::SystemColors::InfoText;
            this->comboAddPurB->FormattingEnabled = true;
            this->comboAddPurB->Location = System::Drawing::Point(1326, 246);
            this->comboAddPurB->Name = L"comboAddPurB";
            this->comboAddPurB->Size = System::Drawing::Size(255, 35);
            this->comboAddPurB->Sorted = true;
            this->comboAddPurB->TabIndex = 24;
            // 
            // comboAddPurLogEmp
            // 
            this->comboAddPurLogEmp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->comboAddPurLogEmp->BackColor = System::Drawing::SystemColors::ControlDark;
            this->comboAddPurLogEmp->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->comboAddPurLogEmp->Location = System::Drawing::Point(1325, 171);
            this->comboAddPurLogEmp->Name = L"comboAddPurLogEmp";
            this->comboAddPurLogEmp->ReadOnly = true;
            this->comboAddPurLogEmp->Size = System::Drawing::Size(256, 35);
            this->comboAddPurLogEmp->TabIndex = 35;
            // 
            // comboAddPurLogBuy
            // 
            this->comboAddPurLogBuy->BackColor = System::Drawing::SystemColors::ControlDark;
            this->comboAddPurLogBuy->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->comboAddPurLogBuy->ForeColor = System::Drawing::SystemColors::InfoText;
            this->comboAddPurLogBuy->FormattingEnabled = true;
            this->comboAddPurLogBuy->Location = System::Drawing::Point(1325, 93);
            this->comboAddPurLogBuy->Name = L"comboAddPurLogBuy";
            this->comboAddPurLogBuy->Size = System::Drawing::Size(256, 35);
            this->comboAddPurLogBuy->Sorted = true;
            this->comboAddPurLogBuy->TabIndex = 22;
            // 
            // numericAddPurQua
            // 
            this->numericAddPurQua->BackColor = System::Drawing::SystemColors::ControlDark;
            this->numericAddPurQua->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->numericAddPurQua->Location = System::Drawing::Point(1326, 321);
            this->numericAddPurQua->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
            this->numericAddPurQua->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            this->numericAddPurQua->Name = L"numericAddPurQua";
            this->numericAddPurQua->Size = System::Drawing::Size(255, 35);
            this->numericAddPurQua->TabIndex = 21;
            this->numericAddPurQua->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // timeAddPurTime
            // 
            this->timeAddPurTime->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->timeAddPurTime->Format = System::Windows::Forms::DateTimePickerFormat::Time;
            this->timeAddPurTime->Location = System::Drawing::Point(1326, 465);
            this->timeAddPurTime->Name = L"timeAddPurTime";
            this->timeAddPurTime->Size = System::Drawing::Size(255, 35);
            this->timeAddPurTime->TabIndex = 20;
            // 
            // dateAddPurDate
            // 
            this->dateAddPurDate->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->dateAddPurDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dateAddPurDate->Location = System::Drawing::Point(1325, 395);
            this->dateAddPurDate->Name = L"dateAddPurDate";
            this->dateAddPurDate->Size = System::Drawing::Size(256, 35);
            this->dateAddPurDate->TabIndex = 19;
            // 
            // label28
            // 
            this->label28->AutoSize = true;
            this->label28->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label28->Location = System::Drawing::Point(1321, 433);
            this->label28->Name = L"label28";
            this->label28->Size = System::Drawing::Size(72, 29);
            this->label28->TabIndex = 18;
            this->label28->Text = L"Час*:";
            // 
            // label27
            // 
            this->label27->AutoSize = true;
            this->label27->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label27->Location = System::Drawing::Point(1321, 363);
            this->label27->Name = L"label27";
            this->label27->Size = System::Drawing::Size(83, 29);
            this->label27->TabIndex = 17;
            this->label27->Text = L"Дата*:";
            // 
            // dgvAddPur
            // 
            this->dgvAddPur->AllowUserToAddRows = false;
            this->dgvAddPur->AllowUserToDeleteRows = false;
            this->dgvAddPur->AllowUserToResizeColumns = false;
            this->dgvAddPur->AllowUserToResizeRows = false;
            this->dgvAddPur->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvAddPur->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvAddPur->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
                this->idAddPur, this->loginAddPur,
                    this->loginEmpAddPur, this->bookAddPur, this->costAddPur, this->quantityAddPur, this->dateAddPur, this->timeAddPur
            });
            this->dgvAddPur->Location = System::Drawing::Point(24, 60);
            this->dgvAddPur->Name = L"dgvAddPur";
            this->dgvAddPur->Size = System::Drawing::Size(1243, 857);
            this->dgvAddPur->TabIndex = 16;
            // 
            // idAddPur
            // 
            this->idAddPur->DataPropertyName = L"idAddPur";
            this->idAddPur->HeaderText = L"ID";
            this->idAddPur->Name = L"idAddPur";
            this->idAddPur->ReadOnly = true;
            // 
            // loginAddPur
            // 
            this->loginAddPur->DataPropertyName = L"loginAddPur";
            this->loginAddPur->HeaderText = L"Логін покупця";
            this->loginAddPur->Name = L"loginAddPur";
            this->loginAddPur->ReadOnly = true;
            this->loginAddPur->Width = 250;
            // 
            // loginEmpAddPur
            // 
            this->loginEmpAddPur->DataPropertyName = L"loginEmpAddPur";
            this->loginEmpAddPur->HeaderText = L"Логін продавця";
            this->loginEmpAddPur->Name = L"loginEmpAddPur";
            this->loginEmpAddPur->ReadOnly = true;
            this->loginEmpAddPur->Width = 250;
            // 
            // bookAddPur
            // 
            this->bookAddPur->DataPropertyName = L"bookAddPur";
            this->bookAddPur->HeaderText = L"Книга";
            this->bookAddPur->Name = L"bookAddPur";
            this->bookAddPur->ReadOnly = true;
            // 
            // costAddPur
            // 
            this->costAddPur->DataPropertyName = L"costAddPur";
            this->costAddPur->HeaderText = L"Ціна";
            this->costAddPur->Name = L"costAddPur";
            this->costAddPur->ReadOnly = true;
            // 
            // quantityAddPur
            // 
            this->quantityAddPur->DataPropertyName = L"quantityAddPur";
            this->quantityAddPur->HeaderText = L"Кількість";
            this->quantityAddPur->Name = L"quantityAddPur";
            this->quantityAddPur->ReadOnly = true;
            // 
            // dateAddPur
            // 
            this->dateAddPur->DataPropertyName = L"dateAddPur";
            this->dateAddPur->HeaderText = L"Дата";
            this->dateAddPur->Name = L"dateAddPur";
            this->dateAddPur->ReadOnly = true;
            this->dateAddPur->Width = 150;
            // 
            // timeAddPur
            // 
            this->timeAddPur->DataPropertyName = L"timeAddPur";
            this->timeAddPur->HeaderText = L"Час";
            this->timeAddPur->Name = L"timeAddPur";
            this->timeAddPur->ReadOnly = true;
            this->timeAddPur->Width = 150;
            // 
            // label22
            // 
            this->label22->AutoSize = true;
            this->label22->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label22->Location = System::Drawing::Point(1321, 289);
            this->label22->Name = L"label22";
            this->label22->Size = System::Drawing::Size(139, 29);
            this->label22->TabIndex = 15;
            this->label22->Text = L"Кількість*:";
            // 
            // label23
            // 
            this->label23->AutoSize = true;
            this->label23->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label23->Location = System::Drawing::Point(1321, 215);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(97, 29);
            this->label23->TabIndex = 14;
            this->label23->Text = L"Книга*:";
            // 
            // label24
            // 
            this->label24->AutoSize = true;
            this->label24->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label24->Location = System::Drawing::Point(1321, 138);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(208, 29);
            this->label24->TabIndex = 13;
            this->label24->Text = L"Логін продавця:";
            // 
            // label25
            // 
            this->label25->AutoSize = true;
            this->label25->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label25->Location = System::Drawing::Point(1321, 61);
            this->label25->Name = L"label25";
            this->label25->Size = System::Drawing::Size(199, 29);
            this->label25->TabIndex = 12;
            this->label25->Text = L"Логін покупця*:";
            // 
            // buttonAddPur
            // 
            this->buttonAddPur->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonAddPur->FlatAppearance->BorderSize = 0;
            this->buttonAddPur->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonAddPur->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonAddPur->Location = System::Drawing::Point(1423, 524);
            this->buttonAddPur->Name = L"buttonAddPur";
            this->buttonAddPur->Size = System::Drawing::Size(75, 35);
            this->buttonAddPur->TabIndex = 11;
            this->buttonAddPur->Text = L"→";
            this->buttonAddPur->UseVisualStyleBackColor = false;
            this->buttonAddPur->Click += gcnew System::EventHandler(this, &Seller::buttonAddPur_Click);
            // 
            // label26
            // 
            this->label26->AutoSize = true;
            this->label26->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label26->Location = System::Drawing::Point(19, 22);
            this->label26->Name = L"label26";
            this->label26->Size = System::Drawing::Size(233, 29);
            this->label26->TabIndex = 6;
            this->label26->Text = L"Пошук за логіном:";
            // 
            // textSearchAdd2
            // 
            this->textSearchAdd2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearchAdd2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearchAdd2->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearchAdd2->Location = System::Drawing::Point(261, 19);
            this->textSearchAdd2->Name = L"textSearchAdd2";
            this->textSearchAdd2->Size = System::Drawing::Size(332, 35);
            this->textSearchAdd2->TabIndex = 5;
            // 
            // buttonSearchAdd2
            // 
            this->buttonSearchAdd2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearchAdd2->FlatAppearance->BorderSize = 0;
            this->buttonSearchAdd2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearchAdd2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearchAdd2->Location = System::Drawing::Point(602, 19);
            this->buttonSearchAdd2->Name = L"buttonSearchAdd2";
            this->buttonSearchAdd2->Size = System::Drawing::Size(75, 35);
            this->buttonSearchAdd2->TabIndex = 4;
            this->buttonSearchAdd2->Text = L"→";
            this->buttonSearchAdd2->UseVisualStyleBackColor = false;
            this->buttonSearchAdd2->Click += gcnew System::EventHandler(this, &Seller::buttonSearchAdd2_Click);
            // 
            // label21
            // 
            this->label21->AutoSize = true;
            this->label21->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label21->Location = System::Drawing::Point(1321, 283);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(108, 29);
            this->label21->TabIndex = 15;
            this->label21->Text = L"Номер*:";
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label20->Location = System::Drawing::Point(1321, 206);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(70, 29);
            this->label20->TabIndex = 14;
            this->label20->Text = L"ПІБ*:";
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label19->Location = System::Drawing::Point(1321, 135);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(118, 29);
            this->label19->TabIndex = 13;
            this->label19->Text = L"Пароль*:";
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label18->Location = System::Drawing::Point(1321, 64);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(93, 29);
            this->label18->TabIndex = 12;
            this->label18->Text = L"Логін*:";
            // 
            // buttonAddBuy
            // 
            this->buttonAddBuy->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonAddBuy->FlatAppearance->BorderSize = 0;
            this->buttonAddBuy->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonAddBuy->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonAddBuy->Location = System::Drawing::Point(1423, 366);
            this->buttonAddBuy->Name = L"buttonAddBuy";
            this->buttonAddBuy->Size = System::Drawing::Size(75, 35);
            this->buttonAddBuy->TabIndex = 11;
            this->buttonAddBuy->Text = L"→";
            this->buttonAddBuy->UseVisualStyleBackColor = false;
            this->buttonAddBuy->Click += gcnew System::EventHandler(this, &Seller::buttonAddBuy_Click);
            // 
            // textAddBuyNum
            // 
            this->textAddBuyNum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textAddBuyNum->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textAddBuyNum->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textAddBuyNum->Location = System::Drawing::Point(1325, 316);
            this->textAddBuyNum->Name = L"textAddBuyNum";
            this->textAddBuyNum->Size = System::Drawing::Size(256, 35);
            this->textAddBuyNum->TabIndex = 10;
            this->textAddBuyNum->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Seller::textAddBuyNum_KeyPress);
            // 
            // textAddBuyName
            // 
            this->textAddBuyName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textAddBuyName->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textAddBuyName->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textAddBuyName->Location = System::Drawing::Point(1325, 239);
            this->textAddBuyName->Name = L"textAddBuyName";
            this->textAddBuyName->Size = System::Drawing::Size(256, 35);
            this->textAddBuyName->TabIndex = 9;
            this->textAddBuyName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Seller::textAddBuyName_KeyPress);
            // 
            // textAddBuyPass
            // 
            this->textAddBuyPass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textAddBuyPass->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textAddBuyPass->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textAddBuyPass->Location = System::Drawing::Point(1326, 169);
            this->textAddBuyPass->Name = L"textAddBuyPass";
            this->textAddBuyPass->Size = System::Drawing::Size(256, 35);
            this->textAddBuyPass->TabIndex = 8;
            // 
            // textAddBuyLog
            // 
            this->textAddBuyLog->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textAddBuyLog->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textAddBuyLog->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textAddBuyLog->Location = System::Drawing::Point(1325, 93);
            this->textAddBuyLog->Name = L"textAddBuyLog";
            this->textAddBuyLog->Size = System::Drawing::Size(256, 35);
            this->textAddBuyLog->TabIndex = 7;
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label17->Location = System::Drawing::Point(19, 22);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(233, 29);
            this->label17->TabIndex = 6;
            this->label17->Text = L"Пошук за логіном:";
            // 
            // textSearchAdd
            // 
            this->textSearchAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearchAdd->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearchAdd->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearchAdd->Location = System::Drawing::Point(261, 19);
            this->textSearchAdd->Name = L"textSearchAdd";
            this->textSearchAdd->Size = System::Drawing::Size(332, 35);
            this->textSearchAdd->TabIndex = 5;
            // 
            // buttonSearchAdd
            // 
            this->buttonSearchAdd->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearchAdd->FlatAppearance->BorderSize = 0;
            this->buttonSearchAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearchAdd->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearchAdd->Location = System::Drawing::Point(602, 19);
            this->buttonSearchAdd->Name = L"buttonSearchAdd";
            this->buttonSearchAdd->Size = System::Drawing::Size(75, 35);
            this->buttonSearchAdd->TabIndex = 4;
            this->buttonSearchAdd->Text = L"→";
            this->buttonSearchAdd->UseVisualStyleBackColor = false;
            this->buttonSearchAdd->Click += gcnew System::EventHandler(this, &Seller::buttonSearchAdd_Click);
            // 
            // dgvAddBuy
            // 
            this->dgvAddBuy->AllowUserToAddRows = false;
            this->dgvAddBuy->AllowUserToDeleteRows = false;
            this->dgvAddBuy->AllowUserToResizeColumns = false;
            this->dgvAddBuy->AllowUserToResizeRows = false;
            this->dgvAddBuy->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvAddBuy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvAddBuy->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
                this->loginAddBuy,
                    this->passwordAddBuy, this->nameAddBuy, this->contact_numberAddBuy
            });
            this->dgvAddBuy->Location = System::Drawing::Point(24, 60);
            this->dgvAddBuy->Name = L"dgvAddBuy";
            this->dgvAddBuy->Size = System::Drawing::Size(1243, 857);
            this->dgvAddBuy->TabIndex = 1;
            // 
            // loginAddBuy
            // 
            this->loginAddBuy->DataPropertyName = L"loginAddBuy";
            this->loginAddBuy->HeaderText = L"Логін";
            this->loginAddBuy->Name = L"loginAddBuy";
            this->loginAddBuy->ReadOnly = true;
            this->loginAddBuy->Width = 300;
            // 
            // passwordAddBuy
            // 
            this->passwordAddBuy->DataPropertyName = L"passwordAddBuy";
            this->passwordAddBuy->HeaderText = L"Пароль";
            this->passwordAddBuy->Name = L"passwordAddBuy";
            this->passwordAddBuy->ReadOnly = true;
            this->passwordAddBuy->Width = 350;
            // 
            // nameAddBuy
            // 
            this->nameAddBuy->DataPropertyName = L"nameAddBuy";
            this->nameAddBuy->HeaderText = L"ПІБ";
            this->nameAddBuy->Name = L"nameAddBuy";
            this->nameAddBuy->ReadOnly = true;
            this->nameAddBuy->Width = 350;
            // 
            // contact_numberAddBuy
            // 
            this->contact_numberAddBuy->DataPropertyName = L"contact_numberAddBuy";
            this->contact_numberAddBuy->HeaderText = L"Номер";
            this->contact_numberAddBuy->Name = L"contact_numberAddBuy";
            this->contact_numberAddBuy->ReadOnly = true;
            this->contact_numberAddBuy->Width = 200;
            // 
            // buttonBuyer2
            // 
            this->buttonBuyer2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonBuyer2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonBuyer2->FlatAppearance->BorderSize = 0;
            this->buttonBuyer2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonBuyer2->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonBuyer2->Location = System::Drawing::Point(238, 20);
            this->buttonBuyer2->Name = L"buttonBuyer2";
            this->buttonBuyer2->Size = System::Drawing::Size(190, 43);
            this->buttonBuyer2->TabIndex = 1;
            this->buttonBuyer2->Text = L"Покупці";
            this->buttonBuyer2->UseVisualStyleBackColor = false;
            this->buttonBuyer2->Click += gcnew System::EventHandler(this, &Seller::buttonBuyer2_Click);
            // 
            // buttonPurchase2
            // 
            this->buttonPurchase2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonPurchase2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonPurchase2->FlatAppearance->BorderSize = 0;
            this->buttonPurchase2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonPurchase2->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonPurchase2->Location = System::Drawing::Point(732, 20);
            this->buttonPurchase2->Name = L"buttonPurchase2";
            this->buttonPurchase2->Size = System::Drawing::Size(190, 43);
            this->buttonPurchase2->TabIndex = 2;
            this->buttonPurchase2->Text = L"Купівлі";
            this->buttonPurchase2->UseVisualStyleBackColor = false;
            this->buttonPurchase2->Click += gcnew System::EventHandler(this, &Seller::buttonPurchase2_Click);
            // 
            // buttonBook2
            // 
            this->buttonBook2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonBook2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonBook2->FlatAppearance->BorderSize = 0;
            this->buttonBook2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonBook2->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonBook2->Location = System::Drawing::Point(1232, 20);
            this->buttonBook2->Name = L"buttonBook2";
            this->buttonBook2->Size = System::Drawing::Size(190, 43);
            this->buttonBook2->TabIndex = 7;
            this->buttonBook2->Text = L"Книги";
            this->buttonBook2->UseVisualStyleBackColor = false;
            this->buttonBook2->Click += gcnew System::EventHandler(this, &Seller::buttonBook2_Click);
            // 
            // groupBoxRevBuy
            // 
            this->groupBoxRevBuy->Controls->Add(this->groupBoxRevPur);
            this->groupBoxRevBuy->Controls->Add(this->buttonSearch);
            this->groupBoxRevBuy->Controls->Add(this->label3);
            this->groupBoxRevBuy->Controls->Add(this->textSearch);
            this->groupBoxRevBuy->Controls->Add(this->dgvRevBuy);
            this->groupBoxRevBuy->Enabled = false;
            this->groupBoxRevBuy->Location = System::Drawing::Point(0, 88);
            this->groupBoxRevBuy->Name = L"groupBoxRevBuy";
            this->groupBoxRevBuy->Size = System::Drawing::Size(1659, 941);
            this->groupBoxRevBuy->TabIndex = 16;
            this->groupBoxRevBuy->TabStop = false;
            this->groupBoxRevBuy->Visible = false;
            // 
            // groupBoxRevPur
            // 
            this->groupBoxRevPur->Controls->Add(this->groupBoxRevBS);
            this->groupBoxRevPur->Controls->Add(this->label6);
            this->groupBoxRevPur->Controls->Add(this->label5);
            this->groupBoxRevPur->Controls->Add(this->buttonPurCal);
            this->groupBoxRevPur->Controls->Add(this->datePur2);
            this->groupBoxRevPur->Controls->Add(this->datePur1);
            this->groupBoxRevPur->Controls->Add(this->buttonSearch2);
            this->groupBoxRevPur->Controls->Add(this->label4);
            this->groupBoxRevPur->Controls->Add(this->textSearch2);
            this->groupBoxRevPur->Controls->Add(this->dgvRevPur);
            this->groupBoxRevPur->Enabled = false;
            this->groupBoxRevPur->Location = System::Drawing::Point(0, 0);
            this->groupBoxRevPur->Name = L"groupBoxRevPur";
            this->groupBoxRevPur->Size = System::Drawing::Size(1659, 941);
            this->groupBoxRevPur->TabIndex = 17;
            this->groupBoxRevPur->TabStop = false;
            this->groupBoxRevPur->Visible = false;
            // 
            // groupBoxRevBS
            // 
            this->groupBoxRevBS->Controls->Add(this->groupBoxRevB);
            this->groupBoxRevBS->Controls->Add(this->buttonSearch4);
            this->groupBoxRevBS->Controls->Add(this->label7);
            this->groupBoxRevBS->Controls->Add(this->textSearch4);
            this->groupBoxRevBS->Controls->Add(this->dgvRevBS);
            this->groupBoxRevBS->Enabled = false;
            this->groupBoxRevBS->Location = System::Drawing::Point(0, 0);
            this->groupBoxRevBS->Name = L"groupBoxRevBS";
            this->groupBoxRevBS->Size = System::Drawing::Size(1659, 941);
            this->groupBoxRevBS->TabIndex = 19;
            this->groupBoxRevBS->TabStop = false;
            this->groupBoxRevBS->Visible = false;
            // 
            // groupBoxRevB
            // 
            this->groupBoxRevB->Controls->Add(this->groupBoxRevV);
            this->groupBoxRevB->Controls->Add(this->buttonSearchRevCost);
            this->groupBoxRevB->Controls->Add(this->label12);
            this->groupBoxRevB->Controls->Add(this->label11);
            this->groupBoxRevB->Controls->Add(this->label10);
            this->groupBoxRevB->Controls->Add(this->numericUpDownRev2);
            this->groupBoxRevB->Controls->Add(this->numericUpDownRev1);
            this->groupBoxRevB->Controls->Add(this->buttonSearch5);
            this->groupBoxRevB->Controls->Add(this->label8);
            this->groupBoxRevB->Controls->Add(this->textSearch5);
            this->groupBoxRevB->Controls->Add(this->dgvRevB);
            this->groupBoxRevB->Enabled = false;
            this->groupBoxRevB->Location = System::Drawing::Point(0, 0);
            this->groupBoxRevB->Name = L"groupBoxRevB";
            this->groupBoxRevB->Size = System::Drawing::Size(1659, 941);
            this->groupBoxRevB->TabIndex = 20;
            this->groupBoxRevB->TabStop = false;
            this->groupBoxRevB->Visible = false;
            // 
            // groupBoxRevV
            // 
            this->groupBoxRevV->Controls->Add(this->buttonVCal);
            this->groupBoxRevV->Controls->Add(this->dateV2);
            this->groupBoxRevV->Controls->Add(this->dateV1);
            this->groupBoxRevV->Controls->Add(this->label15);
            this->groupBoxRevV->Controls->Add(this->label14);
            this->groupBoxRevV->Controls->Add(this->buttonSearch7);
            this->groupBoxRevV->Controls->Add(this->label13);
            this->groupBoxRevV->Controls->Add(this->textSearch7);
            this->groupBoxRevV->Controls->Add(this->dgvRevV);
            this->groupBoxRevV->Enabled = false;
            this->groupBoxRevV->Location = System::Drawing::Point(0, 0);
            this->groupBoxRevV->Name = L"groupBoxRevV";
            this->groupBoxRevV->Size = System::Drawing::Size(1659, 941);
            this->groupBoxRevV->TabIndex = 22;
            this->groupBoxRevV->TabStop = false;
            this->groupBoxRevV->Visible = false;
            // 
            // buttonVCal
            // 
            this->buttonVCal->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonVCal->FlatAppearance->BorderSize = 0;
            this->buttonVCal->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonVCal->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonVCal->Location = System::Drawing::Point(1442, 264);
            this->buttonVCal->Name = L"buttonVCal";
            this->buttonVCal->Size = System::Drawing::Size(75, 35);
            this->buttonVCal->TabIndex = 8;
            this->buttonVCal->Text = L"→";
            this->buttonVCal->UseVisualStyleBackColor = false;
            this->buttonVCal->Click += gcnew System::EventHandler(this, &Seller::buttonVCal_Click);
            // 
            // dateV2
            // 
            this->dateV2->CalendarFont = (gcnew System::Drawing::Font(L"Arial Narrow", 18));
            this->dateV2->Location = System::Drawing::Point(1416, 215);
            this->dateV2->Name = L"dateV2";
            this->dateV2->Size = System::Drawing::Size(200, 20);
            this->dateV2->TabIndex = 7;
            // 
            // dateV1
            // 
            this->dateV1->CalendarFont = (gcnew System::Drawing::Font(L"Arial Narrow", 18));
            this->dateV1->Location = System::Drawing::Point(1416, 161);
            this->dateV1->Name = L"dateV1";
            this->dateV1->Size = System::Drawing::Size(200, 20);
            this->dateV1->TabIndex = 6;
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label15->Location = System::Drawing::Point(1338, 209);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(52, 29);
            this->label15->TabIndex = 5;
            this->label15->Text = L"До:";
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label14->Location = System::Drawing::Point(1338, 152);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(59, 29);
            this->label14->TabIndex = 4;
            this->label14->Text = L"Від:";
            // 
            // buttonSearch7
            // 
            this->buttonSearch7->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearch7->FlatAppearance->BorderSize = 0;
            this->buttonSearch7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearch7->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearch7->Location = System::Drawing::Point(602, 19);
            this->buttonSearch7->Name = L"buttonSearch7";
            this->buttonSearch7->Size = System::Drawing::Size(75, 35);
            this->buttonSearch7->TabIndex = 3;
            this->buttonSearch7->Text = L"→";
            this->buttonSearch7->UseVisualStyleBackColor = false;
            this->buttonSearch7->Click += gcnew System::EventHandler(this, &Seller::buttonSearch7_Click);
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label13->Location = System::Drawing::Point(19, 22);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(233, 29);
            this->label13->TabIndex = 2;
            this->label13->Text = L"Пошук за логіном:";
            // 
            // textSearch7
            // 
            this->textSearch7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearch7->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearch7->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearch7->Location = System::Drawing::Point(261, 19);
            this->textSearch7->Name = L"textSearch7";
            this->textSearch7->Size = System::Drawing::Size(332, 35);
            this->textSearch7->TabIndex = 1;
            // 
            // dgvRevV
            // 
            this->dgvRevV->AllowUserToAddRows = false;
            this->dgvRevV->AllowUserToDeleteRows = false;
            this->dgvRevV->AllowUserToResizeColumns = false;
            this->dgvRevV->AllowUserToResizeRows = false;
            this->dgvRevV->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvRevV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvRevV->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
                this->loginRevVBuy,
                    this->nameRevVBS, this->date_visitRev, this->time_visitRev, this->noteRev
            });
            this->dgvRevV->Location = System::Drawing::Point(24, 60);
            this->dgvRevV->Name = L"dgvRevV";
            this->dgvRevV->Size = System::Drawing::Size(1243, 857);
            this->dgvRevV->TabIndex = 0;
            // 
            // loginRevVBuy
            // 
            this->loginRevVBuy->DataPropertyName = L"loginRevVBuy";
            this->loginRevVBuy->HeaderText = L"Логін покупця";
            this->loginRevVBuy->Name = L"loginRevVBuy";
            this->loginRevVBuy->ReadOnly = true;
            this->loginRevVBuy->Width = 300;
            // 
            // nameRevVBS
            // 
            this->nameRevVBS->DataPropertyName = L"nameRevVBS";
            this->nameRevVBS->HeaderText = L"Назва книгарні";
            this->nameRevVBS->Name = L"nameRevVBS";
            this->nameRevVBS->ReadOnly = true;
            this->nameRevVBS->Width = 300;
            // 
            // date_visitRev
            // 
            this->date_visitRev->DataPropertyName = L"date_visitRev";
            this->date_visitRev->HeaderText = L"Дата";
            this->date_visitRev->Name = L"date_visitRev";
            this->date_visitRev->ReadOnly = true;
            // 
            // time_visitRev
            // 
            this->time_visitRev->DataPropertyName = L"time_visitRev";
            this->time_visitRev->HeaderText = L"Час";
            this->time_visitRev->Name = L"time_visitRev";
            this->time_visitRev->ReadOnly = true;
            // 
            // noteRev
            // 
            this->noteRev->DataPropertyName = L"noteRev";
            this->noteRev->HeaderText = L"Нотатки";
            this->noteRev->Name = L"noteRev";
            this->noteRev->ReadOnly = true;
            this->noteRev->Width = 400;
            // 
            // buttonSearchRevCost
            // 
            this->buttonSearchRevCost->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearchRevCost->FlatAppearance->BorderSize = 0;
            this->buttonSearchRevCost->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearchRevCost->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearchRevCost->Location = System::Drawing::Point(1461, 251);
            this->buttonSearchRevCost->Name = L"buttonSearchRevCost";
            this->buttonSearchRevCost->Size = System::Drawing::Size(75, 35);
            this->buttonSearchRevCost->TabIndex = 9;
            this->buttonSearchRevCost->Text = L"→";
            this->buttonSearchRevCost->UseVisualStyleBackColor = false;
            this->buttonSearchRevCost->Click += gcnew System::EventHandler(this, &Seller::buttonSearchRevCost_Click);
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label12->Location = System::Drawing::Point(1463, 90);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(73, 29);
            this->label12->TabIndex = 8;
            this->label12->Text = L"Ціна:";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label11->Location = System::Drawing::Point(1354, 197);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(52, 29);
            this->label11->TabIndex = 7;
            this->label11->Text = L"До:";
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label10->Location = System::Drawing::Point(1354, 143);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(59, 29);
            this->label10->TabIndex = 6;
            this->label10->Text = L"Від:";
            // 
            // numericUpDownRev2
            // 
            this->numericUpDownRev2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->numericUpDownRev2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18));
            this->numericUpDownRev2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
            this->numericUpDownRev2->Location = System::Drawing::Point(1449, 191);
            this->numericUpDownRev2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3000, 0, 0, 0 });
            this->numericUpDownRev2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->numericUpDownRev2->Name = L"numericUpDownRev2";
            this->numericUpDownRev2->Size = System::Drawing::Size(120, 35);
            this->numericUpDownRev2->TabIndex = 5;
            this->numericUpDownRev2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            // 
            // numericUpDownRev1
            // 
            this->numericUpDownRev1->BackColor = System::Drawing::SystemColors::ControlDark;
            this->numericUpDownRev1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18));
            this->numericUpDownRev1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
            this->numericUpDownRev1->Location = System::Drawing::Point(1449, 138);
            this->numericUpDownRev1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3000, 0, 0, 0 });
            this->numericUpDownRev1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->numericUpDownRev1->Name = L"numericUpDownRev1";
            this->numericUpDownRev1->Size = System::Drawing::Size(120, 35);
            this->numericUpDownRev1->TabIndex = 4;
            this->numericUpDownRev1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            // 
            // buttonSearch5
            // 
            this->buttonSearch5->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearch5->FlatAppearance->BorderSize = 0;
            this->buttonSearch5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearch5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearch5->Location = System::Drawing::Point(602, 19);
            this->buttonSearch5->Name = L"buttonSearch5";
            this->buttonSearch5->Size = System::Drawing::Size(75, 35);
            this->buttonSearch5->TabIndex = 3;
            this->buttonSearch5->Text = L"→";
            this->buttonSearch5->UseVisualStyleBackColor = false;
            this->buttonSearch5->Click += gcnew System::EventHandler(this, &Seller::buttonSearch5_Click);
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label8->Location = System::Drawing::Point(19, 22);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(228, 29);
            this->label8->TabIndex = 2;
            this->label8->Text = L"Пошук за назвою:";
            // 
            // textSearch5
            // 
            this->textSearch5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearch5->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearch5->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearch5->Location = System::Drawing::Point(261, 19);
            this->textSearch5->Name = L"textSearch5";
            this->textSearch5->Size = System::Drawing::Size(332, 35);
            this->textSearch5->TabIndex = 1;
            // 
            // dgvRevB
            // 
            this->dgvRevB->AllowUserToAddRows = false;
            this->dgvRevB->AllowUserToDeleteRows = false;
            this->dgvRevB->AllowUserToResizeColumns = false;
            this->dgvRevB->AllowUserToResizeRows = false;
            this->dgvRevB->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvRevB->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvRevB->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
                this->isbnRev, this->nameRevB,
                    this->authorRev, this->costRevB, this->genreRev, this->publishing_houseRev
            });
            this->dgvRevB->Location = System::Drawing::Point(24, 60);
            this->dgvRevB->Name = L"dgvRevB";
            this->dgvRevB->Size = System::Drawing::Size(1243, 857);
            this->dgvRevB->TabIndex = 0;
            // 
            // isbnRev
            // 
            this->isbnRev->DataPropertyName = L"isbnRev";
            this->isbnRev->HeaderText = L"ISBN";
            this->isbnRev->Name = L"isbnRev";
            this->isbnRev->ReadOnly = true;
            // 
            // nameRevB
            // 
            this->nameRevB->DataPropertyName = L"nameRevB";
            this->nameRevB->HeaderText = L"Назва книги";
            this->nameRevB->Name = L"nameRevB";
            this->nameRevB->ReadOnly = true;
            this->nameRevB->Width = 400;
            // 
            // authorRev
            // 
            this->authorRev->DataPropertyName = L"authorRev";
            this->authorRev->HeaderText = L"Автор";
            this->authorRev->Name = L"authorRev";
            this->authorRev->ReadOnly = true;
            this->authorRev->Width = 300;
            // 
            // costRevB
            // 
            this->costRevB->DataPropertyName = L"costRevB";
            this->costRevB->HeaderText = L"Ціна";
            this->costRevB->Name = L"costRevB";
            this->costRevB->ReadOnly = true;
            // 
            // genreRev
            // 
            this->genreRev->DataPropertyName = L"genreRev";
            this->genreRev->HeaderText = L"Жанр";
            this->genreRev->Name = L"genreRev";
            this->genreRev->ReadOnly = true;
            // 
            // publishing_houseRev
            // 
            this->publishing_houseRev->DataPropertyName = L"publishing_houseRev";
            this->publishing_houseRev->HeaderText = L"Видавництво";
            this->publishing_houseRev->Name = L"publishing_houseRev";
            this->publishing_houseRev->ReadOnly = true;
            this->publishing_houseRev->Width = 200;
            // 
            // buttonSearch4
            // 
            this->buttonSearch4->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearch4->FlatAppearance->BorderSize = 0;
            this->buttonSearch4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearch4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearch4->Location = System::Drawing::Point(602, 19);
            this->buttonSearch4->Name = L"buttonSearch4";
            this->buttonSearch4->Size = System::Drawing::Size(75, 35);
            this->buttonSearch4->TabIndex = 3;
            this->buttonSearch4->Text = L"→";
            this->buttonSearch4->UseVisualStyleBackColor = false;
            this->buttonSearch4->Click += gcnew System::EventHandler(this, &Seller::buttonSearch4_Click);
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label7->Location = System::Drawing::Point(19, 22);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(228, 29);
            this->label7->TabIndex = 2;
            this->label7->Text = L"Пошук за назвою:";
            // 
            // textSearch4
            // 
            this->textSearch4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearch4->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearch4->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearch4->Location = System::Drawing::Point(261, 19);
            this->textSearch4->Name = L"textSearch4";
            this->textSearch4->Size = System::Drawing::Size(332, 35);
            this->textSearch4->TabIndex = 1;
            // 
            // dgvRevBS
            // 
            this->dgvRevBS->AllowUserToAddRows = false;
            this->dgvRevBS->AllowUserToDeleteRows = false;
            this->dgvRevBS->AllowUserToResizeColumns = false;
            this->dgvRevBS->AllowUserToResizeRows = false;
            this->dgvRevBS->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvRevBS->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvRevBS->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
                this->nameRevBS, this->contact_numberRevBS,
                    this->addressRevBS, this->work_scheduleRev
            });
            this->dgvRevBS->Location = System::Drawing::Point(24, 60);
            this->dgvRevBS->Name = L"dgvRevBS";
            this->dgvRevBS->Size = System::Drawing::Size(1243, 857);
            this->dgvRevBS->TabIndex = 0;
            // 
            // nameRevBS
            // 
            this->nameRevBS->DataPropertyName = L"nameRevBS";
            this->nameRevBS->HeaderText = L"Назва книгарні";
            this->nameRevBS->Name = L"nameRevBS";
            this->nameRevBS->ReadOnly = true;
            this->nameRevBS->Width = 400;
            // 
            // contact_numberRevBS
            // 
            this->contact_numberRevBS->DataPropertyName = L"contact_numberRevBS";
            this->contact_numberRevBS->HeaderText = L"Номер телефону";
            this->contact_numberRevBS->Name = L"contact_numberRevBS";
            this->contact_numberRevBS->ReadOnly = true;
            this->contact_numberRevBS->Width = 300;
            // 
            // addressRevBS
            // 
            this->addressRevBS->DataPropertyName = L"addressRevBS";
            this->addressRevBS->HeaderText = L"Адрес";
            this->addressRevBS->Name = L"addressRevBS";
            this->addressRevBS->ReadOnly = true;
            this->addressRevBS->Width = 300;
            // 
            // work_scheduleRev
            // 
            this->work_scheduleRev->DataPropertyName = L"work_scheduleRev";
            this->work_scheduleRev->HeaderText = L"Дні роботи";
            this->work_scheduleRev->Name = L"work_scheduleRev";
            this->work_scheduleRev->ReadOnly = true;
            this->work_scheduleRev->Width = 200;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->label6->Location = System::Drawing::Point(1337, 200);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(46, 29);
            this->label6->TabIndex = 8;
            this->label6->Text = L"До:";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->label5->Location = System::Drawing::Point(1331, 153);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(52, 29);
            this->label5->TabIndex = 7;
            this->label5->Text = L"Від:";
            // 
            // buttonPurCal
            // 
            this->buttonPurCal->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonPurCal->FlatAppearance->BorderSize = 0;
            this->buttonPurCal->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonPurCal->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonPurCal->Location = System::Drawing::Point(1449, 251);
            this->buttonPurCal->Name = L"buttonPurCal";
            this->buttonPurCal->Size = System::Drawing::Size(75, 35);
            this->buttonPurCal->TabIndex = 6;
            this->buttonPurCal->Text = L"→";
            this->buttonPurCal->UseVisualStyleBackColor = false;
            this->buttonPurCal->Click += gcnew System::EventHandler(this, &Seller::buttonPurCal_Click);
            // 
            // datePur2
            // 
            this->datePur2->Location = System::Drawing::Point(1389, 209);
            this->datePur2->Name = L"datePur2";
            this->datePur2->Size = System::Drawing::Size(211, 20);
            this->datePur2->TabIndex = 5;
            // 
            // datePur1
            // 
            this->datePur1->Location = System::Drawing::Point(1389, 159);
            this->datePur1->Name = L"datePur1";
            this->datePur1->Size = System::Drawing::Size(211, 20);
            this->datePur1->TabIndex = 4;
            // 
            // buttonSearch2
            // 
            this->buttonSearch2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearch2->FlatAppearance->BorderSize = 0;
            this->buttonSearch2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearch2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearch2->Location = System::Drawing::Point(602, 19);
            this->buttonSearch2->Name = L"buttonSearch2";
            this->buttonSearch2->Size = System::Drawing::Size(75, 35);
            this->buttonSearch2->TabIndex = 3;
            this->buttonSearch2->Text = L"→";
            this->buttonSearch2->UseVisualStyleBackColor = false;
            this->buttonSearch2->Click += gcnew System::EventHandler(this, &Seller::buttonSearch2_Click);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label4->Location = System::Drawing::Point(19, 22);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(233, 29);
            this->label4->TabIndex = 2;
            this->label4->Text = L"Пошук за логіном:";
            // 
            // textSearch2
            // 
            this->textSearch2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearch2->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearch2->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearch2->Location = System::Drawing::Point(261, 19);
            this->textSearch2->Name = L"textSearch2";
            this->textSearch2->Size = System::Drawing::Size(332, 35);
            this->textSearch2->TabIndex = 1;
            // 
            // dgvRevPur
            // 
            this->dgvRevPur->AllowUserToAddRows = false;
            this->dgvRevPur->AllowUserToDeleteRows = false;
            this->dgvRevPur->AllowUserToResizeColumns = false;
            this->dgvRevPur->AllowUserToResizeRows = false;
            this->dgvRevPur->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvRevPur->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvRevPur->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
                this->purchase_id,
                    this->loginRevPurBuy, this->loginRevPurEmp, this->book, this->cost, this->quantity, this->date, this->time
            });
            this->dgvRevPur->Location = System::Drawing::Point(24, 60);
            this->dgvRevPur->Name = L"dgvRevPur";
            this->dgvRevPur->Size = System::Drawing::Size(1243, 857);
            this->dgvRevPur->TabIndex = 0;
            // 
            // purchase_id
            // 
            this->purchase_id->DataPropertyName = L"purchase_id";
            this->purchase_id->HeaderText = L"ID";
            this->purchase_id->Name = L"purchase_id";
            this->purchase_id->ReadOnly = true;
            // 
            // loginRevPurBuy
            // 
            this->loginRevPurBuy->DataPropertyName = L"loginRevPurBuy";
            this->loginRevPurBuy->HeaderText = L"Логін покупця";
            this->loginRevPurBuy->Name = L"loginRevPurBuy";
            this->loginRevPurBuy->ReadOnly = true;
            this->loginRevPurBuy->Width = 250;
            // 
            // loginRevPurEmp
            // 
            this->loginRevPurEmp->DataPropertyName = L"loginRevPurEmp";
            this->loginRevPurEmp->HeaderText = L"Логін продавця";
            this->loginRevPurEmp->Name = L"loginRevPurEmp";
            this->loginRevPurEmp->ReadOnly = true;
            this->loginRevPurEmp->Width = 250;
            // 
            // book
            // 
            this->book->DataPropertyName = L"book";
            this->book->HeaderText = L"Книга";
            this->book->Name = L"book";
            this->book->ReadOnly = true;
            // 
            // cost
            // 
            this->cost->DataPropertyName = L"cost";
            this->cost->HeaderText = L"Ціна";
            this->cost->Name = L"cost";
            this->cost->ReadOnly = true;
            // 
            // quantity
            // 
            this->quantity->DataPropertyName = L"quantity";
            this->quantity->HeaderText = L"Кількість";
            this->quantity->Name = L"quantity";
            this->quantity->ReadOnly = true;
            // 
            // date
            // 
            this->date->DataPropertyName = L"date";
            this->date->HeaderText = L"Дата";
            this->date->Name = L"date";
            this->date->ReadOnly = true;
            this->date->Width = 150;
            // 
            // time
            // 
            this->time->DataPropertyName = L"time";
            this->time->HeaderText = L"Час";
            this->time->Name = L"time";
            this->time->ReadOnly = true;
            this->time->Width = 150;
            // 
            // buttonSearch
            // 
            this->buttonSearch->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonSearch->FlatAppearance->BorderSize = 0;
            this->buttonSearch->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSearch->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
            this->buttonSearch->Location = System::Drawing::Point(602, 19);
            this->buttonSearch->Name = L"buttonSearch";
            this->buttonSearch->Size = System::Drawing::Size(75, 35);
            this->buttonSearch->TabIndex = 3;
            this->buttonSearch->Text = L"→";
            this->buttonSearch->UseVisualStyleBackColor = false;
            this->buttonSearch->Click += gcnew System::EventHandler(this, &Seller::buttonSearch_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->label3->Location = System::Drawing::Point(19, 22);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(233, 29);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Пошук за логіном:";
            // 
            // textSearch
            // 
            this->textSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->textSearch->BackColor = System::Drawing::SystemColors::ControlDark;
            this->textSearch->Font = (gcnew System::Drawing::Font(L"Arial", 18));
            this->textSearch->Location = System::Drawing::Point(261, 19);
            this->textSearch->Name = L"textSearch";
            this->textSearch->Size = System::Drawing::Size(332, 35);
            this->textSearch->TabIndex = 1;
            // 
            // dgvRevBuy
            // 
            this->dgvRevBuy->AllowUserToAddRows = false;
            this->dgvRevBuy->AllowUserToDeleteRows = false;
            this->dgvRevBuy->AllowUserToResizeColumns = false;
            this->dgvRevBuy->AllowUserToResizeRows = false;
            this->dgvRevBuy->BackgroundColor = System::Drawing::SystemColors::ControlDark;
            this->dgvRevBuy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvRevBuy->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
                this->login, this->password,
                    this->name, this->contact_number
            });
            this->dgvRevBuy->Location = System::Drawing::Point(24, 60);
            this->dgvRevBuy->Name = L"dgvRevBuy";
            this->dgvRevBuy->Size = System::Drawing::Size(1243, 857);
            this->dgvRevBuy->TabIndex = 0;
            // 
            // login
            // 
            this->login->DataPropertyName = L"login";
            this->login->HeaderText = L"Логін";
            this->login->Name = L"login";
            this->login->ReadOnly = true;
            this->login->Width = 300;
            // 
            // password
            // 
            this->password->DataPropertyName = L"password";
            this->password->HeaderText = L"Пароль";
            this->password->Name = L"password";
            this->password->ReadOnly = true;
            this->password->Width = 350;
            // 
            // name
            // 
            this->name->DataPropertyName = L"name";
            this->name->HeaderText = L"ПІБ";
            this->name->Name = L"name";
            this->name->ReadOnly = true;
            this->name->Width = 350;
            // 
            // contact_number
            // 
            this->contact_number->DataPropertyName = L"contact_number";
            this->contact_number->HeaderText = L"Номер";
            this->contact_number->Name = L"contact_number";
            this->contact_number->ReadOnly = true;
            this->contact_number->Width = 200;
            // 
            // buttonBuyer
            // 
            this->buttonBuyer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonBuyer->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonBuyer->FlatAppearance->BorderSize = 0;
            this->buttonBuyer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonBuyer->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonBuyer->Location = System::Drawing::Point(38, 20);
            this->buttonBuyer->Name = L"buttonBuyer";
            this->buttonBuyer->Size = System::Drawing::Size(190, 43);
            this->buttonBuyer->TabIndex = 1;
            this->buttonBuyer->Text = L"Покупці";
            this->buttonBuyer->UseVisualStyleBackColor = false;
            this->buttonBuyer->Click += gcnew System::EventHandler(this, &Seller::buttonBuyer_Click);
            // 
            // buttonBookstore
            // 
            this->buttonBookstore->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonBookstore->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonBookstore->FlatAppearance->BorderSize = 0;
            this->buttonBookstore->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonBookstore->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonBookstore->Location = System::Drawing::Point(722, 20);
            this->buttonBookstore->Name = L"buttonBookstore";
            this->buttonBookstore->Size = System::Drawing::Size(190, 43);
            this->buttonBookstore->TabIndex = 17;
            this->buttonBookstore->Text = L"Книгарні";
            this->buttonBookstore->UseVisualStyleBackColor = false;
            this->buttonBookstore->Click += gcnew System::EventHandler(this, &Seller::buttonBookstore_Click);
            // 
            // buttonVisit
            // 
            this->buttonVisit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonVisit->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonVisit->FlatAppearance->BorderSize = 0;
            this->buttonVisit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonVisit->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonVisit->Location = System::Drawing::Point(1432, 20);
            this->buttonVisit->Name = L"buttonVisit";
            this->buttonVisit->Size = System::Drawing::Size(190, 43);
            this->buttonVisit->TabIndex = 6;
            this->buttonVisit->Text = L"Відвідування";
            this->buttonVisit->UseVisualStyleBackColor = false;
            this->buttonVisit->Click += gcnew System::EventHandler(this, &Seller::buttonVisit_Click);
            // 
            // buttonPurchase
            // 
            this->buttonPurchase->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonPurchase->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonPurchase->FlatAppearance->BorderSize = 0;
            this->buttonPurchase->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonPurchase->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonPurchase->Location = System::Drawing::Point(377, 20);
            this->buttonPurchase->Name = L"buttonPurchase";
            this->buttonPurchase->Size = System::Drawing::Size(190, 43);
            this->buttonPurchase->TabIndex = 2;
            this->buttonPurchase->Text = L"Купівлі";
            this->buttonPurchase->UseVisualStyleBackColor = false;
            this->buttonPurchase->Click += gcnew System::EventHandler(this, &Seller::buttonPurchase_Click);
            // 
            // buttonBook
            // 
            this->buttonBook->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->buttonBook->BackColor = System::Drawing::SystemColors::ControlDark;
            this->buttonBook->FlatAppearance->BorderSize = 0;
            this->buttonBook->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonBook->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
            this->buttonBook->Location = System::Drawing::Point(1078, 20);
            this->buttonBook->Name = L"buttonBook";
            this->buttonBook->Size = System::Drawing::Size(190, 43);
            this->buttonBook->TabIndex = 7;
            this->buttonBook->Text = L"Книги";
            this->buttonBook->UseVisualStyleBackColor = false;
            this->buttonBook->Click += gcnew System::EventHandler(this, &Seller::buttonBook_Click);
            // 
            // Seller
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
            this->ClientSize = System::Drawing::Size(1904, 1041);
            this->Controls->Add(this->groupBox1);
            this->Controls->Add(this->panel1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"Seller";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Книгарня(Продавець)";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->menuStrip1->ResumeLayout(false);
            this->menuStrip1->PerformLayout();
            this->groupBox1->ResumeLayout(false);
            this->groupBox2->ResumeLayout(false);
            this->groupBox3->ResumeLayout(false);
            this->groupBox4->ResumeLayout(false);
            this->groupBox5->ResumeLayout(false);
            this->groupBox14->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq9))->EndInit();
            this->groupBox13->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq8))->EndInit();
            this->groupBox11->ResumeLayout(false);
            this->groupBox11->PerformLayout();
            this->groupBox12->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq7))->EndInit();
            this->groupBox8->ResumeLayout(false);
            this->groupBox8->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq3))->EndInit();
            this->groupBox10->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq5))->EndInit();
            this->groupBox9->ResumeLayout(false);
            this->groupBox9->PerformLayout();
            this->groupBox6->ResumeLayout(false);
            this->groupBox6->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvReq1))->EndInit();
            this->groupBoxDelBuy->ResumeLayout(false);
            this->groupBoxDelBuy->PerformLayout();
            this->groupBoxDelPur->ResumeLayout(false);
            this->groupBoxDelPur->PerformLayout();
            this->groupBoxDelB->ResumeLayout(false);
            this->groupBoxDelB->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDelB))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDelPur))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDelBuy))->EndInit();
            this->groupBoxEdBuy->ResumeLayout(false);
            this->groupBoxEdBuy->PerformLayout();
            this->groupBoxEdPur->ResumeLayout(false);
            this->groupBoxEdPur->PerformLayout();
            this->groupBoxEdB->ResumeLayout(false);
            this->groupBoxEdB->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEdB))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericEdPurQua))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEdPur))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEdBuy))->EndInit();
            this->groupBoxAddBuy->ResumeLayout(false);
            this->groupBoxAddBuy->PerformLayout();
            this->groupBoxAddPur->ResumeLayout(false);
            this->groupBoxAddPur->PerformLayout();
            this->groupBoxAddB->ResumeLayout(false);
            this->groupBoxAddB->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAddB))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericAddPurQua))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAddPur))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAddBuy))->EndInit();
            this->groupBoxRevBuy->ResumeLayout(false);
            this->groupBoxRevBuy->PerformLayout();
            this->groupBoxRevPur->ResumeLayout(false);
            this->groupBoxRevPur->PerformLayout();
            this->groupBoxRevBS->ResumeLayout(false);
            this->groupBoxRevBS->PerformLayout();
            this->groupBoxRevB->ResumeLayout(false);
            this->groupBoxRevB->PerformLayout();
            this->groupBoxRevV->ResumeLayout(false);
            this->groupBoxRevV->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevV))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownRev2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownRev1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevB))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevBS))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevPur))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevBuy))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void buttonBuyer_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearch_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonPurchase_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearch2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonBookstore_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearch4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonPurCal_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonBook_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearch5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonVisit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearch7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearchRevCost_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonVCal_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    Application::Exit();
    return System::Void();
}
private: System::Void проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    MessageBox::Show("Bookstore Manager\nAC-224, Kolisnyk D.S.", "Info");
    return System::Void();
}
private: System::Void buttonRevision_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonEdit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonDel_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonReq_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonBuyer2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonPurchase2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonBook2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearchAdd_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonAddBuy_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearchAdd2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonAddPur_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearchAdd5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonAddB_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonBuyer3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonPurchase3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonBook3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearchEd_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonEdBuy_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dgvEdBuy_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void buttonSearchEd2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonEdPur_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dgvEdPur_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void buttonSearchEd5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonEdB_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dgvEdB_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void buttonBuyer4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonPurchase4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonBook4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearchDel_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonDelBuy_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearchDel2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonDelPur_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearchDel5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonDelB_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonReq1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonReq4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonReq5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonReq6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonReq3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonReq7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonReq8_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonReq9_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textAddBuyName_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!Char::IsLetter(e->KeyChar) && e->KeyChar != ' ' && e->KeyChar != '\b') {
        e->Handled = true;
    }
}
private: System::Void textAddBAuthor_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!Char::IsLetter(e->KeyChar) && e->KeyChar != ' ' && e->KeyChar != '\b') {
        e->Handled = true;
    }
}
private: System::Void textAddBGenre_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!Char::IsLetter(e->KeyChar) && e->KeyChar != ' ' && e->KeyChar != '\b') {
        e->Handled = true;
    }
}
private: System::Void textAddBuyNum_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b') {
        e->Handled = true;
    }
}
private: System::Void textEdBuyNum_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b') {
        e->Handled = true;
    }
}
private: System::Void textEdBuyName_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!Char::IsLetter(e->KeyChar) && e->KeyChar != ' ' && e->KeyChar != '\b') {
        e->Handled = true;
    }
}
private: System::Void textEdBAuthor_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!Char::IsLetter(e->KeyChar) && e->KeyChar != ' ' && e->KeyChar != '\b') {
        e->Handled = true;
    }
}
private: System::Void textEdBGenre_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!Char::IsLetter(e->KeyChar) && e->KeyChar != ' ' && e->KeyChar != '\b') {
        e->Handled = true;
    }
}
private: System::Void textEdBCost_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b') {
        e->Handled = true;
    }
}
private: System::Void textAddBCost_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b') {
        e->Handled = true;
    }
}
};
}
