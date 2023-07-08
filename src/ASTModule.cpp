#include "ASTModule.h"
using namespace foxintango;
#include "ASTElement.h"

ASTElementInterface::ASTElementInterface(){}
ASTElementInterface::~ASTElementInterface(){}
ASTElement* ASTElementInterface::create() { return 0; }