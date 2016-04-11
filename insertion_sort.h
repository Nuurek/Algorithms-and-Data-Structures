#pragma once

#include <vector>

template <typename T, typename Compare = std::less<T>>
void insertion_sort(std::vector<T> input, Compare compare = Compare()) {
	size_t size = input.size();
	for (size_t i = 1; i < size; i++) {
		for (size_t j = i - 1; (j > 0) && (compare(input[j], input[j - 1])); j--) {
			std::swap(input[j], input[j - 1]);
		}
	}
}