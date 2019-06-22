// Laboratory Work #3 (2nd semester) (NOT IMPROVED)

/*

	Author:		Novokhatnii Vlas
	Group:		PZ-18-1 (2nd subgroup)

	Problem:	In the inputed string find the longest and the shortest
				words and if they are in the same sentence, replace them
				with stars(***).

*/

#include "pch.h"
#include <iostream>
#include <string>
#include <vector> 
#include <tuple>
#include <windows.h>

// Delimiter in the end 

int main(void)
{

	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	std::string text_string;
	getline(std::cin, text_string);

	// Convert the string to char*
	char* text_ptr = new char[text_string.length() + 1];
	strcpy_s(text_ptr, text_string.length() + 1, text_string.c_str());

	char delims[10] = " .,:;?!\n\t";
	char sentence_enders[4] = ".?!";

	// Check if the text ends with some of them
	if (strchr(sentence_enders, text_ptr[strlen(text_ptr)-1]) == NULL)
	{
		std::cout << "Error 1: The text must be ended with a punctuation sentense ender: .!?";
		std::cout << std::endl;

		delete[] text_ptr;
		system("pause");
		return 1;
	}




	// Create a vector of tuple of 2 for the pointer to a word and its length
	std::vector<std::tuple<char*, int>> wordlen;

	// Find these poiters and lengths 

	char *delim = text_ptr - 1;
	char *next_delim = NULL;
	int length;

	while (delim != NULL)
	{
		next_delim = strpbrk(delim + 1, delims);
		length = next_delim - delim - 1;

		if (length != 0 && next_delim != NULL)
			wordlen.emplace_back(delim + 1, length);
	
		delim = next_delim;
	}


	// Find the min and the max lengthes

	int min = INT_MAX;
	int max = 0;
	int temp;
	int word_amount = wordlen.size();

	for (int i = 0; i < word_amount; i++)
	{
		temp = std::get<1>(wordlen[i]);

		if (temp < min)
			min = temp;

		if (temp > max)
			max = temp;
	}


	// If words with the min and max lengths are in one sentence replace them with *

	// For the sake of convenience
	char *ptr1, *ptr2;
	int len1, len2;

	for (int i = 0; i < word_amount; i++)
	{
		// Find a word with the min or max lenght 
		if (std::get<1>(wordlen[i]) == min || std::get<1>(wordlen[i]) == max)
		{
			// Choose what to find next(the opposite one): min or max
			int opposite = min; 
			if (std::get<1>(wordlen[i]) == min)
				opposite = max;

			// Continue iterating 
			for (int j = i; j < word_amount; j++)
			{
				// Finf an opposite length-wise word
				if (std::get<1>(wordlen[j]) == opposite)
				{
					// For the sake of convenience and performance 
					ptr1 = std::get<0>(wordlen[i]);
					ptr2 = std::get<0>(wordlen[j]);

					len1 = std::get<1>(wordlen[i]);
					len2 = std::get<1>(wordlen[j]);

					// Find the nearest for the first word sentence end 
					char *sentence_end = strpbrk(ptr1, sentence_enders);

					// If it's more far from the first word, replace both words with *
					if (ptr2 < sentence_end)
					{
						// replace the first length word with *
						for (int k1	= 0; k1 < len1 ; k1++)
						{
							ptr1[k1] = '*';
						}

						// replace the second (the opposite) length word with *
						for (int k2 = 0; k2 < len2; k2++)
						{
							ptr2[k2] = '*'; 
						}
					}
				}
			}
		}
	} 

	// Print probably modified sentence
	std::cout << text_ptr << std::endl;

	delete[] text_ptr;
	return 0;
}
