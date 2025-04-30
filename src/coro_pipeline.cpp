#include "pipeline/coro_pipeline.hpp"


Task generate(std::vector<int>& output)
{
		for (int i =0; i < 1000; ++i)
		{
				output.push_back(i);
				co_await Awaiter{};
		}
}


Task filter_func(const std::vector<int>& input,
		std::vector<int>& output) {
	
		for (int x : input ) {
				if ( x % 2 == 0)
				{
					 output.push_back(x);
				co_await Awaiter{};
				}
		}
		
}
 
Task transform(std::vector<int>& input, std::vector<int>& output)
{
		for (int x: input)
		{
				output.push_back(x * 2);
				co_await Awaiter{};
		}

}

Task run_coroutine_pipeline() {

	std::vector<int> gen_out, filter_out, transform_out;

	co_await generate(gen_out);
	co_await filter_func(gen_out, filter_out);
	co_await transform(filter_out, transform_out);

	std::cout << "Coroutine pipeline finished. Outpu size: "
		<< transform_out.size() << std::endl;
	
}


