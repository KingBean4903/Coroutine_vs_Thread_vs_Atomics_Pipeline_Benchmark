# C++ Coroutine vs. std::future Pipeline Benchmark

# Motivation
This project is inspired by building ETL pipelines in C++, benchmarking both strategies
and get a feel of which path I should take to build a full blown ETL pipeline.

A benchmarking project comparing the performance of C++20 coroutines and std::future for asynchronous pipeline processing.

### Key Features

🚀 Coroutine-based pipeline (stackless, single-threaded)

⏳ std::future-based pipeline (thread-per-task)

📊 Google Benchmark integration for metrics (throughput, latency)

🔍 Profiling support (perf, Valgrind)

## Build & Run
### Prerequisites
1. C++20 compiler (GCC 11+, Clang 12+, MSVC 19.29+)
1. CMake 3.20+
1. Google Benchmark (auto-fetched by CMake)

``# Configure``
``cmake -B build -DCMAKE_BUILD_TYPE=Release``

``# Build``
``cmake --build build --parallel``

``# Run benchmarks``
``./build/benchmarks/bench_coro_vs_future``

## Pipeline Stages
1. Generate → Filter → Transform
    1. Coroutines: Chained via co_await (zero thread switches).
    1. std::future: Chained via .get() (thread-per-stage)

## Profiling

``#CPU hotspots (Linux)``
``perf record ./build/benchmarks/bench_coro_vs_future``

``# Memory usage``
``valgrind --tool=massif ./build/benchmarks/bench_coro_vs_future``

## License
MIT