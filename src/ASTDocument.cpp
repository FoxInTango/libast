#include "ASTDocument.h"
#include <libstream/libstream.h>
using namespace foxintango;

ASTDocument::ASTDocument(ASTContext* context){ this->context = context; }
ASTDocument::ASTDocument(ASTContext* context, const URL& url){ this->context = context; }
ASTDocument::~ASTDocument() {}