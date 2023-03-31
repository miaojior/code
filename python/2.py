# 导入turtle库
import turtle

# 设置画笔的颜色和宽度
turtle.color("green")
turtle.pensize(10)

# 设置填充的颜色
turtle.fillcolor("red")

# 开始填充
turtle.begin_fill()

# 画一个正五边形，每个边长为200，每个角为72度
for i in range(5):
    turtle.forward(200)
    turtle.left(72)

# 结束填充
turtle.end_fill()

# 隐藏海龟
turtle.hideturtle()

# 显示图形
turtle.done()
