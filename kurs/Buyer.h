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
	/// Сводка для Buyer
	/// </summary>
	public ref class Buyer : public System::Windows::Forms::Form
	{
	public:
		Buyer(String^ login)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->labelLogin->Text = login;
			InitializeDatabaseConnection();
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Buyer()
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
	private: System::Windows::Forms::Button^ buttonPurCal;
	private: System::Windows::Forms::DataGridView^ dgvRevBS;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameRevBS;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ contact_numberRevBS;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ addressRevBS;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ work_scheduleRev;
	private: System::Windows::Forms::DataGridView^ dgvRevB;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ isbnRev;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameRevB;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ authorRev;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ costRevB;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ genreRev;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ publishing_houseRev;
	private: System::Windows::Forms::DataGridView^ dgvRevV;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ nameRevVBS;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ date_visitRev;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ time_visitRev;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ noteRev;
	private: System::Windows::Forms::Button^ buttonVCal;
	private: System::Windows::Forms::DateTimePicker^ dateV2;
	private: System::Windows::Forms::DateTimePicker^ dateV1;
	private: System::Windows::Forms::Button^ buttonSearch5;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textSearch5;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textNumberEd;
	private: System::Windows::Forms::TextBox^ textNameEd;
	private: System::Windows::Forms::TextBox^ textPassEd;
	private: System::Windows::Forms::TextBox^ textLogEd;
	private: System::Windows::Forms::Button^ buttonEdAcc;
		   sql::ResultSet* res;
		void InitializeDatabaseConnection();
		void CloseDatabaseConnection();
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonPur;
	private: System::Windows::Forms::Label^ Label1;
	private: System::Windows::Forms::Button^ buttonV;
	private: System::Windows::Forms::Button^ buttonBS;
	private: System::Windows::Forms::Button^ buttonB;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вихідToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ проПрограмуToolStripMenuItem;
	private: System::Windows::Forms::Label^ labelLogin;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonEd;
	private: System::Windows::Forms::DataGridView^ dgvRevPur;
	private: System::Windows::Forms::DateTimePicker^ datePur1;
	private: System::Windows::Forms::DateTimePicker^ datePur2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ purchase_id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ loginRevPurEmp;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ book;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cost;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ quantity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ time;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Buyer::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buttonEd = (gcnew System::Windows::Forms::Button());
			this->labelLogin = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->проПрограмуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonPur = (gcnew System::Windows::Forms::Button());
			this->Label1 = (gcnew System::Windows::Forms::Label());
			this->buttonV = (gcnew System::Windows::Forms::Button());
			this->buttonBS = (gcnew System::Windows::Forms::Button());
			this->buttonB = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonEdAcc = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textNumberEd = (gcnew System::Windows::Forms::TextBox());
			this->textNameEd = (gcnew System::Windows::Forms::TextBox());
			this->textPassEd = (gcnew System::Windows::Forms::TextBox());
			this->textLogEd = (gcnew System::Windows::Forms::TextBox());
			this->textSearch5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->buttonSearch5 = (gcnew System::Windows::Forms::Button());
			this->buttonVCal = (gcnew System::Windows::Forms::Button());
			this->dateV2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateV1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dgvRevV = (gcnew System::Windows::Forms::DataGridView());
			this->nameRevVBS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date_visitRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->time_visitRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->noteRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgvRevB = (gcnew System::Windows::Forms::DataGridView());
			this->isbnRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nameRevB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->authorRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->costRevB = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->genreRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->publishing_houseRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgvRevBS = (gcnew System::Windows::Forms::DataGridView());
			this->nameRevBS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contact_numberRevBS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->addressRevBS = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->work_scheduleRev = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonPurCal = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->datePur2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->datePur1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dgvRevPur = (gcnew System::Windows::Forms::DataGridView());
			this->purchase_id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->loginRevPurEmp = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->book = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->quantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevV))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevBS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevPur))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->button2->Location = System::Drawing::Point(275, 1023);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(43, 36);
			this->button2->TabIndex = 12;
			this->button2->Text = L"←";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Buyer::button2_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->panel1->Controls->Add(this->buttonEd);
			this->panel1->Controls->Add(this->labelLogin);
			this->panel1->Controls->Add(this->menuStrip1);
			this->panel1->Controls->Add(this->buttonPur);
			this->panel1->Controls->Add(this->Label1);
			this->panel1->Controls->Add(this->buttonV);
			this->panel1->Controls->Add(this->buttonBS);
			this->panel1->Controls->Add(this->buttonB);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(319, 1061);
			this->panel1->TabIndex = 13;
			// 
			// buttonEd
			// 
			this->buttonEd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->buttonEd->BackColor = System::Drawing::SystemColors::ControlDark;
			this->buttonEd->FlatAppearance->BorderSize = 0;
			this->buttonEd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonEd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->buttonEd->Location = System::Drawing::Point(273, 982);
			this->buttonEd->Margin = System::Windows::Forms::Padding(4);
			this->buttonEd->Name = L"buttonEd";
			this->buttonEd->Size = System::Drawing::Size(44, 36);
			this->buttonEd->TabIndex = 31;
			this->buttonEd->Text = L"...";
			this->buttonEd->UseVisualStyleBackColor = false;
			this->buttonEd->Click += gcnew System::EventHandler(this, &Buyer::buttonEd_Click);
			// 
			// labelLogin
			// 
			this->labelLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->labelLogin->AutoSize = true;
			this->labelLogin->BackColor = System::Drawing::SystemColors::ControlDark;
			this->labelLogin->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold));
			this->labelLogin->Location = System::Drawing::Point(109, 990);
			this->labelLogin->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelLogin->Name = L"labelLogin";
			this->labelLogin->Size = System::Drawing::Size(54, 23);
			this->labelLogin->TabIndex = 15;
			this->labelLogin->Text = L"Login";
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
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(319, 24);
			this->menuStrip1->TabIndex = 30;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// вихідToolStripMenuItem
			// 
			this->вихідToolStripMenuItem->Name = L"вихідToolStripMenuItem";
			this->вихідToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->вихідToolStripMenuItem->Text = L"Вихід";
			this->вихідToolStripMenuItem->Click += gcnew System::EventHandler(this, &Buyer::вихідToolStripMenuItem_Click);
			// 
			// проПрограмуToolStripMenuItem
			// 
			this->проПрограмуToolStripMenuItem->Name = L"проПрограмуToolStripMenuItem";
			this->проПрограмуToolStripMenuItem->Size = System::Drawing::Size(99, 20);
			this->проПрограмуToolStripMenuItem->Text = L"Про програму";
			this->проПрограмуToolStripMenuItem->Click += gcnew System::EventHandler(this, &Buyer::проПрограмуToolStripMenuItem_Click);
			// 
			// buttonPur
			// 
			this->buttonPur->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->buttonPur->FlatAppearance->BorderSize = 0;
			this->buttonPur->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPur->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->buttonPur->Location = System::Drawing::Point(31, 305);
			this->buttonPur->Margin = System::Windows::Forms::Padding(4);
			this->buttonPur->Name = L"buttonPur";
			this->buttonPur->Size = System::Drawing::Size(251, 64);
			this->buttonPur->TabIndex = 25;
			this->buttonPur->Text = L"Мої купівлі";
			this->buttonPur->UseVisualStyleBackColor = false;
			this->buttonPur->Click += gcnew System::EventHandler(this, &Buyer::buttonPur_Click);
			// 
			// Label1
			// 
			this->Label1->AutoSize = true;
			this->Label1->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold));
			this->Label1->Location = System::Drawing::Point(83, 202);
			this->Label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Label1->Name = L"Label1";
			this->Label1->Size = System::Drawing::Size(120, 37);
			this->Label1->TabIndex = 24;
			this->Label1->Text = L"МЕНЮ";
			// 
			// buttonV
			// 
			this->buttonV->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->buttonV->FlatAppearance->BorderSize = 0;
			this->buttonV->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonV->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->buttonV->Location = System::Drawing::Point(31, 601);
			this->buttonV->Margin = System::Windows::Forms::Padding(4);
			this->buttonV->Name = L"buttonV";
			this->buttonV->Size = System::Drawing::Size(251, 64);
			this->buttonV->TabIndex = 28;
			this->buttonV->Text = L"Відвідування";
			this->buttonV->UseVisualStyleBackColor = false;
			this->buttonV->Click += gcnew System::EventHandler(this, &Buyer::buttonV_Click);
			// 
			// buttonBS
			// 
			this->buttonBS->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->buttonBS->FlatAppearance->BorderSize = 0;
			this->buttonBS->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonBS->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->buttonBS->Location = System::Drawing::Point(31, 400);
			this->buttonBS->Margin = System::Windows::Forms::Padding(4);
			this->buttonBS->Name = L"buttonBS";
			this->buttonBS->Size = System::Drawing::Size(251, 64);
			this->buttonBS->TabIndex = 26;
			this->buttonBS->Text = L"Книгарні";
			this->buttonBS->UseVisualStyleBackColor = false;
			this->buttonBS->Click += gcnew System::EventHandler(this, &Buyer::buttonBS_Click);
			// 
			// buttonB
			// 
			this->buttonB->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->buttonB->FlatAppearance->BorderSize = 0;
			this->buttonB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonB->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->buttonB->Location = System::Drawing::Point(31, 502);
			this->buttonB->Margin = System::Windows::Forms::Padding(4);
			this->buttonB->Name = L"buttonB";
			this->buttonB->Size = System::Drawing::Size(251, 64);
			this->buttonB->TabIndex = 27;
			this->buttonB->Text = L"Книги";
			this->buttonB->UseVisualStyleBackColor = false;
			this->buttonB->Click += gcnew System::EventHandler(this, &Buyer::buttonB_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(109, 1028);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 23);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Покупець";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(4, 975);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(97, 86);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonEdAcc);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textNumberEd);
			this->groupBox1->Controls->Add(this->textNameEd);
			this->groupBox1->Controls->Add(this->textPassEd);
			this->groupBox1->Controls->Add(this->textLogEd);
			this->groupBox1->Controls->Add(this->textSearch5);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->buttonSearch5);
			this->groupBox1->Controls->Add(this->buttonVCal);
			this->groupBox1->Controls->Add(this->dateV2);
			this->groupBox1->Controls->Add(this->dateV1);
			this->groupBox1->Controls->Add(this->dgvRevV);
			this->groupBox1->Controls->Add(this->dgvRevB);
			this->groupBox1->Controls->Add(this->dgvRevBS);
			this->groupBox1->Controls->Add(this->buttonPurCal);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->datePur2);
			this->groupBox1->Controls->Add(this->datePur1);
			this->groupBox1->Controls->Add(this->dgvRevPur);
			this->groupBox1->Location = System::Drawing::Point(325, 0);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(2212, 1266);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			// 
			// buttonEdAcc
			// 
			this->buttonEdAcc->BackColor = System::Drawing::SystemColors::ControlDark;
			this->buttonEdAcc->FlatAppearance->BorderSize = 0;
			this->buttonEdAcc->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonEdAcc->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->buttonEdAcc->Location = System::Drawing::Point(1069, 657);
			this->buttonEdAcc->Margin = System::Windows::Forms::Padding(4);
			this->buttonEdAcc->Name = L"buttonEdAcc";
			this->buttonEdAcc->Size = System::Drawing::Size(219, 53);
			this->buttonEdAcc->TabIndex = 28;
			this->buttonEdAcc->Text = L"Редагувати";
			this->buttonEdAcc->UseVisualStyleBackColor = false;
			this->buttonEdAcc->Visible = false;
			this->buttonEdAcc->Click += gcnew System::EventHandler(this, &Buyer::buttonEdAcc_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->label9->Location = System::Drawing::Point(1013, 561);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(222, 29);
			this->label9->TabIndex = 27;
			this->label9->Text = L"Номер телефону:";
			this->label9->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->label7->Location = System::Drawing::Point(1013, 464);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(61, 29);
			this->label7->TabIndex = 26;
			this->label7->Text = L"ПІБ:";
			this->label7->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(1013, 369);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(109, 29);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Пароль:";
			this->label6->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(1013, 276);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 29);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Логін:";
			this->label4->Visible = false;
			// 
			// textNumberEd
			// 
			this->textNumberEd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textNumberEd->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textNumberEd->Font = (gcnew System::Drawing::Font(L"Arial", 18));
			this->textNumberEd->Location = System::Drawing::Point(1020, 601);
			this->textNumberEd->Margin = System::Windows::Forms::Padding(4);
			this->textNumberEd->Name = L"textNumberEd";
			this->textNumberEd->Size = System::Drawing::Size(313, 35);
			this->textNumberEd->TabIndex = 23;
			this->textNumberEd->Visible = false;
			this->textNumberEd->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Buyer::textNumberEd_KeyPress);
			// 
			// textNameEd
			// 
			this->textNameEd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textNameEd->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textNameEd->Font = (gcnew System::Drawing::Font(L"Arial", 18));
			this->textNameEd->Location = System::Drawing::Point(1020, 503);
			this->textNameEd->Margin = System::Windows::Forms::Padding(4);
			this->textNameEd->Name = L"textNameEd";
			this->textNameEd->Size = System::Drawing::Size(313, 35);
			this->textNameEd->TabIndex = 22;
			this->textNameEd->Visible = false;
			this->textNameEd->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Buyer::textNameEd_KeyPress);
			// 
			// textPassEd
			// 
			this->textPassEd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textPassEd->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textPassEd->Font = (gcnew System::Drawing::Font(L"Arial", 18));
			this->textPassEd->Location = System::Drawing::Point(1020, 409);
			this->textPassEd->Margin = System::Windows::Forms::Padding(4);
			this->textPassEd->Name = L"textPassEd";
			this->textPassEd->Size = System::Drawing::Size(313, 35);
			this->textPassEd->TabIndex = 21;
			this->textPassEd->Visible = false;
			// 
			// textLogEd
			// 
			this->textLogEd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textLogEd->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textLogEd->Font = (gcnew System::Drawing::Font(L"Arial", 18));
			this->textLogEd->Location = System::Drawing::Point(1020, 315);
			this->textLogEd->Margin = System::Windows::Forms::Padding(4);
			this->textLogEd->Name = L"textLogEd";
			this->textLogEd->ReadOnly = true;
			this->textLogEd->Size = System::Drawing::Size(313, 35);
			this->textLogEd->TabIndex = 20;
			this->textLogEd->Visible = false;
			// 
			// textSearch5
			// 
			this->textSearch5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textSearch5->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textSearch5->Font = (gcnew System::Drawing::Font(L"Arial", 18));
			this->textSearch5->Location = System::Drawing::Point(340, 20);
			this->textSearch5->Margin = System::Windows::Forms::Padding(4);
			this->textSearch5->Name = L"textSearch5";
			this->textSearch5->Size = System::Drawing::Size(441, 35);
			this->textSearch5->TabIndex = 19;
			this->textSearch5->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->label8->Location = System::Drawing::Point(28, 21);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(228, 29);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Пошук за назвою:";
			this->label8->Visible = false;
			// 
			// buttonSearch5
			// 
			this->buttonSearch5->BackColor = System::Drawing::SystemColors::ControlDark;
			this->buttonSearch5->FlatAppearance->BorderSize = 0;
			this->buttonSearch5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonSearch5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
			this->buttonSearch5->Location = System::Drawing::Point(791, 21);
			this->buttonSearch5->Margin = System::Windows::Forms::Padding(4);
			this->buttonSearch5->Name = L"buttonSearch5";
			this->buttonSearch5->Size = System::Drawing::Size(100, 43);
			this->buttonSearch5->TabIndex = 17;
			this->buttonSearch5->Text = L"→";
			this->buttonSearch5->UseVisualStyleBackColor = false;
			this->buttonSearch5->Visible = false;
			this->buttonSearch5->Click += gcnew System::EventHandler(this, &Buyer::buttonSearch5_Click);
			// 
			// buttonVCal
			// 
			this->buttonVCal->BackColor = System::Drawing::SystemColors::ControlDark;
			this->buttonVCal->FlatAppearance->BorderSize = 0;
			this->buttonVCal->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonVCal->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->buttonVCal->Location = System::Drawing::Point(1912, 240);
			this->buttonVCal->Margin = System::Windows::Forms::Padding(4);
			this->buttonVCal->Name = L"buttonVCal";
			this->buttonVCal->Size = System::Drawing::Size(100, 43);
			this->buttonVCal->TabIndex = 16;
			this->buttonVCal->Text = L"→";
			this->buttonVCal->UseVisualStyleBackColor = false;
			this->buttonVCal->Visible = false;
			this->buttonVCal->Click += gcnew System::EventHandler(this, &Buyer::buttonVCal_Click);
			// 
			// dateV2
			// 
			this->dateV2->Location = System::Drawing::Point(1835, 191);
			this->dateV2->Margin = System::Windows::Forms::Padding(4);
			this->dateV2->Name = L"dateV2";
			this->dateV2->Size = System::Drawing::Size(280, 22);
			this->dateV2->TabIndex = 15;
			this->dateV2->Visible = false;
			// 
			// dateV1
			// 
			this->dateV1->Location = System::Drawing::Point(1835, 139);
			this->dateV1->Margin = System::Windows::Forms::Padding(4);
			this->dateV1->Name = L"dateV1";
			this->dateV1->Size = System::Drawing::Size(280, 22);
			this->dateV1->TabIndex = 14;
			this->dateV1->Visible = false;
			// 
			// dgvRevV
			// 
			this->dgvRevV->AllowUserToAddRows = false;
			this->dgvRevV->AllowUserToDeleteRows = false;
			this->dgvRevV->AllowUserToResizeColumns = false;
			this->dgvRevV->AllowUserToResizeRows = false;
			this->dgvRevV->BackgroundColor = System::Drawing::SystemColors::ControlDark;
			this->dgvRevV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvRevV->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->nameRevVBS, this->date_visitRev,
					this->time_visitRev, this->noteRev
			});
			this->dgvRevV->Location = System::Drawing::Point(8, 15);
			this->dgvRevV->Margin = System::Windows::Forms::Padding(4);
			this->dgvRevV->Name = L"dgvRevV";
			this->dgvRevV->Size = System::Drawing::Size(1657, 1244);
			this->dgvRevV->TabIndex = 13;
			this->dgvRevV->Visible = false;
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
			this->date_visitRev->Width = 150;
			// 
			// time_visitRev
			// 
			this->time_visitRev->DataPropertyName = L"time_visitRev";
			this->time_visitRev->HeaderText = L"Час";
			this->time_visitRev->Name = L"time_visitRev";
			this->time_visitRev->ReadOnly = true;
			this->time_visitRev->Width = 150;
			// 
			// noteRev
			// 
			this->noteRev->DataPropertyName = L"noteRev";
			this->noteRev->HeaderText = L"Нотатки";
			this->noteRev->Name = L"noteRev";
			this->noteRev->ReadOnly = true;
			this->noteRev->Width = 600;
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
			this->dgvRevB->Location = System::Drawing::Point(8, 74);
			this->dgvRevB->Margin = System::Windows::Forms::Padding(4);
			this->dgvRevB->Name = L"dgvRevB";
			this->dgvRevB->Size = System::Drawing::Size(1657, 1185);
			this->dgvRevB->TabIndex = 12;
			this->dgvRevB->Visible = false;
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
			this->dgvRevBS->Location = System::Drawing::Point(8, 15);
			this->dgvRevBS->Margin = System::Windows::Forms::Padding(4);
			this->dgvRevBS->Name = L"dgvRevBS";
			this->dgvRevBS->Size = System::Drawing::Size(1657, 1244);
			this->dgvRevBS->TabIndex = 11;
			this->dgvRevBS->Visible = false;
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
			// buttonPurCal
			// 
			this->buttonPurCal->BackColor = System::Drawing::SystemColors::ControlDark;
			this->buttonPurCal->FlatAppearance->BorderSize = 0;
			this->buttonPurCal->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonPurCal->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold));
			this->buttonPurCal->Location = System::Drawing::Point(1912, 240);
			this->buttonPurCal->Margin = System::Windows::Forms::Padding(4);
			this->buttonPurCal->Name = L"buttonPurCal";
			this->buttonPurCal->Size = System::Drawing::Size(100, 43);
			this->buttonPurCal->TabIndex = 10;
			this->buttonPurCal->Text = L"→";
			this->buttonPurCal->UseVisualStyleBackColor = false;
			this->buttonPurCal->Visible = false;
			this->buttonPurCal->Click += gcnew System::EventHandler(this, &Buyer::buttonPurCal_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(1757, 183);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 29);
			this->label3->TabIndex = 9;
			this->label3->Text = L"До:";
			this->label3->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(1757, 132);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 29);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Від:";
			this->label5->Visible = false;
			// 
			// datePur2
			// 
			this->datePur2->Location = System::Drawing::Point(1835, 191);
			this->datePur2->Margin = System::Windows::Forms::Padding(4);
			this->datePur2->Name = L"datePur2";
			this->datePur2->Size = System::Drawing::Size(280, 22);
			this->datePur2->TabIndex = 6;
			this->datePur2->Visible = false;
			// 
			// datePur1
			// 
			this->datePur1->Location = System::Drawing::Point(1835, 139);
			this->datePur1->Margin = System::Windows::Forms::Padding(4);
			this->datePur1->Name = L"datePur1";
			this->datePur1->Size = System::Drawing::Size(280, 22);
			this->datePur1->TabIndex = 5;
			this->datePur1->Visible = false;
			// 
			// dgvRevPur
			// 
			this->dgvRevPur->AllowUserToAddRows = false;
			this->dgvRevPur->AllowUserToDeleteRows = false;
			this->dgvRevPur->AllowUserToResizeColumns = false;
			this->dgvRevPur->AllowUserToResizeRows = false;
			this->dgvRevPur->BackgroundColor = System::Drawing::SystemColors::ControlDark;
			this->dgvRevPur->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvRevPur->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->purchase_id,
					this->loginRevPurEmp, this->book, this->cost, this->quantity, this->date, this->time
			});
			this->dgvRevPur->Location = System::Drawing::Point(8, 15);
			this->dgvRevPur->Margin = System::Windows::Forms::Padding(4);
			this->dgvRevPur->Name = L"dgvRevPur";
			this->dgvRevPur->Size = System::Drawing::Size(1657, 1244);
			this->dgvRevPur->TabIndex = 1;
			this->dgvRevPur->Visible = false;
			// 
			// purchase_id
			// 
			this->purchase_id->DataPropertyName = L"purchase_id";
			this->purchase_id->HeaderText = L"ID";
			this->purchase_id->Name = L"purchase_id";
			this->purchase_id->ReadOnly = true;
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
			this->book->Width = 200;
			// 
			// cost
			// 
			this->cost->DataPropertyName = L"cost";
			this->cost->HeaderText = L"Ціна";
			this->cost->Name = L"cost";
			this->cost->ReadOnly = true;
			this->cost->Width = 125;
			// 
			// quantity
			// 
			this->quantity->DataPropertyName = L"quantity";
			this->quantity->HeaderText = L"Кількість";
			this->quantity->Name = L"quantity";
			this->quantity->ReadOnly = true;
			this->quantity->Width = 125;
			// 
			// date
			// 
			this->date->DataPropertyName = L"date";
			this->date->HeaderText = L"Дата";
			this->date->Name = L"date";
			this->date->ReadOnly = true;
			this->date->Width = 200;
			// 
			// time
			// 
			this->time->DataPropertyName = L"time";
			this->time->HeaderText = L"Час";
			this->time->Name = L"time";
			this->time->ReadOnly = true;
			this->time->Width = 200;
			// 
			// Buyer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1924, 1061);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Buyer";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Книгарня(Покупець)";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevV))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevBS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRevPur))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonPur_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonBS_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonB_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonV_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonPurCal_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSearch5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonVCal_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonEd_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonEdAcc_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textNameEd_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsLetter(e->KeyChar) && e->KeyChar != ' ' && e->KeyChar != '\b') {
		e->Handled = true;
	}
}
private: System::Void textNumberEd_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b') {
		e->Handled = true;
	}
}
private: System::Void вихідToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
	return System::Void();
}
private: System::Void проПрограмуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Bookstore Manager\nAC-224, Kolisnyk D.S.", "Info");
	return System::Void();
}
};
}
