#include "Component.h"

namespace def::gui
{
	Component::Component(def::gui::Manager& m) : manager(m)
	{
		nOrder = manager.AddComponent(this);
	}

	bool Component::IsSelected()
	{
		return nOrder == manager.GetSelected();
	}

	bool& Component::FixedSize()
	{
		return bFixedSize;
	}

	bool& Component::Visible()
	{
		return bVisible;
	}

	bool& Component::HasBackground()
	{
		return bHasBackground;
	}

	bool& Component::HasBorders()
	{
		return bHasBorders;
	}

	bool& Component::Clicked()
	{
		return bClicked;
	}

	bool& Component::Updated()
	{
		return bUpdated;
	}

	int32_t& Component::ID()
	{
		return nID;
	}

	size_t& Component::Order()
	{
		return nOrder;
	}

	olc::vi2d& Component::Pos()
	{
		return vPos;
	}

	olc::vi2d& Component::Size()
	{
		return vSize;
	}

	void Component::OnClick()
	{
		manager.GetSelected() = nOrder;
	}

	void Component::OnHover() {}
}
