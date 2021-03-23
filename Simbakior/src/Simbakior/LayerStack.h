#pragma once

#include "Simbakior/Core.h"
#include "Layer.h"

#include <vector>

namespace Simbakior
{
	class SIMBAKIOR_API LayerStack
	{
		/*
		* LayerStack owns the layers it contains as long as it contains them.
		* If the application pops a layer, it becomes its owner.
		* Overlays will always be after layers.
		 */
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};

}

