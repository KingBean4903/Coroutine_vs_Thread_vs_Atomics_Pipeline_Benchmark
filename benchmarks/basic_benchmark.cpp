#include <benchmark/benchmark.h>
#include "pipeline/coro_pipeline.hpp"
#include "pipeline/future_pipeline.hpp"

static void BM_CoroutinePipeline(benchmark::State& state)
{
		
	for (auto _ :  state)
	{
			run_coroutine_pipeline();
	}

}

BENCHMARK(BM_CoroutinePipeline);


static void BM_FuturePipeline(benchmark::State& state)
{
	for (auto _ : state)
	{
		run_future_pipeline();		
	}

}

BENCHMARK(BM_FuturePipeline);



BENCHMARK_MAIN();
