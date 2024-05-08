from pypinyin import pinyin
import pyperclip
codetype='utf-8'

#Shift_JIS ,GBK23001 , BIG5，utf-8,gbk

if __name__ == '__main__':
    a='''串口开启 准备开始握手'''.replace("\"","\\\"").encode(encoding=codetype)
    print(str(a)[2:-1])


    b=a.decode(encoding=codetype)
    print(pinyin(b))
    c=""
    for p in pinyin(b):
        print(p[0] ,end=' ')
        c+=p[0]+" "
    pyperclip.copy("\""+str(a)[2:-1]+"\"/*"+c+"*/")
   # print(type(a))
   # print(hex(a[0]))
    print("char b[]={",end='')
    for byte in a:
        print(hex(byte),end=",")
    print("0x00};//",end="")

    for p in pinyin(b):
        print(str(p).replace("[","").replace("]","").replace("'",""),end=' ')

   # print(a)
   # print(b)