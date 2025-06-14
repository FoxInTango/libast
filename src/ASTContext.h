/** MIT License

Copyright(c) 2022 FoxInTango <foxintango@yeah.net>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
// block -- block pair
// numbers texts
// function
// class
// 栈

#ifndef _AST_CONTEXT_H_
#define _AST_CONTEXT_H_
#include "ASTModule.h"
#include "ASTDocument.h"
#include "ASTElement.h"
#include <libmodule/libmodule.h>
#include <libstring/libstring.h>
#include <libcpp/libcpp.h>
EXTERN_C_BEGIN
namespaceBegin(foxintango)
class foxintangoAPI ASTContext :public ASTScope{
public:
Array<ASTElement*>  stack;
Array<ASTDocument*> documents;

/** scope
Array<ASTElementInterface*> symbols;
Map<String,Index>  symbolMap;
*/
//Index entry;
String entry;
public:
    ASTContext();
   ~ASTContext();
public:
public:
    Error insertDocument(const ASTDocument* document);
    Error removeDocument(const ASTDocument* document);
    Error loadModule(const char* path);
    Error execute();
    virtual Error execute(const ASTContext* context,const ASTElement* caller);
};
namespaceEnd
EXTERN_C_END
#endif
