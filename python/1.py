# 从键盘输入两个字符串
x = input("请输入第一个字符串：")
y = input("请输入第二个字符串：")

# 比较两个字符串
if len(x) > len(y): # 如果x比y长，返回x
    print(x)
    print(y)
elif len(x) < len(y): # 如果x比y短，返回y
    print(y)
    print(x)
else: # 如果x和y长度相等，返回字典序较小的那个
    if x < y: # 如果x在y之前，返回x
        print(x)
        print(y)
    else: # 否则返回y
        print(y)
        print(x)