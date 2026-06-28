#include "pch.h"
#include "MenuPrincipal.h"
#include"Inicio.h"
#include "SeleccionPerfil.h"
//Codigo para iniciar la aplicacion
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// La aplicacion ahora arranca con la pantalla de Seleccion de Perfil
	SebaSteam::SeleccionPerfil form;
	Application::Run(% form);
	return 0;
}