# code = 'utf-8'
# 编译器
__author__ = 'CCC'
__date__ = '2024.05.03'

import math
import re
import os
import ast
import astunparse
import turtle
import numpy

import checker
import lexer
import parser

# 存储绘图步骤的文件
FILENAME = "摹图之凭.txt"
# 从词法分析器获取TOKEN
TOKEN = lexer.TOKEN
# 绘图文件路径
PAINT_PATH = "绘_EXE.py"


class Compiler:
    def __init__(self):
        self.checker = checker.Checker()
        self.intermediate_code = self.checker.analyze()
        with open(PAINT_PATH, 'w', encoding='utf-8') as f:
            f.write(
                '''
import math
import re
import os
import ast
import astunparse
import turtle
import numpy as np

# 画布设置
turtle.setup(1.0, 1.0)
turtle.penup()                
                '''
            )

    def create_file(self):
        with open(PAINT_PATH, 'a', encoding='utf-8') as f:
            for i in self.intermediate_code:
                f.write('''
# 绘图
for ''' + self.checker.variable + ''' in np.arange('''+str(i[3][0])+''', '''+str(i[3][1])+''', '''+str(i[3][2])+'''):
    x = '''+str(i[4][0])+''' * '''+str(i[1][0])+'''
    y = '''+str(i[4][1])+''' * '''+str(i[1][1])+'''
    x_rot = x * math.cos('''+str(i[2])+''') + y * math.sin('''+str(i[2])+''') + '''+str(i[0][0])+'''
    y_rot = y * math.cos('''+str(i[2])+''') - x * math.sin('''+str(i[2])+''') + '''+str(i[0][1])+'''
    turtle.goto(x_rot, y_rot)
    turtle.dot()
                ''')
            f.write('\nturtle.done()\n')


if __name__ == "__main__":
    compiler = Compiler()
    compiler.create_file()
