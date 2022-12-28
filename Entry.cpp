#include "Entry.h"

namespace def::gui
{
	Entry::Entry(Manager& manager, int32_t id, const olc::vi2d& pos, const olc::vi2d& size, const std::string& text) : Component(manager)
	{
		vSize = size;
		nID = id;
		vPos = pos;
		sText = text;

		if (vSize > olc::vf2d(-1, -1))
		{
			vSize *= olc::vi2d(SYM_SIZE, SYM_SIZE);
			vSize += olc::vi2d(2, 2);
			bFixedSize = true;
		}
	}

	void Entry::DrawSelf(olc::PixelGameEngine& pge)
	{
		if (!bVisible)
		{
			pge.TextEntryEnable(false);
			return;
		}

		if (IsSelected())
		{
			if (bClicked)
			{
				bUpdated = true;
				pge.TextEntryEnable(true, sText);
				sText = pge.TextEntryGetString();
			}
			else
			{
				bUpdated = (pge.TextEntryGetString() != sText);
				sText = pge.TextEntryGetString();
				pge.TextEntryEnable(true, sText);
			}
		}

		if (bHasBackground)
			pge.FillRectDecal(vPos, vSize, m_manager.GetTheme().pBackground);

		if (bHasBorders)
			pge.DrawRectDecal(vPos, vSize, m_manager.GetTheme().pBorders);

		olc::vf2d vText = pge.GetTextSize(sText);

		if (bFixedSize)
		{
			int32_t nRemoveCount = (vText.x - vSize.x) / SYM_SIZE + 1;

			if (nRemoveCount > 0)
			{
				sText.erase(sText.length() - nRemoveCount, nRemoveCount);
				pge.TextEntryEnable(true, sText);
			}
		}
		else
			vSize = vText + olc::vf2d(3.0f, 3.0f);

		pge.DrawStringDecal(olc::vf2d((float)vPos.x + 2.0f, (float)vPos.y + ((float)vSize.y - vText.y) * 0.5f), sText, m_manager.GetTheme().pText);
	}

	void Entry::SetText(const std::string& text)
	{
		bUpdated = true;
		sText = text;
	}

	std::string Entry::GetText()
	{
		return sText;
	}
}
