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
			m_vecComponents.back()->Clicked() = false;
		c->Clicked() = true;

		m_nSelected = m_vecComponents.size();
		m_vecComponents.push_back(c);
		return m_nSelected;
	}

	void Manager::Update(olc::PixelGameEngine* pge)
	{
		for (auto& c : m_vecComponents)
		{
			c->Clicked() = false;
			c->Updated() = false;

			if (
				pge->GetMousePos().x > c->Pos().x && pge->GetMousePos().x < c->Pos().x + c->Size().x &&
				pge->GetMousePos().y > c->Pos().y && pge->GetMousePos().y < c->Pos().y + c->Size().y
			)
			{
				c->OnHover();

				if (pge->GetMouse(0).bPressed)
				{
					m_nSelected = c->Order();
					c->Clicked() = true;
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
