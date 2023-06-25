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

#ifndef _AST_ELEMENT_H_
#define _AST_ELEMENT_H_
#include "ASTDebug.h"
#include "ASTDefines.h"
#include <libstring/libstring.h>
#include <libcpp/libcpp.h>
/**
 *
 */
EXTERN_C_BEGIN
namespaceBegin(foxintango)
class foxintangoAPI ASTElement {
public:
    //enum TYPE{};
public:
/*
    union {
        ASTDebug debug;
    } debug;
*/

//ASTDebug debug;
protected:
    /** Debug Infomation
     */

public:
    ASTElement();
    virtual ~ASTElement();
public:
public:
    virtual Size appendSubelement(ASTElement* element);
    virtual Size removeSubelement(ASTElement* element);
    virtual Size removeSubelement(const Index& index);
public:
    virtual Error execute(const ASTContext* context,const ASTElement* caller);
};

class ASTVoid   :public ASTElement{};
class ASTTrue   :public ASTElement{};
class ASTFalse  :public ASTElement{};
class ASTString :public ASTElement {};
class ASTNumber :public ASTElement {};
class ASTArray  :public ASTElement {};
class ASTObject :public ASTElement {};

class ASTAssign    :public ASTElement {};
class ASTAddAssign :public ASTElement {};
class ASTSubAssign :public ASTElement {};
class ASTMulAssign :public ASTElement {};
class ASTDivAssign :public ASTElement {};
class ASTModAssign :public ASTElement {};

class ASTAdd :public ASTElement{};
class ASTSub :public ASTElement{};
class ASTMul :public ASTElement{};
class ASTDiv :public ASTElement{};
class ASTMod :public ASTElement{};

// logic
class ASTAnd :public ASTElement {};
class ASTNot :public ASTElement {};
class ASTOr  :public ASTElement {};

// bits

class ASTNE :public ASTElement {};// not equal
class ASTEQ :public ASTElement {};// equal 
class ASTGT :public ASTElement {};// greater
class ASTGE :public ASTElement {};// greater or equal
class ASTST :public ASTElement {};// smaller 
class ASTSE :public ASTElement {};// smaller or equal

class ASTCall :public ASTElement {
public:
    String name;
    Index location;
};

class ASTReturn   :public ASTElement {
protected:
    ASTScope* scope;// return to this scope
};/** jump to higher level.function only.*/
class ASTBreak    :public ASTElement {};
class ASTContinue :public ASTElement {};

class ASTScope :public ASTElement {
public:
    Map<String,ASTElement*> varMap;
    Array<ASTElement*> subelements;
public:
    ASTScope();
    virtual ~ASTScope();
};/** () | {} */
class ASTExpression :public ASTScope {};

class ASTFunction :public ASTScope {};
class ASTSwitch :public ASTScope {};/** if | switch */
class ASTCase:public ASTScope {};
class ASTFor :public ASTScope {};
class ASTWhile :public ASTScope {};
class ASTDo :public ASTScope {};
class ASTIn :public ASTScope {};
class ASTTry :public ASTScope {};
class ASTCatch :public ASTScope {};

class ASTClass :public ASTScope {};
class ASTNew :public ASTElement {};
class ASTDel :public ASTElement {};
class ASTMemberOf :public ASTElement {};

class ASTSizeOf :public ASTElement{};
class ASTTypeOf :public ASTElement{};
namespaceEnd
EXTERN_C_END
#endif