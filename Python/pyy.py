# -*- coding: utf-8 -*- #!
# weixin_Image.bat 破解
# JPG 16进制 FF D8 FF
# PNG 16进制 89 50 4e
# 微信.bat 16进制 e1 c6 e1
# key 值 1e1e 0x1e  weixin.bat-jpg

import os
# 微信image文件路径
print(u'微信bat转图片')
print(u'----------------------------')
print(u'请键入 bat输入文件夹')
into_path = input()
print(u'请键入 图片输出文件夹')
out_path = input()+u'\\'


def imageXor(f):
    """
    计算异或值
    各图片头部信息
    jpeg：ff d8 ff
    png：89 50 4e 47
    gif： 47 49 46 38
    """

    dat_read = open(f, "rb")
    try:
        a = [(0x89, 0x50, 0x4e), (0x47, 0x49, 0x46), (0xff, 0xd8, 0xff)]
        for now in dat_read:
            for xor in a:
                i = 0
                res = []
                nowg = now[:3]
                for nowByte in nowg:
                    res.append(nowByte ^ xor[i])
                    i += 1
                if res[0] == res[1] == res[2]:
                    return res[0]
    except:
        pass
    finally:
        dat_read.close()


def imageDecode(f, fn):
    """
    解码
    :param f: 微信图片路径
    :param fn:微信图片目录下的.bat
    :return:
    """
    # 先计算出偏移值
    change_Byte = imageXor(f)

    # 读取.bat
    dat_read = open(f, "rb")
    # 图片输出路径
    out = out_path + fn + ".jpg"
    # 图片写入
    png_write = open(out, "wb")
    # 循环字节

    for now in dat_read:
        for nowByte in now:
            # 转码计算
            newByte = nowByte ^ change_Byte
            # 转码后重新写入
            png_write.write(bytes([newByte]))
    dat_read.close()
    png_write.close()
    # pass


def findFile(f):
    """
    寻找文件
    :param f:微信图片路径
    :return:
    """
    # 把路径文件夹下的文件以列表呈现
    fsinfo = os.listdir(f)
    # 逐步读取文件
    change_Byte = None
    for fn in fsinfo:
        # 拼接路径：微信图片路径+图片名
        temp_path = os.path.join(f, fn)
        # 判断目录还是.bat
        if not os.path.isdir(temp_path):
            print('文件路径：{}'.format(temp_path))
            print(fn)
            # 转码函数
            imageDecode(temp_path, fn)
        else:
            pass


# 运行
findFile(into_path)
