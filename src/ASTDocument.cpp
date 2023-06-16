#include "ASTDocument.h"
#include <libstream/libstream.h>
using namespace foxintango;

ASTDocument::ASTDocument() {}
ASTDocument::ASTDocument(const URL& url) {}
ASTDocument::~ASTDocument() {}

Error ASTDocument::load(const URL& url){
    Stream stream(url);
    /** 判断语言类型 调取相应语言处理
     */
    Index index = 0;
    while(stream.readable()){
        switch(stream[index]){
        this->token_handler->load(
        default:break;
        }
    }
}