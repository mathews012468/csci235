/************************
File Name: WordLadder.hpp

Author: Mathew Soto
Date: July 2019
************************/

/*********************************************
This is the interface of the WordLadder class,
*********************************************/

#ifndef WORD_LADDER_H
#define WORD_LADDER_H
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>

class WordLadder
{

public:
	//default constructor
	WordLadder();

	/**
	 @post reads lexicon words from the input file
	       and stores them for later use
	 **/
	void readLexicon(std::string input_file);

	std::string getWord(int index);

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
	std::vector<std::string> findShortestLadder(std::string start_word,
	std::string end_word);

private:
	//vector containing all words in the lexicon
	std::vector<std::string> lexicon_;

	//number of items in lexicon_
	size_t lexicon_size_;
	
	//vector containing all used words
	std::vector<std::string> used_words_;

	//number of items in used_words_
	size_t used_words_size_;

	//@param string from an input file
	//@return string with only alphabetical characters
	std::string strToWord(std::string word);

	//@return last element in a vector containing strings
	std::string lastInVector(std::vector<std::string> string_vector);

	//@return bool indicating whether the string used is in used_words_
	bool inUsedWords(std::string used);
};

#endif
