#include "pch.h"
#include "Programa.h"
//Codigo para iniciar la aplicacion
using namespace System;
using namespace System::Windows::Forms;

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SebaSteam::Programa form;
	Application::Run(% form);
	return 0;
}