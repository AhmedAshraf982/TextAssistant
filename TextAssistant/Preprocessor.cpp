#include "Preprocessor.h"

Preprocessor::Preprocessor() {}

Preprocessor::Preprocessor(const Text &thatTxt)
{
	this->txt = thatTxt;
}

void Preprocessor::lowerCasing()
{
	std::string temp= txt.getContent();
	//std::cout << temp;

	for (std::string::size_type i = 0; i < temp.size(); i++)
    {
        if (temp[i] >= 'A' && temp[i] <= 'Z')
        
            (temp.at(i))+=32;
			//std::cout << temp << " ";
        
    }
	//std::cout << temp;
	txt.setContent(temp);
}

bool Preprocessor::isPeriod(char c)
{
  return (c == '.' || c == '?' || c == '!') ? true:false;
}

void Preprocessor::wordTokenizing()
{
	 std::string temp = txt.getContent();
	 
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == ' ')
		{
			words.emplace_back(temp);
			temp.clear();
		}
	}
	//for (auto x : words) std::cout << x << " ";

}

void Preprocessor::removingPunctuation()
{
	for (std::string::size_type i = 0; i < words.size(); i++)
	{
		std::string temp = words[i];
		words[i] = " ";
		for (std::string::size_type j = 0; j < words[i].size(); i++)
		{
			if (ispunct(words[i][j])) words[i] += temp[i] ;
		}
	}
	
}

void Preprocessor::sentenceTokenizing()
{
	std::string temp = txt.getContent();
	for (std::string::size_type i = 0; i < temp.size(); i++)
	{
		if (isPeriod(temp[i]))	sentences.clear();
		else sentences[i] = temp;
	}
	//for (auto x : sentences) std::cout << x << " ";
}


