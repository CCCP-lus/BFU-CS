# code = 'utf-8'
# 语法分析器
__author__ = 'CCC'
__date__ = '2024.05.01'

import math
import re
import os
import ast
import astunparse
import turtle
import numpy

import lexer

# 存储绘图步骤的文件
FILENAME = "摹图之凭.txt"
# 从词法分析器获取TOKEN
TOKEN = lexer.TOKEN


# 定义语法分析器类
class Parser:
    def __init__(self):
        self.scanner = lexer.Scanner(FILENAME)
        self.dataflow = self.scanner.analyse()
        self.pos = 0
        self.length = len(self.dataflow)

    def analyze(self):
        print("程序入口")
        self.pos = 0
        while self.pos < self.length:
            print("语句入口")
            if self.dataflow[self.pos][1].t_type == 'KEYWORD':
                self.output(self.dataflow[self.pos][0])
            print("语句出口")
        print("程序出口")

    def output(self, s):
        print("保留字匹配：" + s)
        self.pos += 1
        if s == '基' or s == '息':
            self.string_match('赋')
            t = self.parameter_match()
            self.print_syntax_tree(t[0])
            self.print_syntax_tree(t[1])
        elif s == '旋':
            self.string_match('赋')
            self.print_syntax_tree(self.expression_match())
        elif s == '走':
            self.variable_match()
            self.string_match('出')
            self.print_syntax_tree(self.expression_match())
            self.string_match('至')
            self.print_syntax_tree(self.expression_match())
            self.string_match('步')
            self.print_syntax_tree(self.expression_match())
            self.string_match('绘')
            t = self.parameter_match()
            self.print_syntax_tree(t[0])
            self.print_syntax_tree(t[1])
        else:
            raise SyntaxError("保留字匹配出错")
        print("保留字匹配成功")

    def variable_match(self):
        """
        匹配变量
        """
        if self.dataflow[self.pos][0] in ['甲', '乙', '丙', '丁', '戊', '己', '庚', '辛', '壬', '癸']:
            print("变量匹配：" + self.dataflow[self.pos][0])
            self.pos += 1
        else:
            raise SyntaxError("变量非法")

    def string_match(self, s):
        """
        匹配字符串（非变量情况）
        """
        if self.dataflow[self.pos][0] == s:
            print("保留字匹配：" + s)
            self.pos += 1
        else:
            raise SyntaxError("缺少赋值符")

    def parameter_match(self):
        """
        拆开括号，获取参数
        """
        t = self.expression_match()
        if t[0] == '【' and t[-1] == '】':
            t = t[1: -1].split('，')
        else:
            raise SyntaxError("参数格式非法")
        return t

    def expression_match(self):
        """
        匹配一个算数表达式
        """
        t = ''
        while self.dataflow[self.pos][0] != '。' and self.pos < self.length and self.dataflow[self.pos][1].t_type != 'KEYWORD':
            if self.dataflow[self.pos][1].t_type == 'FUNC':
                t += self.dataflow[self.pos][1].t_function
            elif self.dataflow[self.pos][1].t_type == 'CONST_ID':
                t += str(self.dataflow[self.pos][1].t_value)
            elif self.dataflow[self.pos][1].t_type == 'OP':
                t += self.dataflow[self.pos][1].t_value
            elif self.dataflow[self.pos][1].t_type == 'NUMBER':
                t += str(self.dataflow[self.pos][1].t_value)
            else:
                t += self.dataflow[self.pos][0]
            self.pos += 1
        if self.dataflow[self.pos][0] == '。':
            self.pos += 1
        return t

    def print_syntax_tree(self, s):
        print("表达式入口")
        s = s.replace('【', '(').replace('】', ')').replace('，', ',')
        print(astunparse.dump(ast.parse(s, filename='<unknown>')))
        print("表达式出口")


if __name__ == '__main__':
    print("正在运行语法分析器...")
    # print(astunparse.dump(ast.parse("甲乙丙丁", filename='<unknown>')))
    Parser().analyze()
    print("语法分析器运行结束")
