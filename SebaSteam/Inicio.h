#pragma once
#include "MenuPrincipal.h"
namespace SebaSteam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Inicio : public System::Windows::Forms::Form
	{
	public:
		Inicio(void)
		{
			InitializeComponent();
			driver = gcnew ControladoraPrincipal();
			driver->InicializarCatalogoInicio();
		}

	protected:
		
		~Inicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ IDUser;
	private: System::Windows::Forms::Label^ Text1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ ClaveUsuario;
	private: System::Windows::Forms::Button^ IniciarS;
	private: System::Windows::Forms::Button^ RegistraButton;
		   ControladoraPrincipal^ driver;

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Inicio::typeid));
			this->IDUser = (gcnew System::Windows::Forms::TextBox());
			this->Text1 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ClaveUsuario = (gcnew System::Windows::Forms::TextBox());
			this->IniciarS = (gcnew System::Windows::Forms::Button());
			this->RegistraButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// IDUser
			// 
			this->IDUser->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IDUser->Location = System::Drawing::Point(81, 431);
			this->IDUser->Name = L"IDUser";
			this->IDUser->Size = System::Drawing::Size(492, 39);
			this->IDUser->TabIndex = 0;
			// 
			// Text1
			// 
			this->Text1->AutoSize = true;
			this->Text1->BackColor = System::Drawing::Color::Transparent;
			this->Text1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Text1->ForeColor = System::Drawing::Color::Transparent;
			this->Text1->Location = System::Drawing::Point(86, 385);
			this->Text1->Name = L"Text1";
			this->Text1->Size = System::Drawing::Size(277, 32);
			this->Text1->TabIndex = 1;
			this->Text1->Text = L"Ingrese su Usuario:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(86, 501);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(323, 32);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Ingrese su contraseña:";
			// 
			// ClaveUsuario
			// 
			this->ClaveUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClaveUsuario->Location = System::Drawing::Point(81, 547);
			this->ClaveUsuario->Name = L"ClaveUsuario";
			this->ClaveUsuario->Size = System::Drawing::Size(492, 39);
			this->ClaveUsuario->TabIndex = 2;
			// 
			// IniciarS
			// 
			this->IniciarS->BackColor = System::Drawing::Color::Transparent;
			this->IniciarS->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IniciarS.BackgroundImage")));
			this->IniciarS->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->IniciarS->FlatAppearance->BorderSize = 0;
			this->IniciarS->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->IniciarS->ForeColor = System::Drawing::Color::Transparent;
			this->IniciarS->Location = System::Drawing::Point(81, 650);
			this->IniciarS->Name = L"IniciarS";
			this->IniciarS->Size = System::Drawing::Size(209, 67);
			this->IniciarS->TabIndex = 4;
			this->IniciarS->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->IniciarS->UseVisualStyleBackColor = false;
			this->IniciarS->Click += gcnew System::EventHandler(this, &Inicio::IniciarS_Click);
			// 
			// RegistraButton
			// 
			this->RegistraButton->BackColor = System::Drawing::Color::Transparent;
			this->RegistraButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RegistraButton.BackgroundImage")));
			this->RegistraButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->RegistraButton->FlatAppearance->BorderSize = 0;
			this->RegistraButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RegistraButton->ForeColor = System::Drawing::Color::Transparent;
			this->RegistraButton->Location = System::Drawing::Point(364, 650);
			this->RegistraButton->Name = L"RegistraButton";
			this->RegistraButton->Size = System::Drawing::Size(209, 67);
			this->RegistraButton->TabIndex = 5;
			this->RegistraButton->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->RegistraButton->UseVisualStyleBackColor = false;
			this->RegistraButton->Click += gcnew System::EventHandler(this, &Inicio::RegistraButton_Click);
			// 
			// Inicio
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1300, 800);
			this->ControlBox = false;
			this->Controls->Add(this->RegistraButton);
			this->Controls->Add(this->IniciarS);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ClaveUsuario);
			this->Controls->Add(this->Text1);
			this->Controls->Add(this->IDUser);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Inicio";
			this->ShowIcon = false;
			this->Text = L"Inicio";
			this->Load += gcnew System::EventHandler(this, &Inicio::Inicio_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
	System::Void IniciarS_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ id = IDUser->Text;
		String^ clave = ClaveUsuario->Text;
		try {
			if (id->Trim()->Length == 0 || clave->Trim()->Length == 0) {
				MessageBox::Show("Campos vacios, rellene los campos con sus respectivos datos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			bool accesoConcedido = driver->autenticarUsuario(id, clave);
			if (accesoConcedido) {
				//INICIAR NUEVO FORMULARIO DEL FUNCIONAMIENTO PRINCIPAL
				MenuPrincipal^ menuPrinci = gcnew MenuPrincipal(driver);
				menuPrinci->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
				menuPrinci->Location = this->Location;
				this->Hide();
				menuPrinci->ShowDialog();

				//AGREGAR CERRAR SESION EN EL MENU PRINCIPAL PARA MOSTRAR DE NUEVO ESTE FORMULARIO
				this->Show();
				IDUser->Clear();
				ClaveUsuario->Clear();
			}
			else {
				MessageBox::Show("Las credenciales ingresadas son incorrectas. Por favor, inténtelo de nuevo.",
					"Error de Inicio de Sesión",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("No se pudo conectar con el servidor. Inténtelo más tarde" + ex->Message, "Error de inicio de sesion:", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	System::Void RegistraButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ id = IDUser->Text;
		String^ clave = ClaveUsuario->Text;
		try {
			if (id->Trim()->Length == 0 || clave->Trim()->Length == 0) {
				MessageBox::Show("Campos vacios, rellene los campos con sus respectivos datos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			bool registroExitoso = driver->agregarUsuario(id, clave);
			if (registroExitoso) {
				MessageBox::Show("Usuario creado", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				IDUser->Clear();
				ClaveUsuario->Clear();
			}
			else {
				MessageBox::Show("El ID ya existe o es invalido", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error en el registro: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void Inicio_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
