//--------------------------------------------------
// Unit Tests for class Population
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#include <gtest/gtest.h>

#include <VanillaGPLib/GrammarBase/DNAInitializer.h>
#include <VanillaGPLib/GrammarBase/CalculatorBase.h>

#include <VanillaGPLib/Population.h>
using namespace NVL_AI;

//--------------------------------------------------
// Defintion of a test factory
//--------------------------------------------------

class TestFactory : public SolutionFactoryBase
{
private:
	vector<int> _scores;
	int _index;
public:
	TestFactory() {  _scores = vector<int> {3, 1, 2, 5, 4 }; _index = 0; }

	virtual Solution * Generate(InitializerBase * initializer, int level) override
	{
		auto score = _scores[_index++]; if (_index >= _scores.size()) _index = 0;
		auto result = new Solution(vector<int> {score }); result->Score = score;
		return result;
	}

	virtual Solution * Breed(InitializerBase * initializer, Solution * mother, Solution * father) override 
	{ 
		auto value = (mother->Score + father->Score) *.5;
		auto result = new Solution(vector<int> { (int)round(value)}); result->Score = value;
		return result;
	}

	virtual Solution * Mutate(InitializerBase * initializer, Solution * solution, double probability) override 
	{ 
		auto select = initializer->GetNext(0, 100); 
		auto performMutate = (select / 100.0) <= probability;

		if (performMutate) 
		{
			auto dna = vector<int> { solution->DNA[0] + 2 };
			auto clone = new Solution(dna); clone->Score = solution->Score + 2;
			return clone;
		} 
		else 
		{
			auto clone = new Solution(solution->DNA); clone->Score = solution->Score;
			return clone;
		}
	}
	
	virtual CalculatorBase * GetCalculator(Mat& params) override { return nullptr; }
	virtual string GetGrammarName() override { return "test_grammar"; }
	virtual int GetDepthLimit() override {return 1; };	
};

//--------------------------------------------------
// Definition of a test evaluator
//--------------------------------------------------

class TestEvaluator : public EvaluatorBase
	{
	private:
		double _optimalScore;
	public:
		TestEvaluator() : EvaluatorBase(nullptr, Mat()) { _optimalScore = 0; }
		virtual double Eval(Solution * solution) { return solution->Score; }
		virtual Mat GetParams() override { return Mat(); }
		virtual double GetOptimalScore() override { return _optimalScore; }
		inline void SetOptimalScore(double value) { _optimalScore = value; }
	};

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirms that we are able to retain the best results
 */
TEST(Population_Test, best_evaluation_retention)
{
	// Setup: Setup base elements
	auto dash = CodeDash("127.0.0.1", "/codedash/", "80");
	auto factory = TestFactory(); auto evaluator = TestEvaluator();
	
	// Create our population
	auto population = Population(&factory, &dash, "test", "test", 5, 10, 5, 0);
	ASSERT_EQ(population.GetPopulation().size(), 5);

	// Execute
	population.Evaluate(&evaluator, 3);

	// Confirm
	ASSERT_EQ(population.GetBestSolutions().size(), 3);
	ASSERT_EQ(population.GetBestSolutions()[0]->Score, 1);
	ASSERT_EQ(population.GetBestSolutions()[1]->Score, 2);
	ASSERT_EQ(population.GetBestSolutions()[2]->Score, 3);
}

/**
 * @brief Confirm generation termination
 */
TEST(Population_Test, generation_terminate)
{
	// Setup: Setup base elements
	auto dash = CodeDash("127.0.0.1", "/codedash/", "80");
	auto factory = TestFactory(); auto evaluator = TestEvaluator();
	
	// Create our population
	auto population = Population(&factory, &dash, "test", "test", 5, 10, 5, 0);
	ASSERT_EQ(population.GetPopulation().size(), 5);

	// Execute
	ASSERT_FALSE(population.Terminate());
	population.Evaluate(&evaluator, 3);
	ASSERT_FALSE(population.Terminate());

	population.SetGeneration(10);
	population.Evaluate(&evaluator, 3);
	ASSERT_TRUE(population.Terminate());
}

/**
 * @brief Confirm flat line termination
 */
TEST(Population_Test, flat_line_terminate)
{
// Setup: Setup base elements
	auto dash = CodeDash("127.0.0.1", "/codedash/", "80");
	auto factory = TestFactory(); auto evaluator = TestEvaluator();
	
	// Create our population
	auto population = Population(&factory, &dash, "test", "test", 5, 10, 3, 0);
	ASSERT_EQ(population.GetPopulation().size(), 5);

	// Execute
	ASSERT_FALSE(population.Terminate());
	
	population.Evaluate(&evaluator, 3);
	ASSERT_FALSE(population.Terminate());

	population.Evaluate(&evaluator, 3);
	ASSERT_FALSE(population.Terminate());

	population.Evaluate(&evaluator, 3);
	ASSERT_TRUE(population.Terminate());
}

/**
 * @brief Confirm termination because solution found
 */
TEST(Population_Test, solved_terminate)
{
	// Setup: Setup base elements
	auto dash = CodeDash("127.0.0.1", "/codedash/", "80");
	auto factory = TestFactory(); auto evaluator = TestEvaluator();
	
	// Create our population
	auto population = Population(&factory, &dash, "test", "test", 5, 10, 5, 0);
	ASSERT_EQ(population.GetPopulation().size(), 5);

	// Execute
	ASSERT_FALSE(population.Terminate());
	population.Evaluate(&evaluator, 3);
	ASSERT_FALSE(population.Terminate());

	evaluator.SetOptimalScore(1);
	population.Evaluate(&evaluator, 3);
	ASSERT_TRUE(population.Terminate());
}

/**
 * @brief Test the formation of the next generation
 */
TEST(Population_Test, next_generation) 
{
	// Setup: Setup base elements
	auto dash = CodeDash("127.0.0.1", "/codedash/", "80");
	auto factory = TestFactory(); auto evaluator = TestEvaluator();
	
	// Create our population
	auto population = Population(&factory, &dash, "test", "test", 5, 10, 5, 0);
	ASSERT_EQ(population.GetPopulation().size(), 5);

	// Evaluate the population (with retain 3)
	population.Evaluate(&evaluator, 3);

	// Spawn the next generation
	auto initializer = DNAInitializer(vector<int> { 1, 4, 2, 30, 2, 3, 0, 60 } );
	population.NextGeneration(0.4, 3, &initializer);

	// Confirm the next generation
	ASSERT_EQ(population.GetGeneration(), 1);
	ASSERT_EQ(population.GetPopulation().size(), 5);
	ASSERT_EQ(population.GetPopulation()[0]->Score, 1);
	ASSERT_EQ(population.GetPopulation()[1]->Score, 2);
	ASSERT_EQ(population.GetPopulation()[2]->Score, 3);
	ASSERT_EQ(population.GetPopulation()[3]->Score, 3.5);
	ASSERT_EQ(population.GetPopulation()[4]->Score, 2.5);
}