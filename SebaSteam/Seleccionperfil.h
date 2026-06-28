#pragma once
#include "Inicio.h"
#include "RepositorioPerfiles.h"
#include <msclr/marshal_cppstd.h>

namespace SebaSteam
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	using namespace msclr::interop;
	// NOTA: a proposito NO se pone "using namespace std;" aqui, porque
	// choca con el array<T>^ nativo de C++/CLI (std::array tiene el mismo
	// nombre "array" y el compilador se confunde). Por eso mas abajo se
	// usa std::string y std::vector calificados con "std::".

	// Pantalla de bienvenida: el usuario elige uno de los 3 perfiles fijos
	// (en honor a los creadores del proyecto) o crea su propio perfil
	// escribiendo solo su nombre. Esta es la PRIMERA pantalla que se abre
	// al iniciar la aplicacion (ver SebaSteam.cpp).
	public ref class SeleccionPerfil : public System::Windows::Forms::Form
	{
	public:
		SeleccionPerfil(void)
		{
			// EDITA ESTOS 3 NOMBRES si no corresponden a los creadores reales
			NOMBRES_CREADORES = gcnew cli::array<String^> { "Lincoln", "Aaron", "Sebastian" };

			InitializeComponent();

			// Repositorio de perfiles creados manualmente (Perfiles.txt)
			repoPerfiles = new RepositorioPerfiles("Perfiles.txt");
			repoPerfiles->cargarDesdeArchivo();

			// Se instancia el controlador central una sola vez, igual que en Inicio.h
			driver = gcnew ControladoraPrincipal();

			ConstruirTarjetasPerfiles();
		}

	protected:
		~SeleccionPerfil()
		{
			this->!SeleccionPerfil();
			if (components)
			{
				delete components;
			}
		}

		!SeleccionPerfil()
		{
			if (repoPerfiles != nullptr)
			{
				delete repoPerfiles;
				repoPerfiles = nullptr;
			}
		}

	private:
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::FlowLayoutPanel^ panelTarjetas;
		System::Windows::Forms::Panel^ panelCrear;
		System::Windows::Forms::TextBox^ txtNuevoNombre;
		System::Windows::Forms::Label^ lblError;
		System::Windows::Forms::Button^ btnConfirmarCrear;
		System::Windows::Forms::Button^ btnCancelarCrear;
		System::Windows::Forms::LinkLabel^ linkIniciarSesion;
		System::Windows::Forms::Button^ btnCerrar;
		System::ComponentModel::Container^ components;

		// Logica central de la aplicacion (catalogo, usuarios, etc.)
		ControladoraPrincipal^ driver;
		// Persistencia de los perfiles creados solo con un nombre
		RepositorioPerfiles* repoPerfiles;
		// Nombres de los 3 perfiles fijos (los creadores del proyecto)
		cli::array<String^>^ NOMBRES_CREADORES;

#pragma region Construccion de la interfaz
		void InitializeComponent(void)
		{
			this->lblTitulo = gcnew System::Windows::Forms::Label();
			this->lblSubtitulo = gcnew System::Windows::Forms::Label();
			this->panelTarjetas = gcnew System::Windows::Forms::FlowLayoutPanel();
			this->panelCrear = gcnew System::Windows::Forms::Panel();
			this->txtNuevoNombre = gcnew System::Windows::Forms::TextBox();
			this->lblError = gcnew System::Windows::Forms::Label();
			this->btnConfirmarCrear = gcnew System::Windows::Forms::Button();
			this->btnCancelarCrear = gcnew System::Windows::Forms::Button();
			this->linkIniciarSesion = gcnew System::Windows::Forms::LinkLabel();
			this->btnCerrar = gcnew System::Windows::Forms::Button();
			this->SuspendLayout();
			//
			// lblTitulo
			//
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->BackColor = System::Drawing::Color::Transparent;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(60, 45);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Text = L"SebaSteam";
			//
			// lblSubtitulo
			//
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->BackColor = System::Drawing::Color::Transparent;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18));
			this->lblSubtitulo->ForeColor = System::Drawing::Color::Gainsboro;
			this->lblSubtitulo->Location = System::Drawing::Point(63, 130);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Text = L"\xbfQui\xe9n va a usar SebaSteam?";
			//
			// panelTarjetas (contenedor de las tarjetas de perfil)
			//
			this->panelTarjetas->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
			this->panelTarjetas->WrapContents = true;
			this->panelTarjetas->AutoScroll = true;
			this->panelTarjetas->BackColor = System::Drawing::Color::Transparent;
			this->panelTarjetas->Location = System::Drawing::Point(50, 210);
			this->panelTarjetas->Name = L"panelTarjetas";
			this->panelTarjetas->Size = System::Drawing::Size(1200, 480);
			// Nota: no se asigna Anchor con 4 valores combinados (Top|Bottom|Left|Right)
			// porque el parser del Disenador de Windows Forms para C++/CLI no logra
			// interpretar mas de 2 valores combinados con "|" dentro de un static_cast.
			// No hace falta de todas formas: el formulario no se puede redimensionar
			// (FormBorderStyle::None, sin boton de maximizar).
			//
			// panelCrear (panel emergente para escribir el nombre del nuevo perfil)
			//
			this->panelCrear->BackColor = System::Drawing::Color::FromArgb(30, 30, 30);
			this->panelCrear->Location = System::Drawing::Point((1300 - 420) / 2, (800 - 230) / 2);
			this->panelCrear->Name = L"panelCrear";
			this->panelCrear->Size = System::Drawing::Size(420, 230);
			this->panelCrear->Visible = false;
			this->panelCrear->Anchor = System::Windows::Forms::AnchorStyles::None;

			System::Windows::Forms::Label^ lblCrearTitulo = gcnew System::Windows::Forms::Label();
			lblCrearTitulo->AutoSize = true;
			lblCrearTitulo->BackColor = System::Drawing::Color::Transparent;
			lblCrearTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			lblCrearTitulo->ForeColor = System::Drawing::Color::White;
			lblCrearTitulo->Location = System::Drawing::Point(20, 18);
			lblCrearTitulo->Text = L"Crear nuevo perfil";
			//
			// txtNuevoNombre
			//
			this->txtNuevoNombre->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->txtNuevoNombre->Location = System::Drawing::Point(20, 65);
			this->txtNuevoNombre->MaxLength = 20;
			this->txtNuevoNombre->Name = L"txtNuevoNombre";
			this->txtNuevoNombre->Size = System::Drawing::Size(380, 30);
			//
			// lblError
			//
			this->lblError->AutoSize = true;
			this->lblError->BackColor = System::Drawing::Color::Transparent;
			this->lblError->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblError->ForeColor = System::Drawing::Color::FromArgb(229, 9, 20);
			this->lblError->Location = System::Drawing::Point(20, 100);
			this->lblError->Name = L"lblError";
			this->lblError->Text = L"";
			//
			// btnConfirmarCrear
			//
			this->btnConfirmarCrear->BackColor = System::Drawing::Color::FromArgb(229, 9, 20);
			this->btnConfirmarCrear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnConfirmarCrear->ForeColor = System::Drawing::Color::White;
			this->btnConfirmarCrear->Location = System::Drawing::Point(20, 155);
			this->btnConfirmarCrear->Name = L"btnConfirmarCrear";
			this->btnConfirmarCrear->Size = System::Drawing::Size(170, 42);
			this->btnConfirmarCrear->Text = L"Crear y entrar";
			this->btnConfirmarCrear->UseVisualStyleBackColor = false;
			this->btnConfirmarCrear->Click += gcnew System::EventHandler(this, &SeleccionPerfil::btnConfirmarCrear_Click);
			//
			// btnCancelarCrear
			//
			this->btnCancelarCrear->BackColor = System::Drawing::Color::FromArgb(60, 60, 60);
			this->btnCancelarCrear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancelarCrear->ForeColor = System::Drawing::Color::White;
			this->btnCancelarCrear->Location = System::Drawing::Point(220, 155);
			this->btnCancelarCrear->Name = L"btnCancelarCrear";
			this->btnCancelarCrear->Size = System::Drawing::Size(170, 42);
			this->btnCancelarCrear->Text = L"Cancelar";
			this->btnCancelarCrear->UseVisualStyleBackColor = false;
			this->btnCancelarCrear->Click += gcnew System::EventHandler(this, &SeleccionPerfil::btnCancelarCrear_Click);

			this->panelCrear->Controls->Add(lblCrearTitulo);
			this->panelCrear->Controls->Add(this->txtNuevoNombre);
			this->panelCrear->Controls->Add(this->lblError);
			this->panelCrear->Controls->Add(this->btnConfirmarCrear);
			this->panelCrear->Controls->Add(this->btnCancelarCrear);
			//
			// linkIniciarSesion (acceso opcional al login con usuario/clave que ya existia)
			//
			this->linkIniciarSesion->AutoSize = true;
			this->linkIniciarSesion->BackColor = System::Drawing::Color::Transparent;
			this->linkIniciarSesion->LinkColor = System::Drawing::Color::White;
			this->linkIniciarSesion->ActiveLinkColor = System::Drawing::Color::FromArgb(229, 9, 20);
			this->linkIniciarSesion->Location = System::Drawing::Point(960, 745);
			this->linkIniciarSesion->Name = L"linkIniciarSesion";
			this->linkIniciarSesion->Text = L"\xbfYa tienes una cuenta? Inicia sesi\xf3n aqu\xed";
			// Nota: no se asigna Anchor aqui (ver explicacion en panelTarjetas mas arriba)
			this->linkIniciarSesion->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SeleccionPerfil::linkIniciarSesion_LinkClicked);
			//
			// btnCerrar (boton "X" propio, ya que el formulario no tiene barra de titulo)
			//
			this->btnCerrar->BackColor = System::Drawing::Color::Transparent;
			this->btnCerrar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCerrar->FlatAppearance->BorderSize = 0;
			this->btnCerrar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(229, 9, 20);
			this->btnCerrar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->btnCerrar->ForeColor = System::Drawing::Color::White;
			this->btnCerrar->Location = System::Drawing::Point(1300 - 55, 15);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Size = System::Drawing::Size(40, 40);
			this->btnCerrar->TabStop = false;
			this->btnCerrar->Text = L"X";
			this->btnCerrar->UseVisualStyleBackColor = false;
			this->btnCerrar->Cursor = System::Windows::Forms::Cursors::Hand;
			// Nota: no se asigna Anchor aqui (ver explicacion en panelTarjetas mas arriba)
			this->btnCerrar->Click += gcnew System::EventHandler(this, &SeleccionPerfil::btnCerrar_Click);
			//
			// SeleccionPerfil (formulario)
			//
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(15, 15, 15);
			this->ClientSize = System::Drawing::Size(1300, 800);
			this->ControlBox = false;
			this->Controls->Add(this->lblTitulo);
			this->Controls->Add(this->lblSubtitulo);
			this->Controls->Add(this->panelTarjetas);
			this->Controls->Add(this->linkIniciarSesion);
			this->Controls->Add(this->panelCrear);
			this->Controls->Add(this->btnCerrar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"SeleccionPerfil";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SebaSteam - Selecci\xf3n de Perfil";
			this->Load += gcnew System::EventHandler(this, &SeleccionPerfil::SeleccionPerfil_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// ---------------------------------------------------------------
		// Construccion dinamica de las tarjetas (3 creadores + perfiles
		// guardados + tarjeta para crear un perfil nuevo)
		// ---------------------------------------------------------------
		void ConstruirTarjetasPerfiles()
		{
			panelTarjetas->Controls->Clear();

			// Un color distinto para cada uno de los 3 perfiles fijos
			cli::array<Color>^ coloresCreadores = gcnew cli::array<Color>{
				Color::FromArgb(229, 9, 20),
					Color::FromArgb(0, 173, 239),
					Color::FromArgb(46, 204, 113)
			};

			for (int i = 0; i < NOMBRES_CREADORES->Length; i++)
			{
				Color colorTarjeta = coloresCreadores[i % coloresCreadores->Length];
				panelTarjetas->Controls->Add(CrearTarjetaPerfil(NOMBRES_CREADORES[i], colorTarjeta));
			}

			// Perfiles que el usuario ha creado anteriormente (Perfiles.txt)
			std::vector<std::string> perfilesGuardados = repoPerfiles->obtenerPerfiles();
			for (size_t i = 0; i < perfilesGuardados.size(); i++)
			{
				String^ nombre = marshal_as<String^>(perfilesGuardados[i]);
				panelTarjetas->Controls->Add(CrearTarjetaPerfil(nombre, Color::FromArgb(155, 89, 182)));
			}

			// Al final siempre se muestra la tarjeta para crear un perfil nuevo
			panelTarjetas->Controls->Add(CrearTarjetaNuevoPerfil());
		}

		// Tarjeta de un perfil ya existente (creador o creado por el usuario)
		Panel^ CrearTarjetaPerfil(String^ nombre, Color colorAvatar)
		{
			Panel^ tarjeta = gcnew Panel();
			tarjeta->Size = System::Drawing::Size(200, 240);
			tarjeta->Margin = System::Windows::Forms::Padding(15);
			tarjeta->BackColor = Color::FromArgb(35, 35, 35);
			tarjeta->Cursor = Cursors::Hand;
			tarjeta->Tag = nombre; // Usado para identificar el perfil al hacer click

			Panel^ avatar = gcnew Panel();
			avatar->Size = System::Drawing::Size(120, 120);
			avatar->Location = Point(40, 20);
			avatar->BackColor = colorAvatar;
			avatar->Cursor = Cursors::Hand;

			Label^ lblInicial = gcnew Label();
			lblInicial->Dock = DockStyle::Fill;
			lblInicial->TextAlign = ContentAlignment::MiddleCenter;
			lblInicial->Font = gcnew System::Drawing::Font(L"Segoe UI", 36, FontStyle::Bold);
			lblInicial->ForeColor = Color::White;
			lblInicial->BackColor = Color::Transparent;
			lblInicial->Text = nombre->Substring(0, 1)->ToUpper();
			lblInicial->Cursor = Cursors::Hand;

			Label^ lblNombre = gcnew Label();
			lblNombre->Size = System::Drawing::Size(180, 30);
			lblNombre->Location = Point(10, 160);
			lblNombre->TextAlign = ContentAlignment::MiddleCenter;
			lblNombre->Font = gcnew System::Drawing::Font(L"Segoe UI", 13, FontStyle::Bold);
			lblNombre->ForeColor = Color::White;
			lblNombre->BackColor = Color::Transparent;
			lblNombre->Text = nombre;
			lblNombre->Cursor = Cursors::Hand;

			avatar->Controls->Add(lblInicial);
			tarjeta->Controls->Add(avatar);
			tarjeta->Controls->Add(lblNombre);

			// Se asocia el mismo manejador a la tarjeta y a sus controles hijos
			// para que se pueda hacer click en cualquier parte de la tarjeta
			tarjeta->Click += gcnew EventHandler(this, &SeleccionPerfil::PerfilCard_Click);
			avatar->Click += gcnew EventHandler(this, &SeleccionPerfil::PerfilCard_Click);
			lblInicial->Click += gcnew EventHandler(this, &SeleccionPerfil::PerfilCard_Click);
			lblNombre->Click += gcnew EventHandler(this, &SeleccionPerfil::PerfilCard_Click);

			return tarjeta;
		}

		// Tarjeta especial para crear un perfil nuevo (solo con un nombre)
		Panel^ CrearTarjetaNuevoPerfil()
		{
			Panel^ tarjeta = gcnew Panel();
			tarjeta->Size = System::Drawing::Size(200, 240);
			tarjeta->Margin = System::Windows::Forms::Padding(15);
			tarjeta->BackColor = Color::FromArgb(25, 25, 25);
			tarjeta->Cursor = Cursors::Hand;

			Panel^ circuloMas = gcnew Panel();
			circuloMas->Size = System::Drawing::Size(120, 120);
			circuloMas->Location = Point(40, 20);
			circuloMas->BackColor = Color::FromArgb(60, 60, 60);
			circuloMas->Cursor = Cursors::Hand;

			Label^ lblMas = gcnew Label();
			lblMas->Dock = DockStyle::Fill;
			lblMas->TextAlign = ContentAlignment::MiddleCenter;
			lblMas->Font = gcnew System::Drawing::Font(L"Segoe UI", 40, FontStyle::Bold);
			lblMas->ForeColor = Color::White;
			lblMas->BackColor = Color::Transparent;
			lblMas->Text = L"+";
			lblMas->Cursor = Cursors::Hand;

			Label^ lblTexto = gcnew Label();
			lblTexto->Size = System::Drawing::Size(180, 30);
			lblTexto->Location = Point(10, 160);
			lblTexto->TextAlign = ContentAlignment::MiddleCenter;
			lblTexto->Font = gcnew System::Drawing::Font(L"Segoe UI", 12, FontStyle::Bold);
			lblTexto->ForeColor = Color::Gainsboro;
			lblTexto->BackColor = Color::Transparent;
			lblTexto->Text = L"Crear perfil";
			lblTexto->Cursor = Cursors::Hand;

			circuloMas->Controls->Add(lblMas);
			tarjeta->Controls->Add(circuloMas);
			tarjeta->Controls->Add(lblTexto);

			tarjeta->Click += gcnew EventHandler(this, &SeleccionPerfil::CrearPerfilCard_Click);
			circuloMas->Click += gcnew EventHandler(this, &SeleccionPerfil::CrearPerfilCard_Click);
			lblMas->Click += gcnew EventHandler(this, &SeleccionPerfil::CrearPerfilCard_Click);
			lblTexto->Click += gcnew EventHandler(this, &SeleccionPerfil::CrearPerfilCard_Click);

			return tarjeta;
		}

		// ---------------------------------------------------------------
		// Manejadores de eventos
		// ---------------------------------------------------------------

		// Click en cualquier tarjeta de perfil existente -> entra directo al catalogo
		System::Void PerfilCard_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Control^ ctrl = dynamic_cast<Control^>(sender);
			while (ctrl != nullptr && ctrl->Tag == nullptr)
			{
				ctrl = ctrl->Parent;
			}
			if (ctrl != nullptr)
			{
				String^ nombrePerfil = (String^)ctrl->Tag;
				AbrirMenuPrincipal(nombrePerfil);
			}
		}

		// Click en la tarjeta de "Crear perfil" -> muestra el panel para escribir el nombre
		System::Void CrearPerfilCard_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MostrarPanelCrear();
		}

		void MostrarPanelCrear()
		{
			txtNuevoNombre->Clear();
			lblError->Text = "";
			panelCrear->Visible = true;
			panelCrear->BringToFront();
			txtNuevoNombre->Focus();
		}

		System::Void btnConfirmarCrear_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ nombre = txtNuevoNombre->Text->Trim();

			if (nombre->Length == 0)
			{
				lblError->Text = "Ingresa un nombre para tu perfil";
				return;
			}
			if (nombre->Contains(","))
			{
				lblError->Text = "El nombre no puede contener comas";
				return;
			}

			std::string nombreStd = marshal_as<std::string>(nombre);
			// Si el nombre ya existia simplemente se reutiliza ese perfil
			repoPerfiles->registrarPerfil(nombreStd);

			panelCrear->Visible = false;
			ConstruirTarjetasPerfiles(); // refresca para que la nueva tarjeta quede guardada
			AbrirMenuPrincipal(nombre);
		}

		System::Void btnCancelarCrear_Click(System::Object^ sender, System::EventArgs^ e)
		{
			panelCrear->Visible = false;
		}

		// Cierra la aplicacion. Como este formulario es el que arranca en
		// main() (ver SebaSteam.cpp), cerrarlo termina el programa completo,
		// igual que hubiera hecho la "X" nativa de Windows.
		System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}

		// Acceso opcional al login con usuario/clave que ya exist\xeda en el proyecto
		System::Void linkIniciarSesion_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			Inicio^ formInicio = gcnew Inicio();
			formInicio->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;

			this->Hide();
			formInicio->ShowDialog();
			this->Show();
		}

		// Abre el catalogo principal reutilizando el mismo controlador (driver)
		void AbrirMenuPrincipal(String^ nombrePerfil)
		{
			try
			{
				MenuPrincipal^ menuPrinci = gcnew MenuPrincipal(driver);
				menuPrinci->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				menuPrinci->Text = "SebaSteam - " + nombrePerfil;

				this->Hide();
				menuPrinci->ShowDialog(); // El programa se pausa aqui hasta que cierres el catalogo
				this->Show();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("No se pudo abrir el cat\xe1logo: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		System::Void SeleccionPerfil_Load(System::Object^ sender, System::EventArgs^ e)
		{
		}
	};
}