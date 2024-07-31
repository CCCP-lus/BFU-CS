# code = 'utf-8'
# 词法分析器
__author__ = 'CCC'
__date__ = '2024.04.29'

import math
import re
import os
import ast
import astunparse
import turtle
import numpy

# 存储绘图步骤的文件
FILENAME = "摹图之凭.txt"


# 定义Token类，存放记号的类型，值，函数
class Token:
    def __init__(self, t_type, t_value, t_function):
        self.t_type = t_type
        self.t_value = t_value
        self.t_function = t_function


# 定义词法分析器类
class Lexer:
    def __init__(self):
        self.output_list = []

    def get_token(self, sentence):
        self.output_list = []   # 刷新输出列表
        if sentence:
            tokens = sentence.split()
            for token in tokens:
                try:
                    self.show_token(token)
                except:
                    self.argument_lexer(token)
            self.show_token('。')

    # 输出Token的信息
    def show_token(self, name, is_number=False):
        token = None
        if is_number:
            number = chinese2float(name)
            if number == None:
                raise SyntaxError()
            token = Token('NUMBER', number, None)
            self.output_list.append([name, token])
        else:
            # token = TOKEN[name]
            token = TOKEN.get(name, None)
            if token == None:
                raise SyntaxError("词语不是保留字")
            else:
                self.output_list.append([name, token])
        # print("NAME: " + str(name) + ", TYPE: " + token.t_type + ", VALUE: " +
        #       str(token.t_value) + ", FUNCTION: " + str(token.t_function))

    # 更复杂的表达式
    def argument_lexer(self, argument):
        # 扫描位置
        i = 0
        # 字符串长度
        length = len(argument)
        while i < length:
            temp = ""
            if argument[i] in ['零', '一', '二', '三', '四', '五', '六', '七', '八', '九', '十', '百', '又', '负']:
                # 以小数点开头，正规式.[0-9]+
                if argument[i] == '又':
                    i += 1
                    while argument[i] in ['零', '一', '二', '三', '四', '五', '六', '七', '八', '九'] and i < length - 1:
                        temp += argument[i]
                        i += 1
                    temp = '零' + temp
                    self.show_token(temp, True)
                    # print("NAME: " + temp + ", TYPE: NUMBER, VALUE: " + str(chinese2float(temp)) + ", FUNCTION: None")
                # 正常数字，正规式为[0-9]+.?[0-9]*
                else:
                    while argument[i] in ['零', '一', '二', '三', '四', '五', '六', '七', '八', '九', '十', '百', '又', '负'] and i < length:
                        temp += argument[i]
                        i += 1
                    self.show_token(temp, True)
                # print("NAME: " + temp + ", TYPE: NUMBER, VALUE: " + str(chinese2float(temp)) + ", FUNCTION: None")
                if i >= length:
                    break
            else:
                self.show_token(argument[i])
                i += 1


# 读取输入文件类
class Scanner:
    def __init__(self, path = FILENAME):
        # 读预设文件的内容
        self.path = path
        # 缓冲区
        self.buffer = ""
        with open(self.path, 'r', encoding='utf-8') as f:
            lines = f.readlines()
            for line in lines:
                temp_line = line.split('注')[0].split('批')[0].split('\n')[0]
                if len(temp_line) > 0 and not temp_line.endswith('。'):
                    raise SyntaxError("语句需以句号结尾")
                self.buffer = self.buffer + temp_line
        self.buffer = self.buffer.strip()
        self.lexer = Lexer()
        self.output_lists = []

    def analyse(self):
        sentences = re.split("(。)", self.buffer)    # 正则表达式
        state = True
        for sentence in sentences:
            if state and sentence != "。":
                state = False
                self.lexer.get_token(sentence)
                self.output_lists.extend(self.lexer.output_list)
            elif sentence == "。":
                state = True
            else:
                raise SyntaxError()
        if state:
            raise SyntaxError()
        return self.output_lists


