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

#ifndef _AST_MODULE_H_
#define _AST_MODULE_H_
#include "ASTElement.h"
#include <libmodule/libmodule.h>
#include <libcpp/libcpp.h>
EXTERN_C_BEGIN
namespaceBegin(foxintango)

class foxintangoAPI ASTElementInterface {
public:
    ASTElementInterface();
    virtual ~ASTElementInterface();
public:
    virtual ASTElement* create();
};

/** TODO : 处理namespace问题
 */
#define AST_SYMBOL(x) class x:public ASTElement {public:x();~x();};\
                      class x##_interface:public ASTElementInterface{public:x##_interface(){} ~x##_interface(){} virtual x* create(){ return new x();} };
#define AST_FUNCTION
#define AST_CLASS
#define AST_OPERATOR
#define AST_VAR


#define AST_EXPORT(x) AST_MODULE_SYMBOLS.append(new x##_interface());
namespaceEnd
EXTERN_C_END


#endif