//--------------------------------------------------
// Unit Tests for class EuclidEvaluator
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#include <gtest/gtest.h>

#include <NVLib/ARFF/ARFFReader.h>
#include <NVLib/ARFF/ARFFWriter.h>
#include <NVLib/FileUtils.h>

#include <VanillaGPLib/GrammarBase/CalculatorBase.h>
#include <VanillaGPLib/EvalEngine/EvalFactory.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Elements
//--------------------------------------------------

class TestCalculator : public CalculatorBase 
{
public:
	TestCalculator(SolutionFactoryBase * factory, Mat& params) : CalculatorBase(factory, params) {}

	virtual Mat Eval(Solution * solution) override 
	{
		auto input = (double *) GetParams().data;
		Mat result = Mat_<double>(Rows(), 1);
		auto output = (double *) result.data;

		for (auto row = 0; row < Rows(); row++) 
		{
			auto sum = 0.0;

			for (auto column = 0; column < Cols(); column++) 
			{
				auto index = column + row * Cols();
				auto value = solution->DNA[column] * input[index];
				sum += value;
			}

			output[row] = sum;
		}

		return result;
	}

};

//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
void WriteTestData(const string& fileName);

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm that the evaluation works
 */
TEST(EuclidEvaluator_Test, evaluation_test)
{
	WriteTestData("Euclid_Test.arff");

	auto reader = NVLib::ARFFReader("Euclid_Test.arff"); Mat data = reader.ReadAll();
	auto solution = Solution(vector<int> {2, 1}); ASSERT_EQ(solution.Score, -1);
	auto evaluator = EvalFactory::Get("EUCLID", reader.GetHeader(), data);
	auto params = evaluator->GetParams(); auto calculator = new TestCalculator(nullptr, params);
	evaluator->SetCalculator(calculator);
	auto score = evaluator->Eval(&solution);

	ASSERT_EQ(score, 4);
	ASSERT_EQ(solution.Score, 4);

	delete evaluator;
}

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Write some test data to disk
 * @param fileName The file that we are writing to
 */
void WriteTestData(const string& fileName) 
{
	if (NVLib::FileUtils::Exists(fileName)) NVLib::FileUtils::Remove(fileName);

	auto writer = NVLib::ARFFWriter(fileName);

	auto header = NVLib::ARFFHeader("test_data", "WildBoar");
	header.GetFields().push_back("Coefficient_1");
	header.GetFields().push_back("Coefficient_2");
	header.SetHasOutput(true);
	writer.WriteHeader(header);

	Mat data = (Mat_<double>(4, 3) << 1, 2, 3, 3, 4, 7, 5, 6, 11, 7, 8, 15 );
	writer.Write(data);

	writer.Close();
}