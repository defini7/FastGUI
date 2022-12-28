#pragma once

#include "Manager.h"
#include "Label.h"
#include "Component.h"
#include "olcPixelGameEngine.h"

#include <string>
#include <cstdint>

namespace def::gui
{
	class CheckBox : public Component
	{
	public:
		CheckBox() = default;
		CheckBox(Manager& m, int32_t id, const std::string& text, const olc::vi2d& pos, bool checked = false);

		virtual void DrawSelf(olc::PixelGameEngine* pge) override;

		void SetText(const std::string& text);
		std::string GetText();

		bool Checked();

	protected:
		virtual void OnClick() override;

		bool bChecked;
		Label* lText;
	};
}
