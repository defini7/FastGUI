#pragma once

#include "Component.h"
#include "Theme.h"

#include "olcPixelGameEngine.h"

namespace def::gui
{
	class Component;

	class Manager
	{
	public:
		Manager() = default;
		~Manager();

		size_t AddComponent(Component* c);
		void Update(olc::PixelGameEngine* pge);

		Theme& GetTheme();
		size_t& GetSelected();

	private:
		std::vector<Component*> m_vecComponents;
		Theme m_theme;

		size_t m_nSelected;
	};
}
