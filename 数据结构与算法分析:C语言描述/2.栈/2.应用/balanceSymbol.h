//2020年10月23日22点11分
//栈的应用：平衡符号

#ifndef _BalanceSymbol_H

//检查符号是否平衡
void CheckBalanceSymbol(FILE *fp);

//是否是开放符号
int IsOpenSymbol(char ch);

//是否是封闭符号
int IsCloseSymbol(char ch);

//开放符号与封闭符号是否匹配
int IsMatch(char chOpen, char chClose);

#endif      /* _BalanceSymbol_H */