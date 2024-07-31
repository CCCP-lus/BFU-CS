# code = 'utf-8'
# 语义检查器
__author__ = 'CCC'
__date__ = '2024.05.02'

import math
import re
import os
import ast
import astunparse
import turtle
import numpy

import lexer
import parser

# 存储绘图步骤的文件
FILENAME = "摹图之凭.txt"
# 从词法分析器获取TOKEN
TOKEN = lexer.TOKEN


class Checker(parser.Parser):
    def __init__(self):
        super().__init__()
        self.s_origin = [0.0, 0.0]
        self.s_scale = [1.0, 1.0]
        self.s_rot = 0.0
        self.s_for = [0.0, 0.0, 0.0]
        self.s_draw = ['', '']
        self.variable = ''
        self.intermediate_code = []

    def analyze(self):
        while self.pos < self.length:
            if self.dataflow[self.pos][1].t_type == 'KEYWORD':
                self.output(self.dataflow[self.pos][0])
        for x in self.intermediate_code:
            print(x)
        return [eval(x) for x in self.intermediate_code]

    def output(self, s):
        self.pos += 1
        if s == '基':
            self.string_match('赋')
            t = self.parameter_match()
            self.s_origin[0] = eval(t[0].replace('【', '(').replace('】', ')').replace('，', ','))
            self.s_origin[1] = eval(t[1].replace('【', '(').replace('】', ')').replace('，', ','))
            print("本句语义为：设置坐标原点为：", self.s_origin)
        elif s == '息':
            self.string_match('赋')
            t = self.parameter_match()
            self.s_scale[0] = eval(t[0].replace('【', '(').replace('】', ')').replace('，', ','))
            self.s_scale[1] = eval(t[1].replace('【', '(').replace('】', ')').replace('，', ','))
            print("本句语义为：设置缩放比例为：", self.s_scale)
        elif s == '旋':
            self.string_match('赋')
            self.s_rot = eval(self.expression_match().replace('【', '(').replace('】', ')').replace('，', ','))
            print("本句语义为：", end="")
            print("设置旋转角度（弧度制）为：", self.s_rot)
        elif s == '走':
            self.variable_match()
            self.string_match('出')
            self.s_for[0] = eval(self.expression_match().replace('【', '(').replace('】', ')').replace('，', ','))
            self.string_match('至')
            self.s_for[1] = eval(self.expression_match().replace('【', '(').replace('】', ')').replace('，', ','))
            self.string_match('步')
            self.s_for[2] = eval(self.expression_match().replace('【', '(').replace('】', ')').replace('，', ','))
            self.string_match('绘')
            t = self.parameter_match()
            self.s_draw[0] = t[0].replace('【', '(').replace('】', ')').replace('，', ',')
            self.s_draw[1] = t[1].replace('【', '(').replace('】', ')').replace('，', ',')
            print("本句语义为：在", end="")
            print("坐标原点为：", self.s_origin, end="")
            print("，缩放比例为：", self.s_scale, end="")
            print("，旋转角度（弧度制）为：", self.s_rot, end="")
            print(f"的前提下，从{self.s_for[0]}到{self.s_for[1]}，步长为{self.s_for[2]}，", end="")
            print(f"横坐标函数为{self.s_draw[0]}，纵坐标函数为{self.s_for[1]}的图象")
            self.intermediate_code.append(str((self.s_origin, self.s_scale, self.s_rot, self.s_for, self.s_draw)))
        else:
            raise SyntaxError()

    def variable_match(self):
        """
        匹配变量
        """
        if self.dataflow[self.pos][0] in ['甲', '乙', '丙', '丁', '戊', '己', '庚', '辛', '壬', '癸']:
            self.variable = self.dataflow[self.pos][0]
            self.pos += 1
        else:
            raise SyntaxError()

    def string_match(self, s):
        """
        匹配字符串（非变量情况）
        """
        if self.dataflow[self.pos][0] == s:
            self.pos += 1
        else:
            raise SyntaxError()

    def parameter_match(self):
        """
        拆开括号，获取参数
        """
        t = self.expression_match()
        if t[0] == '【' and t[-1] == '】':
            t = t[1: -1].split('，')
        else:
            raise SyntaxError()
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


if __name__ == '__main__':
    checker = Checker()
    checker.analyze()
