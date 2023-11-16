#pragma once

namespace Stock_Analysis_v2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormHelp
	/// </summary>
	public ref class FormHelp : public System::Windows::Forms::Form
	{
	public:
		FormHelp(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormHelp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelSignature;
	protected:

	private: System::Windows::Forms::Label^ labelTip1;
	private: System::Windows::Forms::Button^ buttonFakeDataGridView;


	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelSignature = (gcnew System::Windows::Forms::Label());
			this->labelTip1 = (gcnew System::Windows::Forms::Label());
			this->buttonFakeDataGridView = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelSignature
			// 
			this->labelSignature->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->labelSignature->AutoSize = true;
			this->labelSignature->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSignature->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->labelSignature->Location = System::Drawing::Point(169, 180);
			this->labelSignature->Name = L"labelSignature";
			this->labelSignature->Size = System::Drawing::Size(81, 16);
			this->labelSignature->TabIndex = 1;
			this->labelSignature->Text = L"Parker Jones";
			// 
			// labelTip1
			// 
			this->labelTip1->AutoSize = true;
			this->labelTip1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTip1->Location = System::Drawing::Point(12, 9);
			this->labelTip1->Name = L"labelTip1";
			this->labelTip1->Size = System::Drawing::Size(236, 80);
			this->labelTip1->TabIndex = 2;
			this->labelTip1->Text = L"1. Click and drag over the chart\r\n    to view an area of interest\r\n\r\n2. Use      "
				L"                         button\r\n    to open a table of candlestick values";
			// 
			// buttonFakeDataGridView
			// 
			this->buttonFakeDataGridView->Enabled = false;
			this->buttonFakeDataGridView->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonFakeDataGridView->Location = System::Drawing::Point(57, 55);
			this->buttonFakeDataGridView->Name = L"buttonFakeDataGridView";
			this->buttonFakeDataGridView->Size = System::Drawing::Size(86, 20);
			this->buttonFakeDataGridView->TabIndex = 3;
			this->buttonFakeDataGridView->Text = L"Open DataGrid...";
			this->buttonFakeDataGridView->UseVisualStyleBackColor = false;
			// 
			// FormHelp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(262, 205);
			this->Controls->Add(this->buttonFakeDataGridView);
			this->Controls->Add(this->labelTip1);
			this->Controls->Add(this->labelSignature);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(278, 244);
			this->MinimumSize = System::Drawing::Size(278, 244);
			this->Name = L"FormHelp";
			this->ShowIcon = false;
			this->Text = L"About";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
