#pragma once
#include"Dependencias.h"
namespace SebaSteam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Opciones
	/// </summary>
	public ref class Opciones : public System::Windows::Forms::Form
	{
	public:
		Opciones(int x, int y)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->Location = System::Drawing::Point(x, y);
		}
		bool getCerroSesion() {
			return cerro_sesion;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Opciones()
		{
			if (components)
			{
				delete components;
			}
		}
		
	private:
		bool cerro_sesion = 0;
	private: System::Windows::Forms::Button^ button1;

		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Opciones::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(191, 54);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Opciones::button1_Click);
			// 
			// Opciones
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(200, 800);
			this->Controls->Add(this->button1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->Name = L"Opciones";
			this->Text = L"Opciones";
			this->Load += gcnew System::EventHandler(this, &Opciones::Opciones_Load);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Opciones::Opciones_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Opciones_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		cerro_sesion = 1;
		this->Close();
	}
	System::Void Opciones_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Escape){ this->Close(); }
			
	}
	};
}
