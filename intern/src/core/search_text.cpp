//
//  Created by Tobias Schwandt.
//  Copyright (c) 2012 Zebresel. All rights reserved.
//

#include "core/search_text.h"

#include <map>

namespace Core
{
namespace Text
{
    int FindWordInText(std::string& _rWord, std::string& _rText)
    {
        // ------------------------------------------------------------
        // Algorithm by BROYER/MOORE/HORSPOOL
        // ------------------------------------------------------------
        
        if (_rWord.size() > _rText.size()) 
        {
            return -1;
        }
        
        // ------------------------------------------------------------
        // build list
        // ------------------------------------------------------------
        std::map<char, int> SearchBox;
        
        for (int PositionInWord = 0; PositionInWord < _rWord.size() - 1; ++PositionInWord) 
        {
            
            char ActualLetter   = _rWord.at(PositionInWord);
            int  ActualPosition = _rWord.size() - (PositionInWord + 1);
            
            if (SearchBox.find(ActualLetter) != SearchBox.end()) 
            {
                //Replace item
                SearchBox.at(ActualLetter) = ActualPosition;
            }
            else 
            {
                SearchBox.insert(std::pair<char, int>(ActualLetter, ActualPosition));
            }
            
        }
        
        int FoundWordAtPosition = -1;
        int PositionInText = _rWord.size();
        
        while (PositionInText <= _rText.size()) 
        {
            bool CheckFound = true;
            
            
            char LastTextValue = _rText.at(PositionInText - 1);
            
            
            for (int PositionInWord = _rWord.size() - 1; PositionInWord >= 0; --PositionInWord) 
            {
                int CheckPositionInText = PositionInText - (_rWord.size() - PositionInWord);
                
                char TextValue = _rText.at(CheckPositionInText);
                char WordValue = _rWord.at(PositionInWord);
                
                if (TextValue != WordValue) 
                {               
                    if (SearchBox.find(LastTextValue) == SearchBox.end()) 
                    {
                        PositionInText += _rWord.size();
                    }
                    else 
                    {
                        PositionInText += SearchBox.find(LastTextValue)->second;
                    }
                    
                    CheckFound = false;
                    break;
                }
            }
            
            if (CheckFound == true) 
            {
                FoundWordAtPosition = PositionInText;
                break;
            }
        }
        
        return FoundWordAtPosition - _rWord.size();
    }
}// namespace Text
}// namespace Core