# 录入记号到字典中
TOKEN = {
    # 常量
    # 圆周率——沿用古称
    '彀': Token('CONST_ID', math.pi, None),
    # 自然对数——没有记载，取算盘的元素代替
    '珠': Token('CONST_ID', math.e, None),

    # 变量——天干表示
    '甲': Token('SYMBOL', None, None),
    '乙': Token('SYMBOL', None, None),
    '丙': Token('SYMBOL', None, None),
    '丁': Token('SYMBOL', None, None),
    '戊': Token('SYMBOL', None, None),
    '己': Token('SYMBOL', None, None),
    '庚': Token('SYMBOL', None, None),
    '辛': Token('SYMBOL', None, None),
    '壬': Token('SYMBOL', None, None),
    '癸': Token('SYMBOL', None, None),

    # 函数
    # 三角函数——正、余、切
    '正': Token('FUNC', None, 'math.sin'),
    '余': Token('FUNC', None, 'math.cos'),
    '切': Token('FUNC', None, 'math.tan'),
    # # 幂函数
    # '幂': Token('FUNC', None, math.pow),
    # 指数函数
    '指': Token('FUNC', None, 'math.exp'),
    # 对数函数
    '对': Token('FUNC', None, 'math.log'),
    # 开方函数
    '开': Token('FUNC', None, 'math.sqrt'),

    # 保留字
    # 原点ORIGIN
    '基': Token('KEYWORD', None, None),
    # 缩放比例SCALE
    '息': Token('KEYWORD', None, None),
    # 旋转角度ROT
    '旋': Token('KEYWORD', None, None),
    # 赋值语句IS
    '赋': Token('KEYWORD', None, None),
    # 循环语句FOR
    '走': Token('KEYWORD', None, None),
    # 循环体开始条件FROM
    '出': Token('KEYWORD', None, None),
    # 循环体结束条件TO
    '至': Token('KEYWORD', None, None),
    # 循环体步长STEP
    '步': Token('KEYWORD', None, None),
    # 画图指令DRAW
    '绘': Token('KEYWORD', None, None),

    # 运算符加减乘除
    '和': Token('OP', '+', None),
    '差': Token('OP', '-', None),
    '积': Token('OP', '*', None),
    '商': Token('OP', '/', None),
    '幂': Token('OP', '**', None),

    # 分隔符
    '【': Token('MARK', '(', None),
    '】': Token('MARK', ')', None),
    '，': Token('MARK', ',', None),
    '。': Token('END', ';', None),
    '': Token('EMPTY', None, None),

    # 数字和小数点，到“百”这一数量级够用
    '零': Token('NUMBER', 0.0, None),
    '一': Token('NUMBER', 1.0, None),
    '二': Token('NUMBER', 2.0, None),
    '三': Token('NUMBER', 3.0, None),
    '四': Token('NUMBER', 4.0, None),
    '五': Token('NUMBER', 5.0, None),
    '六': Token('NUMBER', 6.0, None),
    '七': Token('NUMBER', 7.0, None),
    '八': Token('NUMBER', 8.0, None),
    '九': Token('NUMBER', 9.0, None),
    '十': Token('NUMBER', 10.0, None),
    '百': Token('NUMBER', 100.0, None),
    '又': Token('NUMBER', None, None),
    '负': Token('NUMBER', None, None),
}

# 定义基础数字
NUM_DICT = {"零": 0, "一": 1, "二": 2, "三": 3, "四": 4, "五": 5, "六": 6, "七": 7, "八": 8, "九": 9}
# 定义权重
WEIGHT_DICT = {"十": 10, "百": 100}


def chinese2float(chinese):
    """
    将汉字表示的数字转换成float类型
    """
    is_negative = False
    ans = 0.0
    if chinese.startswith('负'):
        is_negative = True
        chinese = chinese[1: ]
    if '又' in chinese:
        if len(chinese.split('又')) > 2:
            raise SyntaxError("出现过多的小数点")
        int_part, dec_part = chinese.split('又')
        ans += chinese2int(int_part)
        dec_factor = 0.1
        for c in dec_part:
            ans += NUM_DICT[c] * dec_factor
            dec_factor *= 0.1
    else:
        ans += chinese2int(chinese)
    return -ans if is_negative else ans


def chinese2int(chinese):
    """
    将整数部分的汉字转换为整数
    """
    ans = 0
    temp = 0
    for c in range(len(chinese)):
        if len(chinese) != 1 and c != len(chinese) - 1:
            if chinese[c] in NUM_DICT and chinese[c + 1] in NUM_DICT:
                return None
        if chinese[c] in NUM_DICT:
            temp += NUM_DICT[chinese[c]]
        elif chinese[c] in WEIGHT_DICT:
            ans += WEIGHT_DICT[chinese[c]] * temp
            temp = 0
        # 对“十”的特判
        if chinese[c] == "十" and ans == 0:
            ans = 10
    # 加上个位数
    ans += temp
    return ans


if __name__ == '__main__':
    print("正在运行词法分析器...")
    scan = Scanner()
    lex_list = scan.analyse()
    for lex in lex_list:
        print(f"{lex[0]:<10}{lex[1].t_type:<10}{str(lex[1].t_value):<10}{str(lex[1].t_function):<10}")
    print("词法分析器运行结束")
    print("*" * 40)
