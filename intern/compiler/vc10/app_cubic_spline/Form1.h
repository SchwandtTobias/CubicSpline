#pragma once

#include "app_cubic_spline/spline_manager.h"

namespace app_cubic_spline 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Panel^  panel_draw;
    protected: 


    private: System::Windows::Forms::ListBox^  SplineList;

    protected: 

    private:
        CSplineManager m_Splines;

    private: System::Windows::Forms::Label^  LabelSpline;



    private: System::Windows::Forms::ListBox^  ListPoints;
    private: System::Windows::Forms::Button^  ButtonAddPoint;
    private: System::Windows::Forms::TextBox^  BoxX;
    private: System::Windows::Forms::TextBox^  BoxY;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Panel^  panel1;
    private: System::Windows::Forms::Panel^  panel2;
    private: System::Windows::Forms::Panel^  panel3;


    private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
            this->panel_draw = (gcnew System::Windows::Forms::Panel());
            this->SplineList = (gcnew System::Windows::Forms::ListBox());
            this->LabelSpline = (gcnew System::Windows::Forms::Label());
            this->ListPoints = (gcnew System::Windows::Forms::ListBox());
            this->ButtonAddPoint = (gcnew System::Windows::Forms::Button());
            this->BoxX = (gcnew System::Windows::Forms::TextBox());
            this->BoxY = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->SuspendLayout();
            // 
            // panel_draw
            // 
            this->panel_draw->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
                | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->panel_draw->AutoSize = true;
            this->panel_draw->BackColor = System::Drawing::Color::White;
            this->panel_draw->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panel_draw->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->panel_draw->ForeColor = System::Drawing::Color::Transparent;
            this->panel_draw->Location = System::Drawing::Point(12, 12);
            this->panel_draw->Name = L"panel_draw";
            this->panel_draw->Size = System::Drawing::Size(600, 423);
            this->panel_draw->TabIndex = 0;
            this->panel_draw->SizeChanged += gcnew System::EventHandler(this, &Form1::panel_draw_SizeChanged);
            this->panel_draw->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel_draw_MouseClick);
            // 
            // SplineList
            // 
            this->SplineList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->SplineList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)), 
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->SplineList->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->SplineList->ForeColor = System::Drawing::SystemColors::WindowText;
            this->SplineList->FormattingEnabled = true;
            this->SplineList->ItemHeight = 21;
            this->SplineList->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Spline 1", L"Spline 2", L"Spline 3"});
            this->SplineList->Location = System::Drawing::Point(618, 36);
            this->SplineList->Name = L"SplineList";
            this->SplineList->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
            this->SplineList->Size = System::Drawing::Size(137, 67);
            this->SplineList->TabIndex = 2;
            this->SplineList->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::SplineList_SelectedIndexChanged);
            this->SplineList->DoubleClick += gcnew System::EventHandler(this, &Form1::SplineList_DoubleClick);
            // 
            // LabelSpline
            // 
            this->LabelSpline->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->LabelSpline->AutoSize = true;
            this->LabelSpline->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->LabelSpline->Location = System::Drawing::Point(619, 12);
            this->LabelSpline->Name = L"LabelSpline";
            this->LabelSpline->Size = System::Drawing::Size(68, 21);
            this->LabelSpline->TabIndex = 3;
            this->LabelSpline->Text = L"Splines:";
            // 
            // ListPoints
            // 
            this->ListPoints->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->ListPoints->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)), 
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->ListPoints->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->ListPoints->FormattingEnabled = true;
            this->ListPoints->ItemHeight = 21;
            this->ListPoints->Location = System::Drawing::Point(618, 133);
            this->ListPoints->Name = L"ListPoints";
            this->ListPoints->Size = System::Drawing::Size(137, 256);
            this->ListPoints->TabIndex = 4;
            this->ListPoints->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::ListPoints_SelectedIndexChanged);
            // 
            // ButtonAddPoint
            // 
            this->ButtonAddPoint->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->ButtonAddPoint->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(250)), 
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->ButtonAddPoint->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->ButtonAddPoint->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->ButtonAddPoint->Location = System::Drawing::Point(728, 401);
            this->ButtonAddPoint->Name = L"ButtonAddPoint";
            this->ButtonAddPoint->Size = System::Drawing::Size(27, 29);
            this->ButtonAddPoint->TabIndex = 5;
            this->ButtonAddPoint->Text = L"+";
            this->ButtonAddPoint->UseVisualStyleBackColor = false;
            this->ButtonAddPoint->Click += gcnew System::EventHandler(this, &Form1::ButtonAddPoint_Click);
            // 
            // BoxX
            // 
            this->BoxX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->BoxX->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->BoxX->Location = System::Drawing::Point(618, 401);
            this->BoxX->Name = L"BoxX";
            this->BoxX->Size = System::Drawing::Size(50, 29);
            this->BoxX->TabIndex = 6;
            // 
            // BoxY
            // 
            this->BoxY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->BoxY->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->BoxY->Location = System::Drawing::Point(674, 401);
            this->BoxY->Name = L"BoxY";
            this->BoxY->Size = System::Drawing::Size(50, 29);
            this->BoxY->TabIndex = 7;
            // 
            // label1
            // 
            this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(619, 109);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(68, 21);
            this->label1->TabIndex = 8;
            this->label1->Text = L"Punkte:";
            // 
            // panel1
            // 
            this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->panel1->BackColor = System::Drawing::Color::DarkRed;
            this->panel1->Location = System::Drawing::Point(624, 41);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(25, 15);
            this->panel1->TabIndex = 9;
            // 
            // panel2
            // 
            this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->panel2->BackColor = System::Drawing::Color::RoyalBlue;
            this->panel2->Location = System::Drawing::Point(624, 83);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(25, 15);
            this->panel2->TabIndex = 10;
            // 
            // panel3
            // 
            this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->panel3->BackColor = System::Drawing::Color::SeaGreen;
            this->panel3->Location = System::Drawing::Point(624, 62);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(25, 15);
            this->panel3->TabIndex = 11;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Window;
            this->ClientSize = System::Drawing::Size(761, 442);
            this->Controls->Add(this->panel_draw);
            this->Controls->Add(this->panel3);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->ListPoints);
            this->Controls->Add(this->SplineList);
            this->Controls->Add(this->BoxX);
            this->Controls->Add(this->LabelSpline);
            this->Controls->Add(this->BoxY);
            this->Controls->Add(this->ButtonAddPoint);
            this->MaximumSize = System::Drawing::Size(1680, 1050);
            this->MinimumSize = System::Drawing::Size(640, 480);
            this->Name = L"Form1";
            this->Text = L"Kubische Spline Interpolation";
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load_1);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void Form1_Load_1(System::Object^  sender, System::EventArgs^  e) 
        {          
            SplineList->SelectedIndex = 0;
        }

