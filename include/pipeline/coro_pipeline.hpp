#pragma once

#include <coroutine>
#include <vector>
#include <iostream>


	struct Awaiter {
		bool await_ready() const noexcept { return false; }
		void await_suspend(std::coroutine_handle<> handle) const noexcept {}
		void await_resume() const noexcept { } 
	};


struct Task {

	struct promise_type;
	using handle_type  = std::coroutine_handle<promise_type>;
	handle_type coro;

	Task(handle_type h) : coro(h) {}

	~Task() { if (coro) coro.destroy(); }

	struct promise_type {
			Task get_return_object() { return Task{handle_type::from_promise(*this)}; }

			std::suspend_never initial_suspend() { return {}; }
			std::suspend_never final_suspend() noexcept { return {}; }

			void return_void() {}
			void unhandled_exception() { std::terminate(); }
	};


	auto operator co_await() noexcept 
	{
			return Awaiter {};
	}

};




Task generate(std::vector<int>& output);
Task filter(std::vector<int>& input, std::vector<int>& output);
Task transform(const std::vector<int>& input,const std::vector<int>& output);

Task run_coroutine_pipeline();
