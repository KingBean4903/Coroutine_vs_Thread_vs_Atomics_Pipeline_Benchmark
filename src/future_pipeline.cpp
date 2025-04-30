#include "pipeline/future_pipeline.hpp"

std::future<std::vector<int>> generator() {
	return std::async([]{	
			std::vector<int> output;
				for (int i = 0; i < 1000; i++)
				{
					output.push_back(i);
				}
				return output;
			});
}

std::future<std::vector<int>> filter_func(std::future<std::vector<int>> input)
{
	
	return std::async([input=std::move(input)]()mutable{
					auto data = input.get();
					std::vector<int> output;
					for (int x : data) {
							if (x % 2 == 0)
							{
									output.push_back(x);
							}
					}
				return output;
			});
}


std::future<std::vector<int>> transform(std::future<std::vector<int>> input)
{
		return std::async([input = std::move(input)]()mutable {
					
				auto data = input.get();
				std::vector<int> output;
				for (int x : data) {
							output.push_back(x * 2);
				}

			return output;
		});
}

void run_future_pipeline()
{
		auto fut = transform(filter_func(generator()));
		auto result = fut.get();
/*		std::cout << "Future pipeline finished, Output size " <<
			result.size() << std::endl;
*/
}
