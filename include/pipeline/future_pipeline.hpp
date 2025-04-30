#pragma once
#include <future>
#include <vector>
#include <iostream>

std::future<std::vector<int>> generator();
std::future<std::vector<int>> filter_func(std::future<std::vector<int>> input);
std::future<std::vector<int>> transform(std::future<std::vector<int>> input);

void run_future_pipeline();
