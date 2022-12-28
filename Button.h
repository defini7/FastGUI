#pragma once

#include "Manager.h"
#include "Label.h"

#include "olcPixelGameEngine.h"

#include <cstdint>
#include <string>

namespace def::gui
{
	class Button : public Component
	{
	public:
		Button() = default;
		Button(Manager& m, int32_t id, const std::string& text, const olc::vi2d& pos, const olc::vi2d& size = { -1, -1 });

		virtual void DrawSelf(olc::PixelGameEngine* pge) override;

		void SetText(const std::string& text);
		std::string GetText();

	protected:
		std::string sText;

	};
}
