#pragma once
#include <cliext/vector>
#include "Candlestick.h"

namespace Stock_Analysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormDataGridView
	/// </summary>
	public ref class FormDataGridView : public System::Windows::Forms::Form
	{
	public:
		FormDataGridView(void)
		{
			InitializeComponent();

			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormDataGridView()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^ dgvStock;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnDate;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnOpen;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnClose;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnHigh;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnLow;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ columnVolume;







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
			this->dgvStock = (gcnew System::Windows::Forms::DataGridView());
			this->columnDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnOpen = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnClose = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnHigh = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnLow = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnVolume = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStock))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvStock
			// 
			this->dgvStock->AllowUserToAddRows = false;
			this->dgvStock->AllowUserToDeleteRows = false;
			this->dgvStock->AllowUserToOrderColumns = true;
			this->dgvStock->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvStock->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->columnDate,
					this->columnOpen, this->columnClose, this->columnHigh, this->columnLow, this->columnVolume
			});
			this->dgvStock->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvStock->Location = System::Drawing::Point(0, 0);
			this->dgvStock->Name = L"dgvStock";
			this->dgvStock->ReadOnly = true;
			this->dgvStock->Size = System::Drawing::Size(884, 461);
			this->dgvStock->TabIndex = 0;
			// 
			// columnDate
			// 
			this->columnDate->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->columnDate->HeaderText = L"Date";
			this->columnDate->Name = L"columnDate";
			this->columnDate->ReadOnly = true;
			// 
			// columnOpen
			// 
			this->columnOpen->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->columnOpen->HeaderText = L"Open";
			this->columnOpen->Name = L"columnOpen";
			this->columnOpen->ReadOnly = true;
			// 
			// columnClose
			// 
			this->columnClose->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->columnClose->HeaderText = L"Close";
			this->columnClose->Name = L"columnClose";
			this->columnClose->ReadOnly = true;
			// 
			// columnHigh
			// 
			this->columnHigh->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->columnHigh->HeaderText = L"High";
			this->columnHigh->Name = L"columnHigh";
			this->columnHigh->ReadOnly = true;
			// 
			// columnLow
			// 
			this->columnLow->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->columnLow->HeaderText = L"Low";
			this->columnLow->Name = L"columnLow";
			this->columnLow->ReadOnly = true;
			// 
			// columnVolume
			// 
			this->columnVolume->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->columnVolume->HeaderText = L"Volume";
			this->columnVolume->Name = L"columnVolume";
			this->columnVolume->ReadOnly = true;
			// 
			// FormDataGridView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 461);
			this->Controls->Add(this->dgvStock);
			this->MinimumSize = System::Drawing::Size(900, 500);
			this->Name = L"FormDataGridView";
			this->Text = L"DataGridView";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvStock))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	};
}
