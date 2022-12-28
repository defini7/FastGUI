#pragma once

#include "Component.h"
#include "Manager.h"

#include "olcPixelGameEngine.h"

#include <cstdint>
#include <string>

namespace def::gui
{
	class Entry : public Component
	{
	public:
		Entry() = default;
		Entry(Manager& manager, int32_t id, const olc::vi2d& pos, const olc::vi2d& size = { -1, -1 }, const std::string& text = "");

		virtual void DrawSelf(olc::PixelGameEngine& pge) override;

		void SetText(const std::string& text);
		std::string GetText();

	protected:
		std::string sText;
	};
}
