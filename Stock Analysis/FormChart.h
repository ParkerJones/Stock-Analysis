#pragma once
#include <iostream>
#include "Candlestick.h"
#include <fstream>
#include <string>
#include <cliext/vector>
namespace Stock_Analysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for FormChart
	/// </summary>
	public ref class FormChart : public System::Windows::Forms::Form
	{
	public:
		FormChart(void)
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
		~FormChart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonOpenFile;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartStock;
	private: System::Windows::Forms::DateTimePicker^ dtpStart;
	private: System::Windows::Forms::Label^ labelStart;
	private: System::Windows::Forms::DateTimePicker^ dtpEnd;
	private: System::Windows::Forms::Label^ labelEnd;
	private: System::Windows::Forms::Button^ buttonDataGridView;


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->buttonOpenFile = (gcnew System::Windows::Forms::Button());
			this->chartStock = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dtpStart = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelStart = (gcnew System::Windows::Forms::Label());
			this->dtpEnd = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelEnd = (gcnew System::Windows::Forms::Label());
			this->buttonDataGridView = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStock))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonOpenFile
			// 
			this->buttonOpenFile->Location = System::Drawing::Point(12, 12);
			this->buttonOpenFile->Name = L"buttonOpenFile";
			this->buttonOpenFile->Size = System::Drawing::Size(75, 23);
			this->buttonOpenFile->TabIndex = 0;
			this->buttonOpenFile->Text = L"Select File...";
			this->buttonOpenFile->UseVisualStyleBackColor = true;
			this->buttonOpenFile->Click += gcnew System::EventHandler(this, &FormChart::buttonOpenFile_Click);
			// 
			// chartStock
			// 
			this->chartStock->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->Name = L"chartAreaStock";
			this->chartStock->ChartAreas->Add(chartArea1);
			this->chartStock->Location = System::Drawing::Point(0, 41);
			this->chartStock->Name = L"chartStock";
			series1->ChartArea = L"chartAreaStock";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->Name = L"seriesPrice";
			series1->YValuesPerPoint = 4;
			series2->ChartArea = L"chartAreaStock";
			series2->Name = L"seriesVolume";
			series2->YAxisType = System::Windows::Forms::DataVisualization::Charting::AxisType::Secondary;
			this->chartStock->Series->Add(series1);
			this->chartStock->Series->Add(series2);
			this->chartStock->Size = System::Drawing::Size(674, 343);
			this->chartStock->TabIndex = 1;
			this->chartStock->Text = L"Stock Chart";
			// 
			// dtpStart
			// 
			this->dtpStart->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpStart->Location = System::Drawing::Point(152, 13);
			this->dtpStart->MaxDate = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			this->dtpStart->MinDate = System::DateTime(2021, 1, 1, 0, 0, 0, 0);
			this->dtpStart->Name = L"dtpStart";
			this->dtpStart->Size = System::Drawing::Size(96, 20);
			this->dtpStart->TabIndex = 2;
			this->dtpStart->Value = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			// 
			// labelStart
			// 
			this->labelStart->AutoSize = true;
			this->labelStart->Location = System::Drawing::Point(120, 17);
			this->labelStart->Name = L"labelStart";
			this->labelStart->Size = System::Drawing::Size(32, 13);
			this->labelStart->TabIndex = 3;
			this->labelStart->Text = L"Start:";
			// 
			// dtpEnd
			// 
			this->dtpEnd->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpEnd->Location = System::Drawing::Point(289, 13);
			this->dtpEnd->MaxDate = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			this->dtpEnd->MinDate = System::DateTime(2021, 1, 1, 0, 0, 0, 0);
			this->dtpEnd->Name = L"dtpEnd";
			this->dtpEnd->Size = System::Drawing::Size(96, 20);
			this->dtpEnd->TabIndex = 4;
			this->dtpEnd->Value = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			// 
			// labelEnd
			// 
			this->labelEnd->AutoSize = true;
			this->labelEnd->Location = System::Drawing::Point(260, 17);
			this->labelEnd->Name = L"labelEnd";
			this->labelEnd->Size = System::Drawing::Size(29, 13);
			this->labelEnd->TabIndex = 5;
			this->labelEnd->Text = L"End:";
			// 
			// buttonDataGridView
			// 
			this->buttonDataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDataGridView->Location = System::Drawing::Point(533, 12);
			this->buttonDataGridView->Name = L"buttonDataGridView";
			this->buttonDataGridView->Size = System::Drawing::Size(108, 23);
			this->buttonDataGridView->TabIndex = 6;
			this->buttonDataGridView->Text = L"Open DataGrid...";
			this->buttonDataGridView->UseVisualStyleBackColor = true;
			// 
			// FormChart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(674, 384);
			this->Controls->Add(this->buttonDataGridView);
			this->Controls->Add(this->labelEnd);
			this->Controls->Add(this->dtpEnd);
			this->Controls->Add(this->labelStart);
			this->Controls->Add(this->dtpStart);
			this->Controls->Add(this->chartStock);
			this->Controls->Add(this->buttonOpenFile);
			this->Name = L"FormChart";
			this->Text = L"Stock Analysis";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStock))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	protected: cliext::vector<Candlestick^> GetStockData(array<String^>^ data) {
		for (int i = 1; i < data->Length; ++i)
		{
			// Initialize Candlestick vector
			cliext::vector<Candlestick^> allCandlesticks;
			// TODO: CREATE CHECK FOR DATETIME PICKERS!!!
			// UPDATE: Check for datetime pickers will create a smaller vector
			// with only the candlesticks that are being displayed
			// 
			// TODO: MAKE THIS SOMETHING LIKE A UpdateChart() METHOD
			// UPDATE: NOT A UpdateChart() METHOD. This should only be called-
			// - when the file is selected/

			// Parse data
			DateTime^ date = DateTime::Parse((data[i]->Split(',')[2] + data[i]->Split(',')[3])->Replace("\"", ""));
			double high = Double::Parse(data[i]->Split(',')[5]);
			double low = Double::Parse(data[i]->Split(',')[6]);
			double open = Double::Parse(data[i]->Split(',')[4]);
			double close = Double::Parse(data[i]->Split(',')[7]);
			long volume = Double::Parse(data[i]->Split(',')[8]);

			// Populate candlestick vector
			Candlestick^ newCandlestick = gcnew Candlestick(date, high, low, open, close, volume);
			allCandlesticks.push_back(newCandlestick);

			return allCandlesticks;
		}
	}

	protected: cliext::vector<Candlestick^> FilterStockData(cliext::vector<Candlestick^> allCandlesticks) {
		// Check if argument vector is empty
		if (allCandlesticks.empty()) {
			cliext::vector<Candlestick^> empty;
			return empty;
		} else {
			// Create filtered candlesticks
			cliext::vector<Candlestick^> displayedCandlesticks;

			// Add candlesticks to filter depending on DateTimePicker values
			for (int i = 0; i < allCandlesticks.size(); ++i) {
				if (dtpStart->Value <= DateTime::FromOADate(allCandlesticks[i]->date->ToOADate()) && dtpEnd->Value >= DateTime::FromOADate(allCandlesticks[i]->date->ToOADate())) {
					displayedCandlesticks.push_back(allCandlesticks[i]);
				}
			}
			return displayedCandlesticks;
		}
	}
			 // TODO: FINISH THIS!!!!
	protected: void DisplayStockData(cliext::vector<Candlestick^> displayedCandlesticks) {
		for (int i = 0; i < displayedCandlesticks.size(); i++) {
			// Add to price series
			chartStock->Series["seriesPrice"]->Points->AddXY(
				displayedCandlesticks[i]->date,
				displayedCandlesticks[i]->low,
				displayedCandlesticks[i]->high,
				displayedCandlesticks[i]->open,
				displayedCandlesticks[i]->close);
			// Add to volume series
			chartStock->Series["seriesVolume"]->Points->AddXY(
				displayedCandlesticks[i]->date,
				displayedCandlesticks[i]->volume
			);
		}
	}
	
	private: System::Void buttonOpenFile_Click(System::Object^ sender, System::EventArgs^ e) {
		
		// Create OpenFileDialog
		OpenFileDialog^ ofd = gcnew OpenFileDialog();

		// Change OpenFileDialog properties
		ofd->InitialDirectory = "c:\\";
		ofd->Filter = "Comma-separated Values (*.csv)|*.csv";
		ofd->RestoreDirectory = true;

		// Show OpenFileDialog and 
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			if (File::Exists(ofd->FileName)) {
				
				// Read from selected file
				array<String^>^ tickerData = File::ReadAllLines(ofd->FileName);

				// Load stock data
				// CHART SHOULD ALSO UPDATE
				GetStockData(tickerData);
			} else {
				// Show "That file doesn't exist." message if the file does not exist
				MessageBox::Show("That file doesn't exist.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		} else {
			// Show "No file selected." message if no file is selected
			MessageBox::Show("No file selected.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

};
};