#include <benchmark/benchmark.h>
#include "pipeline/coro_pipeline.hpp"

static void BM_CoroutinePipeline(benchmark::State& state)
{
		
	for (auto _ :  state)
	{
			run_coroutine_pipeline();
	}

}

BENCHMARK(BM_CoroutinePipeline);

BENCHMARK_MAIN();
