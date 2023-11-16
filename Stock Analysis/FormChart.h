#pragma once
#include <iostream>
#include "Candlestick.h"
#include <fstream>
#include <string>
#include <cliext/vector>
#include "FormHelp.h"

namespace Stock_Analysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class FormChart : public System::Windows::Forms::Form
	{
		// Instantiate other forms so they exist but are not displayed
		FormHelp^ formHelp = gcnew FormHelp();
	public:
		FormChart(void)
		{
			InitializeComponent();

			// Add zoomability to chart areas
			chartStock->ChartAreas["chartAreaPrice"]->AxisX->ScaleView->Zoomable = true;
			chartStock->ChartAreas["chartAreaPrice"]->CursorX->AutoScroll = true;
			chartStock->ChartAreas["chartAreaPrice"]->CursorX->IsUserSelectionEnabled = true;
			chartStock->ChartAreas["chartAreaVolume"]->AxisX->ScaleView->Zoomable = true;
			chartStock->ChartAreas["chartAreaVolume"]->CursorX->AutoScroll = true;
			chartStock->ChartAreas["chartAreaVolume"]->CursorX->IsUserSelectionEnabled = true;
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
	private: System::Windows::Forms::CheckBox^ checkBoxVolume;
	private: System::Windows::Forms::Button^ buttonHelp;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->buttonOpenFile = (gcnew System::Windows::Forms::Button());
			this->chartStock = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dtpStart = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelStart = (gcnew System::Windows::Forms::Label());
			this->dtpEnd = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelEnd = (gcnew System::Windows::Forms::Label());
			this->buttonDataGridView = (gcnew System::Windows::Forms::Button());
			this->checkBoxVolume = (gcnew System::Windows::Forms::CheckBox());
			this->buttonHelp = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStock))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonOpenFile
			// 
			this->buttonOpenFile->Location = System::Drawing::Point(49, 10);
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
			chartArea1->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea1->AxisX->MinorTickMark->Enabled = true;
			chartArea1->AxisX->MinorTickMark->LineColor = System::Drawing::Color::DimGray;
			chartArea1->AxisX->MinorTickMark->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea1->Name = L"chartAreaPrice";
			chartArea2->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea2->AxisX->MinorTickMark->LineColor = System::Drawing::Color::DimGray;
			chartArea2->AxisX->MinorTickMark->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea2->Name = L"chartAreaVolume";
			chartArea2->Visible = false;
			this->chartStock->ChartAreas->Add(chartArea1);
			this->chartStock->ChartAreas->Add(chartArea2);
			this->chartStock->Location = System::Drawing::Point(0, 41);
			this->chartStock->Name = L"chartStock";
			series1->ChartArea = L"chartAreaPrice";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->Color = System::Drawing::Color::Black;
			series1->CustomProperties = L"PriceUpColor=Green, PointWidth=0.5, PriceDownColor=Red";
			series1->Name = L"seriesPrice";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series1->YValuesPerPoint = 4;
			series2->ChartArea = L"chartAreaVolume";
			series2->CustomProperties = L"PointWidth=0.5";
			series2->Name = L"seriesVolume";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			this->chartStock->Series->Add(series1);
			this->chartStock->Series->Add(series2);
			this->chartStock->Size = System::Drawing::Size(884, 420);
			this->chartStock->TabIndex = 1;
			this->chartStock->Text = L"Stock Chart";
			// 
			// dtpStart
			// 
			this->dtpStart->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpStart->Location = System::Drawing::Point(189, 11);
			this->dtpStart->MaxDate = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			this->dtpStart->MinDate = System::DateTime(2011, 8, 1, 0, 0, 0, 0);
			this->dtpStart->Name = L"dtpStart";
			this->dtpStart->Size = System::Drawing::Size(96, 20);
			this->dtpStart->TabIndex = 2;
			this->dtpStart->Value = System::DateTime(2022, 8, 1, 0, 0, 0, 0);
			this->dtpStart->ValueChanged += gcnew System::EventHandler(this, &FormChart::dtpStart_ValueChanged);
			// 
			// labelStart
			// 
			this->labelStart->AutoSize = true;
			this->labelStart->Location = System::Drawing::Point(157, 15);
			this->labelStart->Name = L"labelStart";
			this->labelStart->Size = System::Drawing::Size(32, 13);
			this->labelStart->TabIndex = 3;
			this->labelStart->Text = L"Start:";
			// 
			// dtpEnd
			// 
			this->dtpEnd->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpEnd->Location = System::Drawing::Point(326, 11);
			this->dtpEnd->MaxDate = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			this->dtpEnd->MinDate = System::DateTime(2011, 8, 1, 0, 0, 0, 0);
			this->dtpEnd->Name = L"dtpEnd";
			this->dtpEnd->Size = System::Drawing::Size(96, 20);
			this->dtpEnd->TabIndex = 4;
			this->dtpEnd->Value = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			this->dtpEnd->ValueChanged += gcnew System::EventHandler(this, &FormChart::dtpEnd_ValueChanged);
			// 
			// labelEnd
			// 
			this->labelEnd->AutoSize = true;
			this->labelEnd->Location = System::Drawing::Point(297, 15);
			this->labelEnd->Name = L"labelEnd";
			this->labelEnd->Size = System::Drawing::Size(29, 13);
			this->labelEnd->TabIndex = 5;
			this->labelEnd->Text = L"End:";
			// 
			// buttonDataGridView
			// 
			this->buttonDataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonDataGridView->Location = System::Drawing::Point(701, 12);
			this->buttonDataGridView->Name = L"buttonDataGridView";
			this->buttonDataGridView->Size = System::Drawing::Size(108, 23);
			this->buttonDataGridView->TabIndex = 6;
			this->buttonDataGridView->Text = L"Open DataGrid...";
			this->buttonDataGridView->UseVisualStyleBackColor = true;
			this->buttonDataGridView->Click += gcnew System::EventHandler(this, &FormChart::buttonDataGridView_Click);
			// 
			// checkBoxVolume
			// 
			this->checkBoxVolume->AutoSize = true;
			this->checkBoxVolume->Location = System::Drawing::Point(458, 14);
			this->checkBoxVolume->Name = L"checkBoxVolume";
			this->checkBoxVolume->Size = System::Drawing::Size(61, 17);
			this->checkBoxVolume->TabIndex = 7;
			this->checkBoxVolume->Text = L"Volume";
			this->checkBoxVolume->UseVisualStyleBackColor = true;
			this->checkBoxVolume->CheckedChanged += gcnew System::EventHandler(this, &FormChart::checkBoxVolume_CheckedChanged);
			// 
			// buttonHelp
			// 
			this->buttonHelp->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->buttonHelp->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonHelp->Location = System::Drawing::Point(12, 8);
			this->buttonHelp->Name = L"buttonHelp";
			this->buttonHelp->Size = System::Drawing::Size(25, 25);
			this->buttonHelp->TabIndex = 8;
			this->buttonHelp->Text = L"\?";
			this->buttonHelp->UseVisualStyleBackColor = true;
			this->buttonHelp->Click += gcnew System::EventHandler(this, &FormChart::buttonHelp_Click);
			// 
			// FormChart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 461);
			this->Controls->Add(this->buttonHelp);
			this->Controls->Add(this->checkBoxVolume);
			this->Controls->Add(this->buttonDataGridView);
			this->Controls->Add(this->labelEnd);
			this->Controls->Add(this->dtpEnd);
			this->Controls->Add(this->labelStart);
			this->Controls->Add(this->dtpStart);
			this->Controls->Add(this->chartStock);
			this->Controls->Add(this->buttonOpenFile);
			this->MinimumSize = System::Drawing::Size(900, 500);
			this->Name = L"FormChart";
			this->Text = L"Stock Analysis";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStock))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	public: cliext::vector<Candlestick^> currentCandlesticksFromFile; // Currently selected candlesticks
	public: cliext::vector<Candlestick^> filteredCandlesticksFromFile; // Currently selected candlesticks congruent with selected DateTimes
	public: String^ gInterval; // Time interval of currently selected candlesticks

	/// <summary>
	/// Returns a vector of Candlestick objects given data in a .csv file
	/// </summary>
	/// <param name="data">Candlestick data from .csv file</param>
	/// <returns>A vector of Candlesticks</returns>
	protected: cliext::vector<Candlestick^> GetStockData(array<String^>^ data) {

		// Initialize Candlestick vector
		cliext::vector<Candlestick^> allCandlesticks;

		// Empty master Candlestick vector
		currentCandlesticksFromFile.clear();

		for (int i = 1; i < data->Length; ++i)
		{

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
			currentCandlesticksFromFile.push_back(newCandlestick);
		}
		
		return allCandlesticks;
	}

	/// <summary>
	/// Filters a vector of Candlestick objects depending on DateTimePicker values
	/// </summary>
	/// <param name="allCandlesticks">Candlestick vector to be filtered</param>
	/// <returns>A filtered Candlestick vector</returns>
	protected: cliext::vector<Candlestick^> FilterStockData(cliext::vector<Candlestick^> allCandlesticks) {
		// Check if argument vector is empty
		if (allCandlesticks.empty()) {
			cliext::vector<Candlestick^> empty;
			return empty;
		} else {
			// Create filtered candlesticks and clear master vector
			cliext::vector<Candlestick^> displayedCandlesticks;
			filteredCandlesticksFromFile.clear();

			// Add candlesticks to filter depending on DateTimePicker values
			for (int i = 0; i < allCandlesticks.size(); ++i) {
				if (dtpStart->Value <= DateTime::FromOADate(allCandlesticks[i]->date->ToOADate()) && dtpEnd->Value >= DateTime::FromOADate(allCandlesticks[i]->date->ToOADate())) {
					displayedCandlesticks.push_back(allCandlesticks[i]);
					filteredCandlesticksFromFile.push_back(allCandlesticks[i]);
				}
			}
			
			return displayedCandlesticks;
		}
	}

	/// <summary>
	/// Displays Candlestick values on chart
	/// </summary>
	/// <param name="displayedCandlesticks">Candlesticks to be displayed</param>
	/// <param name="interval">Time interval represented as a string</param>
	protected: void DisplayStockData(cliext::vector<Candlestick^> displayedCandlesticks, String^ interval) {
		// Clear series
		chartStock->Series["seriesPrice"]->Points->Clear();
		chartStock->Series["seriesVolume"]->Points->Clear();

		double highestPrice = 0;
		double lowestPrice = 99999;
		long highestVolume = 0;
		long lowestVolume = long::MaxValue;

		for (int i = 0; i < displayedCandlesticks.size(); ++i) {
			// Decide chart bounds
			highestPrice = (displayedCandlesticks[i]->high > highestPrice) ? displayedCandlesticks[i]->high : highestPrice;
			lowestPrice = (displayedCandlesticks[i]->low < lowestPrice) ? displayedCandlesticks[i]->low : lowestPrice;
			highestVolume = (displayedCandlesticks[i]->volume > highestVolume) ? displayedCandlesticks[i]->volume : highestVolume;
			lowestVolume = (displayedCandlesticks[i]->volume < lowestVolume) ? displayedCandlesticks[i]->volume : lowestVolume;

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

		// Assign axis bounds
		chartStock->ChartAreas["chartAreaPrice"]->AxisY->Maximum = Math::Round(highestPrice + 2, 3);
		chartStock->ChartAreas["chartAreaPrice"]->AxisY->Minimum = Math::Round(lowestPrice - 2, 3);

		// Assign axis interval
		if (interval == "Month.csv") {
			chartStock->ChartAreas["chartAreaPrice"]->AxisX->IntervalType = Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Months;
			chartStock->ChartAreas["chartAreaPrice"]->AxisX->Interval = 1;
			chartStock->ChartAreas["chartAreaVolume"]->AxisX->IntervalType = Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Months;
			chartStock->ChartAreas["chartAreaVolume"]->AxisX->Interval = 1;
		} else if (interval == "Week.csv") {
			chartStock->ChartAreas["chartAreaPrice"]->AxisX->IntervalType = Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Weeks;
			chartStock->ChartAreas["chartAreaPrice"]->AxisX->Interval = 1;
			chartStock->ChartAreas["chartAreaVolume"]->AxisX->IntervalType = Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Weeks;
			chartStock->ChartAreas["chartAreaVolume"]->AxisX->Interval = 1;
		} else if (interval == "Day.csv") {
			chartStock->ChartAreas["chartAreaPrice"]->AxisX->IntervalType = Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Days;
			chartStock->ChartAreas["chartAreaPrice"]->AxisX->Interval = 1;
			chartStock->ChartAreas["chartAreaVolume"]->AxisX->IntervalType = Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Days;
			chartStock->ChartAreas["chartAreaVolume"]->AxisX->Interval = 1;

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

				String^ interval = ofd->FileName->Split('-')[1];
				// Load stock data
				// CHART SHOULD ALSO UPDATE
				DisplayStockData(FilterStockData(GetStockData(tickerData)), interval);
			} else {
				// Show "That file doesn't exist." message if the file does not exist
				MessageBox::Show("That file doesn't exist.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		} else {
			// Show "No file selected." message if no file is selected
			MessageBox::Show("No file selected.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

private: System::Void checkBoxVolume_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBoxVolume->Checked) {
		chartStock->ChartAreas["chartAreaVolume"]->Visible = true;
	} else {
		chartStock->ChartAreas["chartAreaVolume"]->Visible = false;
	}
}
private: System::Void dtpStart_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	DisplayStockData(FilterStockData(currentCandlesticksFromFile), gInterval);
}
private: System::Void dtpEnd_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	DisplayStockData(FilterStockData(currentCandlesticksFromFile), gInterval);
}
private: System::Void buttonDataGridView_Click(System::Object^ sender, System::EventArgs^ e) {
	// Close datagrid view form if already open
	// Open datagrid view form
}
private: System::Void buttonHelp_Click(System::Object^ sender, System::EventArgs^ e) {
	// Close about form if already open
	if (formHelp->Visible){
		formHelp->Close();
	}
	// Open about form
	formHelp = gcnew FormHelp();
	formHelp->Show();
}
};
};