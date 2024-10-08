#pragma once
namespace kurs {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для authForm
	/// </summary>
	public ref class authForm : public System::Windows::Forms::Form
	{
	public:
		authForm(void)
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
		~authForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ labelAuth;
	private: System::Windows::Forms::TextBox^ textLog;
	private: System::Windows::Forms::TextBox^ textPass;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ buttonLog;
	private: System::Windows::Forms::Button^ buttonReg;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(authForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->labelAuth = (gcnew System::Windows::Forms::Label());
			this->textLog = (gcnew System::Windows::Forms::TextBox());
			this->textPass = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonLog = (gcnew System::Windows::Forms::Button());
			this->buttonReg = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->panel1->Controls->Add(this->labelAuth);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(383, 79);
			this->panel1->TabIndex = 0;
			// 
			// labelAuth
			// 
			this->labelAuth->AutoSize = true;
			this->labelAuth->BackColor = System::Drawing::SystemColors::ControlDark;
			this->labelAuth->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAuth->Location = System::Drawing::Point(72, 19);
			this->labelAuth->Name = L"labelAuth";
			this->labelAuth->Size = System::Drawing::Size(242, 37);
			this->labelAuth->TabIndex = 0;
			this->labelAuth->Text = L"АВТОРИЗАЦІЯ";
			this->labelAuth->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textLog
			// 
			this->textLog->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textLog->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textLog->Location = System::Drawing::Point(175, 126);
			this->textLog->Name = L"textLog";
			this->textLog->Size = System::Drawing::Size(153, 35);
			this->textLog->TabIndex = 1;
			// 
			// textPass
			// 
			this->textPass->BackColor = System::Drawing::SystemColors::ControlDark;
			this->textPass->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textPass->Location = System::Drawing::Point(175, 223);
			this->textPass->Name = L"textPass";
			this->textPass->Size = System::Drawing::Size(153, 35);
			this->textPass->TabIndex = 4;
			this->textPass->UseSystemPasswordChar = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(48, 92);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(90, 85);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(31, 194);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(125, 80);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// buttonLog
			// 
			this->buttonLog->BackColor = System::Drawing::SystemColors::ControlDark;
			this->buttonLog->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonLog->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->buttonLog->FlatAppearance->BorderSize = 0;
			this->buttonLog->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonLog->Font = (gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonLog->Location = System::Drawing::Point(122, 386);
			this->buttonLog->Name = L"buttonLog";
			this->buttonLog->Size = System::Drawing::Size(152, 59);
			this->buttonLog->TabIndex = 7;
			this->buttonLog->Text = L"УВІЙТИ";
			this->buttonLog->UseVisualStyleBackColor = false;
			this->buttonLog->Click += gcnew System::EventHandler(this, &authForm::buttonLog_Click);
			// 
			// buttonReg
			// 
			this->buttonReg->FlatAppearance->BorderSize = 0;
			this->buttonReg->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonReg->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonReg->Location = System::Drawing::Point(120, 318);
			this->buttonReg->Name = L"buttonReg";
			this->buttonReg->Size = System::Drawing::Size(154, 45);
			this->buttonReg->TabIndex = 8;
			this->buttonReg->Text = L"Створити";
			this->buttonReg->UseVisualStyleBackColor = true;
			this->buttonReg->Click += gcnew System::EventHandler(this, &authForm::buttonReg_Click);
			// 
			// authForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(383, 486);
			this->Controls->Add(this->buttonReg);
			this->Controls->Add(this->buttonLog);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textPass);
			this->Controls->Add(this->textLog);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"authForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Авторизація";
			this->Load += gcnew System::EventHandler(this, &authForm::authForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void authForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonLog_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonReg_Click(System::Object^ sender, System::EventArgs^ e);
};
}
