#pragma once
#include"Dependencias.h"
#include"Pelicula.h"
namespace SebaSteam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Calificar
	/// </summary>
	public ref class Calificar : public System::Windows::Forms::Form
	{
	public:
		Calificar(Pelicula* peli)
		{
			InitializeComponent();
			peliGuardada = peli;
		}
		bool califcado = 0;
		int nuevaCalificacion = 0;
	protected:
		
		~Calificar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ calif;

	private:
		Pelicula* peliGuardada;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Calificar::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->calif = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(20, 221);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(663, 38);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(22, 185);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(183, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Calificacion:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// calif
			// 
			this->calif->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"calif.BackgroundImage")));
			this->calif->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->calif->Location = System::Drawing::Point(187, 311);
			this->calif->Name = L"calif";
			this->calif->Size = System::Drawing::Size(349, 90);
			this->calif->TabIndex = 2;
			this->calif->UseVisualStyleBackColor = true;
			this->calif->Click += gcnew System::EventHandler(this, &Calificar::calif_Click);
			// 
			// Calificar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(715, 420);
			this->Controls->Add(this->calif);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Calificar";
			this->Padding = System::Windows::Forms::Padding(1);
			this->Text = L"Calificar";
			this->Load += gcnew System::EventHandler(this, &Calificar::Calificar_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Calificar_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	System::Void calif_Click(System::Object^ sender, System::EventArgs^ e) {
		float newNum;
		if (Single::TryParse(textBox1->Text, newNum)) {
			if (newNum >= 0 && newNum <= 10) {
				califcado = 1;
				peliGuardada->AgregarCalificacion(newNum);
				MessageBox::Show("Pelicula calificada correctamente", "Proceso realizado correctamente", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				this->Close();
			}
			else {
				MessageBox::Show("Ingrese un numero entre 0 y 10", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			MessageBox::Show("Ingrese un numero real valido", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
