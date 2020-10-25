/************************
File Name: WordLadder.cpp

Author: Mathew Soto
Date: July 2019
************************/

#include "WordLadder.hpp"

//default constructor
//sets lexicon_size_ and used_words_size_ to 0
WordLadder::WordLadder()
{
	lexicon_size_ = 0;
	used_words_size_ = 0;
}

std::string WordLadder::getWord(int index)
{
	return lexicon_[index];
}

/**
@post reads lexicon words from the input file
      and stores them for later use
**/
void WordLadder::readLexicon(std::string input_file)
{
	std::ifstream fin;
	fin.open(input_file);

	if ( fin.fail() )
	{
		std::cout << "Could not open " << input_file << std::endl;
		exit(1);
	}

	std::string word = "";
	while (std::getline(fin, word))
	{
		lexicon_.push_back(strToWord(word));
		lexicon_size_++;
	}	
}

/**
@param start_word is the first word in the ladder	
@param end_word is the last word in the ladder
@return a vector containing words s.t. the first word
 is start_word, the last word is end_word, and all words
 in between differ by only one character from the preceding
 and following words, in the shortest such transformation
 found in the current lexicon. If no transformation is
 found between start_word and end_word, returns an empty
 vector.
**/
std::vector<std::string> WordLadder::findShortestLadder(std::string start_word,
std::string end_word)
{
	//initializes empty queue
	std::queue<std::vector<std::string>> partial_ladder;
	
	//initializes empty vector and puts start_word in the first position
	std::vector<std::string> ladder;
	ladder.push_back(start_word);

	//pushes partial ladder only containing start_word to the front of the queue
	partial_ladder.push(ladder);

	//makes start_word a used word
	used_words_.push_back(start_word);
	used_words_size_++;

	std::vector<std::string> temp_ladder;

	while (!partial_ladder.empty())
	{
		std::vector<std::string> front_ladder = partial_ladder.front();
		partial_ladder.pop();

		std::string last_word = lastInVector(front_ladder);

		if (last_word == end_word)
		{
			return front_ladder;
		}

		for (int i = 0; i < 4; i++)
		{
			for (char j = 'a'; j < 'z'; j++)
			{
				std::string new_word = last_word;
				new_word[i] = j;

				if (!inUsedWords(new_word) && binary_search(lexicon_.begin(), lexicon_.end(), new_word))
				{
					temp_ladder=front_ladder;
					temp_ladder.push_back(new_word);
					used_words_.push_back(new_word);
					used_words_size_++;
					partial_ladder.push(temp_ladder);
				} //end if
			} //end for
		} //end for
	} // end while

	std::vector<std::string> empty;
	empty.clear();

	return empty;
} // end findShortestLadder



/*************************PRIVATE METHODS*************************/

//@param string from an input file
//@return string with only alphabetical characters
std::string WordLadder::strToWord(std::string word)
{
	int word_length = word.length();

	std::string only_alpha = "";

	for (int i = 0; i < word_length; i++)
	{
		if (isalpha(word[i]))
		{
			only_alpha += word[i];
		}
	}

	return only_alpha;
}

//@return last element in a vector containing strings
std::string WordLadder::lastInVector(std::vector<std::string> string_vector)
{
	size_t vector_size = string_vector.size();

	return string_vector[vector_size - 1];
}

//@return bool indicating whether the string used is in used_words_
bool WordLadder::inUsedWords(std::string used)
{
	used_words_size_ = used_words_.size();

	for (size_t i = 0; i < used_words_size_; i++)
	{
		if (used_words_[i] == used)
		{
			return true;
		}
	}

	return false;
}