private: System::Void panel_draw_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
        {
            // -----------------------------------------------------------------------------
            // add click to instances (splines) selected in list
            // -----------------------------------------------------------------------------
            int SelectedIndex = SplineList->SelectedIndex;

            if (SelectedIndex != -1)
            {
                Core::Math::Float2 NewPoint;
                NewPoint[0] = e->X;
                NewPoint[1] = e->Y;

                NewPoint = SystemToCartesian(NewPoint);

                m_Splines.GetSpline(SelectedIndex)->AddPoint(NewPoint[0], NewPoint[1]);
            }
            
            // -----------------------------------------------------------------------------
            // redraw spline
            // -----------------------------------------------------------------------------
            DrawSpline();

            // -----------------------------------------------------------------------------
            // add points to list
            // -----------------------------------------------------------------------------
            InsertPointsToList();
        }
private: System::Void SplineList_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
            // -----------------------------------------------------------------------------
            // open dialog edit spline
            // -----------------------------------------------------------------------------
        }


    public:
        void DrawSpline()
        {
            Graphics ^ Graphic = panel_draw->CreateGraphics();
            Pen ^ LinePen      = gcnew Pen(Color::LightGray);
            Pen ^ SplinePen    = gcnew Pen(Color::Black);

            // -----------------------------------------------------------------------------
            // restore background
            // -----------------------------------------------------------------------------
            Graphic->Clear(Color::White);

            // -----------------------------------------------------------------------------
            // draw line
            // -----------------------------------------------------------------------------
            int PanelWidth  = panel_draw->Size.Width;
            int PanelHeight = panel_draw->Size.Height;

            LinePen->DashCap = System::Drawing::Drawing2D::DashCap::Flat;

            //x-lines
            for (int HeightPosition = 0; HeightPosition < PanelHeight; HeightPosition += 10)
            {
                Point px0(0,          HeightPosition);
                Point px1(PanelWidth, HeightPosition);
                Graphic->DrawLine(LinePen, px0, px1);
            }
            

            //y-line
            for (int WidthPosition = 0; WidthPosition < PanelWidth; WidthPosition += 10)
            {
                Point py0(WidthPosition, 0);
                Point py1(WidthPosition, PanelHeight);
                Graphic->DrawLine(LinePen, py0, py1);
            }

            LinePen->Color = Color::Gray;

            int MiddleRasterWidth = (int)(PanelWidth / 2 / 10) * 10;
            int MiddleRasterHeight = (int)(PanelHeight / 2 / 10) * 10;

            Point py0(MiddleRasterWidth, 0);
            Point py1(MiddleRasterWidth, PanelHeight);
            Graphic->DrawLine(LinePen, py0, py1);

            Point px0(0,          MiddleRasterHeight);
            Point px1(PanelWidth, MiddleRasterHeight);
            Graphic->DrawLine(LinePen, px0, px1);

            // -----------------------------------------------------------------------------
            // draw points and splines
            // -----------------------------------------------------------------------------
            for (int IndexOfSpline = 0; IndexOfSpline < CSplineManager::s_MAXSPLINES; ++IndexOfSpline)
            {
                if (IndexOfSpline == 0)
                {
                    SplinePen->Color = Color::DarkRed;
                }
                else if (IndexOfSpline == 1)
                {
                    SplinePen->Color = Color::SeaGreen;
                }
                else if (IndexOfSpline == 2)
                {
                    SplinePen->Color = Color::RoyalBlue;
                }
                else
                {
                    SplinePen->Color = Color::Black;
                }

                // -----------------------------------------------------------------------------
                // draw points
                // -----------------------------------------------------------------------------
                std::vector<Core::Math::Float2> Points = m_Splines.GetPoints(IndexOfSpline);

                int InsertedPoints = Points.size();

                for (int IndexOfPoint = 0; IndexOfPoint < InsertedPoints; ++IndexOfPoint)
                {
                    //draw
                    Core::Math::Float2 ActualPoint = Points[IndexOfPoint];

                    ActualPoint = CartesianToSystem(ActualPoint);

                    Point p1(ActualPoint[0], ActualPoint[1]);
                    
                    Graphic->DrawEllipse(SplinePen, p1.X - 3, p1.Y - 3, 6, 6);

                }

                // -----------------------------------------------------------------------------
                // draw interpolation
                // -----------------------------------------------------------------------------
                CSpline^ CurrentSpline = m_Splines.GetSpline(IndexOfSpline);

                float MinX = CurrentSpline->MinX();
                float MaxX = CurrentSpline->MaxX();

                Core::Math::Float2 LastPoint(MinX, CurrentSpline->Interpolate(MinX));
                LastPoint = CartesianToSystem(LastPoint);

                Core::Math::Float2 NextPoint(0, 0);

                for (float xPosition = MinX; xPosition < MaxX; xPosition += 0.2f)
                {
                    NextPoint[0] = xPosition;
                    NextPoint[1] = CurrentSpline->Interpolate(xPosition);

                    NextPoint = CartesianToSystem(NextPoint);

                    Point PNext(NextPoint[0], NextPoint[1]);
                    Point PLast(LastPoint[0], LastPoint[1]);

                    Graphic->DrawLine(SplinePen, PLast, PNext);

                    LastPoint = NextPoint;
                }

                delete CurrentSpline;
            }

            delete LinePen;
            delete SplinePen;
            delete Graphic;
        }

        void InsertPointsToList()
        {
            if (SplineList->SelectedIndex != -1)
            {
                // -----------------------------------------------------------------------------
                // change points in list
                // -----------------------------------------------------------------------------
                int SelectedIndex = SplineList->SelectedIndex;

                ListPoints->Items->Clear();

                // -----------------------------------------------------------------------------
                // add points
                // -----------------------------------------------------------------------------
                std::vector<Core::Math::Float2> Points = m_Splines.GetPoints(SelectedIndex);

                int InsertedPoints = Points.size();

                for (int IndexOfPoint = 0; IndexOfPoint < InsertedPoints; ++IndexOfPoint)
                {
                    //add
                    Core::Math::Float2 ActualPoint = Points[IndexOfPoint];

                    ListPoints->Items->Add(PointToString(ActualPoint));
                }
            }
        }

        Core::Math::Float2 StringToPoint(String^ _ValuePair)
        {
            cli::array<String^>^ Pair = _ValuePair->Split(';');

            Core::Math::Float2 NewPoint;
            NewPoint[0] = System::Convert::ToInt32(Pair[0]);
            NewPoint[1] = System::Convert::ToInt32(Pair[1]);

            return NewPoint;
        }

        String^ PointToString(Core::Math::Float2 _Point)
        {
            return System::Convert::ToString(_Point[0]) + ";" + System::Convert::ToString(-_Point[1]);
        }

        Core::Math::Float2 SystemToCartesian(Core::Math::Float2 _Point)
        {
            _Point[0] = _Point[0] / 10 - (panel_draw->Size.Width / 2 / 10);
            _Point[1] = (_Point[1] / 10 - (panel_draw->Size.Height / 2 / 10));

            return _Point;
        }

        Core::Math::Float2 CartesianToSystem(Core::Math::Float2 _Point)
        {
            _Point[0] = (_Point[0] + (panel_draw->Size.Width / 2 / 10)) * 10;
            _Point[1] = ((_Point[1] + (panel_draw->Size.Height / 2 / 10)) * 10);

            return _Point;
        }

