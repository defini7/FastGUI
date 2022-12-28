#pragma once

#include "olcPixelGameEngine.h"
#include "Manager.h"

namespace def::gui
{
	constexpr int32_t SYM_SIZE = 8;

	class Manager;

	class Component
	{
	public:
		Component(Manager& m);
		virtual ~Component() = default;

		virtual void DrawSelf(olc::PixelGameEngine* pge) = 0;

		bool IsSelected();
		
		bool& FixedSize();
		bool& Visible();
		bool& HasBackground();
		bool& HasBorders();
		bool& Clicked();
		bool& Updated();

		int32_t& ID();
		size_t& Order();
		olc::vi2d& Pos();
		olc::vi2d& Size();

		virtual void OnClick();
		virtual void OnHover();
	
	protected:
		int32_t nID = -1;
		size_t nOrder = -1;

		olc::vi2d vPos = { 0, 0 };
		olc::vi2d vSize = { 0, 0 };

		bool bFixedSize = false;
		bool bVisible = true;
		bool bHasBackground = true;
		bool bHasBorders = true;

		bool bClicked = false;
		bool bUpdated = false;

		Manager& manager;
	};
}
