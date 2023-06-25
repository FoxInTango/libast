#include "ASTElement.h"
using namespace foxintango;

ASTElement::ASTElement(){}
ASTElement::~ASTElement(){}

Size ASTElement::appendSubelement(ASTElement* element){ return 0; }
Size ASTElement::removeSubelement(ASTElement* element) { return 0; }
Size ASTElement::removeSubelement(const Index& index) { return 0; }
Error ASTElement::execute(const ASTContext* context, const ASTElement* caller) { return 0; }

String ASTElement::name(){
    return m_name;
}
ASTElementType ASTElement::type(){
    return m_type;
}

ASTScope::ASTScope(){}
ASTScope::~ASTScope(){}