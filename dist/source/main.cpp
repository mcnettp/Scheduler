/**
* Main.cpp
* General Scheduler for C++ Models
* Allows declaring the target Hz to cycle at and pass into the model layer
* Can also place inputs and outputs in this file
**/

/* Includes */
#include <iostream>
#include <memory>
#include <algorithm>
#include <thread>

/* Constants */
constexpr double DesiredFrequency = 60.0; // Frequency in Hz that we want to target
constexpr auto DesiredPeriod = std::chrono::duration<double>(1.0 / DesiredFrequency); // Convert to Period for Scheduler

/* Example Input Structure */
//void GetInputs(Model& modelName, const InputStructure& inputs)
//{
//	InputStructure in = inputs;
//	in.ValidateInputs(); // Assuming we have this function to check inputs
//	modelName.Inputs(in);
//}

/* Example Output Structure */
//void ExportOutputs(Model& modelName, OutputStructure& outputs)
//{
//	OutputStructure out;
//	modelName.Outputs(out);
//	outputs = std::move(out);
//}

/* Main Entry Point */
auto main(void) -> int
{
	//std::unique_ptr<Model> pModel = std::make_unique<Model>();

	auto stop = std::chrono::high_resolution_clock::now(); // Declare externally of loop so we have a delta time going into the first pass of the loop

	while (true) // (pModel != nullptr)
	{
		auto start = std::chrono::high_resolution_clock::now();
		auto elapsedTime = std::chrono::duration_cast<std::chrono::duration<double>>(start - stop); // Calculate time passing from previous cycle to now

		/* Get Inputs */
		// InputStructure inputs;
		// Get Inputs from external, and pass them into our model
		// GetInputs(*pModel, inputs);

		/* Run Model */
		// pModel->Run(elapsedTime.count()); // Use elapsedTime.count() to pass the delta time into the model

		/* Get Outputs */
		//OutputStructure outputs;

		// Get Outputs from model, and export them to our external
		//ExportOutputs(*pModel, outputs);

		stop = std::chrono::high_resolution_clock::now();
		auto executionTime = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		auto sleepTime = std::chrono::duration_cast<std::chrono::microseconds>(DesiredPeriod) - executionTime;
		if (sleepTime.count() > 0)
		{
			std::this_thread::sleep_for(sleepTime);
		}
	}

	return 0;
}