private: System::Void ButtonAddPoint_Click(System::Object^  sender, System::EventArgs^  e) 
         {
             // -----------------------------------------------------------------------------
             // modify point or add new one
             // -----------------------------------------------------------------------------

             int SelectedSplineIndex = SplineList->SelectedIndex;
             int SelectedPointIndex = ListPoints->SelectedIndex;

             //remove old point
             if (SelectedSplineIndex != -1)
             {
                 bool DeleteOnly = false;

                 if (SelectedPointIndex != -1)
                 {
                     // -----------------------------------------------------------------------------
                     // delete old point
                     // -----------------------------------------------------------------------------
                     m_Splines.RemovePoint(SelectedSplineIndex, SelectedPointIndex);

                     if (BoxX->Text == "" || BoxY->Text == "")
                     {
                         DeleteOnly = true;
                     }
                 }
                 
                 if (!DeleteOnly)
                 {
                        // -----------------------------------------------------------------------------
                        // try add new points
                        // -----------------------------------------------------------------------------
                        try
                        {
                            Core::Math::Float2 NewPoint;
                            NewPoint[0] =  System::Convert::ToInt32(BoxX->Text);
                            NewPoint[1] = -System::Convert::ToInt32(BoxY->Text);

                            m_Splines.GetSpline(SelectedSplineIndex)->AddPoint(NewPoint[0], NewPoint[1]);
                        }
                        catch (...)
                        {
                        }
                 }

                 // -----------------------------------------------------------------------------
                 // refresh all
                 // -----------------------------------------------------------------------------
                 DrawSpline();
                 InsertPointsToList();
             }
         }
private: System::Void SplineList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
             InsertPointsToList();
         }
private: System::Void ListPoints_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
             if (ListPoints->SelectedIndex != -1)
             {
                 String^ ValuePair = ListPoints->SelectedItem->ToString();

                 Core::Math::Float2 NewPoint = StringToPoint(ValuePair);

                 BoxX->Text = System::Convert::ToString(NewPoint[0]);
                 BoxY->Text = System::Convert::ToString(NewPoint[1]);
             }
         }
private: System::Void panel_draw_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
             DrawSpline();
         }
};
}

