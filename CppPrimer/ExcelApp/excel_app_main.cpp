#include<iostream>
#include<Windows.h>

using namespace System;

#include "MyExcelApp.h"

int main() {
	MyExcelApp^ myExcelApp = gcnew MyExcelApp();
	myExcelApp->updateExcel();

	return 0;
}