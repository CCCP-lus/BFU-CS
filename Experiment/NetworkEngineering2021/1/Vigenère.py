# -*- coding: utf-8 -*-
__author__ = 'CCCPlus'


def encrypt(key, text):
    """
    加密算法
    :param key: 密钥
    :param text: 明文
    :return: 密文
    """
    result = ''
    extended_key = ''

    # 扩展密钥到与明文长度一致
    for i in range(len(text)):
        extended_key += key[i % len(key)]

    # 根据对应关系进行加密
    for i in range(len(text)):
        text_offset = ord(text[i])  # 将明文字符转换为ASCII值
        key_offset = ord(extended_key[i])   # 将密钥字符转换为ASCII值
        result += chr((text_offset + key_offset) % 128) # 将值相加后取模，再转换回ASCII字符

    return result


def decrypt(key, text):
    """
    解密算法
    :param key: 密钥
    :param text: 密文
    :return: 明文
    """
    result = ''
    extended_key = ''

    # 扩展密钥到与密文长度一致
    for i in range(len(text)):
        extended_key += key[i % len(key)]

    # 根据对应关系进行解密
    for i in range(len(text)):
        text_offset = ord(text[i])  # 将密文字符转换为ASCII值
        key_offset = ord(extended_key[i])   # 将密钥字符转换为ASCII值
        result += chr((128 + text_offset - key_offset) % 128)   # 将值相减后再+128避免取负，取模，再转换回ASCII字符

    return result


print("Vigenère加密算法程序演示，输入“退出”可退出程序")
while True:
    s = input('请输入原文：')
    if s == '退出':
        break
    if not all(ord(char) < 128 for char in s):
        print("原文包含非ASCII字符，请重新输入")
        continue

    k = input('请输入密钥：')
    if not all(ord(char) < 128 for char in k):
        print("密钥包含非ASCII字符，请重新输入")
        continue

    encrypted_s = encrypt(k, s)
    print("原文加密后的密文为：", encrypted_s)
    with open('C.txt', 'w', encoding='utf-8') as file:
        file.write(encrypted_s)
    decrypted_s = decrypt(k, encrypted_s)
    print("密文解密后的明文为：", decrypted_s)
    with open('M.txt', 'w', encoding='utf-8') as file:
        file.write(decrypted_s)
