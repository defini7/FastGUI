#include "CheckBox.h"

namespace def::gui
{
	CheckBox::CheckBox(Manager& m, int32_t id, const std::string& text, const olc::vi2d& pos, bool checked) : Component(m)
	{
		nID = id;
		vPos = pos;
		bChecked = checked;
		lText = new Label(m, -1, text, vPos + olc::vi2d(SYM_SIZE + SYM_SIZE / 2, 0));
		vSize = olc::vi2d(SYM_SIZE + 3.0f, SYM_SIZE + 3.0f);
	}

	void CheckBox::DrawSelf(olc::PixelGameEngine* pge)
	{
		if (bHasBackground)
			pge->FillRectDecal(vPos, vSize, manager.GetTheme().pBackground);

		if (bHasBorders)
			pge->DrawRectDecal(vPos, vSize, manager.GetTheme().pBorders);

		if (bClicked)
			bUpdated = true;

		if (bChecked)
		{
			pge->FillRectDecal(vPos + olc::vf2d(1.0f, 1.0f), olc::vf2d(SYM_SIZE, SYM_SIZE) + olc::vf2d(1.0f, 1.0f), manager.GetTheme().pText);
			lText->DrawSelf(pge);
		}
	}

	void CheckBox::SetText(const std::string& text)
	{
		lText->SetText(text);
	}

	std::string CheckBox::GetText()
	{
		bUpdated = true;
		return lText->GetText();
	}

	bool CheckBox::Checked()
	{
		return bChecked;
	}

	void CheckBox::OnClick()
	{
		Component::OnClick();
		bUpdated = true;
		bChecked = !bChecked;
	}
}
