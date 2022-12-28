#include "Button.h"

namespace def::gui
{
	Button::Button(Manager& m, int32_t id, const std::string& text, const olc::vi2d& pos, const olc::vi2d& size) : Component(m)
	{
		nID = id;
		vPos = pos;
		vSize = size;
		sText = text;

		if (vSize > olc::vf2d(-1, -1))
		{
			vSize *= olc::vi2d(SYM_SIZE, SYM_SIZE);
			vSize.y += 2;
			bFixedSize = true;
		}
	}

	void Button::DrawSelf(olc::PixelGameEngine* pge)
	{
		if (!bVisible) return;

		if (bHasBackground)
			pge->FillRectDecal(vPos, vSize, manager.GetTheme().pButtonBackground);

		if (bHasBorders)
			pge->DrawRectDecal(vPos, vSize, manager.GetTheme().pBorders);

		olc::vf2d vText = pge->GetTextSize(sText);

		if (!bFixedSize) vSize = vText + olc::vf2d(3.0f, 3.0f);
		pge->DrawStringDecal(olc::vf2d((float)vPos.x + 2.0f, (float)vPos.y + abs((float)vSize.y - vText.y) * 0.5f), sText, manager.GetTheme().pText);
	}

	void Button::SetText(const std::string& text)
	{
		bUpdated = true;
		sText = text;
	}

	std::string Button::GetText()
	{
		return sText;
	}
}
