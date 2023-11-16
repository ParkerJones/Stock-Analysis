#pragma once
#include <iostream>
#include "Candlestick.h"
#include <fstream>
#include <string>
#include <cliext/vector>
#include "SmartCandlestick.h"

namespace Stock_Analysis_v2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Summary for FormChart
	/// </summary>
	public ref class FormChart : public System::Windows::Forms::Form
	{
	public:
		// Constructor used when timeframe is not previously specified
		FormChart(array<String^>^ stockData, String^ interval)
		{
			InitializeComponent();
			DisplayStockData(FilterStockData(GetStockData(stockData)), interval);

			// Dynamically add pattern types to combo box
			comboPatterns->Items->AddRange(SmartCandlestick::Patterns);

			currentCandlesticksFromFile = GetStockData(stockData);
			gInterval = interval;
		}

		// Constructor used when timeframe is specified
		FormChart(array<String^>^ stockData, String^ interval, DateTime start, DateTime end)
		{
			InitializeComponent();
			DisplayStockData(FilterStockData(GetStockData(stockData)), interval);

			// Dynamically add pattern types to combo box
			comboPatterns->Items->AddRange(SmartCandlestick::Patterns);

			// Set DateTime Pickers
			dtpStart->Value = start;
			dtpEnd->Value = end;

			currentCandlesticksFromFile = GetStockData(stockData);
			gInterval = interval;
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
	private: System::Windows::Forms::CheckBox^ checkBoxVolume;
	private: System::Windows::Forms::DateTimePicker^ dtpStart;
	private: System::Windows::Forms::Label^ labelStart;
	private: System::Windows::Forms::DateTimePicker^ dtpEnd;
	private: System::Windows::Forms::Label^ labelEnd;
	private: System::Windows::Forms::CheckBox^ checkBoxPatterns;
	private: System::Windows::Forms::ComboBox^ comboPatterns;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartStock;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->checkBoxVolume = (gcnew System::Windows::Forms::CheckBox());
			this->dtpStart = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelStart = (gcnew System::Windows::Forms::Label());
			this->dtpEnd = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelEnd = (gcnew System::Windows::Forms::Label());
			this->checkBoxPatterns = (gcnew System::Windows::Forms::CheckBox());
			this->comboPatterns = (gcnew System::Windows::Forms::ComboBox());
			this->chartStock = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartStock))->BeginInit();
			this->SuspendLayout();
			// 
			// checkBoxVolume
			// 
			this->checkBoxVolume->AutoSize = true;
			this->checkBoxVolume->Location = System::Drawing::Point(290, 11);
			this->checkBoxVolume->Name = L"checkBoxVolume";
			this->checkBoxVolume->Size = System::Drawing::Size(98, 17);
			this->checkBoxVolume->TabIndex = 0;
			this->checkBoxVolume->Text = L"Display Volume";
			this->checkBoxVolume->UseVisualStyleBackColor = true;
			this->checkBoxVolume->CheckedChanged += gcnew System::EventHandler(this, &FormChart::checkBoxVolume_CheckedChanged);
			// 
			// dtpStart
			// 
			this->dtpStart->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpStart->Location = System::Drawing::Point(45, 9);
			this->dtpStart->MaxDate = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			this->dtpStart->MinDate = System::DateTime(2011, 8, 1, 0, 0, 0, 0);
			this->dtpStart->Name = L"dtpStart";
			this->dtpStart->Size = System::Drawing::Size(99, 20);
			this->dtpStart->TabIndex = 1;
			this->dtpStart->Value = System::DateTime(2022, 8, 1, 0, 0, 0, 0);
			this->dtpStart->ValueChanged += gcnew System::EventHandler(this, &FormChart::dtpStart_ValueChanged);
			// 
			// labelStart
			// 
			this->labelStart->AutoSize = true;
			this->labelStart->Location = System::Drawing::Point(11, 12);
			this->labelStart->Name = L"labelStart";
			this->labelStart->Size = System::Drawing::Size(32, 13);
			this->labelStart->TabIndex = 2;
			this->labelStart->Text = L"Start:";
			// 
			// dtpEnd
			// 
			this->dtpEnd->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpEnd->Location = System::Drawing::Point(185, 9);
			this->dtpEnd->MaxDate = System::DateTime(2023, 8, 31, 0, 0, 0, 0);
			this->dtpEnd->MinDate = System::DateTime(2011, 8, 1, 0, 0, 0, 0);
			this->dtpEnd->Name = L"dtpEnd";
			this->dtpEnd->Size = System::Drawing::Size(99, 20);
			this->dtpEnd->TabIndex = 3;
			this->dtpEnd->Value = System::DateTime(2023, 8, 1, 0, 0, 0, 0);
			this->dtpEnd->ValueChanged += gcnew System::EventHandler(this, &FormChart::dtpEnd_ValueChanged);
			// 
			// labelEnd
			// 
			this->labelEnd->AutoSize = true;
			this->labelEnd->Location = System::Drawing::Point(154, 12);
			this->labelEnd->Name = L"labelEnd";
			this->labelEnd->Size = System::Drawing::Size(29, 13);
			this->labelEnd->TabIndex = 4;
			this->labelEnd->Text = L"End:";
			// 
			// checkBoxPatterns
			// 
			this->checkBoxPatterns->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->checkBoxPatterns->AutoSize = true;
			this->checkBoxPatterns->Location = System::Drawing::Point(679, 11);
			this->checkBoxPatterns->Name = L"checkBoxPatterns";
			this->checkBoxPatterns->Size = System::Drawing::Size(68, 17);
			this->checkBoxPatterns->TabIndex = 5;
			this->checkBoxPatterns->Text = L"Patterns:";
			this->checkBoxPatterns->UseVisualStyleBackColor = true;
			this->checkBoxPatterns->CheckedChanged += gcnew System::EventHandler(this, &FormChart::checkBoxPatterns_CheckedChanged);
			// 
			// comboPatterns
			// 
			this->comboPatterns->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboPatterns->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboPatterns->Enabled = false;
			this->comboPatterns->FormattingEnabled = true;
			this->comboPatterns->Location = System::Drawing::Point(749, 8);
			this->comboPatterns->Name = L"comboPatterns";
			this->comboPatterns->Size = System::Drawing::Size(121, 21);
			this->comboPatterns->TabIndex = 6;
			this->comboPatterns->SelectedIndexChanged += gcnew System::EventHandler(this, &FormChart::comboPatterns_SelectedIndexChanged);
			// 
			// chartStock
			// 
			this->chartStock->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea1->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea1->Name = L"chartAreaPrice";
			chartArea2->AlignWithChartArea = L"chartAreaPrice";
			chartArea2->AxisX->MajorGrid->Enabled = false;
			chartArea2->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash;
			chartArea2->Name = L"chartAreaVolume";
			chartArea2->Visible = false;
			this->chartStock->ChartAreas->Add(chartArea1);
			this->chartStock->ChartAreas->Add(chartArea2);
			this->chartStock->Location = System::Drawing::Point(0, 35);
			this->chartStock->Name = L"chartStock";
			series1->ChartArea = L"chartAreaPrice";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->Color = System::Drawing::Color::Black;
			series1->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Green";
			series1->Name = L"seriesPrice";
			series1->YValuesPerPoint = 4;
			series2->ChartArea = L"chartAreaVolume";
			series2->Color = System::Drawing::Color::Gray;
			series2->Name = L"seriesVolume";
			this->chartStock->Series->Add(series1);
			this->chartStock->Series->Add(series2);
			this->chartStock->Size = System::Drawing::Size(884, 427);
			this->chartStock->TabIndex = 7;
			this->chartStock->Text = L"chart";
			// 
			// FormChart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 461);
			this->Controls->Add(this->chartStock);
			this->Controls->Add(this->comboPatterns);
			this->Controls->Add(this->checkBoxPatterns);
			this->Controls->Add(this->labelEnd);
			this->Controls->Add(this->dtpEnd);
			this->Controls->Add(this->labelStart);
			this->Controls->Add(this->dtpStart);
			this->Controls->Add(this->checkBoxVolume);
			this->Name = L"FormChart";
			this->Text = L"FormChart";
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
		}
		else {
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
		}
		else if (interval == "Week.csv") {
			chartStock->ChartAreas["chartAreaPrice"]->AxisX->IntervalType = Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Weeks;
			chartStock->ChartAreas["chartAreaPrice"]->AxisX->Interval = 1;
			chartStock->ChartAreas["chartAreaVolume"]->AxisX->IntervalType = Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Weeks;
			chartStock->ChartAreas["chartAreaVolume"]->AxisX->Interval = 1;
		}
		else if (interval == "Day.csv") {
			chartStock->ChartAreas["chartAreaPrice"]->AxisX->IntervalType = Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Days;
			chartStock->ChartAreas["chartAreaPrice"]->AxisX->Interval = 1;
			chartStock->ChartAreas["chartAreaVolume"]->AxisX->IntervalType = Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Days;
			chartStock->ChartAreas["chartAreaVolume"]->AxisX->Interval = 1;
		}
	}

	/// <summary>
	/// Annotates points on chartStock series given a detectable pattern
	/// </summary>
	/// <param name="pattern">Pattern to detect</param>
	protected: void AnnotatePatterns(String^ pattern) {
		chartStock->Annotations->Clear();

		for (int i = 0; i < chartStock->Series["seriesPrice"]->Points->Count; ++i) {

			SmartCandlestick^ currentCandlestick = gcnew SmartCandlestick(filteredCandlesticksFromFile[i]);
			DataPoint^ point = chartStock->Series["seriesPrice"]->Points[i];

			// FIX THIS: add method for creating/adding annotation
			if (pattern == "All Doji" && currentCandlestick->isDoji()) {
				ArrowAnnotation^ annotation = gcnew ArrowAnnotation;
				annotation->AnchorDataPoint = point;
				annotation->AnchorX = point->XValue;
				annotation->AnchorY = point->YValues[0];

				annotation->ArrowStyle = ArrowStyle::Simple;
				annotation->Width = .001;
				annotation->Height = 5;
				annotation->LineWidth = 1;
				annotation->ArrowSize = 2;
				annotation->LineColor = Color::Black;

				annotation->BackColor = Color::Red;

				chartStock->Annotations->Add(annotation);
			}
			else if (pattern == "Neutral Doji" && currentCandlestick->isNeutralDoji()) {
				ArrowAnnotation^ annotation = gcnew ArrowAnnotation;
				annotation->AnchorDataPoint = point;
				annotation->AnchorX = point->XValue;
				annotation->AnchorY = point->YValues[0];

				annotation->ArrowStyle = ArrowStyle::Simple;
				annotation->Width = .001;
				annotation->Height = 5;
				annotation->LineWidth = 1;
				annotation->ArrowSize = 2;
				annotation->LineColor = Color::Black;

				annotation->BackColor = Color::Red;

				chartStock->Annotations->Add(annotation);
			}
			else if (pattern == "Dragonfly Doji" && currentCandlestick->isDragonflyDoji()) {
				ArrowAnnotation^ annotation = gcnew ArrowAnnotation;
				annotation->AnchorDataPoint = point;
				annotation->AnchorX = point->XValue;
				annotation->AnchorY = point->YValues[0];

				annotation->ArrowStyle = ArrowStyle::Simple;
				annotation->Width = .001;
				annotation->Height = 5;
				annotation->LineWidth = 1;
				annotation->ArrowSize = 2;
				annotation->LineColor = Color::Black;

				annotation->BackColor = Color::Red;

				chartStock->Annotations->Add(annotation);
			}
			else if (pattern == "Gravestone Doji" && currentCandlestick->isGravestoneDoji()) {
				ArrowAnnotation^ annotation = gcnew ArrowAnnotation;
				annotation->AnchorDataPoint = point;
				annotation->AnchorX = point->XValue;
				annotation->AnchorY = point->YValues[0];

				annotation->ArrowStyle = ArrowStyle::Simple;
				annotation->Width = .001;
				annotation->Height = 5;
				annotation->LineWidth = 1;
				annotation->ArrowSize = 2;
				annotation->LineColor = Color::Black;

				annotation->BackColor = Color::Red;

				chartStock->Annotations->Add(annotation);
			}
			else if (pattern == "All Hammers" && (currentCandlestick->isHammerUpright() || currentCandlestick->isHammerInverted())) {
				ArrowAnnotation^ annotation = gcnew ArrowAnnotation;
				annotation->AnchorDataPoint = point;
				annotation->AnchorX = point->XValue;
				annotation->AnchorY = point->YValues[0];

				annotation->ArrowStyle = ArrowStyle::Simple;
				annotation->Width = .001;
				annotation->Height = 5;
				annotation->LineWidth = 1;
				annotation->ArrowSize = 2;
				annotation->LineColor = Color::Black;

				annotation->BackColor = Color::Red;

				chartStock->Annotations->Add(annotation);
			}
			else if (pattern == "Upright Hammers" && currentCandlestick->isHammerUpright()) {
				ArrowAnnotation^ annotation = gcnew ArrowAnnotation;
				annotation->AnchorDataPoint = point;
				annotation->AnchorX = point->XValue;
				annotation->AnchorY = point->YValues[0];

				annotation->ArrowStyle = ArrowStyle::Simple;
				annotation->Width = .001;
				annotation->Height = 5;
				annotation->LineWidth = 1;
				annotation->ArrowSize = 2;
				annotation->LineColor = Color::Black;

				annotation->BackColor = Color::Red;

				chartStock->Annotations->Add(annotation);
			}
			else if (pattern == "Inverted Hammers" && currentCandlestick->isHammerInverted()) {
				ArrowAnnotation^ annotation = gcnew ArrowAnnotation;
				annotation->AnchorDataPoint = point;
				annotation->AnchorX = point->XValue;
				annotation->AnchorY = point->YValues[0];

				annotation->ArrowStyle = ArrowStyle::Simple;
				annotation->Width = .001;
				annotation->Height = 5;
				annotation->LineWidth = 1;
				annotation->ArrowSize = 2;
				annotation->LineColor = Color::Black;

				annotation->BackColor = Color::Red;

				chartStock->Annotations->Add(annotation);
			}
			else if (pattern == "All Marubozu" && currentCandlestick->isMarubozu()) {
				ArrowAnnotation^ annotation = gcnew ArrowAnnotation;
				annotation->AnchorDataPoint = point;
				annotation->AnchorX = point->XValue;
				annotation->AnchorY = point->YValues[0];

				annotation->ArrowStyle = ArrowStyle::Simple;
				annotation->Width = .001;
				annotation->Height = 5;
				annotation->LineWidth = 1;
				annotation->ArrowSize = 2;
				annotation->LineColor = Color::Black;

				annotation->BackColor = Color::Red;

				chartStock->Annotations->Add(annotation);
			}
			else if (pattern == "White Marubozu" && currentCandlestick->isMarubozu() && currentCandlestick->isBullish()) {
				ArrowAnnotation^ annotation = gcnew ArrowAnnotation;
				annotation->AnchorDataPoint = point;
				annotation->AnchorX = point->XValue;
				annotation->AnchorY = point->YValues[0];

				annotation->ArrowStyle = ArrowStyle::Simple;
				annotation->Width = .001;
				annotation->Height = 5;
				annotation->LineWidth = 1;
				annotation->ArrowSize = 2;
				annotation->LineColor = Color::Black;

				annotation->BackColor = Color::Red;

				chartStock->Annotations->Add(annotation);
			}
			else if (pattern == "Black Marubozu" && currentCandlestick->isMarubozu() && currentCandlestick->isBearish()) {
				ArrowAnnotation^ annotation = gcnew ArrowAnnotation;
				annotation->AnchorDataPoint = point;
				annotation->AnchorX = point->XValue;
				annotation->AnchorY = point->YValues[0];

				annotation->ArrowStyle = ArrowStyle::Simple;
				annotation->Width = .001;
				annotation->Height = 5;
				annotation->LineWidth = 1;
				annotation->ArrowSize = 2;
				annotation->LineColor = Color::Black;

				annotation->BackColor = Color::Red;

				chartStock->Annotations->Add(annotation);
			}
		}
	}

	private: System::Void comboPatterns_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		AnnotatePatterns(comboPatterns->Text);
	}

	private: System::Void checkBoxPatterns_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (checkBoxPatterns->Checked) {
			comboPatterns->Enabled = true;
			AnnotatePatterns(comboPatterns->Text);
		}
		else {
			comboPatterns->Enabled = false;
			chartStock->Annotations->Clear();
		}
	}

	private: System::Void checkBoxVolume_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (checkBoxVolume->Checked) {
			chartStock->ChartAreas["chartAreaVolume"]->Visible = true;
		}
		else {
			chartStock->ChartAreas["chartAreaVolume"]->Visible = false;
		}
	}

	private: System::Void dtpStart_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		DisplayStockData(FilterStockData((currentCandlesticksFromFile)), gInterval);
		if (checkBoxPatterns->Checked) {
			comboPatterns->Enabled = true;
			AnnotatePatterns(comboPatterns->Text);
		}
		else {
			comboPatterns->Enabled = false;
			chartStock->Annotations->Clear();
		}
	}

	private: System::Void dtpEnd_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		DisplayStockData(FilterStockData((currentCandlesticksFromFile)), gInterval);
		if (checkBoxPatterns->Checked) {
			comboPatterns->Enabled = true;
			AnnotatePatterns(comboPatterns->Text);
		}
		else {
			comboPatterns->Enabled = false;
			chartStock->Annotations->Clear();
		}
	}
};
}
