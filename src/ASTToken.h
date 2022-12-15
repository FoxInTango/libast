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
 *  模式与模式匹配
 *  序列与序列排除
 *      自然序列
 *      定义序列
 *  位置与位置表示
 *  行为:查找,追加,插入,删除，分割
 *  @|2022:
 *  @+2022:
 *  @-2022:
 *  @[0-2,3-7,8-200]:[ a - z / h - w ]
 *  @*:[ a - z / h - w,a,b] && ![0 - 5] && * [xy,ab,cd] | 
 * 
 *  
 */

 template <class T>
 class ASTMatch{
 public:
     ASTMatch(){}
     ASTMatch(const char* mode){}
    ~ASTMatch(){}
public:
    int match(T* t,const unsigned int& size){
        return 0;
    }
 };

 class ASTMatch<wchar_t>{
 
 };
