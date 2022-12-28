#include "Manager.h"

namespace def::gui
{
	Manager::~Manager()
	{
		for (auto& c : m_vecComponents)
			delete c;
	}

	size_t Manager::AddComponent(Component* c)
	{
		if (!m_vecComponents.empty())
			m_vecComponents.back()->bClicked = false;
		c->bClicked = true;

		m_nSelected = m_vecComponents.size();
		m_vecComponents.push_back(c);
		return m_nSelected;
	}

	void Manager::Update(olc::PixelGameEngine& pge)
	{
		for (auto& c : m_vecComponents)
		{
			c->bClicked = false;
			c->bUpdated = false;

			if (
				pge.GetMousePos().x > c->vPos.x && pge.GetMousePos().x < c->vPos.x + c->vSize.x &&
				pge.GetMousePos().y > c->vPos.y && pge.GetMousePos().y < c->vPos.y + c->vSize.y
			)
			{
				c->OnHover();

				if (pge.GetMouse(0).bPressed)
				{
					m_nSelected = c->nOrder;
					c->bClicked = true;
					c->OnClick();
				}
			}

			c->DrawSelf(pge);
		}
	}

	Theme& Manager::GetTheme()
	{
		return m_theme;
	}

	size_t& Manager::GetSelected()
	{
		return m_nSelected;
	}
}
