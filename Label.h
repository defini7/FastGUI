#pragma once

#include "Component.h"
#include "Manager.h"

#include "olcPixelGameEngine.h"

#include <cstdint>
#include <string>

namespace def::gui
{
	class Label : public Component
	{
	public:
		Label() = default;
		Label(Manager& m, int32_t id, const std::string& text, const olc::vi2d& pos, const olc::vi2d& size = { -1, -1 });

		virtual void DrawSelf(olc::PixelGameEngine* pge) override;
		
		void SetText(const std::string& text);
		std::string GetText();

	protected:
		std::string sText;

	};
}
