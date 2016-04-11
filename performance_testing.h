#pragma once

#include <chrono>
#include <functional>

template <class ReturnType, class... ArgumentsTypes>
class Chronometer {
	using FunctionType = std::function<ReturnType(ArgumentsTypes...)>;

	FunctionType _function;
	std::chrono::time_point<std::chrono::high_resolution_clock> _start, _end;
	std::chrono::duration<double> _duration;

public:
	Chronometer(FunctionType function) : _function(function) {}

	// TODO: Add template option for void return value.
	ReturnType run(ArgumentsTypes... arguments) {
		_start = std::chrono::high_resolution_clock::now();
		auto value = _function(arguments...);
		_end = std::chrono::high_resolution_clock::now();
		_duration = _end - _start;
		return value;
	}

	std::chrono::duration<double> getDuration() {
		return _duration;
	}

	double getDurationInNanoseconds() {
		std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(_duration);
		return static_cast<double>(ns.count());
	}

	double getDurationInMicroseconds() {
		return getDurationInNanoseconds() / 1000.0;
	}

	double getDurationInMilliseconds() {
		return getDurationInNanoseconds() / 1000000.0;
	}

	double getDurationInSeconds() {
		return getDurationInNanoseconds() / 1000000000.0;
	}
};