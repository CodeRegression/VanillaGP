//--------------------------------------------------
// Add the logic to render trees
//
// @author: Wild Boar
//
// @date: 2022-12-30
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <VanillaGPLib/GrammarBase/RendererBase.h>

namespace NVL_AI
{
	class TreeRenderer : public RendererBase
	{
	public:
		TreeRenderer(SolutionFactoryBase * factory);

		virtual string Render(Solution * solution) override;
	};
}
