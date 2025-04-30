cmake_minimum_required(VERSION 3.20)
project(CoroBenchMark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcoroutines")

find_package(benchmark REQUIRED)

include_directories(include)

#lib targets
add_library(coro_pipeline src/coro_pipeline.cpp include/pipeline/coro_pipeline.hpp)
add_library(future_pipeline src/future_pipeline.cpp include/pipeline/future_pipeline.hpp)

#Benchmarks
add_executable(bench_coro_vs_future benchmarks/basic_benchmark.cpp)
target_link_libraries(bench_coro_vs_future PRIVATE coro_pipeline future_pipeline benchmark::benchmark)

# Thread sanitizer
if (USE_TSAN)
		target_compile_options(bench_coro_vs_future PRIVATE -fsanitize=thread)
		target_link_libraries(bench_coro_vs_future PRIVATE -fsanitize=thread)
endif()
