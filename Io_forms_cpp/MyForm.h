#pragma once
#include "room.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include "list.h"
#include "exam.h"



namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int r = 0;int ex=0;
	std::ifstream iif;
	std::ifstream oof;
	List <room> rmas;
	List <exam> exmas;

	std::string SysToStr(String^ a) {
		return msclr::interop::marshal_as<std::string>(a);
	}

	String^ StdToSys(std::string a) {
		return msclr::interop::marshal_as<String^>(a);
	}

	std::string checktime(int days, int mons, int hours, int mins) {
		if (days < 1)  return "Дней должно быть больше нуля";
		if (mons < 1)  return "Месяцев должно быть больше нуля";
		if (mons < 8) {
			if (mons % 2 == 0 && days > 30) return "В этом месяце не может быть больше 30 дней";
			if (mons % 2 == 1 && days > 31) return "В этом месяце не может быть больше 31 дня";
		}
		if (mons > 7) {
			if (mons % 2 == 1 && days > 30) return "В этом месяце не может быть больше 30 дней";
			if (mons % 2 == 0 && days > 31) return "В этом месяце не может быть больше 31 дня";
		}
		if (mons == 2 && days >= 30) return "В феврале не может быть больше 29 дней";
		if (mons > 12) return "Месяцев не может быть больше 12";
		if (mins > 60) return "Минут не может быть больше 60";
		if (hours > 24) return "Часов не может быть больше 24";
		return "";
	}


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			iif.open("rooms.txt");
			oof.open("exam.txt");
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			iif.close();
			oof.close();
		}
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	protected:
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown5;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown6;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown7;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::Button^  button4;

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
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown6 = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown7 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown6))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown7))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(12, 34);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(58, 20);
			this->numericUpDown1->TabIndex = 0;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(76, 34);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(58, 20);
			this->numericUpDown2->TabIndex = 1;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(140, 34);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(58, 20);
			this->numericUpDown3->TabIndex = 2;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(204, 34);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(58, 20);
			this->numericUpDown4->TabIndex = 3;
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(13, 61);
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(58, 20);
			this->numericUpDown5->TabIndex = 4;
			// 
			// numericUpDown6
			// 
			this->numericUpDown6->Location = System::Drawing::Point(74, 61);
			this->numericUpDown6->Name = L"numericUpDown6";
			this->numericUpDown6->Size = System::Drawing::Size(58, 20);
			this->numericUpDown6->TabIndex = 5;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(10, 19);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(130, 17);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"Аудитория свободна";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->numericUpDown6);
			this->groupBox1->Controls->Add(this->numericUpDown5);
			this->groupBox1->Location = System::Drawing::Point(2, 105);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(155, 93);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Аудитория";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Номер аудитории";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(201, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Минуты";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(137, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Часы";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(73, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Месяц";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(34, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"День";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 204);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 25);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Ввод аудитории";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 232);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 14;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(154, 209);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(75, 17);
			this->checkBox2->TabIndex = 15;
			this->checkBox2->Text = L"Из файла";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(365, 195);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(134, 42);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Свободная аудитория по времени";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(226, 204);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(133, 25);
			this->button3->TabIndex = 17;
			this->button3->Text = L"Ввод экзамена";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// numericUpDown7
			// 
			this->numericUpDown7->Location = System::Drawing::Point(6, 34);
			this->numericUpDown7->Name = L"numericUpDown7";
			this->numericUpDown7->Size = System::Drawing::Size(80, 20);
			this->numericUpDown7->TabIndex = 9;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(98, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(81, 20);
			this->textBox1->TabIndex = 18;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(6, 93);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(116, 20);
			this->textBox2->TabIndex = 19;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->numericUpDown7);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Location = System::Drawing::Point(174, 67);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(185, 131);
			this->groupBox2->TabIndex = 20;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Экзамен группы";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(95, 17);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(70, 13);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Дисциплина";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 77);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(116, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"ФИО Преподавателя";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 16);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(80, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Номер группы";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(511, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(389, 232);
			this->dataGridView1->TabIndex = 21;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"№";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 40;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Дисциплина";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Начало";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Преподаватель";
			this->Column4->Name = L"Column4";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(376, 132);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(122, 47);
			this->button4->TabIndex = 22;
			this->button4->Text = L"Расписание группы";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(909, 261);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown6))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown7))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		room p_room;
		int num, d, m, h, min;
		bool free;
		label6->Text = "";
		try{
		if (checkBox2->Checked) {
			if (iif.eof()) {	
				iif.close();
				throw "В файле больше нет данных";
			}
			iif >> num >> d >> m >> h >> min >> free;
			r++;
		}
		else {
			num = (int)numericUpDown5->Value * 100 + (int)numericUpDown6->Value;
			d = (int)numericUpDown1->Value;
			m = (int)numericUpDown2->Value;
			h = (int)numericUpDown3->Value;
			min = (int)numericUpDown4->Value;
			free = checkBox1->Checked;
		}
			if (checktime(d, m, h, min) == "") {
				for (int i = 0; i < rmas.size(); i++) {
					if (rmas.get(i).getd() == d && rmas.get(i).geth() == h && rmas.get(i).getmin() == min && rmas.get(i).getm() == m && rmas.get(i).getnum() == num) throw "Статус данной аудитории в указанный момент времени был введен ранее";
				}
				p_room.set(d, m, h, min, num, free);
				rmas.add(p_room, rmas.size());
			}
			else throw checktime(d, m, h, min);
		}
		catch (std::string str) {
			label6->Text = StdToSys(str);
		}
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	room p_room;
	int d, m, h, min, num = 0;
	bool free = 1;
	char digit[4];
	d = (int)numericUpDown1->Value;
	m = (int)numericUpDown2->Value;
	h = (int)numericUpDown3->Value;
	min = (int)numericUpDown4->Value;
	try {
		if (checktime(d, m, h, min) == "") {
			for (int i = 0; i < rmas.size(); i++) {
				if (rmas.get(i).getd() == d && rmas.get(i).geth() == h && rmas.get(i).getmin() == min && rmas.get(i).getm() == m && rmas.get(i).getfree() == 1) { sprintf(digit, "%d", rmas.get(i).getnum()); throw digit; }
			}
			throw "В это время нет свободных аудиторий";
		}
		else throw checktime(d, m, h, min);
	}
	catch (std::string str) {
		
		label6->Text = StdToSys(str);
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	exam p_exam;
	int num, d, m, h, min;
	std::string dis;
	std::string fio;
	std::string n;
	std::string f;
	std::string o;
	label6->Text = "";
	try {
		if (checkBox2->Checked) {
			if (iif.eof()) {
				iif.close();
				throw "В файле больше нет данных";
			}
			oof >> num >> d >> m >> h >> min >> f >> n >> o >> dis;
			fio = f + " " + n + " " + o;
			for (int i = 0; i < dis.length() - 1; i++) if (dis[i] == '_') dis[i] = ' ';
			ex++;
			if (num > 99 || num < 0) throw "Номер группы в этой строке выходит за допустимые границы";
		}
		else {
			if (SysToStr(textBox2->Text)=="") throw "Заполните графу ФИО преподавателя";
			if (SysToStr(textBox1->Text) == "") throw "Заполните графу дисциплина";
			fio = SysToStr(textBox2->Text);
			dis = SysToStr(textBox1->Text);
			num = (int)numericUpDown7->Value;
			d = (int)numericUpDown1->Value;
			m = (int)numericUpDown2->Value;
			h = (int)numericUpDown3->Value;
			min = (int)numericUpDown4->Value;
		}
		
		if (checktime(d, m, h, min) == "") {
			for (int i = 0; i < exmas.size(); i++) {
				if (exmas.get(i).getd() == d  && exmas.get(i).getm() == m && exmas.get(i).getnum() == num)
					if (exmas.get(i).geth() > h && exmas.get(i).geth() - h < 2) {
						throw "В это время у этой группы уже идет экзамен";
					}
					else {
						if (exmas.get(i).geth() == h && exmas.get(i).getmin() < min) throw "В это время у этой группы уже идет экзамен";
						else if (exmas.get(i).geth() < h && h - exmas.get(i).geth() < 2) throw"В это время у этой группы уже идет экзамен";
						else if (exmas.get(i).geth() < h&&h - exmas.get(i).geth() == 2 && min < exmas.get(i).getmin()) throw "В это время у этой группы уже идет экзамен";
					}
			}
				p_exam.set(h, min, m, d, num, dis, fio);
			exmas.add(p_exam, rmas.size());
		}
		else throw checktime(d, m, h, min);
	}
	catch (std::string str) {
		label6->Text = StdToSys(str);
	}
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	int num = (int)numericUpDown7->Value;
	for (int i = 0; i < exmas.size(); i++) {
		if (num == exmas.get(i).getnum()) {
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(num);
			dataGridView1->Rows[i]->Cells[1]->Value = StdToSys(exmas.get(i).getdis());
			dataGridView1->Rows[i]->Cells[2]->Value = Convert::ToString(exmas.get(i).getd()) + "." + Convert::ToString(exmas.get(i).getm()) + " " + Convert::ToString(exmas.get(i).geth()) + ":" + Convert::ToString(exmas.get(i).getmin());
			dataGridView1->Rows[i]->Cells[3]->Value = StdToSys(exmas.get(i).getfio());
		}
	}
}
};
}
