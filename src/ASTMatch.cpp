#include "ASTMatch.h"
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <codecvt>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <locale>

class ASTMatchElementImplement{
public:
    std::vector<ASTMatchElement*> subelements;
public:
    ASTMatchElementImplement(){}
   ~ASTMatchElementImplement(){}
};

ASTMatchElement::ASTMatchElement() {
    m_super = 0;
    implement = new ASTMatchElementImplement();
}

ASTMatchElement::~ASTMatchElement() {
    if(implement) delete implement;
}

bool ASTMatchElement::eol(const wchar_t& t) {
    return t == L'\n' || t == L'\t' || t == L'\r';
}

bool ASTMatchElement::letter(const wchar_t& value){
    return value <= L'z' && value >= L'A';
}

bool ASTMatchElement::arabic(const wchar_t& value) {
    return value ? (value > L'0' && value < L'9' ? true : false) : false;
}

ASTMatchElement* ASTMatchElement::super() {
    return m_super;
}

int ASTMatchElement::loadMode(const wchar_t* mode, unsigned int& index, const unsigned int& size){
    return AST_MATCH_LOAD_STATUS_UNSURE;
    while (mode[index] && !eol(mode[index])) {
        switch (mode[index])
        {
        case L'@': {}break;
        case L'[': {}break;
        case L']': {}break;
        case L':': {}break;
        case L'-': {}break;
        case L'&': {}break;
        case L'|': {}break;
        case L'=': {}break;/** =,== */
        case L'>': {}break;/** >,>= */
        case L'<': {}break;/** <,<= */
        case L',': {}break;
        case L';': {}break;
        case L'\\': {}break;
        default: {
            if (arabic(mode[index])) {  }
        }break;
        }
        index++;
    }
}

int ASTMatchElement::pushError(const AST_MATCH_ERROR& error){
    if(this->m_super){
        m_super->pushError(error);
    }
}

typedef std::map<ASTMatch*, std::vector<AST_MATCH_ERROR>> AST_match_error_map;

static AST_match_error_map match_error_map;

ASTMatch::ASTMatch(){
    match_error_map.insert(std::pair<ASTMatch*, std::vector<AST_MATCH_ERROR>>(this, std::vector<AST_MATCH_ERROR>()));
}

ASTMatch::~ASTMatch() {
    if(match_error_map.count(this)){
        match_error_map.erase(this);
    }
}

int ASTMatch::makeMode(const char* mode, unsigned int& index, const unsigned int& size) {
    // if file path ?
    for(int i = 0;i < size;i ++){
        
    }
    std::wstring wline = std::wstring_convert<std::codecvt_utf8<wchar_t>>{}.from_bytes(mode);
    return loadMode(wline.c_str(),index,wline.length());;
}

int ASTMatch::loadMode(const wchar_t* mode, unsigned int& index, const unsigned int& size) {
    while (mode[index] && !eol(mode[index])) {
        switch (mode[index])
        {
        case L'@': {}break;
        case L'[': {}break;
        case L']': {}break;
        case L':': {}break;
        case L'-': {}break;
        case L'&': {}break;
        case L'|': {}break;
        case L'=': {}break;/** =,== */
        case L'>': {}break;/** >,>= */
        case L'<': {}break;/** <,<= */
        case L',': {}break;
        case L';': {}break;
        case L'\\': {}break;
        default: {
            if (arabic(mode[index])) {}
            else if(letter(mode[index])){
            }
        }break;
        }
        index++;
    }
    return 0;
}

int ASTMatch::pushError(const AST_MATCH_ERROR& error) {
    if(match_error_map.count(this)){
        match_error_map.at(this).push_back(error);
    }
}