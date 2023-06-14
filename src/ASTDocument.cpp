#include "ASTDocument.h"
#include <libstream/libstream.h>
using namespace foxintango;

ASTDocument::ASTDocument() {}
ASTDocument::ASTDocument(const URL& url) {}
ASTDocument::~ASTDocument() {}

Error ASTDocument::load(const URL& url){
    Stream stream(url);

    Index index = 0;
    while(stream.readable()){
        switch(stream[index]){
        default:break;
        }
    }
}