#pragma once

namespace SebaSteam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PaginaPelis
	/// </summary>
	public ref class PaginaPelis : public System::Windows::Forms::Form
	{
	public:
		PaginaPelis(int tipo, char tmp)
		{
			InitializeComponent();
			this->cargar(tipo, tmp);
		}

	protected:
		
		~PaginaPelis()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titulo;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PaginaPelis::typeid));
			this->titulo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// titulo
			// 
			this->titulo->AutoSize = true;
			this->titulo->BackColor = System::Drawing::Color::Transparent;
			this->titulo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titulo->ForeColor = System::Drawing::Color::White;
			this->titulo->Location = System::Drawing::Point(114, 24);
			this->titulo->Name = L"titulo";
			this->titulo->Size = System::Drawing::Size(1079, 135);
			this->titulo->TabIndex = 0;
			this->titulo->Text = L"Mejores calificadas";
			// 
			// PaginaPelis
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1300, 800);
			this->ControlBox = false;
			this->Controls->Add(this->titulo);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"PaginaPelis";
			this->Text = L"PaginaPelis";
			this->Load += gcnew System::EventHandler(this, &PaginaPelis::PaginaPelis_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void PaginaPelis_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	void cargar(int tipo, char tmp) {
		if (tipo == 1) titulo->Text = "Mejores calificadas";
		else if (tipo == 2) titulo->Text = "Vistos recientemente";
		else titulo->Text = "Peliculas que inicien con la letra '" + tmp + "'";
	}
	};
}
