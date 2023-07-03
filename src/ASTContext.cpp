#include "ASTContext.h"
using namespace foxintango;

ASTContext::ASTContext(){}
ASTContext::~ASTContext(){}

Error ASTContext::execute(){
    for(Index index = 0;index < subelements.size();index ++){
        if(subelements[index]) subelements[index]->execute(this,this);
    }
}