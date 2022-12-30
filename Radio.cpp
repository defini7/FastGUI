#include "Radio.h"

namespace def::gui
{
	Radio::Radio(Manager& m, int32_t id, const std::string& text, const olc::vi2d& pos, int32_t radius, bool checked) : Component(m)
	{
		if (radius < 0)
			radius = SYM_SIZE + 3.0f;

		nID = id;
		vPos = pos;
		bChecked = checked;
		lText = new Label(m, -1, text, vPos + olc::vi2d(SYM_SIZE + SYM_SIZE / 2, 0));
		vSize = olc::vi2d(radius, radius);
	}

	void Radio::DrawSelf(olc::PixelGameEngine* pge)
	{
		if (bHasBackground)
			pge->FillCircle(vPos + vSize / 2, vSize.y / 2, manager.GetTheme().pBackground);

		if (bHasBorders)
			pge->DrawCircle(vPos + vSize / 2, vSize.y / 2, manager.GetTheme().pBorders);

		if (bClicked)
			bUpdated = true;

		if (bChecked)
		{
			pge->FillCircle(vPos + vSize / 2, vSize.y / 2, manager.GetTheme().pText);
			lText->DrawSelf(pge);
		}
	}

	void Radio::SetText(const std::string& text)
	{
		lText->SetText(text);
	}

	std::string Radio::GetText()
	{
		bUpdated = true;
		return lText->GetText();
	}

	bool Radio::Checked()
	{
		return bChecked;
	}

	void Radio::OnClick()
	{
		Component::OnClick();
		bUpdated = true;
		bChecked = !bChecked;
	}
}
