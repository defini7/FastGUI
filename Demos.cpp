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

		label1 = new def::gui::Label(m, 10000, "Enter your name: ", olc::vi2d(10, 10));
		entry1 = new def::gui::Entry(m, 10001, olc::vi2d(10, 30), olc::vi2d(15, 1));
		entry2 = new def::gui::Entry(m, 10002, olc::vi2d(10, 50), olc::vi2d(10, 1));

		for (size_t i = 0; i < 4; i++)
			voting[i] = new def::gui::CheckBox(m, 10003 + i, "something" + std::to_string(i), olc::vi2d(10, 70 + i * 15));

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		m.Update(*this);

		if (label1->bClicked)
			std::cout << "[label1] " << label1->GetText() << std::endl;

		if (entry1->bUpdated)
			std::cout << "[entry1] " << entry1->GetText() << std::endl;
		
		if (entry2->bUpdated)
			std::cout << "[entry2] " << entry2->GetText() << std::endl;

		for (size_t i = 0; i < 4; i++)
		{
			if (voting[i]->bUpdated)
				std::cout << "[checkbox" << i << "] " << voting[i]->GetText() << std::endl;
		}

		return true;
	}

private:
	def::gui::Manager m;

	def::gui::Label* label1;
	def::gui::Entry* entry1;
	def::gui::Entry* entry2;
	
	std::array<def::gui::CheckBox*, 4> voting;

};

int main()
{
	GUI demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();

	return 0;
}



