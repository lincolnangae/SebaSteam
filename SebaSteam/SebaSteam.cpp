#include "pch.h"
#include "MenuPrincipal.h"
#include"Inicio.h"
//Codigo para iniciar la aplicacion
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SebaSteam::Inicio form;
	Application::Run(% form);
	return 0;
}