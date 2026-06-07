#include "pch.h"
#include "Programa.h"
//Inicializador
using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SebaSteam::Programa form;
	Application::Run(% form);
	return 0;
}