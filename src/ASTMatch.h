#ifndef _AST_MATCH_H_
#define _AST_MATCH_H_

/** ASTMatch ASTToken ASTBlock
 *              type     type
 *              name     name
 *  1,字母 : [a - z]
 *           [A - Z]
 *  2,数字 : [0 - 9]
 *  3,符号 : [~ ` ! @ # $ % ^ & * ( ) - = _ + , . ; : ' " [ ] { } < > ? / | \ ]
 *  4,制表符
 *  5,控制符
 *
 *  [a - z]:![A-Z],[A-Z]:&[[a-z]/[x]])
 * 
 *  功能:
 *  一，匹配:校验目标序列是否符合指定规则
 *  二，查找:于目标序列中查找符合指定规则的子序列
 * 
 *  概念:
 *  元素与序列：元素是一个泛型概念，它指同类型事物所构成的集合中的单一个体。元素序列是指由该事物所构成的集合的数组型排列。
 *  元素分为位置元素和模式元素。
 *  位置元素:是指在某一个序列中位置的序号，由数值或由指代位置数值的符号和表达式构成。
 *  模式元素:是指由该类型事物的单体、复合体，或经表达式描述所构成的复合体。
 *  变量:变量代表了单个元素或者元素序列，变量之间支持相应的序列运算。
 * 
 *  模式元素
 *      自然元素
 *      根据描述定义元素
 * 
 *  位置元素
 *      自然元素
 *      根据描述定义元素
 * 
 *  序列定义与序列运算
 *      自然序列
 *      自定序列
 *  序列通过[]包含,例如 -- 位置元素序列:[0,1,2,3] ，模式元素序列:[x,y,z]
 *  序列与序列之间可以通过运算生成新序列，序列运算包括: 并集运算、子集运算、交集运算、补集运算。运算符: 
 * 
 *  模式与模式匹配
 * 
 *  变量
 * 
 *  行为:匹配,查找,追加,插入,删除,分割
 * 
 *  location=@[2323,3223,[2,3,4,5]]
 *  index=[a-b,c-w,0-9]
 *  @+2022:
 *  @-2022:
 *  @|+2022:
 *  @|-2022:
 *  @|1/3-2022:
 *  @>=2022:
 *  @<=2022:
 *  @[0-2 | -2,3-7,8-]:
 *                                                           
 *  @*:[ a - z / h - w >= 2,a == 3,b < 5] && [0 - 5 < 2] & [xy,ab,cd,xy*,*xy,xy[a,b,c,index]] < 5 | index > 2;
 *
 */

/** ASTMatchMode
 * 
 */

/** ASTMatchOperator 
 *  序列结合运算符： 
 *  并集:|
 *  交集:&
 *  差集:/
 * 
 *  匹配条件运算符：
 *  ==
 *  !=
 *  >=
 *  <=
 *  >
 *  <
 * 
 *  模式结合运算符
 *  & 并且
 *  | 或者
 *  /  
 */

// ASTMatchRange 
typedef struct _ast_ascii_code {

}ast_ascii_code;

typedef struct _ast_;
template <class T>
class ASTMatch {
private:
    char* mode;
public:
    ASTMatch() { mode = 0; }
    ASTMatch(const char* mode) {}
    ~ASTMatch() {}
public:
    bool match(T* t, const unsigned int& size, const char* mode = 0) {
        return 0;
    }

    int lookup() { return 0; }
    int append() { return 0; }
    int split()  { return 0; }
    int remove() { return 0; }
    int replace(){ return 0; }
};

template <>
class ASTMatch<wchar_t> {

};

#endif