#include "CppMath.h"

#include <algorithm>
#include <unordered_map>

int is_permutation(int x, int y) {
	std::unordered_map<int, int> digit_to_count;
	while (x) {
		digit_to_count[x % 10] += 1;
		x /= 10;
	}

	while (y) {
		auto it = digit_to_count.find(y % 10);
		if (it == digit_to_count.end() || it->second <= 0) {
			return false;
		} else {
			--(it->second);
		}
		y /= 10;
	}

	return std::all_of(digit_to_count.begin(), digit_to_count.end(), [](auto it){return it.second == 0;});
}