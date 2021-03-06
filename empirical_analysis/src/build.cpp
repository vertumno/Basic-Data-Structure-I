#include "build.h"
#include <iostream>

void build_list(int const argc, char const **argv, vector<sort_functions> &sort_list, vector<string> &names)
{
	if(argc > 1){
		for(int i = 1; i < argc; ++i)
		{
			if( strcmp(*(argv + i), "-f") == 0 )
			{
				for(int j = i; j < argc; ++j)
				{
					if( strcmp( *(argv + j), "i" ) == 0) {
						sort_list.push_back(insertion_sort);
						names.push_back("Insertion Sort");
					} else if( strcmp( *(argv + j), "s" ) == 0){
						sort_list.push_back(selection_sort);
						names.push_back("Selection Sort");
					} else if( strcmp( *(argv + j), "b" ) == 0){
						sort_list.push_back(bubble_sort);
						names.push_back("Bubble Sort");
					} else if( strcmp( *(argv + j), "m" ) == 0){
						sort_list.push_back(merge_sort);
						names.push_back("Merge Sort");
					} else if( strcmp( *(argv + j), "q" ) == 0){
						sort_list.push_back(quick_sort);
						names.push_back("Quick Sort");
					} else if( strcmp( *(argv + j), "r" ) == 0){
						sort_list.push_back(radix_sort);
						names.push_back("Radix Sort (LSD)");
					} else if( strcmp( *(argv + j), "sh" ) == 0){
						sort_list.push_back(shell_sort);
						names.push_back("Shell Sort");
					}
				}
				return;	
			}	
		}	
	}

	sort_list = {
		insertion_sort, selection_sort, bubble_sort,
        quick_sort, merge_sort, shell_sort, radix_sort
	};
	names = {
		"Insertion Sort", "Selection Sort", "Bubble Sort",
		"Quick Sort", "Merge Sort", "Shell Sort", "Radix Sort (LSD)"
	};
}

void build_sample_size(int const argc, char const **argv, unsigned long &sample_max_size, bool &custom_size)
{
	custom_size = false;
	if(argc > 1)
	{
		for(int i = 1; i < argc; ++i)
		{
			if( strcmp(*(argv + i), "-ri") == 0 )
			{
				if(i + 1 < argc)
				{
					sample_max_size = atol( *(argv + i + 1) );
					custom_size = true;
				}
				return;
			}
		}	
	}
	sample_max_size = 56000;	
}

void build_fill_vector(vector<unsigned int> &A, unsigned long const &sample_max_size)
{
	random_device rd;
    mt19937 g(rd());
    A.resize(sample_max_size);
	iota( A.begin(), A.end(), 1 );
	//Comment line below to use non-decreasing or non-increasing scenario.	
	shuffle(A.begin(), A.end(), g);
	//Only to use non-increasing scenario you should uncomment line below.
	//reverse(A.begin(), A.end());
}