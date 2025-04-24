#include "ASTElement.h"
using namespace foxintango;

ASTElement::ASTElement(){ /*String name = this->name;this->name = name; String* s = this->name;this->name = s;*/}
ASTElement::~ASTElement(){}

Size ASTElement::appendSubelement(ASTElement* element) { return 0; }
Size ASTElement::removeSubelement(ASTElement* element) { return 0; }
Size ASTElement::removeSubelement(const Index& index)  { return 0; }

Error ASTElement::insertMember(ASTElement* element, const String& name){
    return 1;//Error(1, "ASTElement virtual method.");
}

Error ASTElement::removeMember(const String& name){
    return 1;//Error(1, "ASTElement virtual method.");
}

Error ASTElement::execute(const ASTContext* context, const ASTElement* caller) {
    return 0;
}

ASTScope::ASTScope(){}
ASTScope::~ASTScope(){}

Error ASTScope::execute(const ASTContext* context, const ASTElement* caller) {
    for (Index index = 0; index < subelements.size(); index++) {
        if (subelements[index]) subelements[index]->execute(context, caller);

        // IF RETURNED  BREAK;
    }

    ASTElement::execute(context,caller);
}
