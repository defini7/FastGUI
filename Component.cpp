#include "Component.h"

namespace def::gui
{
	Component::Component(def::gui::Manager& m) : m_manager(m)
	{
		nOrder = m_manager.AddComponent(this);
	}

	bool Component::IsSelected()
	{
		return nOrder == m_manager.GetSelected();
	}

	void Component::OnClick()
	{
		m_manager.GetSelected() = nOrder;
	}

	void Component::OnHover() {}
}
