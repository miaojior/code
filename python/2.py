# 导入matplotlib库
import matplotlib.pyplot as plt
# 导入math库
import math

# 定义边长和线宽
side = 200
width = 10

# 定义五个顶点的坐标
x1 = 0
y1 = 0
x2 = side
y2 = 0
x3 = side + side * math.cos(math.radians(72))
y3 = side * math.sin(math.radians(72))
x4 = side / 2
y4 = side * math.sin(math.radians(72)) + side * math.sin(math.radians(36))
x5 = -side * math.cos(math.radians(72))
y5 = y3

# 创建一个多边形对象
polygon = plt.Polygon([[x1, y1], [x2, y2], [x3, y3], [x4, y4], [x5, y5]],
                      facecolor='red', edgecolor='green', linewidth=width)

# 将多边形添加到当前的图形中
plt.gca().add_patch(polygon)

# 设置坐标轴的范围和比例
plt.axis([-100, 400, -100, 400])
plt.axis('equal')

# 显示图形
plt.show()