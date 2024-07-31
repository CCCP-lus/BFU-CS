
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
                
# 绘图
for 甲 in np.arange(0.0, 6.283185307179586, 0.06283185307179587):
    x = math.cos(甲) * 100.0
    y = math.sin(甲) * 100.0
    x_rot = x * math.cos(0.7853981633974483) + y * math.sin(0.7853981633974483) + 0.0
    y_rot = y * math.cos(0.7853981633974483) - x * math.sin(0.7853981633974483) + 0.0
    turtle.goto(x_rot, y_rot)
    turtle.dot()
                
# 绘图
for 甲 in np.arange(0.0, 6.283185307179586, 0.06283185307179587):
    x = math.cos(甲) * 150.0
    y = math.sin(甲) * 75.0
    x_rot = x * math.cos(0.7853981633974483) + y * math.sin(0.7853981633974483) + 100.0
    y_rot = y * math.cos(0.7853981633974483) - x * math.sin(0.7853981633974483) + 0.0
    turtle.goto(x_rot, y_rot)
    turtle.dot()
                
# 绘图
for 甲 in np.arange(0.0, 6.283185307179586, 0.06283185307179587):
    x = math.cos(甲) * 75.0
    y = math.sin(甲) * 150.0
    x_rot = x * math.cos(0.7853981633974483) + y * math.sin(0.7853981633974483) + 0.0
    y_rot = y * math.cos(0.7853981633974483) - x * math.sin(0.7853981633974483) + 100.0
    turtle.goto(x_rot, y_rot)
    turtle.dot()
                
# 绘图
for 甲 in np.arange(0.0, 6.283185307179586, 0.06283185307179587):
    x = math.cos(甲) * 150.0
    y = math.sin(甲) * 75.0
    x_rot = x * math.cos(0.7853981633974483) + y * math.sin(0.7853981633974483) + -100.0
    y_rot = y * math.cos(0.7853981633974483) - x * math.sin(0.7853981633974483) + 0.0
    turtle.goto(x_rot, y_rot)
    turtle.dot()
                
# 绘图
for 甲 in np.arange(0.0, 6.283185307179586, 0.06283185307179587):
    x = math.cos(甲) * 75.0
    y = math.sin(甲) * 150.0
    x_rot = x * math.cos(0.7853981633974483) + y * math.sin(0.7853981633974483) + 0.0
    y_rot = y * math.cos(0.7853981633974483) - x * math.sin(0.7853981633974483) + -100.0
    turtle.goto(x_rot, y_rot)
    turtle.dot()
                
turtle.done()
