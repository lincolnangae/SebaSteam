#pragma once
#include "Controlador.h"

namespace SebaSteam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Programa : public System::Windows::Forms::Form
	{
	public:
		Programa(void)
		{
			InitializeComponent();
			controlador = gcnew ControladoraPrincipal();

			this->DoubleBuffered = true;
			mostrarCatalogo = false;

			imagenFondoCatalogo = System::Drawing::Image::FromFile("Imagenes/Menus/MenuPrincipal.png");

			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Programa::Programa_Paint);
		}

	protected:
		~Programa()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Button^ BotonIniciarSesion;
		System::Windows::Forms::Button^ BotonRegirtar;
		System::Windows::Forms::TextBox^ IDUsuario;
		System::Windows::Forms::TextBox^ ClaveUsuario;
		System::Drawing::Image^ imagenFondoCatalogo;

		ControladoraPrincipal^ controlador;
		bool mostrarCatalogo;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Programa::typeid));
			this->BotonIniciarSesion = (gcnew System::Windows::Forms::Button());
			this->BotonRegirtar = (gcnew System::Windows::Forms::Button());
			this->IDUsuario = (gcnew System::Windows::Forms::TextBox());
			this->ClaveUsuario = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// BotonIniciarSesion
			// 
			this->BotonIniciarSesion->BackColor = System::Drawing::Color::Transparent;
			this->BotonIniciarSesion->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BotonIniciarSesion.BackgroundImage")));
			this->BotonIniciarSesion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->BotonIniciarSesion->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->BotonIniciarSesion->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->BotonIniciarSesion->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotonIniciarSesion->Location = System::Drawing::Point(32, 500);
			this->BotonIniciarSesion->Name = L"BotonIniciarSesion";
			this->BotonIniciarSesion->Size = System::Drawing::Size(212, 60);
			this->BotonIniciarSesion->TabIndex = 2;
			this->BotonIniciarSesion->Text = L"txt";
			this->BotonIniciarSesion->UseVisualStyleBackColor = false;
			this->BotonIniciarSesion->Click += gcnew System::EventHandler(this, &Programa::BotonIniciarSesion_Click);
			// 
			// BotonRegirtar
			// 
			this->BotonRegirtar->BackColor = System::Drawing::Color::Transparent;
			this->BotonRegirtar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BotonRegirtar.BackgroundImage")));
			this->BotonRegirtar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->BotonRegirtar->Cursor = System::Windows::Forms::Cursors::Default;
			this->BotonRegirtar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->BotonRegirtar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->BotonRegirtar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotonRegirtar->Location = System::Drawing::Point(282, 500);
			this->BotonRegirtar->Name = L"BotonRegirtar";
			this->BotonRegirtar->Size = System::Drawing::Size(212, 60);
			this->BotonRegirtar->TabIndex = 3;
			this->BotonRegirtar->UseVisualStyleBackColor = false;
			this->BotonRegirtar->Click += gcnew System::EventHandler(this, &Programa::BotonRegirtar_Click);
			// 
			// IDUsuario
			// 
			this->IDUsuario->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->IDUsuario->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->IDUsuario->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->IDUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IDUsuario->ForeColor = System::Drawing::SystemColors::WindowText;
			this->IDUsuario->Location = System::Drawing::Point(108, 329);
			this->IDUsuario->Name = L"IDUsuario";
			this->IDUsuario->Size = System::Drawing::Size(263, 26);
			this->IDUsuario->TabIndex = 4;
			this->IDUsuario->Text = L"Poner Usuario";
			this->IDUsuario->WordWrap = false;
			// 
			// ClaveUsuario
			// 
			this->ClaveUsuario->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClaveUsuario->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ClaveUsuario->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->ClaveUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClaveUsuario->ForeColor = System::Drawing::SystemColors::WindowText;
			this->ClaveUsuario->Location = System::Drawing::Point(108, 381);
			this->ClaveUsuario->Name = L"ClaveUsuario";
			this->ClaveUsuario->Size = System::Drawing::Size(263, 26);
			this->ClaveUsuario->TabIndex = 5;
			this->ClaveUsuario->Text = L"Poner Clave";
			this->ClaveUsuario->WordWrap = false;
			// 
			// Programa
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1134, 671);
			this->Controls->Add(this->ClaveUsuario);
			this->Controls->Add(this->IDUsuario);
			this->Controls->Add(this->BotonRegirtar);
			this->Controls->Add(this->BotonIniciarSesion);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Programa";
			this->Text = L"Programa";
			this->Load += gcnew System::EventHandler(this, &Programa::Programa_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void LimpiarElementosInicio() {
			this->BotonIniciarSesion->Visible = false;
			this->BotonRegirtar->Visible = false;
			this->IDUsuario->Visible = false;
			this->ClaveUsuario->Visible = false;

			this->BackgroundImage = nullptr;
			mostrarCatalogo = true;
			this->Refresh();
		}

	private: System::Void Programa_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void BotonIniciarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ id = IDUsuario->Text;
		String^ clave = ClaveUsuario->Text;

		try {
			if (id->Trim()->Length == 0 || clave->Trim()->Length == 0) {
				MessageBox::Show("Campos vacios");
				return;
			}

			bool accesoConcedido = controlador->autenticarUsuario(id, clave);

			if (accesoConcedido) {
				this->LimpiarElementosInicio();
			}
			else {
				MessageBox::Show("Credenciales incorrectas");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error en el inicio de sesion: " + ex->Message);
		}
	}

	private: System::Void BotonRegirtar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ id = IDUsuario->Text;
		String^ clave = ClaveUsuario->Text;

		try {
			if (id->Trim()->Length == 0 || clave->Trim()->Length == 0) {
				MessageBox::Show("Campos vacios");
				return;
			}

			bool registroExitoso = controlador->agregarUsuario(id, clave);

			if (registroExitoso) {
				MessageBox::Show("Usuario creado");
				IDUsuario->Clear();
				ClaveUsuario->Clear();
			}
			else {
				MessageBox::Show("El ID ya existe o es invalido");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error en el registro: " + ex->Message);
		}
	}

		   // Manejador del espacio de dibujado principal del sistema
	private: System::Void Programa_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (!mostrarCatalogo) return;

		Graphics^ g = e->Graphics;

		try {
			if (imagenFondoCatalogo != nullptr) {
				g->DrawImage(imagenFondoCatalogo, 0, 0, this->Width, this->Height);
			}
		}
		catch (Exception^ ex) {
		}
	}
	};
}