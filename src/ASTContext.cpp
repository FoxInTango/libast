#include "ASTContext.h"
using namespace foxintango;

ASTContext::ASTContext(){}
ASTContext::~ASTContext(){}

Error ASTContext::load(const String& path){
    ASTDocument* document = new ASTDocument();

    if(document){
        return document->load(path);
    }

    return 1;
}

Error ASTContext::execute(){
    for(Index index = 0;index < subelements.size();index ++){
        if(subelements[index]) subelements[index]->execute(this,0);
    }
}