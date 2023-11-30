#pragma once
#include <iostream>
#include "Candlestick.h"
#include <fstream>
#include <string>
#include <cliext/vector>
#include "FormChart.h"

namespace Stock_Analysis_v3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class FormControls : public System::Windows::Forms::Form
	{
	public:
		FormControls(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormControls()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ buttonOpenFile;
	private: System::Windows::Forms::DateTimePicker^ dtpStart;
	private: System::Windows::Forms::Label^ labelStart;
	private: System::Windows::Forms::DateTimePicker^ dtpEnd;
	private: System::Windows::Forms::Label^ labelEnd;
	private: System::Windows::Forms::CheckBox^ checkBoxDates;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonOpenFile = (gcnew System::Windows::Forms::Button());
			this->dtpStart = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelStart = (gcnew System::Windows::Forms::Label());
			this->dtpEnd = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelEnd = (gcnew System::Windows::Forms::Label());
			this->checkBoxDates = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// buttonOpenFile
			// 
			this->buttonOpenFile->Location = System::Drawing::Point(12, 10);
			this->buttonOpenFile->Name = L"buttonOpenFile";
			this->buttonOpenFile->Size = System::Drawing::Size(258, 23);
			this->buttonOpenFile->TabIndex = 0;
			this->buttonOpenFile->Text = L"Select File(s)...";
			this->buttonOpenFile->UseVisualStyleBackColor = true;
			this->buttonOpenFile->Click += gcnew System::EventHandler(this, &FormControls::buttonOpenFile_Click);
			// 
			// dtpStart
			// 
			this->dtpStart->Enabled = false;
			this->dtpStart->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpStart->Location = System::Drawing::Point(37, 62);
			this->dtpStart->MaxDate = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			this->dtpStart->MinDate = System::DateTime(2011, 8, 1, 0, 0, 0, 0);
			this->dtpStart->Name = L"dtpStart";
			this->dtpStart->Size = System::Drawing::Size(96, 20);
			this->dtpStart->TabIndex = 2;
			this->dtpStart->Value = System::DateTime(2022, 8, 1, 0, 0, 0, 0);
			// 
			// labelStart
			// 
			this->labelStart->AutoSize = true;
			this->labelStart->Location = System::Drawing::Point(5, 66);
			this->labelStart->Name = L"labelStart";
			this->labelStart->Size = System::Drawing::Size(32, 13);
			this->labelStart->TabIndex = 3;
			this->labelStart->Text = L"Start:";
			// 
			// dtpEnd
			// 
			this->dtpEnd->Enabled = false;
			this->dtpEnd->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpEnd->Location = System::Drawing::Point(174, 62);
			this->dtpEnd->MaxDate = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			this->dtpEnd->MinDate = System::DateTime(2011, 8, 1, 0, 0, 0, 0);
			this->dtpEnd->Name = L"dtpEnd";
			this->dtpEnd->Size = System::Drawing::Size(96, 20);
			this->dtpEnd->TabIndex = 4;
			this->dtpEnd->Value = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			// 
			// labelEnd
			// 
			this->labelEnd->AutoSize = true;
			this->labelEnd->Location = System::Drawing::Point(145, 66);
			this->labelEnd->Name = L"labelEnd";
			this->labelEnd->Size = System::Drawing::Size(29, 13);
			this->labelEnd->TabIndex = 5;
			this->labelEnd->Text = L"End:";
			// 
			// checkBoxDates
			// 
			this->checkBoxDates->AutoSize = true;
			this->checkBoxDates->Location = System::Drawing::Point(12, 39);
			this->checkBoxDates->Name = L"checkBoxDates";
			this->checkBoxDates->Size = System::Drawing::Size(92, 17);
			this->checkBoxDates->TabIndex = 9;
			this->checkBoxDates->Text = L"Specify Dates";
			this->checkBoxDates->UseVisualStyleBackColor = true;
			this->checkBoxDates->CheckedChanged += gcnew System::EventHandler(this, &FormControls::checkBoxDates_CheckedChanged);
			// 
			// FormControls
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 96);
			this->Controls->Add(this->checkBoxDates);
			this->Controls->Add(this->labelEnd);
			this->Controls->Add(this->dtpEnd);
			this->Controls->Add(this->labelStart);
			this->Controls->Add(this->dtpStart);
			this->Controls->Add(this->buttonOpenFile);
			this->Name = L"FormControls";
			this->Text = L"Stock Analysis";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void buttonOpenFile_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create OpenFileDialog
		OpenFileDialog^ ofd = gcnew OpenFileDialog();

		// Change OpenFileDialog properties
		ofd->InitialDirectory = "c:\\";
		ofd->Filter = "All Data|*.csv|Daily Data|*Day.csv|Weekly Data|*Week.csv|Monthly Data|*Month.csv";
		ofd->RestoreDirectory = true;
		ofd->Multiselect = true;

		// Show OpenFileDialog and open chart(s)
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			array<array<String^>^>^ stockDataStrings = gcnew array<array<String^>^>(ofd->FileNames->Length);
			array<String^>^ intervalStrings = gcnew array<String^>(ofd->FileNames->Length);
			array<FormChart^>^ formChartForms = gcnew array<FormChart^>(ofd->FileNames->Length);

			for (int i = 0; i < ofd->FileNames->Length; ++i) {
				if (File::Exists(ofd->FileNames[i])) {
					// Read from selected file
					stockDataStrings[i] = File::ReadAllLines(ofd->FileNames[i]);
					intervalStrings[i] = ofd->FileNames[i]->Split('-')[1];
					
					// Display data in chart(s)
					if (checkBoxDates->Checked) {
						formChartForms[i] = gcnew FormChart(stockDataStrings[i], intervalStrings[i], dtpStart->Value, dtpEnd->Value);
						formChartForms[i]->Show();
					}
					else {
						formChartForms[i] = gcnew FormChart(stockDataStrings[i], intervalStrings[i]);
						formChartForms[i]->Show();
					}
					
				}
				else {
					// Show "That file doesn't exist." message if the file does not exist
					MessageBox::Show(ofd->FileNames[i] + " doesn't exist.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			
		} else {
			// Show "No file selected." message if no file is selected
			MessageBox::Show("No file selected.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void checkBoxDates_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		// Toggle the availability of the date time picker controls
		if (checkBoxDates->Checked) {
			dtpStart->Enabled = true;
			dtpEnd->Enabled = true;
		}
		else {
			dtpStart->Enabled = false;
			dtpEnd->Enabled = false;
		}
	}
};
};