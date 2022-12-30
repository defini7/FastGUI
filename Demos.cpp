#include "FastGui.h"

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <array>

class GUI : public olc::PixelGameEngine
{
public:
	GUI()
	{
		sAppName = "GUI";
	}

public:
	bool OnUserCreate() override
	{
		auto& theme = m.GetTheme();
		theme.pBackground = olc::DARK_BLUE;
		theme.pBorders = olc::DARK_GREY;
		theme.pText = olc::WHITE;
		theme.pButtonBackground = olc::GREY;

		label1 = new def::gui::Label(m, 10000, "Enter your name: ", olc::vi2d(10, 10));
		
		entry1 = new def::gui::Entry(m, 10001, olc::vi2d(10, 30), olc::vi2d(16, 1));
		button1 = new def::gui::Button(m, 10010, "Submit", olc::vi2d(10 + 17 * def::gui::SYM_SIZE, 30));

		for (size_t i = 0; i < 4; i++)
			voting[i] = new def::gui::Radio(m, 10003 + i, "something" + std::to_string(i), olc::vi2d(10, 70 + i * 15));

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);

		m.Update(this);

		if (button1->Clicked())
			std::cout << "[" << entry1->ID() << "] " << entry1->GetText() << std::endl;

		for (size_t i = 0; i < 4; i++)
		{
			if (voting[i]->Updated() && voting[i]->Checked())
				std::cout << "[" << voting[i]->ID() << "] " << voting[i]->GetText() << std::endl;
		}

		return true;
	}

private:
	def::gui::Manager m;

	def::gui::Label* label1;
	def::gui::Button* button1;
	def::gui::Entry* entry1;
	
	std::array<def::gui::Radio*, 4> voting;

};

int main()
{
	GUI demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();

	return 0;
}



