//--------------------------------------------------
// Unit Tests for class TreeRenderer
//
// @author: Wild Boar
//
// @date: 2022-12-30
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathExpLib/NodeFactory.h>
#include <MathExpLib/TreeFactory.h>
#include <MathExpLib/TreeRenderer.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Perform a basic render test
 */
TEST(TreeRenderer_Test, basic_render_test)
{
	// Initialize the factory
	auto available = vector<int>(); NodeFactory::GetAllNodeTypes(available);
	auto properties = new TreeProperties(available, 4, 3);
	auto factory = TreeFactory(properties);

	// Generate a solution tree
	auto initializer = DNAInitializer(vector<int> { 1, 4, 5, 6, 0, 2, 200, 6, 1 });
	auto solution = factory.Generate(&initializer);

	// Generate the code
	auto renderer = factory.GetRenderer();
	auto code = renderer->Render(solution);

	// Confirm
	ASSERT_EQ(code, string("((p[0] * 2) + -p[1])"));

	// Free memory
	delete solution; delete renderer;
}
