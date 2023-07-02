#include "ASTElement.h"
using namespace foxintango;

ASTElement::ASTElement(){ String name = this->name;this->name = name;}
ASTElement::~ASTElement(){}

Size ASTElement::appendSubelement(ASTElement* element) { return 0; }
Size ASTElement::removeSubelement(ASTElement* element) { return 0; }
Size ASTElement::removeSubelement(const Index& index)  { return 0; }

virtual Error ASTElement::insertMember(ASTElement* element, const String& name){
    return Error(1, "ASTElement virtual method.");
}
virtual Error ASTElement::removeMember(const String& name){
    return Error(1, "ASTElement virtual method.");
}

Error ASTElement::execute(const ASTContext* context, const ASTElement* caller) { return 0; }

ASTScope::ASTScope(){}
ASTScope::~ASTScope(){}