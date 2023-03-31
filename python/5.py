# 输入你在地球上的体重（单位：kg）
weight_earth = float(input("请输入你在地球上的体重（单位：kg）："))

# 假设你每年在地球上增长0.5kg
growth_rate = 0.5

# 月球上的重力是地球上的16.5%
gravity_moon = 0.165

# 创建一个空列表，用于存储未来10年你在地球和月球上的体重
weight_list = []

# 使用for循环，计算未来10年你在地球和月球上的体重，并将结果添加到列表中
for i in range(1, 11):
    # 计算第i年你在地球上的体重
    weight_earth_i = weight_earth + i * growth_rate
    # 计算第i年你在月球上的体重
    weight_moon_i = weight_earth_i * gravity_moon
    # 将结果以元组的形式添加到列表中
    print(f"第{i}年，你在地球上的体重是{weight_earth_i:f}kg，你在月球上的体重是{weight_moon_i:f}kg。")

