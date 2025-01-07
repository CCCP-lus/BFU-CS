__author__ = 'CCC'
import random
import math
import time


def gcd(a, b):
    """
    求最大公约数
    :param a:
    :param b:
    :return:
    """
    while b:
        a, b = b, a % b
    return a


def exgcd(a, b):
    """
    扩展欧几里得算法
    :param a:
    :param b:
    :return:
    """
    # old_s, s = 1, 0
    # old_t, t = 0, 1
    # while b:
    #     q = a // b
    #     s, old_s = old_s - q * s, s
    #     t, old_t = old_t - q * t, t
    #     a, b = b, a % b
    # return a, old_s, old_t
    if b == 0:
        return a, 1, 0
    g, y, x = exgcd(b, a % b)
    return g, x, y - (a // b) * x


def invmod(e, m):
    """
    求模逆元
    :param e:
    :param m:
    :return:
    """
    g, d, y = exgcd(e, m)
    assert g == 1
    if d < 0:
        d += m
    return d


def sieve(limit, primes):
    """
    区间筛法：筛选出limit范围内的质数，并标记其倍数以筛选出质数
    :param limit:
    :param primes:
    :return:
    """
    mark = [True] * (limit + 1)
    for p in range(2, int(math.sqrt(limit)) + 1):
        if mark[p]:
            for multiple in range(p * p, limit + 1, p):
                mark[multiple] = False
    for p in range(2, limit + 1):
        if mark[p]:
            primes.append(p)


def get_lower_prime(n, primes):
    """
    获取恰好小于N的质数
    :param n:
    :param primes:
    :return:
    """
    for num in range(n - 1, 1, -1):
        if all(num % prime != 0 for prime in primes if prime * prime <= num):
            return num
    return None


def get_upper_prime(n, primes):
    """
    获取恰好大于N的质数
    :param n:
    :param primes:
    :return:
    """
    num = n + 1
    while True:
        if all(num % prime != 0 for prime in primes if prime * prime <= num):
            return num
        num += 1


def get_primes(n):
    """
    获取恰好小于等于N和恰好大于N的质数
    :param n:
    :return:
    """
    print("正在计算小于等于N和大于N的质数...")
    limit = int(math.sqrt(n)) + 1
    primes = []
    sieve(limit, primes)
    upper_prime = get_upper_prime(n, primes)
    lower_prime = get_lower_prime(n, primes)
    print("大于N的最小质数:", upper_prime, "小于N的最大质数:", lower_prime)
    return upper_prime, lower_prime


def get_key_pair(p, q):
    """
    获取公钥-私钥对
    :param p:
    :param q:
    :return:
    """
    n = p * q
    phi = (p - 1) * (q - 1)
    print("φ:", phi)
    e = random.randint(2, phi - 1)
    while gcd(e, phi) != 1:
        e = random.randint(2, phi - 1)
    print("e:", e)
    d = invmod(e, phi)
    print("d:", d)
    print("公钥对:", (e, n), "私钥对：", (d, n))
    return (e, n), (d, n)


def fast_pow(base, exponent, modulus):
    """
    快速幂算法
    :param base: 底数
    :param exponent: 指数
    :param modulus: 模数
    :return: (base^exponent) % modulus
    """
    result = 1
    base = base % modulus
    while exponent > 0:
        if exponent % 2 == 1:  # 如果指数是奇数
            result = (result * base) % modulus
        exponent = exponent >> 1  # 指数右移一位
        base = (base * base) % modulus
    return result


def encrypt(pk, plaintext):
    """
    加密
    :param pk:
    :param plaintext:
    :return:
    """
    key, n = pk
    # cipher = [(ord(char) ** key) % n for char in plaintext]
    cipher = [fast_pow(ord(char), key, n) for char in plaintext]
    return cipher


def decrypt(pk, ciphertext):
    """
    解密
    :param pk:
    :param ciphertext:
    :return:
    """
    key, n = pk
    # plain = [chr((char ** key) % n) for char in ciphertext]
    plain = [chr(fast_pow(char, key, n)) for char in ciphertext]
    return ''.join(plain)


if __name__ == '__main__':
    N = int(input("请输入一个整数N: "))
    public_key, private_key = get_key_pair(*get_primes(N))

    message = input("请输入原文：")
    begin = time.time()
    encrypted_message = encrypt(public_key, message)
    print("加密后的消息:", ''.join(map(lambda x: str(x), encrypted_message)))

    decrypted_message = decrypt(private_key, encrypted_message)
    print("解密后的消息:", decrypted_message)

    end = time.time()
    print(f"运行时间：{end-begin:.2f}s")
