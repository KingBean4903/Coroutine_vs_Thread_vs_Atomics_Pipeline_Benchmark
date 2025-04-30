#include <chrono>
#include "pipeline/coro_pipeline.hpp"
#include "pipeline/future_pipeline.hpp"

int main() {
	
	auto start = std::chrono::high_resolution_clock::now();
	run_coroutine_pipeline();
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Coroutine time " << (end - start).count()
		<< " ns\n";
	

	start = std::chrono::high_resolution_clock::now();
	run_future_pipeline();
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Future time " << (end - start).count()
		<< " ns\n";


}
