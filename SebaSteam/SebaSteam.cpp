#include "pch.h"
#include "MenuPrincipal.h"
#include"Inicio.h"
#include "SeleccionPerfil.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Inicia la aplicación con el formulario de selección de perfil
	SebaSteam::SeleccionPerfil form;
	Application::Run(% form);
	return 0;
}