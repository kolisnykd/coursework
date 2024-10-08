#pragma once
namespace kurs {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для Registration
	/// </summary>
	public ref class Registration : public System::Windows::Forms::Form
	{
	public:
		Registration(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Registration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel2;
	protected:
	private: System::Windows::Forms::Label^ labelReg;
	private: System::Windows::Forms::TextBox^ textLog;
	private: System::Windows::Forms::TextBox^ textPass;
	private: System::Windows::Forms::TextBox^ textName;
	private: System::Windows::Forms::TextBox^ textNumber;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonReg2;
	private: System::Windows::Forms::Button^ button2;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Registration::typeid));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->labelReg = (gcnew System::Windows::Forms::Label());
			this->textLog = (gcnew System::Windows::Forms::TextBox());
			this->textPass = (gcnew System::Windows::Forms::TextBox());
			this->textName = (gcnew System::Windows::Forms::TextBox());
			this->textNumber = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonReg2 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->panel2->Controls->Add(this->labelReg);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(383, 79);
			this->panel2->TabIndex = 1;
			// 
			// labelReg
			// 
			this->labelReg->AutoSize = true;
			this->labelReg->BackColor = System::Drawing::SystemColors::ControlDark;
			this->labelReg->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelReg->Location = System::Drawing::Point(89, 19);
			this->labelReg->Name = L"labelReg";
			this->labelReg->Size = System::Drawing::Size(216, 37);
			this->labelReg->TabIndex = 0;
			this->labelReg->Text = L"РЕЄСТРАЦІЯ";
			this->labelReg->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->labelReg->Click += gcnew System::EventHandler(this, &Registration::labelAuth_Click);
			// 
			// textLog
			// 
			this->textLog->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textLog->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textLog->Location = System::Drawing::Point(120, 120);
			this->textLog->Name = L"textLog";
			this->textLog->Size = System::Drawing::Size(206, 35);
			this->textLog->TabIndex = 2;
			// 
			// textPass
			// 
			this->textPass->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textPass->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textPass->Location = System::Drawing::Point(120, 192);
			this->textPass->Name = L"textPass";
			this->textPass->Size = System::Drawing::Size(206, 35);
			this->textPass->TabIndex = 3;
			this->textPass->UseSystemPasswordChar = true;
			// 
			// textName
			// 
			this->textName->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textName->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textName->Location = System::Drawing::Point(120, 266);
			this->textName->Name = L"textName";
			this->textName->Size = System::Drawing::Size(206, 35);
			this->textName->TabIndex = 4;
			this->textName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::textName_KeyPress);
			// 
			// textNumber
			// 
			this->textNumber->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textNumber->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textNumber->Location = System::Drawing::Point(120, 338);
			this->textNumber->Name = L"textNumber";
			this->textNumber->Size = System::Drawing::Size(206, 35);
			this->textNumber->TabIndex = 5;
			this->textNumber->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Registration::textNumber_KeyPress);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(20, 100);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(67, 73);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(15, 179);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(75, 55);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(24, 266);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 37);
			this->label1->TabIndex = 8;
			this->label1->Text = L"ПІБ:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(6, 334);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 37);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Номер:";
			// 
			// buttonReg2
			// 
			this->buttonReg2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->buttonReg2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->buttonReg2->FlatAppearance->BorderSize = 0;
			this->buttonReg2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonReg2->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonReg2->Location = System::Drawing::Point(105, 408);
			this->buttonReg2->Name = L"buttonReg2";
			this->buttonReg2->Size = System::Drawing::Size(181, 50);
			this->buttonReg2->TabIndex = 10;
			this->buttonReg2->Text = L"Створити";
			this->buttonReg2->UseVisualStyleBackColor = false;
			this->buttonReg2->Click += gcnew System::EventHandler(this, &Registration::buttonReg2_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(359, 460);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(21, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"←";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Registration::button2_Click);
			// 
			// Registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(383, 486);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->buttonReg2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textNumber);
			this->Controls->Add(this->textName);
			this->Controls->Add(this->textPass);
			this->Controls->Add(this->textLog);
			this->Controls->Add(this->panel2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Registration";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Реєстрація";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void labelAuth_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonReg2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void textName_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsLetter(e->KeyChar) && e->KeyChar != ' ' && e->KeyChar != '\b') {
		e->Handled = true;
	}
}
private: System::Void textNumber_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b') {
		e->Handled = true;
	}
}
};
}
