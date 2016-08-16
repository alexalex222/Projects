#pragma once
using namespace Microsoft::Office::Interop;
using namespace System;

ref class MyExcelApp
{
public:
	MyExcelApp();
	~MyExcelApp();
	void updateExcel(String^);
	void updateExcel(String^, String^);
	

private:
	Excel::Application^ excelApp = nullptr;
	Excel::Workbook^ excelWorkbook = nullptr;
	Excel::Workbook^ excelWorkbook = nullptr;
	Excel::Worksheet^ excelWorksheet = nullptr;

};



MyExcelApp::MyExcelApp()
{
	excelApp = gcnew Excel::ApplicationClass();
}

MyExcelApp::~MyExcelApp()
{
	excelApp->Quit();
}


// Update one Excel spreadsheet
void MyExcelApp::updateExcel(String^ fileName) {
	try {
		excelWorkbook = excelApp->Workbooks->Open(fileName, Type::Missing, Type::Missing, Type::Missing,
			Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing,
			Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing);
		excelWorkbook->RefreshAll();
		Sleep(10000);
	}
	catch (Exception^ ex) {
		Console::WriteLine(ex->Message);
		Console::WriteLine("Error in updating Excel file {0}", fileName);
	}
	finally {
		excelWorkbook->Close(true, Type::Missing, Type::Missing);
	}
	return;
}

void MyExcelApp::updateExcel(String^ targetFileName, String^ sourceFileName) {
	try {

	}
	catch (Exception^ ex) {
		Console::WriteLine(ex->Message);
		Console::WriteLine("Error in updaing Excel files {0} and {1}", targetFileName, sourceFileName);
	}
}
