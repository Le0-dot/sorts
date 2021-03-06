#include <tuple>
#include <string>
#include <array>
#include <vector>
#include <thread>
#include <exception>

#include "sorts/sorts.hpp"
#include "benchmark/TimeTest.hpp"
#include "benchmark/test_thread.hpp"
#include "display/write_table.hpp"
#include "display/draw_graphic.hpp"
#include "utils/sequence_type.hpp"
#include "test_data/write_data.hpp"

using testing_signature = std::function<void(std::vector<int>::iterator, std::vector<int>::iterator)>;
using namespace std::literals;

#include <iostream>

int main(int argc, char** argv)
{
	std::array<std::tuple<testing_signature, std::string>, 11> sorts;
	sorts[0] = { std::sort<std::vector<int>::iterator>, "std_sort"s };
	sorts[1] = { bubble_sort<std::vector<int>::iterator>, "bubble_sort"s };
	sorts[2] = { shaker_sort<std::vector<int>::iterator>, "shaker_sort"s };
	sorts[3] = { comb_sort<std::vector<int>::iterator>, "comb_sort"s };
	sorts[4] = { insertion_sort<std::vector<int>::iterator>, "insertion_sort"s };
	sorts[5] = { selection_sort<std::vector<int>::iterator>, "selection_sort"s };
	sorts[6] = { gnome_sort<std::vector<int>::iterator>, "gnome_sort"s };
	sorts[7] = { merge_sort<std::vector<int>::iterator>, "merge_sort"s };
	sorts[8] = { quick_sort<std::vector<int>::iterator>, "quick_sort"s };
	sorts[9] = { lsd_sort<std::vector<int>::iterator>, "lsd_sort"s };
	sorts[10] = { bitonic_sort<std::vector<int>::iterator>, "bitonic_sort"s };

	/*
	write_data("./data/"s);

	std::vector<std::thread> threads;
	for(int type = static_cast<int>(sequence_type::random); type <= static_cast<int>(sequence_type::reversed); ++type) {
		for(auto size = 100; size <= 100000; size *= 10) {
			for(const auto & it : sorts) {
				threads.push_back(std::thread{&test_thread, std::get<0>(it), 100, size,
				       	"./results/"s + std::get<1>(it) + "_"s + std::to_string(size) + "_"s + seqttos(static_cast<sequence_type>(type)),
				       	static_cast<sequence_type>(type)});
			}
		}
	}
	for(auto & thread : threads)
		if(thread.joinable())
	            thread.join();
	*/
	draw_graphic(write_table(sorts));

	return 0;
}
